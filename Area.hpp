#ifndef Area_HPP
#define Area_HPP

#include <string>
#include <sstream>
#include <math.h>
#include "Types.hpp"

class Area
{
public:

    Area(Types::DistanceType type, double  value);

    Area(const Area& other);

    ~Area();

    std::string toString(void);

    Area& operator=(const Area& other);

    Area operator+(Area other);

    Area operator+=(Area other);

    Area operator-(Area other);

    Area operator-=(Area other);

    Area operator*(double ratio);

    double operator/(Area other);

    bool operator==(const Area& other);

    bool operator!=(Area const& other);

    bool operator>(Area const& other);

    bool operator<(Area const& other);

    bool operator>=(Area const& other);

    bool operator<=(Area const& other);

    double get(Types::DistanceType type);

private:
    /* Not Allowed */
    Area(void);

    double m_area;
    
    Types::DistanceType m_type;

};

inline Area&
Area::operator=(const Area & other)
{
    m_area = other.m_area;
    m_type = other.m_type;
    return *this;
}

inline bool
Area::operator==(const Area& other)
{
    return m_type == other.m_type && m_area == other.m_area;
}

inline bool
Area::operator!=(Area const& other)
{
    return m_type != other.m_type || m_area != other.m_area;
}

#endif