/*
You are given a 2D matrix, a, of dimension MxN and a positive integer R. You have to rotate the matrix R times and print the resultant matrix. Rotation should be in anti-clockwise direction.

Rotation of a 4x5 matrix is represented by the following figure. Note that in one rotation, you have to shift elements by one step only (refer sample tests for more clarity).

matrix-rotation

It is guaranteed that the minimum of M and N will be even.

Input
First line contains three space separated integers, M, N and R, where M is the number of rows, N is number of columns in matrix, and R is the number of times the matrix has to be rotated.
Then M lines follow, where each line contains N space separated positive integers. These M lines represent the matrix.

Output
Print the rotated matrix.

Constraints
2 <= M, N <= 300
1 <= R <= 109
min(M, N) % 2 == 0
1 <= aij <= 108, where i ∈ [1..M] & j ∈ [1..N]

Sample Input #00

4 4 1
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sample Output #00

2 3 4 8
1 7 11 12
5 6 10 16
9 13 14 15
Sample Input #01

4 4 2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sample Output #01

3 4 8 12
2 11 10 16
1 7 6 15
5 9 13 14
Sample Input #02

5 4 7
1 2 3 4
7 8 9 10
13 14 15 16
19 20 21 22
25 26 27 28
Sample Output #02

28 27 26 25
22 9 15 19
16 8 21 13
10 14 20 7
4 3 2 1
Sample Input #03

2 2 3
1 1
1 1
Sample Output #03

1 1
1 1
Explanation
Sample Case #00: Here is an illustration of what happens when the matrix is rotated once.

 1  2  3  4      2  3  4  8
 5  6  7  8      1  7 11 12
 9 10 11 12  ->  5  6 10 16
13 14 15 16      9 13 14 15
Sample Case #01: Here is what happens when to the matrix after two rotations.

 1  2  3  4      2  3  4  8      3  4  8 12
 5  6  7  8      1  7 11 12      2 11 10 16
 9 10 11 12  ->  5  6 10 16  ->  1  7  6 15
13 14 15 16      9 13 14 15      5  9 13 14
Sample Case #02: Following are the intermediate states.

1  2  3  4      2  3  4 10    3  4 10 16    4 10 16 22
7  8  9 10      1  9 15 16    2 15 21 22    3 21 20 28
13 14 15 16 ->  7  8 21 22 -> 1  9 20 28 -> 2 15 14 27 ->
19 20 21 22    13 14 20 28    7  8 14 27    1  9  8 26
25 26 27 28    19 25 26 27    13 19 25 26   7 13 19 25



10 16 22 28    16 22 28 27    22 28 27 26    28 27 26 25
 4 20 14 27    10 14  8 26    16  8  9 25    22  9 15 19
 3 21  8 26 ->  4 20  9 25 -> 10 14 15 19 -> 16  8 21 13
 2 15  9 25     3 21 15 19     4 20 21 13    10 14 20  7
 1  7 13 19     2  1  7 13     3  2  1  7     4  3  2  1
Sample Case #03: As all elements are same, any rotation will reflect the same matrix.
*/

#include <iostream>
#include <vector>
using namespace std;

//  You will implement this
vector<vector<int>> matrixRotation(vector<vector<int>>& matrix, int R){
    int m = matrix.size();
    int n = matrix[0].size();

    // We will solve this layer by layer. We will rotate each layer R times and place the elements in the correct position in the answer matrix.

    int layers = min(m,n) / 2;

    // TC:O(mxn) 
    for(int layer = 0 ; layer < layers ; layer++){
        // Convert to 1D array and rotate it R times and place back in answer matrix

        vector<int> temp;

        int top = layer ;
        int right= n - 1 - layer ;
        int bottom = m - 1 - layer ;
        int left = layer ;

        //Top Row
        for(int i  = left ; i <=right ; i++){
            temp.push_back(matrix[top][i]);
        }
        // Right column 
        for(int i = top + 1 ; i <bottom ; i++){
            temp.push_back(matrix[i][right]);
        }

        // Bottom row 
        for(int i = right ; i >=left ; i--){
            temp.push_back(matrix[bottom][i]);
        }

        // Left column 
        for(int i = bottom - 1 ; i >=top +1 ; i--){
            temp.push_back(matrix[i][left]);
        }


        // Rotate temp R times to the left and place back in answer matrix
        int len = temp.size();
        int rot = R % len;
        reverse(temp.begin() , temp.begin() + rot );
        reverse(temp.begin() + rot , temp.end());
        reverse(temp.begin() , temp.end());

        int idx = 0 ;

        // put back in answer matrix
        //Top Row
        for(int i  = left ; i <=right ; i++){
            matrix[top][i] = temp[idx++];
        }
        // Right column
        for(int i = top + 1 ; i <bottom ; i++){
            matrix[i][right] = temp[idx++];
        }
        // Bottom row
        for(int i = right ; i >=left ; i--){
            matrix[bottom][i] = temp[idx++];
        }
        // Left column
        for(int i = bottom - 1 ; i >=top +1 ; i--){
            matrix[i][left] = temp[idx++];
        }
        
    }

    //TC:O(m x n) SC:O( 2(m+n)) for temp array
    return matrix;
}

// Helper to compare matrices
bool areEqual(vector<vector<int>>& a, vector<vector<int>>& b) {
    if (a.size() != b.size() || a[0].size() != b[0].size())
        return false;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

// Helper to print matrix
void printMatrix(vector<vector<int>>& mat) {
    for (auto &row : mat) {
        for (auto &x : row) cout << x << " ";
        cout << endl;
    }
}

int main() {

    // ---------- Test Case 1 ----------
    vector<vector<int>> mat1 = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int R1 = 1;

    vector<vector<int>> expected1 = {
        {2,3,4,8},
        {1,7,11,12},
        {5,6,10,16},
        {9,13,14,15}
    };

    // ---------- Test Case 2 ----------
    vector<vector<int>> mat2 = mat1;
    int R2 = 2;

    vector<vector<int>> expected2 = {
        {3,4,8,12},
        {2,11,10,16},
        {1,7,6,15},
        {5,9,13,14}
    };

    // ---------- Test Case 3 ----------
    vector<vector<int>> mat3 = {
        {1,2,3,4},
        {7,8,9,10},
        {13,14,15,16},
        {19,20,21,22},
        {25,26,27,28}
    };
    int R3 = 7;

    vector<vector<int>> expected3 = {
        {28,27,26,25},
        {22,9,15,19},
        {16,8,21,13},
        {10,14,20,7},
        {4,3,2,1}
    };

    // ---------- Test Case 4 ----------
    vector<vector<int>> mat4 = {
        {1,1},
        {1,1}
    };
    int R4 = 3;

    vector<vector<int>> expected4 = {
        {1,1},
        {1,1}
    };

    vector<pair<vector<vector<int>>, pair<int, vector<vector<int>>>>> tests = {
        {mat1, {R1, expected1}},
        {mat2, {R2, expected2}},
        {mat3, {R3, expected3}},
        {mat4, {R4, expected4}}
    };

    int testNum = 1;

    for (auto &t : tests) {
        vector<vector<int>> input = t.first;
        int R = t.second.first;
        vector<vector<int>> expected = t.second.second;

        vector<vector<int>> output = matrixRotation(input, R);

        cout << "Test Case " << testNum++ << ": ";

        if (areEqual(output, expected)) {
            cout << "✅ Passed\n";
        } else {
            cout << "❌ Failed\n";

            cout << "Expected:\n";
            printMatrix(expected);

            cout << "Got:\n";
            printMatrix(output);
        }

        cout << "----------------------\n";
    }

    return 0;
}