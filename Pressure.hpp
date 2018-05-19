#ifndef Pressure_HPP
#define Pressure_HPP

#include <string>
#include <sstream>
#include "Types.hpp"

class Pressure
{
public:

    Pressure(Types::PressureType type, double value);

    Pressure(const Pressure& other);

    ~Pressure();

    std::string toString(void);

    Pressure& operator=(const Pressure& other);

    Pressure operator+(Pressure other);

    Pressure operator+=(Pressure other);

    Pressure operator-(Pressure other);

    Pressure operator-=(Pressure other);

    Pressure operator*(Pressure other);

    Pressure operator*=(Pressure other);
    
    double operator/(Pressure other);

    bool operator==(const Pressure& other);

    bool operator!=(Pressure const& other);

    bool operator>(Pressure const& other);

    bool operator<(Pressure const& other);

    bool operator>=(Pressure const& other);

    bool operator<=(Pressure const& other);

    double get(Types::PressureType type);

    Pressure getPressure(Types::PressureType type);
    

private:
    /* Default constructor not allowed */
    Pressure(void);

    double m_pressure;

    Types::PressureType m_type;

};

inline Pressure &
Pressure::operator=(const Pressure & other)
{
    m_pressure = other.m_pressure;
    m_type = other.m_type;
    return *this;
}

inline bool
Pressure::operator==(const Pressure& other)
{
    return other.m_type == m_type && other.m_pressure == m_pressure;
}

inline bool
Pressure::operator!=(Pressure const& other)
{
    return other.m_type != m_type || other.m_pressure != m_pressure;
}


#endif
