#include <iostream>
#include <vector>
#include <ctime>
#include <list>
#include <cstdlib>
#include <iterator>

using namespace std;

int test9in16(){
    srand(time(0));

    vector<int> vi0;
    for(int i=0; i<10000000; i++) {
        int a = (rand()  * 100000000);
        vi0.push_back(a);
    }

    vector<int> vi;
    list<int> li;

    copy(vi0.begin(), vi0.end(), insert_iterator<vector<int>>(vi, vi.begin()));
    copy(vi0.begin(), vi0.end(), insert_iterator<list<int>>(li, li.begin()));
    
    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    //计算 对vector排序的时间
    cout << "sort vector spend time  : "  
         << (double)((end - start)/CLOCKS_PER_SEC) 
         << "s" <<  endl;

    li.sort();
    clock_t end2 = clock();
     //计算 对list排序的时间
    cout << "sort list spend time: "  
         << (double)((end2 - end)/CLOCKS_PER_SEC)
         << "s"  <<  endl;

    clock_t start2 = clock();
    li.clear();
    copy(vi0.begin(), vi0.end(), insert_iterator<list<int>>(li, li.begin()));
    copy(li.begin(), li.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());
    clock_t end3 = clock();
    cout << "copy list to vector and then sort,then it spend time: " 
        << (double)((end3 - start2)/CLOCKS_PER_SEC)
        << "s" <<  endl;



    return 0;
}