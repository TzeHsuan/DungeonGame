#include "Player.h"

Player::Player() :Character(){}

Player::Player(string name, char tag, int currentHp, int attack, int defense, int money) :Character(name, tag, currentHp, attack, defense, money){
	setTag(tag);
	setMaxHp(currentHp);
	setCurrentHp(currentHp);
	setAttack(attack);
	setDefense(defense);
}

bool Player::triggerEvent(Object * o){
	Player* player= dynamic_cast<Player*> (o); 
	cout<<endl<<"Name: "<< getName()<<endl;
	cout<<"Occupation: ";
	if(getTag()=='k'){
		cout<<"Knight\n";
	}else if(getTag()=='a'){
		cout<<"Archer\n";
	}else{
		cout<<"Warrior\n";
	}
	cout<<"Hp: "<< getCurrentHp() << "/"<<getMaxHp()<<endl;
	cout<<"Attack: "<< getAttack()<<endl;
	cout<<"Defense: "<< getDefense()<<endl;
	cout<<"Bag: ";
	if(getInventory().size()){
		for(int i=0; i<getInventory().size(); i++){
			cout<<getInventory()[i]->getName()<<" ";
		}
		cout<<endl;
	}else{
		cout<<"Nothing\n";
	}
	return 1;
}

void Player::addItem(Item* i){
	inventory.push_back(i);
}

void Player::removeItem(int i){
	inventory.erase(inventory.begin()+i);
}

void Player::increaseStates(Item* choice){
	setMaxHp(getMaxHp() + choice->getHp());
	setCurrentHp(getMaxHp());
	setAttack(getAttack() + choice->getAttack());
	setDefense(getDefense() + choice->getDefense());
}

void Player::changeRoom(Room* r){
	previousRoom=currentRoom;
	currentRoom= r;
}

void Player::setCurrentRoom(Room* currentRoom){
	 this->currentRoom=currentRoom;
}

void Player::setPreviousRoom(Room* previousRoom){
	this -> previousRoom=previousRoom;
}

void Player::setInventory(vector<Item*> inventory){
	this -> inventory=inventory;
}

void Player::setPlayerName(string playerName){
	this -> playerName=playerName;
}

void Player::setTag(char tag){
	this -> tag=tag;
}

Room* Player::getCurrentRoom(){
	return currentRoom;
}

Room* Player::getPreviousRoom(){
	return previousRoom;
}

vector<Item*> Player::getInventory(){
	return inventory;
}

string Player::getPlayerName(){
	return playerName;
}

char Player::getTag(){
	return tag;
}