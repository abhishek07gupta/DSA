#include <iostream>

using namespace std;

// heapify

void heapify(int arr[],int n , int i ){
    int largest = i ;
    int left = 2*i;
    int right = 2*i + 1; 

    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }

    if(largest!=i){
        int temp = arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heapify(arr,n,largest);
    }
}

// heap sort

void heapSort(int arr[],int n ){
    int t = n ;
    while (t>1)
    {   
        int temp = arr[t];
        arr[t]=arr[1];
        arr[1]=temp;
        t--;
        heapify(arr,t,1);
        
    }
    
}

int main (){
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

    heapSort(arr,n);
    cout<<endl;
    for(int i = 1 ; i < n ; i ++){
        cout<<arr[i]<<endl;
    }

    return 0 ;
}

