//
// Created by Михаил Мурунов on 16.03.2022.
//
#include <iostream>
#include <string>

#include "Expression.h"
#include "Rule.h"

#include "BasicRuleExecuteHelper.h"


Expression* BasicRuleExecuteHelper::execute(Expression& leftExpression, Expression& operationExpression,
                                     Expression& rightExpression)
{
    if (leftExpression.isEmpty() || rightExpression.isEmpty() || operationExpression.isEmpty())
        return nullptr;

    const auto operationIter = std::find(Rules::BasicRules.cbegin(), Rules::BasicRules.cend(), operationExpression.value());
    if (Rules::BasicRules.cend() == operationIter)
    {
        std::cout << "execution failed: uknown operation!" << std::endl;
        return nullptr;
    }

    int index = static_cast<int>(std::distance(Rules::BasicRules.cbegin(), operationIter));
    switch (index)
    {
        case Rules::BasicRulesEnum::Convert:
            return convert(leftExpression, rightExpression);
        default:
            std::cout << "execution failed: unknown error!" << std::endl;
            return nullptr;
    }
}

Expression* BasicRuleExecuteHelper::convert(Expression& leftExpression, Expression& rightExpression)
{
    return new Expression(rightExpression.value());
}
