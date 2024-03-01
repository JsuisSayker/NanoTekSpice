/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4071Component
*/

#include <memory>
#include "Parser/ComponentFactory.hpp"
#include "ElementaryComponents/OrComponent.hpp"
#include "GatesComponents/Gate4071Component.hpp"

nts::Gate4071Component::Gate4071Component()
{
    ComponentFactory cf;
    std::unique_ptr<nts::IComponent> or1 = cf.createOrComponent();
    std::unique_ptr<nts::IComponent> or2 = cf.createOrComponent();
    std::unique_ptr<nts::IComponent> or3 = cf.createOrComponent();
    std::unique_ptr<nts::IComponent> or4 = cf.createOrComponent();

    this->link.push_back(std::make_pair(or1.get(), 1));
    this->link.push_back(std::make_pair(or1.get(), 2));
    this->link.push_back(std::make_pair(or1.get(), 3));
    this->link.push_back(std::make_pair(or2.get(), 3));
    this->link.push_back(std::make_pair(or2.get(), 2));
    this->link.push_back(std::make_pair(or2.get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(or3.get(), 1));
    this->link.push_back(std::make_pair(or3.get(), 2));
    this->link.push_back(std::make_pair(or3.get(), 3));
    this->link.push_back(std::make_pair(or4.get(), 3));
    this->link.push_back(std::make_pair(or4.get(), 2));
    this->link.push_back(std::make_pair(or4.get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
}

nts::Tristate nts::Gate4071Component::compute(std::size_t pin)
{
    if (pin == 3)
        return this->link[0].first->compute(this->link[0].second);
    if (pin == 4)
        return this->link[3].first->compute(this->link[3].second);
    if (pin == 10)
        return this->link[7].first->compute(this->link[7].second);
    if (pin == 11)
        return this->link[10].first->compute(this->link[10].second);
    return nts::Tristate::Undefined;
}