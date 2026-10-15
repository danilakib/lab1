#pragma once
#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include <string>

class Keeper {
private:
    Base** items;
    int size;
    int capacity;
    void swap(Keeper& other);

public:
    Keeper();
    Keeper(int capacity);
    Keeper(const Keeper& other);
    Keeper& operator=(const Keeper& other);
    ~Keeper();

    int getSize() const;
    void add(Base* product);
    void remove(int index);
    Base& operator[](int index);
    const Base& operator[](int index) const;
    void printAll() const;
};

#endif
