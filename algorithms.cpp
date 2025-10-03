#include<iostream>
using namespace std;

// sorting algorithms
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

void merge(int arr[],int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    
    int L[n1],R[n2];
    
    for(int i=0;i<n1;i++)
        L[i]= arr[left+i];
    for(int j=0;j<n2;j++)
        R[j]=arr[mid+1+j];
        
    int i=0,j=0,k=left;
    
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        } 
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

// searching algorithms
int linearSearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int n,int target){
    int left=0,right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }  
    return -1;
}

// Display array
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    // step 1: create array
    cout<<"Enter array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"\nYour array: ";
    printArray(arr,n);
    // step 2: choose sorting algorithm
    cout<<"\nChoose sorting algorithm:\n";
    cout<<"1. Selection Sort\n";
    cout<<"2. Merge Sort\n";
    cout<<"Enter choice (1 or 2): ";
    int sortChoice;
    cin>>sortChoice;
    if(sortChoice==1){
        selectionSort(arr,n);
        cout<<"Sorted with Selection Sort: ";
    }
    else if(sortChoice==2){
        mergeSort(arr,0,n-1);
        cout<<"Sorted with Merge Sort: ";
    } 
    else{
        cout<<"Invalid choice! Using Selection Sort by default: ";
        selectionSort(arr,n);
    }
    printArray(arr,n);
    // step 3: choose searching algorithm
    cout<<"\nChoose searching algorithm:\n";
    cout<<"1. Linear Search\n";
    cout<<"2. Binary Search\n";
    cout<<"Enter choice (1 or 2): ";
    int searchChoice;
    cin>>searchChoice;
    int target;
    cout<<"Enter element to search: ";
    cin>>target;
    int result;
    if(searchChoice == 1){
        result=linearSearch(arr,n,target);
    } 
    else if(searchChoice==2){
        result=binarySearch(arr,n,target);
    } 
    else{
        cout<<"Invalid choice! Using Linear Search by default.\n";
        result=linearSearch(arr,n,target);
    }
    // display result
    if(result!=-1){
        cout<<"Element found at index: "<<result <<endl;
    }
    else{
        cout<<"Element not found in array!"<<endl;
    }
    return 0;
}
