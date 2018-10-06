#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <error.h>

// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/


/************************************************************************************* */

void fibonacci(mpz_t,mpz_t);
void fibonacci_log(mpz_t index , mpz_t value);

void multiply(mpz_t M1[2][2] , mpz_t M2[2][2]);
void power(mpz_t M[2][2] , mpz_t n);


/************************************************************************************* */

int main(int argc, char*argv[]) {

	if(argc != 2) {
		perror("Arguments invalides");
		exit(-1);

	}
	
	mpz_t index;
	mpz_init(index);
	mpz_set_ui(index,atoi(argv[1]));

	if(mpz_cmp_ui(index,0) < 0) {
		perror("L'index n'est pas positif");
		mpz_clear(index);
		exit(-1);
	}

	printf("Index : ");
	mpz_out_str(stdout,10,index);
	printf("\n");

	mpz_t value;
	mpz_t value2;
	mpz_init(value);
	mpz_init(value2);

	fibonacci(index , value);
	fibonacci_log(index , value2);

	mpz_clear(index);	
	mpz_clear(value);

	return 0;
}


/************************************************************************************* */

void fibonacci(mpz_t index , mpz_t value) {
	
	mpz_t i;
	mpz_t tab[2];

	mpz_init(i);
	mpz_init(tab[0]);
	mpz_init(tab[1]);

	mpz_set_ui(tab[0],1);
	mpz_set_ui(tab[1],1);
	

	for(mpz_set_ui(i,2) ; mpz_cmp(i,index) <= 0 ; mpz_add_ui(i,i,1)) {
		mpz_add(value,tab[0],tab[1]);

		printf("Index : ");
		mpz_out_str(stdout,10,i);
		printf("\tValue : ");
		mpz_out_str(stdout,10,value);
		printf("\n");

		mpz_set(tab[0],tab[1]);
		mpz_set(tab[1],value);
	}

	mpz_clear(tab[0]);
	mpz_clear(tab[1]);
	mpz_clear(i);

}

/************************************************************************************* */

void fibonacci_log(mpz_t index , mpz_t value) {

    if(!mpz_cmp_ui(index,0)) {
        mpz_set_ui(value,0);
        return;
    }

    mpz_t F[2][2];
    mpz_t i;

    mpz_init(F[0][0]);
    mpz_init(F[0][1]);
    mpz_init(F[1][0]);
    mpz_init(F[1][1]);
    mpz_init(i);

    mpz_set_ui(F[0][0] , 1);
    mpz_set_ui(F[0][1] , 1);
    mpz_set_ui(F[1][0] , 1);
    mpz_set_ui(F[1][1] , 0);
    mpz_add_ui(i,index , 1);


    mpz_sub_ui(i,i,1);
    power(F,i);

    mpz_set(value,F[0][0]);

    mpz_clear(F[0][0]);
    mpz_clear(F[0][1]);
    mpz_clear(F[1][0]);
    mpz_clear(F[1][1]);
    mpz_clear(i);

    printf("\t***** Fibonacci_log *****\n");
    printf("Index : ");
    mpz_out_str(stdout,10,index);
    printf("\nValue : ");
    mpz_out_str(stdout,10,value);
    printf("\n");
}

/************************************************************************************* */

void multiply(mpz_t M1[2][2] , mpz_t M2[2][2]) {
	
	mpz_t x,y,z,t,op1,op2;

	mpz_init(x);
	mpz_init(y);
	mpz_init(z);
	mpz_init(t);
	mpz_init(op1);
	mpz_init(op2);

	mpz_mul(op1,M1[0][0],M2[0][0]);
	mpz_mul(op2,M1[0][1],M2[1][0]);
	mpz_add(x,op1,op2);

	mpz_mul(op1,M1[0][0],M2[0][1]);
	mpz_mul(op2,M1[0][1],M2[1][1]);
	mpz_add(y,op1,op2);

	mpz_mul(op1,M1[1][0],M2[0][0]);
	mpz_mul(op2,M1[1][1],M2[1][0]);
	mpz_add(z,op1,op2);

	mpz_mul(op1,M1[1][0],M2[0][1]);
	mpz_mul(op2,M1[1][1],M2[1][1]);
	mpz_add(t,op1,op2);

	mpz_set(M1[0][0] , x);
	mpz_set(M1[0][1] , y);
	mpz_set(M1[1][0] , z);
	mpz_set(M1[1][1] , t);

	mpz_clear(x);
	mpz_clear(y);
	mpz_clear(z);
	mpz_clear(t);
	mpz_clear(op1);
	mpz_clear(op2);
	
}

/************************************************************************************* */

void power(mpz_t M[2][2] , mpz_t n) {
    if (mpz_cmp_ui(n,0)==0 || mpz_cmp_ui(n,1)==0) return;

    mpz_t N[2][2];
    mpz_t m;

    mpz_init(m);
    mpz_init(N[0][0]);
    mpz_init(N[0][1]);
    mpz_init(N[1][0]);
    mpz_init(N[1][1]);

    mpz_set_ui(N[0][0] , 1);
    mpz_set_ui(N[0][1] , 1);
    mpz_set_ui(N[1][0] , 1);
    mpz_set_ui(N[1][1] , 0);

    mpz_div_ui(m,n,2);
    power(M , m);
    multiply(M,M);


    if(mpz_odd_p(n))
        multiply(M,N);

    mpz_clear(N[0][0]);
    mpz_clear(N[0][1]);
    mpz_clear(N[1][0]);
    mpz_clear(N[1][1]);
    mpz_clear(m);
}
