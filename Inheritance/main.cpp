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
    std::cout<<"I am base\n"<<std::endl;
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


using namespace std;

int main()
{
    Base b;
  //  cout << a.vTable.size() << endl;
    VIRTUAL_CALL((&b), both);
    Derived d;
    Base* reallyDerived = reinterpret_cast<Base*>(&d);
    VIRTUAL_CALL(reallyDerived, both);
    VIRTUAL_CALL(reallyDerived, onlyBase);
    VIRTUAL_CALL(reallyDerived, onlyDerived);
    return 0;
}

