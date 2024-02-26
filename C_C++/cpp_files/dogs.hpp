#ifndef DOGS_HPP_
#define DOGS_HPP_

#include <string>

class Dogs
{
public:
    Dogs(std::string);
    ~Dogs();

    void setName(std::string name);
    std::string getName();

private:
    std::string _name;
};

#endif // DOGS_HPP_
