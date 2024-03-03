/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** AndComponent
*/

#ifndef ANDCOMPONENT_HPP_
#define ANDCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class AndComponent: public nts::AComponent {
        public:
            AndComponent();
            nts::Tristate compute(std::size_t pin);
            nts::Tristate ThruthTable(nts::Tristate a, nts::Tristate b);
            void setLink(size_t pin, IComponent &other, size_t otherPin);
    };
}

#endif /* !ANDCOMPONENT_HPP_ */
