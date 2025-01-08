#pragma once

#include <iostream>

namespace qlexengine
{
    namespace maths
    {

        template <typename T>
        struct Vec2
        {
            T x;
            T y;

            Vec2(T x_, T y_) : x(x_), y(y_) {}

            // VECTORS OPERATIONS

            Vec2 &operator+=(const Vec2<T> &other)
            {
                this->x += other.x;
                this->y += other.y;

                return *this;
            }

            Vec2 operator+(const Vec2<T> &other) const
            {
                return Vec2<T>(x + other.x, y + other.y);
            }

            Vec2 &operator-=(const Vec2<T> &other)
            {
                this->x -= other.x;
                this->y -= other.y;

                return *this;
            }

            Vec2 operator-(const Vec2<T> &other)
            {
                return Vec2<T>(x - other.x, y - other.y);
            }

            Vec2 &operator*=(const Vec2<T> &other)
            {
                this->x *= other.x;
                this->y *= other.y;

                return *this;
            }

            Vec2 operator*(const Vec2<T> &other)
            {
                return Vec2<T>(x * other.x, y * other.y);
            }

            Vec2 &operator/=(const Vec2<T> &other)
            {
                this->x /= other.x;
                this->y /= other.y;

                return *this;
            }

            Vec2 operator/(const Vec2<T> &other)
            {
                return Vec2<T>(x / other.x, y / other.y);
            }

            // SCALAR OPERATIONS

            Vec2 &operator+=(const T &k)
            {
                this->x += k;
                this->y += k;

                return *this;
            }

            Vec2 operator+(const T &k)
            {
                return Vec2<T>(x + k, y + k);
            }

            Vec2 &operator-=(const T &k)
            {
                this->x -= k;
                this->y -= k;

                return *this;
            }

            Vec2 operator-(const T &k)
            {
                return Vec2<T>(x - k, y - k);
            }

            Vec2 &operator*=(const T &k)
            {
                this->x *= k;
                this->y *= k;

                return *this;
            }

            Vec2 operator*(const T &k)
            {
                return Vec2<T>(x * k, y * k);
            }

            Vec2 &operator/=(const T &k)
            {
                this->x /= k;
                this->y /= k;

                return *this;
            }

            Vec2 operator/(const T &k)
            {
                return Vec2<T>(x / k, y / k);
            }
        };

        template <typename T>
        std::ostream &operator<<(std::ostream &outs, const Vec2<T> &v)
        {
            return outs << '(' << v.x << ", " << v.y << ')';
        }

    } // maths
} // qlexengine