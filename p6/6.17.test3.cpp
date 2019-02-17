#include <iostream>


int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    const char * tip1 = "Please enter one of the following choices:\nc) carnivore\tp)pianist\nt) tree\tg) game\n";
    const char * tip2 = "Please enter a c, p , t, or g : ";
    char choices;
    cout << tip1;
    bool flag = true;
    while(flag && cin >> choices){
        switch (choices)
        {
            case 'c':
            case 'C':
                cout << "carnivore\n";
                cout << tip1;
                break;
            case 'p' :
            case 'P':
                cout << "pianist\n";
                cout << tip1;
                break; 
            case 't':
            case 'T':
                cout << "A maple is a tree\n";
                cout << tip1;
                break;
            case 'g':
            case 'G':
                cout << "game is over\n";
                flag = false;
                break;
            default:
                cout << tip2;
                cout << tip1;
                break;
        }
        cin.clear();
    }
    
    cout<<endl;
    return 0;
}
