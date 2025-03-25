#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkList{
    public:
    Node* head;
    Node* tail;

    LinkList(){
        head = tail = NULL;
    }

    void insert_at_start(int val){
        Node* n = new Node(val);
        if(head == NULL){
            head = tail = n;
            tail->next = n;
            return;
        }
        n->next = head;
        tail->next = n;
        head = n;
    }

    void insert_at_last(int val){
        Node* n = new Node(val);
        if(head == NULL){
            head = tail = n;
            tail->next = n;
            return;
        }
        tail->next = n;
        tail = n;
        tail->next = head;
    }

    void insert_at_position(int pos,int val){
        if(pos == 0){
            insert_at_start(val);
            return;
        }
        Node* temp = head;
        int curr = 0;
        while(curr!= pos-1 && temp->next != head){
            temp = temp->next;
            curr++;
        }
        Node* n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    void update_at_position(int pos, int val){
        Node* temp = head;
        int curr = 0;
        while(curr!= pos){
            temp = temp->next;
            curr++;
        }
        temp->val = val;
    }

    int Lenght(){
        Node* temp = head;
        int len = 0;
       do{
        len++;
        temp = temp->next;
       }
       while(temp!= head);
       return len;
    }

    void delete_from_start(){
        if(head == NULL){
            cout<<"list is empty";
            return;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void delete_from_last(){
        if(head == NULL){
            cout<<"list is empty";
            return;
        }

        if (head == tail) {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next!= head){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }

    void delete_from_position(int pos){
        if(pos == 0){
            delete_from_start();
            return;
        }
        int curr = 0;
        Node* temp = head;
        while(curr!= pos-1 &&temp->next!= head ){
            temp = temp->next;
            curr++;
        }
        Node* to_del = temp->next;
        temp->next = to_del->next;
        delete to_del;
    }

    void display(){
        Node* temp = head;
        do{
            cout<<temp->val<<"->";
            temp = temp->next;
        } while(temp!= head);
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkList ll;
    ll.insert_at_start(10);
    ll.insert_at_start(20);
    ll.insert_at_start(30);
    ll.display();
    ll.insert_at_last(12);
    ll.display();
    ll.insert_at_position(3,40);
    ll.display();
    ll.update_at_position(3,50);
    ll.display();
    cout<<ll.Lenght()<<endl;
    ll.delete_from_start();
    ll.display();
    ll.delete_from_last();
    ll.display();
    ll.delete_from_position(1);
    ll.display();
}