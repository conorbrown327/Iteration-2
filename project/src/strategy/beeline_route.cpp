#include "strategy/beeline_route.h"
#include <EntityProject/facade/delivery_system.h>


namespace csci3081 {

const std::vector< std::vector<float> > Beeline::DetermineRoute(const IGraph* graph, const std::vector<float>& src, const std::vector<float>& dest) {
    std::vector< std::vector<float> > route;
    float srcX = src.at(0);
    float srcY = src.at(1);
    float srcZ = src.at(2);
    float destX = dest.at(0);
    float destY = dest.at(1);
    float destZ = dest.at(2);
    route.push_back(src);

    // elevate the drone to the height 400 in increments of 40 
    for(int i = 0; i <= 10; i++){
        std::vector<float> addToRoute;

        addToRoute.push_back(srcX);
        addToRoute.push_back(srcY + 40 * i);
        addToRoute.push_back(srcZ);
        route.push_back(addToRoute);
    }

    // move to x and z of the intended destination
    float diffX = destX - srcX;
    float diffZ = destZ - srcZ;
    float incremX = diffX / 10;
    float incremZ = diffZ / 10;
    for(int i = 0; i <= 10; i++)
    {
        std::vector<float> addToRoute;
        addToRoute.push_back(srcX + i * incremX);
        addToRoute.push_back(srcY + 400);
        addToRoute.push_back(srcZ + i * incremZ);
        route.push_back(addToRoute);
    }

    // lower the drone to the destination
    float diffY = destY - srcY + 400;
    float incremY = diffY / 10;
    for(int i = 0; i <= 10; i++)
    {
        std::vector<float> addToRoute;
        addToRoute.push_back(destX);
        addToRoute.push_back(srcY + 400 - i * incremY);
        addToRoute.push_back(destZ);
        route.push_back(addToRoute);
    }

    return route;
}

}