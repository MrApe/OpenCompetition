#ifndef IMPORTMODULE_H
#define IMPORTMODULE_H

#include <QWidget>
#include "abstractimporter.h"
#include "importpluginprovider.h"
#include "data/competition.h"

namespace Ui {
    class importModule;
}

class importModule : public QWidget {
    Q_OBJECT
public:
    importModule(Competition* importTarget, QWidget *parent = 0);
    ~importModule();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::importModule *ui;
    ImportPluginProvider m_pluginProvider;
    Competition* m_importTarget;

public slots:
    void importFiles();
    void selectFiles();
    void writeToLog(const QString& message);

private slots:
    void on_remove_clicked();

signals:
    void log(const QString& message);
};


#endif // IMPORTMODULE_H
