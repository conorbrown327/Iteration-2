#ifndef ENTITY_SYSTEM_H_
#define ENTITY_SYSTEM_H_

#include "EntityProject/entity.h"
#include <vector>

namespace entity_project {

/// An abstract class that represents an entity system that contains entities and updates over time.
class IEntitySystem {
public:
	/// Destructor
	virtual ~IEntitySystem() {}

	/// Runs a JSON script on an entity system as a set of commands.
	/**
	 * This method does not make any changes to the current entity system, but rather acts
	 * as a strategy for the entity system passed into the method.  It is therefore possible
	 * to override how scripts are read in depending on the application.
	 */
	virtual void RunScript(const picojson::array& script, IEntitySystem* system) const = 0;
	/// Returns the list of entities in the system.
	virtual const std::vector<IEntity*>& GetEntities() const = 0;
	/// Updates the entity system by a time of dt.
	virtual void Update(float dt) = 0;
};


}

#endif // ENTITY_SYSTEM_H_