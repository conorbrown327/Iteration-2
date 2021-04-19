/**
 * @file vector3d.h
 */
#ifndef VECTOR_3D_H_
#define VECTOR_3D_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <assert.h>
#include <math.h>
#include <ostream>

namespace csci3081 {
  /*******************************************************************************
   * Class Definitions
   ******************************************************************************/
  /**
   * @brief This is the struct for calculating vector math in the simulation.
   *
   * This struct will handle any vector calculations needed for entity movement.
   *
   */
struct Vector3D {
    float x, y, z;
    ~Vector3D() {}
    /**
     * @brief Constructor: this will create a vector with the x,y,z values passed in.
     * The default values for a Vector3D object are 0,0,0
     */
    Vector3D(float x_ = 0, float y_ = 0, float z_ = 0) : x(x_), y(y_), z(z_) {}
    Vector3D(std::vector<float> vec) : x(vec[0]), y(vec[1]), z(vec[2]) {}
    Vector3D(const Vector3D& rhs) { x = rhs.x; y = rhs.y; z = rhs.z; }

    Vector3D operator=(const Vector3D& rhs) {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        return *this;
    }

    Vector3D operator+(const Vector3D& rhs) { return Vector3D(x + rhs.x, y + rhs.y, z + rhs.z); }
    Vector3D operator-(const Vector3D& rhs) { return Vector3D(x - rhs.x, y - rhs.y, z - rhs.z); }
    Vector3D operator*(float scalar) { return Vector3D(x * scalar, y * scalar, z * scalar); }
    Vector3D operator/(float scalar) { return Vector3D(x / scalar, y / scalar, z / scalar); }

    Vector3D operator+=(const Vector3D& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    Vector3D operator+=(float s) {
        x += s;
        y += s;
        z += s;
        return *this;
    }

    Vector3D operator-=(const Vector3D& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }

    Vector3D operator-=(float s) {
        x -= s;
        y -= s;
        z -= s;
        return *this;
    }

    Vector3D operator*=(float s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Vector3D pow(float n) {
        return Vector3D(std::pow(this->x, n), std::pow(this->y, n), std::pow(this->z, n));
    }

    bool operator==(const Vector3D rhs) { return (x == rhs.x && y == rhs.y && z == rhs.z); }
    bool operator!=(const Vector3D rhs) { return (x != rhs.x || y != rhs.y || z != rhs.z); }

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
      os << "<" << v.x << "," << v.y << "," << v.z << ">";
      return os;
    }

    ///Calculates the magnitude of the vector
    float Magnitude() { return std::sqrt(x*x + y*y + z*z); }
	float Dot(const Vector3D& rhs) { return x*rhs.x + y*rhs.y + z*rhs.z; }

    ///Normalizes the vector
    Vector3D Normalize() {
        if (this->Magnitude() == 0) return *this;
        float l = this->Magnitude();
        this->x / l;
        this->y / l;
        this->z / l;
        return *this;
    }

    ///Returns the std::vector version of a Vector3D struct
    std::vector<float> ToVector() { std::vector<float> result = {x, y, z}; return result; }

    ///Converts the std::vector<std::vector<float>> into a std::vector<Vector3D> object
    static std::vector<Vector3D> BuildRoute(std::vector<std::vector<float>> pts) {
        std::vector<Vector3D> route;
        for (auto pt : pts) {
            route.push_back(Vector3D(pt));
        }
        return route;
    }

    void Print() const { printf("<%f,%f,%f>\n", x, y, z); }

    ///Returns the distance between two Vector3D structs
    float DistanceTo(const Vector3D& rhs) {
        return std::sqrt(std::pow(rhs.x-x,2)+std::pow(rhs.y-y,2)+std::pow(rhs.z-z,2));
    }

};

}  // namespace csci3081

#endif  // VECTOR_3_H_
#pragma once
