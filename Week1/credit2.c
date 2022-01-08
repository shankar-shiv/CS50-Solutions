#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int len(long n);
void printArray(int arr[], int size);
void rvereseArray(int arr[], int start, int end);
int luhn(long ccNUM, int count);

int main(void)
{

    long CreditCardNO = 0;

    // initialisations

    CreditCardNO = get_long("Number : ");

    int lengthOfCreditCardNO = len(CreditCardNO);

    printf("%i\n", lengthOfCreditCardNO);

    int count = 0;

    // Array created
    int CreditCardArray[lengthOfCreditCardNO];

    // Turn the CreditCardNO into an array
    while (CreditCardNO != 0)
    {
        CreditCardArray[count] = CreditCardNO % 10;
        CreditCardNO /= 10;
        count++;
    }

    rvereseArray(CreditCardArray, 0, lengthOfCreditCardNO - 1);

    // printArray(CreditCardArray, sizeof(CreditCardArray) / sizeof(CreditCardArray[0]));

    switch (lengthOfCreditCardNO)
    {
    case 16:
        // we check for master card here
        if (CreditCardArray[0] == 5)
        {
            if (CreditCardArray[1] == 1 || CreditCardArray[1] == 2 || CreditCardArray[1] == 3 || CreditCardArray[1] == 4 || CreditCardArray[1] == 5)
            {
                if (luhn(CreditCardNO, lengthOfCreditCardNO))
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                    break;
                }
            }
            else
            {
                printf("INVALID\n");
                break;
            }
        }

        if (CreditCardArray[0] == 4)
        {
            if (luhn(CreditCardNO, lengthOfCreditCardNO))
            {
                printf("VISA\n");
                break;
            }
            else
            {
                printf("INVALID\n");
                break;
            }
        }
        else
        {
            printf("INVALID\n");
            break;
        }
    case 15:
        if (CreditCardArray[0] == 3)
        {
            if (CreditCardArray[1] == 4 || CreditCardArray[1] == 7)
            {
                if (luhn(CreditCardNO, lengthOfCreditCardNO))
                {
                    printf("AMEX\n");
                    break;
                }
                else
                {
                    printf("INVALID\n");
                    break;
                }
            }
            else
            {
                printf("INVALID\n");
                break;
            }
        }
        else
        {
            printf("INVALID\n");
            break;
        }

    case 13:
        if (CreditCardArray[0] == 4)
        {
            if (luhn(CreditCardNO, lengthOfCreditCardNO))
            {
                printf("VISA\n");
                break;
            }
            else
            {
                printf("INVALID\n");
                break;
            }
        }
        else
        {
            printf("INVALID\n");
            break;
        }

    default:
        printf("INVALID\n");
    }

    return 0;
}

int luhn(long ccNUM, int count)
{
    // Luhn's Algorithm
    // Looping variables for computation
    long digit;
    int oneD;
    int twoD;
    int checker;
    int multi;
    int sum1 = 0;
    int sum2 = 0;
    int result;

    // Iterate 1 through length of CC
    for (int i = 0; i < count; i++)
    {
        // Create factor
        long factor = pow(10, i);

        // Formulate first set of digits (2nd from last)
        if (i % 2 != 0 && count == 16)
        {
            digit = (ccNUM / factor) % 10;
            multi = digit * 2;

            if (multi > 9)
            {
                int num1 = multi % 10;
                int num2 = multi / 10;
                multi = num1 + num2;
            }
            sum1 += multi;

            if (i == count - 1)
            {
                oneD = digit;
            }
        }
        else if (i % 2 != 0 && (count == 13 || count == 15))
        {
            digit = (ccNUM / factor) % 10;
            multi = digit * 2;

            if (multi > 9)
            {
                int num1 = multi % 10;
                int num2 = multi / 10;
                multi = num1 + num2;
            }
            sum1 += multi;

            if (i == count - 2)
            {
                twoD = digit;
            }
        }

        // Formulate second set of digits (First from last)
        if (i % 2 == 0 && count == 16)
        {
            digit = (ccNUM / factor) % 10;
            sum2 += digit;

            if (i == count - 2)
            {
                twoD = digit;
            }
        }
        else if (i % 2 == 0 && (count == 13 || count == 15))
        {
            digit = (ccNUM / factor) % 10;
            sum2 += digit;

            if (i == count - 1)
            {
                oneD = digit;
            }
        }
        checker = oneD + twoD;
    }

    // Compute final sum
    result = sum1 + sum2;

    // Final verification
    if (result % 10 == 0)
    {
        printf("%d\n", 1);
        return 1;
    }
    else
    {
        printf("%d\n", 0);
        return 0;
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

/* Function to reverse arr[] from start to end*/
void rvereseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/* Utility that prints out an array on a line */
void printArray(int arr[], int size)
{
    for (int p = 0; p < size; p++)
    {
        printf("%d \t", arr[p]);
    }
}