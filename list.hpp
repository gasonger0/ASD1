#include "node.cpp"
#include <iostream>
#ifndef LIST
#define LIST

class List {                                       //класс списка

protected:
    Node* first;
    Node* last;
    int counter{};
public:

    List() : first(nullptr), last(nullptr) {}      //конструктор

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(char _val) {                    //вставить новый элемент списка
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {                                //вывод элементов
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    void enter_symb() {
        char enter{};
        std::cout << "Enter count of cymbols:  ";
        std::cin >> counter;
        std::cin.clear();
        std::cout << "Enter each symbol:\n";
        for (int i{ 0 }; i < counter; i++) {
            std::cout << (counter - i) << " remain: ";
            std::cin >> enter;
            std::cin.clear();
            push_back(enter);
        }
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove(char _val) {
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            std::cout << "This element does not exist" << std::endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    Node* get_node() {
        return first;
    }

    int get_count() {
        return counter;
    }

    Node* operator[] (const int index) {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};
#endif
