/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** TrueComponent
*/

#include "SpecialComponents/TrueComponent.hpp"

nts::TrueComponent::TrueComponent(): nts::AComponent()
{
}

nts::Tristate nts::TrueComponent::compute(std::size_t pin)
{
    (void)pin;
    return nts::True;
}