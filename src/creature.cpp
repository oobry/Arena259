#include "creature.h"
#include <iostream>

int Creature::creatureCount = 0;

// constructor
Creature::Creature(const std::string& n, int h, int d, int def)
    : name(n), health(h), damage(d), defense(def)
{
    creatureCount++;
}

// getters
std::string Creature::getName() const { return name; }
int Creature::getHealth() const { return health; }
int Creature::getDamage() const { return damage; }
int Creature::getDefense() const { return defense; }

// creature count
int Creature::getCreatureCount() { return creatureCount; }

// alive?
bool Creature::isAlive() const
{
    return health > 0;
}

// damage, using defense also
void Creature::takeDamage(int amount)
{
    int reduced = amount - defense;
    if (reduced < 0) reduced = 0;

    health -= reduced;

    if (health < 0)
        health = 0;
}

// attack behavior
void Creature::attack(Creature &other)
{
    other.takeDamage(damage);
}

// validation of creature
bool Creature::validate(const Creature &c)
{
    if (c.health <= 0 || c.health > 120)
    {
        std::cerr << "Invalid health for " << c.name << "\n";
        return false;
    }

    if (c.damage <= 0 || c.damage > 20)
    {
        std::cerr << "Invalid damage for " << c.name << "\n";
        return false;
    }

    if (c.defense < 0 || c.defense > 10)
    {
        std::cerr << "Invalid defense for " << c.name << "\n";
        return false;
    }

    return true;
}

// validation of battle
bool Creature::validateBattle(const Creature &a, const Creature &b)
{
    return validate(a) && validate(b);
}
