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

Node* convertArr2LL(vector<int> &arr, int size){
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

void printLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data <<" ";
        temp = temp-> next;
    }
    cout << "nullptr" << endl;
}

Node* insertAtHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int size = arr.size();

    Node* head = convertArr2LL(arr, size);
    head = insertAtHead(head, 100);

    printLL(head);

    return 0;
}