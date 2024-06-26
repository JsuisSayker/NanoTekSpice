/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ClockComponent
*/

#include "SpecialComponents/ClockComponent.hpp"

nts::ClockComponent::ClockComponent()
{
    link.push_back(std::make_pair(nullptr, 0));
    this->value = nts::Undefined;
    this->firstValue = true;
}

nts::ClockComponent::~ClockComponent()
{
}

nts::Tristate nts::ClockComponent::compute(std::size_t pin)
{
    if (pin != 1)
        throw "Error: pin index out of range";
    return this->value;
}

void nts::ClockComponent::simulate(std::size_t tick)
{
    (void)tick;
    if (this->firstValue == true && this->value != nts::Undefined) {
        this->firstValue = false;
        return;
    }
    if (this->value == nts::False)
        this->value = nts::True;
    else if (this->value == nts::True)
        this->value = nts::False;
}

void nts::ClockComponent::setValue(nts::Tristate value)
{
    this->value = value;
}