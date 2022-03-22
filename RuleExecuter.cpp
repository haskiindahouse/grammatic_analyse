//
// Created by Михаил Мурунов on 22.03.2022.
//
#include <iostream>

#include "Rule.h"
#include "Expression.h"
#include "ExpressionHelper.h"

#include "RuleExecuter.h"

#include <utility>

RuleExecuter::RuleExecuter(std::set<Expression*> expressions)
{
    for (const auto& exp : expressions)
    {
        const auto newRule = ExpressionHelper::expressionToRule(exp);

        m_rules.insert(newRule);

        if (newRule->isEntryPoint())
            m_entryPoint = newRule;
    }
}

std::set<Rule*> RuleExecuter::rules()
{
    return m_rules;
}

std::set<Rule *> RuleExecuter::queue()
{
    return m_queue;
}

Rule* RuleExecuter::entryPoint()
{
    return m_entryPoint;
}

void RuleExecuter::exec()
{
    // Здесь будет основная логика выполнения
    std::cout << m_entryPoint->result()->value();
}
