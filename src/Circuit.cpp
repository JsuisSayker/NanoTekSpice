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
    this->componentList.push_back(std::make_pair(component, name));
}

nts::IComponent *nts::Circuit::findComponent(std::string name)
{
    for (int i = 0; i < componentList.size(); i++) {
        if (componentList[i].second == name)
            return componentList[i].first;
    }
    return nullptr;
}

void nts::Circuit::simulate(std::size_t tick)
{
    this->tick = tick + 1;
    for (int i = 0; i < componentList.size(); i++)
        componentList[i].first->simulate(tick);
}

void nts::Circuit::display()
{
    std::cout << "tick: " << this->tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (int i = 0; i < componentList.size(); i++) {
        if (dynamic_cast<nts::ClockComponent *>(componentList[i].first))
            std::cout << componentList[i].second << ":" << componentList[i].first->compute(1) << std::endl;
        if (dynamic_cast<nts::Input *>(componentList[i].first))
            std::cout << componentList[i].second << ":" << componentList[i].first->compute(1) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (int i = 0; i < componentList.size(); i++) {
        if (dynamic_cast<nts::Output *>(componentList[i].first))
            std::cout << componentList[i].second << ":" << componentList[i].first->compute(1) << std::endl;
    }
}