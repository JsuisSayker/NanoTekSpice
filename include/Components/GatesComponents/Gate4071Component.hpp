/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4071Component
*/

#ifndef GATE4071COMPONENT_HPP_
#define GATE4071COMPONENT_HPP_

#include "IComponent.hpp"

namespace nts
{
    class Gate4071Component: virtual public IComponent
    {
        public:
            Gate4071Component();
            ~Gate4071Component();

            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);

        protected:
        private:
    };
}

#endif /* !GATE4071COMPONENT_HPP_ */
