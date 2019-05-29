#include <iostream>
#include <fstream>
#include <memory>
#include "emp2.h"
#include "test.h"

using namespace std;

const int MAX = 10;
const char * file = "employee.txt";

int setData(int index, abstr_emp ** pc);

void readData(int index, abstr_emp ** pc, ifstream &fin);

int main_p17test6(){
    int index = 0;
    abstr_emp * pc[MAX] = {NULL};

    ifstream fin(file, ios_base::in);
    if(fin.is_open()) {
        cout << "open file success.\n";
        readData(index, pc, fin);

        for(int i=0; i< MAX; i++) {
            if(pc[i] != NULL) {
                pc[i]->showAll();
                cout << endl;
            }
        }

    } else {
        fin.clear();
        fin.close();
        //通过键盘输入内容
        index = setData(index, pc);

        cout << "enter " << index << " info. and then save it.";
        ofstream fout(file);
        if(fout.is_open()) {
             for(int i=0; i< index; i++) {
                abstr_emp * t = pc[i];
                t->writeAll(fout);
             }
        }
        fout.close();
        cout << "Done!!!!!\n";
    }


    return 0;
}

void readData(int index, abstr_emp ** pc, ifstream &fin) {
    index = -1;
    int point = 0;
    int type = -1;
    while(true) {
            string tmp;

            if(getline(fin, tmp)){
                if(tmp == "#1") {
                    index++;
                    type = 1;
                    point = 0;
                    pc[index] = new employee();
                } else if (tmp == "#2") {
                    index++;
                    type = 2;
                    point = 0;
                    pc[index] = new manager();
                } else if(tmp == "#3") {
                    index++;
                    type = 3;
                    point = 0;
                    pc[index] = new fink();
                } else if(tmp == "#4") {
                    index++;
                    type = 4;
                    point = 0;
                    pc[index] = new highfink();
                } else {
                    if(point==1) {
                        pc[index]->setFirstName(tmp);
                    } else if(point == 2) {
                        pc[index]->setLastName(tmp);
                    } else if(point == 3) {
                        pc[index]->setJob(tmp);
                    } else if(point == 4) {
                        if(type == 2) {
                            //manager
                           manager * m = dynamic_cast<manager *>(pc[index]);
                           const char * kp = tmp.c_str();
                           const int * a =  (const int *)(kp);
                           m->setInchargeOf(*a);
                        } else if(type == 3) {
                            //fink
                             (dynamic_cast<fink *>(pc[index]))->setReportsto(tmp);
                        } else if(type == 4) {
                            //highfink
                            const char * kp = tmp.c_str();
                            const int * a =  (const int *)(kp);
                             (dynamic_cast<highfink *>(pc[index]))->setInchargeOf(*a);
                        }
                    }else if(point == 5) {
                        //highfink
                        (dynamic_cast<highfink *>(pc[index]))->setReportsto(tmp);
                    }
                }
            } else {
                break;
            }
            point++;
        }
}

int setData(int index, abstr_emp ** pc) {
    char choice;
    cout << "Enter (e,m,f,h) to create a person(other word quit input):\n";
    while(true) {
            cin >> choice;
            while(cin.get() != '\n'){
                continue;
            }
            if(choice != 'e' && choice != 'm' && choice != 'f' && choice != 'h') {
                cout << "other choice, so quit.\n";
                break;
            }
            switch(choice) {
                case 'e':{
                    cout << "choice input employee: \n";
                    employee * e = new employee();
                    pc[index] = e;
                    pc[index]->setAll();
                    break;
                    }
                case 'm':
                {
                    cout << "choice input manager: \n";
                    manager * tm = new manager();
                    pc[index] = tm;
                    tm->setAll();
                    break;
                }
                case 'f':
                {
                    cout << "choice input fink: \n";
                    fink * tf = new fink();
                    pc[index] = tf;
                    tf->setAll();
                    break;
                }
                case 'h':
                {
                    cout << "choice input highfink: \n";
                    highfink * th = new highfink();
                    pc[index] = th;
                    th->setAll();
                    break;
                }
            }
            index++;
            if(index >=MAX) break;
            cout << "Enter (e,m,f,h) to create a person(other word quit input):\n";
        }
    return index;
}