#include <iostream>
#include <vector>

struct fish 
{
    int type;
    int weight;
    float length;
};

enum Response
{
    Yes = 1, No = 0, Maybe = 2
};

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << endl;

    struct fish a = {1,10, 3.4};
    cout << "fish \n[ \ttype:" << a.type 
        << ",\n\tweight:" << a.weight 
        << ",\n\tlength:" << a.length << "\n]" << endl;

    double ted = 8.8;
    double * pt_ted = &ted;
    cout << "ted value is : " << *pt_ted << endl;

    float treacle[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    float * pt_treacle = treacle;
    cout << "treacle[0]:\t" << *pt_treacle << "\n last one:\t" << *(pt_treacle + 8) << endl;

    // int num = 0;
    // cout << "Please enter a number : ";
    // cin >> num;
    // cout << "your enter number is :" << num << endl;

    // cout << "create a dynamic array, enter the count : ";
    // int count;
    // cin >> count;
    // int * arr3 = new int[count];
    // cout << "the size of dynamic array : " << count << endl;
    // cout << *arr3 << ", " << *(arr3 + 1) << ", " <<   *(arr3 + 2) << endl;

    // int * arr4 = vector(count);
    // vector<int> arr4(count);

    // const char * pt_str = "Home of the jolly bytes";
    // cout << (int *)pt_str;

    struct fish * fish1 = new struct fish;
    fish1->type = 2;
    cout << "fish1 : type : " << fish1->type << endl;

    

    cout<< endl;
    return 0;
}
