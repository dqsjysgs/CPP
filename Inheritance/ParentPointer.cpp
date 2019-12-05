#include <iostream>
using namespace std;

class A {
private:
    int a;
    int b;
public:
    A():a(0), b(0) {}
    A(int aa, int bb):a(aa), b(bb) {}
    ~A() {}
    void print() {
        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
    }
    void seta(int aa) { a = aa; }
    void setb(int bb) { b = bb; }
    int geta() { return a; }
    int getb() { return b; }
};

class B: public A {
private:
    int c;
public:
    B():A(0, 0), c(0) {}
    B(int aa, int bb, int cc):A(aa, bb), c(cc) {}
    void print() {
        cout << "a = " << geta() << endl;
        cout << "b = " << getb() << endl;
        cout << "c = " << c << endl;
    }
    void setc(int cc) { c = cc; }
};

int main(void) {

    B b(4, 5, 6);
    A a(1, 2);

    A* pA = (A*)&b; //OK!
    B* pB = (B*)&a; //Cause error!

    cout << "****** pB ******\n";
    pB->print();
    cout << "******* a ******\n";
    a.print();
    cout << "****** pA ******\n";
    pA->print();
    cout << "******* b ******\n";
    b.print();

    return 0;
}
