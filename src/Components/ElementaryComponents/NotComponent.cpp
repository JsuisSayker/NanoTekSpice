/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** NotComponent
*/

#include "ElementaryComponents/NotComponent.hpp"

nts::NotComponent::NotComponent(): nts::AComponent()
{
    link.push_back(std::make_pair(nullptr, 0));
    link.push_back(std::make_pair(nullptr, 0));
}

nts::Tristate nts::NotComponent::ThruthTable(nts::Tristate a)
{
    if (a == nts::Tristate::True)
        return nts::Tristate::False;
    if (a == nts::Tristate::False)
        return nts::Tristate::True;
    return nts::Tristate::Undefined;
}

nts::Tristate nts::NotComponent::compute(std::size_t pin)
{
    if (pin > this->link.size())
        throw "Error: pin index out of range";
    return ThruthTable(link[0].first->compute(link[0].second));
}

void nts::NotComponent::setLink(size_t pin, IComponent &other, size_t otherPin)
{
    if (pin > 0 && pin <= link.size()) {
        if (pin == 2)
            other.setLink(otherPin, *this, pin);
        link[pin - 1] = std::make_pair(&other, otherPin);
    }
    else
        std::cerr << "Error: Pin number out of range\n";
}