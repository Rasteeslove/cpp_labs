#include "expressionpart.h"

const QChar ExpressionPart::reservedChars[] = {'+', '-', '*', '/', '^', '!', '(', ')'};
const int ExpressionPart::numOfReservedChars = sizeof(ExpressionPart::reservedChars) / sizeof(QChar);

ExpressionPart::ExpressionPart()
{};

ExpressionPart::ExpressionPart(enum type type)
{
    this->isDefined = 0;
    this->type = type;
}

ExpressionPart::ExpressionPart(enum type type, double value, QString visual)
{
    this->type = type;
    this->value = value;
    this->isDefined = 1;
    this->visual = visual;
}

ExpressionPart::ExpressionPart(const ExpressionPart &other)
{
    this->type = other.type;
    this->isDefined = other.isDefined;
    this->value = other.value;
    this->visual = other.visual;
}

ExpressionPart& ExpressionPart::operator = (const ExpressionPart& other)
{
    this->type = other.type;
    this->isDefined = other.isDefined;
    this->value = other.value;
    this->visual = other.visual;

    return *this;
}

QString ExpressionPart::toString()
{
    if (!this->visual.isEmpty())
        return this->visual;

    return reservedChars[this->type];
}
