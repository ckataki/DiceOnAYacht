#include <vector>
#include <iostream>

#include "DiceOnAYacht.hpp"

/*
 * GAMETYPES:
 * 1: ONES
 * 2: TWOS
 * 3: THREES
 * 4: FOURS
 * 5: FIVES
 * 6: SIXES
 * 7: SEVENS
 * 8: EIGHTS
 * 9: THREEOFAKIND
 * 10: FOUROFAKIND
 * 11: SMALLSTRAIGHT
 * 12: LARGESTRAIGHT
 * 13: ALLDIFFERENT
 * 14: ALLSAME
 * 15: CHANCE
 * Any other value: Give best score
*/

using namespace std;

int main(int argc, char* argv[]) {
    DiceGame game;
    vector<int> rolls(5);
    Category gameType;

    cout << "Enter the five die values: " << endl;
    for (auto i = 0; i < 5; ++i) {
        int temp;
        cin >> temp;
        if (!cin) {
            --i;
            cin.clear();
            cin.ignore();
            cout << "Enter a number between 1 and 8" << endl;
            continue;
        }
        if ((temp < 1) || (temp > 8)) {
            cout << "Enter a number between 1 and 8" << endl;
            --i;
        }
        else {
            rolls[i] = temp;
        }
    }

    cout << "Enter game type: " << endl;
    cout << "Categories: " << endl;
    cout << "1:ONES, 2:TWOS, 3:THREES, 4:FOURS, 5:FIVES, 6:SIXES, 7:SEVENS, 8:EIGHTS" << endl;
    cout << "9:THREEOFAKIND, 10:FOUROFAKIND, 11:SMALLSTRAIGHT, 12:LARGESTRAIGHT, 13:ALLDIFFERENT, 14:ALLSAME, 15:CHANCE, Any other value:Give best score" << endl;
    int temp;
    cin >> temp;
    if (!cin) {
        cin.clear();
        cin.ignore();
        cout << "Not a valid number. Computing best score" << endl;
        temp = 16;
        }
    gameType = Category(temp);

    if ((gameType < 1) || (gameType > 15)) {
        int score = game.getScoreAll(rolls);
        cout << "Best score possible: " << score << endl;
        return 0;
    }
    else {
        int score = game.getScore(rolls, gameType);
        cout << "Score: " << score << endl;
        return 0;
    }

    return 0;
};
