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

int lengthOfLL(Node* head){
    Node* temp = head;
    int length = 0;
    while(temp != nullptr){
        length++;
        temp = temp->next;
    }
    return length;
}

Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;

}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int size = arr.size();

    // Node* y = new Node(arr[0], nullptr);
    // cout << y << endl;
    // cout << y->data << endl;

    Node* head = convertArr2LL(arr, size);
    // cout << head->data << endl;

    // Node* head = convertArr2LL(arr,size);
    // printLL(head);

    // int length = lengthOfLL(head);
    // cout << "length of linked list is : " << length << endl;

    head = removeHead(head);
    printLL(head);

    return 0;
}
