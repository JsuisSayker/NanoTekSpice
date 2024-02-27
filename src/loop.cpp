/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** loop
*/

#include "IComponent.hpp"
#include "Circuit.hpp"

int loopNts(nts::Circuit *circuit)
{
    std::string line;

    while (1)
    {
        std::cout << "> ";
        if (!std::getline(std::cin, line)) {
            if (std::cin.eof())
                return 0;
        }
        if (line == "exit")
            return 0;
        if (line == "simulate")
            std::cout << "simulate" << std::endl;
            // circuit->simulate(1);
        if (line == "display")
            std::cout << "display" << std::endl;
            // circuit->display();
        std::cout << line << std::endl;
    }
}