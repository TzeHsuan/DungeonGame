#ifndef _Object_h_
#define _Object_h_

#include <iostream>
#include <string>

using namespace std;

class Object{
public:
	Object();
	Object(string, char);
	
	virtual bool triggerEvent(Object*) = 0;
	
	void setName(string);
	void setTag(char);
	void setMoney(int);
	string getName();
	char getTag();
	int getMoney();
	
private:
	string name;
	char tag;
	int money;
};

#endif  