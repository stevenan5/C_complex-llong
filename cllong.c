#include<stdio.h>
#include "cllong.h"

int main(){

	cllong t1, t2, t3, res;

	cll_set(&t1, 3LL, 4LL);
	printf("set real/imag\n");
	cll_print(t1);

	cll_get(&t2, t1);
	printf("use get function\n");
	cll_print(t2);
	
	cll_add(&t3, t1, t2);
	printf("use add\n");
	cll_print(t3);

	cll_sub(&res, t1, t3);
	printf("use sub\n");
	cll_print(res);

	cll_mul(&res, t3, t1);
	printf("use mul\n");
	cll_print(res);
	
	cll_conjugate(&res, t3);
	printf("use conjugate\n");
	cll_print(res);

	cll_norm2(&res, t1);
	printf("use norm2\n");
	cll_print(res);

	printf("%lld, %lld \n", cll_real(res), cll_imag(res));

}

void cll_set(cllong* op, long long real, long long imag){

	op->real = real;
	op->imag = imag;

}

void cll_get(cllong* rop, cllong op){

	rop->real = op.real;
	rop->imag = op.imag;

}

void cll_add(cllong* rop, cllong op1, cllong op2){

	rop->real = op1.real + op2.real;
	rop->imag = op1.imag + op2.imag;
}

void cll_sub(cllong* rop, cllong op1, cllong op2){

	rop->real = op1.real - op2.real;
	rop->imag = op1.imag - op2.imag;
}

void cll_mul(cllong* rop, cllong op1, cllong op2){

	rop->real = op1.real * op2.real - op1.imag * op2.imag;
	rop->imag = op1.real * op2.imag + op1.imag * op2.real;
}

void cll_conjugate(cllong* rop, cllong op){

	rop->real = op.real;
	rop->imag = -op.imag;

}

void cll_norm2(cllong* rop, cllong op){
	
	cll_set(rop, cll_real(op) * cll_real(op), cll_imag(op) * cll_imag(op));

}

long long cll_real(cllong op){

	return op.real;

}

long long cll_imag(cllong op){

	return op.imag;

}

void cll_print(cllong op){

	printf("real: %lld complex: %lld\n", op.real, op.imag);

}
