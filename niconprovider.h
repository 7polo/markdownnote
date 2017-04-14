#ifndef NICONPROVIDER_H
#define NICONPROVIDER_H

#include<QFileIconProvider>

class NIconProvider:public QFileIconProvider
{
public:
    NIconProvider();
    ~NIconProvider();
    QIcon icon(const QFileInfo & info) const;
private:
    QIcon *dirIcon;
    QIcon *fileIcon;
};
#endif // NICONPROVIDER_H
