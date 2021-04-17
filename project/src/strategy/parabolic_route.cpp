#include "parabolic_route.h"
#include <EntityProject/facade/delivery_system.h>

namespace csci3081 {

const std::vector< std::vector<float> > Parabolic::DetermineRoute(const IGraph* graph, const std::vector<float>& src, const std::vector<float>& dest) {
    return graph->GetPath(src, dest);
}

}