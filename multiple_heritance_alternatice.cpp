#include <string>
#include <iostream>

using namespace std;

class Device {

};

// ISP interface segregation
class IPrinter{
    public:
    virtual void print() const = 0;
};

class IScanner{
    public:
    virtual void scan() const = 0;
};

// Printer is a specialized form of Device
// Printer is Device
// Printer is child of Device
// Printer assumes the responsibility of Device
class Printer : public Device, public IPrinter {
    public: 
    void print()const {}
};

class Scanner : public Device, public IScanner{
    public:
    void scan()const {}
};

class PrinterScanner : public IPrinter, public IScanner{
    //Aggregation
    IPrinter* pObj;
    IScanner* sObj;
    public:
    // delegation
    PrinterScanner(IPrinter* pPtr, IScanner* sPtr) : pObj{pPtr}, sObj{sPtr}{}
    void print() const{
        pObj->print();
    }
    void scan() const{
        sObj->scan();
    }
};

//DIP
void printJob(const IPrinter& printerRef) {printerRef.print();}
void scanJob(const IScanner& scannerRef){scannerRef.scan();}

int main() {
    // Write C++ code here
    Printer pObj;
    Scanner sObj;
    PrinterScanner psObj(&pObj, &sObj);

    printJob(pObj);
    scanJob(sObj);
    printJob(psObj);
    scanJob(psObj);
    return 0;
}