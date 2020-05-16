#include "lab4.h"

int getLevel(ExpressionPart somePart)
{
    int level = 0;
    switch (somePart.type)
    {

    case type::Plus:
    case type::Minus:
        level = 1;
        break;

    case type::Times:
    case type::Obelus:
        level = 2;
        break;

    case type::Power:
        level = 3;
        break;

    case type::Factorial:
        level = 4;
        break;

    default:;
    }

    return level;
}

int getLevel(Stack<ExpressionPart> someStack)
{
    if (someStack.isEmpty())
        return 0;

    int level = getLevel(someStack.peek().type);

    return level;
}

std::pair<ExpressionPart*, int> reversePolishNotation(std::pair<ExpressionPart*, int> infixExpression)
{
    // the array of operands, operators and scopes. its size is the one of the parameter-array
    ExpressionPart * reversed = new ExpressionPart[infixExpression.second];
    // the size for the final reallocation being the number of scopes less than the original
    int size = 0;

    // the buffer stack for scopes & operators
    Stack<ExpressionPart> buffer;

    // reversing
    for (int i = 0; i < infixExpression.second; i++)
    {
        ExpressionPart currentItem = infixExpression.first[i];

        switch (currentItem.type)
        {

        // operand is always to be added to the rpn expression
        case type::Operand:
            reversed[size++] = currentItem;
            break;

        // oscope is always to be pushed onto the stack
        case type::OScope:
            buffer.push(currentItem);
            break;

        // emptying the stack into the rpn expression up to the oscope, then removing the latter
        case type::CScope:
        {
            ExpressionPart tmp = buffer.pop();
            while (tmp.type != type::OScope)
            {
                reversed[size++] = tmp;
                tmp = buffer.pop();
            }
        }
            break;

        default:
            while (getLevel(buffer) >= getLevel(currentItem))
            {
                reversed[size++] = buffer.pop();
            }
            buffer.push(currentItem);

        }
    }

    // emptying the stack into the rpn expression
    while (!buffer.isEmpty())
        reversed[size++] = buffer.pop();

    // final reallocation
    ExpressionPart * reversedFinal = new ExpressionPart[size];
    for (int i = 0; i < size; i++)
    {
        reversedFinal[i] = reversed[i];
    }
    delete[] reversed;

    // setting up output variable
    std::pair<ExpressionPart*, int> output(reversedFinal, size);
    return output;
}
