#include "kopiec.h"



int main() {

    Element el1 = Element(10);
    Element el2 = Element(20);

    Kopiec kop;

    kop.insert(el1);
    kop.insert(el2);

    kop.pop_min();

    kop.print();


    return 0;
}