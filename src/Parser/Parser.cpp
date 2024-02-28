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
#include "Circuit.hpp"
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>


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
    if (parsedLines[0].type == "input") {
        nts::Input *input = new nts::Input();
        circuit->addComponent(input, parsedLines[0].value);
    } else if (parsedLines[0].type == "output") {
        nts::Output *output = new nts::Output();
        circuit->addComponent(output, parsedLines[0].value);
    } else if (parsedLines[0].type == "clock") {
        nts::ClockComponent *clock = new nts::ClockComponent();
        circuit->addComponent(clock, parsedLines[0].value);
    } else if (parsedLines[0].type == "true") {
        nts::TrueComponent *trueComponent = new nts::TrueComponent();
        circuit->addComponent(trueComponent, parsedLines[0].value);
    } else if (parsedLines[0].type == "false") {
        nts::FalseComponent *falseComponent = new nts::FalseComponent();
        circuit->addComponent(falseComponent, parsedLines[0].value);
    } else if (parsedLines[0].type == "and") {
        nts::AndComponent *andGateComponent = new nts::AndComponent();
        circuit->addComponent(andGateComponent, parsedLines[0].value);
    } else if (parsedLines[0].type == "or") {
        nts::OrComponent *orGateComponent = new nts::OrComponent();
        circuit->addComponent(orGateComponent, parsedLines[0].value);
    } else if (parsedLines[0].type == "xor") {
        nts::XorComponent *xorGateComponent = new nts::XorComponent();
        circuit->addComponent(xorGateComponent, parsedLines[0].value);
    } else if (parsedLines[0].type == "not") {
        nts::NotComponent *notGateComponent = new nts::NotComponent();
        circuit->addComponent(notGateComponent, parsedLines[0].value);
    } else {
        try {
            throw UnknownComponentType("Unknown component type: " + parsedLines[0].type);
        } catch (const UnknownComponentType& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

void nts::Parser::parseAndExtractChipsetFromLine(const std::string line, int linePosition, nts::Circuit *circuit)
{
    std::vector<ChipsetData> parsedLines;
    for (const auto& actualLine : line) {
        std::istringstream iss(line);
        ChipsetData data;
        iss >> data.type >> data.value;
        parsedLines.push_back(data);
    }
    addComponentToCircuitFromMatch(parsedLines, circuit);
}

void nts::Parser::parseAndExtractLinkFromLine(const std::string line, int linePosition, nts::Circuit *circuit)
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
    nts::IComponent *firstComponent =  circuit->findComponent(parsedLines[0].type);
    if (firstComponent == nullptr) {
        try {
            throw UnknownComponentName("Unknown component name: " + parsedLines[0].type);
        } catch (const UnknownComponentName& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    nts::IComponent *secondComponent = circuit->findComponent(parsedLines[1].type);
    if (secondComponent == nullptr) {
       try {
            throw UnknownComponentName("Unknown component name: " + parsedLines[1].type);
        } catch (const UnknownComponentName& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    // std::cout << "type 1 :" << parsedLines[0].type << "\nvalue 1 :" << parsedLines[0].value << std::endl;
    // std::cout << "type 2 :" << parsedLines[1].type << "\nvalue 2 :" << parsedLines[1].value << std::endl;
    firstComponent->setLink(parsedLines[0].value, *secondComponent, parsedLines[1].value);
}

void nts::Parser::saveLine(const std::string line, int linePosition, nts::Circuit *circuit)
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
                }
            }
        } else {
            try {
                throw UnknownSectionName("Unknown section name: " + sectionName);
            } catch (const UnknownSectionName& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    } else {
        if (_section == STARTING) {
            try {
               throw InvalidSectionException("The file must start with a section name");
            } catch (const InvalidSectionException& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else if (_section == CHIPSETS)
            parseAndExtractChipsetFromLine(line, linePosition, circuit);
        else if (_section == LINKS)
            parseAndExtractLinkFromLine(line, linePosition, circuit);
    }

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

void nts::Parser::parseFile(const std::string &filename, nts::Circuit *circuit)
{
    std::ifstream ifs(filename);
    int linePosition = 0;
    std::string line;
    if (!ifs.is_open())
        throw InvalidFileException("File:" + filename + " not found");

    while (std::getline(ifs, line)) {
        line = trim(line);
        line = removeComment(line);
        if (!line.empty())
            saveLine(line, linePosition, circuit);
        linePosition++;
    }
    ifs.close();
    if (_section != LINKS)
        throw MissingSectionException("Missing links section");
}
