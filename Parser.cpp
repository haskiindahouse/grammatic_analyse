//
// Created by Михаил Мурунов on 15.03.2022.
//
#include <iostream>
#include <string>
#include <string_view>
#include <cctype>
#include <algorithm>
#include <set>
#include <vector>

#include "Parser.h"
#include "Expression.h"
// на вход просто строка ->
// бьем ее на правила через запятую
// обязательно находим старт для правил
// S->AB, A->0, B->1
// set<Expression> = {Expression(S->AB), Expression(A->0), Expression(B->1)}
// причем нам известно что S => root-Expression.
// Далее нужен Exprerssion executor.
// Будем иметь точку входа. И далее по контейнеру идти и выбирать.
Parser::Parser(const std::string& s) :
m_originalIns(s),
m_rules(),
m_state(Actions::ParseState::Begin)
{
    auto preRules = tokenize(s);
    for (const auto& rule : preRules)
    {
        m_rules.insert(new Expression(rule));
    }
}

std::set<Expression*> Parser::rules()
{
    return m_rules;
}

void Parser::addRule(const std::string newRule)
{

    //if()
    /*
     * Нужно решить как будут выглядеть
     *
     */

}

std::string Parser::originalInput() {
    return m_originalIns;
}

std::set<std::string> Parser::tokenize(std::string s, std::string del)
{
    std::set<std::string> ret;

    int start = 0;
    int end = s.find(del);
    while (-1 != end)
    {
        auto value = s.substr(start, end);

        ret.insert(trim(value));
        s.erase(start, end + del.size());
        end = s.find(del, start);
    }

    ret.insert(trim(s));

    return ret;
}
