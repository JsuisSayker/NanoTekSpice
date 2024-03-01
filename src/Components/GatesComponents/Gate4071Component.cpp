/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4071Component
*/

#include <memory>
#include "Parser/ComponentFactory.hpp"
#include "AllElementaryComponents.hpp"
#include "AllSpecialComponents.hpp"
#include "GatesComponents/Gate4071Component.hpp"

nts::Gate4071Component::Gate4071Component()
{
    ComponentFactory cf;

    this->orComponentsList.push_back(cf.createOrComponent());
    this->orComponentsList.push_back(cf.createOrComponent());
    this->orComponentsList.push_back(cf.createOrComponent());
    this->orComponentsList.push_back(cf.createOrComponent());

    this->link.push_back(std::make_pair(this->orComponentsList[0].get(), 1));
    this->link.push_back(std::make_pair(this->orComponentsList[0].get(), 2));
    this->link.push_back(std::make_pair(this->orComponentsList[0].get(), 3));
    this->link.push_back(std::make_pair(this->orComponentsList[1].get(), 3));
    this->link.push_back(std::make_pair(this->orComponentsList[1].get(), 2));
    this->link.push_back(std::make_pair(this->orComponentsList[1].get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(this->orComponentsList[2].get(), 1));
    this->link.push_back(std::make_pair(this->orComponentsList[2].get(), 2));
    this->link.push_back(std::make_pair(this->orComponentsList[2].get(), 3));
    this->link.push_back(std::make_pair(this->orComponentsList[3].get(), 3));
    this->link.push_back(std::make_pair(this->orComponentsList[3].get(), 2));
    this->link.push_back(std::make_pair(this->orComponentsList[3].get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
}

nts::Tristate nts::Gate4071Component::compute(std::size_t pin)
{
    if (pin > this->link.size())
        throw "Pin does not exist";
    return link[pin - 1].first->compute(link[pin - 1].second);
}

void nts::Gate4071Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    switch (pin) {
        case 1:
            orComponentsList[0]->setLink(1, other, otherPin);
            break;
        case 2:
            orComponentsList[0]->setLink(2, other, otherPin);
            break;
        case 3:
            orComponentsList[0]->setLink(3, other, otherPin);
            break;
        case 4:
            orComponentsList[1]->setLink(3, other, otherPin);
            break;
        case 5:
            orComponentsList[1]->setLink(2, other, otherPin);
            break;
        case 6:
            orComponentsList[1]->setLink(1, other, otherPin);
            break;
        case 8:
            orComponentsList[2]->setLink(1, other, otherPin);
            break;
        case 9:
            orComponentsList[2]->setLink(2, other, otherPin);
            break;
        case 10:
            orComponentsList[2]->setLink(3, other, otherPin);
            break;
        case 11:
            orComponentsList[3]->setLink(3, other, otherPin);
            break;
        case 12:
            orComponentsList[3]->setLink(2, other, otherPin);
            break;
        case 13:
            orComponentsList[3]->setLink(1, other, otherPin);
            break;
        default:
            break;
    }
}