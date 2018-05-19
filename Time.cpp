#include "Time.hpp"

Time::Time(Types::TimeType type, double time) :
    m_type(type),
    m_time(time)
{
    
}

Time::Time(const Time& other)
{
    m_type = other.m_type;
    m_time = other.m_time;
}

Time::~Time()
{
    //nothing to do
}

Time
Time::operator+(Time other)

{
    Types::TimeType type;
    double time;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        time = other.m_time + m_time;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        type = m_type;
        time = m_time + (conversion * other.m_time);
    }
    return Time(type, time);
}

Time
Time::operator-(Time other)

{
    Types::TimeType type;
    double time;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        time = m_time - other.m_time;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        type = m_type;
        time = m_time - (conversion * other.m_time);
    }
    return Time(type, time);
}

Time
Time::operator*(Time other)

{
    Types::TimeType type;
    double time;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        time = other.m_time * m_time;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        type = m_type;
        time = m_time * conversion * other.m_time;
    }
    return Time(type, time);
}

double
Time::operator/(Time other)

{
    
    double time;
    if (other.m_type == m_type)
    {
        time = m_time / other.m_time;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        time = m_time / (conversion * other.m_time);
    }
    return time;
}

Time // += -= *= /=
Time::operator+=(Time other)
{
    if (other.m_type == m_type)
    {
        m_time += other.m_time;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        m_time += conversion * other.m_time;
    }
    return *this;

}

Time
Time::operator-=(Time other)
{
    if (other.m_type == m_type)
    {
        m_time -= other.m_time;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        m_time -= conversion * other.m_time;
    }
    return *this;

}

Time
Time::operator*=(Time other)
{
    if (other.m_type == m_type)
    {
        m_time *= other.m_time;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        m_time *= conversion * other.m_time;
    }
    return *this;
}

bool
Time::operator>(Time const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_time > other.m_time;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_time * conversion) > other.m_time;
    }
    return result;
}

bool
Time::operator<(Time const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_time < other.m_time;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_time * conversion) < other.m_time;
    }
    return result;
}

bool
Time::operator<=(Time const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_time <= other.m_time;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_time * conversion) <= other.m_time;
    }
    return result;
}

bool
Time::operator>=(Time const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_time >= other.m_time;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_time * conversion) >= other.m_time;
    }
    return result;
}

std::string
Time::toString(void)
{
    std::ostringstream out;
    out << m_time;
    out << " ";
    switch (m_type)
    {
    case Types::Time_Type_Second:
        out << "second";
        break;
    case Types::Time_Type_Minute:
        out << "minute";
        break;
    case Types::Time_Type_Hour:
        out << "hour";
        break;
    }
    out << "'s";
    return out.str();
}
