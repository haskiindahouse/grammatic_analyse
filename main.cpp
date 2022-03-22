#include <iostream>

#include "Rule.h"

#include "Expression.h"
#include "ExpressionHelper.h"

#include "Parser.h"

using namespace std;


int main() {
    // TODO:
    // 1) Разобраться с более сложными случаями (ВЛОЖЕННЫЙ ВЫЗОВ ПРАВИЛ)
    // 2) Написать парсер для ввода в консоль (A->a)
    // 3) Расширить базовые правила (логические OR, AND, NOT)
    // 4) Рефакторинг
    /*
     * Первый вариант (слишком ограничен)
    const auto left = new Expression("A");
    const auto right = new Expression("B");
    const auto operation = new Expression("->");
    Rule* testRule = new Rule(left, operation, right);

    Expression* ret = testRule->result();

     std::cout << ret->value() << std::endl;
    */
     std::cout << "Input:\n";
    std::string s;
    std::getline(cin, s);
    auto pars = new Parser(s);
    for (const auto& expr : pars->rules())
    {
        Rule* testRule = ExpressionHelper::expressionToRule(expr);
        if (nullptr == testRule)
            continue;

        Expression* ret = testRule->result(); // простое правило
        std::cout << ret->value() << std::endl; // результ простого правила
    }
    return 0;
}
/*
1.   Написать программу,
которая по заданной грамматике будет определять тип грамматики и генерировать цепочки языка.
Диапазон длин генерируемых цепочек должен задаваться пользователем при запуске.
Предусмотреть интерфейс для удобного ввода грамматики с клавиатуры.
*/