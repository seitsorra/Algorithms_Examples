#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
    THREE NUMBER SUM

    Write a function that takes in a non-empy array of distinct integres and an integer
    representing a target sum. The function should find all triplets in the array that sum up
    to the target sum and return a two-dimensional array of all these triplets. The numbers in each
    triplet should be ordered in ascending order, and the triplets themselves should be ordered in
    ascending order with the respect to the numbers they hold. If no three numbers sum up to the target
    sum, the function should return an empty array.

    SAMPLE INPUT:
        - [12,3,1,2,-6,5,-8,6], 0
    
    SAMPLE OUTPUT
        -[[-8,2,6], [-8,3,5], [-6,1,5]]
*/

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++){
        cout << v[i];
        if (i == v.size() - 1){
            cout << endl;
        }
        else{
            cout << " , ";
        }
    }
}

vector<vector<int> > threeNumberSum(vector<int> array, int targetSum) {
    // Write your code here.
	std::sort(array.begin(), array.end());
	vector<vector<int>> ret;
	
	int staticIndex = 0;
	
	while(staticIndex != array.size()-2){
		int left = staticIndex+1;
		int right = array.size()-1;
		
		for(int i = 0; i<array.size() && left < right; i++){
			int sum = array[staticIndex] + array[left] + array[right];
			if(sum == targetSum){
					ret.push_back({array[staticIndex], array[left], array[right]});
					left++;
					right--;
			}
			else if(sum < targetSum){
				left++;
			}
			else{
				right--;
			}
		}
		staticIndex++;
	}
	return ret;
}

int main(){
    vector<vector<int>> exp {{1,2,3}};

    if(threeNumberSum({1,2,3}, 6) == exp){
        cout << "PASSED";
    }
    else{
        cout << "FAILED";
    }
    return 0;
}