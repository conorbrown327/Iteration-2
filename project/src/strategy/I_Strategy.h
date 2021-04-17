#ifndef I_STRATEGY_H
#define I_STRATEGY_H

#include <EntityProject/facade/delivery_system.h>
#include <vector>

namespace csci3081 {

class IStrategy {
 public:
    IStrategy() {}
    virtual ~IStrategy() {}

    virtual const std::vector< std::vector<float> > DetermineRoute(const IGraph* graph, const std::vector<float>& src, const std::vector<float>& dest) = 0;
};

}

#endif  // SRC_I_STRATEGY_H