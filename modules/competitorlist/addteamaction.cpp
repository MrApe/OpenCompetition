#include "addteamaction.h"

AddTeamAction::AddTeamAction(Group* group, QObject *parent) :
    QAction(parent),
    m_group(group)
{
}

void AddTeamAction::trigger()
{
    emit triggered(m_group);
}
