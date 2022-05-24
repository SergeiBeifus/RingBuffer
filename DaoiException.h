//
// Created by User on 20.05.2022.
//

#ifndef UNTITLED3_DAOIEXCEPTION_H
#define UNTITLED3_DAOIEXCEPTION_H


#include <exception>

class DaoiException: public std::exception{
private:
    const char* message;
public:
    DaoiException(const char *message) : message(message) {}
    const char* what() const noexcept override {return message;}
};


#endif //UNTITLED3_DAOIEXCEPTION_H
