/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** input
*/

#ifndef INPUT_COMPONENT_HPP_
#define INPUT_COMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Input: virtual public nts::AComponent
    {
        public:
            Input();
            ~Input();
            nts::Tristate compute(std::size_t pin);
            void setValue(nts::Tristate value);
            void simulate(std::size_t tick);

        protected:
            nts::Tristate value;
            nts::Tristate newValue;
    };
}

#endif /* !INPUT_COMPONENT_HPP_ */
