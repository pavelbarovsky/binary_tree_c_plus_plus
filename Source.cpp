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

    // adding an element to the tree
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

    // search for an element in the tree
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

    // preorder tree traversal
    void preorder_traversal(Node* node, void (*visit)(int)) const {
        if (node != nullptr) {
            visit(node->data);
            preorder_traversal(node->left, visit);
            preorder_traversal(node->right, visit);
        }
    }

    // pastorder tree traversal
    void postorder_traversal(Node* node, void (*visit)(int)) const {
        if (node != nullptr) {
            postorder_traversal(node->left, visit);
            postorder_traversal(node->right, visit);
            visit(node->data);
        }
    }

    // minimum element of the tree
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

// output element to the terminal
void print(int value) {
    cout << value << " ";
}

// calculate the height of the tree
int height(Node* root) {
    if (root == nullptr) {
        return -1; // empty tree has height -1
    }

    int left_height = height(root->left);
    int right_height = height(root->right);
    
    return max(left_height, right_height) + 1;
}

// Number of tree vertices
int TreeSize(Node* root) {
    if (root == NULL)
        return 0;
    return TreeSize(root->right) + TreeSize(root->left) + 1;
}

void Compare(int H, int _size) {
     cout << "In the resulting tree (height h=" << H;
     if (H < pow(2, H + 1) - 1) {
         cout << ") number of vertices = " << _size << ", this value does not exceed 2^(h+1)-1 = " << pow(2, H + 1) - 1 << endl;
     }
     else {
         cout << ") number of vertices = " << _size << ", this value is greater than 2^(h+1)-1 = " << pow(2, H + 1) - 1 << endl;
     }
}



int main() {

     setlocale(LC_ALL, "ru");

     BinarySearchTreeMyTree;
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

     cout << "Direct bypass: ";
     MyTree.preorder_traversal(MyTree.root, print); cout << endl;
   
     cout << "Reverse traversal: ";
     MyTree.postorder_traversal(MyTree.root, print); cout << endl;

     int h = height(MyTree.root);
     cout << "Tree height: " << h << endl;

     compare(h, size);

     int z = 7;
     cout << "Is there an element " << z << " in the tree? Answer: " << MyTree.search(z) << endl;

     cout << "Minimum element of the tree: " << MyTree.get_min() << endl;

     cout << endl;
     cout << "Clearing memory. Deleting tree..." << endl;
     deleteTree(MyTree.root);
}