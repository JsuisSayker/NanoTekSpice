/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4001Component
*/

#include <memory>
#include "Parser/ComponentFactory.hpp"
#include "ElementaryComponents/OrComponent.hpp"
#include "GatesComponents/Gate4001Component.hpp"

nts::Gate4001Component::Gate4001Component()
{
    ComponentFactory cf;
    std::unique_ptr<nts::IComponent> or1 = cf.createOrComponent();
    std::unique_ptr<nts::IComponent> or2 = cf.createOrComponent();
    std::unique_ptr<nts::IComponent> or3 = cf.createOrComponent();
    std::unique_ptr<nts::IComponent> or4 = cf.createOrComponent();

    std::unique_ptr<nts::IComponent> not1 = cf.createNotComponent();
    std::unique_ptr<nts::IComponent> not2 = cf.createNotComponent();
    std::unique_ptr<nts::IComponent> not3 = cf.createNotComponent();
    std::unique_ptr<nts::IComponent> not4 = cf.createNotComponent();

    not1->setLink(1, *or1, 3);
    not2->setLink(1, *or2, 3);
    not3->setLink(1, *or3, 3);
    not4->setLink(1, *or4, 3);

    this->link.push_back(std::make_pair(not1.get(), 1));
    this->link.push_back(std::make_pair(not1.get(), 2));
    this->link.push_back(std::make_pair(not1.get(), 3));
    this->link.push_back(std::make_pair(not2.get(), 3));
    this->link.push_back(std::make_pair(not2.get(), 2));
    this->link.push_back(std::make_pair(not2.get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(not3.get(), 1));
    this->link.push_back(std::make_pair(not3.get(), 2));
    this->link.push_back(std::make_pair(not3.get(), 3));
    this->link.push_back(std::make_pair(not4.get(), 3));
    this->link.push_back(std::make_pair(not4.get(), 2));
    this->link.push_back(std::make_pair(not4.get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
}

nts::Tristate nts::Gate4001Component::compute(std::size_t pin)
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