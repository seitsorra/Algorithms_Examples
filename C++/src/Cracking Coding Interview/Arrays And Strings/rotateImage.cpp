/*
    Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
    write a method to rotate the image by 90 degrees.
    Can you do this in place?
*/

#include "../../utils.h";
/*
    1  2  3  4    13 9  5  1
    5  6  7  8    14 10 6  2
    9 10 11 12    15 11 7  3
   13 14 15 16    16 12 8  4
*/
// Run time is O(n^2)
void rotate(int arr[][4], int matrixSize){
    for(int layer = 0; layer < matrixSize / 2; layer++){
        int first = layer;
        int last = matrixSize - 1 - layer;

        for(int idx = first; idx < last; idx++){
            int offset = idx - first; 

            // Save top value
            int top = arr[first][idx];

            // left -> top  (13 to 1)
            arr[first][idx] = arr[last - offset][first];

            // bottom -> left (16 to 13)
            arr[last - offset][first] = arr[last][last - offset];

            // right -> bottom (4 to 16)
            arr[last][last - offset] = arr[idx][last];

            arr[idx][last] = top;
        }
    }
}

int main(){
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    rotate(arr, 4);
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            cout << arr[r][c] << " ";
        }
        cout << "\n";
    }
}