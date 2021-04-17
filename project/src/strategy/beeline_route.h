#ifndef BEELINE_ROUTE_H
#define BEELINE_ROUTE_H

#include <EntityProject/facade/delivery_system.h>
#include "I_Strategy.h"

#include <vector>

namespace csci3081 {

class Beeline : public IStrategy{
 public:
    Beeline() {}
    ~Beeline() {}

    const std::vector< std::vector<float> > DetermineRoute(const IGraph* graph, const std::vector<float>& src, const std::vector<float>& dest);
};

}

#endif  // SRC_BEELINE_ROUTE_H