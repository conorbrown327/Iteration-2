#include "json_helper.h"
#include "entities/package.h"

namespace csci3081 {

void Package::Deliver() {
  printf("Package %i delivered to customer %i\n", this->id_, customer_->GetId());
  this->SetPosition(Vector3D(0, -1000, 0));
  delivered_ = true;
}

}  // namespace csci3081
