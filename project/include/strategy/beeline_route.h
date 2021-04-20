/**
 *@file beeline_route.h
 */

#ifndef BEELINE_ROUTE_H
#define BEELINE_ROUTE_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "I_Strategy.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class defines the algorithm for the beeilne drone path.
 *
 */
class Beeline : public IStrategy{
 public:
    Beeline() {}
    ~Beeline() {}

    /** 
     * Beeline path will move the drone to the hieght of 400 then move 
     * directly to the destination. Then lower to the entity's height.
     */
    const std::vector< std::vector<float> > DetermineRoute(const IGraph* graph, const std::vector<float>& src, const std::vector<float>& dest);
};

}  // namespace csci3081

#endif  // BEELINE_ROUTE_H