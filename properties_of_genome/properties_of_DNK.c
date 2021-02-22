#include <stdio.h>
#include <stdlib.h>

struct Couples
{
    int amount_TA;
    int amount_AT;
    int amount_TC;
    int amount_CT;
    int amount_CA;
    int amount_AC;
    int amount_TG;
    int amount_GT;
    int amount_GA;
    int amount_AG;
    int amount_CG;
    int amount_GC;
    int amount_AA;
    int amount_CC;
    int amount_GG;
    int amount_TT;
};

void Amount_of_letters (char c, int *amount_A, int *amount_T, int *amount_G, int *amount_C)
{
    if (c == 'A')
        *amount_A = *amount_A + 1;
    else if (c == 'T')
        *amount_T = *amount_T + 1;
    else if (c == 'G')
        *amount_G = *amount_G + 1;
    else 
        *amount_C = *amount_C + 1;
}

struct Couples Amount_of_Couples (char letter, char previos_letter, struct Couples s)
{
    if ((letter == 'A') && (previos_letter == 'T'))
        s.amount_TA = s.amount_TA + 1;
    else if ((letter == 'T') && (previos_letter == 'A'))
         s.amount_AT = s.amount_AT + 1;
    else if ((letter == 'C') && (previos_letter == 'T'))
         s.amount_TC = s.amount_TC + 1;
    else if ((letter == 'A') && (previos_letter == 'C'))
         s.amount_CA = s.amount_CA + 1;
    else if ((letter == 'C') && (previos_letter == 'A'))
         s.amount_AC = s.amount_AC + 1;
    else if ((letter == 'G') && (previos_letter == 'T'))
         s.amount_TG = s.amount_TG + 1;
    else if ((letter == 'T') && (previos_letter == 'G'))
         s.amount_GT = s.amount_GT + 1;
    else if ((letter == 'A') && (previos_letter == 'G'))
         s.amount_GA = s.amount_GA + 1;
    else if ((letter == 'G') && (previos_letter == 'A'))
         s.amount_AG = s.amount_AG + 1;
    else if ((letter == 'G') && (previos_letter == 'C'))
         s.amount_CG = s.amount_CG + 1;
    else if ((letter == 'C') && (previos_letter == 'G'))
         s.amount_GC = s.amount_GC + 1;
    else if ((letter == 'A') && (previos_letter == 'A'))
         s.amount_AA = s.amount_AA + 1;
    else if ((letter == 'C') && (previos_letter == 'C'))
         s.amount_CC = s.amount_CC+ 1;
    else if ((letter == 'T') && (previos_letter == 'T'))
         s.amount_TT = s.amount_TT + 1;
    else if ((letter == 'G') && (previos_letter == 'G'))
         s.amount_GG = s.amount_GG + 1;
    else 
         s.amount_CT = s.amount_CT + 1;
    
    return s;
}

FILE * Open_file (char *name)
{
     FILE * fp;
     fp = fopen(name, "r+");
     return fp;
}

int main(int argc, char* argv[])
{
    int amount_A = 0;
    int amount_T = 0;
    int amount_G = 0;
    int amount_C = 0;
    int amount_G_1 = 0;
    int amount_C_1 = 0;
    int amount_G_2 = 0;
    int amount_C_2 = 0;
    float G_C = 0;
    int halth_of_gen = 0;

    FILE * fp = Open_file(argv[1]);
    FILE * f = Open_file(argv[1]);
    char letter = fgetc(fp);
    char previos_letter;
    int max_couple = 0;
    int min_couple = 0;
    int check = 1;
    struct Couples gen = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    while (letter != EOF)
        {
           Amount_of_letters(letter, &amount_A, &amount_T, &amount_G, &amount_C); 
           previos_letter = letter;
           letter = fgetc(fp);
           check ++;
           if (check == 2)
           {
               gen = Amount_of_Couples(letter,previos_letter, gen);
               check = 0;
           }
               
        }
    check = 0;
    letter = fgetc(f);
    halth_of_gen = (amount_A + amount_G + amount_C + amount_T) / 2;
    printf("%d", halth_of_gen);
    printf("amount of A : %d, amount of T : %d, amount of G : %d, amount of C : %d \n", amount_A, amount_T, amount_G, amount_C );
    while (letter != EOF)
    {
         if (check < halth_of_gen)
               Amount_of_letters(letter, &amount_A, &amount_T, &amount_G_1, &amount_C_1); 
          else 
               Amount_of_letters(letter, &amount_A, &amount_T, &amount_G_2, &amount_C_2); 
          letter = fgetc(f);
          check ++;
    }
    
    fclose(fp);
    fclose(f);
    printf("amount of TA : %d, amount of CG : %d\n", gen.amount_TA, gen.amount_CG);
    if ((amount_C_1 > amount_G_1) && (amount_C_2 < amount_G_2))
          printf ("GC skew is true\n");
     else 
          printf ("GC skew is false\n");
}