/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** Acomponent
*/

#include "AComponent.hpp"

nts::AComponent::AComponent()
{
}

void nts::AComponent::setLink(size_t pin, IComponent &other, size_t otherPin)
{
    if (pin > 0 && pin <= link.size())
        link[pin - 1] = std::make_pair(&other, otherPin);
    else
        std::cerr << "Error: Pin number out of range\n";
}

nts::Tristate nts::AComponent::getLink(size_t pin) const
{
    return nts::Tristate::Undefined;
}

std::ostream &operator<<(std::ostream &s, nts::Tristate v)
{
    switch (v)
    {
    case nts::Undefined:
        return s << "U";
    case nts::False:
        return s << "0";
    case nts::True:
        return s << "1";
    default:
        return s;
    }
}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    return this->link[pin].first->compute(this->link[pin].second);
}