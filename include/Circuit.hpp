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
    class Circuit: public nts::IComponent
    {
        public:
            Circuit();
            ~Circuit(){};
            void simulate(std::size_t tick);
            void addComponent(IComponent *component, std::string name);
            IComponent *findComponent(std::string name);
            void display();
        protected:
            std::vector<std::pair<IComponent *, std::string>> componentList;
            int tick;
            nts::Tristate clock;
    };
}

#endif /* !CIRCUIT_HPP_ */
