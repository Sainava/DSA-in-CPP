/*
Problem statement
Your friend Ninja has been learning about binary numbers lately. In order to understand binary numbers with perfection, Ninja asks you to generate a list of binary numbers from 1 to ‘N’, which he can use later for reference.

For every integer Ninja gives, your task is to generate all the binary numbers from 1 to ‘N’.

Example:

Consider N = 5,
All the binary numbers from 1 to 5 are: 1, 10, 11, 100, 101.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10 
1 <= N <= 10 ^ 5

Time Limit: 1 sec
Sample Input 1:
2
2
6
Sample Output 1:
1 10
1 10 11 100 101 110
Explanation 1:
For the first test case when N = 2. 
We need all the binary numbers from 1 to 2:
1 -> 1
2 -> 10
Thus, the output is 1, 10.

For the second test case when N = 6
We need all the binary numbers from 1 to 6:
1 -> 1
2 -> 10
3 -> 11
4 -> 100
5 -> 101
6 -> 110
Thus, the output is 1, 10, 11, 100, 101, 110.
Sample Input 2:
2
8
4
Sample Output 2:
1 10 11 100 101 110 111 1000
1 10 11 100

*/

#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string func(int n){
    string ans="";
    while(n!=0){
        if(n%2 == 1){
            ans.push_back('1');
        }else{
            ans.push_back('0');
        } 
        n= n/2;

    }

    reverse(ans.begin() , ans.end());

    return ans;
}

vector<string> generateBinaryNumbers(int n)
{
    // vector<string> ans;
    // for(int i = 1 ; i<=n ; i++){
    //     ans.push_back( func(i) );
    // }
    
    // //TC:O(n logn) and SC:O(nlogn) because we store n binary numbers and each number can have logn bits
    // return ans;

    //The queue solution is a very popular interview approach because it generates binary numbers in order without converting integers to binary.

    //Start with "1".

    // Every binary number can generate two children:

    // x ? x0
    // x ? x1

    // Example tree:

    //         1
    //       /   \
    //     10     11
    //    /  \   /  \
    // 100 101 110 111

    // If we traverse this level by level, we get:

    // 1
    // 10
    // 11
    // 100
    // 101
    // 110
    // 111

    // This is exactly what we want.

    vector<string> ans ;
    queue<string> q;

    q.push("1");

    // A number n in decimal needs about logn bits in binary 

    // TC:O(nlogn) 
    // n for the outer loop 
    for(int i = 0 ; i < n ; i++){
        string curr = q.front();
        q.pop();

        ans.push_back(curr);

        // Curr will have k bits and k<=logn so copying this would require logn time 
        q.push(curr + "0");
        q.push(curr + "1");

    }

    //TC :O(nlogn)
    // SC:O(nlogn) we store n binary numbers in queue and length of each is <=logn so nlogn
    return ans;


    
}