#ifndef Acceleration_HPP
#define Acceleration_HPP

#include <string>
#include <sstream>
#include "Distance.hpp"
#include "Time.hpp"

class Acceleration
{
public:

    Acceleration(Distance distance, Time  time);

    Acceleration(const Acceleration& other);

    ~Acceleration();

    std::string toString(void);

    Acceleration& operator=(const Acceleration& other);

    Acceleration operator+(Acceleration other);

    Acceleration operator+=(Acceleration other);

    Acceleration operator-(Acceleration other);

    Acceleration operator-=(Acceleration other);

    Acceleration operator*(double ratio);

    double operator/(Acceleration other);

    bool operator==(const Acceleration& other);

    bool operator!=(Acceleration const& other);

    bool operator>(Acceleration const& other);

    bool operator<(Acceleration const& other);

    bool operator>=(Acceleration const& other);

    bool operator<=(Acceleration const& other);

private:
    /* Not Allowed */
    Acceleration(void);

    Distance m_distance;

    Time m_time;
};

inline Acceleration&
Acceleration::operator=(const Acceleration & other)
{
    m_distance = other.m_distance;
    m_time = other.m_time;
    return *this;
}

inline bool
Acceleration::operator==(const Acceleration& other)
{
    return m_time == other.m_time && m_distance == other.m_distance;
}

inline bool
Acceleration::operator!=(Acceleration const& other)
{
    return m_time != other.m_time || m_distance != other.m_distance;
}

#endif