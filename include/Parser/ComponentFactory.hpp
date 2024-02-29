/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include <unordered_map>
#include <functional>
#include <string>
#include <memory>
#include "IComponent.hpp"

namespace nts {
    class ComponentFactory {
        public:
            ComponentFactory();
            ~ComponentFactory();

            std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
            std::unique_ptr<nts::IComponent> createAndComponent();
            std::unique_ptr<nts::IComponent> createOrComponent();
            std::unique_ptr<nts::IComponent> createNotComponent();
            std::unique_ptr<nts::IComponent> createXorComponent();
            std::unique_ptr<nts::IComponent> createFalseComponent();
            std::unique_ptr<nts::IComponent> createTrueComponent();
            std::unique_ptr<nts::IComponent> createInputComponent();
            std::unique_ptr<nts::IComponent> createOutputComponent();
            std::unique_ptr<nts::IComponent> createClockComponent();

        protected:
            std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> componentCreator;
    };
}

#endif /* !COMPONENTFACTORY_HPP_ */
