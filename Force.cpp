#include "Force.hpp"


Force::Force(Types::ForceType type, double  value) :
    m_force(value),
    m_type(type)
{

}

Force::Force(const Force& other) :
    m_force(other.m_force),
    m_type(other.m_type)
{

}

Force::~Force()
{
    //nothing to do
}

Force
Force::operator+(Force other)

{
    double area(0.0);
    if (m_type == other.m_type)
    {
        area = m_force + other.m_force;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        conversion *= conversion;
        area = m_force + other.m_force * conversion;
    }
    return Force(m_type, area);
}

Force
Force::operator-(Force other)

{
    double area(0.0);
    if (m_type == other.m_type)
    {
        area = m_force - other.m_force;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        conversion *= conversion;
        area = m_force - other.m_force * conversion;
    }
    return Force(m_type, area);
}

Force
Force::operator*(double ratio)

{
    double area(m_force);
    area *= ratio;

    return Force(m_type, area);
}

double
Force::operator/(Force other)

{
    double ratio(0.0);
    if (m_type == other.m_type)
    {
        ratio = m_force / other.m_force;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        conversion *= conversion;
        ratio = m_force / other.m_force * conversion;
    }
    return ratio;
}

Pressure Force::operator/(Area other)
{
    Types::PressureType type;
    double value(0.0);
    double area(0.0);
    switch (m_type)
    {
    case Types::Force_Type_Pound:
        type = Types::Pressure_Type_Psi;
        area = other.get(Types::Distance_Type_Inch);
        break;
    case Types::Force_Type_Newton:
        type = Types::Pressure_Type_Pascal;
        area = other.get(Types::Distance_Type_Meter);
        break;
    default:
        std::cout << "Force / : Unsupported Force Type" << std::endl;
        type = Types::Pressure_Type_Psi;
        area = 0.0;
    }
    value = m_force / area;
    return Pressure(type, value);
}

Force // += -= *= /=
Force::operator+=(Force other)
{
    if (m_type == other.m_type)
    {
        m_force += other.m_force;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        conversion *= conversion;
        m_force += conversion * other.m_force;
    }
    return *this;
}

Force
Force::operator-=(Force other)
{
    if (m_type == other.m_type)
    {
        m_force -= other.m_force;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        conversion *= conversion;
        m_force -= conversion * other.m_force;
    }
    return *this;
}

bool
Force::operator>(Force const& other)
{
    bool retVal(false);
    if (m_type == other.m_type)
    {
        retVal = m_force > other.m_force;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        conversion *= conversion;
        retVal = m_force > conversion * other.m_force;
    }
    return retVal;
}

bool
Force::operator<(Force const& other)
{
    bool retVal(false);
    if (m_type == other.m_type)
    {
        retVal = m_force < other.m_force;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        conversion *= conversion;
        retVal = m_force < conversion * other.m_force;
    }
    return retVal;
}

bool
Force::operator<=(Force const& other)
{
    bool retVal(false);
    if (m_type == other.m_type)
    {
        retVal = m_force <= other.m_force;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        conversion *= conversion;
        retVal = m_force <= conversion * other.m_force;
    }
    return retVal;
}

bool
Force::operator>=(Force const& other)
{
    bool retVal(false);
    if (m_type == other.m_type)
    {
        retVal = m_force >= other.m_force;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        conversion *= conversion;
        retVal = m_force >= conversion * other.m_force;
    }
    return retVal;
}

std::string
Force::toString(void)
{
    std::ostringstream out;
    out << m_force;
    out << " ";
    switch (m_type)
    {
    case Types::Distance_Type_Feet:
        out << "feet^2";
        break;
    case Types::Distance_Type_Meter:
        out << "meter^2";
        break;
    default:
        out << "unsupported type ";
        break;
    }
    out << " / ";
    return out.str();
}
