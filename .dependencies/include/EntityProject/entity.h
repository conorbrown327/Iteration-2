#ifndef ENTITY_H_
#define ENTITY_H_

#include <sstream>
#include "picojson.h"

namespace entity_project {

/// A movable object in a scene. Entities have position, direction and size.
/** 
 * @brief Defines the common characteristics of an Entity.
 * 
 * All entities that you create must implement this interface.
 */
class IEntity {
public:
	/// The destructor.
	virtual ~IEntity() {}
	/**
   * Returns the unique entity id. Each Entity should have a unique ID.
   */
	virtual int GetId() const = 0;
	/**
   * Returns the name of an entity. (Should match the "name" field of the json
   * that was passed in when the entity was created)
   */ 
	virtual const std::string& GetName() = 0;

	/** Returns the entity's position. The returned vector should have three
   * values which correspond to the x, y, z, position of the entity.
   */
	virtual const std::vector<float>& GetPosition() const = 0;
	/**
   * Returns the entity's direction. The vector should be a unit length vector.
   */
	virtual const std::vector<float>& GetDirection() const = 0;
	/**
   * Returns the entity's radius.
	 * Entities are bounded by a sphere used for calculating proximity to
	 * boundaries or other entities.
	 */
	virtual float GetRadius() const = 0;
	/**
   * Returns the entity's details. The returned picojson::object should be a 
   * copy of the json that was passed in when the entity was created.
	 * Details are also used to send additional information to other
	 * subsystems (e.g. mesh, scale, rotation, etc...).
	 */
	virtual const picojson::object& GetDetails() = 0;
	/**
   * Get version can be used to see whether or not a variable other than position 
   * or direction has changed.
   */
	virtual int GetVersion() const = 0;
	/** This method specifies whether or not the entity is static (doesn't change) or moves.
   * It should return true if you want the entities position/orientation to be updated 
   * in the visualization.
	 *
	 * Combining GetVersion() with a non-dynamic entity allows the entity to be
	 * updated less often than on a frame by frame basis for other subsystems.
	 * For example, we may want to update a dynamic object every frame, while it is 
	 * more efficient to update a static object only when the version changes.
	 */
	virtual bool IsDynamic() const = 0;
};

}


#endif // ENTITY_H_
