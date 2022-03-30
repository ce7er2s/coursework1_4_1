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
        uint32_t count = 0;

    public:
        Node () = default;
        Node (KEY _key, ITEM _item): key(_key), item(_item), count(1) {
            ;
        }

        void insert(const std::string new_key, const std::string new_item) {
            char pos = key.compare(new_key);
            if (pos == -1) { //  если ключ меньше текущего значения, сливаем его влево
                if (left != nullptr) { // выделяем новый узел, если его нет, либо рекурсивно отдаем его
                    left->insert(new_key, new_item);
                } else {
                    left = new Node(new_key, new_item);
                }
            } else if (pos == 1) { // аналогично вправо
                if (right != nullptr) {
                    right->insert(new_key, new_item);
                } else {
                    right = new Node(new_key, new_item);
                }
            } else { // если текущий ключ узла равен новому ключу, прибавляем 1
                ++count;
            }
        }

        ITEM search(const std::string& search_key) {
            char pos = key.compare(search_key);
            if (pos == 0) {
                return key;
            } else if (pos == -1) {
                if (left != nullptr) {
                    return left->search(search_key);
                } else {
                    return "";
                }
            } else {
                if (right != nullptr) {
                    return right->search(search_key);
                } else {
                    return "";
                }
            }
        }
    };

    Node* head;
    size_t size;

public:
    BinaryTree () = default;// стандартная инициализация

    BinaryTree (KEY key, ITEM item) {
        head = new BinaryTree::Node(key, item);
        size = 1;
    }; // конструктор создания словаря из одной пары значений

    BinaryTree (const BinaryTree& tree) = default;

    BinaryTree (BinaryTree&& tree) noexcept = default;

    inline void insert (const std::string key, const std::string item) {
        head->insert(key, item);
        ++size;
    }

    inline ITEM search (const std::string& search_key) {
        return head->search(search_key);
    }
};

#endif //COURSEWORK1_4_1_BINARYTREE_H