//risk_error.h
#include <string>
#include <stdexcept>
#include<iostream>

  class risk_error : public std::logic_error
    {
    public:
      explicit risk_error (const std::string& what_arg) throw() : std::logic_error(what_arg) {}
    };
