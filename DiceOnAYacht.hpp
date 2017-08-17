#ifndef DICEONAYACHT_HPP
#define DICEONAYACHT_HPP

#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
using namespace std;

enum Category {ONES=1, TWOS=2, THREES=3, FOURS=4, FIVES=5, SIXES=6, SEVENS=7, EIGHTS=8, THREEOFAKIND, FOUROFAKIND, SMALLSTRAIGHT, LARGESTRAIGHT, ALLDIFFERENT, ALLSAME, CHANCE};


class DiceGame {
    private:
    int getScoreDigits(const vector<int>&, const Category&);
    int getScoreThreeOfAKind(const vector<int>&);
    int getScoreFourOfAKind(const vector<int>&);
    int getScoreChance(const vector<int>&);
    int getScoreSmallStraight(const vector<int>&);
    int getScoreLargeStraight(const vector<int>&);
    int getScoreAllDifferent(const vector<int>&);
    int getScoreAllSame(const vector<int>&);

    public:
    DiceGame();
    ~DiceGame();
    DiceGame (const DiceGame&) = delete;
    DiceGame (DiceGame&&) = delete;
    DiceGame& operator=(const DiceGame&) = delete;
    DiceGame& operator=(DiceGame&&) = delete;
    int getScore(const vector<int>&, const Category&);
    int getScoreAll(const vector<int>&);
};


#endif
