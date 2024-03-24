#include "Item.h"

Item::Item(){}

Item::Item(string name, char tag, int hp, int attack, int defense, int price){
	setName(name);
	setTag(tag);
	setHp(hp);
	setAttack(attack);
	setDefense(defense);
	setPrice(price);
	used=0;
}

bool Item::triggerEvent(Object *o){
	int option;
	cout<<"__________________________________________________________\n";
	cout<<"|You see something lying on the foor. Want to pick it up?|\n";
	cout<<"----------------------------------------------------------\n";
	cout<<">>1. Pick it up\n";
	cout<<">>2. No, I'm scared\n";
	do{
		cout<<"I think I will...";
		cin>>option;
		if (option==1) {
			cout<<endl<<"You found a water gun !"<<endl;
		}else if(option==2){
			cout<<endl<<"Are you sure? You will regret."<<endl;
		}
	}while(option!=1);
	cout<<"Water gun equipped"<<endl;
	used=1;
	return 1; 
}

void Item::setHp(int hp){
	this-> hp=hp;
}

void Item::setAttack(int attack){
	this-> attack=attack;
}

void Item::setDefense(int defense){
	this-> defense=defense;
}

void Item::setPrice(int price){
	this-> price=price;
}

void Item::setTag(char tag){
	this-> tag=tag;
}

int Item::getHp(){
	return hp;
}

int Item::getAttack(){
	return attack;
}

int Item::getDefense(){
	return defense;
}

int Item::getPrice(){
	return price;
}

char Item::getTag(){
	return tag;
}