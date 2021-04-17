#include "beeline_route.h"
#include <EntityProject/facade/delivery_system.h>


namespace csci3081 {

const std::vector< std::vector<float> > Beeline::DetermineRoute(const IGraph* graph, const std::vector<float>& src, const std::vector<float>& dest) {
    std::vector< std::vector<float> > route;
    route.push_back(src);

    // elevate the drone to the max height 400 in increments of 40 
    for(int i = 0; i < 10; i++){
        std::vector<float> addToRoute;
        addToRoute.push_back(src.at(0));
        addToRoute.push_back(src.at(1) + 40 * i);
        addToRoute.push_back(src.at(2));
        route.push_back(addToRoute);
    }

    return route;
    //return graph->GetPath(src, dest);
}

}