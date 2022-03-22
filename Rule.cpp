//
// Created by Михаил Мурунов on 15.03.2022.
//

#include "Expression.h"

#include "BasicRuleExecuteHelper.h"

#include "Rule.h"

Rule::Rule(Expression* left, Expression* operation, Expression* right):
    m_leftExpression(left),
    m_operationExpression(operation),
    m_rightExpression(right),
    m_result(nullptr)
{}

void Rule::executeRule()
{
    m_result = BasicRuleExecuteHelper::execute(*m_leftExpression, *m_operationExpression, *m_rightExpression);

}

Expression* Rule::result()
{
    this->executeRule();
    return m_result;
}
