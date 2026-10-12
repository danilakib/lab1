#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include "Book.h"
#include "Stationery.h"
#include "Input.h"
#include <iostream>
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif
    while (true) {
        std::cout << "\nМеню\n1. Книга\n2. Канцелярия\n0. Выход\n";
        try {
            int choice = readInt("Выбор: ");
            if (choice == 0) return 0;
            Base* product = nullptr;
            if (choice == 1) {
                std::string title = readText("Название: ");
                std::string author = readText("Автор: ");
                int year = readInt("Год выпуска: ");
                std::string annotation = readText("Аннотация: ");
                std::string genre = readText("Жанр: ");
                int pages = readInt("Страницы: ");
                double price = readPrice("Стоимость: ");
                product = new Book(title, author, year, annotation, genre, pages, price);
            }
            else if (choice == 2) {
                std::string kind = readText("Тип канцелярии: ");
                std::string color = readText("Цвет: ");
                std::string purpose = readText("Назначение: ");
                double price = readPrice("Стоимость: ");
                product = new Stationery(kind, color, purpose, price);
            }
            else {
                throw std::out_of_range("Нет такого пункта меню.");
            }
            product->print();
            delete product;
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << '\n';
            if (!std::cin) return 1;
        }
    }
}
