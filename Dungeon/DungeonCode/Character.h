#ifndef _Character_h_
#define _Character_h_

#include "Object.h"

#include <iostream>
#include <string>


using namespace std;

class Character: public Object{
public:
	Character();
	Character(string, char, int, int, int, int);
	int attacked(int, int); //被攻擊
	bool checkDead(); //確認死亡
	
	bool triggerEvent(Object*) override;
	
	void setMaxHp(int);
	void setCurrentHp(int);
	void setAttack(int);
	void setDefense(int);
	void setMoney(int);
	int getMaxHp();
	int getCurrentHp();
	int getAttack();
	int getDefense();
	int getMoney();
		
private:
	string name;
	int maxHp;
	int currentHp;
	int attack;
	int defense;
	int money;
};

#endif