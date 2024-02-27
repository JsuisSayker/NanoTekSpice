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
        std::getline (std::cin, line);
        std::cout << line << std::endl;
    }

}