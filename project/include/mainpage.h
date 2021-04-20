/*! \mainpage CSCI 3081 Delivery Simulation project
*
* \section team_docs Team Documentation
*
* Roles:
*
* Development Lead    | Noah \n
* Scheduler           | Erik \n
* Reporter            | Nick \n
* Project Manager     | Conor \n
*\n
* Meetings:
*
* - 4/5/21
*   - Assigned Nick and Erik to Priority One and Two, respectively
* - 4/12/21
*   - Assigned Conor and Noah to Priority Three and Four, respectively
* - 4/19/21
*   - Merged branches into master for final turn-in and completed group documentation
*
* \section strategy_pattern Designing and Implementing the different routes
* 
* The drones required three different routes to pick from depending on various factors like weather. This included a smart route, beeline route and a parabolic route. \n
* The smart route uses a map of the streets to plan out its path. It will determine the fastest route as if it couldn’t fly up and follow the streets to its destination. The code for the smart route is contained within smart_route.h and smart_route.cc. \n
* The beeline route first moves the drone to a given height to avoid flying into any buildings. The drone will then move on a straight line to its target. Finally, the drone will lower straight down to the target. The code for this strategy is contained within beeline_route.h and beeline_route.cc. \n
* The parabolic path calculates an arced path for the drone to follow to reach its target. It will break this parabola into ten steps for the drone to follow. This code is contained within parabolic_route.h and parabolic_route.cc. \n
* The implementation of the multiple drone routes was implemented with a strategy pattern. The strategy pattern defines an abstract class IStrategy, contained within I_Strategy.h, the has 3 child classes, Smart, Beeline, and Parabolic. Each of the child classes overwrites the virtual method DetermineRoute defined in IStrategy. Smart’s implementation of DetermineRoute uses the provided GetPath function to determine the smart route. Beeline’s DetermineRoute will create a vector of points, represented as vectors, for the drone to follow. Initially, the drone will move up to a height to avoid buildings in ten steps. Then it will move to the destination’s x and z position in ten steps. Finally, the drone will lower to the destination in 10 steps. The DetermineRoute defined in Parabolic will calculate an arc from the starting position to the destination. The drone will then follow this arc in a series of ten steps. \n
* An IStrategy* was added to the protected attributes of delivery_agent.h. This specifies the strategy to be used by the delivery agent. By default, it is set as a smart route. This is the route used by robots, which cannot fly and drones that do not have a specified route. A getter and setter were added for the IStrategy* in DeliveryAgent as well as the function, DetermineStrategy, to assign which strategy is specified by the drone’s json attributes. In delivery_simulation.cc’s ScheduleDelivery function, DetermineStrategy is called if the DeliveryAgent has specified the key “path” within the json object. If not the default is already set as Smart in DeliveryAgent. \n
* \image html /strategy_uml.PNG "Strategy Pattern" width = 900 cm
* The most difficult part of the strategy pattern implementation was calculating the parabolic path. The lab and supplement to lab posted on canvas were helpful in solving that problem. Where to put everything and organize the strategy pattern was confusing at first. However, the lab on the strategy pattern alleviated that problem. \n
* \image html /lab_help.PNG "Equations from lab supplement" width = 900 cm
*
* \section observer_pattern Observer Pattern Discussion
* The observer pattern was used to allow the simulations entities to notify observers in
* the delivery simulation of changes in the state of the entity. For example, when the
* drone delivers a package and stops moving it will notify the observers of this change.
* This notification is printed in a UI on the simulations left hand side. The observer
* pattern was useful because it is dynamic and allows for new observers to be added and
* removed easily.
*
* 
*/
