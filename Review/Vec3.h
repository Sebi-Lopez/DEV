#ifndef _VEC3_H__
#define _VEC3_H__

template <class TYPE>
class vec3 {

private:
	TYPE x, y, z;

public:


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

	vec3 normalize()
	{
		
	}

	vec3 zero()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;

		return (*this); 
	}

	/*void zero()
	{
		x = 0;
		y = 0;
		z = 0;
	}*/


	bool is_zero()
	{
		return (x == 0 && y == 0 && z == 0);
	}


	vec3 distance_to(const vec3& vec)
	{
		vec3 r;
		r.x = vec.x - x;
		r.y = vec.y - y;
		r.z = vec.z - z;

		return r; 
	}

	// OPERATORS
	vec3 operator +(const vec3& vec)
	{
		vec3 r;

		r.x = this->x + vec.x;
		r.y = this->y + vec.y;
		r.z = this->z + vec.z;

		return r;
	}

	vec3 operator -(const vec3& vec)
	{
		vec3 r;

		r.x = this->x - vec.x;
		r.y = this->y - vec.y;
		r.z = this->z - vec.z;

		return r;
	}

	vec3  operator +=(const vec3& vec)
	{
		this->x += vec.x;
		this->y += vec.y;
		this->z += vec.z;

		return (*this);
	}

	vec3  operator -=(const vec3& vec)
	{
		this->x -= vec.x;
		this->y -= vec.y;
		this->z -= vec.z;

		return (*this);
	}

	bool operator ==(const vec3& vec)
	{
		/*if (x == vec.x && y == vec.y && z == vec.z)
			return true;*/

		return (x == vec.x && y == vec.y && z == vec.z); 
	}


};





#endif //_VEC·_H__