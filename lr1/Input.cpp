#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include "Input.h"
#include <iostream>
#include <locale>
#include <sstream>
#include <stdexcept>

std::string readText(const std::string& message) {
    std::cout << message;
    std::string text;
    if (!std::getline(std::cin, text))
        throw std::runtime_error("Не удалось прочитать ввод.");
    if (text.find_first_not_of(" \t") == std::string::npos)
        throw std::invalid_argument("Поле не может быть пустым.");
    return text;
}

int readInt(const std::string& message) {
    std::string text = readText(message);
    std::istringstream in(text);
    int value;
    char extra;
    if (!(in >> value) || (in >> extra))
        throw std::invalid_argument("Введите целое число.");
    return value;
}

double readPrice(const std::string& message) {
    std::string text = readText(message);
    for (char& ch : text) if (ch == ',') ch = '.';
    std::istringstream in(text);
    in.imbue(std::locale::classic());
    double value;
    char extra;
    if (!(in >> value) || (in >> extra))
        throw std::invalid_argument("Введите число.");
    return value;
}
