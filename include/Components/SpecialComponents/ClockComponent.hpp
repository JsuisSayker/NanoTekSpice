/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** clockComponent
*/

#ifndef CLOCKCOMPONENT_HPP_
#define CLOCKCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class ClockComponent : virtual public nts::AComponent
    {
        public:
            ClockComponent();
            ~ClockComponent(){};
            nts::Tristate compute(std::size_t pin);
            void simulate(std::size_t tick);
        protected:
            nts::Tristate value;
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */
