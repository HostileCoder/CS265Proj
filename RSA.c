/*
 * references
 * http://www.sillycodes.com/2014/12/prime-number-program-in-c-using-sqrt.html
 * http://blockofcodes.blogspot.com/2013/02/c-program-to-generate-prime-factor.html
 */

#include <stdio.h>
#include <stdlib.h>

int size=500;
int isPrime(int);
int N,p,q,e,d;
int getCoprime(int);
int getMultiInverse(int,int);
int encrypt(int,int,char);
int decrypt(int,int,int);
int f=0;
int C;


int main(int argc, char** argv) {
	int M[size];
	char input[size];


    printf("Enter First Prime\n");
    fflush(stdout);
    scanf(" %d", &p);
//    if (scanf(" %d", &p)  != 1) {
//    }
    f=isPrime(p);
    if (f == 0) {
        printf("Not a Prime\n");
        getchar();
        exit(1);
    }

    printf("Enter second Prime\n");
    fflush(stdout);
    scanf(" %d", &q);
//    if (scanf(" %d", &q)  != 1) {
//    }
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

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    fgets (input, 500, stdin);
    printf("Your input:%s",input);

    //encrypt the message
    int i=0;
    int eM[strlen(input)];
    for(i=0;i<strlen(input);i++){
    	 int x =encrypt(e,N,input[i]);
    	 eM[i]=x;
    }

    for(i=0;i<strlen(input);i++)
    	 printf("%c",eM[i]);
    	 printf("\n");

    //decrypt the message
    int dM[strlen(input)];
    for(i=0;i<strlen(input);i++){
    	int x=decrypt(d,N,eM[i]);
    	dM[i]=x;
    }

    for(i=0;i<strlen(input);i++)
    	 printf("%c",dM[i]);
    	 printf("\n");

    return 0;
}

//-----------------------------------------------------------------------------------------
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
	int primef[n];
    
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
    int i=0;
    int j=0;
    int N[num];
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
    int coPrimeList[num];
    int s=0;
    for(j=1;j<num;j++){
        if(N[j]!=0){
            coPrimeList[s]=N[j];
            s++;
        }
        
    }


    //randomly choose a coprime
    while(1){
    	int r=rand() % s;
    	int x =coPrimeList[r];
    	if(x!=p&&x!=q){
    		return x;
    	}
    }

}


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


int encrypt(int e,int N,char M){
	//printf("This Number %d which is %c in Char\n",M,M);
	int i;
	int C=1;
	for(i=0;i<e;i++)
		C=C*M%N;
	C=C%N;

	return C;
}

int decrypt(int d,int N,int C){
	int i;
	int M=1;
	for(i=0;i<d;i++)
		M=M*C%N;
	M=M%N;

	return M;
}
