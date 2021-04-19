/**
 *@file smart_route.h
 */
#ifndef SMART_ROUTE_H
#define SMART_ROUTE_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "I_Strategy.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class defines the smart route drone path.
 */
class Smart : public IStrategy{
 public:
    Smart() {}
    ~Smart() {}

    /**
     * Smart's DetermineRoute will call GetPath on the passed in IGraph
     */
    const std::vector< std::vector<float> > DetermineRoute(const IGraph* graph, const std::vector<float>& src, const std::vector<float>& dest);
};

}  // namespace csci3081

#endif  // SMART_ROUTE_H