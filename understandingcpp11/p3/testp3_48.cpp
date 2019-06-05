#include <iostream>

#include "test3.h"
using namespace std;

namespace Jim2{
    namespace Basic2 {
        struct Knife2 {
            Knife2(){
                cout << "Knife in Basic2.\n";
            }
        };

        class CorkScrew2{};
    }

    namespace Toolkit2 {
        template<class T>
        class SwissArmyKnife2{};
    }

    namespace Other2{
        // Knife b;   //无法通过编译  error: unknown type name 'Knife'; did you mean 'Basic::Knife'?
        struct Knife2{
            Knife2(){
                cout << "Knife in Other2.\n";
            }
        };
        Knife2 c;
        Basic2::Knife2 k;  //在这个名称空间下，有一个 ⚠️Basic::Knife变量，使用Other空间时，就会创建
    }

    //再总的名称空间最后，打开二级/三级名称空间，那么在使用时，引入总的名称空间就可以直接使用子名称空间下的内容
    //⚠️，这里没有默认打开Other里的名称空间，防止冲突
    using namespace Basic2;
    using namespace Toolkit2;
};

//尝试对Jim2 下的 模板类进行实例化
//目前在C++11中，貌似没有出现 C++98 的问题， 可以正常模板实例化
namespace Jim2{
    template<> class SwissArmyKnife2<Knife2>{};
};


using namespace Jim2;

void testp3_48(){
    cout << __func__ << "() called.\n";

    // Toolkit::SwissArmyKnife<Basic::Knife> sknife;
    SwissArmyKnife2<Knife2> sknife;

    cout << __func__ << "() called.done.\n";
}