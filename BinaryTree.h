//
// Created by Foko on 30.03.2022.
//

#ifndef COURSEWORK1_4_1_BINARYTREE_H
#define COURSEWORK1_4_1_BINARYTREE_H

#include <string>

template <typename KEY, typename ITEM> class BinaryTree {
private:
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        KEY key;
        ITEM item;

    private:
        bool addPair(const std::string key, const std::string item) {

        }
    };

    Node* head;
    size_t size;

    BinaryTree(); // стандартная инициализация

    BinaryTree(KEY key, ITEM item); // конструктор создания словаря из одной пары значений

    BinaryTree(const BinaryTree& tree) = default;

    BinaryTree(BinaryTree&& tree) noexcept = default;

    bool addPair (const std::string key, const std::string item) {
        return head->addPair(key, item)
    }
};

#endif //COURSEWORK1_4_1_BINARYTREE_H