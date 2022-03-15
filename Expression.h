//
// Created by Михаил Мурунов on 16.03.2022.
//

#pragma once

#include <string>


class Expression
{
public:
    explicit Expression(std::string value);

public:
    std::string value();
    bool isEmpty();

private:
    std::string m_value;
};

