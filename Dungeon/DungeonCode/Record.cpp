#include "Record.h"

Record::Record(){}

void Record::saveToFile(Player* player, vector<Room>& rooms){
	ofstream fplayer("playerRecord.txt");
	ofstream frooms("roomsRecord.txt");
	Record::savePlayer(player, fplayer);
	Record::saveRooms(rooms, frooms);
}

void Record::loadFromFile(Player* player, vector<Room>& rooms){
	ifstream fplayer("playerRecord.txt");
	ifstream frooms("roomsRecord.txt");
	
	string name;
	char tag;
	int currentHp, maxHp, attack, defense, index, money;
	fplayer>>name;
	fplayer>>tag;
	fplayer>>currentHp;
	fplayer>>maxHp;
	fplayer>>attack;
	fplayer>>defense;
	fplayer>>index;
	fplayer>>money;
	
	loadRooms(rooms, frooms);
	player->setName(name);
	player->setTag(tag);
	player->setCurrentHp(currentHp);
	player->setMaxHp(maxHp);
	player->setAttack(attack);
	player->setDefense(defense);
	player->setCurrentRoom(&rooms[index]);
	player->Object::setMoney(money);
}

void Record::savePlayer(Player* player, ofstream& fplayer){
	fplayer<<player->getName()<<endl;
	fplayer<<player->getTag()<<endl;
	fplayer<<player->getCurrentHp()<<endl;
	fplayer<<player->getMaxHp()<<endl;
	fplayer<<player->getAttack()<<endl;
	fplayer<<player->getDefense()<<endl;
	fplayer<<player->getCurrentRoom()->getIndex()<<endl;
	fplayer<<player->getMoney()<<endl;
}

void Record::saveRooms(vector<Room>& rooms, ofstream& frooms){
	Monster* goblin1= dynamic_cast<Monster*> (rooms[1].getEvents()[0]);
	Monster* goblin2= dynamic_cast<Monster*> (rooms[3].getEvents()[0]);
	Monster* slime= dynamic_cast<Monster*> (rooms[4].getEvents()[0]);
	Monster* dragon= dynamic_cast<Monster*> (rooms[7].getEvents()[0]);
	frooms<< goblin1->getCurrentHp()<<endl;
	frooms<< goblin2->getCurrentHp()<<endl;
	frooms<< slime->getCurrentHp()<<endl;
	frooms<< dragon->getCurrentHp()<<endl;
}

void Record::loadPlayer(Player* player, vector<Room>& rooms, ifstream& fplayer){
	string name;
	char tag;
	int currentHp, maxHp, attack, defense, index, money;
	fplayer>>name;
	fplayer>>tag;
	fplayer>>currentHp;
	fplayer>>maxHp;
	fplayer>>attack;
	fplayer>>defense;
	fplayer>>index;
	fplayer>>money;
	
	player->setName(name);
	player->setTag(tag);
	player->setCurrentHp(currentHp);
	player->setMaxHp(maxHp);
	player->setAttack(attack);
	player->setDefense(defense);
	player->setCurrentRoom(&rooms[index]);
	player->setMoney(money);
}

void Record::loadRooms(vector<Room>& rooms, ifstream& frooms){
	int gCurrentHp1, gCurrentHp2, sCurrentHp, dCurrentHp;
	frooms>>gCurrentHp1;
	frooms>>gCurrentHp2;
	frooms>>sCurrentHp;
	frooms>>dCurrentHp;
	
	Monster* goblin1= dynamic_cast<Monster*> (rooms[1].getEvents()[0]);
	Monster* goblin2= dynamic_cast<Monster*> (rooms[3].getEvents()[0]);
	Monster* slime= dynamic_cast<Monster*> (rooms[4].getEvents()[0]);
	Monster* dragon= dynamic_cast<Monster*> (rooms[7].getEvents()[0]);
	goblin1->setCurrentHp(gCurrentHp1);
	goblin2->setCurrentHp(gCurrentHp2);
	slime->setCurrentHp(sCurrentHp);
	dragon->setCurrentHp(dCurrentHp);
}