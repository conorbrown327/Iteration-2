#ifndef ENTITY_OBSERVER_H_
#define ENTITY_OBSERVER_H_

#include "EntityProject/entity.h"

namespace entity_project {

/// Observers entity events when they occur.
/**
 * USAGE: This class is meant to be inhereted by your own entity observer class
 * This class is available in order to enable the observer pattern for entities.
 * A callback function onEvent 
 */
class IEntityObserver {
public:
	/// Destructor
	virtual ~IEntityObserver() {}
	/// Callback when an event happens.
	virtual void OnEvent(const picojson::value& event, const IEntity& entity) = 0;
        /**
	 * Use this function to alert an observer to a change in the passed in entity.
	 */
};

}


#endif // ENTITY_OBSERVER_H_
