/**
 *@file composite_factory.h
 */
#ifndef COMPOSITE_FACTORY_H_
#define COMPOSITE_FACTORY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>

#include <EntityProject/entity_factory.h>
#include "factories/drone_factory.h"
#include "entity_base.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the composite facory used for creating entities
 *
 */

class CompositeFactory : public IEntityFactory {
 public:
  CompositeFactory();
  ~CompositeFactory();

  /** 
   * Overridden by each entity factor that will create an 
   * instance of that entity
   */
  IEntity* CreateEntity(const picojson::object &val) override;
  /// Add an entities factory to factories_
  void AddFactory(IEntityFactory* factory);

 private:
  /// Vector of all entity factories to be created
  std::vector<IEntityFactory*> factories_;
};

}

#endif  // SRC_COMPOSITE_FACTORY_H_
