void maxHeapify(int ind, long *arr, int n){
    int left = 2*ind + 1;
    int right = 2*ind + 2;

    int largest = ind;
    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;

    if(largest != ind){
        swap(arr[ind], arr[largest]);
        maxHeapify(largest, arr, n);
    }
}

void minHeapToMaxHeap(long *arr, int n)
{
    //Write your code here
    for(int ind = (n-2)/2; ind >= 0; ind--){
        maxHeapify(ind, arr, n);
    }
}