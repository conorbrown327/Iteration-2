#ifndef SMART_ROUTE_H
#define SMART_ROUTE_H

#include <EntityProject/facade/delivery_system.h>
#include "I_Strategy.h"

namespace csci3081 {

class Smart : public IStrategy{
 public:
    Smart() {}
    ~Smart() {}

    const std::vector< std::vector<float> > DetermineRoute(const IGraph* graph, const std::vector<float>& src, const std::vector<float>& dest);
};

}

#endif  // SRC_SMART_ROUTE_H