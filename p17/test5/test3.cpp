#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int main_p17test3(){

    string filename;
    getline(cin, filename);

    ifstream fin(filename);
    if(!fin.is_open()) {
        cerr << "open file " << filename << " is not exists.\n";
        exit(EXIT_FAILURE);
    }
    // char ch;
    ofstream fout("tmp2.txt");
    // while(fin.read(&ch, 1)){
    //     fout.write(&ch, 1);
    //     fout.flush();
    //     ch = '\0';
    // }

    string content;
    while(getline(fin, content)) {
        fout.write(content.c_str(), content.size());
    }

    cout << "Done!\n";
    return 0;
}