#include <iostream>
using namespace std;

// MARK: - Node
struct node {
    int data;
    node *next;
};

node *head=NULL , *last=NULL;
int length=0;

// MARK: - Definitions
void insert(int element);
void insertFirst(int element);
void insertLast(int element);
void remove(int val);
void display();
void printnode();
void printnode2();
void search ();


// MARK: - Main
int main() {
    
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    
    display();
    remove(35);
    display();
    insert(45);
    display();
    
    // printnode();
    search ();
    return 0;
}


// MARK: - Functions
void insert(int element) {
    node* newnode;
    newnode = new node;
    newnode -> data = element;
    if (head == NULL) {
        head = newnode;
        newnode -> next = NULL;
    } else {
        last = head;
        while (last -> next != NULL) {
            last = last -> next;
        }
        last ->next = newnode;
        newnode -> next = NULL;
    }
    length++;
}



void insertFirst(int element) {
    node *newnode = new node;
    newnode -> data = element;
    if ( length == 0) {
        head =last = newnode;
        newnode -> next = NULL;
    } else {
        last->next=newnode;
        newnode -> next = NULL;
        last = newnode;
    }
    length++;
}


void remove(int val) {
    node* curent, *prev;
    if (length == 0) {
        cout << "The list is empty" << endl;
    } else if ( length == 1) {
        curent = head;
        if (curent ->data == val ) {
            head = NULL;
            free(curent);
        } else {
            cout << "The value not found" << endl;
        }
    } else {
        curent = prev = head;
        while (curent ->data != val) {
            prev = curent;
            curent = curent ->next;
        }
        prev -> next = curent -> next;
        free(curent);
    }
    length--;
}


void display() {
    node* currentnode;
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
    node* curr = head;
    int sum = 1;
    int num ;
    cin >> num;
    while (num != sum) {
        curr = curr -> next;
        sum++;
    }
    cout << curr ->data <<" " << endl;
}

void insertLast(int element) {
    node *newnode = new node;
    newnode -> data = element;
    if ( length == 0) {
        head = last = newnode;
        newnode -> next = NULL;
    } else {
        head -> next = newnode;
        newnode -> next = NULL;
        head = newnode;
    }
    length++;
}



void printnode2() {
    node* current = head;
    
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
    node* current = head;
    
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

