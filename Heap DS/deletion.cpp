// Heap node deletion

// deleting any random node from a heap does not make any sense, it can be done by other data structures like array easily or by creating an auxilary heap which will store all the elements of the heap except the one to be deleted

// * Deletion in heap means deletion of root node

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


void deleteNode(vector<int> &nums, int node){

    int n = nums.size();

    for(int i = 0; i < n; i++){
        if(nums[i] == node){
            swap(nums[n - 1], nums[i]);
            heapify(nums, n - 1, i);
            break;
        }
    }  cout << "\n" << node << " not found !";
}


int main(void){

    vector<int> nums = {5, 10, 20, 17, 6, 5, 9, 12};

    int n = nums.size();

    makeHeap(nums, n);

    cout << "\nOriginal Heap : ";
    display(nums);

    int key;
    cout << "\nNode to be deleted : ";
    cin >> key;
    
    deleteNode(nums, key);
    cout << "\nNew Heap : ";
    display(nums);


    return 0;
}