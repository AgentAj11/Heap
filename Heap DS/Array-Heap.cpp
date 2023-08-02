// Program to convert given array to heap

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


int main(void){

    vector<int> nums = {5, 10, 20, 17, 6, 5, 9, 12};

    int n = nums.size();

    cout << "\nOriginal Array : ";
    display(nums);

    makeHeap(nums, n); 

    cout << "\nHeap : ";
    display(nums);

    return 0;
}