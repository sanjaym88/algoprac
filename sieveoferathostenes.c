#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void sieve(int n){
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    int p;
    for(p=2;p*p<=n;p++){
        if(prime[p]==true){
            int i;
            for(i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    for(p=2;p<=n;p++){
        if(prime[p]){
            printf("%d ",p);
        }
    }
}


int main(){
    sieve(15);
    return 0;
}