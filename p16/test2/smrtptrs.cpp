// 16.5 smart pointer  -- using three kinds of smart pointers
// requires support of C++11 shared_ptr nad unique_ptr  
// requires support of c++98 auto_ptr

#include <iostream>
#include <string>
#include <memory>

using std::string;
using std::cout;
using std::cin;
using std::endl;

//3 kinds
using std::auto_ptr;
using std::shared_ptr;
using std::unique_ptr;

class Report {
    private:
        string str;
    public:
        Report(const string s) : str(s) {
            cout << "Object created!\n";
        }
        ~Report(){cout << "Object deleted!\n";}

        void comment() const {cout << str<< "\n";}
};

int main_smrt_ptrs(){

    {
        auto_ptr<Report> ps(new Report("using auto_ptr"));
        ps->comment();
    }
    cout << "\n===================\n";
    {
        shared_ptr<Report> ps(new Report("using shared_ptr"));
        ps->comment();
    }
    cout << "\n===================\n";
    {
        unique_ptr<Report> ps(new Report("using unique_ptr"));
        ps->comment();
    }
    cout << "\n===================\n";
    return 0;
}