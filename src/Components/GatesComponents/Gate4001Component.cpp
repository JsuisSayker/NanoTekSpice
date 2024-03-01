/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4001Component
*/

#include <memory>
#include "Parser/ComponentFactory.hpp"
#include "AllElementaryComponents.hpp"
#include "AllSpecialComponents.hpp"
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

    not1->setLink(1, *or1.get(), 3);
    not2->setLink(1, *or2.get(), 3);
    not3->setLink(1, *or3.get(), 3);
    not4->setLink(1, *or4.get(), 3);
    
    this->link.push_back(std::make_pair(or1.get(), 1));
    this->link.push_back(std::make_pair(or1.get(), 2));
    this->link.push_back(std::make_pair(not1.get(), 1));
    this->link.push_back(std::make_pair(not2.get(), 1));
    this->link.push_back(std::make_pair(or2.get(), 2));
    this->link.push_back(std::make_pair(or2.get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(or3.get(), 1));
    this->link.push_back(std::make_pair(or3.get(), 2));
    this->link.push_back(std::make_pair(not3.get(), 1));
    this->link.push_back(std::make_pair(not4.get(), 1));
    this->link.push_back(std::make_pair(or4.get(), 2));
    this->link.push_back(std::make_pair(or4.get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
}

nts::Tristate nts::Gate4001Component::compute(std::size_t pin)
{
    if (pin > this->link.size())
        throw "Pin does not exist";
    printf("\npin: %ld\n", pin);
    if (dynamic_cast<nts::NotComponent *>(this->link[pin - 1].first))
        printf("NotComponent\n");
    if (dynamic_cast<nts::OrComponent *>(this->link[pin - 1].first))
        printf("OrComponent\n");
    if (dynamic_cast<nts::Input *>(this->link[pin - 1].first))
        printf("Input\n");
    if (dynamic_cast<nts::Output *>(this->link[pin - 1].first))
        printf("Output\n");
    return this->link[pin - 1].first->compute(this->link[pin - 1].second);
}