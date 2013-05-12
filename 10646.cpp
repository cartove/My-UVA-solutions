#include <string>
#include <iostream>
#include <stdio.h>
#include <istream>
#include <ostream>
#include <deque>
#include <algorithm>
using namespace std;

enum Suit {CLUB,DIAMOND,HEART,SPADE,SUIT_COUNT};
enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
            EIGHT, NINE, TEN, JACK, QUEEN, KING, RANK_COUNT
          };
class Card {
    friend std::istream &operator>>(std::istream &, Card &);

public:
    Card();
    Card(Suit, Rank);
    Suit suit_;
    Rank rank_;
    int val_;
};
Card::Card() {
    suit_=SUIT_COUNT;
    rank_=RANK_COUNT;
    val_=0;
}
Card::Card(Suit s, Rank r) {
    suit_ = s;
    rank_ = r;
    if(rank_ >= NINE && rank_ <= 2)
        val_=rank_;
    else val_=10;
}

bool operator==(const Card &a, const Card &b) {
    return a.suit_ == b.suit_ && a.rank_ == b.rank_;
}

ostream &operator<<(ostream &out, const Card &c) {
    string suits[SUIT_COUNT] = {"C", "D", "H", "S"};
    string ranks[RANK_COUNT] = {"A", "2", "3", "4", "5", "6",
                                "7", "8", "9", "T", "J", "Q", "K"
                               };
    out << ranks[c.rank_] << suits[c.suit_];
    return out;
}

istream &operator>>(istream &in, Card &c) {
    string suits = "CDHS", ranks = "A23456789TJQK";
    string str;
    in >> str;
    c.rank_ = (Rank)ranks.find( str.at(0) );
    c.suit_ = (Suit)suits.find( str.at(1) );
    return in;
}

int main() {

    int cases;
    register int y,x=0,revcases=0;
    std::deque <Card> mycards;
    std::deque <Card> myhand;
    Card temp;
    scanf("%d",&cases);
    while(cases--) {
            x=0,y=0;
        for(int i=0; i<27; ++i) {
            cin>>temp;
            mycards.push_back(temp);
        }
        for(int i=0; i<25; ++i) {
            cin>>temp;
            myhand.push_back(temp);
        }
        for(int i=0; i<3; ++i){
        x=mycards.front().val_;
        y+=x;
        for(int j=0; j<9; ++j)
        mycards.pop_front();
        }
        cout<<"Case "<<++revcases<<": "<<myhand[5-y]<<endl;//never ask why the 5-y cuz i don't know it just works!
        mycards.clear();
        myhand.clear();
    }
    return 0;
}

