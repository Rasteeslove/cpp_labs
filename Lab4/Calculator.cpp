#include <math.h>
#include "lab4.h"

int factorial(int num)
{
    if (num > 1)
        return num * factorial(num - 1);
    else
        return 1;
}

float calculate(std::pair<ExpressionPart*, int> array)
{
    Stack<ExpressionPart> calculationStack;

    for (int i = 0; i < array.second; i++)
    {
        if (array.first[i].type == type::Operand)
        {
            calculationStack.push(array.first[i]);
            continue;
        }

        ExpressionPart second = calculationStack.pop();

        if (array.first[i].type == type::Factorial)
        {
            second.value = factorial(second.value);
            calculationStack.push(second);
            continue;
        }

        ExpressionPart first = calculationStack.pop();

        switch (array.first[i].type)
        {

        case type::Plus:
            first.value += second.value;
            break;

        case type::Minus:
            first.value -= second.value;
            break;

        case type::Times:
            first.value *= second.value;
            break;

        case type::Obelus:
            first.value /= second.value;
            break;

        case type::Power:
            first.value = powf(first.value, second.value);
            break;

        default:;

        }

        calculationStack.push(first);
    }

    return calculationStack.pop().value;

}
