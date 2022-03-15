//
// Created by Михаил Мурунов on 16.03.2022.
//

#include <utility>

#include "Expression.h"

Expression::Expression(std::string value):
m_value(std::move(value))
{
}

std::string Expression::value() {
    return m_value;
}

bool Expression::isEmpty() {
    return m_value.empty();
}
