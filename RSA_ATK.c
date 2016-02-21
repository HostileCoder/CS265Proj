/*
 * RSA_ATK.c
 *
 *  Created on: Feb 20, 2016
 *      Author: RollRoll
 */

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void BigFFA(mpz_t);

int main(int argc, char** argv) {
	//printf("%d\n",FFA(221));

	mpz_t N;
	mpz_init_set_str(N, "221", 10);
	BigFFA(N);
	mpz_clear(N);
}

void BigFFA(mpz_t N){
	mpz_t zero,y,one,ans,NplusYsq,Ysqtr;

	mpz_init_set_str(zero, "0", 10);
	mpz_init_set_str(y, "0", 10);
	mpz_init_set_str(one, "1", 10);

	mpz_init_set_str(NplusYsq, "0", 10);
	mpz_init_set_str(Ysqtr, "0", 10);
	mpz_init_set_str(ans, "0", 10);

	if(mpz_even_p (N)!=0){
	    printf("2\n");
		return;
	}
	if(mpz_probab_prime_p(N,45)==2){
		gmp_printf("%Zd\n",N);
		return;
	}




	while(1){
		 mpz_mul(Ysqtr, y, y);
		 mpz_add(NplusYsq,Ysqtr,N);
		 if(mpz_perfect_square_p(NplusYsq)!=0){
			 break;
		 }
		 mpz_add(y,y,one);
	}

	mpz_sub(ans, NplusYsq, y);
	gmp_printf(":%Zd\n",NplusYsq);
	gmp_printf(":%Zd\n",y);
	gmp_printf(":%Zd\n",ans);

}

int FFA(int n){
	if(n%2==0)
		return 2;
	if(isPrime(n)==1)
		return n;

	int y=0;
	while(isSquare(n+y*y)==0){
		y++;
	}
	return sqrt(n+y*y)-y;

}

int isSquare(int n){
	float f;
	int i;
	f = sqrt(n) ;
	i = f ;
	if (f == i) {
		return 1;
	}
	return 0;
}

int isPrime(int n){
	   int i=0;
       for(i=2;i<sqrt(n);i++)
       {
           if(n%i == 0){
               return 0;
           }
       }
        return 1;
}
