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
    if(head == NULL) return head;
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertAtTail (Node* head, int val){
    if(head == NULL) return head;

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

Node* insertAtK(Node* head, int val, int K){
    if(head == NULL){
        if(K==1){
            return new Node(val);
        }else{
            return NULL;
        }
    }
    if(K == 1){
        return new Node(val, head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == K-1){
            Node* X = new Node(val, temp->next);
            temp->next = X;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int size = arr.size();

    Node* head = convertArr2LL(arr, size);
    // head = insertAtHead(head, 100);
    // head = insertAtTail(head, 100);
    head = insertAtK(head, 100, 4);

    printLL(head);

    return 0;
}