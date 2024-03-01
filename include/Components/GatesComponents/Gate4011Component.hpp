/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4011Component
*/

#ifndef GATE4011COMPONENT_HPP_
#define GATE4011COMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Gate4011Component: virtual public nts::AComponent
    {
        public:
            Gate4011Component();
            nts::Tristate compute(std::size_t pin); 
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            nts::Tristate ThruthTable(nts::Tristate a);
        protected:
            std::vector<std::unique_ptr<nts::IComponent>> andComponentsList;
    };
}

#endif /* !GATE4011COMPONENT_HPP_ */
