#ifndef Mass_HPP
#define Mass_HPP

#include <string>
#include <sstream>
#include "Types.hpp"

class Mass
{
public:

    

    Mass(Types::MassType type, double distance);

    Mass(const Mass& other);

    ~Mass();

    std::string toString(void);

    Mass& operator=(const Mass& other);

    Mass operator+(Mass other);

    Mass operator+=(Mass other);

    Mass operator-(Mass other);

    Mass operator-=(Mass other);

    Mass operator*(Mass other);

    Mass operator*=(Mass other);

    double operator/(Mass other);

    bool operator==(const Mass& other);

    bool operator!=(Mass const& other);

    bool operator>(Mass const& other);

    bool operator<(Mass const& other);

    bool operator>=(Mass const& other);

    bool operator<=(Mass const& other);

private:
    /* Not Allowed */
    Mass(void);

    Types::MassType m_type;

    double m_mass;
};

inline Mass&
Mass::operator=(const Mass & other)
{
    m_mass = other.m_mass;
    m_type = other.m_type;
    return *this;
}

inline bool
Mass::operator==(const Mass& other)
{
    return other.m_type == m_type && other.m_mass == m_mass;
}

inline bool
Mass::operator!=(Mass const& other)
{
    return other.m_type != m_type || other.m_mass != m_mass;
}

#endif