/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4030Component
*/

#include <memory>
#include "Parser/ComponentFactory.hpp"
#include "AllElementaryComponents.hpp"
#include "AllSpecialComponents.hpp"
#include "GatesComponents/Gate4030Component.hpp"

nts::Gate4030Component::Gate4030Component()
{
    ComponentFactory cf;

    this->xorComponentsList.push_back(cf.createXorComponent());
    this->xorComponentsList.push_back(cf.createXorComponent());
    this->xorComponentsList.push_back(cf.createXorComponent());
    this->xorComponentsList.push_back(cf.createXorComponent());

    this->link.push_back(std::make_pair(this->xorComponentsList[0].get(), 1));
    this->link.push_back(std::make_pair(this->xorComponentsList[0].get(), 2));
    this->link.push_back(std::make_pair(this->xorComponentsList[0].get(), 3));
    this->link.push_back(std::make_pair(this->xorComponentsList[1].get(), 3));
    this->link.push_back(std::make_pair(this->xorComponentsList[1].get(), 2));
    this->link.push_back(std::make_pair(this->xorComponentsList[1].get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(this->xorComponentsList[2].get(), 1));
    this->link.push_back(std::make_pair(this->xorComponentsList[2].get(), 2));
    this->link.push_back(std::make_pair(this->xorComponentsList[2].get(), 3));
    this->link.push_back(std::make_pair(this->xorComponentsList[3].get(), 3));
    this->link.push_back(std::make_pair(this->xorComponentsList[3].get(), 2));
    this->link.push_back(std::make_pair(this->xorComponentsList[3].get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
}

nts::Tristate nts::Gate4030Component::compute(std::size_t pin)
{
    if (pin > this->link.size())
        throw "Pin does not exist";
    return link[pin - 1].first->compute(link[pin - 1].second);
}

void nts::Gate4030Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    switch (pin) {
        case 1:
            xorComponentsList[0]->setLink(1, other, otherPin);
            break;
        case 2:
            xorComponentsList[0]->setLink(2, other, otherPin);
            break;
        case 3:
            xorComponentsList[0]->setLink(3, other, otherPin);
            break;
        case 4:
            xorComponentsList[1]->setLink(3, other, otherPin);
            break;
        case 5:
            xorComponentsList[1]->setLink(2, other, otherPin);
            break;
        case 6:
            xorComponentsList[1]->setLink(1, other, otherPin);
            break;
        case 8:
            xorComponentsList[2]->setLink(1, other, otherPin);
            break;
        case 9:
            xorComponentsList[2]->setLink(2, other, otherPin);
            break;
        case 10:
            xorComponentsList[2]->setLink(3, other, otherPin);
            break;
        case 11:
            xorComponentsList[3]->setLink(3, other, otherPin);
            break;
        case 12:
            xorComponentsList[3]->setLink(2, other, otherPin);
            break;
        case 13:
            xorComponentsList[3]->setLink(1, other, otherPin);
            break;
        default:
            break;
    }
}