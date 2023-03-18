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

    // добавление элемента в дерево
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

    // поиск элемента в дереве
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

    // прямой обход дерева
    void preorder_traversal(Node* node, void (*visit)(int)) const {
        if (node != nullptr) {
            visit(node->data);
            preorder_traversal(node->left, visit);
            preorder_traversal(node->right, visit);
        }
    }

    // обратный объод дерева
    void postorder_traversal(Node* node, void (*visit)(int)) const {
        if (node != nullptr) {
            postorder_traversal(node->left, visit);
            postorder_traversal(node->right, visit);
            visit(node->data);
        }
    }

    // минимальный элемент дерева
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

// вывод элемента в терминал
void print(int value) {
    cout << value << " ";
}

// вычисляем высоту дерева
int height(Node* root) {
    if (root == nullptr) {
        return -1; // пустое дерево имеет высоту -1
    }

    int left_height = height(root->left);
    int right_height = height(root->right);
    
    return max(left_height, right_height) + 1;
}

// Количество вершин дерева 
int TreeSize(Node* root) {
    if (root == NULL)
        return 0;
    return TreeSize(root->right) + TreeSize(root->left) + 1;
}

void Compare(int H, int _size) {
    cout << "В полученном дереве (высотой h=" << H;
    if (H < pow(2, H + 1) - 1) {
        cout << ") количество верщин = " << _size << ", это значение не превышает 2^(h+1)-1 = " << pow(2, H + 1) - 1 << endl;
    }
    else {
        cout << ") количество верщин = " << _size << ", это значение превышает 2^(h+1)-1 = " << pow(2, H + 1) - 1 << endl;
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

    cout << "Прямой обход: ";
    MyTree.preorder_traversal(MyTree.root, print); cout << endl;
   
    cout << "Обратный обход: ";
    MyTree.postorder_traversal(MyTree.root, print); cout << endl;

    int h = height(MyTree.root);
    cout << "Высота дерева: " << h << endl;

    Compare(h, size);

    int z = 7;
    cout << "Есть ли в дереве элемент " << z << "? Ответ: " << MyTree.search(z) << endl;

    cout << "Минимальный элемент дерева: " << MyTree.get_min() << endl;

    cout << endl; 
    cout << "Очистка памяти. Удаление дерева..." << endl;
    deleteTree(MyTree.root);
}