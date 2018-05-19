#include "Acceleration.hpp"

Acceleration::Acceleration(Distance distance, Time  time) :
    m_distance(distance.getType(), 0.0),
    m_time(time.getType(), 1.0)
{
    m_distance = distance;
    double ratio = time / m_time;
    ratio *= ratio;
    m_distance *= ratio;
}

Acceleration::Acceleration(const Acceleration& other) :
    m_distance(other.m_distance),
    m_time(other.m_time)
{

}

Acceleration::~Acceleration()
{
    //nothing to do
}

Acceleration
Acceleration::operator+(Acceleration other)

{
    Distance distance(m_distance);
    Time time(m_time);
    double ratio = m_time / other.m_time;
    ratio *= ratio;
    distance += other.m_distance * ratio;

    return Acceleration(distance, time);
}

Acceleration
Acceleration::operator-(Acceleration other)

{
    Distance distance(m_distance);
    Time time(m_time);
    double ratio = m_time / other.m_time;
    ratio *= ratio;
    distance -= other.m_distance * ratio;

    return Acceleration(distance, time);
}

Acceleration
Acceleration::operator*(double ratio)

{
    Distance distance(m_distance);
    distance *= ratio;
    
    return Acceleration(distance, m_time);
}

double
Acceleration::operator/(Acceleration other)

{
    double dist = m_distance /  other.m_distance;
    double time = m_time / other.m_time;
    time *= time;
    return dist * time;
}

Acceleration // += -= *= /=
Acceleration::operator+=(Acceleration other)
{
    
    double ratio = m_time / other.m_time;
    ratio *= ratio;
    m_distance += other.m_distance * ratio;
    return *this;
}

Acceleration
Acceleration::operator-=(Acceleration other)
{
    double ratio = m_time / other.m_time;
    ratio *= ratio;
    m_distance -= other.m_distance * ratio;
    return *this;
}

bool
Acceleration::operator>(Acceleration const& other)
{
    double ratio = m_time / other.m_time;
    ratio *= ratio;
    return ((m_distance / ratio) > other.m_distance);
}

bool
Acceleration::operator<(Acceleration const& other)
{
    double ratio = m_time / other.m_time;
    ratio *= ratio;
    return ((m_distance / ratio) < other.m_distance);
}

bool
Acceleration::operator<=(Acceleration const& other)
{
    double ratio = m_time / other.m_time;
    ratio *= ratio;
    return ((m_distance / ratio) <= other.m_distance);
}

bool
Acceleration::operator>=(Acceleration const& other)
{
    double ratio = m_time / other.m_time;
    ratio *= ratio;
    return ((m_distance / ratio) >= other.m_distance);
}

std::string
Acceleration::toString(void)
{
    std::ostringstream out;
    out << m_distance / Distance(m_distance.getType(),1.0);
    out << " ";
    switch (m_distance.getType())
    {
    case Types::Distance_Type_Feet:
        out << "feet";
        break;
    case Types::Distance_Type_Meter:
        out << "meter";
        break;
    default:
        out << "unsupported distance type ";
        break;
    }
    out << " / ";
    switch (m_time.getType())
    {
    case Types::Time_Type_Second:
        out << "second^2";
        break;
    case Types::Time_Type_Minute:
        out << "minute^2";
        break;
    case Types::Time_Type_Hour:
        out << "hour^2";
        break;
    default:
        out << "unsupported time type ";
        break;
    }
    return out.str();
}
