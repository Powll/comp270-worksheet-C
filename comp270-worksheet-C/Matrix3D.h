#pragma once
#include "Point3D.h"

// A class for performing basic 3D transformation operations with homogeneous matrices.
// Feel free to edit/extend!
class Matrix3D
{
public:
	// Const accessor for individual components.
	const float& operator()(unsigned i, unsigned j) const
	{
		return m_[i][j];
	}

	// Writable accessor for individual components.
	float& operator()(unsigned i, unsigned j)
	{
		return m_[i][j];
	}

	// Apply this matrix to a vector
	Vector3D operator*(const Vector3D& vec) const
	{
		Vector3D result(vec);
		multiply(result.x, result.y, result.z, result.w);
		return result;
	}

	// Apply this matrix to a point
	Point3D operator*(const Point3D& pt) const
	{
		Point3D result(pt);
		multiply(result.x, result.y, result.z, result.w);
		return result;
	}

	// Apply another matrix to this one
	Matrix3D operator*(const Matrix3D& right)
	{
		Matrix3D result(right);
		multiply(result(0, 0), result(1, 0), result(2, 0), result(3, 0));
		multiply(result(0, 1), result(1, 1), result(2, 1), result(3, 1));
		multiply(result(0, 2), result(1, 2), result(2, 2), result(3, 2));
		multiply(result(0, 3), result(1, 3), result(2, 3), result(3, 3));
		return result;
	}

	// Add two matrices together
	Matrix3D operator+(const Matrix3D& other)
	{
		Matrix3D result(other);

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				result(i, j) = this->m_[i][j] + other.m_[i][j];
			}
		}

		return result;
	}

	Matrix3D inverseTransform() const;

private:
	float	m_[4][4] = {	{ 1.0f, 0.0f, 0.0f, 0.0f },
							{ 0.0f, 1.0f, 0.0f, 0.0f },
							{ 0.0f, 0.0f, 1.0f, 0.0f },
							{ 0.0f, 0.0f, 0.0f, 1.0f } };

	void multiply(float& x, float& y, float& z, float& w) const;
									
};