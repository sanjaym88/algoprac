#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void sortlist(int arr1[],int arr2[],int m, int n,int result[]){
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            result[k++]=arr1[i++];
        }
        else{
            result[k++]=arr2[j++];
        }
    }

    while(i<m){
        result[k++] = arr1[i++];
    }

    while(j<n){
        result[k++]=arr2[j++];
    }//if m and n are not equal then the remaining numbers are printed as it is
}
int main(){
    int arr1[] = {2,5,7,12,13,14};
    int arr2[] = {1,6,15,17,35};

    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    int result[m+n];

    sortlist(arr1,arr2,m,n,result);

    int i;
    for(i=0;i<m+n;i++){
        printf("%d ",result[i]);
    }
    return 0;
}