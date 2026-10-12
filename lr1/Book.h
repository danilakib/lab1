#pragma once
#ifndef BOOK_H
#define BOOK_H

#include "Base.h"
#include <string>

class Book : public Base {
private:
    std::string title, author, annotation, genre;
    int year, pages;

public:
    Book();
    Book(const std::string& title, const std::string& author, int year,
        const std::string& annotation, const std::string& genre, int pages, double price);
    Book(const Book& other);
    ~Book() override;

    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getAnnotation() const;
    std::string getGenre() const;
    int getPages() const;

    void setTitle(const std::string& value);
    void setAuthor(const std::string& value);
    void setYear(int value);
    void setAnnotation(const std::string& value);
    void setGenre(const std::string& value);
    void setPages(int value);

    const char* getType() const override;
    void input() override;
    void print() const override;
};

#endif
