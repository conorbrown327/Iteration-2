#include "entity_base.h"
#include "json_helper.h"

namespace csci3081 {

void EntityBase::SetDetails(const picojson::object& obj) {
    t_ = UNDEFINED_ENTITY;
    details_ = obj;
    name_ = (obj.find("name") != obj.end()) ? obj.find("name")->second.get<std::string>() : name_;
    id_++;
    radius_ = (obj.find("name") != obj.end()) ? (float) obj.find("radius")->second.get<double>() : radius_;
    direction_ = JsonHelper::GetStdFloatVector(obj, "direction");
}

void EntityBase::Print() const {
    printf("\x1B[32mEntity %i\033[0m \n", id_);
    std::cout << "name: " << name_ << std::endl;
    printf("position: <%f,%f,%f>\n\n",position_[0], position_[1], position_[2]);
}

}