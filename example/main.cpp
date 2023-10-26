/*
MIT License

Copyright (c) 2023 Igor Korsukov

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#include <cassert>

#include "../funcinfo.h"

using namespace kors;

#define EXPECT_EQ(v, s) \
    if (std::string_view(v) != std::string_view(s)) { \
        std::cout << "FAILED EXPECT_EQ val: `" << v << "` should: `" << s << "`" << std::endl; \
    } \

#define PRINT_CHECK(title, val, ref) \
    std::cout << "  " << title << ": " << val << std::endl; \
    EXPECT_EQ(val, ref); \

static void justFunc()
{
    PRINT_CHECK("Func name", FUNCNAME, "justFunc");
    PRINT_CHECK("Class name", CLASSNAME, "");
    PRINT_CHECK("Class::func", CLASSFUNC, "justFunc");
    PRINT_CHECK("Module name", MODULENAME, "");
}

namespace kors {
static void funcInNamespace()
{
    PRINT_CHECK("Func name", FUNCNAME, "funcInNamespace");
    PRINT_CHECK("Class name", CLASSNAME, "kors");
    PRINT_CHECK("Class::func", CLASSFUNC, "kors::funcInNamespace");
    PRINT_CHECK("Module name", MODULENAME, "");
}
}

namespace kors::mymodule {
static void funcInModule()
{
    PRINT_CHECK("Func name", FUNCNAME, "funcInModule");
    PRINT_CHECK("Class name", CLASSNAME, "mymodule");
    PRINT_CHECK("Class::func", CLASSFUNC, "mymodule::funcInModule");
    PRINT_CHECK("Module name", MODULENAME, "mymodule");
}
}

namespace kors::mymodule::sub {
static void funcInSubModule()
{
    PRINT_CHECK("Func name", FUNCNAME, "funcInSubModule");
    PRINT_CHECK("Class name", CLASSNAME, "sub");
    PRINT_CHECK("Class::func", CLASSFUNC, "sub::funcInSubModule");
    PRINT_CHECK("Module name", MODULENAME, "mymodule");
}
}

class JustClass
{
public:
    void methodOfJustClass()
    {
        PRINT_CHECK("Func name", FUNCNAME, "methodOfJustClass");
        PRINT_CHECK("Class name", CLASSNAME, "JustClass");
        PRINT_CHECK("Class::func", CLASSFUNC, "JustClass::methodOfJustClass");
        PRINT_CHECK("Module name", MODULENAME, "");
    }
};

namespace kors {
class ClassInNS
{
public:
    void methodOfClassInNS()
    {
        PRINT_CHECK("Func name", FUNCNAME, "methodOfClassInNS");
        PRINT_CHECK("Class name", CLASSNAME, "ClassInNS");
        PRINT_CHECK("Class::func", CLASSFUNC, "ClassInNS::methodOfClassInNS");
        PRINT_CHECK("Module name", MODULENAME, "ClassInNS");
    }
};
}

namespace kors::mymodule {
class ClassInModule
{
public:
    void methodOfClassInModule()
    {
        PRINT_CHECK("Func name", FUNCNAME, "methodOfClassInModule");
        PRINT_CHECK("Class name", CLASSNAME, "ClassInModule");
        PRINT_CHECK("Class::func", CLASSFUNC, "ClassInModule::methodOfClassInModule");
        PRINT_CHECK("Module name", MODULENAME, "mymodule");
    }
};
}

namespace kors::mymodule::sub {
class ClassInSubModule
{
public:
    void methodOfSub()
    {
        PRINT_CHECK("Func name", FUNCNAME, "methodOfSub");
        PRINT_CHECK("Class name", CLASSNAME, "ClassInSubModule");
        PRINT_CHECK("Class::func", CLASSFUNC, "ClassInSubModule::methodOfSub");
        PRINT_CHECK("Module name", MODULENAME, "mymodule");
    }
};
}

int main(int argc, char* argv[])
{
    std::cout << "Hello World, I am FuncInfo!" << std::endl;

    std::cout << std::endl;
    std::cout << "Test 1: just function" << std::endl;
    justFunc();

    std::cout << std::endl;
    std::cout << "Test 2: function in namespace" << std::endl;
    kors::funcInNamespace();

    std::cout << std::endl;
    std::cout << "Test 3: function in module" << std::endl;
    kors::mymodule::funcInModule();

    std::cout << std::endl;
    std::cout << "Test 4: function in submodule" << std::endl;
    kors::mymodule::sub::funcInSubModule();

    std::cout << std::endl;
    std::cout << "Test 5: just class" << std::endl;
    JustClass().methodOfJustClass();

    std::cout << std::endl;
    std::cout << "Test 6: class in namespace" << std::endl;
    kors::ClassInNS().methodOfClassInNS();

    std::cout << std::endl;
    std::cout << "Test 7: class in module" << std::endl;
    kors::mymodule::ClassInModule().methodOfClassInModule();

    std::cout << std::endl;
    std::cout << "Test 8: class in submodule" << std::endl;
    kors::mymodule::sub::ClassInSubModule().methodOfSub();

    std::cout << "Goodbye!" << std::endl;
}
