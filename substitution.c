#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char ABC[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(int argc, string argv[])
{
    bool flag1 = false, flag2 = false;

    //Check command line
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //Validate key

    //length
    if(strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    //Unique characters

    //first make all key characters uppercase for unity + check if non alphabetic characters exist
    for(int i = 0; i < 26; i++)
    {
        if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z'))
        {
            if(islower(argv[1][i]))
            {
                argv[1][i] = toupper(argv[1][i]);
            }
        }
        else
        {
            printf("Non alphabetic character found\n");
            return 1;
        }
    }

    //then check unique characters by running key from the left and from the right
    //if both flags are true at the same index, then the character is unique
    //repeat for all characters using ABC
    int temp1 = 0, temp2 = 0;

    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(ABC[i] == argv[1][j])
            {
               flag1 = true;
               temp1 = j;
               break;
            }
        }

        for(int k = 25; k >= 0; k--)
        {
            if(ABC[i] == argv[1][k])
            {
               flag2 = true;
               temp2 = k;
               break;
            }
        }

        if(flag1 == true && flag2 == true && temp1 == temp2)
        {
            flag1 = false;
            flag2 = false;
            continue;
        }
        else
        {
            printf("Non unique character found\n");
            return 1;
        }
    }

    //Get plaintext
    string input = get_string("plaintext: ");
    int n = strlen(input);
    char output[n];

    //Encipher

    //first create lower case encrypted table (argv is all uppercase from before)
    char lcase[26];
    for(int l = 0; l < 26; l++)
    {
        if(islower(argv[1][l]))
        {
            lcase[l] = argv[1][l];
        }
        else if(isupper(argv[1][l]))
        {
            lcase[l] = tolower(argv[1][l]);
        }
    }

    //if we need to encrypt a lowercase letter we use lcase string
    //if we need to encrypt an uppercase letter we use argv string
    //for every other character just copy paste
    //save everything to output string
    for(int m = 0; m < n; m++)
    {
        if(islower(input[m]))
        {
            output[m] = lcase[input[m] - 97];
        }
        else if(isupper(input[m]))
        {
            output[m] = argv[1][input[m] - 65];
        }
        else output[m] = input[m];
    }

    //Print encrypted text
    printf("ciphertext: ");
    for(int q = 0; q < n; q++)
    {
    printf("%c", output[q]);
    }
    printf("\n");
}
