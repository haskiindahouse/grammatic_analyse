//
// Created by Михаил Мурунов on 16.03.2022.
//
#include <string>

class Expression;
class Rule;

class ExpressionHelper final
{
public:
    static bool isRule(Expression* expression);
    static Rule* expressionToRule(Expression* expression);
};

