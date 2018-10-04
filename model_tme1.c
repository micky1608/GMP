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
	mpz_init(value);

	fibonacci(index , value);

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

	mpz_mul(op1,M1[0][0],M2[0][0];
	mpz_mul(op2,M1[0][1],M2[1][0]; 
	mpz_add(x,op1,op2);

	mpz_mul(op1,M1[0][0],M2[0][1];
	mpz_mul(op2,M1[0][1],M2[1][1]; 
	mpz_add(y,op1,op2);

	mpz_mul(op1,M1[1][0],M2[0][0];
	mpz_mul(op2,M1[1][1],M2[1][0]; 
	mpz_add(z,op1,op2);

	mpz_mul(op1,M1[1][0],M2[0][1];
	mpz_mul(op2,M1[1][1],M2[1][1]; 
	mpz_add(t,op1,op2);

	mpz_set_ui(M1[0][0] , x);
	mpz_set_ui(M1[0][1] , y);
	mpz_set_ui(M1[1][0] = z);
	mpz_set_ui(M1[1][1] = t);

	mpz_clear(x);
	mpz_clear(y);
	mpz_clear(z);
	mpz_clear(t);
	mpz_clear(op1);
	mpz_clear(op2);
	
}

/************************************************************************************* */

void power(mpz_t M[2][2] , mpz_t n) {

}
