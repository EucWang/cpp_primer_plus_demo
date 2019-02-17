#include <iostream>

const  int strSize = 64;

struct bop{
    char fullname[strSize];      //真实姓名 real name
    char title[strSize];        //头衔      job title
    char bopname[strSize];      //bop姓名   bop secret name
    int preference;             // 0 fullname, 1 title, 2 bopname
};

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    struct bop bops[3] = {
        {"张三", "ceo", "ceo zhang", 0},
        {"lisi", "cfo", "cfo zhang", 1},
        {"wangwu", "coo", "coo zhang", 2},
    };
    
   

    char choice;
    const char * tip = "Please enter one of the following choices:\na. display by name \t b. display by title\nc. display by bopname\td. display by preference\nq. quit\n";
    cout << tip;
    bool flag = true;
    while(flag && cin >> choice){
        switch (choice)
        {
            case 'a':
                cout << "\n========\n";
                for (int i=0 ;i<3; i++){
                    cout << bops[i].fullname << endl;
                }
                cout << tip;
                break;
            case 'b':
                cout << "\n========\n";
                for (int i=0 ;i<3; i++){
                    cout << bops[i].title << endl;
                }
                cout << tip;
                break;
            case 'c':
                cout << "\n========\n";
                for (int i=0 ;i<3; i++){
                    cout << bops[i].bopname << endl;
                }
                cout << tip;
                break;
            case 'd':
                cout << "\n========\n";
                 for(int i=0; i<3; i++) {
                    char * name;
                    switch (bops[i].preference)
                    {
                        case 0:
                            name = bops[i].fullname;
                            break;
                        case 1:
                            name = bops[i].title;
                            break;
                        case 2:
                            name=  bops[i].bopname;
                            break;
                        default:
                            break;
                    }
                    cout << name << endl;
                }
                cout << tip;
                break;
            case 'q':
                flag = false;
                cout << "Done!" << endl;
                break;
            default:
                cout << "Please enter a, b, c,d, q: ";
                break;
        }
    }
    cout<<endl;
    return 0;
}