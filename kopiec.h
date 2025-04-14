#ifndef KOPIEC_H
#define KOPIEC_H

#include "element.h"
#include <vector>


class Kopiec{
    private:
        std::vector<Element> elements;

    public:
        Kopiec() {
            elements.clear();
        }

        void insert(Element &element) {
            elements.push_back(element);
        }

        void pop_min() {
            elements.erase(elements.begin());
        }

        void print() {
            for (int i = 0; i < elements.size(); i++) {
                std::cout << elements[i].getPriority() << " ";
            }
        }

};


#endif
