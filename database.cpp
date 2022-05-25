#include <iostream>
#include "database.h"

void Database::dataBaseInit(){
    if(hostName == nullptr || dataBaseName == nullptr || dataBaseUserName == nullptr){
        std::cout << "Set parameters to database!\n";
        exit(1);
    }
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(hostName);
    db.setDatabaseName(dataBaseName);
    db.setUserName(dataBaseUserName);
    db.setPassword(dataBasePassword);
}

Database::Database(QString hostName, QString dataBaseName, QString dataBaseUserName, QString dataBasePassword)
{
    this->hostName = hostName;
    this->dataBaseName = dataBaseName;
    this->dataBaseUserName = dataBaseUserName;
    this->dataBasePassword = dataBasePassword;
    this->person = new PersonModel();
    dataBaseInit();
}

Database::Database(){
    hostName.clear();
    dataBaseName.clear();
    dataBaseUserName.clear();
    dataBasePassword.clear();
}

bool Database::openDataBase(){
    bool connection = db.open();
    if(!connection){
        qDebug() << db.lastError().text();
    }
    return connection;
}

void Database::closeConnection()
{
    db.close();
}

QSqlDatabase Database::getDataBase(){
    return db;
}

void Database::addDataToDataBase(){
    QSqlQuery query;
    query.prepare("INSERT INTO public.people (person_name, person_surname, age, height, children_amount, gender, was_married) "
               "VALUES (:person_name, :person_surname, :age, :height, :children_amount, :gender, :was_married)");
    query.bindValue(":person_name", person->getName());
    query.bindValue(":person_surname", person->getSurname());
    query.bindValue(":age", person->getAge());
    query.bindValue(":height", person->getHeight());
    query.bindValue(":children_amount", person->getChildrenAmount());
    query.bindValue(":gender", person->getGender());
    query.bindValue(":was_married", person->getMarriedFlag());
    query.exec();
    qDebug() << query.lastError();
    std::cout << "adding..\n";
}

Database::~Database(){}

void Database::deleteById(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM people WHERE id=:id");
    query.bindValue(":id", id);
    if(!query.exec()){
        qDebug() << query.lastError().text();
    }
}

PersonModel* Database::getPersonModel()
{
    return person;
}

