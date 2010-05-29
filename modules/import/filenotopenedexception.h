#ifndef FILENOTOPENEDEXCEPTION_H
#define FILENOTOPENEDEXCEPTION_H

#include "exception"

class FileNotOpenedException : public std::exception
{
public:
    FileNotOpenedException(const char* filename);

    virtual const char* what() const throw() ;

private:
    const char* m_filename;
};

#endif // FILENOTOPENEDEXCEPTION_H
