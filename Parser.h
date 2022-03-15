//
// Created by Михаил Мурунов on 15.03.2022.
//

#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <string>

class Parser final
{
public:
    explicit Parser();
    ~Parser() = default;

public:
    std::set<std::string> rules();
    virtual void  addRule(const std::string* newRule);

private:
    std::string m_originalIns;
    std::set<std::string> m_rules;
};


