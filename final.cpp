#include <iostream>
using namespace std;

// ================= LINKED LIST =================
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data=val;
        next=NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head=NULL;
    }

    // Insert at start
    void insertStart(int val) {
        Node* newNode=new Node(val);
        newNode->next=head;
        head = newNode;
        cout<<val<<" added at start.\n";
    }

    // Insert at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head==NULL) {
            head =newNode;
            cout<<val<< " added at end.\n";
            return;
        }

        Node* temp =head;
        while (temp->next != NULL) {
            temp =temp->next;
        }

        temp->next = newNode;
        cout<<val<<" added at end.\n";
    }

    // Delete by value
    void deleteValue(int val) {
        if (head==NULL) {
            cout<<"List empty!\n";
            return;
        }

        if (head->data==val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout<<val<<" deleted.\n";
            return;
        }

        Node* temp = head;
        while(temp->next && temp->next->data != val) {
            temp=temp->next;
        }

        if (temp->next){
            Node* del=temp->next;
            temp->next=temp->next->next;
            delete del;
            cout<<val<<" deleted.\n";
        } 
        else{
            cout<<"Value not found!\n";
        }
    }

    // Display list
    void display(){
        if(head==NULL){
            cout<<"List is empty.\n";
            return;
        }

        Node* temp=head;
        cout<<"List: ";
        while (temp){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }
};

// ================ SORTING (MERGE / QUICK) =================
void merge(int arr[],int l,int m,int r) {
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];

    for (int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }

    for (int j=0;j<n2;j++) {
        R[j]=arr[m+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        } 
        else{
            arr[k++]=R[j++];
        }
    }

    while(i<n1){
        arr[k++]=L[i++];
    }

    while(j<n2){
        arr[k++]=R[j++];
    }
}

void mergeSort(int arr[],int l,int r) {
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int partition(int arr[],int low,int high) {
    int pivot=arr[high];
    int i=low-1;

    for (int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(int arr[],int low,int high) {
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

// ================== BINARY SEARCH ==================
int binarySearch(int arr[],int n,int key) {
    int low=0,high=n-1;

    while(low<=high){
        int mid =(low+high)/2;

        if(arr[mid]==key) {
            return mid;
        } 
        else if(arr[mid]<key) {
            low=mid+1;
        } 
        else{
            high=mid-1;
        }
    }

    return -1;
}

// ================== MAIN MENU ==================
int main() {
    LinkedList list;
    int choice;

    do {
        cout<<"\n===== MAIN MENU =====\n";
        cout<<"1. Linked List\n";
        cout<<"2. Sorting (Merge/Quick)\n";
        cout<<"3. Binary Search\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:{
                int ch,val;
                do{
                    cout<<"\n-- LINKED LIST MENU --\n";
                    cout<<"1. Insert at Start\n";
                    cout<<"2. Insert at End\n";
                    cout<<"3. Delete Value\n";
                    cout<<"4. Display\n";
                    cout<<"5. Back\n";
                    cout<<"Enter choice: ";
                    cin>>ch;

                    switch(ch){
                        case 1:{
                            cout<<"Enter value: ";
                            cin>>val;
                            list.insertStart(val);
                            break;
                        }
                        case 2:{
                            cout<<"Enter value: ";
                            cin>>val;
                            list.insertEnd(val);
                            break;
                        }
                        case 3:{
                            cout<<"Enter value: ";
                            cin>>val;
                            list.deleteValue(val);
                            break;
                        }
                        case 4:{
                            list.display();
                            break;
                        }
                        case 5:{
                            cout<<"Returning to main menu...\n";
                            break;
                        }
                        default:{
                            cout<<"Invalid choice!\n";
                        }
                    }
                }while(ch!=5);
                break;
            }
            case 2:{
                int n,ch;
                cout<<"Enter size: ";
                cin>>n;
                int arr[n];
                cout<<"Enter "<<n<<" elements: ";
                for (int i= 0;i<n;i++) {
                    cin>>arr[i];
                }
                cout<<"1. Merge Sort\n2. Quick Sort\nEnter choice: ";
                cin>>ch;
                if(ch==1){
                    mergeSort(arr,0,n-1);
                }
                else if(ch==2){
                    quickSort(arr,0,n-1);
                }
                else{
                    cout<<"Invalid sort choice!\n";
                    break;
                }
                cout<<"Sorted Array: ";
                for (int i=0;i<n;i++) {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
                break;
            }

            case 3:{
                int n,key;
                cout<<"Enter size: ";
                cin>>n;
                int arr[n];
                cout<<"Enter sorted elements: ";
                for(int i=0;i<n;i++){
                    cin>>arr[i];
                }
                cout<<"Enter value to search: ";
                cin>>key;
                int res=binarySearch(arr,n,key);
                if(res!=-1){
                    cout<<"Element found at index "<<res<<endl;
                }
                else{
                    cout<<"Element not found.\n";
                }
                break;
            }

            case 4:{
                cout<<"Exiting program. Goodbye!\n";
                break;
            }
            default:{
                cout<<"Invalid choice!\n";
            }
        }
    }while(choice!=4);
    return 0;
}
