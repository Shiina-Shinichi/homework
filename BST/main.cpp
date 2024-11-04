#include <iostream>
#include "BinarySearchTree.h"

int main() {
    BinarySearchTree<int> bst;

    // 插入测试数据
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Initial tree (In-order): ";
    bst.printTree();
    std::cout << std::endl;

    // 测试删除叶子节点
    std::cout << "Removing leaf node 20: ";
    bst.remove(20);
    bst.printTree();
    std::cout << std::endl;

    // 测试删除只有一个子节点的节点
    std::cout << "Removing node with one child 30: ";
    bst.remove(30);
    bst.printTree();
    std::cout << std::endl;

    // 测试删除具有两个子节点的节点
    std::cout << "Removing node with two children 50: ";
    bst.remove(50);
    bst.printTree();
    std::cout << std::endl;

    // 测试删除不存在的节点
    std::cout << "Attempting to remove non-existing node 90: ";
    bst.remove(90);
    bst.printTree();
    std::cout << std::endl;

    // 测试边界情况：删除树的所有节点
    std::cout << "Removing remaining nodes to empty the tree: ";
    bst.remove(40);
    bst.remove(60);
    bst.remove(70);
    bst.remove(80);
    bst.printTree();
    std::cout << " (Tree should be empty)" << std::endl;

    return 0;
}