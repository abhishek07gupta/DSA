#include<vector>
#include<iostream>
using namespace std;

// here we are implementing max heap , min head can be implemented similarly .

class maxHeap {
public:
    int arr[100];
    int size;
    // Constructor for the class.
    maxHeap() {
        // Write your code here.
        
        // we dont use 0th index in the heap
        arr[0]=-1;
        size = 0 ;
    }

    // Implement the function to remove minimum element.

// --------------------------------------------------------------------------------------------------------

// Implement the function to delete root element
    void deleteElement() {
        // Write you code here.
        int el = arr[1];
        if(size ==0 ){
            cout<<"nothing to delete";
            return ;
        }
        // replacing that node with last node and removing the last node to delete the  required element
        int pos = 0 ;
        // first find that el
        for(int i =1 ; i <=size-2 ; i++){
            if(arr[i]==el){
                pos=i;
                break;
            }
        }
        if(pos==0){
            cout<<"element not found in the heap"<<endl;
            return ;
        }

        arr[pos]=arr[size];
        size--;

        while(pos<size){
            int leftsize = pos*2;
            int rightsize = pos*2+1;
            if(leftsize < size && arr[leftsize]>arr[pos] && arr[leftsize]>arr[rightsize]){
                // swap left child with parent
                int temp = arr[leftsize];
                arr[leftsize]=arr[pos];
                arr[pos]=temp;
                pos=leftsize;
            }else if(rightsize<size && arr[rightsize]>arr[pos] && arr[rightsize]>arr[leftsize]){
                // swap right child with parent
                int temp = arr[rightsize];
                arr[rightsize]=arr[pos];
                arr[pos]=temp;
                pos=rightsize;
            }else{
                // both sides good
                return;
            }
        }

    }

//delete function for specific element; 
    void deleteElement(int el) {
        // Write you code here.
        if(size ==0 ){
            cout<<"nothing to delete";
            return ;
        }
        // replacing that node with last node and removing the last node to delete the  required element
        int pos = 0 ;
        // first find that el
        for(int i =1 ; i <=size-2 ; i++){
            if(arr[i]==el){
                pos=i;
                break;
            }
        }
        if(pos==0){
            cout<<"element not found in the heap"<<endl;
            return ;
        }

        arr[pos]=arr[size];
        size--;

        while(pos<size){
            int leftsize = pos*2;
            int rightsize = pos*2+1;
            if(leftsize < size && arr[leftsize]>arr[pos] && arr[leftsize]>arr[rightsize]){
                // swap left child with parent
                int temp = arr[leftsize];
                arr[leftsize]=arr[pos];
                arr[pos]=temp;
                pos=leftsize;
            }else if(rightsize<size && arr[rightsize]>arr[pos] && arr[rightsize]>arr[leftsize]){
                // swap right child with parent
                int temp = arr[rightsize];
                arr[rightsize]=arr[pos];
                arr[pos]=temp;
                pos=rightsize;
            }else{
                // both sides good
                return;
            }
        }

    }

//------------------------------------------------------------------------------------------------------------

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        // Write you code here.
        size = size + 1; 
        int index = size; 
        arr[index] = val;

        while(index>1){
            // index of the parent
            int mid = index/2;
            
            // if(arr[mid]>arr[index]) -->> condition for min heap;
            if(arr[mid]<arr[index]){
                // swap the element with its parent
                int temp = arr[index];
                arr[index]=arr[mid];
                arr[mid]=temp;
                index = mid;
            }else{
                return ;
            }
        }
    }

// ------------------------------------------------------------------------------------------------------------

    // to print all the elements of heap
    void print(){
            cout<<"the elements of the heap::"<<endl;
        for(int i = 1 ; i <= size ; i ++){
            cout<<arr[i]<<' ';
        }
    }
};

// ------------------------------------------------------------------------------------------------------------

// heapify

void heapify(int arr[],int n , int i ){
    int largest = i ;
    int left = 2*i;
    int right = 2*i + 1; 

    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest!=i){
        int temp = arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heapify(arr,n,largest);
    }
}


int main(){
    maxHeap mheap;

// inserting into the heap
    mheap.insert(50);
    mheap.insert(55);
    mheap.insert(53);
    mheap.insert(52);
    mheap.insert(54);

    mheap.print();

    cout<<endl;

// deleting from the heap
    int delel;
    cout<<"enter the element to delete"<<endl;
    cin>>delel;

    mheap.deleteElement(delel);

    mheap.print();


// heapify 
    int arr[]={-1,50,55,53,52,54};
    int n = 6;
    for(int i = n/2 ; i >0 ; i --){
        heapify(arr,n,i);
    }
    cout<<endl;
    for(int i = 1 ; i < n ; i ++){
        cout<<arr[i]<<endl;
    }
    

    return 0 ;
}