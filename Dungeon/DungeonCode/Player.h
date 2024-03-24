#ifndef _Player_h_
#define _Player_h_

#include "Character.h"
#include "Room.h"
#include "Item.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player : public Character{
public:
	Player();
	Player(string, char, int, int, int, int);
	bool triggerEvent(Object*);
	void addItem(Item*);
	void removeItem(int);
	void increaseStates(Item* choice);
	void changeRoom(Room*);
	
	void setCurrentRoom(Room*);
	void setPreviousRoom(Room*);
	void setInventory(vector<Item*>);
	void setPlayerName(string);
	void setTag(char);
	Room* getCurrentRoom();
	Room* getPreviousRoom();
	vector<Item*> getInventory();
	string getPlayerName();
	char getTag();
	
private:
	Room* currentRoom;
	Room* previousRoom;
	vector<Item*> inventory;
	string playerName;
	char tag;
};

#endif