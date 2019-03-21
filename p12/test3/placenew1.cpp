#include <iostream>
#include <string>
#include <new>

using namespace std;
const int BUF = 512;

class JustTesting {
    private:
        string words;
        int number;
    public:
        JustTesting(const string & s="Just Testing", int n=0){
            words = s; 
            number = n; 
            cout << "[" << words << " constructed]\n";
        }

        ~JustTesting(){
            cout << words << " destroyed\n";
        }

        void show() const {
            cout << words << ", " << number << endl;
        }
};

int main() {
    char * buffer = new char[BUF];
    JustTesting * pc1, * pc2;

    pc1 = new (buffer)JustTesting;           //将对象放入到buffer中
    pc2 = new JustTesting("Heap1", 20);      //创建默认构造函数

    cout << "Memory block addresses:\n" << "\tbuffer: "
        << (void *) buffer << "\n\theap: " << pc2 << endl;
    
    cout << "==============\nMemory contents:\n";
    cout << pc1 << ":\n\t";
    pc1->show();

    cout << pc2 << ":\n\t";
    pc2->show();

    JustTesting *pc3, *pc4;
    pc3 = new (buffer)JustTesting("Bad Idea", 6); //将对象放入到buffer中
    pc4 = new JustTesting("Heap2", 10);

    cout << "Memory contents:\n";
    cout << pc3 << ":\n\t";
    pc3->show();
    cout << pc4 << ":\n\t";
    pc4->show();

    delete pc2;
    delete pc4;
    delete [] buffer;
    cout << "Done\n";
    return 0;
}