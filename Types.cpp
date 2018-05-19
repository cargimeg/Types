#include "Types.hpp"

namespace Types
{
    double getConversion(DistanceType from, DistanceType to)
    {
        double conversion(0.0);

        if (from == to)
        {
            conversion = 1.0;
        }
        else
        {
            switch (from)
            {
            case Distance_Type_Feet:
                switch (to)
                {
                case Distance_Type_Meter:
                    conversion = 0.3048;
                    break;
                case Distance_Type_Inch:
                    conversion = 12.0;
                    break;
                default:
                    error();
                    break;
                }
                break;
            case Distance_Type_Inch:
                switch (to)
                {
                case Distance_Type_Feet:
                    conversion = 0.0833333;
                case Distance_Type_Meter:
                    conversion = 0.0254;
                    break;
                default:
                    error();
                    break;
                }
                break;
            case Distance_Type_Meter:
                switch (to)
                {
                case Distance_Type_Feet:
                    conversion = 3.28084;
                    break;
                case Distance_Type_Inch:
                    conversion = 39.3701;
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

    double getConversionArea(DistanceType from, DistanceType to)
    {
        double conversion(0.0);

        if (from == to)
        {
            conversion = 1.0;
        }
        else
        {
            switch (from)
            {
            case Distance_Type_Feet:
                switch (to)
                {
                case Distance_Type_Meter:
                    conversion = 0.3048;
                    break;
                case Distance_Type_Inch:
                    conversion = 12.0;
                    break;
                default:
                    error();
                    break;
                }
                break;
            case Distance_Type_Inch:
                switch (to)
                {
                case Distance_Type_Feet:
                    conversion = 0.0833333;
                    break;
                case Distance_Type_Meter:
                    conversion = 0.0254;
                    break;
                default:
                    error();
                    break;
                }
                break;
            case Distance_Type_Meter:
                switch (to)
                {
                case Distance_Type_Feet:
                    conversion = 3.28084;
                    break;
                case Distance_Type_Inch:
                    conversion = 39.3701;
                    break;
                default:
                    error();
                    break;
                }
            default:
                error();
                break;
            }
        }
        conversion *= conversion;
        return conversion;
    }

    double getConversion(ForceType from, ForceType to)
    {
        double conversion(0.0);
        if (from == to)
        {
            conversion = 1.0;
        }
        else
        {
            switch (from)
            {
            case Force_Type_Pound:
                switch (to)
                {
                case Force_Type_Newton:
                    conversion = 4.448222;
                    break;
                default:
                    error();
                    break;
                }
                break;
            case Force_Type_Newton:
                switch (to)
                {
                case Force_Type_Pound:
                    conversion = 0.22481;
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

    double getConversion(MassType from, MassType to)
    {
        double conversion(0.0);

        if (from == to)
        {
            conversion = 1.0;
        }
        else
        {
            switch (from)
            {
            case Mass_Type_Kilogram:
                switch (to)
                {
                case Mass_Type_Pound:
                    conversion = 2.20462;
                    break;
                default:
                    error();
                    break;
                }
                break;
            case Mass_Type_Pound:
                switch (to)
                {
                case Mass_Type_Kilogram:
                    conversion = 0.453592;
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

    double getConversion(PressureType from, PressureType to)
    {
        double conversion(0.0);

        if (from == to)
        {
            conversion = 1.0;
        }
        else
        {
            switch (from)
            {
            case Pressure_Type_Pascal:
                switch (to)
                {
                case Pressure_Type_Atmosphere:
                    conversion = 9.86923e-6;
                    break;
                case Pressure_Type_Psi:
                    conversion = 0.000145038;
                    break;
                case Pressure_Type_Bar:
                    conversion = 1e-5;
                    break;
                default:
                    error();
                    break;
                }
                break;
            case Pressure_Type_Atmosphere:
                switch (to)
                {
                case Pressure_Type_Pascal:
                    conversion = 101325.0;
                    break;
                case Pressure_Type_Psi:
                    conversion = 14.6959;
                    break;
                case Pressure_Type_Bar:
                    conversion = 1.01325;
                    break;
                default:
                    error();
                    break;
                }
                break;
            case Pressure_Type_Psi:
                switch (to)
                {
                case Pressure_Type_Atmosphere:
                    conversion = 0.068046;
                    break;
                case Pressure_Type_Pascal:
                    conversion = 6894.76;
                    break;

                case Pressure_Type_Bar:
                    conversion = 0.0689476;
                    break;
                default:
                    error();
                    break;
                }
                break;

            case Pressure_Type_Bar:
                switch (to)
                {
                case Pressure_Type_Atmosphere:
                    conversion = 0.986923;
                    break;
                case Pressure_Type_Psi:
                    conversion = 14.5038;
                    break;

                case Pressure_Type_Pascal:
                    conversion = 100000;
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

    double getConversion(TimeType from, TimeType to)
    {
        double conversion(0.0);

        if (from == to)
        {
            conversion = 1.0;
        }
        else
        {
            switch (from)
            {
            case Time_Type_Second:
                switch (to)
                {
                case Time_Type_Minute:
                    conversion = 1 / 60.0;
                    break;
                case Time_Type_Hour:
                    conversion = 1.0 / 3600.0;
                    break;
                default:
                    error();
                    break;
                }
                break;
            case Time_Type_Minute:
                switch (to)
                {
                case Time_Type_Second:
                    conversion = 60.0;
                    break;
                case Time_Type_Hour:
                    conversion = 1 / 60.0;
                    break;
                default:
                    error();
                    break;
                }
                break;
            case Time_Type_Hour:
                switch (to)
                {
                case Time_Type_Second:
                    conversion = 3600.0;
                    break;
                case Time_Type_Minute:
                    conversion = 60.0;
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

    void error(void)
    {
        std::string er = "ERROR: Types.cpp: Supplied type not supported, conversion incorrect";
        std::cout << er << std::endl;
    }
}