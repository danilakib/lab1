#pragma once
#ifndef BASE_H
#define BASE_H

#include <iosfwd>

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
    virtual void print() const = 0;
};

#endif
