/*
** EPITECH PROJECT, 2024
** bs_NanoTekSpice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <cstddef>
#include "IComponent.hpp"
#include <vector>

namespace nts
{
    class AComponent: virtual public nts::IComponent
    {
    public:
        AComponent();
        virtual ~AComponent() = default;

        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void simulate(std::size_t tick) override {(void)tick;}
        void setLink(size_t pin, IComponent &other, size_t otherPin);

    protected:
        std::vector<std::pair<IComponent *, size_t>> link;
    };
}

std::ostream &operator<<(std::ostream &s, nts::Tristate v);

#endif /* !ACOMPONENT_HPP_ */
