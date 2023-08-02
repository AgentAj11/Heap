// program to delete root of the HEAP

#include <iostream>
#include <vector>
using namespace std;


void heapify(vector<int> &nums, int n, int i){

    int largest = i;
    int parent = i;
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;

    if(lchild < n && nums[lchild] > nums[largest])
        largest = lchild;

    if(rchild < n && nums[rchild] > nums[largest])
        largest = rchild;

    if(parent != largest){
        swap(nums[parent], nums[largest]);
        heapify(nums, n, largest);
    }
}


void makeHeap(vector<int> &nums, int n){
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(nums, n, i);
}


void display(vector<int> nums){
    int n = nums.size();
    for(int i = 0; i < n; i++)
        cout << nums[i] << " ";
}


void insertNode(vector<int> &heap, int current){
    
    int parent = (current - 1) / 2;

    if(heap[current] > heap[parent]){
        swap(heap[current], heap[parent]);
        insertNode(heap, parent);
    }
}


void deleteRoot(vector<int> &heap){

    int n = heap.size();
    swap(heap[0], heap[n - 1]);
    heapify(heap, n - 1, 0);
}


int main(void){

    vector<int> nums = {5, 10, 20, 17, 6, 5, 9, 12};

    int n = nums.size();
    makeHeap(nums, n); 

    cout << "\nOriginal Heap : ";
    display(nums);

    deleteRoot(nums);
    cout << "\nHeap after deletion of Root Node : ";
    display(nums);


    return 0;
}