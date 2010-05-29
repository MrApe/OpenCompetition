#ifndef IMPORTMODULE_H
#define IMPORTMODULE_H

#include <QWidget>
#include "abstractimporter.h"

namespace Ui {
    class importModule;
}

class importModule : public QWidget {
    Q_OBJECT
public:
    importModule(QWidget *parent = 0);
    ~importModule();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::importModule *ui;
    std::vector<AbstractImporter*> m_importPlugins;

public slots:
    void nextPage();
    void selectFiles();

private slots:
    void on_remove_clicked();
};


#endif // IMPORTMODULE_H
