#ifndef OSM_GRAPH_PARSER_H_
#define OSM_GRAPH_PARSER_H_

#include "EntityProject/graph.h"

namespace entity_project {

/// Parses an Open Street Map xml file along with a normalized height map.
class OSMGraphParser {
public:
	/// Destructor
	virtual ~OSMGraphParser() {}
	/// Creates a graph by parsing a osm file and a height map.
	const IGraph* CreateGraph(const std::string& osmFile, const std::string& heightFile) const;
};

}

#endif