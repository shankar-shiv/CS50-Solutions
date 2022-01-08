
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// MASTERCARD: 16-Digit #'s, Start with: 51, 52, 53, 54, or 55
// VISA: 13-16-Digit #'s, Start with: 4
// AMEX: 15-Digit #'s, Star with: 34 or 37

// Luhn's Algorithm:
// 1. Multiply every other digit by 2, starting with the second number to the last
// 2. Add the sum of those digits
// 3. Add the sum of the other digits
// 4. If the total sum ends with a 0, it is valid!

int len(long n);

int main(void)
{
    long CreditCardNO = 0;
    string card;

    CreditCardNO = get_long("Number : ");

    int lengthOfCreditCardNO = len(CreditCardNO);

    // Check if cc num length is valid
    if (lengthOfCreditCardNO != 13 && lengthOfCreditCardNO != 15 && lengthOfCreditCardNO != 16)
    {
        printf("INVALID");
    }

    // Luhn's Algorithm
    // Looping variables for computation
    long digit;
    int multi;
    int sum1 = 0;
    int sum2 = 0;
    int result;

    // Iterate 1 through length of Credit Card
    for (int i = 0; i < lengthOfCreditCardNO; i++)
    {
        // Create factor
        long factor = pow(10, i);

        // Formulate first set of digits (2nd from last)
        if (i % 2 != 0 && (lengthOfCreditCardNO == 13 || lengthOfCreditCardNO == 15 || lengthOfCreditCardNO == 16))
        {
            digit = (CreditCardNO / factor) % 10;
            multi = digit * 2;

            while (multi > 9)
            {
                int num1 = multi % 10;
                int num2 = multi / 10;
                multi = num1 + num2;
            }
            sum1 += multi;
        }

        // Formulate second set of digits (First from last)
        if (i % 2 == 0 && (lengthOfCreditCardNO == 13 || lengthOfCreditCardNO == 15 || lengthOfCreditCardNO == 16))
        {
            digit = (CreditCardNO / factor) % 10;
            sum2 += digit;
        }
    }

    // Define which card type
    int test = CreditCardNO / pow(10, lengthOfCreditCardNO - 2);

    if ((lengthOfCreditCardNO == 16 || lengthOfCreditCardNO == 13) && (test / 10 == 4))
    {
        card = "VISA";
    }
    else if ((lengthOfCreditCardNO == 13 || lengthOfCreditCardNO == 16) && test >= 51 && test <= 55)
    {
        card = "MASTERCARD";
    }
    else if (lengthOfCreditCardNO == 15 && (test == 34 || test == 37))
    {
        card = "AMEX";
    }
    else
    {
        card = "INVALID";
    }

    // Compute final sum
    result = sum1 + sum2;

    // Final verification
    if (result % 10 == 0)
    {
        printf("%s\n", card);
        // printf("%d\n", result % 10);
    }
    else
    {
        printf("INVALID\n");
    }
}

int len(long n)
{

    int count = 0;

    // iterate until n becomes 0
    // remove last digit from n in each iteration
    // increase count by 1 in each iteration
    while (n != 0)
    {
        n /= 10; // n = n/10
        ++count;
    }

    return count;
}