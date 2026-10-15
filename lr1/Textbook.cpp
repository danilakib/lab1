#ifdef _MSC_VER
#pragma execution_character_set("utf-8")
#endif

#include "Textbook.h"
#include "Input.h"
#include <iostream>
#include <stdexcept>

Textbook::Textbook() : Base(), year(0), studyYear(0), pages(0) {
    std::cout << "Textbook: конструктор без параметров.\n";
}
Textbook::Textbook(const std::string& t, const std::string& a, int y,
    const std::string& inst, int sy, int pg, double p)
    : Base(p), year(0), studyYear(0), pages(0) {
    std::cout << "Textbook: конструктор с параметрами.\n";
    setTitle(t); setAuthor(a); setYear(y);
    setInstitution(inst); setStudyYear(sy); setPages(pg);
}
Textbook::Textbook(const Textbook& other)
    : Base(other), title(other.title), author(other.author), institution(other.institution),
    year(other.year), studyYear(other.studyYear), pages(other.pages) {
    std::cout << "Textbook: конструктор копирования.\n";
}
Textbook::~Textbook() { std::cout << "Textbook: деструктор.\n"; }

std::string Textbook::getTitle() const { return title; }
std::string Textbook::getAuthor() const { return author; }
int Textbook::getYear() const { return year; }
std::string Textbook::getInstitution() const { return institution; }
int Textbook::getStudyYear() const { return studyYear; }
int Textbook::getPages() const { return pages; }

void Textbook::setTitle(const std::string& v) { if (v.empty()) throw std::invalid_argument("Пустое название."); title = v; }
void Textbook::setAuthor(const std::string& v) { if (v.empty()) throw std::invalid_argument("Пустой автор."); author = v; }
void Textbook::setYear(int v) { if (v < 1 || v > 9999) throw std::invalid_argument("Неверный год выпуска."); year = v; }
void Textbook::setInstitution(const std::string& v) { if (v.empty()) throw std::invalid_argument("Пустое название учреждения."); institution = v; }
void Textbook::setStudyYear(int v) { if (v < 1) throw std::invalid_argument("Год обучения должен быть больше нуля."); studyYear = v; }
void Textbook::setPages(int v) { if (v < 1) throw std::invalid_argument("Страниц должно быть больше нуля."); pages = v; }

const char* Textbook::getType() const { return "Textbook"; }

void Textbook::input() {
    setTitle(readText("Название: "));
    setAuthor(readText("Автор: "));
    setYear(readInt("Год выпуска: "));
    setInstitution(readText("Учебное заведение: "));
    setStudyYear(readInt("Год обучения: "));
    setPages(readInt("Страницы: "));
    setPrice(readPrice("Стоимость: "));
}

void Textbook::edit() {
    std::cout << "1. Название\n2. Автор\n3. Год выпуска\n4. Учебное заведение\n"
        "5. Год обучения\n6. Страницы\n7. Стоимость\n8. Все поля\n0. Назад\n";
    switch (readInt("Поле: ")) {
    case 0: break;
    case 1: setTitle(readText("Название: ")); break;
    case 2: setAuthor(readText("Автор: ")); break;
    case 3: setYear(readInt("Год выпуска: ")); break;
    case 4: setInstitution(readText("Учебное заведение: ")); break;
    case 5: setStudyYear(readInt("Год обучения: ")); break;
    case 6: setPages(readInt("Страницы: ")); break;
    case 7: setPrice(readPrice("Стоимость: ")); break;
    case 8: input(); break;
    default: throw std::out_of_range("Нет такого поля.");
    }
}

void Textbook::print() const {
    std::cout << "Учебник: " << getTitle() << "\nАвтор: " << getAuthor()
        << "\nГод: " << getYear() << "\nУчебное заведение: " << getInstitution()
        << "\nГод обучения: " << getStudyYear() << "\nСтраницы: " << getPages()
        << "\nСтоимость: " << getPrice() << "\n";
}

Base* Textbook::clone() const { return new Textbook(*this); }
