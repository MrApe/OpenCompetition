#ifndef ADDTEAMACTION_H
#define ADDTEAMACTION_H

#include <QAction>
#include "data/group.h"

class AddTeamAction : public QAction
{
    Q_OBJECT
public:
    explicit AddTeamAction(Group* group, QObject *parent = 0);

signals:
    void triggered(Group* group);

private:
    Group* m_group;

private slots:
    void trigger();

};

#endif // ADDTEAMACTION_H
