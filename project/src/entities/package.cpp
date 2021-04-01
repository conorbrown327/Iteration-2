#include "json_helper.h"
#include "entities/package.h"

namespace csci3081 {

void Package::Deliver() {
  printf("Package %i delivered to customer %i\n", this->id_, customer_->GetId());
  this->SetPosition(Vector3D(0, -1000, 0));
  delivered_ = true;
}

void Package::Notify(std::vector<IEntityObserver*> observers, std::string value){
  for (IEntityObserver* observer : observers){
		picojson::object notification = JsonHelper::CreateJsonNotification();
		JsonHelper::AddStringToJsonObject(notification, "value", value);
		picojson::value package_value = JsonHelper::ConvertPicojsonObjectToValue(notification);
		observer->OnEvent(package_value, *this);
	}
}

}  // namespace csci3081
