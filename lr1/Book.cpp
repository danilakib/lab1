#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include "Book.h"
#include "Input.h"
#include <iostream>
#include <stdexcept>

Book::Book() : Base(), year(0), pages(0) {
    std::cout << "Book: конструктор без параметров.\n";
}
Book::Book(const std::string& t, const std::string& a, int y,
    const std::string& note, const std::string& g, int pg, double p)
    : Base(p), year(0), pages(0) {
    std::cout << "Book: конструктор с параметрами.\n";
    setTitle(t); setAuthor(a); setYear(y);
    setAnnotation(note); setGenre(g); setPages(pg);
}
Book::Book(const Book& other)
    : Base(other), title(other.title), author(other.author),
    annotation(other.annotation), genre(other.genre),
    year(other.year), pages(other.pages) {
    std::cout << "Book: конструктор копирования.\n";
}
Book::~Book() { std::cout << "Book: деструктор.\n"; }

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
std::string Book::getAnnotation() const { return annotation; }
std::string Book::getGenre() const { return genre; }
int Book::getPages() const { return pages; }

void Book::setTitle(const std::string& v) { if (v.empty()) throw std::invalid_argument("Пустое название."); title = v; }
void Book::setAuthor(const std::string& v) { if (v.empty()) throw std::invalid_argument("Пустой автор."); author = v; }
void Book::setYear(int v) { if (v < 1 || v > 9999) throw std::invalid_argument("Неверный год выпуска."); year = v; }
void Book::setAnnotation(const std::string& v) { if (v.empty()) throw std::invalid_argument("Пустая аннотация."); annotation = v; }
void Book::setGenre(const std::string& v) { if (v.empty()) throw std::invalid_argument("Пустой жанр."); genre = v; }
void Book::setPages(int v) { if (v < 1) throw std::invalid_argument("Страниц должно быть больше нуля."); pages = v; }

const char* Book::getType() const { return "Book"; }

void Book::input() {
    setTitle(readText("Название: "));
    setAuthor(readText("Автор: "));
    setYear(readInt("Год выпуска: "));
    setAnnotation(readText("Аннотация: "));
    setGenre(readText("Жанр: "));
    setPages(readInt("Страницы: "));
    setPrice(readPrice("Стоимость: "));
}

void Book::edit() {
    std::cout << "1. Название\n2. Автор\n3. Год выпуска\n4. Аннотация\n"
        "5. Жанр\n6. Страницы\n7. Стоимость\n8. Все поля\n0. Назад\n";
    switch (readInt("Поле: ")) {
    case 0: break;
    case 1: setTitle(readText("Название: ")); break;
    case 2: setAuthor(readText("Автор: ")); break;
    case 3: setYear(readInt("Год выпуска: ")); break;
    case 4: setAnnotation(readText("Аннотация: ")); break;
    case 5: setGenre(readText("Жанр: ")); break;
    case 6: setPages(readInt("Страницы: ")); break;
    case 7: setPrice(readPrice("Стоимость: ")); break;
    case 8: input(); break;
    default: throw std::out_of_range("Нет такого поля.");
    }
}

void Book::print() const {
    std::cout << "Книга: " << getTitle() << "\nАвтор: " << getAuthor()
        << "\nГод: " << getYear() << "\nАннотация: " << getAnnotation()
        << "\nЖанр: " << getGenre() << "\nСтраницы: " << getPages()
        << "\nСтоимость: " << getPrice() << "\n";
}

Base* Book::clone() const { return new Book(*this); }
