/* Convert a binary number to a decimal number.

*/
#include <stdio.h>
#include <stdbool.h>

// Function Declarations
long long getNum(void);
long long binaryToDecimal(long long binary);
long long powerTwo(long long num);
long long firstDigit(long long num);
bool validateBinary(long long binary);

int main()
{
// Local Declaration
	long long binary;
	long long decimal;

// Statements
	binary = getNum();
	decimal = binaryToDecimal(binary);
	printf("The binary nunber was: %lld", binary);
	printf("\nThe decimal number was: %lld", decimal);

	system("pause");
	return 0;
} // main

/* ===================== getNum ========================
	This function reads and validates a binary number
	from the keyboard.
		Pre  nothing
		Post a valid binary number is returned
*/
long long getNum(void)
{
// Local Declarations
	bool       isValid;
	long long  binary;

// Statements
	do
	{
		printf("Enter a binary number (Zeros and ones): ");
		scanf("%lld", &binary);
		isValid = validateBinary(binary);
		if (!isValid)
			printf("\a\aNot binary. zeros/ones only.\n\n");
	} while (!isValid);
	return binary;
} // getNum

/* ======================= binaryTodecimal ===================
	Change a binary number to a decimal number.
		Pre  binary is a number containing only 0 or 1
		Post returns decimal number
*/
long long binaryToDecimal(long long binary)
{
	// Local  Declarations
	long long decimal;

	// Statemetns
	decimal = 0;
	for (int i = 0; binary != 0; i++)
	{
		decimal += firstDigit(binary) * powerTwo (i);
		binary /= 10;
	} //for i
	return decimal;
} // binaryToDecimal

/* ================== validateBinary =====================
	Check the digits in a binary number for 0 and 1.
		Pre  binary is a number to be validated
		Post returns true if valid; false if not
*/
bool validateBinary(long long binary)
{
// Statements
	while (binary != 0)
	{
		if (!(binary % 10 == 0 || binary % 10 == 1))
			return false;
		binary /= 10;
	} // while
	return true;
} // validateBinary

/* ======================== powerTwo ================
	This function raises 2 to the power num
		Pre  num is exponent
		Post Returns 2 to the power of num
*/
long long powerTwo(long long num)
{
// Local Declaration
	long long power = 1;

// Statements
	for (long i = 1; i <= num; i++)
		power *= 2;
	return power;
} // powerTwo

/* =================== firstDigit ===================
	This function returns the right most digit of nun
		Pre  the integer num
		Post the right digit of num returned 
*/
long long firstDigit(long long num)
{
// Statements
	return (num % 10);
} // firstDigit 