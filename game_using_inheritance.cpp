#include <iostream>
using namespace std;

class Tool {
protected:
    int strength;
    char type;

public:
    // Constructor
    Tool(int str = 0, char t = ' ') : strength(str), type(t) {}

    // Set strength
    void setStrength(int str) {
        strength = str;
    }

    // Get strength
    int getStrength() const {
        return strength;
    }

    // Get type
    char getType() const {
        return type;
    }

    // Virtual function for fight
    virtual bool fight(Tool& opponent) = 0;
};

class Rock : public Tool {
public:
    // Constructor
    Rock(int str) : Tool(str, 'r') {}

    // Fight function for Rock
    bool fight(Tool& opponent) override {
        int adjustedStrength = strength;

        if (opponent.getType() == 's') {
            adjustedStrength *= 2;  // Rock is stronger against Scissors
        } else if (opponent.getType() == 'p') {
            adjustedStrength /= 2;  // Rock is weaker against Paper
        }

        return adjustedStrength > opponent.getStrength();
    }
};

class Paper : public Tool {
public:
    // Constructor
    Paper(int str) : Tool(str, 'p') {}

    // Fight function for Paper
    bool fight(Tool& opponent) override {
        int adjustedStrength = strength;

        if (opponent.getType() == 'r') {
            adjustedStrength *= 2;  // Paper is stronger against Rock
        } else if (opponent.getType() == 's') {
            adjustedStrength /= 2;  // Paper is weaker against Scissors
        }

        return adjustedStrength > opponent.getStrength();
    }
};

class Scissors : public Tool {
public:
    // Constructor
    Scissors(int str) : Tool(str, 's') {}

    // Fight function for Scissors
    bool fight(Tool& opponent) override {
        int adjustedStrength = strength;

        if (opponent.getType() == 'p') {
            adjustedStrength *= 2;  // Scissors is stronger against Paper
        } else if (opponent.getType() == 'r') {
            adjustedStrength /= 2;  // Scissors is weaker against Rock
        }

        return adjustedStrength > opponent.getStrength();
    }
};

int main() {
    // Test objects
    Scissors s1(5);
    Paper p1(7);
    Rock r1(15);

    // Test fights and output results with if-else statements
    if (s1.fight(p1)) {
        cout << "Scissors wins" << endl;
    } else {
        cout << "Paper wins" << endl;
    }

    if (p1.fight(r1)) {
        cout << "Paper wins" << endl;
    } else {
        cout << "Rock wins" << endl;
    }

    if (r1.fight(s1)) {
        cout << "Rock wins" << endl;
    } else {
        cout << "Scissors wins" << endl;
    }

    return 0;
}