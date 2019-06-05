#include <iostream>
#include "test3.h"

using namespace std;

/**
 * c++11中，引入 了“内联的名称空间”， 
 * 使用关键字  inline namespace 可以声明一个内联的名称空间。
 * 内联的名称空间 允许 在父名称空间中定义或者模板实例化 子名称空间 中的 模板。
 */ 

namespace Jim3{
    inline namespace Basic3 {
        struct Knife3 {
            Knife3(){
                cout << "Knife in Basic3.\n";
            }
        };

        class CorkScrew3{};
    }

    inline namespace Toolkit3 {
        template<class T>
        class SwissArmyKnife3{};
    }

    namespace Other3{
        Knife3 b;   //现在， 通过inline namespace ，这个默认就使用了 Basic3::Knife3
        struct Knife3{
            Knife3(){
                cout << "Knife in Other3.\n";
            }
        };
        Knife3 c;
        Basic3::Knife3 k;  //在这个名称空间下，有一个 ⚠️Basic::Knife变量，使用Other空间时，就会创建
    }

    //再总的名称空间最后，打开二级/三级名称空间，那么在使用时，引入总的名称空间就可以直接使用子名称空间下的内容
    //⚠️，这里没有默认打开Other里的名称空间，防止冲突
    using namespace Basic3;
    using namespace Toolkit3;
};

//尝试对Jim2 下的 模板类进行实例化
//目前在C++11中，貌似没有出现 C++98 的问题， 可以正常模板实例化
//通过 使用 inline namespace 来 完全实现 父名称空间中对 子名称空间 中对 模板实例化
namespace Jim3{
    template<> class SwissArmyKnife3<Knife3>{};
};

using namespace Jim3;

void testp3_49(){
    cout << __func__ << "() called.\n";

    // Toolkit::SwissArmyKnife<Basic::Knife> sknife;
    SwissArmyKnife3<Knife3> sknife;

    cout << __func__ << "() called.done.\n";
}