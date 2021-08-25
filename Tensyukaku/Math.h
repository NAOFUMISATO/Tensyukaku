#pragma once
#include <cmath>
#include <limits>
#include <array>
#include <DxLib.h>

namespace Math {
	// �~����
	constexpr double Pi = 3.1415926535f;
	constexpr double TwoPi = Pi * 2.0f;
	constexpr double PiOver2 = Pi / 2.0f;

	// �x������Ǔx(���W�A��)�ɕϊ�
	inline double ToRadians(double degrees) {
		return degrees * Pi / 180.0f;
	}
	// �Ǔx����x��(�f�B�O���[)�ɕϊ�
	inline double ToDegrees(double radians) {
		return radians * 180.0f / Pi;
	}
	// ��̒l�̑傫���l���擾
	template <typename T>
	T Max(const T& a, const T& b) {
		return (a < b ? b : a);
	}
	// ��̒l�̏������l���擾
	template <typename T>
	T Min(const T& a, const T& b) {
		return (a < b ? a : b);
	}
	// ��̒l�̊ԂŃN�����v����
	template <typename T>
	T Clamp(const T& value, const T& lower, const T& upper) {
		return Min(upper, Max(lower, value));
	}
}

// 2D�x�N�g���N���X
class Vector2 {
public:
	// x����,y����
	double x, y;
	// �R���X�g���N�^
	Vector2() noexcept = default;
	constexpr Vector2(double inX, double inY) noexcept
		: x{ inX }
		, y{ inY } {
	}
	// �x�N�g���̉��Z a + b ���O���֐�
	friend Vector2 operator+(const Vector2& a, const Vector2& b) {
		return { a.x + b.x, a.y + b.y };
	}
	// �x�N�g���̌��Z a - b ���O���֐�
	friend Vector2 operator-(const Vector2& a, const Vector2& b) {
		return { a.x - b.x, a.y - b.y };
	}
	// �x�N�g���̃X�J���[�{ v * scalar ���O���֐�
	friend Vector2 operator*(const Vector2& v, double scalar) {
		return { v.x * scalar, v.y * scalar };
	}
	// �x�N�g���̃X�J���[�{ scalar * v ���O���֐�
	friend Vector2 operator*(double scalar, const Vector2& v) {
		return { v.x * scalar, v.y * scalar };
	}
	// �x�N�g�����Z���
	Vector2& operator+=(const Vector2& right) {
		x += right.x;
		y += right.y;
		return *this;
	}
	// �x�N�g�����Z���
	Vector2& operator-=(const Vector2& right) {
		x -= right.x;
		y -= right.y;
		return *this;
	}
	// �x�N�g���̃X�J����Z���
	Vector2& operator*=(double scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}
	// �x�N�g���̑傫��
	double Length() const {
		return std::sqrt(x * x + y * y);
	}
	// �x�N�g���̐��K��
	void Normalize() {
		auto length = Length();
		x /= length;
		y /= length;
	}
	static Vector2 Normalize(const Vector2& vec) {
		auto temp = vec;
		temp.Normalize();
		return temp;
	}
};