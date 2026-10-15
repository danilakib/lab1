#pragma once
#ifndef BASE_H
#define BASE_H

#include <iosfwd>

// Общая часть любого товара магазина.
class Base {
private:
    double price;

public:
    Base();
    Base(double price);
    Base(const Base& other);
    virtual ~Base();

    double getPrice() const;
    void setPrice(double value);

    virtual const char* getType() const = 0;
    virtual void input() = 0;
    virtual void edit() = 0;
    virtual void print() const = 0;
    virtual Base* clone() const = 0;
};

#endif
