#ifndef KOPIEC_H
#define KOPIEC_H

#include <iostream>
#include <vector>
#include <stdexcept>

class Kopiec{
    private:
        std::vector<int> elements;
        int parent(int i) {
            return (i - 1) / 2;
        }
        int left(int i) {
            return 2 * i + 1;
        }
        int right(int i) {
            return 2 * i + 2;
        }

        void heapifyUp(int i) {
            while (i > 0 && elements[i] < elements[parent(i)]) {
                std::swap(elements[i], elements[parent(i)]);
                i = parent(i);
            }
        }

    public:
        Kopiec() {
            elements.clear();
        }
        void heapifyDown(int i) {
            int l = left(i);
            int r = right(i);
            int smallest = i;
            int n = elements.size();
            if (l < n && elements[l] < elements[smallest]) {
                smallest = l;
            }
            if (r < n && elements[r] < elements[smallest]) {
                smallest = r;
            }
            if (smallest != i) {
                std::swap(elements[i], elements[smallest]);
                heapifyDown(smallest);
            }
        }

        void inserta(int element) {
            elements.push_back(element);
            heapifyUp(elements.size() - 1);
        }

        void pop_min() {
            elements[0] = elements.back();
            elements.pop_back();
            heapifyDown(0);
        }

    void print() {
            int n = elements.size();
            int level = 0;
            int index = 0;

            while (index < n) {
                int nodesInLevel = 1 << level; // 2^level
                int spaces = (1 << (4 - level)); // dobierz liczbę jak trzeba

                for (int i = 0; i < nodesInLevel && index < n; ++i) {
                    std::cout << std::string(spaces, ' ') << "[" << elements[index++] << "]";
                }
                std::cout << "\n";
                level++;
            }
        }


};


#endif
