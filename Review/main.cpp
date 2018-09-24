#include <stdio.h>
#include <iostream>
#include "Vec3.h"



int main() {
	
	vec3 <int>vec(50, 30, 450);
	vec3 <int>vec2(50, 30, 500);
	int distance; 

	vec3 <float>vecf(200.5, 300.5, 400.5);
	vecf.normalize(); 

	distance = vec.distance_to(vec2);

	system("pause");
	return 0; 
}


