#include<iostream>
using namespace std;
void display ( int arr[][9]){
    for ( int i = 0 ; i < 9 ; i++){
        for ( int j = 0 ; j < 9 ; j++ ){
            cout << arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int mat[9][9] = {               
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,6,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    display(mat);
}