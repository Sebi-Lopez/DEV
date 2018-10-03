#ifndef STRING_H
#define STRING_H
#include <string.h>
#include <assert.h>
class String {

private: 
	char* string = nullptr;
	unsigned int allocated_memory = 0u; 


public: 

	String() {}
	String(const char* string)
	{
		assert(string != nullptr);
		if (string != nullptr) 
		{
			allocated_memory = strlen(string) + 1;
			this->string = new char[allocated_memory];
			strcpy_s(this->string, allocated_memory, string);
		}
	}

	String(const String& chain)
	{
		assert(chain.string != nullptr);
		if (chain.string != nullptr)
		{
			allocated_memory = chain.allocated_memory;
			this->string = new char[allocated_memory];
			strcpy_s(this->string, allocated_memory, chain.string); 
		}
	}

	String operator=(const char* chain)
	{
		// Si el tamany de chain es mes petit o igual al que tenim no cal fer un new. 
		if (strlen(chain) + 1 <= this->allocated_memory)
		{
			allocated_memory = strlen(chain) + 1; 
			strcpy_s(string, allocated_memory, chain);
		}
	}

	String operator=(const String& chain)
	{
		return String(chain.string);
	}
	
	void GetChar() 
	{
		
	}

	~String() 
	{
		if (string != nullptr)
		{
			delete[] string;
			string = nullptr; 
			allocated_memory = 0u;
		}
	}
};


#endif
