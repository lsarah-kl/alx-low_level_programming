int add(int i, int k);
int sub(int i, int k);
int mul(int i, int k);
int div(int i, int k);
int mod(int i, int k);

/**
* add - adds two integers
* @i: 1st integer to add
* @k: 2nd integer to add
* Return: the sum
*/

int add(int i, int k)
{
	return (i + k);
}

/**
* sub - subtracts two integers
* @i: 1st integer to add
* @k: 2nd integer to add
* Return: the result
*/

int sub(int i, int k)
{
	return (i - k);
}

/**
* mul - multiply two integers
* @i: 1st integer to add
* @k: 2nd integer to add
* Return: the multiple
*/

int mul(int i, int k)
{
	return (i * k);
}

/**
* div - divides two integers
* @i: 1st integer to add
* @k: 2nd integer to add
* Return: the dividend integer
*/

int div(int i, int k)
{
	return (i / k);
}

/**
  mod - finds  modulus of two integers
  @i: 1st integer to add
  @k: 2nd integer to add
  Return: the modulus
*/

int mod(int i, int k)
{
	return (i % k);
}
