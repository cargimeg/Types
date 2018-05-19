#include "Distance.hpp"

Distance::Distance(Types::DistanceType type, double distance) :
    m_type(type),
    m_distance(distance)
{
    
}

Distance::Distance(const Distance& other)
{
    m_type = other.m_type;
    m_distance = other.m_distance;
}

Distance::~Distance()
{
    //nothing to do
}

Distance
Distance::operator+(Distance other)

{
    Types::DistanceType type;
    double distance;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        distance = other.m_distance + m_distance;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        type = m_type;
        distance = m_distance + (conversion * other.m_distance);
    }
    return Distance(type, distance);
}

Distance
Distance::operator-(Distance other)

{
    Types::DistanceType type;
    double distance;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        distance = m_distance - other.m_distance;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        type = m_type;
        distance = m_distance - (conversion * other.m_distance);
    }
    return Distance(type, distance);
}

Area
Distance::operator*(Distance other)
{
    double area;
    if (other.m_type == m_type)
    {
        area = other.m_distance * m_distance;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        area = m_distance * conversion * other.m_distance;
    }
    return Area(m_type, area);
}

Distance
Distance::operator*(double ratio)
{
    double distance = m_distance * ratio;
    return Distance(m_type,distance);
}

Distance Distance::operator/(double ratio)
{
    double distance = m_distance / ratio;
    return Distance(m_type, distance);
}

double
Distance::operator/(Distance other)

{
    
    double distance;
    if (other.m_type == m_type)
    {
        distance = m_distance / other.m_distance;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        distance = m_distance / (conversion * other.m_distance);
    }
    return distance;
}

Distance // += -= *= /=
Distance::operator+=(Distance other)
{
    if (other.m_type == m_type)
    {
        m_distance += other.m_distance;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        m_distance += conversion * other.m_distance;
    }
    return *this;

}

Distance
Distance::operator-=(Distance other)
{
    if (other.m_type == m_type)
    {
        m_distance -= other.m_distance;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        m_distance -= conversion * other.m_distance;
    }
    return *this;

}

Distance
Distance::operator*=(double ratio)
{
    m_distance *= ratio;
    return *this;
}

bool
Distance::operator>(Distance const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_distance > other.m_distance;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_distance * conversion) > other.m_distance;
    }
    return result;
}

bool
Distance::operator<(Distance const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_distance < other.m_distance;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_distance * conversion) < other.m_distance;
    }
    return result;
}

bool
Distance::operator<=(Distance const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_distance <= other.m_distance;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_distance * conversion) <= other.m_distance;
    }
    return result;
}

bool
Distance::operator>=(Distance const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_distance >= other.m_distance;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_distance * conversion) >= other.m_distance;
    }
    return result;
}

std::string
Distance::toString(void)
{
    std::ostringstream out;
    out << m_distance;
    out << " ";
    switch (m_type)
    {
    case Types::Distance_Type_Feet:
        out << "feet";
        break;
    case Types::Distance_Type_Meter:
        out << "meter";
        break;
    default:
        out << "unsupported type ";
        break;
    }
    out << "'s";
    return out.str();
}
