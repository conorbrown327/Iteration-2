/**
 *@file I_Strategy.h
 */
#ifndef I_STRATEGY_H
#define I_STRATEGY_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>
#include <vector>

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the abstract class for the strategy pattern
 *
 */

class IStrategy {
 public:
    /// Virtual deconstructor to delete pointer class
    virtual ~IStrategy() {}

    /** 
     * @brief Virtual method overwritten in the child classes that forms the route
     * for the delivery system.
     *
     * It takes in an IGraph pointer for the
     * Smart route case where calls GetPath(). It takes in the src vector,
     * where the delivery agent starts and dest vector, where the deleivery
     * system is trying to go. It will return a vector of points represented as
     * vectors for the delivery system to follow.
     */
    virtual const std::vector< std::vector<float> > DetermineRoute(const IGraph* graph, const std::vector<float>& src, const std::vector<float>& dest) = 0;
};

}  // namespace csci3081

#endif  // I_STRATEGY_H