#include "abstractimporter.h"

AbstractImporter::AbstractImporter(const QString& filter):
        m_filter(filter)
{
}

AbstractImporter::~AbstractImporter(){}
