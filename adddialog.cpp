#include "adddialog.h"
#include "ui_adddialog.h"

adddialog::adddialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adddialog)
{
    ui->setupUi(this);
}

adddialog::~adddialog()
{
    delete ui;
}

void adddialog::receieveTableModel(QSqlTableModel *model)
{
    this->model = model;
}

void adddialog::receieveDatabase(Database* database)
{
    this->database = database;
}

void adddialog::on_cancelButton_clicked()
{
    this->close();
}

void adddialog::on_addButton_clicked()
{
    if(database == nullptr || !database->openDataBase()){
        QMessageBox::information(this, "", "Нет подключения к базе данных!");
    } else {
        this->setPersonData();
        this->database->addDataToDataBase();
        this->model->select();
    }
}

void adddialog::setPersonData()
{
    database->getPersonModel()->setName(ui->nameField->toPlainText());
    database->getPersonModel()->setSurname(ui->surnameField->toPlainText());
    database->getPersonModel()->setAge(ui->ageField->value());
    database->getPersonModel()->setHeight(ui->heightField->value());
    database->getPersonModel()->setChildrenAmount(ui->childrenField->value());
    database->getPersonModel()->setGender(ui->genderField->currentText());
    database->getPersonModel()->setMarriedFlag(ui->marriedField->checkState());
}
