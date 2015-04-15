#include "macrosBase.h"

VIRTUAL_CLASS (A)

DECLARE_METHOD(A, write)
    std::cout<<"bum!"<<std::endl;
}

DECLARE_METHOD(A, meow)
    std::cout<<"мяу"<<std::endl;
}

DATA(A)

int i = 5;

METHODS(A)

METHOD(A, write)
METHOD(A, meow)

METHODS_END(A)

END (A)


struct B{
    B() {
        std::cout <<"!"<<std::endl;
    }
};

using namespace std;

int main()
{
    A a;
  //  cout << a.vTable.size() << endl;
    VIRTUAL_CALL((&a), write);
    VIRTUAL_CALL((&a), meow);
    return 0;
}

