#ifndef _Room_h_
#define _Room_h_

#include "Object.h"
#include "Character.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room{
public:
	Room();
	Room(int, bool, vector<Object*>);

	void setIndex(int);
	void setExit(bool);
	void setEvents(vector<Object*>);
	int getIndex();
	bool getExit();
	vector<Object*> getEvents();
		
	Room* n_Room;
	Room* s_Room;
	Room* e_Room;
	Room* w_Room;
	int n;
	int s;
	int e;
	int w;
		
private:
	int index;
	bool exit;
	vector<Object*> events;
};

#endif