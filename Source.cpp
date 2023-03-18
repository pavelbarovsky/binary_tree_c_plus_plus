#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;
    BinarySearchTree() {
        root = nullptr;
    }

    // ���������� �������� � ������
    void add(int value) {
        if (root == nullptr) {
            root = new Node(value);
            return;
        }
        Node* current_node = root;
        while (true) {
            if (value < current_node->data) {
                if (current_node->left == nullptr) {
                    current_node->left = new Node(value);
                    break;
                }
                else {
                    current_node = current_node->left;
                }
            }
            else if (value > current_node->data) {
                if (current_node->right == nullptr) {
                    current_node->right = new Node(value);
                    break;
                }
                else {
                    current_node = current_node->right;
                }
            }
            else {
                break;
            }
        }
    }

    // ����� �������� � ������
    bool search(int value) const {
        Node* current_node = root;
        while (current_node != nullptr) {
            if (value < current_node->data) {
                current_node = current_node->left;
            }
            else if (value > current_node->data) {
                current_node = current_node->right;
            }
            else {
                return true;
            }
        }
        return false;
    }

    // ������ ����� ������
    void preorder_traversal(Node* node, void (*visit)(int)) const {
        if (node != nullptr) {
            visit(node->data);
            preorder_traversal(node->left, visit);
            preorder_traversal(node->right, visit);
        }
    }

    // �������� ����� ������
    void postorder_traversal(Node* node, void (*visit)(int)) const {
        if (node != nullptr) {
            postorder_traversal(node->left, visit);
            postorder_traversal(node->right, visit);
            visit(node->data);
        }
    }

    // ����������� ������� ������
    int get_min() const {
        Node* node = root;
        while (node && node->left) node = node->left;
        return node ? node->data : -1;
    }
};

void deleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// ����� �������� � ��������
void print(int value) {
    cout << value << " ";
}

// ��������� ������ ������
int height(Node* root) {
    if (root == nullptr) {
        return -1; // ������ ������ ����� ������ -1
    }

    int left_height = height(root->left);
    int right_height = height(root->right);
    
    return max(left_height, right_height) + 1;
}

// ���������� ������ ������ 
int TreeSize(Node* root) {
    if (root == NULL)
        return 0;
    return TreeSize(root->right) + TreeSize(root->left) + 1;
}

void Compare(int H, int _size) {
    cout << "� ���������� ������ (������� h=" << H;
    if (H < pow(2, H + 1) - 1) {
        cout << ") ���������� ������ = " << _size << ", ��� �������� �� ��������� 2^(h+1)-1 = " << pow(2, H + 1) - 1 << endl;
    }
    else {
        cout << ") ���������� ������ = " << _size << ", ��� �������� ��������� 2^(h+1)-1 = " << pow(2, H + 1) - 1 << endl;
    }
}



int main() {

    setlocale(LC_ALL, "ru");

    BinarySearchTree MyTree;
    MyTree.add(12);
    MyTree.add(19);
    MyTree.add(16);
    MyTree.add(10);
    MyTree.add(48);
    MyTree.add(55);
    MyTree.add(75);
    MyTree.add(61);
    MyTree.add(99);
    MyTree.add(90);

    int size = TreeSize(MyTree.root);

    cout << "������ �����: ";
    MyTree.preorder_traversal(MyTree.root, print); cout << endl;
   
    cout << "�������� �����: ";
    MyTree.postorder_traversal(MyTree.root, print); cout << endl;

    int h = height(MyTree.root);
    cout << "������ ������: " << h << endl;

    Compare(h, size);

    int z = 7;
    cout << "���� �� � ������ ������� " << z << "? �����: " << MyTree.search(z) << endl;

    cout << "����������� ������� ������: " << MyTree.get_min() << endl;

    cout << endl; 
    cout << "������� ������. �������� ������..." << endl;
    deleteTree(MyTree.root);
}