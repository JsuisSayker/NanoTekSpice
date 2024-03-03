/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** FalseComponent
*/

#include "SpecialComponents/FalseComponent.hpp"

nts::FalseComponent::FalseComponent(): nts::AComponent()
{
}

nts::Tristate nts::FalseComponent::compute(std::size_t pin)
{
   (void)pin;
   return  nts::False;
}
