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
    int extractMinElement() {
        // Write you code here.
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        // Write you code here.
    }

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

    // to print all the elements of heap
    void print(){
            cout<<"the elements of the heap::"<<endl;
        for(int i = 1 ; i <= size ; i ++){
            cout<<arr[i]<<' ';
        }
    }
};


int main(){
    maxHeap mheap;
    mheap.insert(50);
    mheap.insert(55);
    mheap.insert(23);
    mheap.insert(49);
    mheap.insert(53);

    mheap.print();

    return 0 ;
}