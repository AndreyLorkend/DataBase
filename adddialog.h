#pragma once

#include <QDialog>
#include <QMessageBox>
#include "database.h"

namespace Ui {
class adddialog;
}

class adddialog : public QDialog
{
    Q_OBJECT

public:
    explicit adddialog(QWidget *parent = nullptr);
    ~adddialog();
    void receieveTableModel(QSqlTableModel* model);
    void receieveDatabase(Database* database);

public slots:
    void on_cancelButton_clicked();

    void on_addButton_clicked();

private:
    Ui::adddialog *ui;
    void checkFields();
    QSqlTableModel* model;
    Database* database;
    void setPersonData();
};

