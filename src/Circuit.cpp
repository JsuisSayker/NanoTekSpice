/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include <iostream>
#include "SpecialComponents/InputComponent.hpp"
#include "SpecialComponents/OutputComponent.hpp"
#include "SpecialComponents/ClockComponent.hpp"

nts::Circuit::Circuit()
{
    tick = 0;
}

void nts::Circuit::addComponent(std::unique_ptr<nts::IComponent> &component, std::string name)
{
    componentList[name] = std::move(component);
}

nts::IComponent *nts::Circuit::findComponent(std::string name)
{
    for (const auto& pair : componentList) {
        const std::string& nameComponent = pair.first;
        const std::unique_ptr<nts::IComponent>& componentPtr = pair.second;
        if (nameComponent == name)
            return componentPtr.get();
    }
    return nullptr;
}

void nts::Circuit::simulate(std::size_t tick)
{
    this->tick = tick + 1;
    for (const auto& pair : componentList) {
        const std::string& name = pair.first;
        const std::unique_ptr<nts::IComponent>& componentPtr = pair.second;
        componentPtr->simulate(tick);
    }
}

int nts::Circuit::getTick()
{
    return this->tick;
}

void nts::Circuit::display()
{
    std::cout << "tick: " << this->tick << std::endl;
    std::cout << "input(s):" << std::endl;
    for (const auto& pair : componentList) {
        const std::string& name = pair.first;
        const std::unique_ptr<nts::IComponent>& componentPtr = pair.second;
        if (dynamic_cast<nts::ClockComponent *>(componentPtr.get()))
            std::cout << "  " << name << ": " << componentPtr->compute(1) << std::endl;
        if (dynamic_cast<nts::Input *>(componentPtr.get()))
            std::cout << "  " << name << ": " << componentPtr->compute(1) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (const auto& pair : componentList) {
        const std::string& name = pair.first;
        const std::unique_ptr<nts::IComponent>& componentPtr = pair.second;
        if (dynamic_cast<nts::Output *>(componentPtr.get()))
            std::cout << "  " << name << ": " << componentPtr->compute(1) << std::endl;
    }
}
