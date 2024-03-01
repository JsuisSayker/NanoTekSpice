/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** Gate4081Component
*/

#include <memory>
#include "Parser/ComponentFactory.hpp"
#include "AllElementaryComponents.hpp"
#include "AllSpecialComponents.hpp"
#include "GatesComponents/Gate4081Component.hpp"

nts::Gate4081Component::Gate4081Component()
{
    ComponentFactory cf;

    this->andComponentsList.push_back(cf.createAndComponent());
    this->andComponentsList.push_back(cf.createAndComponent());
    this->andComponentsList.push_back(cf.createAndComponent());
    this->andComponentsList.push_back(cf.createAndComponent());

    this->link.push_back(std::make_pair(this->andComponentsList[0].get(), 1));
    this->link.push_back(std::make_pair(this->andComponentsList[0].get(), 2));
    this->link.push_back(std::make_pair(this->andComponentsList[0].get(), 3));
    this->link.push_back(std::make_pair(this->andComponentsList[1].get(), 3));
    this->link.push_back(std::make_pair(this->andComponentsList[1].get(), 2));
    this->link.push_back(std::make_pair(this->andComponentsList[1].get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
    this->link.push_back(std::make_pair(this->andComponentsList[2].get(), 1));
    this->link.push_back(std::make_pair(this->andComponentsList[2].get(), 2));
    this->link.push_back(std::make_pair(this->andComponentsList[2].get(), 3));
    this->link.push_back(std::make_pair(this->andComponentsList[3].get(), 3));
    this->link.push_back(std::make_pair(this->andComponentsList[3].get(), 2));
    this->link.push_back(std::make_pair(this->andComponentsList[3].get(), 1));
    this->link.push_back(std::make_pair(nullptr, 0));
}

nts::Tristate nts::Gate4081Component::compute(std::size_t pin)
{
    if (pin > this->link.size())
        throw "Pin does not exist";
    return link[pin - 1].first->compute(link[pin - 1].second);
}

void nts::Gate4081Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    switch (pin) {
        case 1:
            andComponentsList[0]->setLink(1, other, otherPin);
            break;
        case 2:
            andComponentsList[0]->setLink(2, other, otherPin);
            break;
        case 3:
            andComponentsList[0]->setLink(3, other, otherPin);
            break;
        case 4:
            andComponentsList[1]->setLink(3, other, otherPin);
            break;
        case 5:
            andComponentsList[1]->setLink(2, other, otherPin);
            break;
        case 6:
            andComponentsList[1]->setLink(1, other, otherPin);
            break;
        case 8:
            andComponentsList[2]->setLink(1, other, otherPin);
            break;
        case 9:
            andComponentsList[2]->setLink(2, other, otherPin);
            break;
        case 10:
            andComponentsList[2]->setLink(3, other, otherPin);
            break;
        case 11:
            andComponentsList[3]->setLink(3, other, otherPin);
            break;
        case 12:
            andComponentsList[3]->setLink(2, other, otherPin);
            break;
        case 13:
            andComponentsList[3]->setLink(1, other, otherPin);
            break;
        default:
            break;
    }
}