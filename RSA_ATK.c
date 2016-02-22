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
void BigFFA2(mpz_t);

int main(int argc, char** argv) {
	//printf("%d\n",FFA(221));

	mpz_t N;
	mpz_init_set_str(N, "316033277426326097045474758505704980910037958719395560565571239100878192955228495343184968305477308460190076404967552110644822298179716669689426595435572597197633507818204621591917460417859294285475630901332588545477552125047019022149746524843545923758425353103063134585375275638257720039414711534847429265419", 10);
	BigFFA2(N);
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
		 printf("%d\n","d");
		 mpz_mul(Ysqtr, y, y);
		 mpz_add(NplusYsq,Ysqtr,N);
		 if(mpz_perfect_square_p(NplusYsq)!=0){
			 break;
		 }
		 mpz_add(y,y,one);
	}

	mpz_sqrt(NplusYsq,NplusYsq);
	mpz_sub(ans, NplusYsq, y);
	gmp_printf("%Zd\n",ans);

}


void BigFFA2(mpz_t N){
	mpz_t a,b2,one,rem,sq,ans,b,Pm1,Qm1,p,q,pqM1,d,e,c;
	mpz_init_set_str(one, "1", 10);
	mpz_init_set_str(b2, "1", 10);
	mpz_init_set_str(a, "1", 10);
	mpz_init_set_str(rem, "1", 10);
	mpz_init_set_str(sq, "1", 10);
	mpz_init_set_str(ans, "1", 10);
	mpz_init_set_str(b, "1", 10);
	mpz_init_set_str(Pm1, "1", 10);
	mpz_init_set_str(Qm1, "1", 10);
	mpz_init_set_str(p, "1", 10);
	mpz_init_set_str(q, "1", 10);
	mpz_init_set_str(pqM1, "1", 10);
	mpz_init_set_str(d, "1", 10);
	mpz_init_set_str(e, "17", 10);
	mpz_sqrtrem(a,rem,N);
	mpz_add(a,a,one);
	mpz_mul(sq, a, a);
	mpz_sub(b2, sq, N);

	while(mpz_perfect_square_p(b2)==0){
		mpz_add(a,a,one);
		mpz_mul(sq, a, a);
		mpz_sub(b2, sq, N);
	}

	mpz_sqrt(b,b2);
	mpz_sub(p, a, b);
	mpz_add(q, a, b);

	mpz_sub(Pm1, p, one);
	mpz_sub(Qm1, q, one);
	mpz_mul(pqM1, Pm1, Qm1);
	mpz_invert(d,e,pqM1);

	gmp_printf("p:   		%Zd\n",p);
	gmp_printf("q:   		%Zd\n",q);
	gmp_printf("p-1: 		%Zd\n",Pm1);
	gmp_printf("q-1: 		%Zd\n",Qm1);
	gmp_printf("(p-1)(q-1): %Zd\n",pqM1);
	gmp_printf("d: 			%Zd\n",d);

	mpz_init_set_str(c, "6553737221362549160467829576342303867230194078458614544455788969208029481986028792492547434668066713199741381758065961061995002107860154452799857795971736508536768368771616799261668162539134913957419310641713821039539526627103122788149293368223969280354360846637109616466207418440363036312473649455733021730", 10);
	Decrypt(d,N,c);

}

void Decrypt(mpz_t d,mpz_t N,mpz_t c){
	mpz_t m;
	mpz_init_set_str(m, "0", 10);
	mpz_powm_sec(m,c,d,N);
	gmp_printf("m:%Zd\n",m);
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
