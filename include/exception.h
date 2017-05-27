#ifndef _EXCEPTION_H
#define _EXCEPTION_H

namespace DTLib
{

class Exception
{
public:
    Exception(const char* message);
    Exception(const char* file,int line);
    Exception(const char* message,const char* file,int line);

    Exception(const Exception& e);
    Exception& operator=(const Exception& e);

    virtual const char* message() const;
    virtual const char* location() const;

    virtual ~Exception()=0;
protected:
    char* m_message;
    char* m_location;

    void init(const char* messagg,const char* file,int line);

};

class ArithmeticExxception:public Exception
{
public:
    ArithmeticExxception():Exception(0){}
    ArithmeticExxception(const char* message):Exception(message){}
    ArithmeticExxception(const char* file,int line):Exception(file,line){}
    ArithmeticExxception(const char* message,const char* file,int line):Exception(message,file,line){}

    ArithmeticExxception(const ArithmeticExxception& e):Exception(e){}

    ArithmeticExxception& operator=(const ArithmeticExxception& e)
    {
        Exception::operator =(e);
        return *this;
    }
};

class IndexOutOfBoundsExceptio:public Exception
{
public:
    IndexOutOfBoundsExceptio():Exception(0) {}
    IndexOutOfBoundsExceptio(const char* message):Exception(message){}
    IndexOutOfBoundsExceptio(const char* file,int line):Exception(file,line){}
    IndexOutOfBoundsExceptio(const char* message,const char* file,int line):Exception(message,file,line){}

    IndexOutOfBoundsExceptio(const IndexOutOfBoundsExceptio& e):Exception(e){}

    IndexOutOfBoundsExceptio& operator =(const IndexOutOfBoundsExceptio& e)
    {
        Exception::operator =(e);
        return *this;
    }
};

}


#endif // EXCEPTION_H
