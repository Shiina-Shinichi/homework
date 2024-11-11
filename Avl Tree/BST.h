#ifndef BST_H
#define BST_H

#include <algorithm>
#include <iostream>
#include <utility>
#include <stdexcept>

class UnderflowException : public std::runtime_error {
public:
    UnderflowException() : std::runtime_error("Underflow Exception: Tree is empty") {}
};

template <typename Comparable>
class BinarySearchTree {
protected:
    struct BinaryNode {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;
        int height;

        BinaryNode(const Comparable &ele, BinaryNode *lt = nullptr, BinaryNode *rt = nullptr, int h = 0)
            : element{ele}, left{lt}, right{rt}, height{h} {}

        BinaryNode(Comparable &&ele, BinaryNode *lt = nullptr, BinaryNode *rt = nullptr, int h = 0)
            : element{std::move(ele)}, left{lt}, right{rt}, height{h} {}
    };

    BinaryNode *root;

    // 获取节点高度
    int height(BinaryNode *t) const {
        return t == nullptr ? -1 : t->height;
    }

    // 插入元素，递归并保持平衡
    void insert(const Comparable &x, BinaryNode *&t) {
        if (t == nullptr) {
            t = new BinaryNode{x, nullptr, nullptr, 0};
        } else if (x < t->element) {
            insert(x, t->left);
        } else if (x > t->element) {
            insert(x, t->right);
        }
        balance(t); // 插入后保持平衡
    }

    void insert(Comparable &&x, BinaryNode *&t) {
        if (t == nullptr) {
            t = new BinaryNode{std::move(x), nullptr, nullptr, 0};
        } else if (x < t->element) {
            insert(std::move(x), t->left);
        } else if (x > t->element) {
            insert(std::move(x), t->right);
        }
        balance(t);
    }

    // 删除节点，保持平衡
    void remove(const Comparable &x, BinaryNode *&t) {
        if (t == nullptr) return;  // 节点不存在

        if (x < t->element) {
            remove(x, t->left);
        } else if (x > t->element) {
            remove(x, t->right);
        } else if (t->left != nullptr && t->right != nullptr) {  // 双子节点
            BinaryNode *minNode = findMin(t->right);
            t->element = std::move(minNode->element);
            remove(t->element, t->right);
        } else {  // 单子节点或叶子节点
            BinaryNode *oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
        balance(t);  // 删除后保持平衡
    }

    // 查找树中最小元素
    BinaryNode *findMin(BinaryNode *t) const {
        if (t == nullptr) return nullptr;
        while (t->left != nullptr) t = t->left;
        return t;
    }

    // 平衡树
    void balance(BinaryNode *&t) {
        if (t == nullptr) return;

        if (height(t->left) - height(t->right) > 1) {  // 左重
            if (height(t->left->left) >= height(t->left->right))
                rotateWithLeftChild(t);  // LL
            else
                doubleWithLeftChild(t);  // LR
        } else if (height(t->right) - height(t->left) > 1) {  // 右重
            if (height(t->right->right) >= height(t->right->left))
                rotateWithRightChild(t);  // RR
            else
                doubleWithRightChild(t);  // RL
        }

        // 更新高度
        t->height = 1 + std::max(height(t->left), height(t->right));
    }

    // 左旋转
    void rotateWithLeftChild(BinaryNode *&k2) {
        BinaryNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = 1 + std::max(height(k2->left), height(k2->right));
        k1->height = 1 + std::max(height(k1->left), height(k1->right));
        k2 = k1;
    }

    // 右旋转
    void rotateWithRightChild(BinaryNode *&k1) {
        BinaryNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = 1 + std::max(height(k1->left), height(k1->right));
        k2->height = 1 + std::max(height(k2->left), height(k2->right));
        k1 = k2;
    }

    // 左右双旋转
    void doubleWithLeftChild(BinaryNode *&k3) {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    // 右左双旋转
    void doubleWithRightChild(BinaryNode *&k1) {
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }

public:
    BinarySearchTree() : root{nullptr} {}

    ~BinarySearchTree() {
        makeEmpty(root);
    }

    void insert(const Comparable &x) {
        insert(x, root);
    }

    void insert(Comparable &&x) {
        insert(std::move(x), root);
    }

    void remove(const Comparable &x) {
        remove(x, root);
    }

    void printTree() const {
        if (root == nullptr) {
            std::cout << "Empty tree" << std::endl;
        } else {
            printTree(root);
            std::cout << std::endl;
        }
    }

private:
    // 清空树
    void makeEmpty(BinaryNode *&t) {
        if (t != nullptr) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            t = nullptr;
        }
    }

    // 中序打印
    void printTree(BinaryNode *t) const {
        if (t != nullptr) {
            printTree(t->left);
            std::cout << t->element << " ";
            printTree(t->right);
        }
    }
};

#endif // BST_H
