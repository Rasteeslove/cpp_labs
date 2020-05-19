#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractItemView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void textEditorDisplay();

private slots:
    void on_pasteAfterLineButton_clicked();

    void on_removeSelectedButton_clicked();

    void on_moveSelectedToBufferButton_clicked();

    void on_loadFileTextButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
