//
// Created by Михаил Мурунов on 16.03.2022.
//

#include <iostream>
#include <string>

#include "Rule.h"
#include "Parser.h"

#include "Expression.h"
#include "ExpressionHelper.h"


bool ExpressionHelper::isRule(Expression* expression)
{
    for (const auto& character : expression->value())
    {
        if (std::isupper(character))
            return true;
    }

    return false;
}

Rule* ExpressionHelper::expressionToRule(Expression* expression)
{
    // сюда приходит
    // A->b
    // на выходе ты должен создать Rule(A, ->, b);
    const std::string del = "->";
    const auto preRule = Parser::tokenize(expression->value(), del);
    if (2 != preRule.size())
        return nullptr;

    const auto leftExp = new Expression(*preRule.begin());
    const auto rightExp = new Expression(*preRule.rbegin());
    const auto operation = new Expression(del);

    return new Rule(leftExp, operation, rightExp);
}
