#include<iostream>
using namespace std;

void merge(int *a, int s , int e){
    int mid = (s+e)/2;

    int i = s;
    int j = mid+1;
    int k = s;
    int temp[100];

    while ( i<= mid && j <= e){
        if ( a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }
    while( i <= mid){
        temp[k++] = a[i++]; 
    }
    while (j <= e){
        temp[k++] = a[j++];
    }
    for ( int i =s ; i<= e ; i++){
        a[i] = temp[i];
    }
}


void mergesort(int *a , int s , int e){
    if ( s >= e){
        return;
    }
    int mid = (s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);

    merge(a,s,e);
}

int main(){
    int a[6] = {1,23,5,33,66,7};
    mergesort(a,0,5);
    for ( int i = 0 ; i < 6 ;i++){
        cout<<a[i]<<" , ";
    }
    return 0;
}