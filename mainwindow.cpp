#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    database = nullptr;
}

MainWindow::~MainWindow()
{
    delete database;
    delete model;
    delete ui;
}


void MainWindow::on_addElement_clicked()
{
    adddialog* widget = new adddialog;
    widget->receieveTableModel(model);
    widget->receieveDatabase(database);
    widget->exec();
    delete widget;
}

void MainWindow::on_deleteButton_clicked()
{
    database->deleteById(ui->idSelector->value());
    model->select();
}

void MainWindow::on_reselectButton_clicked()
{
    if(database == nullptr || !database->openDataBase()){
        QMessageBox::information(this, "", "Нет подключения к базе данных!");
    } else {
        model->select();
    }
}

void MainWindow::on_findButton_clicked()
{
    dialogfind* widget = new dialogfind;
    widget->exec();
    delete widget;
}

void MainWindow::on_openDatabase_clicked()
{
    database = new Database("localhost", "PeopleData", "postgres", "andrey559");
    database->dataBaseInit();
    if(!database->openDataBase()){
        QMessageBox::information(this, "", "Can't connect to PostgreSQL server on '127.0.0.1' ");
    } else {
        ui->openDatabase->setEnabled(false);
        ui->closeDatabase->setEnabled(true);
        model = new QSqlTableModel(this, database->getDataBase());
        model->setEditStrategy(QSqlTableModel::OnRowChange);
        model->setTable("people");
        model->select();
        ui->tableView->setModel(model);
    }
}

void MainWindow::on_closeDatabase_clicked()
{
    database->closeConnection();
    model->clear();
    ui->openDatabase->setEnabled(true);
    ui->closeDatabase->setEnabled(false);
    delete database;
    database = nullptr;
}

void MainWindow::on_writeToFileBtn_clicked()
{
    std::ofstream fout("people_table.txt");
    if(database != nullptr){
        QSqlQuery query;
        query.exec("SELECT * FROM people");
        if(query.lastError().type() == QSqlError::NoError){
            if(fout.is_open()){
                while (query.next()) {
                    fout << query.value(0).toString().toStdString().append("%");
                    fout << query.value(1).toString().toStdString().append("%");
                    fout << query.value(2).toString().toStdString().append("%");
                    fout << query.value(3).toString().toStdString().append("%");
                    fout << query.value(4).toString().toStdString().append("%");
                    fout << query.value(5).toString().toStdString().append("%");
                    fout << query.value(6).toString().toStdString().append("%");
                    fout << query.value(7).toString().toStdString();
                    fout << "\n";
                }
                fout.close();
                QMessageBox::information(this, "", "Таблица people успешно записана в файл people_table.txt");
            } else {
                QMessageBox::information(this, "", "Невозможно открыть файл!");
            }

        } else {
            QMessageBox::information(this, "", "Ошибка запроса!");
        }
    } else {
        QMessageBox::information(this, "", "Нет подключения к базе данных!");
    }
}

