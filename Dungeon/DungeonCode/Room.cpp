#include "Room.h"

Room::Room(){}

Room::Room(int index, bool exit, vector<Object*> events){
	setIndex(index);
	setExit(exit);
	setEvents(events);
}

void Room::setIndex(int index){
	this -> index=index;
}

void Room::setExit(bool exit){
	this-> exit=exit;
}

void Room::setEvents(vector<Object*> events){
	this-> events=events;
}

int Room::getIndex(){
	return index;
}

bool Room::getExit(){
	return exit;
}

vector<Object*> Room::getEvents(){
	return events;
} 