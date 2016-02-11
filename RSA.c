/*
 * references
 * http://www.sillycodes.com/2014/12/prime-number-program-in-c-using-sqrt.html
 * http://blockofcodes.blogspot.com/2013/02/c-program-to-generate-prime-factor.html
 */

#include <stdio.h>
#include <stdlib.h>

int isPrime(int);
int N,p,q,e,d;
int getCoprime(int);
int getMultiInverse(int,int);
int encrypt(int);
int decrypt(int);
int f=0;
int primeFactors(int);
int main(int argc, char** argv) {
    
    printf("Enter First Prime\n");
    if (scanf(" %d", &p)  != 1) { 
    }  
    f=isPrime(p);
    if (f == 0) {
        printf("Not a Prime\n");
        getchar();
        exit(1);
    }
    
    printf("Enter second Prime\n");
    if (scanf(" %d", &q)  != 1) { 
    }
    f=isPrime(q);
    if (f == 0) {
        printf("Not a Prime\n");
        getchar();
        exit(1);
    }
    
    
    
    N=p*q;  
    e=getCoprime((p-1)*(q-1));
    printf("Value of e:%d\n",e);
    
    d=getMultiInverse(e,(p-1)*(q-1));
    printf("Value of d:%d\n",d);

    
    return 0;
}

int isPrime(int num){
        int i=0;
       for(i=2;i<sqrt(num);i++)
       {
           if(num%i == 0){
               return 0;
           }
       }
        return 1;
}

int getCoprime(int n)
{
    int num=n;
    int c=0;
    int array[n];
    
    int   div = 2;   
    while(n!=0){
        if(n%div!=0)
            div = div + 1;
        else {
            n = n / div;
            array[c]=div;
            c++;       
            if(n==1){
                break;
            }
            
        }
    }
    
    int i=0;
    int j=0;
    int N[num];
    for (j=1;j<num;j++){
        N[j]=j;
    }
    
    for(j=1;j<num;j++){
        for(i=0;i<c;i++){   
            if(N[j]%array[i]==0){
                N[j]=0;
            }
        }
    }
    
    int coPrimeList[num];
    int s=0;
    for(j=1;j<num;j++){
        if(N[j]!=0){
            //printf("%d\n",N[j]);
            coPrimeList[s]=N[j];
            s++;
        }
        
    }
   
    return coPrimeList[s/2];
}

//int getCoprime(int num){
//    int p=primeFactors(num);
//    return p;
//}

int getMultiInverse(int num, int N){
    int i=0;
    while(1){
        if((num*i)%N==1){
            return i;
        }
        i++;
    }
    return 0;
}