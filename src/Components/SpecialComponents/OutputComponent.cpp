/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** outputComponent
*/

#include "SpecialComponents/OutputComponent.hpp"

nts::Output::Output()
{
    this->value = nts::Undefined;
}

nts::Output::~Output()
{
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
    if (pin != 1)
        throw "Error: pin index out of range";
    return this->value;
}

void nts::Output::setValue(nts::Tristate value)
{
    this->value = value;
}
