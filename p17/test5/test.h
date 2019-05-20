#ifndef TEST_P17_H_
#define TEST_P17_H_


#include <iostream>
#include <vector>
template<class T>
void showVector2(const char * tips, std::vector<T> & v) {
    std::cout << tips << std::endl;
    std::copy(v.begin(), v.end(), std::ostream_iterator<T , char>(std::cout, "\n"));
    std::cout << std::endl;
};

int main_p17test1();
int main_p17test2();
int main_p17test3();
int main_p17test4();
int main_p17test5();
int main_p17test6();
int main_p17test7();

#endif