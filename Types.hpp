#ifndef Types_HPP
#define Types_HPP

#include <string>
#include <iostream>
namespace Types
{

    enum DistanceType
    {
        Distance_Type_Feet,

        Distance_Type_Inch,

        Distance_Type_Meter
    };

    enum ForceType
    {
        Force_Type_Pound,

        Force_Type_Newton

    };

    enum MassType
    {
        Mass_Type_Kilogram,

        Mass_Type_Pound
    };

    enum PressureType
    {
        Pressure_Type_Pascal,

        Pressure_Type_Atmosphere,

        Pressure_Type_Psi,

        Pressure_Type_Bar
    };

    enum TemperatureType
    {
        Temperature_Type_Celcius,

        Temperature_Type_Fahrenheit,

        Temperature_Type_Kelvin,

        Temperature_Type_Rankine
    };

    enum TimeType
    {
        Time_Type_Second,

        Time_Type_Minute,

        Time_Type_Hour
    };

    double getConversion(DistanceType from, DistanceType to);

    double getConversionArea(DistanceType from, DistanceType to);

    double getConversion(ForceType from, ForceType to);

    double getConversion(MassType from, MassType to);

    double getConversion(PressureType from, PressureType to);

    double getConversion(TimeType from, TimeType to);

    static void error(void);
}

#endif
