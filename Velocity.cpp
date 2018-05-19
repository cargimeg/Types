#include "Velocity.hpp"

Velocity::Velocity(Distance distance, Time  time) :
    m_distance(distance),
    m_time(time.getType(), 1.0)
{
    double ratio = time / m_time;
    m_distance *= ratio;
}

Velocity::Velocity(const Velocity& other) :
    m_distance(other.m_distance),
    m_time(other.m_time)
{

}

Velocity::~Velocity()
{
    //nothing to do
}

Velocity
Velocity::operator+(Velocity other)

{
    Distance distance(m_distance);
    Time time(m_time);
    double ratio = m_time / other.m_time;
    distance += other.m_distance * ratio;

    return Velocity(distance, time);
}

Velocity
Velocity::operator-(Velocity other)

{
    Distance distance(m_distance);
    Time time(m_time);
    double ratio = m_time / other.m_time;
    distance -= other.m_distance * ratio;

    return Velocity(distance, time);
}

Velocity
Velocity::operator*(double ratio)

{
    Distance distance(m_distance);
    distance *= ratio;
    
    return Velocity(distance, m_time);
}

double
Velocity::operator/(Velocity other)

{
    double dist = m_distance /  other.m_distance;
    double time = m_time / other.m_time;
    return dist * time;
}

Velocity // += -= *= /=
Velocity::operator+=(Velocity other)
{
    
    double ratio = m_time / other.m_time;
    m_distance += other.m_distance * ratio;
    return *this;
}

Velocity
Velocity::operator-=(Velocity other)
{
    double ratio = m_time / other.m_time;
    m_distance -= other.m_distance * ratio;
    return *this;
}

bool
Velocity::operator>(Velocity const& other)
{
    double timeRatio = m_time / other.m_time;
    return ((m_distance / timeRatio) > other.m_distance);
}

bool
Velocity::operator<(Velocity const& other)
{
    double timeRatio = m_time / other.m_time;
    return ((m_distance / timeRatio) < other.m_distance);
}

bool
Velocity::operator<=(Velocity const& other)
{
    double timeRatio = m_time / other.m_time;
    return ((m_distance / timeRatio) <= other.m_distance);
}

bool
Velocity::operator>=(Velocity const& other)
{
    double timeRatio = m_time / other.m_time;
    return ((m_distance / timeRatio) >= other.m_distance);
}

std::string
Velocity::toString(void)
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
    }
    out << " / ";
    switch (m_time.getType())
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
    return out.str();
}
