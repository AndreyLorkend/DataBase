#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QString>

class PersonModel
{
private:
    QString name;
    QString surname;
    int age;
    int height;
    int childrenAmount;
    QString gender;
    bool wasMarried;
public:
    PersonModel();
    // Setters
    void setName(QString name);
    void setSurname(QString surname);
    void setAge(int age);
    void setHeight(int height);
    void setChildrenAmount(int childrenAmount);
    void setGender(QString gender);
    void setMarriedFlag(bool wasMarried);
    // Getters
    QString getName();
    QString getSurname();
    int getAge();
    int getHeight();
    int getChildrenAmount();
    QString getGender();
    bool getMarriedFlag();
};

#endif // PERSONMODEL_H
