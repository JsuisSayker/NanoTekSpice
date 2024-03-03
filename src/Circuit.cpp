/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include <iostream>
#include "Parser/ParserExceptions.hpp"
#include "AllSpecialComponents.hpp"

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
        const std::unique_ptr<nts::IComponent>& componentPtr = pair.second;
        componentPtr->simulate(tick);
    }
}

void nts::Circuit::setState(std::string name, std::string value)
{
    for (const auto& pair : componentList) {
        const std::string& nameComponent = pair.first;
        const std::unique_ptr<nts::IComponent>& componentPtr = pair.second;
        if (nameComponent == name) {
            nts::Input* inputComponent = dynamic_cast<nts::Input*>(componentPtr.get());
            nts::Output* outputComponent = dynamic_cast<nts::Output*>(componentPtr.get());
            nts::ClockComponent* clockComponent = dynamic_cast<nts::ClockComponent*>(componentPtr.get());
            if (inputComponent != nullptr) {
                inputComponent->setValue(getTristateValue(value));
                return;
            }
            if (outputComponent != nullptr) {
                outputComponent->setValue(getTristateValue(value));
                return;
            }
            if (clockComponent != nullptr) {
                clockComponent->setValue(getTristateValue(value));
                return;
            } else {
                try {
                    throw UnknownComponentName("This component does not exist.");
                } catch (UnknownComponentName &e) {
                    std::cerr << e.what() << std::endl;
                }
            }
        }
    }

}

nts::Tristate nts::Circuit::getTristateValue(std::string name)
{
    if (name == "U")
        return nts::Tristate::Undefined;
    if (name == "1")
        return nts::Tristate::True;
    if (name == "0")
        return nts::Tristate::False;
    return nts::Tristate::Undefined;
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
