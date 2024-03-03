/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <map>
#include <memory>
#include "IComponent.hpp"

namespace nts
{
    class Circuit: virtual public nts::IComponent
    {
        public:
            Circuit();
            ~Circuit(){};
            void simulate(std::size_t tick);
            void addComponent(std::unique_ptr<nts::IComponent> &component, std::string name);
            IComponent *findComponent(std::string name);
            void display();
            int getTick();
            nts::Tristate compute(std::size_t pin){(void)pin;return nts::Tristate::Undefined;};
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin){(void)pin;(void)other;(void)otherPin;};
            void setState(std::string name, std::string value);
            nts::Tristate getTristateValue(std::string name);

        protected:
            std::map<std::string, std::unique_ptr<nts::IComponent>> componentList;
            int tick;
            nts::Tristate clock;
    };
}

#endif /* !CIRCUIT_HPP_ */
