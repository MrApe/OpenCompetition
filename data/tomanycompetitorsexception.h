#ifndef TOMANYCOMPETITORSEXCEPTION_H
#define TOMANYCOMPETITORSEXCEPTION_H

#include "exception"

class ToManyCompetitorsException : public std::exception
{
public:
    ToManyCompetitorsException();

    virtual const char* what() const throw() ;

};

#endif // TOMANYCOMPETITORSEXCEPTION_H
