#ifndef _VEC3_H__
#define _VEC3_H__

template <class TYPE>
class vec3 {

public:

	TYPE x, y, z;


	// CONSTRUCTORS

	vec3()
	{}

	vec3(const vec3& vec)
	{
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
	}

	vec3(const TYPE& x, const TYPE& y, const TYPE& z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}


	// METHODS

	void normalize()
	{
		TYPE module = (TYPE) sqrt(x*x + y*y + z*z);
		x = x / module;
		y = y / module;
		z = z / module; 
	}

	vec3 zero()
	{
		x = 0;
		y = 0;
		z = 0;

		return *this; 
	}

	bool is_zero()
	{
		return (x == 0 && y == 0 && z == 0);
	}


	TYPE distance_to(const vec3& vec)
	{
		return (TYPE) sqrt((x - vec.x)*(x - vec.x) + (y - vec.y)*(y - vec.y) + (z - vec.z)*(z - vec.z));
	}

	TYPE distance_to_squared(const vec3& vec)
	{
		return (TYPE) ((x - vec.x)*(x - vec.x) + (y - vec.y)*(y - vec.y) + (z - vec.z)*(z - vec.z));
	}


	// OPERATORS
	vec3 operator +(const vec3& vec)
	{
		return vec3(vec.x + x, vec.y + y, vec.z + z);
	}

	vec3 operator -(const vec3& vec)
	{
		return vec3(vec.x - x, vec.y - y, vec.z - z);
	}

	vec3  operator +=(const vec3& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		this->z += vec.z;

		return *this;
	}

	vec3  operator -=(const vec3& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;

		return *this;
	}

	bool operator ==(const vec3& vec)
	{
		return (x == vec.x && y == vec.y && z == vec.z); 
	}

};





#endif //_VEC·_H__