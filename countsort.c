#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void countsort(int arr[], int n){
    int max = arr[0];
    int i;
    for(i=0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    } //find max and make array of size max-1

    int count[max+1];
    memset(count,0,sizeof(count)); //set all values of count array to 0

    for(i=0;i<n;i++){
        count[arr[i]]++;
    }//populate count array
    
    int k=0;

    for(i=0;i<=max;i++){
        while(count[i]>0){          //checks number of occurences in count array
                arr[k]=i;           //assigning index of count array to k position
                k++;                //traversing main array
                count[i]--;         
        }
    }
}



int main(){
    int arr[] = {1,5,2,3,5};
    int n = 5;
    countsort(arr,n);
    int i;
    for(i=0;i<=n-1;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}