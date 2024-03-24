#ifndef _Monster_h_
#define _Monster_h_

#include "Character.h"
#include "Player.h"

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

class Monster : public Character{
public:
	Monster();
	Monster(string, char, string, int, int, int ,int, int);
	void description();
	
	bool triggerEvent(Object* o) override;
	
	void setType(string);
	string getType();
	
	bool attackedDragon=0;
	
private:
	string type; 
};

#endif