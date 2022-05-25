#pragma once

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

#include <QSqlRecord>
#include <QSqlError>

#include <QDebug>
#include "personmodel.h"

class Database
{
private:
    QSqlDatabase db;
    QSqlTableModel model;

    QString hostName;
    QString dataBaseName;
    QString dataBaseUserName;
    QString dataBasePassword;

    //data
    PersonModel* person;
public:
    Database();
    Database(QString hostName, QString dataBaseName, QString dataBaseUserName, QString dataBasePassword);
    ~Database();

    void dataBaseInit();
    void tableModelInit();
    bool openDataBase();
    void closeConnection();

    QSqlDatabase getDataBase();
    void addDataToDataBase();
    void deleteById(int id);
    PersonModel* getPersonModel();
};

