#include <iostream>

class Treenode{
    private:
        int index, value;
        Treenode* left;
        Treenode* right;

    public:
    Treenode(int index, int value)
        : index(index), value(value), left(nullptr), right(nullptr){}

    // Getters
    int getIndex() const { return index; }
    int getValue() const { return value; }
    Treenode* getLeft() const { return left; }
    Treenode* getRight() const { return right; }

    // Setters
    void setLeft(Treenode* node) { left = node; }
    void setRight(Treenode* node) { right = node; }
};

class SparseVector{
    private:
        Treenode* root;

        Treenode* insertRecursive(Treenode* node, int index, int value){
            if(node == nullptr){
                return new Treenode(index,value);
            }

            if(index < node->getIndex()){
                node->setLeft(insertRecursive(node->getLeft(), index, value));
            }
            else if(index > node->getIndex()){
                node->setRight(insertRecursive(node->getRight(), index, value));
            }

            return node;
        }

        int getValueRecursive(Treenode* node, int index){
            if(node == nullptr){
                return 0;
            }

            if(index < node->getIndex()){
                return getValueRecursive(node->getLeft(), index);
            }
            else if(index > node->getIndex()){
                return getValueRecursive(node->getRight(), index);
            }

            return node->getValue();
        }

        void displayRecursive(Treenode* node){
            if(node == nullptr){
                return;
            }

            displayRecursive(node->getLeft());
            std::cout << node->getIndex() << ":[ " << node->getValue() << " ]" << " ";
            displayRecursive(node->getRight());
        }

    public:
        SparseVector()
            : root(nullptr){}

        void insert(int index, int value){
            root = insertRecursive(root, index, value);
        }
        int getValue(int index){
            return getValueRecursive(root, index);
        }
        void display(){
            std::cout << "Sparse Vector: " << "\n";
            displayRecursive(root);
        }

};

int main(){
    SparseVector vector = SparseVector();
    vector.insert(1,1);
    vector.insert(2,2);
    vector.insert(3,3);
    vector.insert(4,4);
    vector.display();
    return 0;
}