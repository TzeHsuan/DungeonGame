#include "NPC.h"

NPC::NPC() :Character(){}

NPC::NPC(string name, char tag){
	setName(name);
	setTag(tag);
}

NPC::NPC(string name, char tag, vector<Item*> i){
	setName(name);
	setTag(tag);
	setCommodity(i);
}

void NPC::dialogue(){
	int option;
	cout<<endl<<"You see someone standing in the middle of the room.\n";
	cout<<"_______________________________\n";
	cout<<"|Hello. Do you know who am I ?|\n";
	cout<<"-------------------------------\n";
	cout<<">>1. Magician\n";
	cout<<">>2. Trainer\n";
	cout<<">>3. My DS&OOP Teacher\n";
retry:
	cout<<"I think you are... ";
	cin>>option;
	do{
		if(option==1){
			cout<<" : Magic ~~~ But nope ! Guess again.\n";
			goto retry;
		}else if(option==2){
			cout<<" : OMG! That's right ! How did you know that?\n";
			break;
		}else if(option==3){
			cout<<" : Do I look like him? Guess again. But I hope he scores you an A or above for you final grade.\n";
			goto retry;
		}else{
			cout<<"Please input the above options only.\n";
			goto retry;
		}
	}while(option!=2);
}

void NPC::printCommodity(){
	vector<Item*> i=getCommodity();
	Item* item=NULL;
	for(int j=0; j<i.size(); j++){
		item=i[j];
		cout<<">>"<<j+1<<". "<<item->getName()<<" ("<<item->getPrice()<<" coins)\n";
	}
	cout<<">>"<<i.size()+1<<". No thanks.\n";
}

bool NPC::triggerEvent(Object *o){
	Player* player=dynamic_cast<Player*>(o); 
	
	//Trainer
	if(getTag()=='t'){
		if(visited==0){
			dialogue();
			visited=1;
		}
		//用券換attack, defense
		int option;
	ask:
		cout<<"_________________________________________________\n";
		cout<<"|What training sessions would you like to have ?|\n";
		cout<<"-------------------------------------------------\n";
		cout<<">>1. Attack\n";
		cout<<">>2. Defense\n";
		cout<<">>3. No thanks\n";
	retry:
		cout<<"I want to train on...";
		cin>>option;
		
		Item* choice; 
		bool found=0;
		if(option==1){
			for(int i=0; i < player->getInventory().size(); i++){
				if(player->getInventory()[i]->getTag()=='a'){
					choice= player->getInventory()[i];
					found=1;
					cout<<" : Congrats! Your attack has increased by 50 !\n";
					cout<<" : Good luck on your journey !\n";
					choice->used=1;
					player->increaseStates(choice);
					player->removeItem(i);
					break;
				}
			}
			if(found==0){
				cout<<"Sorry, seems like you don't have an Attack Ticket.\n";
				cout<<"You can buy one from the Seller.\n";
			}
		}else if(option==2){
			for(int i=0; i < player->getInventory().size(); i++){
				if(player->getInventory()[i]->getTag()=='d'){
					choice= player->getInventory()[i];
					found=1;
					cout<<" : Congrats! Your defense has increased by 50 !\n";
					cout<<" : Good luck on your journey !\n";
					choice->used=1;
					player->increaseStates(choice);
					player->removeItem(i);
					break;
				}
			}
			if(found==0){
				cout<<"Sorry, seems like you don't have a Defense Ticket.\n";
				cout<<"You can buy one from the Seller.\n";
			}
		}else if (option==3){
			cout<<"Well then see you next time!\n";
		}else{
			cout<<"Please input the above options only.\n";
			goto retry;
		}
		
		cout<<"____________________________________________________\n";
		cout<<"|Do you want to attend any other training sessions?|\n";
		cout<<"----------------------------------------------------\n";
		cout<<">>1. Yes please!\n";
		cout<<">>2. No thanks\n";
		cout<<"I think I will...";
		cin>>option;
		if(option==1){
			goto ask;
		}else if(option==2){
			cout<<"Ok then, see you next time!\n";
		}else{
			cout<<"Please input the above options only.\n";
		}
	}
	
	//Seller
	if(getTag()=='s'){ 
			int option;
			cout<<endl<<"Welcome to a hidden store in the Dungeon.\n";
	buy:
			cout<<"______________________________\n";
			cout<<"|What would you like to buy ?|\n";
			cout<<"------------------------------\n";
			cout<<"You have "<<player->getMoney()<< " coins.\n";
			printCommodity();
			
	retry1:
			cout<<"I want to buy...";
			cin>>option;
			
			if(option == commodity.size()+1){
				cout<<"Ok then. See you next time!\n";
			}else if(option < commodity.size()+1){
				Item* choice = commodity[option-1];
				if(player->getMoney() < choice->getPrice()){
					cout<<" : Oh no, not enough coins. Fight more monsters or find more treasure chests to earn money.\n";
				}else if(choice->sold==1){
					cout<<" : Oh no, the item is sold.\n";
				}else{
					if(choice->getTag()=='e'){ //e for energy drink
						cout<<" : Good choice ! Here you go ! Good luck on your journey.\n";
						//售出, 用過, increase states
						choice->sold=1;
						choice->used=1;
						player->increaseStates(choice);
						player->setMoney( player->getMoney() - choice->getPrice() );
						cout<<"You now have "<< player->getMoney() << " coins\n";
					}else if(choice->getTag()=='a'){ //a for attack ticket
						cout<<" : Good choice ! Here you go ! Good luck on your journey.\n";
						player->setMoney( player->getMoney() - choice->getPrice() );
						cout<<"You now have "<< player->getMoney() << " coins\n";
						//售出, 購入商品到包包 
						choice->sold=1;
						player->addItem(choice);					
					}else if(choice->getTag()=='d'){ //d for defense ticket
						cout<<" : Good choice ! Here you go ! Good luck on your journey.\n";
						player->setMoney( player->getMoney()-choice->getPrice() );
						cout<<"You now have "<< player->getMoney() << " coins\n";
						//售出, 購入商品到包包 
						choice->sold=1;
						player->addItem(choice);					
					}
				}
				
				cout<<"__________________________________\n";
				cout<<"|Do you want to buy another item?|\n";
				cout<<"----------------------------------\n";
				cout<<">>1. Yeah sure!\n"<<">>2. No thanks\n";
				
			retry2:
				cout<<"I think I will...";
				cin>>option;
				if(option==1){
					goto buy;
				}else if(option==2){
					cout<<"Okay then. See you next time!\n";
					//break;
				}else{
					cout<<"Please input the above options only.\n";
					goto retry2;
				}
			}else{
				cout<<"Please input the above options only.\n";
				goto retry1;
			}	
		}
	return 1;
}

void NPC::setCommodity(vector<Item*> i){
	commodity=i;
}

vector<Item*> NPC::getCommodity(){
	return commodity;
}