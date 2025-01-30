#include <iostream>
const int MAXSIZE = 100;

class Node{
    // Node class
    public:
        // Public attributes
        double data;
        int Row;
        int Col;
        Node *next;
    
    Node(){
        // Constructor
        data = 0;
        next = NULL; 
    }

    Node(double data, int Col, int Row){
        this->Col = Col;
        this->Row = Row;
        this->data = data;
        this->next = NULL;
    }
};


class LinkedList{
    private:
        // Private attributes
        Node *head;

    public:
        // Public attributes
        LinkedList(){
            // Constructor
            head = NULL;
        }

        void checkEmpty(Node *head){
            // Checks if node is empty
            if(head==NULL){
                // Displays if empty
                std::cout<< "List is empty";
                return;
            }
        }
    
        void addHead(double data){
            // Adds data to the head of the linked list
            Node *newInsertNode = new Node(data,1,1); 
            newInsertNode->next = this->head;
            this->head = newInsertNode;
        } 

        void removeHead(){
            // Removes the current head of the linked list
            Node *newRemoveNode = head;
            head = head->next;
            delete newRemoveNode;
        }

        void addTail(double data){
            //Adds a tail to the linked list
            Node *newInsertNode = new Node(data,1,1);   
            newInsertNode->next = NULL;

            Node *lastValue = head;

            // Traverse linked list to the end
            while(lastValue->next){
                lastValue = lastValue->next;
            }
            // Insert Node
            lastValue->next = newInsertNode;
        }

        void removeTail(){
            // Remove currrent tail node
            Node *newRemoveNode = head;

            // Traverse linked list to the end
            while(newRemoveNode->next->next){
                newRemoveNode = newRemoveNode->next;
            }

            // Remove final node
            delete newRemoveNode->next;
        }

        void addGeneralNode(double data, int position){
            // Add a node to the linked list at a certain position
            Node *newInsertNode = new Node(data, 1, 1);  

            Node *checkNode = head;

            // Search for the position in the linked list
            for(int i = 1; i<position - 1; i++){
                checkNode = checkNode->next;
            }    

            newInsertNode->next = checkNode->next;
            checkNode->next = newInsertNode;
        }

        void removeGeneralNode(int position){
            // Remove a node to the linked list at a certain position
            Node *newRemoveNode = head;
            
            // Search for the position in the linked list
            for(int i = 1; i<position - 1; i++){
                newRemoveNode = newRemoveNode->next;
            }

            // Remove this specific node
            Node *deleteNode = newRemoveNode->next;
            newRemoveNode->next = newRemoveNode->next->next;
            delete deleteNode;
        }

        void displayLinkedList(){
            // Displays linked list
            Node *displayNode = head;

            // Check linked list is not empty
            checkEmpty(displayNode);
            
            // While linked list is not empty display each of the values one after another
            while (displayNode != NULL){
                std::cout << displayNode->data << " ";
                displayNode = displayNode->next;
            }
        }

        void addElementToMatrix(double data, int Row, int Col){
            // Create new node
            Node*insetNode = new Node(data,Col,Row);
            //Check if the new node is before the current head
            if(head==NULL|| (head->Row > Row || (head->Row == Row && head->Col > Col))) {
                insetNode->next = head;
                head = insetNode;
                return;
                // Head = new node
            }
            // Otherwise traverse list to find position
            Node *currentNode = head;
            while(currentNode->next != NULL && (currentNode->next->Row < Row || 
                (currentNode->next->Row == Row && currentNode->next->Col < Col))) {
                    currentNode = currentNode->next;
                }
                insetNode->next = currentNode->next;
                currentNode->next = insetNode;
            }

        void displayMatrix(){
            Node *currentNode = head;
            while(currentNode != NULL){
                // Prints all data
                std::cout << "data: " << currentNode->data;
                std::cout << " row: " << currentNode->Row;
                std::cout <<" col: " << currentNode->Col << std::endl;
                currentNode = currentNode->next;
            }
        }
        void denseToSparse(double matrixD[][MAXSIZE], int Row, int Col, LinkedList &sparseMatrix){
            for (int i = 0; i <Row; ++i) {
                for (int j =0; j < Col; ++j) {
                    // Loops through matrix
                    if(matrixD[i][j] != 0)
                    // Only adds the non zero terms to the sparse matrix
                    sparseMatrix.addElementToMatrix(matrixD[i][j],i,j);
                }
            }
        }     
};


int main(){
    LinkedList newList, sparseMatrix;

    // All Linked list operations
    newList.addHead(5);
    newList.addHead(4);
    newList.addHead(3);
    newList.addHead(2);
    newList.addHead(1);
    newList.addTail(1);
    newList.addGeneralNode(5,3);
    newList.removeHead();
    newList.removeTail();
    newList.removeGeneralNode(3);

    //Displaying linked list
    std::cout << "Linked List:" << std::endl;
    newList.displayLinkedList();
    std::cout<< std::endl;

    // Sparse matrix using linked list approach.

    //Matrix size
    int SIZE = 4;
    // Sparse Matrix
    double matrixD[][MAXSIZE] = {
        {5, 0, 0, 0},
        {0, 8, 0, 0},
        {0, 0, 3, 0},
        {0, 6, 0, 0}
    };

    // Displays sparse matrix
    sparseMatrix.denseToSparse(matrixD, 4, 4, sparseMatrix);
    std::cout << "Sparse matrix:" << std::endl;
    sparseMatrix.addElementToMatrix(5,1,3);
    sparseMatrix.displayMatrix();


    return 0;
}