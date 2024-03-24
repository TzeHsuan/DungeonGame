#ifndef _NPC_h_
#define _NPC_h_
#include "Character.h"
#include "Player.h"
#include "Item.h"

#include <iostream>
#include <vector>

using namespace std;

class NPC : public Character{
public:
	NPC();
	NPC(string, char); //trainer
	NPC(string, char, vector<Item*> i);  //seller
	void dialogue(); //trainer's
	void printCommodity();
	void checkItemStatus();
	
	bool triggerEvent(Object* o) override;
	
	void setCommodity(vector<Item*>);
	vector<Item*> getCommodity();
	
	bool visited=0;
	
private:
	vector<Item*> commodity;
};

#endif