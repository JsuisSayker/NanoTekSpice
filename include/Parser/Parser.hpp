/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <fstream>
#include "Circuit.hpp"

namespace nts {
    class Parser {
        public:
            enum Section {
                STARTING,
                CHIPSETS,
                LINKS,
                CIRCUIT
            };
            struct LineData {
                std::string type;
                std::string value;
            };
                Parser();

            static std::string removeComment(std::string line);
            static std::string findSectionName(const std::string line);
            static void addComponentToCircuitFromMatch(std::vector<LineData> parsedLines, nts::Circuit *circuit);
            void saveLine(const std::string line, int linePosition, nts::Circuit *circuit);
            void parseFile(const std::string &filename, nts::Circuit *circuit);
            void parseAndExtractDataFromLine(const std::string line, int linePosition, nts::Circuit *circuit);
            // static inline void ltrim(std::string &line);
            // static inline void rtrim(std::string &line);
            // static inline void trim(std::string &line);

        protected:
            Section _section;
        private:
    };
}
#endif /* !PARSER_HPP_ */
