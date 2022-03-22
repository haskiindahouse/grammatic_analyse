//
// Created by Михаил Мурунов on 15.03.2022.
//

#pragma once

#include <string>
#include <vector>


/*
 * Базовый класс для правил
 * В дальнейшем иерархию я вижу следующую:
 * Rule -> SimpleRule -> CompositeRule
 * А что если весь анализ сделать в одном классе?
 */
class Expression;
namespace Rules
{
    // Описание базовых правил
    const static std::vector<std::string> BasicRules =
            {
                "->"
            };
    enum BasicRulesEnum
    {
       Convert = 0,
    };
} // namespace Rules

class Rule final
{
    // + (+ s s) s
    // Сущность правил должна описывать в дальнейшем 3 варианта правил:
    // Левосторонние (x x +) / правосторонние (+ x x) / смешанные (x + x)
    // Проще всего будет завести список базовых правил, который будет выполняться компилятором как обычные мат операции
    // Например:
    // на вход: (x + x + x)
    // В процессе анализа:
    // x def_summary x def_summary x
    // Тк приоритет операций одинаков, то выполняется слева направо
    // def_summary(x, x) def_summary x
    // Тк в строке с првилом еще осталось правило "без вызова", то идем дальше
    // def_summary(def_summary(x, x), x)
    // Теперь мы видим, что таких правил не осталось => выводим результат:
    // 3x - Представьте, что здесь все в полном порядке
    // Зачем мне это?
    // Пока напишу класс чисто для первого задания
public:
    explicit Rule(Expression* left, Expression* operation, Expression* right);
    ~Rule() = default;

public:
    Expression* result();
    bool isEntryPoint();

private:
    void executeRule();

private:
    Expression* m_rightExpression;
    Expression* m_operationExpression;
    Expression* m_leftExpression;
    Expression* m_result;
    bool m_isEntryPoint;
};

