#include "../../utils.h"

/**
 * Write an algorithm such that uf an element in an MxN matrix is 0, its entire row and column are set to 0
 */

void nullifyRow(vector<vector<int>>& data, int row){
    for(int i = 0; i < data[0].size(); i++){
        data[row][i] = 0;
    }
}

void nullifyColumn(vector<vector<int>>& data, int col){
    for(int i = 0; i < data.size(); i++){
        data[i][col] = 0;
    }
}

void checkForZero(vector<vector<int>>& data){

    vector<bool> rows(data.size(), false);
    vector<bool> cols(data[0].size(), false);
    // Run through the matrix and mark rows & columns that have zeros in them
    for (int row = 0; row < data.size(); row++){
        for(int col = 0; col < data[row].size(); col++){

            if(data[row][col] == 0){
                rows[row] = true;
                cols[col] = true;
            }
        }
    }

    // Nullify rows with zero in them
    for(int i = 0; i < rows.size(); i++){
        if(rows[i]){
            nullifyRow(data, i);
        }
    }
    //Nullify columns with zero in them
    for(int i = 0; i < cols.size(); i++){
        if(cols[i]){
            nullifyColumn(data, i);
        }
    }
}

int main(){
    vector<vector<int>> v {{1, 2, 0},
                           {4, 5, 0},
                           {0, 8, 9}};
    checkForZero(v);

    printVectorList(v);

    return 1;
}