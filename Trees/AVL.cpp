#include <iostream>
using namespace std;
// GENERIC NODE CLASS  
template <typename T>
class Node{
public:
    T data;
    Node<T>* right;
    Node<T>* left;
    int height;

    Node(T value){
        this->data=value;
        right=nullptr;
        left=nullptr;
        height=0;
    }
};

template <typename T>
class AVL{
private:
    Node<T>* root;
    // LEFT NODE RIGHT
    void printInOrder(Node<T>* ptr){
        if (ptr==nullptr) return;
        printInOrder(ptr->left);
        cout<<ptr->data<<" ";
        printInOrder(ptr->right);
    }

    // LEFT RIGHT NODE
    void printPostOrder(Node<T>* ptr){
        if (ptr==nullptr) return;
        printPostOrder(ptr->left);
        printPostOrder(ptr->right);
        cout<<ptr->data<<" ";
    }

    // NODE LEFT RIGHT
    void printPreOrder(Node<T>* ptr){
        if (ptr==nullptr) return;
        cout<<ptr->data<<" ";
        printPreOrder(ptr->left);
        printPreOrder(ptr->right);
    }

    void destroyTree(Node<T>* ptr){
        if (ptr==nullptr) return;
        destroyTree(ptr->left);
        destroyTree(ptr->right);
        delete ptr;
    }

    int height(Node<T>* node){
        if (node==nullptr) return -1;
        return node->height;            
    }

    Node<T>* leftRotate(Node<T>* problemNode){
        Node<T>* right=problemNode->right;
        Node<T>* subtree=right->left;
        // ROTATION
        right->left=problemNode;
        problemNode->right=subtree;

        // UPDATE HEIGHTS
        problemNode->height=1+max(height(problemNode->left),height(problemNode->right));
        right->height=1+max(height(right->left),height(right->right));
        
        // RETURN NEW ROOT
        return right;
    }

    Node<T>* rightRotate(Node<T>* problemNode){
        Node<T>* left=problemNode->left;
        Node<T>* subtree=left->right;
        // ROTATION
        left->right=problemNode;
        problemNode->left=subtree;

        // UPDATE HEIGHTS
        problemNode->height=1+max(height(problemNode->left),height(problemNode->right));
        left->height=1+max(height(left->left),height(left->right));
            
        // RETURN NEW ROOT
        return left;
    }

    Node<T>* insertRecursive(Node<T>* node,T value){  
        // 1. BST INSERT
        if (node==nullptr){
            return new Node<T>(value);
        }
        if (value<node->data){
            node->left=insertRecursive(node->left,value);
        }else{
            node->right=insertRecursive(node->right,value);
        }
        // 2. UPDATE HEIGHT
        node->height=1+max(height(node->left),height(node->right));
        // 3. COMPUTE BALANCE
        int balance=height(node->left)-height(node->right);
        // 4. DETECT IMBALANCE & ROTATE
        //  4.1 LL
        if (balance>1 && value<node->left->data){
            return rightRotate(node);
        //  4.2 RR
        }else if (balance<-1 && value>node->right->data){
            return leftRotate(node);
        // 4.3 LR
        }else if (balance>1 && value>node->left->data){
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }else if (balance<-1 && value<node->right->data){
            node->right=rightRotate(node->right);
            return leftRotate(node);
        }   
        return node;
    }


    Node<T>* rebalance(Node<T>* node) {
        if (node == nullptr) return node;

        // Update height
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = height(node->left) - height(node->right);

        // LEFT HEAVY
        if (balance > 1) {
            if (height(node->left->left) >= height(node->left->right))
                return rightRotate(node);              // LL Case
            else {
                node->left = leftRotate(node->left);   // LR Case
                return rightRotate(node);
            }
        }

        // RIGHT HEAVY
        else if (balance < -1) {
            if (height(node->right->right) >= height(node->right->left))
                return leftRotate(node);               // RR Case
            else {
                node->right = rightRotate(node->right); // RL Case
                return leftRotate(node);
            }
        }

        return node;
    }
    Node<T>* minValueNode(Node<T>* node) {
        Node<T>* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    int getBalance(Node<T>* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node<T>* deleteAVL(Node<T>* node, T value) {
        // Base case
        if (node == nullptr) return nullptr;
        
        // Search for node to delete
        if (value < node->data) {
            node->left = deleteAVL(node->left, value);
        } else if (value > node->data) {
            node->right = deleteAVL(node->right, value);
        } else {
            // Node to delete found
            // Cases 1 & 2: Node with 0 or 1 child
            if (node->left == nullptr || node->right == nullptr) {
                Node<T>* temp = node->left ? node->left : node->right;

                // No child case
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else { // One child case
                    *node = *temp; // Copy contents
                }
                delete temp;
            } else {
                // Case 3: Node with 2 children
                Node<T>* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteAVL(node->right, temp->data);
            }
        }
        // If tree had only one node
        if (node == nullptr) return nullptr;

        // Update height
        node->height = 1 + max(height(node->left), height(node->right));

        // Get balance factor
        int balance = getBalance(node);

        // Balance the tree
        // Left Left Case
        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);

        // Left Right Case
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);

        // Right Left Case
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
public:
    // Constructor
    AVL(){
        root=nullptr;
    }
    // Destructor
    ~AVL(){
        destroyTree(root);
    }

    void insert(T value){
        root=insertRecursive(root,value);
    }

    void inOrder(){
        printInOrder(root);
    }

    void postOrder(){
        printPostOrder(root);
    }
    
    void preOrder(){
        printPreOrder(root);
    }

    void deleteNode(T value) {
        root = deleteAVL(root, value);
    }

};