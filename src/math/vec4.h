//
// Created by blinku on 02.02.19.
//

#pragma once

#include <iostream>
#include "pch.h"

namespace Bald::Math {
    class Vec4 {
    public:
        /**
         * @fn                          Vec4
         * @brief                       constructor
         * @param [float]               x variable
         * @param [float]               y variable
         * @param [float]               z variable
         * @param [float]               w variable
         */
        explicit constexpr Vec4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f)
            : m_X(x), m_Y(y), m_Z(z), m_W(w) {}

        /**
        * @fn                          MakeUnitVec
        * @brief                       creates unit vector with the length of 1.0f
        * @param [const Vec4&]         vec -> vector which will be used to create unit vector
        * @return [Vec4]               unit long vector
        */
        [[nodiscard]] static Vec4 MakeUnitVec(const Vec4& vec) noexcept;

        /**
         * @fn                          Normalize
         * @brief                       normalizes vector to the length of 1.0f
         *                              (divides each component by the length of the vector)
         */
        constexpr void Normalize() noexcept;

        /**
        * @fn                          MakeReverseVec
        * @brief                       creates reverse vector of a given vector
        * @param [const Vec4&]         vec -> vector which will be used to create reversed vector
        * @return [Vec4]               new, reversed vector
        */
        [[nodiscard]] static constexpr Vec4 MakeReverseVec(const Vec4& vec) noexcept;

        /**
         * @fn                         Reverse
         * @brief                      reverses the current vector
         * @return [void]
         */
        constexpr void Reverse() noexcept;

        /**
         * @fn                          DotProduct
         * @brief                       calculates dot product between two vectors
         * @param [const Vec4&]         vec1 vector
         * @param [const Vec4&]         vec2 vector
         * @return [float]              dot product of the vector passed in
         */
        [[nodiscard]] static constexpr float DotProduct(const Vec4& vec1, const Vec4& vec2) noexcept;

        /**
         * @fn                          AngleBetween
         * @brief                       returns angle in RADIANS between two vectors
         * @param [const Vec4&]         vec1 vector
         * @param [const Vec4&]         vec2 vector
         * @return [float]              angle in radians
         */
        [[nodiscard]] static constexpr float AngleBetween(const Vec4& vec1, const Vec4& vec2) noexcept;

        /**
         * @fn                          Length
         * @brief                       calculates the length of the vector
         * @return [float]              length of the vector
         */
        [[nodiscard]] constexpr float Length() const noexcept;

        /**
         * @fn                          operator+
         * @brief                       adds another vector to the current vector
         * @param [const Vec4&]         other vector
         * @return [Vec4]               new vector
         */
        [[nodiscard]] constexpr Vec4 operator+(const Vec4& other) const noexcept;


        /**
         * @fn                          operator-
         * @brief                       subtracts another vector from the current vector
         * @param [const Vec4&]         other vector
         * @return [Vec4]               new vector
         */
        [[nodiscard]] constexpr Vec4 operator-(const Vec4& other) const noexcept;

        /**
         * @fn                          operator*
         * @brief                       multiplies current vector by the passed multiplier
         * @param [float]               multiplier
         * @return [Vec4]               new vector
         */
        [[nodiscard]] constexpr Vec4 operator*(float multiplier) const noexcept;

        /**
         * @fn                          operator+=
         * @brief                       adds another vector to the current vector
         * @param [const Vec4&]         other vector
         * @return [Vec4&]              current vector added with the passed vector
         */
        constexpr Vec4& operator+=(const Vec4& other) noexcept;

        /**
         * @fn                          operator-=
         * @brief                       adds reversed other vector to the current vector
         * @param [const Vec4&]         other vector
         * @return [Vec4&]              current vector subtracted with the passed vector
         */
        constexpr Vec4& operator-=(const Vec4& other) noexcept;

        /**
         * @fn                          operator*=
         * @brief                       multiplies current vector by the passed multiplier
         * @param [const Vec43&]         other vector
         * @return [Vec4&]              current vector multiplied by the passed multiplier
         */
        constexpr Vec4& operator*=(float multiplier) noexcept;

        /**
         * @fn                          operator==
         * @brief                       checks if the two vectors are the same
         * @param [const Vec4&]          other vector
         * @return [bool]               true  - vectors are     the same
         *                              false - vectors are NOT the same
         */
        constexpr bool operator==(const Vec4& other) const noexcept;

        /**
         * @fn                          operator!=
         * @brief                       checks if the two vectors are NOT the same
         * @param [const Vec4&]          other vector
         * @return [bool]               true  - vectors are NOT the same
         *                              false - vectors are     the same
         */
        constexpr bool operator!=(const Vec4& other) const noexcept;

        /**
         * @fn                          operator<<
         * @brief                       prints the Vec4
         * @param [std::ostream&]       output stream
         * @param [const Vec4&]         vector object to be printed
         * @return [std::ostream&]      stream
         */
        [[nodiscard]] friend std::ostream &operator<<(std::ostream& out, const Vec4& vec) noexcept;

        /**
         * @fn                          GetX
         * @brief                       returns m_X component
         * @return [float]              m_X
         */
        [[nodiscard]] constexpr inline float GetX() const noexcept { return m_X; }

        /**
         * @fn                          GetY
         * @brief                       returns m_Y component
         * @return [float]              m_Y
         */
        [[nodiscard]] constexpr inline float GetY() const noexcept { return m_Y; }

        /**
         * @fn                          GetZ
         * @brief                       returns m_Z component
         * @return [float]              m_Z
         */
        [[nodiscard]] constexpr inline float GetZ() const noexcept { return m_Z; }

        /**
         * @fn                          GetW
         * @brief                       returns m_W component
         * @return [float]              m_W
         */
        [[nodiscard]] constexpr inline float GetW() const noexcept { return m_W; }
    private:
        float m_X;
        float m_Y;
        float m_Z;
        float m_W;
    }; // END OF CLASS Vec4

        Vec4 Vec4::MakeUnitVec(const Vec4& vec) noexcept {
                float len = vec.Length();
                if(len != 0)
                    return Vec4(vec.GetX() / len, vec.GetY() / len, vec.GetZ() / len, vec.GetW() / len);
                CORE_LOG_WARN("[Vec4] Cannot make unit vector from zero vector!");
                return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
        }

        constexpr void Vec4::Normalize() noexcept {
                float len = Length();
                if (len != 0) {
                        m_X /= len;
                        m_Y /= len;
                        m_Z /= len;
                        m_W /= len;
                }
        }

        constexpr Vec4 Vec4::MakeReverseVec(const Vec4& vec) noexcept {
                return Vec4(-1.0f * vec.GetX(), -1.0f * vec.GetY(), -1.0f * vec.GetZ(), -1.0f * vec.GetW());
        }

        constexpr void Vec4::Reverse() noexcept {
                m_X *= -1.0f;
                m_Y *= -1.0f;
                m_Z *= -1.0f;
                m_W *= -1.0f;
        }

        constexpr float Vec4::DotProduct(const Vec4& vec1, const Vec4& vec2) noexcept {
                return vec1.GetX() * vec2.GetX() + vec1.GetY() * vec2.GetY() + vec1.GetZ() * vec2.GetZ() + vec1.GetW() * vec2.GetW();
        }

        constexpr float Vec4::AngleBetween(const Vec4& vec1, const Vec4& vec2) noexcept {
                float dot = DotProduct(vec1, vec2);
                float len = vec1.Length() * vec2.Length();
                return static_cast<float>(acos(dot / len));
        }

        constexpr float Vec4::Length() const noexcept {
                return static_cast<float>(sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z + m_W * m_W));
        }

        constexpr Vec4 Vec4::operator+(const Vec4& other) const noexcept {
                return Vec4(m_X + other.m_X, m_Y + other.m_Y, m_Z + other.m_Z, m_W + other.m_W);
        }

        constexpr Vec4 Vec4::operator-(const Vec4& other) const noexcept {
                return Vec4(m_X - other.m_X, m_Y - other.m_Y, m_Z - other.m_Z, m_W - other.m_W);
        }

        constexpr Vec4 Vec4::operator*(float multiplier) const noexcept {
                return Vec4(multiplier * m_X, multiplier * m_Y, multiplier * m_Z, multiplier * m_W);
        }

        constexpr Vec4& Vec4::operator+=(const Vec4& other) noexcept {
                m_X += other.m_X;
                m_Y += other.m_Y;
                m_Z += other.m_Z;
                m_W += other.m_W;
                return *this;
        }

        constexpr Vec4& Vec4::operator-=(const Vec4& other) noexcept {
                m_X -= other.m_X;
                m_Y -= other.m_Y;
                m_Z -= other.m_Z;
                m_W -= other.m_W;
                return *this;
        }

        constexpr Vec4& Vec4::operator*=(float multiplier) noexcept {
                m_X *= multiplier;
                m_Y *= multiplier;
                m_Z *= multiplier;
                m_W *= multiplier;
                return *this;
        }

        constexpr bool Vec4::operator==(const Vec4& other) const noexcept {
                return m_X == other.m_X && m_Y == other.m_Y && m_Z == other.m_Z && m_W == other.m_W;
        }

        constexpr bool Vec4::operator!=(const Vec4& other) const noexcept {
                return !(*this == other);
        }

        std::ostream& operator<<(std::ostream& out, const Vec4& vec) noexcept {
                out << "[" << vec.m_X << ", " << vec.m_Y << ", " << vec.m_Z << ", " << vec.m_W << "]\n";
                return out;
        }

} // END OF NAMESPACE Bald::Math