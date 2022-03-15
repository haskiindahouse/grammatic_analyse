//
// Created by Михаил Мурунов on 16.03.2022.
//

#include <string>

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
