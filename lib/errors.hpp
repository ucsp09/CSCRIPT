#ifndef _ERRORS_HPP
#define _ERRORS_HPP

#include <exception>
#include <string>

namespace html{
    class Error:public std::exception{
        public:const char* name;
                const char* message;
                Error(const char* _name,const char* _message):name(_name),message(_message){};
                const char* what() const throw()
                {
                    std::string _name(name);
                    std::string _message(message);
                    std::string out=_name+":"+_message;
                    return const_cast<char*>(out.c_str());
                }
    };
};
#endif