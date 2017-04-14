#include "user.h"

User::User()
{
    this->name="";
    this->iconPath="";
}

QString User::getName(){
    return this->name;
}

void User::setName(QString name){
    this->name = name;
}

QString User::getIconPath(){
    return this->iconPath;
}

void User::setIconPath(QString iconPath){
    this->iconPath = iconPath;
}
