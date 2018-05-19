#ifndef Time_HPP
#define Time_HPP

#include <string>
#include <sstream>
#include "Types.hpp"

class Time
{
public:

    Time(Types::TimeType type, double time);

    Time(const Time& other);

    ~Time();

    std::string toString(void);

    Time& operator=(const Time& other);

    Time operator+(Time other);

    Time operator+=(Time other);

    Time operator-(Time other);

    Time operator-=(Time other);

    Time operator*(Time other);

    Time operator*=(Time other);

    double operator/(Time other);

    bool operator==(const Time& other);

    bool operator!=(Time const& other);

    bool operator>(Time const& other);

    bool operator<(Time const& other);

    bool operator>=(Time const& other);

    bool operator<=(Time const& other);

    Types::TimeType getType(void);

private:
    /* Not Allowed */
    Time(void);

    Types::TimeType m_type;

    double m_time;
};

inline Time&
Time::operator=(const Time & other)
{
    m_time = other.m_time;
    m_type = other.m_type;
    return *this;
}

inline bool
Time::operator==(const Time& other)
{
    return other.m_type == m_type && other.m_time == m_time;
}

inline bool
Time::operator!=(Time const& other)
{
    return other.m_type != m_type || other.m_time != m_time;
}

inline Types::TimeType
Time::getType(void)
{
    return m_type;
}
#endif