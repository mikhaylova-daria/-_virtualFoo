#include <iostream>
#include <map>
#include <set>

#define VIRTUAL_CLASS(Name)  struct Name { \
    std::set< void(*) (Name*)> vTable;

#define END(Name) };

#define DECLARE_METHOD(className, fooName)\
    void fooName (className* thisPoint)

#define VIRTUAL_CALL(object, fooName) fooName(&object);


VIRTUAL_CLASS (A)
int i = 5;
END (A)

DECLARE_METHOD(A, write) {
    std::cout<<"bum!"<<std::endl;
}



using namespace std;

int main()
{
    A a;
    cout << a.i << endl;
    VIRTUAL_CALL(a, write);
    return 0;
}

