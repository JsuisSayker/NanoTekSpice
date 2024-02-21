/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** NotComponent
*/

#ifndef NOTCOMPONENT_HPP_
#define NOTCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class NotComponent: virtual public nts::AComponent {
        public:
            NotComponent();
            nts::Tristate compute(std::size_t pin);
            nts::Tristate ThruthTable(nts::Tristate a);
    };
}

#endif /* !NOTCOMPONENT_HPP_ */
