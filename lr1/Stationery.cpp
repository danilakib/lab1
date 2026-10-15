#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include "Stationery.h"
#include "Input.h"
#include <iostream>
#include <stdexcept>

Stationery::Stationery() : Base() {
    std::cout << "Stationery: конструктор без параметров.\n";
}
Stationery::Stationery(const std::string& k, const std::string& c,
    const std::string& use, double p) : Base(p) {
    std::cout << "Stationery: конструктор с параметрами.\n";
    setKind(k); setColor(c); setPurpose(use);
}
Stationery::Stationery(const Stationery& other)
    : Base(other), kind(other.kind), color(other.color), purpose(other.purpose) {
    std::cout << "Stationery: конструктор копирования.\n";
}
Stationery::~Stationery() { std::cout << "Stationery: деструктор.\n"; }

std::string Stationery::getKind() const { return kind; }
std::string Stationery::getColor() const { return color; }
std::string Stationery::getPurpose() const { return purpose; }
void Stationery::setKind(const std::string& v) { if (v.empty()) throw std::invalid_argument("Пустой тип канцелярии."); kind = v; }
void Stationery::setColor(const std::string& v) { if (v.empty()) throw std::invalid_argument("Пустой цвет."); color = v; }
void Stationery::setPurpose(const std::string& v) { if (v.empty()) throw std::invalid_argument("Пустое назначение."); purpose = v; }

const char* Stationery::getType() const { return "Stationery"; }

void Stationery::input() {
    setKind(readText("Тип канцелярии: "));
    setColor(readText("Цвет: "));
    setPurpose(readText("Назначение: "));
    setPrice(readPrice("Стоимость: "));
}

void Stationery::edit() {
    std::cout << "1. Тип канцелярии\n2. Цвет\n3. Назначение\n"
        "4. Стоимость\n5. Все поля\n0. Назад\n";
    switch (readInt("Поле: ")) {
    case 0: break;
    case 1: setKind(readText("Тип канцелярии: ")); break;
    case 2: setColor(readText("Цвет: ")); break;
    case 3: setPurpose(readText("Назначение: ")); break;
    case 4: setPrice(readPrice("Стоимость: ")); break;
    case 5: input(); break;
    default: throw std::out_of_range("Нет такого поля.");
    }
}

void Stationery::print() const {
    std::cout << "Канцелярия: " << getKind() << "\nЦвет: " << getColor()
        << "\nНазначение: " << getPurpose()
        << "\nСтоимость: " << getPrice() << "\n";
}

Base* Stationery::clone() const { return new Stationery(*this); }
