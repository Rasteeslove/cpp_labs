#include <QFileDialog>
#include <QTextStream>

#include <vector>
#include <algorithm>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "d_list.h"

d_list<QString> main_list;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEditor->setSelectionMode(QAbstractItemView::ExtendedSelection);

    textEditorDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::textEditorDisplay()
{
    ui->textEditor->clear();
    ui->textEditor->insertItem(0, "[ zero line ]");

    /* zero line is a default line in the text editor,
    allowing the user to paste lines before ones of the list
    widget by pasting them after it-abstract-self */

    for (int i = 0; i < main_list.get_length(); i++)
        ui->textEditor->insertItem(i + 1, main_list[i]);
}

void MainWindow::on_pasteAfterLineButton_clicked()
{
    QString bufferText = ui->bufferEdit->toPlainText();

    // checking if the buffer is empty:
    if (bufferText.isEmpty())
        return;

    // getting lines from buffer text edit into QStringList:
    QStringList bufferLinesList = bufferText.split(QRegExp("[\n]"),QString::SkipEmptyParts);

    // creating d_list from QStringList:
    d_list<QString> new_sublist(bufferLinesList);

    // adding new sublist to the main one:
    if (!ui->textEditor->selectionModel()->selectedIndexes().isEmpty())
        main_list.merge(new_sublist, ui->textEditor->selectionModel()->selectedIndexes()[0].row() - 1);

    // refreshing text editor:
    textEditorDisplay();
}

void MainWindow::on_removeSelectedButton_clicked()
{
    // getting indices of selected lines into vector excluding zero line, then sorting in descending order:
    QModelIndexList selectedIndicesList = ui->textEditor->selectionModel()->selectedIndexes();
    std::vector<int> indices;
    for (int i = 0; i < selectedIndicesList.length(); i++)
        if (selectedIndicesList[i].row() != 0)
            indices.push_back(selectedIndicesList[i].row() - 1);

    if (indices.empty())
        return;

    sort(indices.begin(), indices.end(), std::greater<int>());

    // removing selected lines from the main d_list:
    for (size_t i = 0; i < indices.size(); i++)
        main_list.remove(indices[i]);

    // refreshing text editor:
    textEditorDisplay();
}

void MainWindow::on_moveSelectedToBufferButton_clicked()
{
    // getting indices of selected lines into vector excluding zero line, then sorting:
    QModelIndexList selectedIndicesList = ui->textEditor->selectionModel()->selectedIndexes();
    std::vector<int> indices;
    for (int i = 0; i < selectedIndicesList.length(); i++)
        if (selectedIndicesList[i].row() != 0)
            indices.push_back(selectedIndicesList[i].row() - 1);

    if (indices.empty())
        return;

    sort(indices.begin(), indices.end());

    // adding selected lines to buffer edit:
    ui->bufferEdit->clear();
    for (size_t i = 0; i < indices.size(); i++)
        ui->bufferEdit->append(main_list[indices[i]]);

    // sorting indices in descending order then removing from main list
    sort(indices.begin(), indices.end(), std::greater<int>());

    for (size_t i = 0; i < indices.size(); i++)
        main_list.remove(indices[i]);

    // refreshing text editor:
    textEditorDisplay();
}

void MainWindow::on_loadFileTextButton_clicked()
{
    QString text_file_name = QFileDialog::getOpenFileName(this,
        tr("Select file whose text is to paste to buffer"),
            "/home/some text file", tr("Text&Code files (*.txt *.cpp *.h *.ui)"));

    QFile text_file(text_file_name);
    if (text_file.open(QIODevice::ReadOnly))
    {
        ui->bufferEdit->clear();

        QTextStream in(&text_file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            ui->bufferEdit->append(line);
        }
        text_file.close();
    }
}
