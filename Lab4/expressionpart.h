#ifndef EXPRESSIONPART_H
#define EXPRESSIONPART_H

#include <QString>

enum type
{
    Plus,
    Minus,
    Times,
    Obelus,
    Power,
    Factorial,
    OScope,
    CScope,
    Operand
};

struct ExpressionPart
{
    static const QChar reservedChars[];
    static const int numOfReservedChars;
    type type;
    bool isDefined;
    double value;
    QString visual;

    ExpressionPart();
    ExpressionPart(enum type);
    ExpressionPart(enum type, double, QString);
    ExpressionPart(const ExpressionPart&);
    ExpressionPart& operator = (const ExpressionPart&);

    QString toString();
};

#endif // EXPRESSIONPART_H
