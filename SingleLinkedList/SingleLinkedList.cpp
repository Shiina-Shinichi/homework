#include <iostream>  
#include <initializer_list>  
#include <stdexcept>  
#include <iomanip> // 包含对输出格式控制的库
  
template <typename T>  
class SingleLinkedList  
{  
private:  
    class Node  
    {  
    public:  
        T data;  
        Node *next = nullptr;  
        Node(T _val) : data(_val), next(nullptr) {}  
    };  
  
    Node* head = nullptr;  
    Node* currentPos = nullptr;  
    int size = 0;  
  
    void _emptyList();  
    void _copy(const SingleLinkedList<T> &_l);  
  
public:  
    SingleLinkedList() : head(nullptr), currentPos(nullptr), size(0) {}  
    SingleLinkedList(std::initializer_list<T> _l);  
    SingleLinkedList(const SingleLinkedList<T> &_l);  
    ~SingleLinkedList();  
    SingleLinkedList<T>& operator=(const SingleLinkedList<T> &_l);  
  
    T getCurrentVal() const;  
    void setCurrentVal(const T &_val);  
    bool isEmpty() const;  
    void insert(T _val);  
    void remove();  
    void emptyList();  
    int getSize() const;  
    bool find(const T &_val);  
    void printList() const;  
};  
  
template<typename T>  
T SingleLinkedList<T>::getCurrentVal() const {  
    if (currentPos == nullptr) {  
        throw std::runtime_error("Empty current position! Can't get value!");  
    }  
    return currentPos->data;  
}  
  
template<typename T>  
void SingleLinkedList<T>::setCurrentVal(const T &_val) {  
    if (currentPos == nullptr) {  
        throw std::runtime_error("Empty current position! Can't set value!");  
    }  
    currentPos->data = _val;  
}  
  
template<typename T>  
bool SingleLinkedList<T>::isEmpty() const {  
    return head == nullptr;  
}  
  
template<typename T>  
void SingleLinkedList<T>::insert(T _val) {  
    Node* newNode = new Node(_val);  
    if (head == nullptr) {  
        // If the list is empty, initialize it with the new node.  
        head = newNode;  
        currentPos = newNode;  
    } else {  
        // Insert the new node right after the current position.  
        newNode->next = currentPos->next;  
        currentPos->next = newNode;  
        // Update currentPos to the newly inserted node  
        currentPos = newNode;  
    }  
    ++size;  
}     
  
template<typename T>  
void SingleLinkedList<T>::remove() {  
    if (currentPos == nullptr) {  
        // If currentPos is null, do nothing.  
        return;  
    }  
    if (head == currentPos && currentPos->next == nullptr) {  
        // If there's only one element in the list.  
        delete head;  
        head = nullptr;  
        currentPos = nullptr;  
        size = 0;  
    } else if (currentPos->next != nullptr) {  
        // If there's more than one element and currentPos is not the last node.  
        Node* temp = currentPos->next;  
        currentPos->next = temp->next;  
        delete temp;  
        size--;  
        
    }  
    // If currentPos is the last node, do nothing.  
}        
  
template<typename T>  
void SingleLinkedList<T>::_emptyList() {  
    Node* p = head;  
    while (p != nullptr) {  
        Node* t = p;  
        p = p->next;  
        delete t;  
    }  
    head = nullptr;  
    currentPos = nullptr;  
    size = 0;  
}  
  
template<typename T>  
void SingleLinkedList<T>::emptyList() {  
    _emptyList();  
}  
  
template<typename T>  
int SingleLinkedList<T>::getSize() const {  
    return size;  
}  
  
template<typename T>  
bool SingleLinkedList<T>::find(const T &_val) {  
    Node *p = head;  
    while (p != nullptr) {  
        if (p->data == _val) {  
            currentPos = p;  
            return true;  
        }  
        p = p->next;  
    } 
    currentPos = nullptr; // 未找到时重置currentPos 
    return false;  
}  
   
  
template<typename T>  
void SingleLinkedList<T>::printList() const {  
    Node* p = head;  
    while (p != nullptr) {  
        std::cout << std::fixed << std::setprecision(1) << p->data << " "; // Format output to one decimal place  
        p = p->next;  
    }  
    std::cout << std::endl;  
}  
  
template<typename T>  
SingleLinkedList<T>::SingleLinkedList(std::initializer_list<T> _l) {  
    for (auto& val : _l) {  
        insert(val);  
    }  
}  
  
template<typename T>  
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T> &_l) {  
    _copy(_l);  
}  
  
template<typename T>  
SingleLinkedList<T>::~SingleLinkedList() {  
    _emptyList();  
}  
  
template<typename T>  
SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList<T> &_l) {  
    if (this != &_l) {  
        emptyList();  
        _copy(_l);  
    }  
    return *this;  
}  
  
template<typename T>  
void SingleLinkedList<T>::_copy(const SingleLinkedList<T> &_l) {  
    Node* p = _l.head;  
    Node* last = nullptr;  
    while (p != nullptr) {  
        Node* newNode = new Node(p->data);  
        if (last == nullptr) {  
            head = newNode;  
        } else {  
            last->next = newNode;  
        }  
        last = newNode;  
        if (p == _l.currentPos) {  
            currentPos = newNode;  
        }  
        p = p->next;  
        ++size;  
    }  
}  
  
int main() {  
    // Test cases provided in the original problem statement  
    SingleLinkedList<int> a{1, 2, 3, 4, 5};  
    int a_get = a.getCurrentVal();  
    std::cout << a_get << std::endl;  
  
    SingleLinkedList<char> b{'a', 'c', 'e'};  
    b.setCurrentVal('g');  
    b.printList();  
  
    SingleLinkedList<char> e;  
    std::cout << b.isEmpty() << " " << e.isEmpty() << std::endl;  
  
    SingleLinkedList<double> c1;  
    SingleLinkedList<double> c2{1.5, 2.0, 9.0, 4.7};  
    SingleLinkedList<double> c3;  
    c3 = c2;  
    c1.insert(3.0);  
    c2.insert(8.8);  
    bool f_c3 = c3.find(2.0);  
    c3.insert(8.8);  
    c1.printList();  
    c2.printList();  
    c3.printList();  
  
    e.remove();  
    c1.remove();  
    bool f = c2.find(9.0);  
    c2.remove();  
    e.printList();  
    c1.printList();  
    c2.printList();  
  
    return 0;  
}  