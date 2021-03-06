#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iosfwd>

struct Vector2D
{
	int x;
	int y;

	Vector2D();
	Vector2D(int, int);
	~Vector2D();

	Vector2D& add(const Vector2D&);
	Vector2D& substract(const Vector2D&);
	Vector2D& multiply(const Vector2D&);
	Vector2D& divide(const Vector2D&);

	friend Vector2D& operator+(Vector2D, const Vector2D&);
	friend Vector2D& operator-(Vector2D, const Vector2D&);
	friend Vector2D& operator*(Vector2D, const Vector2D&);
	friend Vector2D& operator/(Vector2D, const Vector2D&);

	friend Vector2D& operator*(Vector2D, int);
	friend Vector2D& operator*(Vector2D, double);

	Vector2D& operator+=(const Vector2D&);
	Vector2D& operator-=(const Vector2D&);
	Vector2D& operator*=(const Vector2D&);
	Vector2D& operator/=(const Vector2D&);

	Vector2D& operator*=(int);

	friend std::ostream& operator<<(std::ostream& stream, const Vector2D& v);
};

#endif