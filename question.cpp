#include <iostream>
using namespace std;
class node{
public:
    int data;
    node* next;

    node(int x){
        data = x;
        next = NULL;
    }
};
class linkedlist{
public:
    node* head;
    linkedlist(){
        head = NULL;
    }

    void insertfront(int x){
        node* newnode = new node(x);
        newnode->next = head;
        head = newnode;
    }

    void insertend(int x){
        node* newnode = new node(x);
        if(head == NULL){
            head = newnode;
            return;
        }
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void insertPosition(int pos, int x){
        
    }

    void deleteFront(){
        if(head == NULL)
            return;
        node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast(){
        if(head == NULL)
            return;
        if(head->next == NULL){
            delete head;
            head = NULL;
            return;
        }

        node* temp = head;

        while(temp->next->next != NULL){
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    void deletePosition(int pos){
        if(head == NULL)
            return;

        if(pos == 1){
            deleteFront();
            return;
        }

        node* temp = head;

        for(int i = 1; i < pos - 1 && temp != NULL; i++){
            temp = temp->next;
        }
        if(temp == NULL || temp->next == NULL)
            return;

        node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    bool search(int key){
        node* temp = head;

        while(temp!= NULL){
            if(temp->data == key)
                return true;

            temp = temp->next;
        }

        return false;
    }

    int length(){
        int count = 0;
        node* temp = head;

        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        return count;
    }

    void display(){
        node* temp = head;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};
int main(){
    linkedlist list;

    list.insertfront(10);
    list.insertend(20);
    list.insertend(30);
    list.insertPosition(2, 15);

    cout << "linked list:";
    list.display();

    cout << "length=" << list.length() << endl;

    if(list.search(20))
        cout << "20 found" << endl;
    else
        cout << "20 not found" << endl;

    list.deleteFront();
    cout << "after delete front: ";
    list.display();

    list.deleteLast();
    cout << "after delete last: ";
    list.display();

    list.deletePosition(2);
    cout << "after delete 2ndlast: ";
    list.display();

    return 0;
}