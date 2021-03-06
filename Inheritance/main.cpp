#include "macrosBase.h"
#include "macrosDerived.h"


//Базовый класс
VIRTUAL_CLASS (Base)

DECLARE_METHOD(Base, both)
DECLARE_METHOD(Base, onlyBase)

DATA(Base)

int i = 0;

METHODS(Base)

METHOD(Base, onlyBase)
METHOD(Base, both)

METHODS_END(Base)

END (Base)

IMPL_METHOD(Base, both)
    std::cout<<"Base i:"<<thisPoint->i<<"\n"<<std::endl;
}

IMPL_METHOD(Base, onlyBase)
    std::cout<<"I am base\n"<<thisPoint->i<<std::endl;
}


//класс-наследник
VIRTUAL_CLASS (Derived)

DECLARE_METHOD(Derived, both)
DECLARE_METHOD(Derived, onlyDerived)

DATA_DERIVED(Base, Derived)

int b = 7;

METHODS(Derived)

METHOD(Derived, both)
METHOD(Derived, onlyDerived)

METHODS_END_DERIVED(Base, Derived)

END (Derived)

IMPL_METHOD(Derived, both)
    std::cout<<"Derived b: "<<thisPoint->b<<"\n"<<std::endl;
}

IMPL_METHOD(Derived, onlyDerived)
    std::cout<<"I am derived!"<<"\n"<<std::endl;
}

class A {
};

class B: public A{
};
using namespace std;

int main()
{
    A* a =new B();

    std::cout<<"Метод, определённый в базовом и непереопределённый в наследнике, вызванный от наследника:"<<std::endl;
    Derived d;
    VIRTUAL_CALL((&d), onlyBase);

    std::cout<<"Код из примера:"<<std::endl;
    Base b;
    VIRTUAL_CALL((&b), both);
    Base* reallyDerived = reinterpret_cast<Base*>(&d);
    VIRTUAL_CALL(reallyDerived, both);
    VIRTUAL_CALL(reallyDerived, onlyBase);
    VIRTUAL_CALL(reallyDerived, onlyDerived);

    std::cout<<"Метод, неопределённый в классе, бросает исключение: (вызываем от Base метод onlyDerived:)"<<std::endl;
    VIRTUAL_CALL((&b), onlyDerived);
    return 0;
}

