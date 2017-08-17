#include "DiceOnAYacht.hpp"


DiceGame::DiceGame() {
    ;
};

DiceGame::~DiceGame() {
    ;
};

int DiceGame::getScore(const vector<int>& rolls, const Category& gameType) {



    switch (gameType) {
        case ONES:
        case TWOS:
        case THREES:
        case FOURS:
        case FIVES:
        case SIXES:
        case SEVENS:
        case EIGHTS:
            return getScoreDigits(rolls, gameType);
        case THREEOFAKIND:
            return getScoreThreeOfAKind(rolls);
        case FOUROFAKIND:
            return getScoreFourOfAKind(rolls);
        case SMALLSTRAIGHT:
            return getScoreSmallStraight(rolls);
        case LARGESTRAIGHT:
            return getScoreLargeStraight(rolls);
        case ALLDIFFERENT:
            return getScoreAllDifferent(rolls);
        case ALLSAME:
            return getScoreAllSame(rolls);
        case CHANCE:
            return getScoreChance(rolls);
        default:
            // Code should never reach here!
            cout << "Error" << endl;
    }

    return 0;
};


int DiceGame::getScoreThreeOfAKind(const vector<int>& rolls) {
    unordered_map<int,int> freq;
    for (auto i = 0; i < rolls.size(); ++i) {
        if (freq.count(rolls[i]) > 0) {
            freq[rolls[i]] += 1;
        }
        else {
            freq[rolls[i]] = 1;
        }
    }

    if (freq.size() > 3) {
        return 0;
    }
    else {
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            if (it->second >= 3) {
                return accumulate(rolls.cbegin(), rolls.cend(), 0);
            }
        }
    }
    return 0;
};


int DiceGame::getScoreFourOfAKind(const vector<int>& rolls) {
    unordered_map<int,int> freq;
    for (auto i = 0; i < rolls.size(); ++i) {
        if (freq.count(rolls[i]) > 0) {
            freq[rolls[i]] += 1;
        }
        else {
            freq[rolls[i]] = 1;
        }
    }

    if (freq.size() > 2) {
        return 0;
    }
    else {
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            if (it->second >= 4) {
                return accumulate(rolls.cbegin(), rolls.cend(), 0);
            }
        }
    }
    return 0;
};


int DiceGame::getScoreChance(const vector<int>& rolls) {
    int sum = 0;
    for (auto i = 0; i < rolls.size(); ++i) {
        sum += rolls[i];
    }
    return sum;
};


int DiceGame::getScoreSmallStraight(const vector<int>& rolls) {
    int strikes = 0;
    int temp = rolls[0];
    for (auto i = 1; i < rolls.size(); ++i) {
        if ((rolls[i] - temp) != 1) {
            ++strikes;
        }
        else {
            temp = rolls[i];
        }
        if (strikes > 1) {
            return 0;
        }
    }
    return ((rolls.size()-2) * 10);
};


int DiceGame::getScoreLargeStraight(const vector<int>& rolls) {
    int temp = rolls[0];
    for (auto i = 1; i < rolls.size(); ++i) {
        if ((rolls[i] - temp) != 1) {
            return 0;
        }
        else {
            temp = rolls[i];
        }
    }
    return ((rolls.size()-1) * 10);
};


int DiceGame::getScoreAllDifferent(const vector<int>& rolls) {
    unordered_set<int> nums;
    for (auto i = 0; i < rolls.size(); ++i) {
        if (nums.count(rolls[i]) > 0) {
            return 0;
        }
        else {
            nums.insert(rolls[i]);
        }
    }
    return ((rolls.size()-1) * 10);
};


int DiceGame::getScoreAllSame(const vector<int>& rolls) {
    int num = rolls[0];
    for (auto i = 1; i < rolls.size(); ++i) {
        if (rolls[i] != num) {
            return 0;
        }
    }
    return (rolls.size() * 10);
};


int DiceGame::getScoreDigits(const vector<int>& rolls, const Category& gameType) {
    int count = 0;
    for (auto i = 0; i < rolls.size(); ++i) {
        if (rolls[i] == gameType) {
            ++count;
        }
    }
    return (gameType*count);
};



int DiceGame::getScoreAll(const vector<int>& rolls) {
    int max_score = 0;
    Category best = CHANCE;
    for (auto i = 1; i != CHANCE; ++i) {
        int temp = getScore(rolls, Category(i));
        if (temp > max_score) {
            max_score = temp;
            best = Category(i);
        }
    }
    cout << "Best category: " << best << endl;
    return max_score;
};
