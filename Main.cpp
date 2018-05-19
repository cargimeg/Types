#include "Pressure.hpp"
#include "Temperature.hpp"
#include "Distance.hpp"
#include "NormalShock.hpp"
#include "Mass.hpp"
#include "Time.hpp"
#include "Velocity.hpp"
#include "Acceleration.hpp"
#include "Force.hpp"
#include <string>
#include <iostream>
#include "Types.hpp"


int main()
{
    Force f(Types::Force_Type_Newton, 284.0);
    Area a(Types::Distance_Type_Meter, 1.0);
    Pressure p = f / a;
    Pressure p2 = p.getPressure(Types::Pressure_Type_Pascal);
    Distance d(Types::Distance_Type_Feet, 1);
    Distance d2(Types::Distance_Type_Meter, 1);
    Distance d3 = d + d2;
    std::cout << p2.toString();
    std::cout << std::endl;
    /* 
    std::cout << v2.toString();
    std::cout << std::endl;
    std::cout << v3.toString();
    std::cout << std::endl;
    std::cout << v4.toString();
    std::cout << std::endl;
    */

    std::cout << std::endl;

    std::string g = "";
    std::getline(std::cin, g);
    return 0;
}

