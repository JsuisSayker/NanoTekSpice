/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** FalseCompenent
*/

#ifndef FALSECOMPENENT_HPP_
#define FALSECOMPENENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class FalseComponent: virtual public nts::AComponent {
        public:
            FalseComponent();
            nts::Tristate compute(std::size_t pin);
    };
}

#endif /* !FALSECOMPENENT_HPP_ */
