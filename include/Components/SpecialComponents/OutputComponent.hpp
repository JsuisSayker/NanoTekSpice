/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** output
*/

#ifndef OUTPUT_COMPONENT_HPP_
#define OUTPUT_COMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Output: virtual public nts::AComponent
    {
        public:
            Output();
            ~Output();
            nts::Tristate compute(std::size_t pin);
            void setValue(nts::Tristate value);
        protected:
            nts::Tristate value;
    };
}

#endif /* !OUTPUT_COMPONENT_HPP_ */
