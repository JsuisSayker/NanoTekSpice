/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4071Component
*/

#include <memory>
#include "ElementaryComponents/OrComponent.hpp"
#include "GatesComponents/Gate4071Component.hpp"

nts::Gate4071Component::Gate4071Component()
{
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(nullptr, 0));

    std::unique_ptr<nts::IComponent> or1 = std::make_unique<nts::OrComponent>();
    std::unique_ptr<nts::IComponent> or2 = std::make_unique<nts::OrComponent>();
    std::unique_ptr<nts::IComponent> or3 = std::make_unique<nts::OrComponent>();
    std::unique_ptr<nts::IComponent> or4 = std::make_unique<nts::OrComponent>();

    this->link[0].first->setLink(1, *or1, 1);
    this->link[1].first->setLink(2, *or1, 2);
    this->link[2].first->setLink(3, *or1, 3);

    this->link[3].first->setLink(4, *or2, 3);
    this->link[4].first->setLink(5, *or2, 1);
    this->link[5].first->setLink(6, *or2, 2);

    this->link[7].first->setLink(8, *or3, 1);
    this->link[8].first->setLink(9, *or3, 2);
    this->link[9].first->setLink(10, *or3, 3);

    this->link[10].first->setLink(11, *or4, 3);
    this->link[11].first->setLink(12, *or4, 1);
    this->link[12].first->setLink(13, *or4, 2);
}

nts::Gate4071Component::~Gate4071Component()
{
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