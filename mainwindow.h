#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adddialog.h"
#include "dialogfind.h"
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_addElement_clicked();

    void on_deleteButton_clicked();

    void on_reselectButton_clicked();

    void on_findButton_clicked();

    void on_openDatabase_clicked();

    void on_closeDatabase_clicked();

    void on_writeToFileBtn_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel* model;
    Database* database;
};
#endif // MAINWINDOW_H
