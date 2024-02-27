/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ClockComponent
*/

#include "SpecialComponents/ClockComponent.hpp"

nts::ClockComponent::ClockComponent()
{
    this->value = nts::Undefined;
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw "Error: pin index out of range";
    return this->value;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    if (this->value == nts::True)
        this->value = nts::False;
    else
        this->value = nts::True;
}