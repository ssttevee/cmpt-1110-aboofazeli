#include <iostream>
 
float pi()
{
    return (float) atan(1) * 4;
}
 
float conicalVolume(float r1, float r2, float h)
{
    return pi() * ((pow(r1, 2) + (r1 * r2) + pow(r2, 2)) * h) / 3;
}
 
float cylinderVolume(float r, float h)
{
    return pi() * pow(r, 2) * h;
}
 
int mainx()
{
    float cy1_h = 0; // bottom cylinder height
    float cy1_r = 0; // bottom cylinder radius
 
    float con_h = 0; // cone height
 
    float cy2_h = 0; // top cylinder radius
    float cy2_r = 0; // top cylinder radius
 
    float result = 0; // Final answer
 
 
    std::cout << "Welcome to the bottle volume calculator." << std::endl
              << "Please enter the following measurements:" << std::endl;
 
 
    std::cout << "Bottom Cylinder Height: ";
    std::cin >> cy1_h;
     
    std::cout << "Bottom Cylinder Radius: ";
    std::cin >> cy1_r;
 
    std::cout << "Conical Section Height: ";
    std::cin >> con_h;
 
    std::cout << "Top Cylinder Height:    ";
    std::cin >> cy2_h;
 
    std::cout << "Top Cylinder Radius:    ";
    std::cin >> cy2_r;
 
 
    // Calculate Volume
    result = cylinderVolume(cy1_r, cy1_h) + conicalVolume(cy1_r, cy2_r, con_h) + cylinderVolume(cy2_r, cy2_h);
 
    std::cout << "The volume of your bottle is " << result << std::endl;
 
    return 0;
}