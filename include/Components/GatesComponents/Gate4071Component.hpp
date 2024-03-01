/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4071Component
*/

#ifndef GATE4071COMPONENT_HPP_
#define GATE4071COMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Gate4071Component: virtual public nts::AComponent
    {
        public:
            Gate4071Component();
            nts::Tristate compute(std::size_t pin); 
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        protected:
            std::vector<std::unique_ptr<nts::IComponent>> orComponentsList;
    };
}

#endif /* !GATE4071COMPONENT_HPP_ */
