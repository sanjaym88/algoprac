#include <stdio.h>
#include <stdlib.h>

int gcd(int a,int b){
    int temp;
    if(a<b){
        temp = a;
        b = a;
        b = temp;
    }
    while(b!=0){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}   


int main(){
    int a;
    a = gcd(32,4);
    printf("%d",a);
}
