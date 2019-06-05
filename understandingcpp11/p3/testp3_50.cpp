#include <iostream>
#include "test3.h"
using namespace std;

/**
 * c++11中，引入 了“内联的名称空间”， 
 * 使用关键字  inline namespace 可以声明一个内联的名称空间。
 * 内联的名称空间 允许 在父名称空间中定义或者模板实例化 子名称空间 中的 模板。
 */ 

namespace Jim4{

    //通过编译环境版本，来确定使用那个版本的类
    #if __cplusplus >= 201103L
        inline
    #endif
        namespace cpp11{
            struct Knife4{
                Knife4(){
                    cout << "Knife in C++11.\n";
                }
            };
            class CorkScrew4{};
        }
    #if __cplusplus < 201103L
        inline
    #endif
        namespace oldcpp{
            struct Knife4{
                Knife4(){
                    cout << "Knife in old c++.\n";
                }
            };
            class CorkScrew4{};
        }

    // inline namespace Basic4 {
    //     struct Knife4 {
    //         Knife4(){
    //             cout << "Knife in Basic.\n";
    //         }
    //     };

    //     class CorkScrew4{};
    // }

    inline namespace Toolkit4 {
        template<class T>
        class SwissArmyKnife4{};
    }

    namespace Other4{
        Knife4 b;   //现在， 通过inline namespace ，这个默认就使用了 Basic4::Knife4
        struct Knife4{
            Knife4(){
                cout << "Knife in Other.\n";
            }
        };
        Knife4 c;
        // Basic4::Knife4 k;  //在这个名称空间下，有一个 ⚠️Basic::Knife变量，使用Other空间时，就会创建
    }

    //再总的名称空间最后，打开二级/三级名称空间，那么在使用时，引入总的名称空间就可以直接使用子名称空间下的内容
    //⚠️，这里没有默认打开Other里的名称空间，防止冲突
    // using namespace Basic4;
    // using namespace Toolkit4;
};

//尝试对Jim2 下的 模板类进行实例化
//目前在C++11中，貌似没有出现 C++98 的问题， 可以正常模板实例化
//通过 使用 inline namespace 来 完全实现 父名称空间中对 子名称空间 中对 模板实例化
namespace Jim4{
    template<> class SwissArmyKnife4<Knife4>{};
};

using namespace Jim4;

void testp3_50(){
    cout << __func__ << "() called.\n";

    // Toolkit::SwissArmyKnife<Basic::Knife> sknife;
    // SwissArmyKnife4<Knife4> sknife;

    Knife4 a;
    cpp11::Knife4 b;  //强制使用cpp11版本的类
    oldcpp::Knife4 c;

    cout << __func__ << "() called.done.\n";
}