#include "Pressure.hpp"

Pressure::Pressure(Types::PressureType type, double pressure ):
    m_type(type),
    m_pressure(pressure)
{
    m_pressure =  pressure;
    m_type = type;
}

Pressure::Pressure(const Pressure& other)
{
    m_type = other.m_type;
    m_pressure = other.m_pressure;
}

Pressure::~Pressure()
{
    //nothing to do
}

Pressure
Pressure::operator+(Pressure other)

{
    Types::PressureType type;
    double pressure;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        pressure = other.m_pressure + m_pressure;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        type = m_type;
        pressure = m_pressure + ( conversion * other.m_pressure );
    }
    return Pressure(type, pressure);
}

Pressure
Pressure::operator-(Pressure other)

{
    Types::PressureType type;
    double pressure;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        pressure = m_pressure - other.m_pressure;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        type = m_type;
        pressure = m_pressure - ( conversion * other.m_pressure );
    }
    return Pressure(type, pressure);
}

Pressure
Pressure::operator*(Pressure other)

{
    Types::PressureType type;
    double pressure;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        pressure = other.m_pressure * m_pressure;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        type = m_type;
        pressure = m_pressure * conversion * other.m_pressure;
    }
    return Pressure(type, pressure);
}

double
Pressure::operator/(Pressure other)

{
    
    double pressure;
    if (other.m_type == m_type)
    {
        pressure = m_pressure / other.m_pressure;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        pressure = m_pressure / ( conversion * other.m_pressure) ;
    }
    return pressure;
}

Pressure
Pressure::operator+=(Pressure other)
{
    if (other.m_type == m_type)
    {
        m_pressure += other.m_pressure;
    }
    else
    {
        double conversion = getConversion(other.m_type,  m_type);
        m_pressure += conversion * other.m_pressure;
    }
    return *this;

}

Pressure 
Pressure::operator-=(Pressure other)
{
    if (other.m_type == m_type)
    {
        m_pressure -= other.m_pressure;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        m_pressure -= conversion * other.m_pressure;
    }
    return *this;

}

Pressure
Pressure::operator*=(Pressure other)
{
    if (other.m_type == m_type)
    {
        m_pressure *= other.m_pressure;
    }
    else
    {
        double conversion = getConversion(other.m_type, m_type);
        m_pressure *= conversion * other.m_pressure;
    }
    return *this;
}

bool
Pressure::operator>(Pressure const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_pressure > other.m_pressure;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_pressure * conversion) > other.m_pressure;
    }
    return result;
}

bool
Pressure::operator<(Pressure const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_pressure < other.m_pressure;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_pressure * conversion) < other.m_pressure;
    }
    return result;
}

bool
Pressure::operator<=(Pressure const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_pressure <= other.m_pressure;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_pressure * conversion) <= other.m_pressure;
    }
    return result;
}

double Pressure::get(Types::PressureType type)
{
    double retVal = m_pressure * getConversion(m_type, type);
    return retVal;
}

Pressure Pressure::getPressure(Types::PressureType type)
{

    double retVal = m_pressure * getConversion(m_type, type);
    return Pressure(type, retVal);
}

bool
Pressure::operator>=(Pressure const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_pressure >= other.m_pressure;
    }
    else
    {
        double conversion = getConversion(m_type, other.m_type);
        result = (m_pressure * conversion) >= other.m_pressure;
    }
    return result;
}

std::string
Pressure::toString(void)
{
    std::ostringstream out;
    out << m_pressure;
    out << " ";
    switch (m_type)
    {
    case Types::Pressure_Type_Psi:
        out << "Psi";
        break;
    case Types::Pressure_Type_Bar:
        out << "Bar";
        break;
    case Types::Pressure_Type_Atmosphere:
        out << "Atm";
        break;
    case Types::Pressure_Type_Pascal:
        out << "Pa";
        break;
    default:
        out << "unsupported type ";
        break;
    }
    out << "'s";
    return out.str();
}
