#ifndef Distance_HPP
#define Distance_HPP

#include <string>
#include <sstream>
#include "Types.hpp"
#include "Area.hpp"

class Distance
{
public:

    Distance(Types::DistanceType type, double distance);

    Distance(const Distance& other);

    ~Distance();

    std::string toString(void);

    Distance& operator=(const Distance& other);

    Distance operator+(Distance other);

    Distance operator+=(Distance other);

    Distance operator-(Distance other);

    Distance operator-=(Distance other);

    Area operator*(Distance other);

    Distance operator*(double ratio);

    Distance operator/(double ratio);

    Distance operator*=(double ratio);

    double operator/(Distance other);

    bool operator==(const Distance& other);

    bool operator!=(Distance const& other);

    bool operator>(Distance const& other);

    bool operator<(Distance const& other);

    bool operator>=(Distance const& other);

    bool operator<=(Distance const& other);

    Types::DistanceType getType(void);

private:
    /* Not Allowed */
    Distance(void);

    Types::DistanceType m_type;

    double m_distance;

};

inline Distance&
Distance::operator=(const Distance & other)
{
    m_distance = other.m_distance;
    m_type = other.m_type;
    return *this;
}

inline bool
Distance::operator==(const Distance& other)
{
    return other.m_type == m_type && other.m_distance == m_distance;
}

inline bool
Distance::operator!=(Distance const& other)
{
    return other.m_type != m_type || other.m_distance != m_distance;
}

inline Types::DistanceType
Distance::getType(void) {
    return m_type;
}
#endif