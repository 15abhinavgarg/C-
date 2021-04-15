#include <iostream>
using namespace std;

int partition( int *a , int s , int e){
    int pivot = a[e];
    int i = s-1;
    int j = s;
    for ( ;j < e; j++){
        if (a[j] <= pivot){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;

}

void quicksort( int *a, int s, int e){
    if( s>= e){
        return;
    }
    int p = partition(a,s,e);
    quicksort(a,s,p-1); //because pivot element has been inserted in its right place.
    quicksort(a,p+1,e);
}

int main(){
    int a[] = {1,209,2,333,23,65,3};
    int n = sizeof(a)/sizeof(int);
    quicksort(a,0,n-1);
    for ( int i = 0 ; i < n ;i++){
        cout<<a[i]<<", ";
    }
    return 0;
}