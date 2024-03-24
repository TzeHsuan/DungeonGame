#ifndef _Item_h_
#define _Item_h_
#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

class Item : public Object { 
public:
	Item();
	Item(string, char, int, int, int, int);
	
	bool triggerEvent(Object* o) override;
	
	void setHp(int);
	void setAttack(int);
	void setDefense(int);
	void setPrice(int);
	void setTag(char);
	int getHp();
	int getAttack();
	int getDefense();
	int getPrice();
	char getTag();
	
	bool used = 0;
	bool sold = 0;
	
private:
	int hp;
	int attack;
	int defense;
	int price;
	char tag;
};

#endif