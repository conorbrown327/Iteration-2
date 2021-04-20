/**
 *@file parabolic_route.h
 */
#ifndef PARABOLIC_ROUTE_H
#define PARABOLIC_ROUTE_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "I_Strategy.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class defines the algorithm for the parabolic drone path.
 */
class Parabolic : public IStrategy{
 public:
    Parabolic() {}
    ~Parabolic() {}

    /**
     * Parabolic's DetermineRoute will use the quadratic equation to
     * determine 10 points for the drone to follow to create a parabolic
     * path to the destination
     */
    const std::vector< std::vector<float> > DetermineRoute(const IGraph* graph, const std::vector<float>& src, const std::vector<float>& dest);
};

}  // namespace csci3081

#endif  // PARABOLIC_ROUTE_H