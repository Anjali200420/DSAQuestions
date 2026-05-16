class BinaryHeap{
    int size;
    int capacity;
    vector<int> arr;
    
  public:
    BinaryHeap(int capacity){
        this -> capacity = capacity;
        this -> size = 0;
        
        arr.resize(capacity);
    }
    
    int parent(int ind){
        return (ind - 1)/2;
    }
    
    int leftChild(int ind){
        return 2*ind + 1;
    }
    
    int rightChild(int ind){
        return 2*ind + 2;
    }
    
    void insert(int val){
        arr[size] = val;
        
        int k = size;
        size++;
        
        while(k != 0 && arr[parent(k)] < arr[k]){
            swap(&arr[parent(k)], &arr[k]);
            k = parent(k);
        }
    }
    
    void heapify(int ind){
        int lChild = leftChild(ind);
        int rChild = rightChild(ind);
        
        int largest = ind;
        if(lChild < size && arr[lChild] > arr[largest]) largest = lChild;
        if(rChild < size && arr[rChild] > arr[largest]) largest = rChild;
        
        if(largest != ind){
            swap(&arr[ind], &arr[largest]);
            heapify(largest);
        }
    }
    
    void deleteFirstElement(){
        arr[0] = arr[size - 1];
        
        size--;
        heapify(0);
    }
    
    int getTop(){
        return arr[0];
    }
    
    void swap(int *x, int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }
};

class Solution {
  public:
    // Function to return kth largest element from an array.
    int KthLargest(vector<int> &arr, int k) {
        // Your code here
        int n = arr.size();
        
        BinaryHeap bh(n);
        for(int ind = 0; ind < n; ind++){
            bh.insert(arr[ind]);
        }
        
        for(int ind = 1; ind < k; ind++){
            bh.deleteFirstElement();
        }
        
        return bh.getTop();
    }
};