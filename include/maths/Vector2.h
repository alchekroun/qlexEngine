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

            inline static Vec2 getZeroVec()
            {
                return Vec2(0, 0);
            }

            float getMagnitude() const
            {
                return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
            }

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

            Vec2 operator-(const Vec2<T> &other) const
            {
                return Vec2<T>(x - other.x, y - other.y);
            }

            Vec2 &operator*=(const Vec2<T> &other)
            {
                this->x *= other.x;
                this->y *= other.y;

                return *this;
            }

            Vec2 operator*(const Vec2<T> &other) const
            {
                return Vec2<T>(x * other.x, y * other.y);
            }

            Vec2 &operator/=(const Vec2<T> &other)
            {
                this->x /= other.x;
                this->y /= other.y;

                return *this;
            }

            Vec2 operator/(const Vec2<T> &other) const
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

            Vec2 operator+(const T &k) const
            {
                return Vec2<T>(x + k, y + k);
            }

            Vec2 &operator-=(const T &k)
            {
                this->x -= k;
                this->y -= k;

                return *this;
            }

            Vec2 operator-(const T &k) const
            {
                return Vec2<T>(x - k, y - k);
            }

            Vec2 &operator*=(const T &k)
            {
                this->x *= k;
                this->y *= k;

                return *this;
            }

            Vec2 operator*(const T &k) const
            {
                return Vec2<T>(x * k, y * k);
            }

            friend Vec2 operator*(const T &k, const Vec2<float> &v)
            {
                return v * k;
            }

            Vec2 &operator/=(const T &k)
            {
                this->x /= k;
                this->y /= k;

                return *this;
            }

            Vec2 operator/(const T &k) const
            {
                return Vec2<T>(x / k, y / k);
            }
        };

        inline float dotProduct(const Vec2<float> &v1, const Vec2<float> &v2)
        {
            return v1.x * v2.x + v1.y * v1.y;
        }

        inline float distance(const Vec2<float> &v1, const Vec2<float> &v2)
        {
            return std::sqrt(std::pow((v1.x - v2.x), 2) + std::pow((v1.y - v2.y), 2));
        }

        template <typename T>
        inline std::ostream &operator<<(std::ostream &outs, const Vec2<T> &v)
        {
            return outs << '(' << v.x << ", " << v.y << ')';
        }

    } // maths
} // qlexengine