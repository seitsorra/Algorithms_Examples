/*
    River Sizes
    
    You are given a two dimensional array (matrix) of potentially unequal height and width containing
    only 0s and 1s.
    Each '0' represents land, and each '1' represents part of a river.
    A river consists of any number of 1s that are either horizontally or vertically adjacent (but not diagonally adjecent)
    The number of adjecent 1s forming a river determines its size.

    Write a function that returns an array of the sizes of all rivers represented in the input matrix.
    NOTE: these sizes do not need to be in any particular order.

    Sample input:
        [
            [1, 0, 0, 1, 0],
            [1, 0, 1, 0, 0],
            [0, 0, 1, 0, 1],
            [1, 0, 1, 0, 1],
            [1, 0, 1, 1, 0]
        ]

    Sample output: [1, 2, 2, 2, 5]
*/
#include "utils.h"

/**
 * given a matrix index this function will check its neighbouring nodes (Left, Right, Top, Bottom) if they are visited
 * 
 * It returns a vector of vector<int> ([0]-row, [1]-col) representing the unvisited neighbouring nodes 
 */
vector<vector<int>> getUnvisitedNeighboring(int i, int j, const vector<vector<int>>& matrix, const vector<vector<bool>>& visited){
    vector<vector<int>> unvisited;

    // Left node
    int x = i;
    int y = j;

    x = i - 1;
    if(x >= 0 && !visited[x][y]){
        unvisited.push_back({{x,y}});
    }

    // Right Node
    x = i + 1;
    if(x < matrix[0].size() && !visited[x][y]){
        unvisited.push_back({{x,y}});
    }

    // Top node
    x = i;
    y = j - 1;
    if(y >= 0 && !visited[x][y]){
        unvisited.push_back({{x,y}});
    }

    // Bottom Node
    y = j + 1;
    if(y < matrix.size() && !visited[x][y]){
        unvisited.push_back({{x,y}});
    }

    return unvisited;
}

void traverseNode(vector<int>& sizes, int row, int col, const vector<vector<int>>& matrix, vector<vector<bool>>& visited){
    /*
        Here we are going to make use of DEPTH FIRST SEARCH ALGORITHM and traverse to all nodes while maintaining the visited flag
    */

    int riverSize = 0;

    vector<vector<int>> nodesToVisit {{row, col}};
    // Keep traversing until we arrive in a node which is a land and also all its neighbouring nodes are also land
    while (nodesToVisit.size() != 0){
        vector<int> currentNode = nodesToVisit.back();
        nodesToVisit.pop_back();
        int i = currentNode[0];
        int j = currentNode[1];

        if(visited[i][j]){
            continue;
        }
        // Mark as visited
        visited[i][j] = true;

        if(matrix[i][j] == 0){
            continue;
        }
        riverSize += 1;
        vector<vector<int>> unvisited = getUnvisitedNeighboring(i, j, matrix, visited);
        for(int r = 0; r < unvisited.size(); r++){
            nodesToVisit.push_back(unvisited[r]);
        }
    }
    if(riverSize > 0){
        sizes.push_back(riverSize);
    }
}

vector<int> riverSizes(vector<vector<int>> matrix){

    // Create a copy of the matrix to keep track of visited nodes (matrix indexes) as we traverse through the matrix
    vector<vector<bool>> visited (matrix.size(), vector<bool>(matrix[0].size(), false));

    vector<int> ret; // vector with river sizes that this function will return

    // This is the main loop where we traverse the matrix
    for(int row = 0; row < matrix.size(); row++){
        for (int col = 0; col < matrix[row].size(); col++){
            if(visited[row][col]){
                continue;
            }
            // A helper function that will get a matrix index and check if it is a land or river
            // If it is a river will keep going on unvisited neighbouring nodes and check them as well of there are land or river
            traverseNode(ret, row, col, matrix, visited);
        }
        
    }
    std::sort(ret.begin(), ret.end());
    return ret;
}

struct TestCase{
    vector<vector<int>> matrix;
    vector<int> result;
};

int main(){
    vector<TestCase> cases;
    TestCase test;

    // Test Case 1
    test.matrix = {{1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, {0, 0, 1, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 0}};

    test.result = {1, 2, 2, 2, 5};
    cases.push_back(test);

    for (int i = 0; i < cases.size(); i++) {
        vector<int> ret = riverSizes(cases[i].matrix);
        if(ret == cases[i].result){
            cout << "Test Case " << i+1 << " PASSED!" << endl;
        }
        else{
            cout << "Test Case " << i+1 << " FAILED! (Expected \n";
            printVector(cases[i].result);
            cout << "\n Got \n";
            printVector(ret);
        }
    }
    return 0;
}