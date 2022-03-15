//
// Created by Михаил Мурунов on 15.03.2022.
//

#include "Parser.h"

Parser::Parser() :
m_rules(std::set<std::string>())
{}

std::set<std::string> Parser::rules()
{
    return m_rules;
}

void Parser::addRule(const std::string* newRule)
{
    m_rules.insert(newRule->data());
}
