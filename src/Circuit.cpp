/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "SpecialComponents/InputComponent.hpp"
#include "SpecialComponents/OutputComponent.hpp"
#include "SpecialComponents/ClockComponent.hpp"

nts::Circuit::Circuit()
{
    tick = 0;
}

void nts::Circuit::addComponent(IComponent *component, std::string name)
{
    this->componentList[name] = component;
}

nts::IComponent *nts::Circuit::findComponent(std::string name)
{
    return componentList[name];
}

void nts::Circuit::simulate(std::size_t tick)
{
    this->tick = tick + 1;
    for (std::pair<std::string, IComponent *> component : componentList)
        component.second->simulate(tick);
}

int nts::Circuit::getTick()
{
    return this->tick;
}

void nts::Circuit::display()
{
    std::cout << "tick: " << this->tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (std::pair<std::string, IComponent *> component : componentList) {
        if (dynamic_cast<nts::ClockComponent *>(component.second))
            std::cout << "  " << component.first << ": " << component.second->compute(1) << std::endl;
        if (dynamic_cast<nts::Input *>(component.second))
            std::cout << "  " << component.first << ": " << component.second->compute(1) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (std::pair<std::string, IComponent *> component : componentList) {
        if (dynamic_cast<nts::Output *>(component.second))
            std::cout << "  " << component.first << ": " << component.second->compute(1) << std::endl;
    }
}
