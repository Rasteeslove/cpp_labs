#ifndef LAB4_H
#define LAB4_H

#include <QMainWindow>

#include "stack.h"
#include "expressionpart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Lab4; }
QT_END_NAMESPACE

class Lab4 : public QMainWindow
{
    Q_OBJECT

public:
    Lab4(QWidget *parent = nullptr);
    ~Lab4();

    void defineOperand(ExpressionPart &operand);
    int numOrVar(ExpressionPart &operand);

private slots:
    void on_CalculateButton_clicked();

private:
    Ui::Lab4 *ui;
};

bool mightBeNumber(QString str);

bool isTheStringBad(QString str);
bool isInfixBad(std::pair<ExpressionPart*, int> array);

std::pair<ExpressionPart*, int> interpretExpression(QString);
std::pair<ExpressionPart*, int> reversePolishNotation(std::pair<ExpressionPart*, int>);
float calculate(std::pair<ExpressionPart*, int> array);

#endif // LAB4_H
