/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Parser
*/

#include "Parser.hpp"
#include "ParserExceptions.hpp"
#include "AllSpecialComponents.hpp"
#include "AllElementaryComponents.hpp"
#include "GatesComponents/Gate4071Component.hpp"
#include "ComponentFactory.hpp"
#include "AllGateComponents.hpp"
#include "Circuit.hpp"
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include "macros.hpp"

#include <memory>

nts::Parser::Parser()
{
    _section = STARTING;
}

std::string nts::Parser::removeComment(std::string line)
{
    std::size_t found = line.find("#");
    if (found != std::string::npos)
        line = line.substr(0, found);
    return line;
}

std::string nts::Parser::findSectionName(const std::string line)
{
    std::string sectionName;
    size_t pos = line.find(':');
    if (pos != std::string::npos && line[0] == '.')
        sectionName = line.substr(1, pos - 1);
    return sectionName;
}

void nts::Parser::addComponentToCircuitFromMatch(std::vector<ChipsetData> parsedLines, nts::Circuit *circuit)
{
    nts::ComponentFactory factory;
    if (parsedLines[0].type == "input") {
        std::unique_ptr<nts::IComponent> input = factory.createInputComponent();
        circuit->addComponent(input, parsedLines[0].value);
    // } else if (parsedLines[0].type == "output") {
    //     circuit->addComponent(factory.createOutputComponent().get(), parsedLines[0].value);
    // } else if (parsedLines[0].type == "clock") {
    //     circuit->addComponent(factory.createClockComponent().get(), parsedLines[0].value);
    // } else if (parsedLines[0].type == "true") {
    //     circuit->addComponent(factory.createTrueComponent().get(), parsedLines[0].value);
    // } else if (parsedLines[0].type == "false") {
    //     circuit->addComponent(factory.createFalseComponent().get(), parsedLines[0].value);
    } else if (parsedLines[0].type == "and") {
        std::unique_ptr<nts::IComponent> andComponent = factory.createAndComponent();
        circuit->addComponent(andComponent, parsedLines[0].value);
    // } else if (parsedLines[0].type == "or") {
    //     circuit->addComponent(factory.createOrComponent().get(), parsedLines[0].value);
    // } else if (parsedLines[0].type == "xor") {
    //     circuit->addComponent(factory.createXorComponent().get(), parsedLines[0].value);
    // } else if (parsedLines[0].type == "not") {
    //     circuit->addComponent(factory.createNotComponent().get(), parsedLines[0].value);
    // } else if (parsedLines[0].type == "4071") {
    //     circuit->addComponent(factory.create4071Component().get(), parsedLines[0].value);
    } else {
        try {
            throw UnknownComponentType("Unknown component type: " + parsedLines[0].type);
        } catch (const UnknownComponentType& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

int nts::Parser::parseAndExtractChipsetFromLine(const std::string line, int linePosition, nts::Circuit *circuit)
{
    std::vector<ChipsetData> parsedLines;
    for (const auto& actualLine : line) {
        std::istringstream iss(line);
        ChipsetData data;
        iss >> data.type >> data.value;
        parsedLines.push_back(data);
    }
    addComponentToCircuitFromMatch(parsedLines, circuit);
    return OK;
}

int nts::Parser::parseAndExtractLinkFromLine(const std::string line, int linePosition, nts::Circuit *circuit)
{
    std::vector<LineData> parsedLines;
    std::istringstream iss(line);
    std::string token;

    while (iss >> token) {
        LineData data;
        size_t pos = token.find(':');
        if (pos != std::string::npos) {
            data.type = token.substr(0, pos);
            data.value = std::stoi(token.substr(pos + 1));
            parsedLines.push_back(data);
        }
    }
    nts::IComponent *firstComponent = circuit->findComponent(parsedLines[0].type);
    if (firstComponent == nullptr) {
        try {
            throw UnknownComponentName("Unknown component name: " + parsedLines[0].type);
        } catch (const UnknownComponentName& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return KO;
        }
    }
    nts::IComponent *secondComponent = circuit->findComponent(parsedLines[1].type);
    if (secondComponent == nullptr) {
        try {
            throw UnknownComponentName("Unknown component name: " + parsedLines[1].type);
        } catch (const UnknownComponentName& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return KO;
        }
    }
    if (parsedLines[0].type == "out" || parsedLines[1].type == "out") {
        printf("before setLink\n");
        firstComponent->setLink(parsedLines[0].value, *secondComponent, parsedLines[1].value);
        printf("after setLink\n");
    }
    else {
        printf("before setLink\n");
        secondComponent->setLink(parsedLines[1].value, *firstComponent, parsedLines[0].value);
        printf("after setLink\n");
    }
    return OK;
}

int nts::Parser::saveLine(const std::string line, int linePosition, nts::Circuit *circuit)
{
    std::string sectionName = findSectionName(line);
    if (!sectionName.empty()) {
        if (sectionName == "chipsets") {
            if (_section == STARTING)
                _section = CHIPSETS;
            else {
                try {
                    throw InvalidSectionException("The chipsets section must be the first one");
                } catch (const InvalidSectionException& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                    return KO;
                }
            }
        } else if (sectionName == "links") {
            if (_section == CHIPSETS)
                _section = LINKS;
            else {
                try {
                    throw InvalidSectionException("The links section must be after the chipsets section");
                } catch (const InvalidSectionException& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                    return KO;
                }
            }
        } else {
            try {
                throw UnknownSectionName("Unknown section name: " + sectionName);
            } catch (const UnknownSectionName& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return KO;
            }
        }
    } else {
        if (_section == STARTING) {
            try {
               throw InvalidSectionException("The file must start with a section name");
            } catch (const InvalidSectionException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return KO;
            }
        }
        else if (_section == CHIPSETS) {
            if (parseAndExtractChipsetFromLine(line, linePosition, circuit) == KO)
                return KO;
        }
        else if (_section == LINKS) {
            if (parseAndExtractLinkFromLine(line, linePosition, circuit) == KO)
                return KO;
        }
        return OK;
    }
    return OK;
}

std::string nts::Parser::trim(const std::string &str)
{
    std::string result = str;
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), result.end());
    return result;
}

int nts::Parser::parseFile(const std::string &filename, nts::Circuit *circuit)
{
    std::ifstream ifs(filename);
    int linePosition = 1;
    std::string line;
    if (!ifs.is_open()) {
        try {
            throw InvalidFileException("File:" + filename + " not found");
        } catch (const InvalidFileException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return KO;
        }
    }

    while (std::getline(ifs, line)) {
        line = trim(line);
        line = removeComment(line);
        if (!line.empty())
            if (saveLine(line, linePosition, circuit) == KO)
                return KO;
        linePosition++;
    }
    ifs.close();
    if (_section != LINKS) {
        try {
            throw MissingSectionException("Missing links section");
        } catch (const MissingSectionException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return KO;
        }
    }
    return OK;
}
