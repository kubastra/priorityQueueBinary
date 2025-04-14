#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>

class Element{
    private:
      int number;
      int priority;

    public:
        explicit Element(int num) : number(num), priority(num){}

        int getPriority(){
          return priority;
        }

        int getNumber(){
          return number;
        }
};


#endif //ELEMENT_H
