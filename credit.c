#include <cs50.h>
#include <stdio.h>
void printf_creditcard_brand(long long ccn);
bool check_validity(long long credit_card_num);
int find_length(long long n);
bool checksum(long long ccn);

int main(void)
{
    long long credit_card_num;
    do
    {
        credit_card_num = get_long_long("Number: ");
    }
    while (credit_card_num < 0);

    //check card validity and print
    if (check_validity(credit_card_num))
    {
        printf_creditcard_brand(credit_card_num);
    }

    else
    {
        printf("INVALID\n");
    }
}

//check is card exist
bool check_validity(long long credit_card_num)
{
    int len = find_length(credit_card_num);
    return (len == 13 || len == 15 || len == 16) && checksum(credit_card_num);
}

//find the lenth 
int find_length(long long n)
{
    int len;
    for (len = 0; n != 0; n /= 10, len ++);
    return len;
}

// check digit 
bool checksum(long long ccn)
{
    int sum = 0;
    for (int i = 0; ccn != 0; i++, ccn /= 10)
    {
        if (i % 2 == 0)
        {
            sum += ccn % 10;
        }

        else
        {
            int digit = 2 * (ccn % 10);
            sum += digit / 10 + digit % 10;

        }
    }
    return (sum % 10) == 0;
}

//print card number
void printf_creditcard_brand(long long ccn)
{
    //check and print amex card
    if ((ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13))
    {
        printf("AMEX\n");

    }

    //check and print mastercard
    else if (ccn >= 51e14 && ccn < 56e14)
    {
        printf("MASTERCARD\n");
    }

    //check and print visa
    else if ((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    } 
}
