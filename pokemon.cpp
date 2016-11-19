#include "pokemon.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Fire::Fire(int index) : Pokemon(index){
	maxHP+=1; speed+=2;
	attack+=2; defense-=2;
	specialAttack+=4; specialDefense+=1;
	weaknesses.push_back(element::water);
}

Water::Water(int index) : Pokemon(index){
	maxHP+=2; speed-=1;
	attack-=2; defense+=2;
	specialAttack-=4; specialDefense-=1;
	weaknesses.push_back(element::grass);
	virtual int attack1(Pokemon* PokePointer)
	{
		cout<<this->name<<" used Bubble."<<PokePointer->Entry.name<<" took "<<PokePointer->take_damage(2, list<element> (water))<<" Damage.";//Bubble
	}
}

Squirtle::Squirtle() : Water(7)
{
	virtual int attack2(Pokemon* PokePointer)
	{
		cout<<this->name<<" used Tackle."<<PokePointer->Entry.name<<" took "<<PokePointer->take_damage(2, list<element> (normal))<<" Damage.";//Tackle
	}
} 
Wartortle::Wartortle() : Water(8)
{
	virtual int attack2(Pokemon* PokePointer)
	{
		cout<<this->name<<" used Surf."<<PokePointer->Entry.name<<" took "<<PokePointer->take_damage(4, list<element> (water))<<" Damage.";//Surf
	}
} 
Blastoise::Blastoise() : Water(9)
{
	virtual int attack1(Pokemon* PokePointer)
	{
		cout<<this->name<<" used Water Pledge."<<PokePointer->Entry.name<<" took "<<PokePointer->take_damage(8, list<element> (water,dragon))<<" Damage.";//Water Pledge
	}
		virtual int attack2(Pokemon* PokePointer)
	{
		cout<<this->name<<" used Hydro Cannon."<<PokePointer->Entry.name<<" took "<<PokePointer->take_damage(6, list<element> (water))<<" Damage.";//Hydro Cannon
	}
} 

Grass::Grass(int index) : Pokemon(index){
	maxHP-=3; speed-=2;
	attack-=2; defense+=0;
	specialAttack-=3; specialDefense+=0;
	weaknesses.push_back(element::fire);
}

int Pokemon::take_damage(int damageAmount, std::list<element> damageTypes) {
	int weaknessCount = 0;
	for(auto wIt = weaknesses.begin(); wIt != weaknesses.end(); wIt++)
		for(auto dIt = damageTypes.begin(); dIt != damageTypes.end(); dIt++)
			if(*dIt == *wIt) weaknessCount++;

	damageAmount = damageAmount * (log(5 * weaknessCount + 5) / log(5));
	currentHP -= damageAmount;
	return damageAmount;
};

Pokemon *make_pokemon(int index) {

	Pokemon *newPokemon;
	switch(index)
	{
		case 7: newPokemon=new Squirtle;
		case 8: newPokemon=new Wartortle;
		case 9: newPokemon=new Blastoise;
	}
	return newPokemon;

}

void Pokemon::write()
{
	string fileName = this->ID + ".dat";
	ofstream myFile;
	myFile.open(fileName.c_str());
	myFile << this;
	myFile.close();	
}
