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

void nts::Parser::addComponentToCircuitFromMatch(std::vector<LineData> parsedLines, nts::Circuit *circuit)
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
    // } else if (parsedLines[0].type == "4001") {
    //     nts::C4001 *c4001 = new nts::C4001();
    //     circuit->addComponent(c4001, parsedLines[0].value);
    // } else if (parsedLines[0].type == "4008") {
    //     nts::C4008 *c4008 = new nts::C4008();
    //     circuit->addComponent(c4008, parsedLines[0].value);
    // } else if (parsedLines[0].type == "4011") {
    //     nts::C4011 *c4011 = new nts::C4011();
    //     circuit->addComponent(c4011, parsedLines[0].value);
    // } else if (parsedLines[0].type == "4030") {
    //     nts::C4030 *c4030 = new nts::C4030();
    //     circuit->addComponent(c4030, parsedLines[0].value);
    // } else if (parsedLines[0].type == "4069") {
    //     nts::C4069 *c4069 = new nts::C4069();
    //     circuit->addComponent(c4069, parsedLines[0].value);
    // } else if (parsedLines[0].type == "4071") {
    //     nts::C4071 *c4071 = new nts::C4071();
    //     circuit->addComponent(c4071, parsedLines[0].value);
    // } else if (parsedLines[0].type == "4081") {
    //     nts::C4081 *c4081 = new nts::C4081();
    //     circuit->addComponent(c4081, parsedLines[0].value);
    // } else if (parsedLines[0].type == "4514") {
    //     nts::C4514 *c4514 = new nts::C4514();
    //     circuit->addComponent(c4514, parsedLines[0].value);
    // } else if (parsedLines[0].type == "4801") {
    //     nts::C4801 *c4801 = new nts::C4801();
    //     circuit->addComponent(c4801, parsedLines[0].value);
    } else
        throw UnknownComponentType("Unknown component type: " + parsedLines[0].type);
}

void nts::Parser::parseAndExtractDataFromLine(const std::string line, int linePosition, nts::Circuit *circuit)
{
    std::vector<LineData> parsedLines;
    for (const auto& actualLine : line) {
        std::istringstream iss(line);
        LineData data;
        iss >> data.type >> data.value;
        parsedLines.push_back(data);
    }
    std::cout << "type :" << parsedLines[0].type << "\nvalue :" << parsedLines[0].value << std::endl;
    addComponentToCircuitFromMatch(parsedLines, circuit);
}

void nts::Parser::saveLine(const std::string line, int linePosition, nts::Circuit *circuit)
{
    std::string sectionName = findSectionName(line);
    if (!sectionName.empty()) {
        if (sectionName == "chipsets") {
            if (_section == STARTING)
                _section = CHIPSETS;
            else
                throw InvalidSectionException("The chipsets section must be the first one");
        } else if (sectionName == "links") {
            if (_section == CHIPSETS)
                _section = LINKS;
            else
                throw InvalidSectionException("The links section must be after the chipsets section");
        } else
            throw UnknownSectionName("Unknown section name: " + sectionName);
    } else {
        if (_section == STARTING)
            throw InvalidSectionException("The file must start with a section name");
        else if (_section == CHIPSETS  )
            parseAndExtractDataFromLine(line, linePosition, circuit);
        // else if (_section == LINKS)

    }

}

// void Parser::ltrim(std::string &line)
// {
//     line.erase(line.begin(), std::find_if(line.begin(), line.end(), [](unsigned char ch) {
//         return !std::isspace(ch);
//     }));
// }

// void Parser::rtrim(std::string &line)
// {
//     line.erase(std::find_if(line.rbegin(), line.rend(), [](unsigned char ch) {
//         return !std::isspace(ch);
//     }).base(), line.end());
// }

// void Parser::trim(std::string &line)
// {
//     ltrim(line);
//     rtrim(line);
// }


void nts::Parser::parseFile(const std::string &filename, nts::Circuit *circuit)
{
    std::ifstream ifs(filename);
    int linePosition = 0;
    std::string line;
    if (!ifs.is_open())
        throw InvalidFileException("File:" + filename + " not found");

    while (std::getline(ifs, line)) {
        // line = ;
        line = removeComment(line);
        if (!line.empty())
            saveLine(line, linePosition, circuit);
        linePosition++;
    }
    ifs.close();
    if (_section != LINKS)
        throw MissingSectionException("Missing links section");
    // for()

}
