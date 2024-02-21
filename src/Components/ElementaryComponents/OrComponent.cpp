/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** OrComponent
*/

#include "ElementaryComponents/OrComponent.hpp"

nts::OrComponent::OrComponent(): nts::AComponent()
{
    link.push_back(std::make_pair(nullptr, 0));
    link.push_back(std::make_pair(nullptr, 0));
}

nts::Tristate nts::OrComponent::ThruthTable(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::True || b == nts::Tristate::True)
        return nts::Tristate::True;
    if (a == nts::Tristate::False && b == nts::Tristate::False)
        return nts::Tristate::False;
    else
        return nts::Tristate::Undefined;
}

nts::Tristate nts::OrComponent::compute(std::size_t pin)
{
    if (pin == 1)
        return link[0].first->compute(link[0].second);
    if (pin == 2)
        return link[1].first->compute(link[1].second);
    else
        return ThruthTable(link[0].first->compute(link[0].second), link[1].first->compute(link[1].second));
}
