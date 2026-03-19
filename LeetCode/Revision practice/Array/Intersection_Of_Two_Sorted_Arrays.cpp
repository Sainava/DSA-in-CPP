/*
Problem statement
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

Note :
1. The length of each array is greater than zero.
2. Both the arrays are sorted in non-decreasing order.
3. The output should be in the order of elements that occur in the original arrays.
4. If there is no intersection present then return an empty array.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 100
1 <= N, M <= 10^4
0 <= A[i] <= 10^5
0 <= B[i] <= 10^5

Time Limit: 1 sec
Sample Input 1 :
2
6 4
1 2 2 2 3 4
2 2 3 3
3 2
1 2 3
3 4  
Sample Output 1 :
2 2 3
3   
Explanation for Sample Input 1 :
For the first test case, the common elements are 2 2 3 in both the arrays, so we print it.

For the second test case, only 3 is common so we print 3.
Sample Input 2 :
2
3 3 
1 4 5
3 4 5
1 1
3
6
Sample Output 2 :
4 5
-1
*/
#include <iostream>
#include <vector>
using namespace std;


// Brute Force : TC:O(n * m) and SC:O(min(n,m)) for result vector - TLE
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Brute force
	vector<int> ans ;

	vector<int> visited(m,0) ; // To keep a one to one mapping and the same element is not considered to create a pair with two elements

	for(int i = 0 ; i < n ;i++){
		
		for(int j = 0 ; j < m ;j++){

			if( arr1[i] == arr2[j] && visited[j] == 0){
				//visited[j] == 0 makes sure this element has not created a pair yet
				ans.push_back(arr1[i]);
				visited[j] = 1;
				break;
			}else if( arr2[j] > arr1[i]){
				break;
			}
		}
	}

	//TC:(n + m) and SC:O(m)
	return ans;
}


// Optimal Two pointer approach : TC:O(n + m ) and SC:O(min(n,m)) for result vector - since in the worst case all elements of the smaller array may be present in the larger array and SC:O(1) extra space
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i = 0 ;
	int j = 0 ;
	vector<int> ans;

	while( i < n && j < m){

		if(arr1[i] == arr2[j]){
			ans.push_back(arr1[i]);
			i++;
			j++;
		}

		else if( arr1[i] < arr2[j]){
			i++;
		}
		else{
			j++;
		}
	}

	// TC :O(n + m ) since at every step both i and j may not be incremented 
	// Consider the case where i and j are incremented in turns . Once i is incremented and then j and then i again and so on 
	//Any two-pointer merge-type algorithm (like merge sort, union, intersection) is almost always: O(n + m)
	// and SC:(1)
	return ans;
}