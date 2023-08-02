// Heap Sort

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


void makeHeap(vector<int> &nums){
    int n = nums.size();
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(nums, n, i);
}


void display(vector<int> nums){
    int n = nums.size();
    for(int i = 0; i < n; i++)
        cout << nums[i] << " ";
}


void heapSort(vector<int> &nums){
    int n = nums.size();
    for(int i = n - 1; i >= 0; i--){
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}


int main(void){

    vector<int> nums = {
        10, 23, 8, 21, 32, 17, 14, 20, 9, -2, 91, 0, -12,
        10, 23, 8, 21, 32, 17, 14, 20, 9, -2, 91, 0, -12,
        10, 23, 8, 21, 32, 17, 14, 20, 9, -2, 91, 0, -12,
        10, 23, 8, 21, 32, 17, 14, 20, 9, -2, 91, 0, -12,
        10, 23, 8, 21, 32, 17, 14, 20, 9, -2, 91, 0, -12,
        10, 23, 8, 21, 32, 17, 14, 20, 9, -2, 91, 0, -12,
        10, 23, 8, 21, 32, 17, 14, 20, 9, -2, 91, 0, -12,
        10, 23, 8, 21, 32, 17, 14, 20, 9, -2, 91, 0, -12
    };
    cout << "\nOriginal Array : ";

    display(nums);
    makeHeap(nums);

    cout << "\nSorted Array : ";
    heapSort(nums);
    display(nums);


    return 0;
}