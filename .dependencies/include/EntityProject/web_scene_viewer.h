#ifndef WEB_SCENE_VIEWER_H_
#define WEB_SCENE_VIEWER_H_

#include <string>
#include <vector>

#include "EntityProject/scene_viewer.h"
#include "EntityProject/entity_observer.h"

namespace entity_project {

/// Represents the hidden state of the web viewer
/**
 * This is hidden in the implementation so that additional complexity and
 * dependencies are not involved in user code.
 */
struct WebSceneViewerState;

/// A web viewer for the entity system that uses web sockets.
class WebSceneViewer : public ISceneViewer, public IEntityObserver {
public:
	/// Constructor that initializes with a port and a website directory
	WebSceneViewer(int port, const std::string& webDir, const std::string& scene);
	/// Destructor
	virtual ~WebSceneViewer();

	/// Sets the current entity system.
	/**
	 * This is overriden so that the web viewer can observe entities.
	 */
	void SetEntitySystem(IEntitySystem* entitySystem);
	/// Returns the current entity system.
	virtual IEntitySystem* GetEntitySystem() const { return entitySystem_; }
	/// Runs the web viewer.
	bool Run();
	/// Sends events to the web page over web sockets.
	void OnEvent(const picojson::value& event, const IEntity& entity);
	/// Sends JSON to all web clients
	void SendJSON(const picojson::value& json);

protected:
	/// The current entity system.
	IEntitySystem* entitySystem_;

private:
	WebSceneViewerState* state;
};

}


#endif // ENTITY_H_