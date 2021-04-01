#ifndef ENTITY_FACTORY_H_
#define ENTITY_FACTORY_H_

#include "EntityProject/entity.h"

namespace entity_project {
	
/**
 * USAGE: This class is meant to be inhereted by your own entity factory classes
 * Implement this class to manage the creation of entity objects in your system.
 */
class IEntityFactory {
public:
	/// returns a pointer to a newly created entity
	virtual IEntity* CreateEntity(const picojson::object& val) = 0;
	/**
	 * The passed in object val contains an entity's properties to be initialized during creation
	 * The JsonHelper class will be useful for parsing the information in val.
	 */
};

}


#endif // ENTITY_H_
