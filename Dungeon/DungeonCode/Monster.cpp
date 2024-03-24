#include "Monster.h"

Monster::Monster() :Character(){}

Monster::Monster(string name, char tag, string type, int maxHp, int currentHp, int attack, int defense, int money){
	setName(name);
	setTag(tag);
	setType(type);
	setMaxHp(maxHp);
	setCurrentHp(currentHp);
	setAttack(attack);
	setDefense(defense);
	setMoney(money);
}

void Monster::description(){
	cout<<endl;
	cout<<"Name: "<<getName()<<endl;
	cout<<"Type: "<<getType()<<endl;
	cout<<"HP: "<<getCurrentHp()<<"/"<<getMaxHp()<<endl;
	cout<<"Attack: "<<getAttack()<<endl;
	cout<<"Defense: "<<getDefense()<<endl;
}

bool Monster::triggerEvent(Object *o){
	Player* player=dynamic_cast<Player*>(o); 
	int option;
	cout<<endl<<"You entered a "<< getName()<<"'s room.\n";
	cout<<"____________________________\n";
	cout<<"|What would you like to do?|\n";
	cout<<"----------------------------\n";
	cout<<">>1. Observe the monster.\n";
	cout<<">>2. Check my status\n";
	cout<<">>3. Attack !\n";
	cout<<">>4. Retreat to previous room !\n";
retry:
	cout<<"I think I will... ";
	cin>>option;
	if(option==1){
		description();
	}else if(option==2){
		player->triggerEvent(player);
	}else if(option==3){
		int round=1;
		//攻擊模式
		while(getCurrentHp()>0 && player->getCurrentHp()>0){
			int pdamage, mdamage;
			if(getTag()=='d'){
				mdamage= (pow(player->getAttack()+25, 2)) / getDefense();
			}else{
				mdamage= (pow(player->getAttack(), 2)) / getDefense();
			}
			pdamage= (pow(getAttack(),2)) / player->getDefense();
			

			cout<<endl<<"--------------------Round "<<round<<"--------------------"<<endl;
			//Player attack monster
			if(getTag()=='d'){
				cout<<"Launching water attack! ";
			}
			cout<<"You attacked the "<<getName()<<", causing "<<mdamage<<" damage !\n";
			setCurrentHp(attacked(getCurrentHp(), mdamage));
			cout<<getName()<<"'s current HP: "<<getCurrentHp()<<endl;
			if(getCurrentHp()>0){
				//Monster attack player
				cout<<getName()<<" attacked you back, causing "<<pdamage<<" damage !\n";
				player->setCurrentHp(attacked(player->getCurrentHp(), pdamage));
				cout<<"Your current HP: "<<player->getCurrentHp()<<endl;
			}else{
				break;
			}
			round=round+1;
		}
		//打鬥結果成功 + 掉金幣
		if(getCurrentHp()<0){
			cout<<endl<<"Oh yay ! You successfully defeated the "<<getName()<<endl;
			if(getName()!="Dragon"){
				cout<<"________________________________________________________________\n";
				cout<<"|The "<<getName()<< " has dropped some coins. You want to pick it up?"<<setw(6)<<"|\n";
				cout<<"----------------------------------------------------------------\n";
				cout<<">>1. Of course !\n";
				cout<<">>2. I don't feel like picking it up.\n";
				int option;
			retry2:
				cout<<"I think I will...";
				cin>>option;
				if(option==1){
					cout<<endl<<"You picked up 50 coins.\n";
					player->setMoney(player->getMoney() + getMoney());
					cout<<"Your attack and defense has increased by 25.\n"<<"Your HP has recovered and Max HP has increased by 50.\n";
					player->setMaxHp(player->getMaxHp()+50);
					player->setCurrentHp(player->getMaxHp());
					player->setAttack(player->getAttack()+25);
					player->setDefense(player->getDefense()+25);
				}else if (option==2){
					cout<<endl<<"Bad choice. No regrets!\n";
					cout<<"But good news is that your attack and defense has increased by 25.\n"<<"Your HP has recovered and Max HP has increased by 50.\n";
					player->setMaxHp(player->getMaxHp()+50);
					player->setCurrentHp(player->getMaxHp());
					player->setAttack(player->getAttack()+25);
					player->setDefense(player->getDefense()+25);
				}else{
					goto retry2;
				}
			}
		}
		//打鬥結果失敗 掰掰
		if(player->getCurrentHp()<0){
			cout<<endl<<"Sorry,"<<player->getPlayerName()<<"you are dead. Better luck next time.\n";
			return 0;
		}
		//打敗終極BOSS
		if(getTag()=='d' && getCurrentHp()<0){
			attackedDragon=1;
		}
		
	}else if (option==4){
		player->changeRoom(player->getPreviousRoom());
		cout<<"You are now back to Room"<<player->getCurrentRoom()->getIndex()<<endl;
	}else{
		goto retry;
	}
	return 1;
}

void Monster::setType(string type){
	this -> type = type;
}

string Monster::getType(){
	return type;
}