#include "List.h"  
#include <iostream>  
#include <string>  
  
using namespace std;  
  
template<typename T>  
void printList(const List<T>& list) {  
    cout << "List contents: ";  
    if (list.empty()) {  // 添加安全检查  
        cout << "empty" << endl;  
        return;  
    }  
    for (auto it = list.begin(); it != list.end(); ++it) {  
        cout << *it << " ";  
    }  
    cout << endl;  
}  //这里确保了printList不会尝试访问空的或无效的列表！
  
int main() {  
    // 测试默认构造函数  
    List<int> intList;  
    cout << "Testing default constructor: ";  
    printList(intList);  // 应显示空列表  
  
    // 测试 push_back 和 push_front  
    intList.push_back(1);  
    intList.push_front(0);  
    intList.push_back(2);  
    cout << "Testing push_back and push_front: ";  
    printList(intList);  // 应显示 0 1 2  
  
    // 测试拷贝构造函数  
    List<int> copyList(intList);  
    cout << "Testing copy constructor: ";  
    printList(copyList);  // 应显示 0 1 2  
  
    // 测试移动构造函数  
    List<int> movedList(std::move(copyList));  
    cout << "Testing move constructor (original should be empty): ";  
    printList(movedList);  // 应显示 0 1 2  
    printList(copyList);   // 应显示空  
  
    // 测试赋值运算符  
    List<int> assignedList ; 
    assignedList = movedList;  
    cout << "Testing assignment operator: "; 
    printList(assignedList);  // 应显示 0 1 2 
  
    // 测试移动赋值  
    List<int> movedAssignList;  
    movedAssignList = std::move(assignedList);  
    cout << "Testing move assignment (original should be empty): ";  
    printList(movedAssignList);  // 应显示 0 1 2  
    printList(assignedList);     // 应显示空  
  
    // 测试 initializer_list 构造函数  
    List<string> stringList = {"Hello", "World"};  
    cout << "Testing initializer_list constructor: ";  
    printList(stringList);  // 应显示 Hello World  
  
    // 测试 insert  
    auto it = stringList.begin();  
    ++it;  
    stringList.insert(it, "there");  
    cout << "Testing insert: ";  
    printList(stringList);  // 应显示 Hello there World  
  
    // 安全测试 erase  
    if (!stringList.empty()) {  
        it = stringList.begin();  
        ++it;  
        stringList.erase(it);  
        cout << "Testing erase: ";  
        printList(stringList);  // 应显示 Hello World  
    }  
  
    // 安全测试 pop_back and pop_front  
    if (!stringList.empty()) {  
        stringList.pop_back();  
    }  
    if (!stringList.empty()) {  
        stringList.pop_front();  
    }  
    cout << "Testing pop_back and pop_front: ";  
    printList(stringList);  // 应显示空  
  
    // 测试 size and empty  
    cout << "Testing size and empty: Size = " << stringList.size() << ", Is Empty = " << (stringList.empty() ? "Yes" : "No") << endl;  
  
    // 测试 clear  
    stringList.clear();  
    cout << "Testing clear: ";  
    printList(stringList);  // 应显示空  
  
    // Ensure all is well  
    if (stringList.empty()) {  
        cout << "All tests passed successfully." << endl;  
    } else {  
        cout << "Some tests failed." << endl;  
    }  
  
    return 0;  
}  