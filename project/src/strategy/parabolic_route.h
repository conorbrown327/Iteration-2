#ifndef PARABOLIC_ROUTE_H
#define PARABOLIC_ROUTE_H

#include <EntityProject/facade/delivery_system.h>
#include "I_Strategy.h"

namespace csci3081 {

class Parabolic : public IStrategy{
 public:
    Parabolic();
    ~Parabolic();

    const std::vector< std::vector<float> > DetermineRoute(const IGraph* graph, const std::vector<float>& src, const std::vector<float>& dest);
};

}

#endif  // SRC_PARABOLIC_ROUTE_H