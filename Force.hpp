#ifndef Force_HPP
#define Force_HPP

#include <string>
#include <sstream>
#include <math.h>
#include "Pressure.hpp"
#include "Area.hpp"

class Force
{
public:

    Force(Types::ForceType type, double  value);

    Force(const Force& other);

    ~Force();

    std::string toString(void);

    Force& operator=(const Force& other);

    Force operator+(Force other);

    Force operator+=(Force other);

    Force operator-(Force other);

    Force operator-=(Force other);

    Force operator*(double ratio);

    double operator/(Force other);
    
    Pressure operator/(Area other);

    bool operator==(const Force& other);

    bool operator!=(Force const& other);

    bool operator>(Force const& other);

    bool operator<(Force const& other);

    bool operator>=(Force const& other);

    bool operator<=(Force const& other);

private:
    /* Not Allowed */
    Force(void);

    double m_force;
    
    Types::ForceType m_type;

};

inline Force&
Force::operator=(const Force & other)
{
    m_force = other.m_force;
    m_type = other.m_type;
    return *this;
}

inline bool
Force::operator==(const Force& other)
{
    return m_type == other.m_type && m_force == other.m_force;
}

inline bool
Force::operator!=(Force const& other)
{
    return m_type != other.m_type || m_force != other.m_force;
}

#endif