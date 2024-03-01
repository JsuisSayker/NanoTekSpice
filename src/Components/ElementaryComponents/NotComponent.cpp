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
    if (pin != 1)
        throw "Error: pin index not valid";
    return ThruthTable(link[0].first->compute(link[0].second));
}
