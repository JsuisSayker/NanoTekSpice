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

int main(int argc, char const* const* argv)
{
    nts::Circuit myCircuit;
    nts::Parser parser;
    if (argc == 2)
        parser.parseFile(argv[1], &myCircuit);

    std::unique_ptr<nts::IComponent> gate = std::make_unique<nts::AndComponent>();
    std::unique_ptr<nts::IComponent> input1 = std::make_unique<nts::FalseComponent>();
    std::unique_ptr<nts::IComponent> input2 = std::make_unique<nts::TrueComponent>();
    std::unique_ptr<nts::IComponent> inverter = std::make_unique<nts::NotComponent>();
    gate->setLink(1, *input1, 1);
    gate->setLink(2, *input2, 1);
    inverter->setLink(1, *gate, 3);
    std::cout << "!(" << input1->compute(1) << " && " << input2->compute(1) << ") -> " << inverter->compute(2) << std::endl;
    loopNts(&myCircuit);
}
