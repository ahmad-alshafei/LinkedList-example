#include <iostream>
using namespace std;

// MARK: - Node
struct Node {
    int data;
    Node *next;
};

Node *head=NULL , *last=NULL;
int length = 0;

// MARK: - Definitions
void insertWithLoop(int element);
void insertFirst(int element);
void insertLast(int element);
void remove(int val);
void display();
void printnode();
void printnode2();
void search ();


// MARK: - Main
int main() {
    
//    insert(2);
//    insert(3);
//    insert(4);
//    insertFirst(1);
//    insertLast(2);
//    insertLast(3);
//    insertLast(4);
//    insertLast(5);
//    insertLast(6);
    
    insertWithLoop(1);
    insertWithLoop(2);
    insertWithLoop(3);
    insertWithLoop(4);
    
    remove(4);
//    remove(6);
//    remove(5);
//    remove(4);
//    remove(3);
    
    
    display();
    
    
    
    /*remove(35);
    display();
    insert(45);
    display();
    */
    // printnode();x
    search ();
    return 0;
}


// MARK: - Functions
void insertWithLoop(int element) {
    Node* newNode;
    newNode = new Node;
    newNode -> data = element;
    
    if (head == NULL) {
        head = newNode;
        newNode -> next = NULL;
    } else {
        last = head;
        
        while (last -> next != NULL) {
            last = last -> next;
        }
        last -> next = newNode;
        last = newNode;
        newNode -> next = NULL;
    }
    
    length++;
}


void insertFirst(int element) { // newNode, 1 , 2 , 3
    Node *newNode = new Node;
    newNode -> data = element;
    
    if (length == 0) {
        head = last = newNode;
    } else {
        newNode -> next = head;
        head = newNode;
    }
    
    length++;
}


void insertLast(int element) { // 1 , 2 , 3 , newNode
    Node *newNode = new Node;
    newNode -> data = element;
    
    if (length == 0) {
        head = last = newNode;
    } else {
        last -> next = newNode;
        last = newNode;
    }
    newNode -> next = NULL;
    length++;
}




void remove(int val) {
    Node* current, *prev;
    if (length == 0) {
        cout << "The list is empty" << endl;
    } else if ( length == 1) {
        current = head;
        if (current ->data == val ) {
            head = NULL;
            free(current);
        } else {
            cout << "The value not found" << endl;
        }
    } else {
        current = prev = head;

        while (current ->data != val) {
            prev = current;
            current = current ->next;
        }
        prev -> next = current -> next;
        
        // make the prev is last when we will remove last val
        if (current -> next == NULL) {
            last = prev;
        }
        
        free(current);
    }
    length--;
}


void display() {
    Node* currentnode;
    if (head == NULL) {
        cout << "The node is empty" << endl;
    } else {
        currentnode = head;
        do {
            cout << currentnode -> data << " ";
            currentnode = currentnode -> next;
        }
        while (currentnode -> next != NULL);
        cout << currentnode -> data << " ";
        
        cout << endl;
        cout << "- Linked list count is (" << length << ")" << endl << endl;
    }
}

void printnode() {
    Node* curr = head;
    int sum = 1;
    int num ;
    cin >> num;
    while (num != sum) {
        curr = curr -> next;
        sum++;
    }
    cout << curr ->data <<" " << endl;
}



void printnode2() {
    Node* current = head;
    
    int sum =1;
    int num;
    cin >> num;
    
    while (num != sum ) {
        current = current -> next;
        sum++;
    }
    cout << current -> data << " " << endl;
}


void search () {
    Node* current = head;
    
    int value;
    bool test=1;
    cin >> value;
    
    while (current ->data != value) {
        if ( current -> next != NULL) {
            current = current -> next;
            
        } else {
            test = 0;
            break;
        }
    }
    
    if (test == 1) {
        cout <<"faund it : " << current -> data << endl;
    } else {
        cout <<"not faund it : " << endl;
    }
}

