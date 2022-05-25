#include "personmodel.h"

PersonModel::PersonModel()
{

}

void PersonModel::setName(QString name){
    this->name = name;
}

void PersonModel::setSurname(QString surname){
    this->surname = surname;
}

void PersonModel::setAge(int age){
    this->age = age;
}

void PersonModel::setHeight(int height){
    this->height = height;
}

void PersonModel::setChildrenAmount(int childrenAmount){
    this->childrenAmount = childrenAmount;
}


void PersonModel::setGender(QString gender){
    this->gender = gender;
}

void PersonModel::setMarriedFlag(bool wasMarried)
{
    this->wasMarried = wasMarried;
}

QString PersonModel::getName()
{
    return name;
}

QString PersonModel::getSurname()
{
    return surname;
}

int PersonModel::getAge()
{
    return age;
}

int PersonModel::getHeight()
{
    return height;
}

int PersonModel::getChildrenAmount()
{
    return childrenAmount;
}

QString PersonModel::getGender()
{
    return gender;
}

bool PersonModel::getMarriedFlag()
{
    return wasMarried;
}

