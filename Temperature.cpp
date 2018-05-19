#include "Temperature.hpp"

Temperature::Temperature(Types::TemperatureType type, double temp) :
    m_type(type),
    m_temp(temp)
{

}

Temperature::Temperature(const Temperature& other)
{
    m_type = other.m_type;
    m_temp = other.m_temp;
}


Temperature::~Temperature()
{
}


Temperature
Temperature::operator+(Temperature other)

{
    Types::TemperatureType type;
    double temp;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        temp = other.m_temp + m_temp;
    }
    else
    {
        double conversion = getConversion(other, *this);
        type = m_type;
        temp = m_temp + conversion;
    }
    return Temperature(type, temp);
}

Temperature
Temperature::operator-(Temperature other)

{
    Types::TemperatureType type;
    double temp;
    if (other.m_type == m_type)
    {
        type = m_type;
        temp = m_temp - other.m_temp;
    }
    else
    {
        double conversion = getConversion(other, *this);
        type = m_type;
        temp = m_temp - conversion;
    }
    return Temperature(type, temp);
}

Temperature
Temperature::operator*(Temperature other)

{
    Types::TemperatureType type;
    double temp;
    if (other.m_type == m_type)
    {
        type = other.m_type;
        temp = other.m_temp * m_temp;
    }
    else
    {
        double conversion = getConversion(other, *this);
        type = m_type;
        temp = m_temp * conversion;
    }
    return Temperature(type, temp);
}

double
Temperature::operator/(Temperature other)

{
    double temp;
    if (other.m_type == m_type)
    {
        temp = m_temp / other.m_temp;
    }
    else
    {
        double conversion = getConversion(other, *this);
        temp = m_temp / conversion;
    }
    return temp;
}

Temperature
Temperature::operator+=(Temperature other)
{
    if (other.m_type == m_type)
    {
        m_temp += other.m_temp;
    }
    else
    {
        double conversion = getConversion(other, *this);
        m_temp += conversion;
    }
    return *this;

}

Temperature
Temperature::operator-=(Temperature other)
{
    if (other.m_type == m_type)
    {
        m_temp -= other.m_temp;
    }
    else
    {
        double conversion = getConversion(other, *this);
        m_temp -= conversion;
    }
    return *this;

}

Temperature
Temperature::operator*=(Temperature other)
{
    if (other.m_type == m_type)
    {
        m_temp *= other.m_temp;
    }
    else
    {
        double conversion = getConversion(other, *this);
        m_temp *= conversion;
    }
    return *this;
}

bool
Temperature::operator>(Temperature const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_temp > other.m_temp;
    }
    else
    {
        double conversion = getConversion(*this, other);
        result = (conversion) > other.m_temp;
    }
    return result;
}

bool
Temperature::operator<(Temperature const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_temp < other.m_temp;
    }
    else
    {
        double conversion = getConversion(*this, other);
        result = (conversion) < other.m_temp;
    }
    return result;
}

bool
Temperature::operator<=(Temperature const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_temp <= other.m_temp;
    }
    else
    {
        double conversion = getConversion(*this, other);
        result = (conversion) <= other.m_temp;
    }
    return result;
}

bool
Temperature::operator>=(Temperature const& other)
{
    bool result = false;
    if (other.m_type == m_type)
    {
        result = m_temp >= other.m_temp;
    }
    else
    {
        double conversion = getConversion(*this, other);
        result = (conversion) >= other.m_temp;
    }
    return result;
}

double
Temperature::getConversion(Temperature from, Temperature to)
{
    double conversion(0.0);

    if (from == to)
    {
        conversion = from.m_temp;
    }
    else
    {
        switch (from.m_type)
        {
        case Types::Temperature_Type_Celcius:
            switch (to.m_type)
            {
            case Types::Temperature_Type_Fahrenheit:
                conversion = ( from.m_temp * 1.8 ) + 32.0;
                break;
            case Types::Temperature_Type_Kelvin:
                conversion = from.m_temp + 273.15;
                break;
            case Types::Temperature_Type_Rankine:
                conversion = ( from.m_temp + 273.15 ) * 1.8;
                break;
            default:
                error();
                break;
            }
            break;
        case Types::Temperature_Type_Fahrenheit:
            switch (to.m_type)
            {
            case Types::Temperature_Type_Celcius:
                conversion = (from.m_temp - 32) / 1.8;
                break;
            case Types::Temperature_Type_Kelvin:
                conversion = (from.m_temp + 459.67) / 1.8;
                break;
            case Types::Temperature_Type_Rankine:
                conversion = (from.m_temp + 459.67);
                break;
            default:
                error();
                break;
            }
            break;
        case Types::Temperature_Type_Kelvin:
            switch (to.m_type)
            {
            case Types::Temperature_Type_Fahrenheit:
                conversion = ( from.m_temp * 1.8 ) - 459.67;
                break;
            case Types::Temperature_Type_Celcius:
                conversion = from.m_temp - 273.15;
                break;

            case Types::Temperature_Type_Rankine:
                conversion = from.m_temp * 1.8;
                break;
            default:
                error();
                break;
            }
            break;

        case Types::Temperature_Type_Rankine:
            switch (to.m_type)
            {
            case Types::Temperature_Type_Fahrenheit:
                conversion = from.m_temp - 459.67;
                break;
            case Types::Temperature_Type_Celcius:
                conversion = ( from.m_temp - 491.67) / 1.8;
                break;

            case Types::Temperature_Type_Kelvin:
                conversion = from.m_temp / 1.8;
                break;
            default:
                error();
                break;
            }
            break;
        default:
            error();
            break;
        }
    }
    return conversion;
}

void Temperature::error(void)
{
    std::string err = "ERROR: Temperature: Unsupported Type";
    std::cout << err << std::endl;
}

std::string
Temperature::toString(void)
{
    std::ostringstream out;
    out << m_temp;
    out << " ";
    switch (m_type)
    {
    case Types::Temperature_Type_Celcius:
        out << "Celcius";
        break;
    case Types::Temperature_Type_Fahrenheit:
        out << "Fahrenheit";
        break;
    case Types::Temperature_Type_Kelvin:
        out << "Kelvin";
        break;
    case Types::Temperature_Type_Rankine:
        out << "Rankine";
        break;
    }
    return out.str();
}

