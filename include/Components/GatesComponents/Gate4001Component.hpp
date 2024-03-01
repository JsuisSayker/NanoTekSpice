/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4001Component
*/

#ifndef GATE4001COMPONENT_HPP_
#define GATE4001COMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Gate4001Component: virtual public nts::AComponent
    {
        public:
            Gate4001Component();
            nts::Tristate compute(std::size_t pin); 
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            nts::Tristate ThruthTable(nts::Tristate a);
        protected:
            std::vector<std::unique_ptr<nts::IComponent>> orComponentsList;
    };
}

#endif /* !GATE4001COMPONENT_HPP_ */
