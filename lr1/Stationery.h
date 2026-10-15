#pragma once
#ifndef STATIONERY_H
#define STATIONERY_H

#include "Base.h"
#include <string>

class Stationery : public Base {
private:
    std::string kind, color, purpose;

public:
    Stationery();
    Stationery(const std::string& kind, const std::string& color,
               const std::string& purpose, double price);
    Stationery(const Stationery& other);
    ~Stationery() override;

    std::string getKind() const;
    std::string getColor() const;
    std::string getPurpose() const;
    void setKind(const std::string& value);
    void setColor(const std::string& value);
    void setPurpose(const std::string& value);

    const char* getType() const override;
    void input() override;
    void edit() override;
    void print() const override;
    Base* clone() const override;
};

#endif

