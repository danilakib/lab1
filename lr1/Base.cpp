#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include "Base.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

Base::Base() : price(0) {
    std::cout << "Base: конструктор без параметров.\n";
}
Base::Base(double value) : price(0) {
    std::cout << "Base: конструктор с параметрами.\n";
    setPrice(value);
}
Base::Base(const Base& other) : price(other.price) {
    std::cout << "Base: конструктор копирования.\n";
}
Base::~Base() {
    std::cout << "Base: деструктор.\n";
}

double Base::getPrice() const { return price; }
void Base::setPrice(double value) {
    if (!std::isfinite(value) || value < 0)
        throw std::invalid_argument("Стоимость не может быть отрицательной.");
    price = value;
}
