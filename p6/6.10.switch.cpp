#include <iostream>


using namespace std;

void showmenu();
void report();
void comfort();



/**
 * switch语句
 * 
 */ 
int main289()
{
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    showmenu();
    int choice;
    cin >> choice;
    while(choice != 5) 
    {
        switch (choice)
        {
            case 1:
                cout << "\a\n";
                break;
            case 2:
                report();
                break;

            case 3:
                cout << "The boss was in all day.\n";
                break;
            case 4:
                comfort();
                break;
        
            default:
                cout << "That's not a choice.\n";
                break;
        }
        showmenu();
        cin >> choice;
    }
    
    cout<<endl;
    return 0;
}

void showmenu()
{
    cout << "Please enter 1,2,3,4, or 5:\n"
            "1) alarm \t2) report\n"
            "3) alibi \t4) comfort\n"
            "5) quit\n";
}

void report()
{
    cout << "It's been an excellent week for business.\n"
        "Sales are up 120%. Expenses are down 35%.\n";
}

void comfort()
{
    cout << "Your employees think you are the finest CEO\n"
        "in the industry. The board of directors think \n"
        "you are the finest CEO in the industry.\n";
}