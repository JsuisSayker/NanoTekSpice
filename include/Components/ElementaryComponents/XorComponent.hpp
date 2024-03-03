/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** XorComponent
*/

#ifndef XORCOMPONENT_HPP_
#define XORCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class XorComponent: virtual public nts::AComponent {
        public:
            XorComponent();
            nts::Tristate compute(std::size_t pin);
            nts::Tristate ThruthTable(nts::Tristate a, nts::Tristate b);
            void setLink(size_t pin, IComponent &other, size_t otherPin);
    };
}

#endif /* !XORCOMPONENT_HPP_ */
