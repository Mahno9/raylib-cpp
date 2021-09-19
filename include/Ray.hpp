#ifndef RAYLIB_CPP_INCLUDE_RAY_HPP_
#define RAYLIB_CPP_INCLUDE_RAY_HPP_

#include "./raylib.hpp"
#include "./raylib-cpp-utils.hpp"
#include "./RayCollision.hpp"

namespace raylib {
/**
 * Ray type (useful for raycast)
 */
class Ray : public ::Ray {
 public:
    Ray(const ::Ray& ray) {
        set(ray);
    }

    Ray(::Vector3 position, ::Vector3 direction) : ::Ray{position, direction} {}

    Ray(::Vector2 mousePosition, ::Camera camera) {
        set(::GetMouseRay(mousePosition, camera));
    }

    Ray& operator=(const ::Ray& ray) {
        set(ray);
        return *this;
    }

    GETTERSETTER(::Vector3, Position, position)
    GETTERSETTER(::Vector3, Direction, direction)

    /**
     * Draw a ray line
     */
    inline Ray& Draw(::Color color) {
        DrawRay(*this, color);
        return *this;
    }

    /**
     * Get collision info between ray and sphere
     */
    inline ::RayCollision CheckCollisionSphere(::Vector3 center, float radius) const {
        return GetRayCollisionSphere(*this, center, radius);
    }

    /**
     * Get collision info between ray and box
     */
    inline ::RayCollision CheckCollision(const ::BoundingBox& box) const {
        return GetRayCollisionBox(*this, box);
    }

    /**
     * Get collision info between ray and model
     */
    inline RayCollision GetCollision(const ::Model& model) const {
        return GetRayCollisionModel(*this, model);
    }

    /**
     * Get collision info between ray and triangle
     */
    inline RayCollision GetCollisionTriangle(::Vector3 p1, ::Vector3 p2, ::Vector3 p3) const {
        return GetRayCollisionTriangle(*this, p1, p2, p3);
    }

    /**
     * Get collision info between ray and quad
     */
    inline RayCollision GetCollisionGround(::Vector3 p1, ::Vector3 p2, ::Vector3 p3, ::Vector3 p4) const {
        return GetRayCollisionQuad(*this, p1, p2, p3, p4);
    }

 private:
    inline void set(const ::Ray& ray) {
        position = ray.position;
        direction = ray.direction;
    }
};
}  // namespace raylib

#endif  // RAYLIB_CPP_INCLUDE_RAY_HPP_
