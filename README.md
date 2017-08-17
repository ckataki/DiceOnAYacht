## Dice on a Yacht game!
This game is played with five eight-sided dice.
> Input: Category indicator, and array of the five die values

> Output: Score for that category

### Scoring categories:
* *Ones, Twos, Threes, Fours, Fives, Sixes, Sevens, Eights:* Sum of all dice that match the title of the category.  For example {4,4,4,4,5} scores 16 for fours.
* *ThreeOfAKind:* Sum of all dice if there are at least three dice that are the same, otherwise zero. For example {1,1,1,2,8} scores 13.
* *FourOfAKind:* Sum of all dice if there are at least four dice that are the same, otherwise zero. For example {1,1,1,1,8} scores 12.
* *FullHouse:* If there are three of one kind and two of another score 25, otherwise score zero. For example {1,1,1,8,8} scores 25.
* *SmallStraight:* If there are four dice in sequence score 30, otherwise zero. For example {1,2,3,4,7} scores 30.
* *LargeStraight:* If all five dice fall in sequence score 40, otherwise zero.  For example {3,4,5,6,7} scores 40.
* *AllDifferent:* If all five dice have unique values score 40, otherwise zero.  For example {1,2,4,6,8} scores 40.
* *Chance:* Sum of all dice. For example {1,2,1,8,8} scores 20.
* *AllSame:* If all five dice have the same value score 50, otherwise zero.  For example {1,1,1,1,1} scores 50.

### Code:
- DiceGameMain.cpp (main program driver)
- DiceOnAYacht.cpp (Game logic class, with functions)
- DiceOnAYacht.hpp (Header file for the game class)

> Implemented all categories (except FullHouse)
>> `int getScore(vector<int>, Category)` takes a game category and die rolls to give the score

>> `int getScoreAll(vector<int>)` takes only the die rolls and iterates through all categories

### Compilation:
Use gcc (version 5.4 or higher); C++11 standard.

### Execution:
To run the program, simply run the binary. The instructions will show up:

* It'll first ask for the 5 die roll values
* Then it'll show you the game categories, and ask you to pick one.
* Finally it'll show the score.
