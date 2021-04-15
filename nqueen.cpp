#include<iostream>
#include<cstring>
using namespace std;
void display ( int arr[][10],int k){
    for ( int i = 0 ; i < k; i++){
        for ( int j = 0 ; j < k; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe ( int arr[][10], int i , int j , int n){ //is it safe to put queen at this position.

    for ( int row = 0 ; row < i ; row++){ // checking the above columns
        if ( arr[row][j] == 1){
            return false;
        }
    }
    //checking for left diagonal
    int x = i;
    int y = j;
    while ( x >= 0 and y < n){
        if ( arr[x][y] == 1){
            return false; //cause there is a queen
        }
        x--;
        y--;
    }
     x = i;
     y = j;
     //check the right diagonal
    while ( x >= 0 and y >=0){
        if ( arr[x][y] == 1){
            return false; //cause there is a queen
        }
        x--;
        y++;
    }

    // if false is not returned than it is safe to put the queen at that location
    return true;
}

bool nqueen ( int arr[][10] , int i , int n ){
    //base case
    if ( i >= n){
        // Print the board
        display(arr,n);
        cout<<endl<<endl;
        return false; //if we return as false all the config would be generated //for 1 it should be true
    }
    //recursive case
    //try to place the queen on the current row rest will be taken care by recursion
    for ( int j = 0 ; j < n ; j++){
        if ( isSafe(arr , i, j , n)){ // is it safe to place the queen at i and j position
            arr[i][j] = 1;
            // means i j is the right position
            bool nextqueen_rakhparahe = nqueen(arr,i+1,n);
            if (nextqueen_rakhparahe){
                return true;
            }

            // if the func is coming here it means i , j is not right place
            arr[i][j] = 0; // backtracking since we wrongly placed the queen
        }
    }
    //we couldn't place queen anywhere 
    return false;

}

int main(){
    //cout<< "Hello" <<endl;
    int n;
    cin>>n;
    int arr[10][10] = {0};
    nqueen(arr, 0 , n);
    //cout<<arr<<endl; //printing the address
    //display(arr,n);
    return 0;
}
