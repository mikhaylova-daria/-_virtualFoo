#ifndef MACROSINHARITANCE_H
#define MACROSINHARITANCE_H

#include <iostream>
#include <map>
#include <set>
#include <vector>

#define VIRTUAL_CLASS(className) struct className;

#define DATA(className) struct className {\
           std::map<std::string, void(*) (className*)> vTable;

#define END(className) };

#define METHOD(className, nameFoo)\
    this->vTable.insert(std::pair<std::string, void(*) (className*)> (#nameFoo, &nameFoo));



#define DECLARE_METHOD(className, fooName)\
    void fooName (className* thisPoint);


#define IMPL_METHOD(className, fooName)\
    void fooName (className* thisPoint) {\
        std::cout<<#className<<"::"<<#fooName<<std::endl;

#define VIRTUAL_CALL(objectPtr, fooName) \
    (*(objectPtr->vTable.at(#fooName)))(objectPtr);

#define METHODS(className) className() {

#define METHODS_END(className) }

#endif // MACROSINHARITANCE_H
