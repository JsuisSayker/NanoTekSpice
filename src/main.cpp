/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** main
*/


#include <memory>
#include <iostream>
#include "AllElementaryComponents.hpp"
#include "AllSpecialComponents.hpp"
#include "IComponent.hpp"
#include "AComponent.hpp"
#include "proto.hpp"
#include "Parser.hpp"
#include "macros.hpp"

int main(int argc, char const* const* argv)
{
    nts::Circuit myCircuit;
    nts::Parser parser;
    if (argc != 2)
        return KO;
    else {
        if (parser.parseFile(argv[1], &myCircuit) == KO)
            return KO;
       loopNts(&myCircuit);
    }
    return OK;
}
