#include <iostream>
using namespace std;

// GENERIC NODE CLASS
template <typename T>
class Node{
public:
    T data;
    Node<T>* right;
    Node<T>* left;

    Node(T value){
        this->data=value;
        right=nullptr;
        left=nullptr;
    }
};

// GENERIC TREE CLASS
template <typename T>
class BST{
private:
    Node<T>* root;
    void printInOrder(Node<T>* ptr){
        if (ptr==nullptr) return;
        printInOrder(ptr->left);
        cout<<ptr->data<<" ";
        printInOrder(ptr->right);
    }

    void printPostOrder(Node<T>* ptr){
        if (ptr==nullptr) return;
        printPostOrder(ptr->left);
        printPostOrder(ptr->right);
        cout<<ptr->data<<" ";
    }

    void printPreOrder(Node<T>* ptr){
        if (ptr==nullptr) return;
        cout<<ptr->data<<" ";
        printPreOrder(ptr->left);
        printPreOrder(ptr->right);
    }

    void printLevelOrder(Node<T>* root){
        if (root==nullptr) return;
        queue<Node<T>*> Q;
        Q.push(root);
        while (!Q.empty()){
            Node* curr=Q.front();
            Q.pop();
            if (curr==nullptr){
                if (!Q.empty()) {
                    Q.push(nullptr);
                    continue;
                }else{
                    break;
                }
            }
            cout<<curr->data<<" ";
            if (curr->left!=nullptr) Q.push(curr->left);
            if (curr->right!=nullptr) Q.push(curr->right);
        }
    }

    Node<T>* search(Node<T>* ptr,T key){
        if (ptr==nullptr) return ptr;
        if (ptr->data==key) return ptr;
        if (key<ptr->data){
            return search(ptr->left,key);
        }else{
            return search(ptr->right,key);
        }
    }

    void destroyTree(Node<T>* ptr){
        if (ptr==nullptr) return;
        destroyTree(ptr->left);
        destroyTree(ptr->right);
        delete ptr;
    }

public:
    // ============== CONSTRUCTOR =============
    BST(){
        root=nullptr;
    }
    // ============== DESTRUCTOR ============== 
    ~BST(){
        destroyTree(root);
    }

    // ============== INSERTIONS ==============
    // 1. ITERATIVE
    void insertNode(T value){
        Node<T>* newNode=new Node(value);
        // 1. Empty Tree
        if (root==nullptr){
            root=newNode;
            return;
        }
        // 2. Non-Empty Tree
        Node<T>* prev=nullptr;
        Node<T>* ptr=root;
        while (ptr!=nullptr){
            prev=ptr;
            if  (value<ptr->data){
                ptr=ptr->left;
            }else{
                ptr=ptr->right;
            }
        }
        // we have reached a leaf bc loop exits at nullptr
        if (value<prev->data){
            prev->left=newNode;
        }else{
            prev->right=newNode;
        }
    }

    // 2. RECURSIVE
    Node<T>* insertRecursive(Node<T>* node,T value){
        if (node==nullptr){
            return new Node<T>(value);
        }

        if (value<node->data){
            node->left=insertRecursive(node->left,value);
        }else{
            node->right=insertRecursive(node->right,value);
        }
        return node;
    }

    // =============== TRAVERSALS ==============
    void inOrder(){
        printInOrder(root);
    }
    void postOrder(){
        printPostOrder(root);
    }
    void preOrder(){
        printPreOrder(root);
    }

    // ============== DELETIONS ================
    void deleteNode(T value){
        Node<T>* ptr=root;
        Node<T>* prev=nullptr;
        while (ptr!=nullptr && ptr->data!=value){
            prev=ptr;
            if  (value<ptr->data){
                ptr=ptr->left;
            }else{
                ptr=ptr->right;
            }
        }
        if (ptr==nullptr) return;
        // LEAF CASE
        if (ptr->left==nullptr && ptr->right==nullptr){
            if (ptr == root) {
                root = nullptr;
            }
            else if (prev->left == ptr)
                prev->left = nullptr;
            else
                prev->right = nullptr;
            delete ptr;
            return;
        }
        // ONE CHILD CASE
        if (ptr->left==nullptr || ptr->right==nullptr){
            Node<T>* child=(ptr->left)?ptr->left:ptr->right;
            if (ptr==root){
                root=child;
            }
            else if (prev->left==ptr){
                prev->left=child;
            }
            else{
                prev->right=child;
            }
            delete ptr;
            return;
        }

        // TWO CHILD CASE
        Node<T>* successorParent=ptr;
        Node<T>* successor=ptr->right;
        while (successor->left!=nullptr){
            successorParent=successor;
            successor=successor->left;
        }
        ptr->data = successor->data;
        if (successorParent->left == successor)
            successorParent->left = successor->right;
        else
            successorParent->right = successor->right;

        delete successor;
    }

    // ============= SEARCH =============
    Node<T>* searchNode(T key){
        return search(root,key)
    }

    
    // ============= PRINT EXTREMES ===========
    void printSmallestValue(){
        Node<T>* ptr=root;
        while (ptr->left!=nullptr){
            ptr=ptr->left;
        }
        cout<<"Smallest Value: "<<ptr->data<<endl;
    }

    void printLargestValue(){
        Node<T>* ptr=root;
        while (ptr->right!=nullptr){
            ptr=ptr->right;
        }
        cout<<"Largest Value: "<<ptr->data<<endl;
    }
};
int main(){
    // DESIGN MENU MENTIONED IN MANUAL
    BST<int> tree;
    int choice, value;

do {
    cout << "\n======= Main Menu =======\n";
    cout << "1. Insert new data\n";
    cout << "2. In-Order Traversal\n";
    cout << "3. Pre-Order Traversal\n";
    cout << "4. Post-Order Traversal\n";
    cout << "5. Delete an item\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insertNode(value);
            cout << "Value inserted successfully.\n";
            break;

        case 2:
            cout << "In-Order Traversal: ";
            tree.inOrder();
            cout << "\n";
            break;

        case 3:
            cout << "Pre-Order Traversal: ";
            tree.preOrder();
            cout << "\n";
            break;

        case 4:
            cout << "Post-Order Traversal: ";
            tree.postOrder();
            cout << "\n";
            break;

        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.deleteNode(value);
            cout << "Deletion complete.\n";
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
    }
} while (choice != 6);

return 0;

}