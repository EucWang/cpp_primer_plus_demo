#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class Beta {
    private:
        //内部的模板类
        template <typename V>
        class Hold;

        Hold<T> q;
        Hold<int> n;

    public:
        Beta(T t, int i) : q(t), n(i) {}
        
        //单独的模板方法
        template <typename U>
        U blab(U u, T t);
        // template <typename U>
        // U blab(U u, T t) {return (n.value() + q.value()) * u / t; };

        void show() const { q.show(); n.show();};
};

/**
 * 在类外面定义嵌套模板类，注意模板也必须是嵌套的
 */ 
template <typename T>
    template <typename V>
    class Beta<T>::Hold {
        private:
            V val;
        public:
            Hold(V v=0):val(v){}
            void show() const{ cout << val << endl;};
            V value() const {return val;};
    };

/**
 * 在类外面定义嵌套的 模板函数， 注意嵌套的模板定义
 */ 
template <typename T>
    template <typename U>
    U Beta<T>::blab(U u, T t) {
        return (n.value() + q.value()) * u / t; 
    };


int main() {
    Beta<double>  guy(3.5, 3);
    cout << "T was set to double.\n";
    guy.show();

    cout << "V was set to T, which is double, then V was set to int.\n";
    cout << guy.blab(10, 2.3) << endl;

    cout << "U was set to int.\n";
    cout << guy.blab(10.0, 2.3) << endl;

    cout << "U was set to double.\n";
    cout << "Done.\n";

    return 0;
}