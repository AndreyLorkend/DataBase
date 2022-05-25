#ifndef DIALOGFIND_H
#define DIALOGFIND_H

#include "database.h"
#include <QDialog>

struct PersonFilterData {
    int age;
    int height;
    int childrenAmount;
    bool wasMarried;
    QString gender;
};

namespace Ui {
class dialogfind;
}

class dialogfind : public QDialog
{
    Q_OBJECT

public:
    explicit dialogfind(QWidget *parent = nullptr);
    ~dialogfind();
    void recieveDatabase(Database* database);

private slots:
    void on_cancelButton_clicked();

    void on_addButton_clicked();

    void on_childrenField_stateChanged(int arg1);

private:
    void setFilter();
    QString convertChildrenAmount(int data);

    Ui::dialogfind *ui;
    Database* database;
    QSqlTableModel* model;
    QSqlQueryModel* queryModel;
    PersonFilterData data;
    QString children;
};

#endif // DIALOGFIND_H
