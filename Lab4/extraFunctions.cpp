#include "lab4.h"

bool isReserved(QChar c)
{
    for (int i = 0; i < ExpressionPart::numOfReservedChars; i++)
        if (c == ExpressionPart::reservedChars[i])
            return true;

    return false;
}

bool isTheStringBad(QString str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!str[i].isLetterOrNumber() && str[i] != '.' && str[i] != ' ' && !isReserved(str[i]))
            return true;
    }

    return false;
}

bool isInfixBad(std::pair<ExpressionPart*, int> array)
{
    if (array.first[0].type != type::OScope && array.first[0].type != type::Operand)
        return true;

    int scopesCount = 0;
    bool theLastItemIsBinaryOperator = false;

    for (int i = 0; i < array.second; i++)
    {

        switch (array.first[i].type)
        {

        case type::OScope:
            scopesCount++;
            theLastItemIsBinaryOperator = false;
            break;

        case type::CScope:
            scopesCount--;
            theLastItemIsBinaryOperator = false;
            break;

        case type::Plus:
        case type::Minus:
        case type::Power:
        case type::Times:
        case type::Obelus:
            if (theLastItemIsBinaryOperator)
                return true;
            theLastItemIsBinaryOperator = true;
            break;

        default:
            theLastItemIsBinaryOperator = false;
        }

        if (scopesCount < 0)
            return true;
    }

    if (scopesCount != 0 || theLastItemIsBinaryOperator)
        return true;

    return false;
}

bool mightBeNumber(QString str)
{
    for (int i = 0; i < str.length(); i++)
        if (!str[i].isNumber() && str[i] != '.')
            return false;

    return true;
}
