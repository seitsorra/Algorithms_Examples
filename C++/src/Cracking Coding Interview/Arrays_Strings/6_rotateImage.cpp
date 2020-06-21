#include "../../utils.h"

/**
 * Given an image represented by NxN matrix, where each pixel in the image is 4 bytes,
 * write a method to rotate the image by 90 degrees.
 * 
 * Can you do this in place?
 */


/**
 * Because we're rotating the matrix by 90 degrees, the easiest way to do this is to implement the rotation in layers.
 * We perform a circular rotation in each layer, 
 *      moving the top edge to right edge,
 *      moving the right edge to bottom edge
 *      moving the bottom edge to left edge
 *      moving the left edge to top edge
 * 
 * How do we perform this four way edge swap?
 * 
 *  - One way could be copy the top edge to an arrya and move left to top, bottom to left, right to bottom and so on.
 *      - that would require O(n) though which is not necessary
 * 
 *  - A better way is to perform the swap index by index. In this case we do the following:
 *      for i = 0 to n
 *          temp = top[i]
 *          top[i] = left[i]
 *          left[i] = bottom[i]
 *          bottom[i] = right[i]
 *          right[i] = temp
 *      
 *      We perform such opearation on a layer basis starting to the outermost layer and working towards the inner layer.
 */
void rotate(vector<vector<int>>& img){
    int layers = img.size() / 2;

    for(int layerIdx = 0; layerIdx < layers; layerIdx++){
        int first = layerIdx;
        int last = img.size() - 1 - layerIdx;

        int offset = 0; // Offset of the item in the array
        for(int idx = layerIdx; idx < last; idx++){
            offset = idx - first;

            // Save top value
            int top = img[first][idx];

            // left -> top  (13 to 1)
            img[first][idx] = img[last - offset][first];

            // bottom -> left (16 to 13)
            img[last - offset][first] = img[last][last - offset];

            // right -> bottom (4 to 16)
            img[last][last - offset] = img[idx][last];

            img[idx][last] = top;
        }
    }
}

int main(){
    vector<vector<int>> v {{1, 2, 3},
                           {4, 5, 6},
                           {7, 8, 9}};
    rotate(v);

    printVectorList(v);

    return 1;
}