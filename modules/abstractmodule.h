#ifndef ABSTRACTMODULE_H
#define ABSTRACTMODULE_H

#include <QWidget>
#include <QString>

class AbstractModule : public QWidget
{

    Q_OBJECT

public:
    AbstractModule(const QString& name, QWidget* parent = 0):
            QWidget(parent),m_name(name){};

    inline const QString getName() const {
        return m_name;
    }

private:
    QString m_name;
};

#endif // ABSTRACTMODULE_H
