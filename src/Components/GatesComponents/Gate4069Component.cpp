/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4069Component
*/

#include <memory>
#include "Parser/ComponentFactory.hpp"
#include "AllElementaryComponents.hpp"
#include "AllSpecialComponents.hpp"
#include "GatesComponents/Gate4069Component.hpp"

nts::Gate4069Component::Gate4069Component()
{
    ComponentFactory cf;

    this->invComponentsList.push_back(cf.createNotComponent());
    this->invComponentsList.push_back(cf.createNotComponent());
    this->invComponentsList.push_back(cf.createNotComponent());
    this->invComponentsList.push_back(cf.createNotComponent());
    this->invComponentsList.push_back(cf.createNotComponent());
    this->invComponentsList.push_back(cf.createNotComponent());

    this->link.push_back(std::make_pair(this->invComponentsList[0].get(), 1));
    this->link.push_back(std::make_pair(this->invComponentsList[0].get(), 2));
    this->link.push_back(std::make_pair(this->invComponentsList[1].get(), 1));
    this->link.push_back(std::make_pair(this->invComponentsList[1].get(), 2));
    this->link.push_back(std::make_pair(this->invComponentsList[2].get(), 1));
    this->link.push_back(std::make_pair(this->invComponentsList[2].get(), 2));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(this->invComponentsList[3].get(), 2));
    this->link.push_back(std::make_pair(this->invComponentsList[3].get(), 1));
    this->link.push_back(std::make_pair(this->invComponentsList[4].get(), 2));
    this->link.push_back(std::make_pair(this->invComponentsList[4].get(), 1));
    this->link.push_back(std::make_pair(this->invComponentsList[5].get(), 2));
    this->link.push_back(std::make_pair(this->invComponentsList[5].get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
}

nts::Tristate nts::Gate4069Component::compute(std::size_t pin)
{
    if (pin > this->link.size())
        throw "Pin does not exist";
    if (pin == 2 || pin == 4 || pin == 6)
        return this->link[pin - 2].first->compute(link[pin - 2].second);
    if (pin == 8 || pin == 10 || pin == 12)
        return this->link[pin].first->compute(link[pin].second);
    return nts::Tristate::Undefined;
}

void nts::Gate4069Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    switch (pin) {
        case 1:
            invComponentsList[0]->setLink(1, other, otherPin);
            break;
        case 2:
            invComponentsList[0]->setLink(2, other, otherPin);
            break;
        case 3:
            invComponentsList[1]->setLink(1, other, otherPin);
            break;
        case 4:
            invComponentsList[1]->setLink(2, other, otherPin);
            break;
        case 5:
            invComponentsList[2]->setLink(1, other, otherPin);
            break;
        case 6:
            invComponentsList[2]->setLink(2, other, otherPin);
            break;
        case 8:
            invComponentsList[3]->setLink(2, other, otherPin);
            break;
        case 9:
            invComponentsList[3]->setLink(1, other, otherPin);
            break;
        case 10:
            invComponentsList[4]->setLink(2, other, otherPin);
            break;
        case 11:
            invComponentsList[4]->setLink(1, other, otherPin);
            break;
        case 12:
            invComponentsList[5]->setLink(2, other, otherPin);
            break;
        case 13:
            invComponentsList[5]->setLink(1, other, otherPin);
            break;
        default:
            break;
    }
}