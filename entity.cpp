#include "entity.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

entity::entity(string a, int b, int c, int d)
{
    name=a;
    health=b;
    stamina=c;
    damage=d;
}

entity::entity(string a, string b, int c, int d)
{
    name=a;
    nickname=b;
    health=c;
    damage=d;
}

string entity::getName()
{
    return this->name;
}

void entity::seeStats()
{
    cout<<"Name: "<<this->name<<" || Health: "<<this->health<<" || Stamina: "<<this->stamina<<" || Damage: "<<this->damage<<"\n"<<endl;
}

void entity::seeEnemy()
{
    cout<<"Nickname: "<<this->nickname<<" || Health: "<<this->health<<" || Damage: "<<this->damage<<"\n"<<endl;
}

void entity::setHealth(int h)
{
    this->health=h;
    cout<<this->health;
}

void entity::setStamina(int s)
{
    this->stamina=s;
}
