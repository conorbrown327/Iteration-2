#ifndef ENTITY_CONSOLE_LOGGER_H_
#define ENTITY_CONSOLE_LOGGER_H_

#include <iostream>
#include "EntityProject/entity_observer.h"

namespace entity_project {

/// The Entity Console Logger outputs entity events to the command line
class EntityConsoleLogger : public IEntityObserver {
public:
	virtual void OnEvent(const picojson::value& event, const IEntity& entity) {
		std::cout << "Entity #" << entity.GetId() << ": " << event.serialize() << std::endl;
	}
};

}


#endif // ENTITY_CONSOLE_LOGGER_H_
