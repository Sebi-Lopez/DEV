#ifndef STRING_H
#define STRING_H
#include <string.h>
class String {

private: 
	char* ch;
	int size; 


public: 

	String() {
		size = 0; 
	}
	String(char* string){}

	void MakeString(int size, char* string) {
		for (int i = 0; i < size; ++i)
		{
			ch[i] = string[i];
		}
	}

};


#endif
