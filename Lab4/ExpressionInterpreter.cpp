#include "lab4.h"

template <typename T> T * reallocate(T * array, int &capacity)
{
    T * reallocated = new T[capacity * 2];

    for (int i = 0; i < capacity; i++)
    {
        reallocated[i] = array[i];
    }

    capacity *= 2;

    delete[] array;
    return reallocated;
}

int getType(QChar symbol)
{
    for (int i = 0; i < ExpressionPart::numOfReservedChars; i++)
        if (symbol == ExpressionPart::reservedChars[i])
            return i;

    return ExpressionPart::numOfReservedChars;
}

bool isNumPart(QChar symbol)
{
    return symbol.isLetterOrNumber() || symbol == '.';
}

std::pair<ExpressionPart*, int> interpretExpression(QString expressionStr)
{     
    int capacity = DEF_SIZE, size = 0;
    ExpressionPart * array = new ExpressionPart[capacity];

    for (int i = 0; i < expressionStr.length(); i++)
    {
         // skipping spaces
         if (expressionStr[i] == ' ')
             continue;

         // creating new operand or operator or scope
         ExpressionPart newOne(static_cast<type>(getType(expressionStr[i])));

         // if it's minus in the beginning of some expression
         if (newOne.type == type::Minus && (size == 0 || array[size - 1].type == type::OScope))
         {
             // adding extra zero before the minus
             ExpressionPart tmp(type::Operand, 0, "[zero]");            
             array[size++] = tmp;
             if (size == capacity)
                array = reallocate(array, capacity);
         }
         // dealing with operands
         else if (newOne.type == type::Operand)
         {
             // reading the identifier / numeric representation or whatever
             for (; isNumPart(expressionStr[i]) ; i++)
             {
                 newOne.visual.append(expressionStr[i]);
             }
             i--;

             // if there are two operands in a row adding times operator in between
             if (size && array[size - 1].type == type::Operand)
             {
                 ExpressionPart tmp(type::Times);
                 array[size++] = tmp;
                 if (size == capacity)
                     array = reallocate(array, capacity);
             }
         }

         // adding whatever has been read
         array[size++] = newOne;
         if (size == capacity)
             array = reallocate(array, capacity);
    }

    // final reallocation
    ExpressionPart * final = new ExpressionPart[size];
    for (int i = 0; i < size; i++)
    {
        final[i] = array[i];
    }
    delete[] array;

    // setting up output variable
    std::pair<ExpressionPart*, int> infixExpression(final, size);
    return infixExpression;
}
