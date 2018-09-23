#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include "entity.h"
using namespace std;

string rollIntro(); //game starting function
int chooseOpponent(); //choosing a worthy opponent
void chooseWeapon(); // choosing a random weapon function
void fight(entity player, entity enemy); //fighting function
void attack(); //player attack function
void defend(); //player defend function
void rest(entity player); //player rest function
void run(); //player running function
void enemyAttack(entity player, entity enemy); //enemy attack function

int main()
{
    //intro
    string playerName=rollIntro(); //roll intro and get the name of the player
    int opponentChoice=chooseOpponent();
    chooseWeapon();
    ifstream fileObj("Character_Info.txt");
    string weapon;
    int weaponDmg;
    fileObj>>weapon>>weaponDmg;
    fileObj.close();
    cout<<"You grab a "<<weapon<<" because it was the closest weapon to you"<<endl;
    cout<<"The weapon you got deals: "<<weaponDmg<<" damage"<<endl;

    entity player(playerName,100,10,weaponDmg);
    player.seeStats();

    entity goblin("Goblin","Sneaky Joe",75,7);
    entity human("Human","Brave Dave",100,4);
    entity troll("Troll","Ooor the Troll",150,10);

    switch(opponentChoice)
    {
        case 1:
            fight(player, goblin);
            break;
        case 2:
            fight(player, human);
            break;
        case 3:
            fight(player, troll);
            break;
        default:
            cout<<"\n Invalid choice, please choose between 1, 2 or 3 !"<<endl;
    }
}

string rollIntro()
{
    cout<<"\nThis is a story about you, a traveler who stumbles across a tavern full of cutthroats"<<endl;
    cout<<"My name is ";
    string playerName;
    cin>>playerName;
    return playerName;
}

int chooseOpponent()
{
    cout<<"\nYou are casually drinking some ale when you realize, a brawl is brewing..."<<endl;
    cout<<"You make an effort to reach the door but no luck, it already started...\n"<<endl;
    cout<<"Better pick a worthy opponent..."<<endl;
    cout<<"1. A sneaky Goblin"<<endl;
    cout<<"2. A mighty Human"<<endl;
    cout<<"3. A terrifying Troll\n"<<endl;
    int opponentChoice;
    cin>>opponentChoice;
    return opponentChoice;
}

void chooseWeapon()
{
    srand(time(0));
    int itemIndex=rand()%6;

    string itemNames[5]={"sword","hammer","bottle","hatchet","short-bow"};
    int itemDamage[5]={10,8,7,12,5};

    string choosenItemName=itemNames[itemIndex];
    int choosenItemDamage=itemDamage[itemIndex];

    ofstream fileObj("Character_Info.txt");
    fileObj<<choosenItemName<<' '<<choosenItemDamage<<endl;
    fileObj.close();
}

void fight(entity player, entity enemy)
{
    cout<<"You have chosen to fight the "<<enemy.getName()<<endl;
    enemy.seeEnemy();
    cout<<"The fight begins"<<endl;
    bool fighting=true;
    while (fighting)
    {
        player.seeStats();
        cout<<"What do you do ?"<<endl;
        cout<<"1. Attack !"<<endl;
        cout<<"2. Defend !"<<endl;
        cout<<"3. Rest !"<<endl;
        cout<<"4. RUN !"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                //attack();
                enemyAttack(player,enemy);
                break;
            case 2:
                //defend();
                break;
            case 3:
                rest(player);
                break;
            case 4:
                run();
                fighting=false;
                break;
            default:
                cout<<"\n Invalid choice, choose 1, 2, 3 or 4 !"<<endl;
        }
    }
}

void rest(entity player) //does not modify health & stamina in class.
{
    int healthAmount=1+(rand()%5);
    int staminaAmount=1+(rand()%5);
    cout<<"You recovered "<<healthAmount<<" health & "<<staminaAmount<<" stamina !"<<endl;
    int newHealth=player.health+healthAmount;
    int newStamina=player.stamina+staminaAmount;
    player.setHealth(newHealth);
    player.setStamina(newStamina);
    player.seeStats();
}

void run()
{
    cout<<"You leg it like a coward..."<<endl;
    cout<<">>> BAD ENDING <<<"<<endl;
}

void enemyAttack(entity player, entity enemy) ////does not modify health of player in class.
{
    int critChance=1+(rand()%2);
    int newDmg=0;
    if (critChance==1)
    {
        cout<<"It's a critical hit !"<<endl;
        newDmg=enemy.damage*2;
    }
    else
    {
        newDmg=enemy.damage;
    }
    cout<<"The "<<enemy.getName()<<" dealt to you "<<newDmg<<" !"<<endl;
    int newHealth=player.health-newDmg;
    player.setHealth(newHealth);
    player.seeStats();
}
