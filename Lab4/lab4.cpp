#include <QInputDialog>
#include <QMessageBox>

#include "lab4.h"
#include "ui_lab4.h"

Lab4::Lab4(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Lab4)
{
    ui->setupUi(this);
}

Lab4::~Lab4()
{
    delete ui;
}

void Lab4::defineOperand(ExpressionPart &operand)
{
    bool ok;
    double d = QInputDialog::getDouble(this, tr("Set variable:"),
        tr("define %1:").arg(operand.toString()), 0, -2147483647, 2147483647, 3, &ok);

    if (ok)
    {
        operand.value = d;
        operand.isDefined = 1;
    }
}

int Lab4::numOrVar(ExpressionPart &operand)
{
    QMessageBox numOrVar;
    numOrVar.setText(tr("The variable \"%1\" could be a number.").arg(operand.visual));
    numOrVar.setInformativeText("Is it a number?");
    numOrVar.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    numOrVar.setDefaultButton(QMessageBox::Yes);
    int answer = numOrVar.exec();

    return answer;
}

void Lab4::on_CalculateButton_clicked()
{
    // checking the input string for unprocessable chars
    {

    if (isTheStringBad(ui->ExpressionEdit->text()))
    {
        ui->PostfixExpression->setText("The string is unprocessable. Get rid of everything except "
                                       "letters, digits, spaces, dots, scopes and operators.");
        return;
    }

    }

    std::pair<ExpressionPart *, int> infixExpression = interpretExpression(ui->ExpressionEdit->text());

    // checking the array for 'bad' scopes and multiple binary operators in a row
    {

    if (isInfixBad(infixExpression))
    {
        ui->PostfixExpression->setText("The string contains \"bad\" scopes or multiple binary operators in a row.");
        return;
    }

    }

    std::pair<ExpressionPart*, int> RPN = reversePolishNotation(infixExpression);

    // printing the expression in rpn
    {

    QString rpn;
    for (int i = 0; i < RPN.second; i++)
    {
        rpn += RPN.first[i].type == type::Operand ? RPN.first[i].visual :
                                                    ExpressionPart::reservedChars[RPN.first[i].type];
        rpn += ' ';
    }
    ui->PostfixExpression->setText(rpn);

    }

    // defining operands before the calculation
    for (int i = 0; i < RPN.second; i++)
    {
        while (RPN.first[i].type == type::Operand && RPN.first[i].isDefined == 0)
        {

            if (mightBeNumber(RPN.first[i].visual))
            {
                int answer = numOrVar(RPN.first[i]);

                if (answer == QMessageBox::Yes)
                {
                    RPN.first[i].isDefined = true;
                    RPN.first[i].value = RPN.first[i].visual.toDouble();
                    break;
                }
            }

            defineOperand(RPN.first[i]);
            for (int j = i; j < RPN.second; j++)
            {
                if (RPN.first[j].type == type::Operand &&
                    RPN.first[i].visual == RPN.first[j].visual)
                {
                    RPN.first[j].isDefined = true;
                    RPN.first[j].value = RPN.first[i].value;
                }
            }

        }
    }   

    ui->Result->setNum(calculate(RPN));
}



