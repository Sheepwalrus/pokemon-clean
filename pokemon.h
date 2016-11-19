#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <cmath>
#include <list>
#include <string>

enum class element {
    fire = 0, water = 1, grass = 2, normal = 3, dragon = 4
};


class Pokemon {
private:
	std::string name;
	int level = 1;
	int ID;
	PokeEntry Entry;
protected:
	int maxHP = 20;
	int currentHP = maxHP;
	int speed = 10;
	int attack = 10;
	int defense = 10;
	int specialAttack = 10;
	int specialDefense = 10;
public:
	Pokemon(int i) {}
	~Pokemon() {}
	std::string get_name() {
		return name;
	}
	int get_level() {
		return level;
	}
	int get_maxHP() {
		return maxHP;
	}
	int get_currentHP() {
		return currentHP;
	}

	int take_damage(int damageAmount, std::list<element> damageTypes);
	string get_species()
	{
		return this->Entry.name;
	}
	virtual int attack1(Pokemon* PokePointer);
	virtual int attack2(Pokemon* PokePointer);
	friend Pokemon* make_pokemon(int index);
	void write();

ostream& operator<< (ostream &out, Pokemon myPokemon)
{
	out << "<pokemon>" <<endl;
	out << "\t<id> " << myPokemon.ID << " </id>"<<endl;
	out << "\t<name> " << myPokemon.name << " </name>"<<endl;
	out << "\t<attack> " << myPokemon.attack << " </attack>"<<endl;
	out << "\t<defense> " << myPokemon.defense << " </defense>"<<endl;
	out << "\t<entry>"<<endl;
	out << "\t\t<number> " << myPokemon->Entry.number << " </number>"<<endl;
	out << "\t\t<name> " << myPokemon->Entry.name << " </name>"<<endl;
	out << "\t/<entry>"<<endl;
	out << "/<pokemon>" <<endl;
	return out;
}
};

class Fire: public Pokemon {
public:
	Fire(int index);
};

class Water: public Pokemon {
public:
	Water(int index);
};

class Squirtle: public Water 
{
	Squirtle(string nickname="Squirtle")
	{
		Pokemon.name=nickname;
	};	
};

class Wartortle: public Water 
{
	Wartortle(string nickname="Wartortle");	
	{
		Pokemon.name=nickname;
	};
};

class Blastoise: public Water 
{
	Blastoise(string nickname="Blastoise");	
	{
		Pokemon.name=nickname;
	};
};

class Grass: public Pokemon {
public:
	Grass(int index);
};
struct PokeEntry {
	int number;
	char name[20];
	char type[10];
	char description[100];
	PokeEntry() {};
	PokeEntry(int n) {};
};

#endif // POKEMON_H
