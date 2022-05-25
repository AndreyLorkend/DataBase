#include "dialogfind.h"
#include "ui_dialogfind.h"
#include <iostream>
#include <QMessageBox>

dialogfind::dialogfind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogfind)
{
    ui->setupUi(this);
}

dialogfind::~dialogfind()
{
    delete ui;
}

void dialogfind::recieveDatabase(Database *database)
{
    this->database = database;
    model = new QSqlTableModel(this, database->getDataBase());
}

void dialogfind::on_cancelButton_clicked()
{
    this->close();
}

void dialogfind::on_addButton_clicked()
{
    setFilter();
    queryModel->setQuery("SELECT * FROM people WHERE "
                         "gender = '"+data.gender+"' "
                         "AND height >= '"+QString::number(data.height)+"' "
                         "AND children_amount >= '"+children+"'"
                         "AND was_married = '"+QString::number(data.wasMarried)+"' "
                         "AND age <= '"+QString::number(data.age)+"'");
}

void dialogfind::setFilter()
{
    QSqlQuery query;
    queryModel = new QSqlQueryModel;

    data.age = ui->ageField->value();
    data.height = ui->heightField->value();

    if(!ui->childrenField->checkState()){
       data.childrenAmount = 0;
    } else {
        data.childrenAmount = ui->childrenAmountField->value();
    }
    children = convertChildrenAmount(data.childrenAmount);

    data.wasMarried = ui->marriedField->checkState();
    data.gender = ui->genderField->currentText();

    queryModel->setQuery(query);
    ui->tableView->setModel(queryModel);
}

QString dialogfind::convertChildrenAmount(int data)
{
    QString result;
    if(data == 0){
        result = "0";
    } else if (data > 0){
        result = QString::number(data);
    }
    return result;
}

void dialogfind::on_childrenField_stateChanged(int arg1)
{
    if(!ui->childrenField->checkState()){
        ui->childrenAmountField->setEnabled(false);
    } else {
        ui->childrenAmountField->setEnabled(true);
    }
}
