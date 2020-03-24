#include "CustomException.h"

using namespace std::string_literals;

CustomException::CustomException(std::string_view const& arg):
errorMessage{"Error, resource not found : "s + arg.data()}
{

}

const char* CustomException::what() const noexcept
{
    return errorMessage.c_str();
}