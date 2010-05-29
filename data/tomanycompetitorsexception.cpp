#include "tomanycompetitorsexception.h"

ToManyCompetitorsException::ToManyCompetitorsException()
{
}

const char* ToManyCompetitorsException::what() const throw()
{
    return "Maximale Gruppengröße erreicht! Kategorie ändern oder Ersatzstarter hinzufügen.";
}
