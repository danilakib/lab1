#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include "Keeper.h"
#include "Book.h"
#include "Textbook.h"
#include "Stationery.h"
#include <iostream>
#include <stdexcept>

Keeper::Keeper() : items(nullptr), size(0), capacity(0) {
    std::cout << "Keeper: конструктор без параметров.\n";
}

Keeper::Keeper(int n) : items(nullptr), size(0), capacity(0) {
    std::cout << "Keeper: конструктор с параметрами.\n";
    if (n < 0) throw std::invalid_argument("Вместимость не может быть отрицательной.");
    if (n > 0) {
        items = new Base * [n];
        capacity = n;
    }
}

Keeper::Keeper(const Keeper& other) : items(nullptr), size(0), capacity(0) {
    std::cout << "Keeper: конструктор копирования.\n";
    try {
        for (int i = 0; i < other.size; ++i) {
            Base* copy = other.items[i]->clone();
            try { add(copy); }
            catch (...) { delete copy; throw; }
        }
    }
    catch (...) {
        for (int i = 0; i < size; ++i) delete items[i];
        delete[] items;
        throw;
    }
}

void Keeper::swap(Keeper& other) {
    Base** p = items; items = other.items; other.items = p;
    int n = size; size = other.size; other.size = n;
    n = capacity; capacity = other.capacity; other.capacity = n;
}

Keeper& Keeper::operator=(const Keeper& other) {
    if (this != &other) {
        Keeper copy(other);
        swap(copy);
    }
    return *this;
}

Keeper::~Keeper() {
    std::cout << "Keeper: деструктор.\n";
    for (int i = 0; i < size; ++i) delete items[i];
    delete[] items;
}

int Keeper::getSize() const { return size; }

void Keeper::add(Base* product) {
    if (!product) throw std::invalid_argument("Нельзя добавить пустой объект.");
    if (size == capacity) {
        Base** next = new Base * [size + 1];
        for (int i = 0; i < size; ++i) next[i] = items[i];
        delete[] items;
        items = next;
        capacity = size + 1;
    }
    items[size++] = product;
}

void Keeper::remove(int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Товара с таким номером нет.");
    delete items[index];
    for (int i = index; i + 1 < size; ++i) items[i] = items[i + 1];
    --size;
}

Base& Keeper::operator[](int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Товара с таким номером нет.");
    return *items[index];
}
const Base& Keeper::operator[](int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("Товара с таким номером нет.");
    return *items[index];
}

void Keeper::printAll() const {
    if (size == 0) std::cout << "Товаров нет.\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "\nТовар " << i + 1 << ":\n";
        items[i]->print();
    }
}
