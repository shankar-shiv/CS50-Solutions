#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int len(long n);
void printArray(int arr[], int size);
void rvereseArray(int arr[], int start, int end);
int luhn(int arr[], int lengthOfCreditCardNO);

int main(void){

    long CreditCardNO = 0;

    // initialisations

    CreditCardNO = get_long("Number : ");


    int lengthOfCreditCardNO = len(CreditCardNO);

    // printf("%i\n", lengthOfCreditCardNO);

    int count = 0;

    // Array created
    int CreditCardArray[lengthOfCreditCardNO];

    // Turn the CreditCardNO into an array
    while (CreditCardNO != 0){
       CreditCardArray[count] = CreditCardNO % 10;
       CreditCardNO /= 10;
       count++;
   }

    rvereseArray(CreditCardArray, 0, lengthOfCreditCardNO - 1);

    // 4003600000000014
    // printArray(CreditCardArray, sizeof(CreditCardArray) / sizeof(CreditCardArray[0]));

    if(lengthOfCreditCardNO == 16){
        // mastercard or visa
        if(CreditCardArray[0] == 5){
            if(CreditCardArray[1] == 1 || CreditCardArray[1] == 2 || CreditCardArray[1] == 3 || CreditCardArray[1] == 4 || CreditCardArray[1] == 5){

                int passFail = luhn(CreditCardArray,lengthOfCreditCardNO);
                if (passFail == 0){
                    printf("MASTERCARD\n");
                }else{
                    printf("INVALID\n");
                }

            }
        }else if(CreditCardArray[0] == 4){

            int passFail = luhn(CreditCardArray,lengthOfCreditCardNO);
            if (passFail == 0){
                printf("VISA\n");
            }else{
                printf("INVALID\n");
            }
        }
    }else if(lengthOfCreditCardNO == 15){
        // Amex
        if (CreditCardArray[0] == 3){
            if(CreditCardArray[1] == 4 || CreditCardArray[1] == 7){

                int passFail = luhn(CreditCardArray,lengthOfCreditCardNO);
                if (passFail == 0){
                    printf("AMEX\n");
                }else{
                    printf("INVALID\n");
                }

            }
        }
    }else if(lengthOfCreditCardNO == 13){
        // Visa
        if(CreditCardArray[0] == 4){

            int passFail = luhn(CreditCardArray,lengthOfCreditCardNO);
            if (passFail == 0){
                printf("VISA\n");
            }else{
                printf("INVALID\n");
            }
        }
    }else{
        printf("INVALID\n");
    }

    return 0;
}

int luhn(int arr[], int lengthOfCreditCardNO){
    // int oddIntegerArray1[lengthOfCreditCardNO/2];
    // int oddIntegerArray2[lengthOfCreditCardNO/2];

    // int evenIntegerArray1[lengthOfCreditCardNO/2];

    int oddIntegerArray1[15] = {0};
    int oddIntegerArray2[15] = {0};

    int evenIntegerArray1[15] = {0};

    int x = 0;

    int resultStep1 = 0;
    int resultStep2 = 0;
    int resultStep3 = 0;

    for(int i = 0; i < lengthOfCreditCardNO; i+=2){
        oddIntegerArray1[x] = arr[i];
        x++;
    }

    // reset the variable
    x = 0;

    for(int e = 1; e < lengthOfCreditCardNO; e+=2){
        // printf("%d \t", arr[e]);
        evenIntegerArray1[x] = arr[e];
        x++;
    }

    // reset the variable
    x = 0;

    // printArray(oddIntegerArray1, sizeof(oddIntegerArray1) / sizeof(oddIntegerArray1[0]));
    for (int y = 0; y < (sizeof(oddIntegerArray1) / sizeof(oddIntegerArray1[0])); y++){
        oddIntegerArray2[x] = oddIntegerArray1[y] * 2;
        x++;
    }

    // Now let’s add those products’ digits (i.e., not the products themselves) together:
    for (int randomVar = 0; randomVar < (sizeof(oddIntegerArray2) / sizeof(oddIntegerArray2[0])); randomVar++){
        if (oddIntegerArray2[randomVar] > 9){
            while(oddIntegerArray2[randomVar]){
                resultStep1 += oddIntegerArray2[randomVar] % 10;
                oddIntegerArray2[randomVar] /= 10;
            }
        }else{
            resultStep1 += oddIntegerArray2[randomVar];
        }
    }


    for (int ab = 0; ab < (sizeof(evenIntegerArray1) / sizeof(evenIntegerArray1[0])); ab++)
        resultStep2 += evenIntegerArray1[ab];

    resultStep3 = resultStep2 + resultStep1;
    // printf("resultStep3 = %d \n", resultStep3);

    if (resultStep3 % 10 == 0){
        // this means card is legit!
        return 0;
    }else{
        // card is NOT legit!
        return 1;
    }
}

int len(long n){

    int count = 0;

    // iterate until n becomes 0
    // remove last digit from n in each iteration
    // increase count by 1 in each iteration
    while (n != 0) {
        n /= 10;     // n = n/10
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
  int i;
  for (i=0; i < size; i++)
    printf("%d ", arr[i]);

  printf("\n");
}
