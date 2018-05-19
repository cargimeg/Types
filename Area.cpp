#include "Area.hpp"


Area::Area(Types::DistanceType type, double  value) :
    m_area(value),
    m_type(type)
{

}

Area::Area(const Area& other) :
    m_area(other.m_area),
    m_type(other.m_type)
{

}

Area::~Area()
{
    //nothing to do
}

Area
Area::operator+(Area other)

{
    double area(0.0);
    if (m_type == other.m_type)
    {
        area = m_area + other.m_area;
    }
    else
    {
        double conversion = getConversionArea(other.m_type, m_type);
        area = m_area + other.m_area * conversion;
    }
    return Area(m_type, area);
}

Area
Area::operator-(Area other)

{
    double area(0.0);
    if (m_type == other.m_type)
    {
        area = m_area - other.m_area;
    }
    else
    {
        double conversion = getConversionArea(other.m_type, m_type);
        area = m_area - other.m_area * conversion;
    }
    return Area(m_type, area);
}

Area
Area::operator*(double ratio)

{
    double area(m_area);
    area *= ratio;

    return Area(m_type, area);
}

double
Area::operator/(Area other)

{
    double ratio(0.0);
    if (m_type == other.m_type)
    {
        ratio = m_area / other.m_area;
    }
    else
    {
        double conversion = getConversionArea(other.m_type, m_type);
        ratio = m_area / other.m_area * conversion;
    }
    return ratio;
}

Area // += -= *= /=
Area::operator+=(Area other)
{
    if (m_type == other.m_type)
    {
        m_area += other.m_area;
    }
    else
    {
        double conversion = getConversionArea(other.m_type, m_type);
        m_area += conversion * other.m_area;
    }
    return *this;
}

Area
Area::operator-=(Area other)
{
    if (m_type == other.m_type)
    {
        m_area -= other.m_area;
    }
    else
    {
        double conversion = getConversionArea(other.m_type, m_type);
        m_area -= conversion * other.m_area;
    }
    return *this;
}

bool
Area::operator>(Area const& other)
{
    bool retVal(false);
    if (m_type == other.m_type)
    {
        retVal = m_area > other.m_area;
    }
    else
    {
        double conversion = getConversionArea(other.m_type, m_type);
        retVal = m_area > conversion * other.m_area;
    }
    return retVal;
}

bool
Area::operator<(Area const& other)
{
    bool retVal(false);
    if (m_type == other.m_type)
    {
        retVal = m_area < other.m_area;
    }
    else
    {
        double conversion = getConversionArea(other.m_type, m_type);
        retVal = m_area < conversion * other.m_area;
    }
    return retVal;
}

bool
Area::operator<=(Area const& other)
{
    bool retVal(false);
    if (m_type == other.m_type)
    {
        retVal = m_area <= other.m_area;
    }
    else
    {
        double conversion = getConversionArea(other.m_type, m_type);
        retVal = m_area <= conversion * other.m_area;
    }
    return retVal;
}

double Area::get(Types::DistanceType type)
{
    double retVal(0.0);
    if (m_type == type)
    {
        retVal = m_area;
    }
    else
    {
        double conversion = getConversionArea(m_type, type);
        retVal = m_area * conversion;
    }
    return retVal;
}

bool
Area::operator>=(Area const& other)
{
    bool retVal(false);
    if (m_type == other.m_type)
    {
        retVal = m_area >= other.m_area;
    }
    else
    {
        double conversion = getConversionArea(other.m_type, m_type);
        retVal = m_area >= conversion * other.m_area;
    }
    return retVal;
}


std::string
Area::toString(void)
{
    std::ostringstream out;
    out << m_area;
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
