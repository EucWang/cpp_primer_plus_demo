#ifndef PAIRS_H_
#define PAIRS_H_

// #include <iostream>
// #include <string>

template <class T1, class T2>
class Pair{
    private:
        T1 a;
        T2 b;
    public:
        Pair(const T1 & aval, const T2 &bval): a(aval), b(bval){}
        T1 & first(){return a;};
        T2 & second(){return b;};
        T1 first() const { return a;};
        T2 second() const {return b;};
};

#endif

// template <class T1, class T2>
// T1 & Pair<T1, T2>::first() {
//     return a;
// }

// template <class T1, class T2>
// T2 & Pair<T1, T2>::second() {
//     return b;
// }

//------------------------------------------------

// using std::cout;
// using std::endl;
// using std::string;

// int main(){
//     Pair<string, int> ratings[4] = {
//         Pair<string, int>("The Purpled Duck", 5),
//         Pair<string, int>("Jaquie's Frisco AI Fresco", 4),
//         Pair<string, int>("Cafe Sourffle", 5),
//         Pair<string, int>("Bertie's Eats", 3)};

//     int joints = sizeof(ratings) /sizeof(Pair<string, int>);
//     cout << "Rating:\tRatery\n";
//     for(int i=0; i<joints; i++) {
//         cout << ratings[i].second() << ", \t"
//             << ratings[i].first() << endl;
//     }

//     cout << "Ooops! Revised rating:\n";
//     ratings[3].first() = "Bertie's Fab Eats";
//     ratings[3].second() = 6;

//     cout << ratings[3].second() << ":\t"
//         << ratings[3].first() << endl;

//     return 0;
// }