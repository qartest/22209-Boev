#pragma once
#include <iostream>
#include <string>

class DataError : public std::exception{
    std::string  error;
public:
    DataError(int colone, int line);
    char const* what() const noexcept override;
};

DataError::DataError(int colone, int line){
    error = "You have a problem in " + std::to_string(line) + " Line " + std::to_string(colone) + " Colone";
}

char const* DataError::what() const noexcept{
    return error.data();
}
