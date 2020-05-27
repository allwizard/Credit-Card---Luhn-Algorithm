#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //environment variables
    long long cc_number = 0;
    int count = 0;
    int slots = 0;
    int single = 0;

    //request user input
    do
    {
        cc_number = get_long("Please provide your credit card number: ");
    }
    while (cc_number < 0);

    //count digits in int
    long long digits = cc_number;
    while (digits > 0)
    {
        digits = digits / 10;
        count++;
    }


    //deny if not does not contain to required digits
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
    }

    int cc_arr[count];
    int arr_count = count;

    //convert int(cc_number) to arr(cc_arr)
    while (cc_number)
    {
        single = cc_number % 10;
        cc_arr[arr_count - 1] = single;
        arr_count -= 1;
        cc_number /= 10;
    }



    // VISA 16-digit Verification
    if (count == 16)
    {
        if (cc_arr[0] == 4)
        {
            int cc2_arr[8];
            cc2_arr[0] = cc_arr[14] * 2;
            cc2_arr[1] = cc_arr[12] * 2;
            cc2_arr[2] = cc_arr[10] * 2;
            cc2_arr[3] = cc_arr[8] * 2;
            cc2_arr[4] = cc_arr[6] * 2;
            cc2_arr[5] = cc_arr[4] * 2;
            cc2_arr[6] = cc_arr[2] * 2;
            cc2_arr[7] = cc_arr[0] * 2;

            //formatting from products to product's digits example "12" should be "1" "2"
            int cc3_arr[16];
            cc3_arr[0] = cc2_arr[0] / 10;
            cc3_arr[1] = cc2_arr[0] % 10;
            cc3_arr[2] = cc2_arr[1] / 10;
            cc3_arr[3] = cc2_arr[1] % 10;
            cc3_arr[4] = cc2_arr[2] / 10;
            cc3_arr[5] = cc2_arr[2] % 10;
            cc3_arr[6] = cc2_arr[3] / 10;
            cc3_arr[7] = cc2_arr[3] % 10;
            cc3_arr[8] = cc2_arr[4] / 10;
            cc3_arr[9] = cc2_arr[4] % 10;
            cc3_arr[10] = cc2_arr[5] / 10;
            cc3_arr[11] = cc2_arr[5] % 10;
            cc3_arr[12] = cc2_arr[6] / 10;
            cc3_arr[13] = cc2_arr[6] % 10;
            cc3_arr[14] = cc2_arr[7] / 10;
            cc3_arr[15] = cc2_arr[7] % 10;

            int visa_sum = cc3_arr[0] + cc3_arr[1] + cc3_arr[2] + cc3_arr[3] + cc3_arr[4] + cc3_arr[5] + cc3_arr[6] + cc3_arr[7] + cc3_arr[8] +
                           cc3_arr[9] + cc3_arr[10] + cc3_arr[11] + cc3_arr[12] + cc3_arr[13] + cc3_arr[14] + cc3_arr[15];
            visa_sum = visa_sum + cc_arr[15] + cc_arr[13] + cc_arr[11] + cc_arr[9] + cc_arr[7] + cc_arr[5] + cc_arr[3] + cc_arr[1];

            //printf("total sum is: %i\n", visa_sum);

            //count digits in int
            int count2 = 0;
            int single2 = 0;
            int digits2 = visa_sum;
            while (digits2 > 0)
            {
                digits2 = digits2 / 10;
                count2++;
            }

            //printf("count2 works: %i\n", count2);

            int visa_sum_arr[count2];
            int visa_sum_count = count2;

            //convert int(cc_number) to arr(cc_arr)
            while (visa_sum)
            {
                single2 = visa_sum % 10;
                visa_sum_arr[visa_sum_count - 1] = single2;
                visa_sum_count -= 1;
                visa_sum /= 10;
            }

            //printf("%i\n", visa_sum_arr[count2 -1]);
            if (visa_sum_arr[count2 - 1] == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }

    // VISA 13-digit Verification
    if (count == 13)
    {
        if (cc_arr[0] == 4)
        {
            int cc2_arr[6];
            cc2_arr[0] = cc_arr[11] * 2;
            cc2_arr[1] = cc_arr[9] * 2;
            cc2_arr[2] = cc_arr[7] * 2;
            cc2_arr[3] = cc_arr[5] * 2;
            cc2_arr[4] = cc_arr[3] * 2;
            cc2_arr[5] = cc_arr[1] * 2;

            //formatting from products to product's digits example "12" should be "1" "2"
            int cc3_arr[12];
            cc3_arr[0] = cc2_arr[0] / 10;
            cc3_arr[1] = cc2_arr[0] % 10;
            cc3_arr[2] = cc2_arr[1] / 10;
            cc3_arr[3] = cc2_arr[1] % 10;
            cc3_arr[4] = cc2_arr[2] / 10;
            cc3_arr[5] = cc2_arr[2] % 10;
            cc3_arr[6] = cc2_arr[3] / 10;
            cc3_arr[7] = cc2_arr[3] % 10;
            cc3_arr[8] = cc2_arr[4] / 10;
            cc3_arr[9] = cc2_arr[4] % 10;
            cc3_arr[10] = cc2_arr[5] / 10;
            cc3_arr[11] = cc2_arr[5] % 10;

            int visa_sum = cc3_arr[0] + cc3_arr[1] + cc3_arr[2] + cc3_arr[3] + cc3_arr[4] + cc3_arr[5] + cc3_arr[6] + cc3_arr[7] + cc3_arr[8] +
                           cc3_arr[9] + cc3_arr[10] + cc3_arr[11];
            visa_sum = visa_sum + cc_arr[12] + cc_arr[10] + cc_arr[8] + cc_arr[6] + cc_arr[4] + cc_arr[2] + cc_arr[0];

            //printf("total sum is: %i\n", visa_sum);

            //count digits in int
            int count2 = 0;
            int single2 = 0;
            int digits2 = visa_sum;
            while (digits2 > 0)
            {
                digits2 = digits2 / 10;
                count2++;
            }

            //printf("count2 works: %i\n", count2);

            int visa_sum_arr[count2];
            int visa_sum_count = count2;

            //convert int(cc_number) to arr(cc_arr)
            while (visa_sum)
            {
                single2 = visa_sum % 10;
                visa_sum_arr[visa_sum_count - 1] = single2;
                visa_sum_count -= 1;
                visa_sum /= 10;
            }

            //printf("%i\n", visa_sum_arr[count2 -1]);
            if (visa_sum_arr[count2 - 1] == 0)
            {
                printf("VISA\n");
            }
        }
    }


    // MasterCard 16-digit Verification
    if (count == 16)
    {
        if ((cc_arr[0] == 5 && cc_arr[1]) == 1 || cc_arr[1] == 2 || cc_arr[1] == 3 || cc_arr[1] == 4 || cc_arr[1] == 5)
        {
            if (cc_arr[1] != 6)
            {

                int cc2_arr[8];
                cc2_arr[0] = cc_arr[14] * 2;
                cc2_arr[1] = cc_arr[12] * 2;
                cc2_arr[2] = cc_arr[10] * 2;
                cc2_arr[3] = cc_arr[8] * 2;
                cc2_arr[4] = cc_arr[6] * 2;
                cc2_arr[5] = cc_arr[4] * 2;
                cc2_arr[6] = cc_arr[2] * 2;
                cc2_arr[7] = cc_arr[0] * 2;

                //formatting from products to product's digits example "12" should be "1" "2"
                int cc3_arr[16];
                cc3_arr[0] = cc2_arr[0] / 10;
                cc3_arr[1] = cc2_arr[0] % 10;
                cc3_arr[2] = cc2_arr[1] / 10;
                cc3_arr[3] = cc2_arr[1] % 10;
                cc3_arr[4] = cc2_arr[2] / 10;
                cc3_arr[5] = cc2_arr[2] % 10;
                cc3_arr[6] = cc2_arr[3] / 10;
                cc3_arr[7] = cc2_arr[3] % 10;
                cc3_arr[8] = cc2_arr[4] / 10;
                cc3_arr[9] = cc2_arr[4] % 10;
                cc3_arr[10] = cc2_arr[5] / 10;
                cc3_arr[11] = cc2_arr[5] % 10;
                cc3_arr[12] = cc2_arr[6] / 10;
                cc3_arr[13] = cc2_arr[6] % 10;
                cc3_arr[14] = cc2_arr[7] / 10;
                cc3_arr[15] = cc2_arr[7] % 10;

                int card_sum = cc3_arr[0] + cc3_arr[1] + cc3_arr[2] + cc3_arr[3] + cc3_arr[4] + cc3_arr[5] + cc3_arr[6] + cc3_arr[7] + cc3_arr[8] +
                               cc3_arr[9] + cc3_arr[10] + cc3_arr[11] + cc3_arr[12] + cc3_arr[13] + cc3_arr[14] + cc3_arr[15];
                card_sum = card_sum + cc_arr[15] + cc_arr[13] + cc_arr[11] + cc_arr[9] + cc_arr[7] + cc_arr[5] + cc_arr[3] + cc_arr[1];

                //printf("total sum is: %i\n", visa_sum);

                //count digits in int
                int count2 = 0;
                int single2 = 0;
                int digits2 = card_sum;
                while (digits2 > 0)
                {
                    digits2 = digits2 / 10;
                    count2++;
                }

                //printf("count2 works: %i\n", count2);

                int card_sum_arr[count2];
                int card_sum_count = count2;

                //convert int(cc_number) to arr(cc_arr)
                while (card_sum)
                {
                    single2 = card_sum % 10;
                    card_sum_arr[card_sum_count - 1] = single2;
                    card_sum_count -= 1;
                    card_sum /= 10;
                }

                //printf("%i\n", card_sum_arr[count2 -1]);
                if (card_sum_arr[count2 - 1] == 0)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            if (cc_arr[1] == 6 || cc_arr[1] == 7 || cc_arr[1] == 8 || cc_arr[1] == 9)
            {
                printf("INVALID\n");
            }
        }
    }

    // AMEX 15-digit Verification
    if (count == 15)
    {
        if ((cc_arr[0] == 0 && cc_arr[1] == 4) || cc_arr[1] == 7)
        {
            int cc2_arr[7];
            cc2_arr[0] = cc_arr[13] * 2;
            cc2_arr[1] = cc_arr[11] * 2;
            cc2_arr[2] = cc_arr[9] * 2;
            cc2_arr[3] = cc_arr[7] * 2;
            cc2_arr[4] = cc_arr[5] * 2;
            cc2_arr[5] = cc_arr[3] * 2;
            cc2_arr[6] = cc_arr[1] * 2;

            //formatting from products to product's digits example "12" should be "1" "2"
            int cc3_arr[14];
            cc3_arr[0] = cc2_arr[0] / 10;
            cc3_arr[1] = cc2_arr[0] % 10;
            cc3_arr[2] = cc2_arr[1] / 10;
            cc3_arr[3] = cc2_arr[1] % 10;
            cc3_arr[4] = cc2_arr[2] / 10;
            cc3_arr[5] = cc2_arr[2] % 10;
            cc3_arr[6] = cc2_arr[3] / 10;
            cc3_arr[7] = cc2_arr[3] % 10;
            cc3_arr[8] = cc2_arr[4] / 10;
            cc3_arr[9] = cc2_arr[4] % 10;
            cc3_arr[10] = cc2_arr[5] / 10;
            cc3_arr[11] = cc2_arr[5] % 10;
            cc3_arr[12] = cc2_arr[6] / 10;
            cc3_arr[13] = cc2_arr[6] % 10;

            int card_sum = cc3_arr[0] + cc3_arr[1] + cc3_arr[2] + cc3_arr[3] + cc3_arr[4] + cc3_arr[5] + cc3_arr[6] + cc3_arr[7] + cc3_arr[8] +
                           cc3_arr[9] + cc3_arr[10] + cc3_arr[11] + cc3_arr[12] + cc3_arr[13];
            card_sum = card_sum + cc_arr[14] + cc_arr[12] + cc_arr[10] + cc_arr[8] + cc_arr[6] + cc_arr[4] + cc_arr[2] + cc_arr[0];

            //printf("total sum is: %i\n", visa_sum);

            //count digits in int
            int count2 = 0;
            int single2 = 0;
            int digits2 = card_sum;
            while (digits2 > 0)
            {
                digits2 = digits2 / 10;
                count2++;
            }

            //printf("count2 works: %i\n", count2);

            int card_sum_arr[count2];
            int card_sum_count = count2;

            //convert int(cc_number) to arr(cc_arr)
            while (card_sum)
            {
                single2 = card_sum % 10;
                card_sum_arr[card_sum_count - 1] = single2;
                card_sum_count -= 1;
                card_sum /= 10;
            }

            //printf("%i\n", card_sum_arr[count2 -1]);
            if (card_sum_arr[count2 - 1] == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }

}

