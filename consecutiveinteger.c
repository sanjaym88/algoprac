#include <stdio.h>

int gcd(int a,int b){
    int t = (a < b) ? a : b;
    while(t>0){
        if(a%t==0&&b%t==0){
            return t;
    }
    t--;
    }
    return 1;
}

int main(){
    int p;
    p = gcd(32,4);
    printf("%d",p);
}