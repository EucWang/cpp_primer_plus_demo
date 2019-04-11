#include <iostream>
#include <cstring>

using namespace std;

const int SLEN = 30;

struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);

void display1(student st);

void display2(const student * ps);

void display3(const student pa[], int n);

int main55()
{
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;

    while( cin.get() != '\n') {
        continue;
    }

    student * ptr_stu = new student[class_size];

    int entered = getinfo(ptr_stu, class_size);
    for(int i=0; i< entered; i++) {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done\n";
    return 0;
    
    cout<<endl;
    return 0;
}

/**
 * 输入学生数组的数据
 */ 
int getinfo(student pa[], int n) {
    int result;
    for(int i=0; i<n; i++) {
        cout << "========Enter student info ==========" << endl;
        cout << "Enter student's name : ";
        cin.getline(pa[i].fullname, SLEN);
        if(strlen(pa[i].fullname) == 0) {
            break;
        }
        cout << "Enter student's hobby : ";
        cin.getline(pa[i].hobby, SLEN);

        cout << "Enter student's level: ";
        cin >> pa[i].ooplevel;
        cin.get();
        result++;
    }
    return result;
}

void display1(student st) {
    cout << "+++ DISPLAY1 +++" << endl;
    cout << "Student [fullname : " << st.fullname 
        << ", \nhobby : "  << st.hobby 
        << ", \nooplevel : " << st.ooplevel 
        << "]" << endl;
}

void display2(const student * ps) {
    cout << "+++ DISPLAY2 +++" << endl;
    cout << "Student [fullname : " << ps->fullname 
        << ", hobby : "  << ps->hobby 
        << ", ooplevel : " << ps->ooplevel 
        << "]" << endl;
}

void display3(const student pa[], int n) {
    cout << "+++ DISPLAY3 +++" << endl;
    for(int i=0; i<n; i++) {
        cout << "Student [fullname : " << (pa+i)->fullname 
                << ", hobby : "  << (pa+i)->hobby 
                << ", ooplevel : " << (pa+i)->ooplevel 
                 << "]" << endl;
    }
}
