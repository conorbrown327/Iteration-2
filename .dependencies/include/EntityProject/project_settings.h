#ifndef PROJECT_SETTINGS_H_
#define PROJECT_SETTINGS_H_

#include <EntityProject/entity_system.h>

extern "C"
{
	/// Method to override for each shared library that is built.
	/**
	 * This is a common interface that allows dynamic loading of systems at runtime
	 * rather than compile time.  This will enable drone system competitions between teams.
	 */
	entity_project::IEntitySystem* GetEntitySystem(const std::string& id);
}

#endif // PROJECT_SETTINGS_H_
