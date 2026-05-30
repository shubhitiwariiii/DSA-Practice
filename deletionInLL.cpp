#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

Node* arrToLL(vector<int> &arr, int size){
    if(size == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<size; i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* deletionAtHead(Node* head){
    if(head == NULL) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int size = arr.size(); 

    Node* head = arrToLL(arr, size);
    printLL(head);

    head = deletionAtHead(head);
    printLL(head);
    // head = deletionAtTail(head, 100);
    // head = deletionAtK(head, 100, 4);
}