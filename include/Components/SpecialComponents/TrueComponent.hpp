/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** TrueComponent
*/

#ifndef TRUECOMPONENT_HPP_
#define TRUECOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class TrueComponent: virtual public nts::AComponent {
        public:
            TrueComponent();
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !TRUECOMPONENT_HPP_ */
