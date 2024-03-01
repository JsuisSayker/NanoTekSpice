/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** loop
*/

#include "IComponent.hpp"
#include "Circuit.hpp"
#include "ParserExceptions.hpp"
#include <csignal>

bool isLoopRunning;

void signalHandler(int signum)
{
    if (signum == SIGINT)
        isLoopRunning = false;
}

void loopCommand(nts::Circuit *circuit, bool *isLoopRunning)
{
    while ((*isLoopRunning))
    {
        circuit->simulate(circuit->getTick());
        circuit->display();
    }
}

void newStateValue(nts::Circuit *circuit, std::string name, std::string value)
{

    if (value != "0" && value != "1" && value != "U") {
        try {
            throw UnknownComponentName("This value does not exist.");
        } catch (UnknownComponentName &e) {
            std::cerr << e.what() << std::endl;
        }
    } else
        circuit->setState(name, value);
}

void changeValue(nts::Circuit *circuit, std::string line)
{
    std::string name;
    std::string value;
    size_t pos = line.find("=");
    if (pos != std::string::npos) {
        name = line.substr(0, pos);
        value = line.substr(pos + 1);
        nts::IComponent *component = circuit->findComponent(name);
        if (component == nullptr) {
            try {
                throw UnknownComponentName("This component does not exist.");
            } catch (UnknownComponentName &e) {
                std::cerr << e.what() << std::endl;
            }
        }
        newStateValue(circuit, name, value);
    }
}

int loopNts(nts::Circuit *circuit)
{
    std::string line;
    bool mainRunner = true;
    signal(SIGINT, signalHandler);
    while (mainRunner)
    {
        isLoopRunning = true;
        std::cout << "> ";
        if (!std::getline(std::cin, line)) {
            if (std::cin.eof())
                mainRunner = false;
        }
        if (line == "exit")
            mainRunner = false;
        if (line == "simulate")
            circuit->simulate(circuit->getTick());
        if (line == "display")
            circuit->display();
        if (line == "loop")
            loopCommand(circuit, &isLoopRunning);
        changeValue(circuit, line);
    }
    return 0;
}
