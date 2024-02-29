/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"
#include "AllElementaryComponents.hpp"
#include "AllSpecialComponents.hpp"

nts::ComponentFactory::ComponentFactory()
{
    componentCreator["and"] = [this](){ return createAndComponent();};
    componentCreator["or"] = [this](){ return createOrComponent();};
    componentCreator["not"] = [this](){ return createNotComponent();};
    componentCreator["xor"] = [this](){ return createXorComponent();};
    componentCreator["false"] = [this](){ return createFalseComponent();};
    componentCreator["true"] = [this](){ return createTrueComponent();};
    componentCreator["input"] = [this](){ return createInputComponent();};
    componentCreator["output"] = [this](){ return createOutputComponent();};
    componentCreator["clock"] = [this](){ return createClockComponent();};
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type)
{
    auto it = componentCreator.find(type);
    if (it != componentCreator.end())
        return it->second();
    return nullptr;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createAndComponent()
{
    return std::make_unique<nts::AndComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createOrComponent()
{
    return std::make_unique<nts::OrComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createNotComponent()
{
    return std::make_unique<nts::NotComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createXorComponent()
{
    return std::make_unique<nts::XorComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createFalseComponent()
{
    return std::make_unique<nts::FalseComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createTrueComponent()
{
    return std::make_unique<nts::TrueComponent>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createInputComponent()
{
    return std::make_unique<nts::Input>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createOutputComponent()
{
    return std::make_unique<nts::Output>();
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createClockComponent()
{
    return std::make_unique<nts::ClockComponent>();
}

nts::ComponentFactory::~ComponentFactory()
{
}
