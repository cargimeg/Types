
#ifndef Temperature_HPP
#define Temperature_HPP

#include <string>
#include <sstream>
#include "Types.hpp"

class Temperature
{
public:

    Temperature(Types::TemperatureType type, double temp);

    Temperature(const Temperature& other);

    ~Temperature();

    std::string toString(void);

    Temperature& operator=(const Temperature& other);

    Temperature operator+(Temperature other);

    Temperature operator+=(Temperature other);

    Temperature operator-(Temperature other);

    Temperature operator-=(Temperature other);

    Temperature operator*(Temperature other);

    Temperature operator*=(Temperature other);

    double operator/(Temperature other);

    bool operator==(const Temperature& other);

    bool operator!=(Temperature const& other);

    bool operator>(Temperature const& other);

    bool operator<(Temperature const& other);

    bool operator>=(Temperature const& other);

    bool operator<=(Temperature const& other);

private:
    /* Not Allowed */
    Temperature(void);

    Types::TemperatureType m_type;

    double m_temp;

    double getConversion(Temperature from, Temperature to);

    static void error(void);
};

inline Temperature&
Temperature::operator=(const Temperature & other)
{
    m_temp = other.m_temp;
    m_type = other.m_type;
    return *this;
}

inline bool
Temperature::operator==(const Temperature& other)
{
    return other.m_type == m_type && other.m_temp == m_temp;
}

inline bool
Temperature::operator!=(Temperature const& other)
{
    return other.m_type != m_type || other.m_temp != m_temp;
}

#endif

