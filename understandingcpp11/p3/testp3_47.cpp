#include <iostream>

#include "test3.h"
using namespace std;

namespace Jim{
    namespace Basic {
        struct Knife {
            Knife(){
                cout << "Knife in Basic.\n";
            }
        };

        class CorkScrew{};
    }

    namespace Toolkit {
        template<class T>
        class SwissArmyKnife{};
    }

    namespace Other{
        // Knife b;   //无法通过编译  error: unknown type name 'Knife'; did you mean 'Basic::Knife'?
        struct Knife{
            Knife(){
                cout << "Knife in Other.\n";
            }
        };
        Knife c;
        Basic::Knife k;  //在这个名称空间下，有一个 ⚠️Basic::Knife变量，使用Other空间时，就会创建
    }
};

using namespace Jim;

void testp3_47(){
    cout << __func__ << "() called.\n";

    Toolkit::SwissArmyKnife<Basic::Knife> sknife;

    cout << __func__ << "() called.done.\n";
}