/*
You are given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Example 1:

Input: nums = [10,9,1,1,1,2,3,1]

Output: [1,1,1,1,2,3,9,10]
Example 2:

Input: nums = [5,10,2,1,3]

Output: [1,2,3,5,10]
Constraints:

1 <= nums.length <= 50,000.
-50,000 <= nums[i] <= 50,000
*/
#include <iostream>
#include <vector>
using namespace std;

// Solution 1 -> Heap Sort O(nlogn) and O(1) space
class Solution {
public:
    void heapify( vector<int>& nums , int n , int i){
        int largest = i ; // It may not be the largets element yet 

        int left = 2*i + 1 ;
        int right = 2*i + 2 ;

        if( left < n && nums[left] > nums[largest] ){
            largest = left ; 
        }

        if( right < n && nums[right] > nums[largest] ){
            largest = right ; 
        }

        if( largest != i){
            swap(nums[i],nums[largest]);
            // Still may not be a heap so it needs to go down 
            // Notice how we call heapify on only one of the subtress 
            // So that is why heapify needs both subtree to be heap as when elements are swapped 
            // Only one subtree shoudl be distorted and will be fixed , the other is not touched 
            // and that is why we always build heap from the bottom up 
            heapify(nums,n,largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        // For TC:O(nlogn) and SC:O(1)
        // We use heap sort 
        // First build a heap where every node is greater than both its children 
        // This means the root node is the greatest element and
        // This means all leaf nodes are already max heap 
        // The idea of heapify is it assumes left and right subtree are already heaps

        // So we build heap by calling heapify but only from the last non leaf node which is at position n/2 - 1

        int n = nums.size() ;

        // Step 1 : Build heap 
        // Build Max Heap
        //
        // At first glance it looks like O(n log n) because we call heapify()
        // roughly n/2 times and each heapify can take O(log n).
        //
        // However, most heapify calls are on nodes near the bottom of the tree,
        // which have very small heights and therefore do very little work.
        //
        // Number of nodes at height h decreases exponentially:
        //
        // Height 0 (leaves)      : ~n/2 nodes, cost O(0)
        // Height 1               : ~n/4 nodes, cost O(1)
        // Height 2               : ~n/8 nodes, cost O(2)
        // ...
        //
        // Total work:
        //
        // (n/4)*1 + (n/8)*2 + (n/16)*3 + ...
        //
        // This sums to O(n), so building the heap is O(n), not O(n log n).
        //
        // We start from the last non-leaf node (n/2 - 1) because leaf nodes
        // are already valid heaps, and heapify assumes its children are heaps.
        for(int i = n/2 - 1 ; i>= 0 ; i--){
            heapify( nums , n , i );
        }

        // Now max element is at the root , we can push to the end and continue the method 
        // Step 2 : Extract maximum element one by one
        // heapify -> logn and we call it n times so 
        // TC:O(nlogn)
        for(int i = n-1 ; i >= 0 ; i--){

            // Root contains the largest element
            // Move it to its final sorted position
            swap(nums[0] , nums[i]);

            // Heap size decreases by 1 ( as we ran a loop from n-1 , so first it is n-1 , n-2 and so on )
            // Restore heap property in the remaining heap
            heapify(nums , i , 0);

        }

        //TC:O(nlogn) and SC:O(1)
        return nums ;
    }
};

// Solution 2 -> Merge Sort O(nlogn) and O(n) space
class Solution {
public:
    void mergeSorted(vector<int>& nums ,int start ,int end , int mid){
        int n1 = mid - start + 1 ; 
        int n2 = end - mid ; 
        int idx = start ;

        vector<int> first(n1) ; 
        vector<int> second(n2) ;

        for(int i = 0 ; i < n1 ; i++){
            first[i] = nums[idx++];
        }

        for(int i = 0 ; i < n2 ; i++){
            second[i] = nums[idx++];
        }

        int i = 0 ; 
        int j = 0 ;
        idx = start ; 
        while( i < n1 && j < n2){
            if( first[i] <= second[j]){
                nums[idx++] = first[i++];
            }else{
                nums[idx++] = second[j++];
            }
        }

        while(i < n1){
            nums[idx++] = first[i++];
        }

         while(j < n2){
            nums[idx++] = second[j++];
        }

    }
    void merge(vector<int>& nums ,int start ,int end){
        if( start >= end){
            return ;
        }

        int mid = start + ( end - start) / 2;

        merge(nums , start , mid );
        merge(nums , mid + 1 , end);

        mergeSorted(nums , start , end , mid);
    }
    vector<int> sortArray(vector<int>& nums) {
        // O(nlogn) so merge sort but O(n) for space 
        // For O(1) we need heap sort 
        int n = nums.size() ;
        int start = 0 ; 
        int end = n - 1;
        merge(nums , start , end);

        return nums ; 
    }
};