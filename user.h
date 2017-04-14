#ifndef USER_H
#define USER_H
#include <QString>

class User
{
public:
    User();
    QString getName();
    void setName(QString name);
    QString getIconPath();
    void setIconPath(QString iconPath);

private:
    QString name;
    QString pwd;
    QString iconPath;
    QString rootPath;
};

#endif // USER_H
