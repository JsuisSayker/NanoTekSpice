/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <vector>
#include "IComponent.hpp"

namespace nts
{
    class Circuit: virtual public nts::IComponent
    {
        public:
            Circuit();
            ~Circuit(){};
            void simulate(std::size_t tick);
            void addComponent(IComponent *component, std::string name);
            IComponent *findComponent(std::string name);
            void display();

            nts::Tristate compute(std::size_t pin){return nts::Tristate::Undefined;};
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin){};

        protected:
            std::vector<std::pair<IComponent *, std::string>> componentList;
            int tick;
            nts::Tristate clock;
    };
}

#endif /* !CIRCUIT_HPP_ */
