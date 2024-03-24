#include "Dungeon.h"

Dungeon::Dungeon(){}

void Dungeon::createPlayer(){
	cout<<"______________________________\n"<< "|Please enter your user name: |\n" << "------------------------------\n";
	string playerName;
	cout<< "My name is... ";
	cin>>playerName;
	player.setPlayerName(playerName);
	cout<<"Welcome to the Dungeon, "<<player.getPlayerName()<<endl;
	
	//Choose character
	cout<<"_____________________________\n" << "|Please choose a character. | \n" <<"-----------------------------\n" ;
	cout<<">>1. Knight\n" << ">>2. Archer\n"<<">>3. Warrior\n";
	int character;
retry:
	cout<<"My choice is...";
	cin >> character;
	if(character==1){
		Player player(playerName, 'k', 100, 100, 100, 0); 
		cout<<endl<<"A knight is born !\n";
		cout<<"A silver sword is in your hand.\n";
		setPlayer(player);
	}else if(character ==2){
		Player player(playerName, 'a', 85, 85, 85, 0); 
		cout<<endl<<"An archer is born !\n";
		cout<<"A bow is in your hand.\n";
		setPlayer(player);
	}else if(character==3){
		Player player(playerName, 'w', 75, 75, 75, 0); 
		cout<<endl<<"A warrior is born !\n";
		cout<<"A wooden sword is in your hand.\n";
		setPlayer(player);
	}else{
		cout<< "Please input the above options only.\n" ;
		goto retry;
	}
	
	player.setCurrentRoom(&rooms[0]);
	cout<<"Please help us defeat the big boss, Dragon.\n"<<"You are now in Room";
	cout<<player.getCurrentRoom()->getIndex()<<". Explore different rooms in the dungeon to find surprises.\n"<<"You will see the Dragon in the last room, Room7.\n" <<"Good luck!\n";
}

void Dungeon::setPlayer(Player player){
	this -> player=player;
}

Player Dungeon::getPlayer(){
	return player;
}

void Dungeon::createMap(){
	vector<Room> rooms(8);
	int link[8][4]={{1, -1, -1, -1}, {4, 0, 3, 2}, {-1, -1, 1, -1}, {-1, -1, -1, 1}, {6, 1, -1, 5}, {-1, -1, 4, -1}, {7, 4, -1, -1}, {-1, 6, -1, -1}};
	
	//create items
	Item* att=new Item("Attack Training Ticket",'a', 0, 100, 0, 50);
	Item* dtt=new Item("Defense Training Ticket",'d', 0, 0, 100, 50);
	Item* energy=new Item("Energy Drink",'e', 100, 0, 0, 50);
	Item* gun=new Item("Water Gun", 'w', 0, 0, 0,100);
	vector<Item*> commodities={att, dtt, energy};
	//create monsters
	Monster* goblin1=new Monster("Goblin", 'm', "none", 150, 150, 75, 75, 50);
	Monster* goblin2=new Monster("Goblin", 'm', "none", 200, 200, 100, 80, 50);
	Monster* slime=new Monster("Slime", 'm', "water", 400, 400, 80, 200, 50);
	Monster* dragon=new Monster("Dragon", 'd', "fire", 500, 500, 250, 275, 0);
	//create NPC
	NPC* seller=new NPC("Seller", 's', commodities);
	NPC* trainer=new NPC("Trainer", 't');
	
	vector<Object*>none, gob1(1,goblin1), gob2(1,goblin2), sli(1,slime), dra(1,dragon), sel(1,seller), tr(1,trainer), wg(1,gun);
	//create rooms & set index
	for(int i=0; i<8; i++){
		Room* r= new Room;
		r->setIndex(i);
		r->n=link[i][0];
		r->s=link[i][1];
		r->w=link[i][2];
		r->e=link[i][3];
		rooms[i]=*r;
	}
	//set event to room
	rooms[0].setEvents(none);
	rooms[1].setEvents(gob1);
	rooms[2].setEvents(sel);
	rooms[3].setEvents(gob2);
	rooms[4].setEvents(sli);
	rooms[5].setEvents(tr);
	rooms[6].setEvents(wg);
	rooms[7].setEvents(dra);
	//set exit
	for(int i=0; i<8; i++){
		rooms[i].setExit(0);
	}
	//set links
	for(int i=0; i<8; i++){
		if(rooms[i].n >= 0){
			rooms[i].n_Room=&rooms[rooms[i].n];
		}else {
			rooms[i].n_Room=nullptr;
		}
		
		if(rooms[i].s >= 0){
			rooms[i].s_Room=&rooms[rooms[i].s];
		}else {
			rooms[i].s_Room=nullptr;
		}
		
		if(rooms[i].w >= 0){
			rooms[i].w_Room=&rooms[rooms[i].w];
		}else {
			rooms[i].w_Room=nullptr;
		}
		
		if(rooms[i].e >= 0){
			rooms[i].e_Room=&rooms[rooms[i].e];
		}else {
			rooms[i].e_Room=nullptr;
		}
	}
	setRooms(rooms);
}

void Dungeon::setRooms(vector<Room> rooms){
	this-> rooms=rooms;
}

vector<Room> Dungeon::getRooms(){
	return rooms;
}

bool Dungeon::handleMovement(){
	int option;	
	while(1){ //若玩家走到死路就要一直問要去哪
		cout<<"______________________________\n";
		cout<<"|Where would you like to go ?|\n";
		cout<<"------------------------------\n";
		cout<<">>1. Go North\n";
		cout<<">>2. Go South\n";
		cout<<">>3. Go West\n";
		cout<<">>4. Go East\n";
		cout<<">>5. I changed my mind\n";
	retry:
		cout<<"I will... ";
		cin>>option;
		if(option==1){
			if(player.getCurrentRoom()->n_Room==nullptr){
				cout<<endl<<"Apparently you've reached a dead end. Try a different direction.\n";
				continue;
			}else{
				player.changeRoom(&rooms[player.getCurrentRoom()->n]);
				cout<<endl<<"Knock. Knock. (Door Opens)"<<endl<<"You're now in room"<<player.getCurrentRoom()->getIndex()<<endl;
				break;
			}
		}else if(option==2){
			if(player.getCurrentRoom()->s_Room==nullptr){
				cout<<endl<<"Apparently you've reached a dead end. Try a different direction.\n";
				continue;
			}else{
				player.changeRoom(&rooms[player.getCurrentRoom()->s]);
				cout<<endl<<"Knock. Knock. (Door Opens)"<<endl<<"You're now in room"<<player.getCurrentRoom()->getIndex()<<endl;
				break;
			}
		}else if(option==3){
			if(player.getCurrentRoom()->w_Room==nullptr){
				cout<<endl<<"Apparently you've reached a dead end. Try a different direction.\n";
				continue;
			}else{
				player.changeRoom(&rooms[player.getCurrentRoom()->w]);
				cout<<endl<<"Knock. Knock. (Door Opens)"<<endl<<"You're now in room"<<player.getCurrentRoom()->getIndex()<<endl;
				break;
			}
		}else if(option==4){
			if(player.getCurrentRoom()->e_Room==nullptr){
				cout<<endl<<"Apparently you've reached a dead end. Try a different direction.\n";
				continue;
			}else{
				player.changeRoom(&rooms[player.getCurrentRoom()->e]);
				cout<<endl<<"Knock. Knock. (Door Opens)"<<endl<<"You're now in room"<<player.getCurrentRoom()->getIndex()<<endl;
				break;
			}
		}else if(option==5){
			back=1;
			chooseAction(player.getCurrentRoom()->getEvents());
		}else{
			cout<<"Please input the above options only.\n";
			goto retry;
		}
		break;
	}
	return 1;
}

void Dungeon::handleEvent(Object* o){
	Item* item=dynamic_cast<Item*> (o);
	Monster* monster=dynamic_cast<Monster*> (o);
	NPC* npc=dynamic_cast<NPC*> (o);
	if(item){
		if(item->used==1){
			cout<<"You have already picked up the item in the Room.\n";
		}else{
			item->triggerEvent(&player); 
		}
		handleMovement();
	}else if(monster){
		if(monster->getCurrentHp()<=0){
			if(monster->getTag()=='d'){
				rooms[7].setExit(1);
			}else{
				cout<<endl<<"You are now in Room"<<player.getCurrentRoom()->getIndex()<<" and you have killed the monster.\n";
				handleMovement();
			}
		}else{
			monster->triggerEvent(&player);
		}
	}else if(npc){
		npc->triggerEvent(&player);
		handleMovement();
	}else{
		handleMovement();
	}
}

void Dungeon::startGame(){
	bool start;
	cout<<"_______________________________________________________________\n";
	cout<<"|Hello ! Welcome to The Dungeon. Do you accept the challenge ? |" << endl << "|Enter '1' to accept, '0' to decline  (ง’̀-‘́)ง " << setw(19) <<"|\n" <<"---------------------------------------------------------------\n" ;
	cin >> start;
	if(start==0){
		cout<< "Too bad. See you next time.\n" ;
		exit(0);
	}else if(start==1){
		int option;
		cout<<"______________________________________________________________\n";
		cout<<"|Do you want to start new game or continue from previous game?|\n";
		cout<<"--------------------------------------------------------------\n";
		cout<<">>1. Start new game\n";
		cout<<">>2. Load previous game\n";
	retry:
		cout<<"I want to...";
		cin>>option;
		if(option==2){
			createMap(); 
			Record record;
			record.loadFromFile(&player, rooms);
			cout<<endl<<"Welcome Back, "<<player.getName()<<endl;
			cout<<"You are now in Room"<<player.getCurrentRoom()->getIndex()<<endl;
		}else if(option==1){
			createMap();
			createPlayer();
		}else{
			cout<<"Please input the above options only.\n";
			goto retry;
		}
	}
}

void Dungeon::chooseAction(vector<Object*> o){
	if(o.empty() || back==1){
		int option;
		cout<< "____________________________\n";
		cout<<"|Please choose your action.|\n";
		cout<<"----------------------------\n";
		cout<<">>1. Move\n";
		cout<<">>2. Check my status\n";
		cout<<">>3. Save and leave game\n";
	retry:
		cout<<"I want to... ";
		cin>> option;
		if(option==1){
			handleMovement();
			back=0;
		}else if(option==2){
			player.triggerEvent(&player);
		}else if(option==3){
			cout<<"Game record saved.\n";
			cout<<"See you next time,"<<player.getName();
			Record record;
			record.saveToFile(&player, rooms);
			exit(1);
		}else{
			cout<<"Please input the above options only.\n";
			goto retry;
		}
	}else{
		handleEvent(o[0]);
	}
}

bool Dungeon::checkGameLogic(){
	if(player.getCurrentHp()<=0){
		cout<<"Wish to see you again.\n";
		cout<<"--------------------GAME OVER--------------------";
		return 0;
	}else if(rooms[7].getExit()==1){
		cout<<"--------------------GAME OVER--------------------";
		return 0;
	}
	else{
		return 1;
	}
}

void Dungeon::runDungeon(){
	startGame(); //created map and player
	//Choose actions unless dead or win
	player.setCurrentRoom(&rooms[0]);
	while(checkGameLogic()){
		chooseAction(player.getCurrentRoom()->getEvents());
	}
}