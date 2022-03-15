//
// Created by Михаил Мурунов on 16.03.2022.
//

#pragma once

class Expression;


class BasicRuleExecuteHelper final
{
public:
    static Expression* execute(Expression& leftExpression, Expression& operationExpression, Expression& rightExpression);

private:
    /// ->
    static Expression* convert(Expression& leftExpression, Expression& rightExpression);
};
