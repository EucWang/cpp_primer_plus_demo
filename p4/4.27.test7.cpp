#include <iostream>
#include <string>
using namespace std;

struct pizza
{
    string company_name;  //公司名称
    double diameter; //直径
    double weight;   //重量
};

char * get_name(){
    char tmp[256];
    cin.getline(tmp, 256);
    char * ret_val = new char(strlen(tmp) + 1);
    strcpy(ret_val, tmp);
    return ret_val;
}

int main()
{
  
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    string tip1 = "Please enter where from the pizza? ";
    string tip2 = "Please enter value of the pizza diameter? ";
    string tip3 = "Please enter weight of the pizza? ";

    struct pizza * one_pizza = new pizza;


    cout <<tip2;
    cin >> one_pizza->diameter;
    cin.get();

    cout << tip1;
    char * name = get_name();
    one_pizza->company_name = name;

    cout << tip3;
    cin >> one_pizza->weight;
    cin.get();

    cout << "pizza info : \n[" << one_pizza->company_name 
        <<", \t " << one_pizza->diameter
        << ", \t " << one_pizza->weight << "]";
    
    cout<<endl;
    return 0;
}
