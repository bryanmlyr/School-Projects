/*
** EPITECH PROJECT, 2018
** ex00 CPP pool
** File description:
** mul_div
*/

void	add_mul_4param(int first, int second, int *sum, int *product)
{
	*sum = first + second;
	*product = first * second;
}

void	add_mul_2param(int *first, int *second)
{
	int temp_a1 = *first;
	int temp_a2 = *second;

	*first = temp_a1 + temp_a2;
	*second = temp_a1 * temp_a2;
}