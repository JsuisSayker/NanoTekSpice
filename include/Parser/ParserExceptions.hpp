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

// class CustomException : public std::exception {
//     public:
//         CustomException(const std::string &message) : _message(message) {}
//         const char *what() const noexcept override { return _message.c_str(); }

//     private:
//         std::string _message;
//     };

// #define CREATE_EXCEPTION(name)                                             \
//     class name: virtual public CustomException {                           \
//         public:                                                            \
//             name(const std::string &message) : CustomException(message) {} \
//     };

// CREATE_EXCEPTION(InvalidFileException)
// CREATE_EXCEPTION(InvalidSectionException)
// CREATE_EXCEPTION(MissingSectionException)
// CREATE_EXCEPTION(UnknownSectionName)
// CREATE_EXCEPTION(UnknownComponentType)
// CREATE_EXCEPTION(UnknownComponentName)
// CREATE_EXCEPTION(InvalidLinkException)

#endif /* !PARSEREXCEPTIONS_HPP_ */
