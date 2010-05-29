#include "filenotopenedexception.h"

FileNotOpenedException::FileNotOpenedException(const char *filename):
        m_filename(filename)
{
}

const char* FileNotOpenedException::what() const throw()
{
    return "Datei konnte nicht geöffnet werden. Mögliecherweise existiert sie nicht oder wird von einem anderen Programm verwendet.";
}
