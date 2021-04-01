/**
 *@file entity_base.h
 */
#ifndef ENTITY_BASE_H_
#define ENTITY_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <EntityProject/facade/delivery_system.h>
#include "lib/vector3d.h"

namespace csci3081 {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base class for creating entities.
 *
 * This class can be used as the base for all entities in the delivery system.
 * The overall design is up to you (the student), but all entities must implement
 * the IEntity interface.
 *
 * See the documentation for IEntity for more information
 */
enum EntityType { UNDEFINED_ENTITY, DRONE, CUSTOMER, PACKAGE, ROBOT };

class EntityBase : public IEntity {
 public:
  virtual ~EntityBase() {}

    /// Returns the unique entity id.
    int GetId() const override { return id_; }
    /// Returns the name of an entity.
    const std::string& GetName() override { return name_; }
    /// Returns the entity's position.
    const std::vector<float>& GetPosition() const override { return position_; }
    /// Returns the entity's direction.
    const std::vector<float>& GetDirection() const override { return direction_; }
    /// Returns the entity's radius.
    float GetRadius() const override { return radius_; }
    ///Get version can be used to see whether or not a variable other than position or direction has changed.
    int GetVersion() const override { return 0; }

    EntityType GetType() { return t_; }
    /// This method specifies whether or not the entity is static (doesn't change often) or moves.
    bool IsDynamic() const override { return false; }

    const picojson::object& GetDetails() override { return details_; }

    void SetPosition(std::vector<float> position) { position_ = position; }

    void SetPosition(Vector3D position) { position_ = {position.x, position.y, position.z}; }

    void SetDirection(Vector3D target) { direction_ = (target -= Vector3D(position_)).Normalize().ToVector(); }

    void SetType(EntityType t) { t_ = t; }

    void SetDetails(const picojson::object& obj);

    Vector3D GetVPosition() { return Vector3D(position_); }

    void SetId(int id) { id_ = id; }

    void Print() const;

protected:
    EntityType t_ = UNDEFINED_ENTITY;
    picojson::object details_;
    std::string name_ = "undefined";
    int id_ = -99;
    float radius_ = 1.0;
    std::vector<float> position_;
    std::vector<float> direction_;

};

}  // namespace csci3081

#endif  // ENTITY_BASE_H_
