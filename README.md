# The Dungeon

This is a text-based game I programmed for my OOP course midterm project. By using OOP, its features such as inheritance, polymorphism, and encapsulation helps to make the game more powerful, secure, and allows the functions to be more dynamic at runtime. [Here](https://youtu.be/MegS2KbQG2A?si=k0teE_KX3vkuDz2x) is the link to the demo of my game, which includes the UML design.

## How The Game Works
The aim of this game is to defeat the Dragon in the last room. The game’s flow starts by asking the player to accept the challenge, start a new or old game, and create a character. When the player explores the different rooms, he/she may encounter a monster, where the player can choose to attack, a NPC to talk to and exchange items, and maybe a treasure(item). Each time the player defeats or finishes interacting with the event in the room, the player will be asked what he/she wants to do or where to go. At last, the game will terminate when the player dies, defeats the dragon, or chooses to save the game. When playing the game, if the player chooses the character archer, he/she may be defeated when encountering the first monster, Goblin, in Room1. However, the other 2 characters should work just fine.

## How To Run The Game
Run the main.cpp

## Reflections & Improvements In The Future
Reflecting on my work, considering the fact that this was my first programming project and game, I had tried my very best to make the game run fluently, and I included the requirements of the project. 

Some improvements of my game could be to have multiple weapons for each character and the player can choose to use the desired weapon each time encountering a monster. Other improvements could be to make the game more challenging. For example, the player needs to collect all required items in order to unlock the final room. 

Despite the fact that there are many more improvements that could be made, I gained a huge sense of achievement since I managed to finish this project on time and I actually quite enjoyed writing my very own first game using OOP.


## Discussion
When coding this project, the biggest problem I encountered was setting the current room and changing the rooms. I’d spent hours trying to figure out why the compiler kept on telling me there was a segmentation error. I turned to my friends and they told me to check my declarations of pointers and references again. At last, I found the reason. It was due to my declaration of vector<Room*> instead of vector<Room> in the “createMap” function and I didn’t code this->rooms=rooms. Despite the fact that I found this project quite challenging, I think my programming skills have improved enormously. Through debugging and trying to find out the reasons resulting in the errors, I’ve gained more knowledge about object-oriented programming, inheritance, and virtual functions. Inheritance allowed me to create derived classes and inherit the properties from the parent class, which allowed me to reuse the code. Polymorphism allowed me to create objects that behave differently based on the context they’re used in runtime, and it made the game more dynamic and interactive. Encapsulation allowed the game to be more secure and reliable.

