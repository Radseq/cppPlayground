//Module Interface Unit can be only one

export module testClass;

// if export is before namespace it means all in namespace will be visible outside
namespace TestNamespace {

    // without export it wont be visible outside module
    // this will be visible out
    export class myClass{
        int a{0};
        friend void print(myClass* cl);
    public:
        const int& getAval();
        void setVal(const int& newVal);
        explicit myClass(const int& val);
    };
    
    //also visible outside
    export void print(myClass* cl);
    
}
