#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>

#include "Item.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Dungeon.h"

using namespace std;

int main() {
	Dungeon d;
	d.runDungeon();
	return 0;
}