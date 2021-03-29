#ifndef FACADE_DELIVERY_SYSTEM_H_
#define FACADE_DELIVERY_SYSTEM_H_

#include "EntityProject/facade/common.h"

namespace csci3081 {

/// The abstract facade of a drone delivery subsystem.
/**
 * USAGE: this class is meant to be inherited by a delivery system class you create.
 * Extend this class to manage the drone delivery subsystem of entities.
 */
class IDeliverySystem : public IEntitySystem {
public:
	/// Destructor
	virtual ~IDeliverySystem() {}
	/// Translates a set of JSON commands into method calls for the drone delivery system
	/**
	 * The script will be called by main.cc
	 * Override this method only if you would like to control or extend your own script commands.
	 */
	virtual void RunScript(const picojson::array& script, IEntitySystem* system) const = 0;
	/// Creates an entity based on a JSON object passed in.
	/**
	 * Passes a json object to an entity factory to create that entity.
	 * The entity creation should be done by your entity factory.
	 *
	 * Essentially, this method represents a factory so that creation is separate from the system itself.
	 * This means that entities can be created for use outside the subsystem.  It also ensures entities can
	 * be created within or outside the system for any reason.
	 */
	virtual IEntity* CreateEntity(const picojson::object& val) = 0;
    /// Adds an entity factory to a composite factory for creating new entities.
    virtual void AddFactory(IEntityFactory* factory) = 0;
	/// Adds an entity to an entity vector member. Once added, entities can be affected by the system.
	virtual void AddEntity(IEntity* entity) = 0;
    	/// Adds the graph used for dynamic routing in the delivery system.
	virtual void SetGraph(const IGraph* graph) = 0;
	/// Schedule a drone delivery for a package to be delivered to a customer.
	/**
	 * Package/Customer details allows extra specifications for package delivery based on the business needs.
	 */
	virtual void ScheduleDelivery(IEntity* package, IEntity* dest) = 0;
	/// Add an observer to a specific entity.
	virtual void AddObserver(IEntityObserver* observer) = 0;
	/// Remove an observer from a specific entity.
	virtual void RemoveObserver(IEntityObserver* observer) = 0;
	/// Returns all the entities that are added to the drone system.
	virtual const std::vector<IEntity*>& GetEntities() const = 0;
	/// Updates the drone system time by dt.
	virtual void Update(float dt) = 0;
    /**
	 * This method will be repeatedly called to keep the simulation up to date.
	 * This should modify the states of entities in the system relative to the amount of time that has passed.
	 */
};

}

#endif
