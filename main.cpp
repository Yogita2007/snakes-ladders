#include <bits/stdc++.h>

using namespace std;

class Board {
    private int size;
    map<pair<int,int>, pair<int,int>> snakesAndLadders;

    public Board(int size) {
        this.size = size;
    }

    public void addSnakeOrLadder(pair<int,int> start, pair<int,int> end) {
        if(isValid(start) && isValid(end)) {
            if(snakesAndLadders.find(start) == snakesAndLadders.end()) {
                snakesAndLadders[start] = end;
            }
            else {
                cout<<"An object already exists in this location !!"<<endl;
            }
        }
        else {
            cout<<"Invalid object coordinates !!"<<endl;
        }
    }

    private bool isValid(pair<int,int> pos) {
        return (pos.first < 0 || pos.second < 0 || pos.first >= this.size || pos.second >= this.size);
    }
}

class Dice {
    private int size;

    public Dice(int size) {
        this.size = size;
    }

    public int roll() {
        int max = this.size;
        int min = 1;

        return  rand() % (max - min + 1) + min;
    }
}

class Player {
    private pair<int,int> position;

    public Player() {
        this.position = make_pair(0,0);
    }

    public pair<int,int> getPosition() {
        return this.position;
    }
}

