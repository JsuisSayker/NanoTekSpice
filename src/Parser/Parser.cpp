/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Parser
*/

#include "Parser.hpp"
#include "ParserExceptions.hpp"
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

void nts::Parser::parseAndExtractDataFromLine(const std::string line, int linePosition, nts::Circuit *circuit)
{
    struct LineData {
        std::string type;
        std::string value;
    };
    std::vector<LineData> parsedLines;
    for (const auto& actualLine : line) {
        std::istringstream iss(line);
        LineData data;
        iss >> data.type >> data.value;
        parsedLines.push_back(data);
    }
    std::cout << "type :" << parsedLines[0].type << "\nvalue :" << parsedLines[0].value << std::endl;

    // circuit->addComponent();
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
