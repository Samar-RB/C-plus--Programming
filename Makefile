all: Decks_game

Decks_game: main.o Deck.o Card.o Character.o Enemies.o Sorcerer.o Troll.o Ranger.o Fighter.o Ghost.o Dragon.o Vector.o
	g++ -Wall -g -o Decks_game main.o Deck.o Card.o Character.o Enemies.o Sorcerer.o Troll.o Ranger.o Fighter.o Ghost.o Dragon.o Vector.o
Deck.o: Deck.cpp
	g++ -Wall -g -c Deck.cpp
Character.o: Character.cpp
	g++ -Wall -g -c Character.cpp
Enemies.o: Enemies.cpp
	g++ -Wall -g -c Enemies.cpp
Troll.o: Troll.cpp
	g++ -Wall -g -c Troll.cpp
Sorcerer.o: Sorcerer.cpp
	g++ -Wall -g -c Sorcerer.cpp
Ranger.o: Ranger.cpp
	g++ -Wall -g -c Ranger.cpp
Fighter.o: Fighter.cpp
	g++ -Wall -g -c Fighter.cpp
Ghost.o: Ghost.cpp
	g++ -Wall -g -c Ghost.cpp
Dragon.o: Dragon.cpp
	g++ -Wall -g -c Dragon.cpp
Card.o: Card.cpp
	g++ -Wall -g -c Card.cpp
Vector.o: Vector.cpp
	g++ -Wall -g -c Vector.cpp
main.o: main.cpp
	g++ -Wall -g -c main.cpp

clean:
	rm *.o Decks_game
