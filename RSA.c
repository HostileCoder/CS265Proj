/*
 * references
 * http://www.sillycodes.com/2014/12/prime-number-program-in-c-using-sqrt.html
 * http://blockofcodes.blogspot.com/2013/02/c-program-to-generate-prime-factor.html
 */

#include <stdio.h>
#include <stdlib.h>

int size=500;
long int isPrime(long int);
long int N,p,q,e,d;
long int getCoprime(long int);
long int getMultiInverse(long int,long int);
long int encrypt(long int,long int,long int);
long int decrypt(long int,long int,long int);
int f=0;
long int C;


int main(int argc, char** argv) {
	long int M[size];
	char input[size];

//	long int t=2;
//	long int c=1;
//	long int j=0;
//	for(j=0;j<0;j++)
//		c=c*t;
//	 printf("%d\n",c);

    printf("Enter First Prime\n");
    fflush(stdout);
    if (scanf(" %d", &p)  != 1) {
    }
    f=isPrime(p);
    if (f == 0) {
        printf("Not a Prime\n");
        getchar();
        exit(1);
    }

    printf("Enter second Prime\n");
    fflush(stdout);
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


    printf("Enter Message\n");
    fflush(stdout);
    if (scanf("%s", &input)  != 1) {
    }
    
    //printf("%s",input);

    int i=0;
//    for(i=0;i<size;i++)
//    	M[i]=input[i];

    for(i=0;i<size;i++){
    	input[i]=encrypt(e,N,input[i]);
    }

    printf("%s\n",input);


//    for(i=0;i<size;i++)
//    	M[i]=input[i];

    for(i=0;i<size;i++){
    	input[i]=decrypt(d,N,input[i]);
    }

    printf("%s\n",input);

    return 0;
}

//--------------------------------------------------
long int isPrime(long int num){
	   long int i=0;
       for(i=2;i<sqrt(num);i++)
       {
           if(num%i == 0){
               return 0;
           }
       }
        return 1;
}

long int getCoprime(long int n)
{
	long int num=n;
	long int c=0;
	long int primef[n];
    
    //find prime factor of num. Store in primef
    int   div = 2;   
    while(n!=0){
        if(n%div!=0)
            div = div + 1;
        else {
            n = n / div;
            primef[c]=div;
            c++;       
            if(n==1){
                break;
            }
            
        }
    }
    
    //find list of coprime from prime factors
    long int i=0;
    long int j=0;
    long int N[num];
    for (j=1;j<num;j++){	//array of 1-num
        N[j]=j;
    }
    
    //replace N[j] with 0 if not coprime
    for(j=1;j<num;j++){
        for(i=0;i<c;i++){   
            if(N[j]%primef[i]==0){
                N[j]=0;
            }
        }
    }
    
    //extract coprime list from N[]
    long int coPrimeList[num];
    long int s=0;
    for(j=1;j<num;j++){
        if(N[j]!=0){
            coPrimeList[s]=N[j];
            s++;
        }
        
    }


//    for(j=0;j<s;j++){
//    	printf("%d ",coPrimeList[j]);
//    }

    //randomly choose a coprime
    while(1){
    	long int r=rand() % s;
    	long int x =coPrimeList[r];
    	if(x!=p&&x!=q){
    		return x;
    	}
    }

}


long int getMultiInverse(long int num, long int N){
    int i=0;
    while(1){
        if((num*i)%N==1){
            return i;
        }
        i++;
    }
    return 0;
}


long int encrypt(long int e,long int N,long int M){
	long int i;
	long int C=1;
	for(i=0;i<e;i++)
		C=C*M;
	C=C%N;
	return C;
}

long int decrypt(long int d,long int N,long int C){
	long int i;
	long int M=1;
	for(i=0;i<d;i++)
		M=M*C;
	M=M%N;
	return M;
}
