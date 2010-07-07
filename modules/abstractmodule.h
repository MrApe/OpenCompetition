#ifndef ABSTRACTMODULE_H
#define ABSTRACTMODULE_H

#include <QMainWindow>
#include <QString>

class AbstractModule : public QMainWindow
{

public:
    AbstractModule(const QString& name,QWidget* parent):
            QMainWindow(parent),
            m_name(name){};

    inline const QString getName() const {
        return m_name;
    }

private:
    QString m_name;
};

#endif // ABSTRACTMODULE_H
