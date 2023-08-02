// inserting new node in a HEAP
// Max Heap
// bottom up

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


int main(void){

    vector<int> nums = {5, 10, 20, 17, 6, 5, 9, 12};

    int n = nums.size();
    makeHeap(nums, n); 

    cout << "\nHeap : ";
    display(nums);

    int newNode;
    cout << "\nNew Node : ";
    cin >> newNode;

    nums.push_back(newNode);
    insertNode(nums, nums.size() - 1);

    cout << "\nHeap after insertion of " << newNode << " : ";
    display(nums);

    return 0;
}