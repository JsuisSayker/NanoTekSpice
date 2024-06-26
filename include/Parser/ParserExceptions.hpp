/*
** EPITECH PROJECT, 2024
** NanoTekSpice
** File description:
** ParserExceptions
*/

#ifndef PARSEREXCEPTIONS_HPP_
#define PARSEREXCEPTIONS_HPP_

#include <exception>
#include <string>

class InvalidFileException : public std::exception {
    public:
        InvalidFileException(const std::string &message) : _message(message) {}
        const char *what() const noexcept override { return _message.c_str(); }

    private:
        std::string _message;
};

class InvalidSectionException : public std::exception {
    public:
        InvalidSectionException(const std::string &message) : _message(message) {}
        const char *what() const noexcept override { return _message.c_str(); }

    private:
        std::string _message;
};

class MissingSectionException : public std::exception {
    public:
        MissingSectionException(const std::string &message) : _message(message) {}
        const char *what() const noexcept override { return _message.c_str(); }

    private:
        std::string _message;
};

class UnknownSectionName : public std::exception {
    public:
        UnknownSectionName(const std::string &message) : _message(message) {}
        const char *what() const noexcept override { return _message.c_str(); }

    private:
        std::string _message;
};

class UnknownComponentType : public std::exception {
    public:
        UnknownComponentType(const std::string &message) : _message(message) {}
        const char *what() const noexcept override { return _message.c_str(); }

    private:
        std::string _message;
};

class UnknownComponentName : public std::exception {
    public:
        UnknownComponentName(const std::string &message) : _message(message) {}
        const char *what() const noexcept override { return _message.c_str(); }

    private:
        std::string _message;
};

class InvalidLinkException : public std::exception {
    public:
        InvalidLinkException(const std::string &message) : _message(message) {}
        const char *what() const noexcept override { return _message.c_str(); }

    private:
        std::string _message;
};

class ComponentNameAlreadyExists : public std::exception {
    public:
        ComponentNameAlreadyExists(const std::string &message) : _message(message) {}
        const char *what() const noexcept override { return _message.c_str(); }

    private:
        std::string _message;
};

#endif /* !PARSEREXCEPTIONS_HPP_ */
