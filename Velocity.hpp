#ifndef Velocity_HPP
#define Velocity_HPP

#include <string>
#include <sstream>
#include "Distance.hpp"
#include "Time.hpp"

class Velocity
{
public:

    Velocity(Distance distance, Time  time);

    Velocity(const Velocity& other);

    ~Velocity();

    std::string toString(void);

    Velocity& operator=(const Velocity& other);

    Velocity operator+(Velocity other);

    Velocity operator+=(Velocity other);

    Velocity operator-(Velocity other);

    Velocity operator-=(Velocity other);

    Velocity operator*(double ratio);

    double operator/(Velocity other);

    bool operator==(const Velocity& other);

    bool operator!=(Velocity const& other);

    bool operator>(Velocity const& other);

    bool operator<(Velocity const& other);

    bool operator>=(Velocity const& other);

    bool operator<=(Velocity const& other);

private:
    /* Not Allowed */
    Velocity(void);

    Distance m_distance;

    Time m_time;
};

inline Velocity&
Velocity::operator=(const Velocity & other)
{
    m_distance = other.m_distance;
    m_time = other.m_time;
    return *this;
}

inline bool
Velocity::operator==(const Velocity& other)
{
    return m_time == other.m_time && m_distance == other.m_distance;
}

inline bool
Velocity::operator!=(Velocity const& other)
{
    return m_time != other.m_time || m_distance != other.m_distance;
}

#endif