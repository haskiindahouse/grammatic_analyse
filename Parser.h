//
// Created by Михаил Мурунов on 15.03.2022.
//

#pragma once

#include <iostream>
#include <algorithm>
#include <cctype>
#include <functional>
#include <vector>
#include <set>
#include <string>

class Expression;
namespace Actions
{
    enum ParseState
    {
        Begin = 0,
        Process = 1,
        End = 2,
    };
}
class Parser final
{
public:
    explicit Parser(const std::string& input);
    ~Parser() = default;

private:
    virtual void  addRule(const std::string newRule);

    // trim from start (in place)
    static inline void ltrim(std::string& s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
        {
            return !std::isspace(ch);
        }));
    }

    // trim from end (in place)
    static inline void rtrim(std::string& s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
        {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    // trim from both ends
    static inline std::string& trim(std::string& s)
    {
        ltrim(s);
        rtrim(s);
        return s;
    }

public:
    std::set<Expression*> rules();
    virtual std::string originalInput();
    static std::set<std::string> tokenize(std::string s, std::string del = ", ");

private:
    std::string m_originalIns;
    std::set<Expression*> m_rules;
    Actions::ParseState m_state; // реализовать стейт-машину
};
