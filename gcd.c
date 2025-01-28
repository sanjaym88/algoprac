#include <stdio.h>
int gcd(int a,int b){
    int t=(a<b)?a:b;
    while(t>0){
        if(a%t==0&&b%t==0){
            return t;
        }
        t--;
        }
    }

int main(){

int t = gcd(16,12);
printf("%d",t);
return 0;
}