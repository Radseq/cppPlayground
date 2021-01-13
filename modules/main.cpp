import hello;
import testClass;

#include <string>

int main () 
{ 
    TestNamespace::myClass *clTest = new TestNamespace::myClass(111);
    const auto a = clTest->getAval();
    
    TestNamespace::print(clTest);
    
    clTest->setVal(1243);
    
    TestNamespace::print(clTest);

    say_hello ("Modules"); 
}
