#pragma once

#include "Vector2.h"

namespace qlexengine
{
    namespace maths
    {

        template <typename T>
        struct Vec3 : public Vec2<T>
        {
            T z;

            Vec3(T x_, T y_, T z_) : Vec2(x_, y_), z(z_) {}

            // VECTORS OPERATIONS

            Vec3 &operator+=(const Vec3<T> &other)
            {
                this->x += other.x;
                this->y += other.y;
                this->z += other.z;

                return *this;
            }

            Vec3 operator+(const Vec3<T> &other) const
            {
                return Vec3<T>(x + other.x, y + other.y, z + other.z);
            }

            Vec3 &operator-=(const Vec3<T> &other)
            {
                this->x -= other.x;
                this->y -= other.y;
                this->z -= other.z;

                return *this;
            }

            Vec3 operator-(const Vec3<T> &other)
            {
                return Vec3<T>(x - other.x, y - other.y, z - other.z);
            }

            Vec3 &operator*=(const Vec3<T> &other)
            {
                this->x *= other.x;
                this->y *= other.y;
                this->z *= other.z;

                return *this;
            }

            Vec3 operator*(const Vec3<T> &other)
            {
                return Vec3<T>(x * other.x, y * other.y, z * other.z);
            }

            Vec3 &operator/=(const Vec3<T> &other)
            {
                this->x /= other.x;
                this->y /= other.y;
                this->z /= other.z;

                return *this;
            }

            Vec3 operator/(const Vec3<T> &other)
            {
                return Vec3<T>(x / other.x, y / other.y, z / other.z);
            }

            // SCALAR OPERATIONS

            Vec3 &operator+=(const T &k)
            {
                this->x += k;
                this->y += k;
                this->z += k;

                return *this;
            }

            Vec3 operator+(const T &k)
            {
                return Vec3<T>(x + k, y + k, z + k);
            }

            Vec3 &operator-=(const T &k)
            {
                this->x -= k;
                this->y -= k;
                this->z -= k;

                return *this;
            }

            Vec3 operator-(const T &k)
            {
                return Vec3<T>(x - k, y - k, z - k);
            }

            Vec3 &operator*=(const T &k)
            {
                this->x *= k;
                this->y *= k;
                this->z *= k;

                return *this;
            }

            Vec3 operator*(const T &k)
            {
                return Vec3<T>(x * k, y * k, z * k);
            }

            Vec3 &operator/=(const T &k)
            {
                this->x /= k;
                this->y /= k;
                this->z /= k;

                return *this;
            }

            Vec3 operator/(const T &k)
            {
                return Vec3<T>(x / k, y / k, z / k);
            }
        };

        template <typename T>
        std::ostream &operator<<(std::ostream &outs, const Vec3<T> &v)
        {
            return outs << '(' << v.x << ", " << v.y << ", " << v.z << ')';
        }

    } // maths
} // qlexengine