/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** inputComponent
*/

#include "SpecialComponents/InputComponent.hpp"

nts::Input::Input()
{
    link.push_back(std::make_pair(nullptr, 0));
    this->value = nts::Undefined;
}

nts::Input::~Input()
{
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
    if (pin != 1)
        throw "Error: pin index out of range";
    return this->value;
}

void nts::Input::setValue(nts::Tristate value)
{
    this->value = value;
}
