#include "parabolic_route.h"
#include <EntityProject/facade/delivery_system.h>

#include <math.h>
#include <iostream>

namespace csci3081 {

const std::vector< std::vector<float> > Parabolic::DetermineRoute(const IGraph* graph, const std::vector<float>& src, const std::vector<float>& dest) {
    std::vector< std::vector<float> > route;
    route.push_back(src);
    float srcX = src.at(0);
    float srcY = src.at(1);
    float srcZ = src.at(2);

    float destX = dest.at(0);
    float destY = dest.at(1);
    float destZ = dest.at(2);

    float diffX = destX - srcX;
    float diffZ = destZ - srcZ;

    float a = (-4 * 400) + (2 * srcY) + (2 * destY);
    float b = (4 * 400) - (3 * srcY) - (destY);

    for(int i = 0; i <= 10; i++)
    {
        std::vector<float> addToRoute;
        float interval = float(i) / 10.0;
        addToRoute.push_back(srcX + diffX * interval);
        addToRoute.push_back((a * interval * interval) + (b * interval) + srcY);
        std::cout << "Y: " << ((a * interval * interval) + (b * interval) + srcY) << std::endl;
        addToRoute.push_back(srcZ + diffZ * interval);
        route.push_back(addToRoute);
    }
    
    return route;
}

}