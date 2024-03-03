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
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include "macros.hpp"

#include <memory>
#include <string.h>

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

void nts::Parser::addComponentToCircuitFromMatch(std::vector<ChipsetData> lines, nts::Circuit *circuit)
{
    nts::ComponentFactory factory;
    if (lines[0].type == "input") {
        std::unique_ptr<nts::IComponent> input = factory.createInputComponent();
        circuit->addComponent(input, lines[0].value);
    } else if (lines[0].type == "output") {
        std::unique_ptr<nts::IComponent> output = factory.createOutputComponent();
        circuit->addComponent(output, lines[0].value);
    } else if (lines[0].type == "clock") {
        std::unique_ptr<nts::IComponent> clock = factory.createClockComponent();
        circuit->addComponent(clock, lines[0].value);
    } else if (lines[0].type == "true") {
        std::unique_ptr<nts::IComponent> trueComponent = factory.createTrueComponent();
        circuit->addComponent(trueComponent, lines[0].value);
    } else if (lines[0].type == "false") {
        std::unique_ptr<nts::IComponent> falseComponent = factory.createFalseComponent();
        circuit->addComponent(falseComponent, lines[0].value);
    } else if (lines[0].type == "and") {
        std::unique_ptr<nts::IComponent> andComponent = factory.createAndComponent();
        circuit->addComponent(andComponent, lines[0].value);
    } else if (lines[0].type == "or") {
        std::unique_ptr<nts::IComponent> orComponent = factory.createOrComponent();
        circuit->addComponent(orComponent, lines[0].value);
    } else if (lines[0].type == "xor") {
        std::unique_ptr<nts::IComponent> xorComponent = factory.createXorComponent();
        circuit->addComponent(xorComponent, lines[0].value);
    } else if (lines[0].type == "not") {
        std::unique_ptr<nts::IComponent> notComponent = factory.createNotComponent();
        circuit->addComponent(notComponent, lines[0].value);
    } else if (lines[0].type == "4071") {
        std::unique_ptr<nts::IComponent> notComponent = factory.create4071Component();
        circuit->addComponent(notComponent, lines[0].value);
    } else if (lines[0].type == "4081") {
        std::unique_ptr<nts::IComponent> notComponent = factory.create4081Component();
        circuit->addComponent(notComponent, lines[0].value);
    } else if (lines[0].type == "4001") {
        std::unique_ptr<nts::IComponent> notComponent = factory.create4001Component();
        circuit->addComponent(notComponent, lines[0].value);
    } else if (lines[0].type == "4011") {
        std::unique_ptr<nts::IComponent> notComponent = factory.create4011Component();
        circuit->addComponent(notComponent, lines[0].value);
    } else if (lines[0].type == "4030") {
        std::unique_ptr<nts::IComponent> notComponent = factory.create4030Component();
        circuit->addComponent(notComponent, lines[0].value);
    } else if (lines[0].type == "4069") {
        std::unique_ptr<nts::IComponent> notComponent = factory.create4069Component();
        circuit->addComponent(notComponent, lines[0].value);
    } else {
        try {
            throw UnknownComponentType("Unknown component type: " + lines[0].type);
        } catch (const UnknownComponentType& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

int nts::Parser::parseAndExtractChipsetFromLine(const std::string line, nts::Circuit *circuit)
{
    std::vector<ChipsetData> lines;
    std::istringstream iss(line);
    ChipsetData data;
    iss >> data.type >> data.value;
    lines.push_back(data);
    // }
    if (circuit->findComponent(lines[0].value) != nullptr) {
        try {
            throw ComponentNameAlreadyExists("Component name already exists: " + lines[0].value);
        } catch (const ComponentNameAlreadyExists& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return KO;
        }
    }
    addComponentToCircuitFromMatch(lines, circuit);
    return OK;
}

void nts::Parser::findAlreadyLinkedComponent(std::vector<LineData> parsedLines, std::vector<LineData>newParsedLines)
{
    for (size_t i = 0; i < parsedLines.size() - 2; ++i) {
        const std::string& type = parsedLines[i].type;
        const size_t& value = parsedLines[i].value;
        if ((newParsedLines[0].type == type && newParsedLines[0].value == value) || (newParsedLines[1].type == type && newParsedLines[1].value == value)) {
            throw InvalidLinkException("Link already exists");
        }
    }
}

int nts::Parser::parseAndExtractLinkFromLine(const std::string line, nts::Circuit *circuit, std::vector<LineData> *parsedLines)
{
    std::vector<LineData> newParsedLines;
    std::istringstream iss(line);
    std::string token;

    while (iss >> token) {
        LineData data;
        size_t pos = token.find(':');
        if (pos != std::string::npos) {
            data.type = token.substr(0, pos);
            try {
                data.value = std::stoi(token.substr(pos + 1));
            } catch (const std::invalid_argument& e) {
                try {
                    throw InvalidLinkException("Missing link value");
                } catch (const InvalidLinkException& e) {
                    std::cerr << "Error: " << e.what() << std::endl;
                    return KO;
                }
            }
            newParsedLines.push_back(data);
            parsedLines->push_back(data);
        }
    }
    if (!newParsedLines[0].value || !newParsedLines[1].value) {
        try {
            throw InvalidLinkException("Invalid link value");
        } catch (const InvalidLinkException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return KO;
        }
    }
    try {
        findAlreadyLinkedComponent(parsedLines[0], newParsedLines);
    } catch (const InvalidLinkException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return KO;
    }
    nts::IComponent *firstComponent = circuit->findComponent(newParsedLines[0].type);
    if (firstComponent == nullptr) {
        try {
            throw UnknownComponentName("Unknown component name: " + newParsedLines[0].type);
        } catch (const UnknownComponentName& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return KO;
        }
    }
    nts::IComponent *secondComponent = circuit->findComponent(newParsedLines[1].type);
    if (secondComponent == nullptr) {
        try {
            throw UnknownComponentName("Unknown component name: " + newParsedLines[1].type);
        } catch (const UnknownComponentName& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return KO;
        }
    }
// dynamic_cast<nts::Output*>(secondComponent) || dynamic_cast<nts::Input*>(firstComponent)
    if (strncmp(newParsedLines[0].type.c_str(), "out", 3) == 0)
        secondComponent->setLink(newParsedLines[1].value, *firstComponent, newParsedLines[0].value);
    else
        firstComponent->setLink(newParsedLines[0].value, *secondComponent, newParsedLines[1].value);
    return OK;
}

int nts::Parser::saveLine(const std::string line, nts::Circuit *circuit, std::vector<LineData> *parsedLines)
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
            if (parseAndExtractChipsetFromLine(line, circuit) == KO)
                return KO;
        }
        else if (_section == LINKS) {
            if (parseAndExtractLinkFromLine(line, circuit, parsedLines) == KO)
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
    std::vector<LineData> parsedLines;
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
            if (saveLine(line, circuit, &parsedLines) == KO)
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
