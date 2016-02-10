
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int isPrime(int);
int N,p,q,e,d;
int getCoprime(int);
int getMultiInverse(int);
int encrypt(int);
int decrypt(int);
int f;
int main(int argc, char** argv) {
    
    printf("Enter First Prime\n");
    p=getchar();
    f=isPrime(p);
    if (f == 1) {
        printf("Not a Prime\n");
        getchar();
        exit(1);
    }
   
    while((d = getchar()) != '\n' && d != EOF);
    
    printf("Enter second Prime\n");
    q=getchar();
    f=isPrime(q);
    if (f == 1) {
        printf("Not a Prime\n");
        getchar();
        exit(1);
    }
    
    N=p*q;
    e=getCoprime(p*q);
    d=getMultiInverse((p-1)*(q-1));
    
    
    
    return 0;
}

int isPrime(int num){
     if (num <= 1) return 0;
     if (num % 2 == 0) return 1;
     int i;
     for(i = 3; i < num / 2; i+= 2)
     {
         if (num % i == 0)
             return 0;
     }
     return 1;
}

int getCoprime(int num){
    return 0;
}

int getMultiInverse(int num){
    return 0;
}