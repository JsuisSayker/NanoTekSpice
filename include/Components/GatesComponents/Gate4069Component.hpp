/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4069Component
*/

#ifndef GATE4069COMPONENT_HPP_
#define GATE4069COMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Gate4069Component: virtual public nts::AComponent
    {
        public:
            Gate4069Component();
            nts::Tristate compute(std::size_t pin); 
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        protected:
            std::vector<std::unique_ptr<nts::IComponent>> invComponentsList;
    };
}

#endif /* !GATE4069COMPONENT_HPP_ */
