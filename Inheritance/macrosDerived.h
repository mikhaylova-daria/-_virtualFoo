#ifndef MACROSDERIVED_H
#define MACROSDERIVED_H

#define DATA_DERIVED( classNameB, classNameD ) struct classNameD {\
    std::map<std::string, void(*) (classNameD*)> vTable;\

#define METHODS_DERIVED(nameClassBase, nameClassDerived) nameClassDerived() {\

#define METHODS_END_DERIVED( classNameB, classNameD )\
    classNameB _b_;\
    std::map<std::string, void(*) (classNameB*)>::iterator itr;\
    for (itr = _b_.vTable.begin(); itr != _b_.vTable.end(); ++itr) {\
        this->vTable.insert(std::pair<std::string, void(*) (classNameD*)>(itr->first, (void(*) (classNameD*))itr->second));\
    }\
    }

#endif // MACROSDERIVED_H
