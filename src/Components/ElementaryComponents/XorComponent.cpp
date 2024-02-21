/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** XorComponent
*/

#include "ElementaryComponents/XorComponent.hpp"

nts::XorComponent::XorComponent()
{
    link.push_back(std::make_pair(nullptr, 0));
    link.push_back(std::make_pair(nullptr, 0));
}

nts::Tristate nts::XorComponent::ThruthTable(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::Undefined || b == nts::Tristate::Undefined)
        return nts::Tristate::Undefined;
    if ((a == nts::Tristate::True) ^ (b == nts::Tristate::True))
        return nts::Tristate::True;
    else
        return nts::Tristate::False;
}

nts::Tristate nts::XorComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return link[0].first->compute(link[0].second);
    if (pin == 2)
        return link[1].first->compute(link[1].second);
    else
        return ThruthTable(link[0].first->compute(link[0].second), link[1].first->compute(link[1].second));
}
