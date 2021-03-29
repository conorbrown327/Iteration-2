#ifndef SCENE_VIEWER_H_
#define SCENE_VIEWER_H_

#include "EntityProject/entity_system.h"
#include <string>
#include <vector>

namespace entity_project {

/// Abstact class for viewing a scene representing an entity system.
/**
 * Overide this class for different types of viewers.
 */
class ISceneViewer {
public:
	/// Destructor
	virtual ~ISceneViewer() {}

	/// Sets the current entity system model that the viewer visualizes
	virtual void SetEntitySystem(IEntitySystem* entitySystem) = 0;
	/// Returns the current entity system.
	virtual IEntitySystem* GetEntitySystem() const = 0;
	/// Runs the visualization.
	virtual bool Run() = 0;
};

}


#endif // SCENE_VIEWER_H_