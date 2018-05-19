#include "Mass.hpp"

Mass::Mass(Types::MassType type, double distance) :
    m_type(type),
    m_mass(distance)
{
    
}

Mass::Mass(const Mass& other)
{
    m_type = other.m_type;
    m_mass = other.m_mass;
}

Mass::~Mass()
{
    //nothing to do
}

Mass
Mass::operator+(Mass other)

{
    Types::MassType type;
    double mass;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        mass = other.m_mass + m_mass;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        type = m_type;
        mass = m_mass + (conversion * other.m_mass);
    }
    return Mass(type, mass);
}

Mass
Mass::operator-(Mass other)

{
    Types::MassType type;
    double mass;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        mass = m_mass - other.m_mass;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        type = m_type;
        mass = m_mass - (conversion * other.m_mass);
    }
    return Mass(type, mass);
}

Mass
Mass::operator*(Mass other)

{
    Types::MassType type;
    double mass;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        mass = other.m_mass * m_mass;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        type = m_type;
        mass = m_mass * conversion * other.m_mass;
    }
    return Mass(type, mass);
}

double
Mass::operator/(Mass other)

{
    
    double mass;
    if (other.m_type == m_type)
    {
        mass = m_mass / other.m_mass;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        mass = m_mass / (conversion * other.m_mass);
    }
    return mass;
}

Mass // += -= *= /=
Mass::operator+=(Mass other)
{
    if (other.m_type == m_type)
    {
        m_mass += other.m_mass;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        m_mass += conversion * other.m_mass;
    }
    return *this;

}

Mass
Mass::operator-=(Mass other)
{
    if (other.m_type == m_type)
    {
        m_mass -= other.m_mass;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        m_mass -= conversion * other.m_mass;
    }
    return *this;

}

Mass
Mass::operator*=(Mass other)
{
    if (other.m_type == m_type)
    {
        m_mass *= other.m_mass;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        m_mass *= conversion * other.m_mass;
    }
    return *this;
}

bool
Mass::operator>(Mass const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_mass > other.m_mass;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_mass * conversion) > other.m_mass;
    }
    return result;
}

bool
Mass::operator<(Mass const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_mass < other.m_mass;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_mass * conversion) < other.m_mass;
    }
    return result;
}

bool
Mass::operator<=(Mass const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_mass <= other.m_mass;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_mass * conversion) <= other.m_mass;
    }
    return result;
}

bool
Mass::operator>=(Mass const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_mass >= other.m_mass;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_mass * conversion) >= other.m_mass;
    }
    return result;
}

std::string
Mass::toString(void)
{
    std::ostringstream out;
    out << m_mass;
    out << " ";
    switch (m_type)
    {
    case Types::Mass_Type_Pound:
        out << "lb";
        break;
    case Types::Mass_Type_Kilogram:
        out << "kg";
        break;
    default:
        out << "unsupported type ";
        break;
    }
    out << "'s";
    return out.str();
}
