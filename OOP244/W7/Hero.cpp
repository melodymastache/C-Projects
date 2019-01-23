// Workshop 7
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Hero.cpp

#include <iostream>
#include "Hero.h" 

namespace sict {
    // sets safe state
    Hero::Hero(const char * name, int health, int strength) {
        name = '\0';
        health = 0;
        strength = 0;
    }
    bool Hero::safe() const {
        return (god == '\0');
    }
    // deducts health based on attack
    void Hero::operator-=(int attack) {
        if (attack > 0) {
            life -= attack;
        }
        
        if (life < 0) {
            life = 0;
        }
    }
    // tells us whether or not life is 0
    bool Hero::isAlive() const {
        return (life > 0);
    }
    // returns zero if object is empty. otherwise, returns power
    int Hero::attackStrength() const {
        if (safe()) {
            return 0;
        }
        else {
            return power;
        }
    }
    // returns name of hero if there is one
    std::ostream& operator<<(std::ostream& os, const Hero& hero) {
        if (hero.safe()) {
            os << "No hero" << std::endl;
        }
        else {
            os << hero.god;
        }
        return os;
    }
    void Hero::operator=(const Hero& rhs) {
        this->god[40] = rhs.god[40];
        this->life = rhs.life;
        this->power = rhs.power;
    }

    // return name of god
    const char* Hero::getName() const {
        return *this->god;
    }

    // the battle commences
    const Hero& operator*(const Hero& first, const Hero& second) {
        Hero one = first;
        Hero two = second;
        std::cout << "Ancient Battle! " << one << " vs " << two << " : "; 
        int count = 0;
        
        while (one.isAlive() && two.isAlive() && count != MAX_ROUNDS) {
            one -= two.attackStrength();
            two -= one.attackStrength();
            count++;
        }
        
        if (two.isAlive() && !one.isAlive()) {
            std::cout << "winter is " << two.getName() << " in " << count << " rounds." << std::endl;
            return second;
        }
        else {
            std::cout << "Winner is " << one << " in " << count << " rounds." << std::endl;
            return first;
        } 
    }
     /*const Hero& operator*(const Hero& first, const Hero& second) {
        Hero one = first;
        Hero two = second;
        std::cout << "Ancient Battle! " << one << " vs " << two << " : "; 

        for (int i = 0; i <= MAX_ROUNDS; i++) {
            if (one.isAlive() && two.isAlive() && i <= MAX_ROUNDS) {
                one -= two.attackStrength();
                two -= one.attackStrength();
            }
            else if (one.isAlive() && !two.isAlive()) {
                std::cout << "Winner is " << one << " in " << i << " rounds." << std::endl;
                return first;
            }
            else if (two.isAlive() && !one.isAlive()) {
                std::cout << "Winner is " << two << " in " << i << " rounds." << std::endl;
                return second;
            }
            else if (one.isAlive() && two.isAlive()) {
                std::cout << "Winner is " << one << " in " << i << " rounds." << std::endl;
                return first;
            } 
        }
        return first;
    }*/
}
