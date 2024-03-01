/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4030Component
*/

#ifndef GATE4030COMPONENT_HPP_
#define GATE4030COMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Gate4030Component: virtual public nts::AComponent
    {
        public:
            Gate4030Component();
            nts::Tristate compute(std::size_t pin); 
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        protected:
            std::vector<std::unique_ptr<nts::IComponent>> xorComponentsList;
    };
}

#endif /* !GATE4030COMPONENT_HPP_ */
