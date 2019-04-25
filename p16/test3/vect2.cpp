/**
 * 16.8  methods and iterators
 * 
 * size()
 * begin()
 * end()
 * 
 * push_back()
 * erase()
 * insert()
 */ 

#include <iostream>
#include <vector>
#include "vect.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

int main_vect2(){

    vector<Review> books;  //不指定vector的大小
    Review temp;

    while(fillReview(temp)) {    //每次都向vector尾部添加一个元素，vector大小自动调整
        books.push_back(temp);
    }
    int num = books.size();
    if(num > 0) {
        cout << "Thank you. You entered the following:" << endl
            << "Rating\tBook\n";
            for(int i=0; i<num; i++) {
                showReview(books[i]);
            }
            cout << "Reprising:\n"
                << "Rating\tBook\n";

            vector<Review>::iterator pr; //迭代器指针，这是一个指针, 迭代器遍历输出所有的元素
            for(pr =  books.begin(); pr != books.end(); pr++) {
                showReview(*pr);
            }
            vector<Review> oldlist(books);  //复制vector一份
            if(num > 3) {

                books.erase(books.begin() + 1, books.begin() + 3); //移除两个元素
                cout << "After erasure:" << endl;
                for(pr = books.begin(); pr != books.end(); pr++) {
                    showReview(*pr);
                }

                //将oldlist容器中的指定开始位置和结束位置的元素插入到当前开始位置， 这里只有一个元素
                books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
                cout << "After insertion:\n";
                for(pr = books.begin(); pr != books.end(); pr++) {
                    showReview(*pr);
                }
            } else {
                cout << "Nothing entered, nothing gained.\n";
            }
    }

    return 0;
}
