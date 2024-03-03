/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
#define ORCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class OrComponent: virtual public nts::AComponent {
        public:
            OrComponent();
            nts::Tristate compute(std::size_t pin);
            nts::Tristate ThruthTable(nts::Tristate a, nts::Tristate b);
            void setLink(size_t pin, IComponent &other, size_t otherPin);
    };
}

#endif /* !ORCOMPONENT_HPP_ */
