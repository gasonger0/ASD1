struct Node {                                      //структура для элемента списка
    char val;                                     //значение элемента 
    Node* next;                                   //указатель на следующий элемент списка
    Node(char _val) : val(_val), next(nullptr) {} //конструктор
};
