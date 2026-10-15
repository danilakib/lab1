#pragma once
#ifndef TEXTBOOK_H
#define TEXTBOOK_H

#include "Base.h"
#include <string>

class Textbook : public Base {
private:
    std::string title, author, institution;
    int year, studyYear, pages;

public:
    Textbook();
    Textbook(const std::string& title, const std::string& author, int year,
        const std::string& institution, int studyYear, int pages, double price);
    Textbook(const Textbook& other);
    ~Textbook() override;

    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    std::string getInstitution() const;
    int getStudyYear() const;
    int getPages() const;

    void setTitle(const std::string& value);
    void setAuthor(const std::string& value);
    void setYear(int value);
    void setInstitution(const std::string& value);
    void setStudyYear(int value);
    void setPages(int value);

    const char* getType() const override;
    void input() override;
    void edit() override;
    void print() const override;
    Base* clone() const override;
};

#endif
