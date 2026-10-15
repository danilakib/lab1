#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include "Book.h"
#include "Textbook.h"
#include "Stationery.h"
#include "Keeper.h"
#include "Input.h"
#include <iostream>
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#endif

void menu() {
    std::cout << "\nМеню\n"
        << "1. Добавить товар\n"
        << "2. Показать все товары\n"
        << "3. Показать товар\n"
        << "4. Изменить товар\n"
        << "5. Удалить товар\n"
        << "6. Копировать товар\n"
        << "0. Выход\n";
}

int selectIndex(const Keeper& keeper) {
    int number = readInt("Номер товара: ");
    if (number < 1 || number > keeper.getSize())
        throw std::out_of_range("Товара с таким номером нет.");
    return number - 1;
}

Base* createProduct() {
    std::cout << "1. Книга\n2. Учебник\n3. Канцелярия\n";
    int type = readInt("Тип товара: ");

    if (type == 1) {
        std::string title = readText("Название: ");
        std::string author = readText("Автор: ");
        int year = readInt("Год выпуска: ");
        std::string annotation = readText("Аннотация: ");
        std::string genre = readText("Жанр: ");
        int pages = readInt("Страницы: ");
        double price = readPrice("Стоимость: ");
        return new Book(title, author, year, annotation, genre, pages, price);
    }
    if (type == 2) {
        std::string title = readText("Название: ");
        std::string author = readText("Автор: ");
        int year = readInt("Год выпуска: ");
        std::string institution = readText("Учебное заведение: ");
        int studyYear = readInt("Год обучения: ");
        int pages = readInt("Страницы: ");
        double price = readPrice("Стоимость: ");
        return new Textbook(title, author, year, institution, studyYear, pages, price);
    }
    if (type == 3) {
        std::string kind = readText("Тип канцелярии: ");
        std::string color = readText("Цвет: ");
        std::string purpose = readText("Назначение: ");
        double price = readPrice("Стоимость: ");
        return new Stationery(kind, color, purpose, price);
    }
    throw std::out_of_range("Нет такого типа товара.");
}

int main() {
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif
    Keeper keeper;
    while (true) {
        menu();
        try {
            int choice = readInt("Выбор: ");
            switch (choice) {
            case 0: return 0;
            case 1: {
                Base* product = createProduct();
                try { keeper.add(product); }
                catch (...) { delete product; throw; }
                std::cout << "Товар добавлен.\n";
                break;
            }
            case 2: keeper.printAll(); break;
            case 3: keeper[selectIndex(keeper)].print(); break;
            case 4: keeper[selectIndex(keeper)].edit(); break;
            case 5: keeper.remove(selectIndex(keeper)); break;
            case 6: {
                Base* copy = keeper[selectIndex(keeper)].clone();
                try { keeper.add(copy); }
                catch (...) { delete copy; throw; }
                std::cout << "Товар скопирован.\n";
                break;
            }
            default: throw std::out_of_range("Нет такого пункта меню.");
            }
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << '\n';
            if (!std::cin) return 1;
        }
    }
}
