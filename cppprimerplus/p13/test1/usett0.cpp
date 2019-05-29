#include <iostream>
#include "tabtenn0.h"
#include "ratedtabtenn0.h"

using namespace std;

/**
 * g++ usett0.cpp tabtenn0.cpp 
 */ 
void test131(){

    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);

    player1.name();
    if(player1.getHasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }

    player2.name();
    if(player2.getHasTable()) {
        cout << ": has a table.\n";
    } else {
        cout << ": hasn't a table.\n";
    }
}

void show(const TableTennisPlayer & rt) {
    using std::cout;
    cout << "[Name : " ;
    rt.name();
    cout << "\t\tTable: " ;
    if(rt.getHasTable()) {
        cout << "yes.]\n";
    } else {
        cout << "no.]\n";
    } 
}

void test132(){
    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);

    // rplayer1.name();
    // if(rplayer1.getHasTable()) {
    //     cout << ": has a table.\n";
    // }else {
    //     cout << ": hasn't a table.\n";
    // }
    show(rplayer1);


    // player1.name();
    // if(player1.getHasTable()) {
    //     cout << ": has a table.\n";
    // }else {
    //     cout << ": hasn't a table.\n";
    // }
    show(player1);

    rplayer1.name();
    cout <<": Rating : " << rplayer1.getRating() << endl;

    RatedPlayer rplayer2(1212, player1);
    cout << "Name : ";
    rplayer2.name();
    cout << "; Rating : " << rplayer2.getRating() << endl;
}

int main290(){

    using std::cout, std::endl;

    // test131();
    test132();
    return 0;
}
