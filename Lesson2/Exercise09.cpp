#include <iostream>

struct node {
    int data;
    node* left;
    node* right;
};

struct bst {
    node* root = nullptr;

    node* find(int value) {
        return find_impl(root, value);
    }

    void insert(int value) {
        if (!root)
            root = new node { value, NULL, NULL };
        else
            insert_impl(root, value);
    }

    void inorder() {
        inorder_impl(root);
    }

    node* successor(node* start) {
        auto current = start->right;
        while (current && current->left)
            current = current->left;
        return current;
    }

    void deleteValue(int value) {
        root = delete_impl(root, value);
    }

private: 
    node* find_impl(node* current, int value) {
        if (!current) {
            std::cout << std::endl;
            return NULL;
        }

        if (current->data == value) {
            std::cout << value << "을(를) 찾았습니다. " << std::endl;
            return current;
        }

        if (value < current->data) {
            std::cout << current->data << "에서 왼쪽으로 이동: ";
            return find_impl(current->left, value);
        }

        std::cout << current->data << "에서 오른쪽으로 이동: ";
        return find_impl(current->right, value);
    }

    void insert_impl(node* current, int value) {
        if (value < current->data) {
            if (!current->left)
                current->left = new node { value, NULL, NULL };
            else
                insert_impl(current->left, value);
        } else {
            if (!current->right)
                current->right = new node { value, NULL, NULL };
            else
                insert_impl(current->right, value);
        }
    }

    void inorder_impl(node* start) {
        if (!start)
            return;

        inorder_impl(start->left);
        std::cout << start->data << " ";
        inorder_impl(start->right);
    }

    //TODO 이해가 좀 안됨... 
    node* delete_impl(node* start, int value) {
        if (!start)
            return NULL;

        if (value < start->data)
            start->left = delete_impl(start->left, value);
        else if (value > start->data)
            start->right = delete_impl(start->right, value);
        else {
            if (!start->left) {
                auto tmp = start->right;
                delete start;
                return tmp;
            }

            if (!start->right) {
                auto tmp = start->left;
                delete start;
                return tmp;
            }

            auto succNode = successor(start);
            start->data = succNode->data;

            start->right = delete_impl(start->right, succNode->data);
        }

        return start;
    }
};

int main() {
    bst tree;
    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);

    std::cout << "중위 순회: ";
    tree.inorder();
    std::cout << std::endl;

    tree.deleteValue(12);
    std::cout << "12를 삭제한 후 중위 순회: ";
    tree.inorder();
    std::cout << std::endl;

    if (tree.find(12))
        std::cout << "원소 12는 트리에 있습니다." << std::endl;
    else 
        std::cout << "원소 12는 트리에 없습니다." << std::endl;
}