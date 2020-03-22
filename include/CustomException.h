#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H

#include <exception>
#include <string_view>
#include <string>

class CustomException: public std::exception
{
    public:
        CustomException(std::string_view const&);
        virtual const char* what() const noexcept override;
    private:
        std::string errorMessage{};
};

#endif