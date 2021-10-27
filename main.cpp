#include <bits/stdc++.h>

using namespace std;

class Board {
    private int size;
    public map<pair<int,int>, pair<int,int>> snakesAndLadders;

    public Board(int size) {
        this.size = size;
    }

    public int getSize() {
        return this.size;
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

    public void updatePosition(pair<int,int> newPos) {
        this.position = newPos;
    }
}


class Game {
    private Board board;
    private Dice dice;
    private vector<Player> players;
    private int currentPlayerIndex;

    public Game(Board b=new Board(10), Dice d=new Dice(6), vector<Player> players={new Player(), new Player()}) {
        this.board = board;
        this.dice = dice;
        this.players = players;
        this.currentPlayerIndex = 0;
    }

    private pair<int,int> nextPosition(Player player, int move) {
        pair<int,int> curPos = player.getPosition();
        pair<int,int> finalPos = curPos;
        finalPos.first = (finalPos.first + move)%this.board.getSize();
        finalPos.second += (finalPos.first + move)/this.board.getSize();
        if(this.board.snakesAndLadders.find(finalPos) != this.board.snakesAndLadders.end()) {
            cout<<"Encountered snake/ladder at ("<<finalPos.first<<","<<finalPos.second<<")"<<endl;
            finalPos = this.board.snakesAndLadders[finalPos];
        }

        return finalPos;            
    }

    public void nextMove() {
        int val = this.dice.roll();
        cout<<"Dice roll generated a "<<val<<endl;
        pair<int,int> finalPos = this.nextPosition(this.players[currentPlayerIndex], val);
        pair<int,int> initialPos = this.players[currentPlayerIndex].getPosition();
        this.players[currentPlayerIndex].updatePosition(finalPos);
        currentPlayerIndex = (currentPlayerIndex+1)%this.players.size();
        cout<<"Player "<<currentPlayerIndex<<" moved from ("<<initialPos.first<<","<<initialPos.second<<") to ("<<finalPos.first<<","<<finalPos.second<<")"<<endl; 
    }
}

