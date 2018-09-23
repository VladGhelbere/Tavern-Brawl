#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>
using namespace std;

class entity
{
    public:
        string name;
        string nickname;
        int health;
        int stamina;
        int damage;
        entity(string a, int b, int c, int d);
        entity(string a, string b, int c, int d);
        string getName();
        void seeStats();
        void seeEnemy();
        void setHealth(int h);
        void setStamina(int s);
};

#endif // ENTITY_H
