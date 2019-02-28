#include <iostream>
#include "list.cpp"

// using namespace std;
using std::cout;
using std::endl;

int main()
{
    List list = List(5);
    cout << "list is empty ? : "<< list.isempty() << endl;
    cout << "list is full ? : " << list.isfull() << endl;

    Item item = {1.1, 2.2};
    list.add(item);
    cout << "after add a item then " << endl;
    cout << "list is empty ? : "<< list.isempty() << endl;
    cout << "list is full ? : " << list.isfull() << endl;


    Item item2 = {1.1, 2.2};
    Item item3 = {2.2, 2.2};
    Item item4 = {3.3, 2.2};
    Item item5 = {4.4, 2.2};
    list.add(item2);
    list.add(item3);
    list.add(item4);
    list.add(item5);

    cout << "after add 4 items then " << endl;
    cout << "list is empty ? : "<< list.isempty() << endl;
    cout << "list is full ? : " << list.isfull() << endl;

    list.remove();
    cout << "after remove 1 item then " << endl;
    cout << "list is empty ? : "<< list.isempty() << endl;
    cout << "list is full ? : " << list.isfull() << endl;

    list.remove();
    list.remove();
    list.remove();
    list.remove();
    cout << "after remove 4 items then " << endl;
    cout << "list is empty ? : "<< list.isempty() << endl;
    cout << "list is full ? : " << list.isfull() << endl;

    return 0;
}
