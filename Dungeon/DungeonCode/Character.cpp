#include "Character.h"

Character::Character() :Object() {}

Character::Character(string name, char tag, int currentHp, int attack, int defense, int money) :Object(name, tag){
	setName(name);
	setTag(tag);
	setCurrentHp(currentHp);
	setAttack(attack);
	setDefense(defense);
	setMoney(money);
}

int Character::attacked(int currentHp, int damage){
	currentHp-=damage;
	return currentHp;
}

bool Character::checkDead(){
	if(currentHp<=0){
		cout<<"Sorry. You're dead. \n";
		return 1;
	}
	return 0;
}

bool Character::triggerEvent(Object *o){
	return 1;
}


void Character::setMaxHp(int maxHp){
	this -> maxHp = maxHp;
}

void Character::setCurrentHp(int currentHp){
	this -> currentHp = currentHp;
}

void Character::setAttack(int attack){
	this -> attack = attack;
}

void Character::setDefense(int defense){
	this -> defense = defense;
}

void Character::setMoney(int money){
	this -> money = money;
}

int Character::getMaxHp(){
	return maxHp;
}

int Character::getCurrentHp(){
	return currentHp;
}

int Character::getAttack(){
	return attack;
}

int Character::getDefense(){
	return defense;
}

int Character::getMoney(){
	return money;
}