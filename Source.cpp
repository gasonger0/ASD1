#include <iostream>
#include "list.hpp"



class Text : List {

private:
    List A;
    int len{};

public:

    Text(int c, char* a) {
        char* buf = new char[c] {};
        for (int i{}; i < c; i++) {
            buf[i] = a[i];
        }
        for (int i{}; i < c; i++) {
            A.push_back(buf[i]);
        }
    };

    void print() {
        if (A.is_empty()) return;
        Node* p = A.get_node();
        while (p) {
            std::cout << p->val << "";
            p = p->next;
        }
        std::cout << std::endl;
    }

    List get_list() {
        return A;
    }
};


int main(int argc, char** argv) {
    if (argc == 1) {
        std::cout << "No text in input!\n";
        std::exit(0);
    }
    List T;
    T.enter_symb();
    Text A(sizeof(argv[1]), argv[1]);
    A.print();
    for (int i{}; i < sizeof(argv[1]); i++) {
        for (int j{}; j < T.get_count(); j++) {
            if (A.get_list()[i] == T[j]){
                A.get_list().remove(i);
            }
        }
    }
    A.print();


    return 0;
}
