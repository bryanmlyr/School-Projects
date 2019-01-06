/*
** EPITECH PROJECT, 2018
** ex04
** File description:
** castmania
*/

#include "castmania.h"
#include <stdio.h>

void	exec_op_div(void *data)
{
	instruction_t *d = (instruction_t *)data;
	div_t *op2 = (div_t *)d->operation;

	if (d->output_type == VERBOSE && op2->div_type == INTEGER) {
		integer_op_t *ar = (integer_op_t *)op2->div_op;
		exec_div((div_t *)d->operation);
		printf("%d\n", ar->res);
	}
	if (d->output_type == VERBOSE && op2->div_type == DECIMALE) {
		decimale_op_t *ar = (decimale_op_t *)op2->div_op;
		exec_div((div_t *)d->operation);
		printf("%f\n", ar->res);
	}
}

void	exec_op_add(void *data)
{
	instruction_t *d = (instruction_t *)data;
	add_t *op1 = (add_t *)d->operation;

	exec_add((add_t *)d->operation);
	if (d->output_type == VERBOSE) {
		integer_op_t ar = (integer_op_t)op1->add_op;
		printf("%d\n", ar.res);
	}
}

void	exec_operation(instruction_type_t instruction_type , void *data)
{
	if (instruction_type == ADD_OPERATION) {
		exec_op_add(data);
	}
	if (instruction_type == DIV_OPERATION) {
		exec_op_div(data);
	}
}

void	exec_instruction(instruction_type_t instruction_type , void *data)
{
	if (instruction_type == PRINT_INT) {
		printf("%d\n", ((int *)data)[0]);
	}
	if (instruction_type == PRINT_FLOAT) {
		printf("%f\n", ((float *)data)[0]);
	}
	exec_operation(instruction_type, data);
}