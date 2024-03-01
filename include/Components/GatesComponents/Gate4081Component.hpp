/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4081Component
*/

#ifndef GATE4081COMPONENT_HPP_
#define GATE4081COMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Gate4081Component: virtual public nts::AComponent
    {
        public:
            Gate4081Component();
            nts::Tristate compute(std::size_t pin); 
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        protected:
            std::vector<std::unique_ptr<nts::IComponent>> andComponentsList;
    };
}

#endif /* !GATE4081COMPONENT_HPP_ */
