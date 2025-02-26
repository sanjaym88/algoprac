#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void insert(int arr[],int n){
    int i,j,v;
    for(i=1;i<n;i++){
        v = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>v){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=v;

    }
}


int main(){
    int arr[]={3,6,1,8,5};
    int n=5;
    int i;
    insert(arr,n);
    for(i=0;i<n;i++)
        printf("%d",arr[i]);
    return 0;
}