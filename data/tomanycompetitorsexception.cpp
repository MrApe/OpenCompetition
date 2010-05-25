#include "tomanycompetitorsexception.h"

ToManyCompetitorsException::ToManyCompetitorsException()
{
}

const char* ToManyCompetitorsException::what() const throw()
{
    return "Group full! May change categorie or add a stand-by.";
}
