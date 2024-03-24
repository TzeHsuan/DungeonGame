#include "Object.h"

Object::Object(){}

Object::Object(string name, char tag){
	setName(name);
	setTag(tag);
}

void Object::setName(string name){
	this -> name = name;
}

void Object::setTag(char tag){
	this -> tag = tag;
}

void Object::setMoney(int money){
	this -> money = money;
}

string Object :: getName(){
	return name;
}

char Object :: getTag(){
	return tag;
}

int Object :: getMoney(){
	return money;
}