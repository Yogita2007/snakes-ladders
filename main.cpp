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

