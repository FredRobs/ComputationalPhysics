#include <iostream>
#include <algorithm>

class Treenode{
    private:
        // Private attributes
        int index, value, height;
        Treenode* left;
        Treenode* right;

    public:
        // Public attributes
    Treenode(int index, int value)
        : index(index), value(value), height(1), left(nullptr), right(nullptr){}

    // Getters
    int getIndex() const {return index;}
    int getValue() const {return value;}
    int getHeight() const {return height;}
    Treenode* getLeft() const {return left;}
    Treenode* getRight() const {return right;}

    // Setters
    void setLeft(Treenode* node) { left = node; }
    void setRight(Treenode* node) { right = node; }
    void setHeight(int h){height = h;}
};

class BalancedSparseVector{
    private:
    // Private attributes
        Treenode* root;

        Treenode* insertRecursive(Treenode* node, int index, int value){
            // Recursively divides the tree into new sub treese
            if(node == nullptr){
                // Base case
                return new Treenode(index,value);
            }
            if(index < node->getIndex()){
                // Get left side of the tree
                node->setLeft(insertRecursive(node->getLeft(), index, value));
            }
            else if(index > node->getIndex()){
                // Get right side of the tree
                node->setRight(insertRecursive(node->getRight(), index, value));
            }
            // Return the node
            return node;
        }

        int getValueRecursive(Treenode* node, int index){
            if(node == nullptr){
                // Base case
                return 0;
            }
            if(index < node->getIndex()){
                // Gets the left side of the tree
                return getValueRecursive(node->getLeft(), index);
            }
            else if(index > node->getIndex()){
                // Gets the right side of the tree
                return getValueRecursive(node->getRight(), index);
            }
            // Returns the value of the node
            return node->getValue();
        }

        void displayRecursive(Treenode* node){
            // Recursive divides the tree into subtrees that then displays the values of the tree
            if(node == nullptr){
                // Base case
                return;
            }
            // Displays vector
            displayRecursive(node->getLeft());
            std::cout << node->getIndex() << ":[ " << node->getValue() << " ]" << " ";
            displayRecursive(node->getRight());
        }

    public:
        BalancedSparseVector()
            : root(nullptr){}

        void insert(int index, int value){
            // Insets a value at the index
            root = insertRecursive(root, index, value);
        }
        int getValue(int index){
            // Returns the value at the index
            return getValueRecursive(root, index);
        }
        void display(){
            // Calls display method
            std::cout << "Sparse Vector: " << "\n";
            displayRecursive(root);
        }

};

int main(){
    // Creates new sparse vector
    BalancedSparseVector vector = BalancedSparseVector();
    // Inserts new nodes to vector
    vector.insert(1,1);
    vector.insert(2,2);
    vector.insert(3,3);
    vector.insert(5,4);
    // Displays vector
    vector.display();
    return 0;
}