// Workshop 7
// Name: Citlalli Melody Mastache
// Student #: 126275189
// Course: OOP244 Fall 2018
// File: Hero.h

#ifndef SICT_HERO_H
#define SICT_HERO_H
#define MAX_ROUNDS 100

namespace sict {
    class Hero {
        const char * god[41];
        int life;
        int power;

        public:
        Hero(const char *, int, int);
        bool safe() const;
        void operator-=(int);
        bool isAlive() const;
        int attackStrength() const;
        void operator=(const Hero&);
        const char* getName() const;
        friend std::ostream& operator<<(std::ostream&, const Hero&);
    };
    const Hero& operator*(const Hero&, const Hero&);
}

#endif
