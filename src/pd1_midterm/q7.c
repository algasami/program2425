/*
[10] Write a function unsigned a_plus_b_mod_c(unsigned a, unsigned b, unsigned c) to compute
(a+b)%c and a function unsigned a_times_b_mod_c(unsigned a, unsigned b, unsigned c) to
compute (a*b)%c, where a, b, c are numbers of type unsigned.
*/

/*
(a + b) % c = a % c + b % c (prevents overflow)
*/
unsigned a_plus_b_mod_c(unsigned a, unsigned b, unsigned c)
{
	return a % c + b % c;
}

/*
(a * b) % c = ((a % c) * (b % c)) % c
*/

unsigned a_times_b_mod_c(unsigned a, unsigned b, unsigned c)
{
	return ((a % c) * (b % c)) % c;
}