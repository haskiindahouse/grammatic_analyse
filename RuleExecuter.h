//
// Created by Михаил Мурунов on 22.03.2022.
//

#pragma once

#include "set"

class Rule;
class Expression;

class RuleExecuter
{
public:
    explicit RuleExecuter(std::set<Expression*> rules);
    ~RuleExecuter() = default;
public:
    std::set<Rule*> rules();
    std::set<Rule*> queue();
    Rule* entryPoint();
    void exec();

private:
    std::set<Rule*> m_rules;
    std::set<Rule*> m_queue;
    Rule* m_entryPoint;
};
