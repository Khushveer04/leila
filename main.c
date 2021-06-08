/*
 ============================================================================
 Name        : TP XOR
 Author      : Khushveer Sujeebun
 Version     : super version
 Copyright   : Copyright notice
 Description : TP Cryptage XOR
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//Conversion in binary.

void conversion (char pwd[1000])// password as parameter to convert to binary.
{
int i,j,c;

    for(i=0;pwd[i] != '\0'; i++) // i equals to 0, while not termination of character string do ,increment i.
    {
        c=pwd[i]; //c is used to store temporarily.
        for(j=7;j+1>0;j--)
        {
            if (c>=(1<<j)) // << moves one by one in left hand side.
            {
                c=c-(1<<j);
                printf("1"); //Output 1
            }
            else
                printf("0");// Output 0
        }
        printf(" "); // space if 8 bits reached
    }
}


//encrypt function

int encrypt (char text[555])//text as parameter because it takes the value  of text to do the encryption.
{
// Initialisation of variables
//key is the "decalage"
//i is used to store values temporarily.
//values of each character is stored in ch and then compared.

		int  i,key ;
		char ch ;

//For lowercase characters

   printf("Enter key between 1 and 9 inclusive: ");
   scanf("%d", &key);
   printf("-------------------------------------------------------------------------------\n");

	for(i = 0; text[i] != '\0'; ++i){// i equals to 0, while not termination of character string do ,increment i.
		ch = text[i];// storing value of text[i] in ch temporarily.

		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key; // character equals to character plus key to get new alphabet for encryption.

			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1; //takes ascii of ch minus ascii of z plus a minus 1 which gives another ascii value between range of alphabets.
			}

			text[i] = ch;// text[i] takes value of ch (new alphabet).

		}

		//Uppercase characters

		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key; // character equals to character plus key to get new alphabet for encryption.

			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1; //takes ascii of ch minus ascii of Z plus A minus 1 which gives another ascii value between range of alphabets.
			}

			text[i] = ch; // text[i] takes value of ch (new alphabet).
		}
	}
	return key,text; //returns to main program.
	}

   //Function decrypt

   void decrypt(char text[555])
   {

   //Lowercase characters
   //x is used to store each character

    int x,key;
    char ch;

    printf("Enter key between 1 and 9 inclusive: ");// key must be between 1 and 9
    scanf("%d", &key);//takes key



	for(x = 0; text[x] != '\0'; ++x){ // x equals to 0, while not termination of character string do ,increment x.
		ch = text[x];// storing value of text[x] in ch temporarily.

		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;// character equals to character subtract key to get new alphabet for decryption.

			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1; //takes ascii of ch minus ascii of z plus a minus 1 which gives another ascii value between range of alphabets.
			}

			text[x] = ch; // text[x] takes value of ch (old alphabet).
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;// character equals to character subtract key to get new alphabet for decryption.

			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1; //takes ascii of ch minus ascii of Z plus A minus 1 which gives another ascii value between range of alphabets.
			}

			text[x] = ch; // text[x] takes value of ch (old alphabet).
		}

   }
}
int main()
{
    printf("-------------------------------------------------------------------------------\n");
    printf("Bonjour voici mon programme de cryptage.\nVeuillez bien lire les instructions ci-dessous s'il vous plait. Merci.\n");
    printf("-------------------------------------------------------------------------------\n");

    char text[500];//initialisaton of text.
    FILE* fichier;//Syntax of file.

    //Open text file

    fichier = fopen("TP1.txt","w");// write to file TP1.txt

	printf("Entrer une phrase s'il vous plait: ");//insert a sentence
    gets(text) ;//grabs text
    printf("-------------------------------------------------------------------------------\n");

	fprintf(fichier,"Sentence: %s \n", text);//print sentence in text document.

    int i,length,hash; // i as temporary variable to store characters.
    // length to store length of password.
    //hash is the xor between each character in password.
    char pwd[555];

    printf("Enter the password in string: "); // Enter password in letters.
    scanf("%s",pwd);
    printf("-------------------------------------------------------------------------------\n");

    printf("Password into binary is: "); // Password converted in binary.
    conversion(pwd);// Function to convert password in binary.
    printf("\n");
    printf("-------------------------------------------------------------------------------\n");


    //Hash word by word

    length= strlen(pwd); // gets the length of the password.

    for(i=0; i < length; i++) // i is zero, while i is less than length, increment i.

    {

    hash= hash ^ pwd[i]; // hash is xor of every characters in password.

    }

     //XOR letter and decal

     int k, key, xor; // k is the second hash using the "decalage", key is the decalage, xor is the variable name for the third hash.

     k= hash ^ key; // k is the xor of hash and key.

     //XOR cesar and k

     int atoi(const char *str); //syntax to initialise atoi function.
     xor= atoi(text) ^ k;// xor of text and k. Text has been converted to integer using function atoi.


    //Menu

    char choice[200]; // For choice making initialisation.

    printf("Enter choice encrypt or decrypt: "); //Choose between encrypt or decrypt.
    scanf("%s",choice); // grab choice.
    printf("-------------------------------------------------------------------------------\n");

    if ((strcmp(choice, "encrypt") == 0) || (strcmp(choice, "Encrypt") == 0) || (strcmp(choice, "ENCRYPT") == 0))// strcmp is to compare string with ....
    {
        encrypt(text);//calls function encrypt to encrypt given text.
        printf("Cesar encrypted text  :%s\n",text) ;//Output encrypted text.
        printf("-------------------------------------------------------------------------------\n");
        fprintf(fichier,"Cesar encrypted  : %s \n", text);//Writes into text document.
        printf("Hash is : %d\n",hash);// Output hash.
        printf("-------------------------------------------------------------------------------\n");
        printf("XOR letter et decal (K): %d\n",k); // Output k.
        printf("-------------------------------------------------------------------------------\n");
        printf("Encrypted XOR is: "); //Output Encrypted XOR.
        printf(xor);printf("\n");
        printf("-------------------------------------------------------------------------------\n");

        fprintf(fichier," XOR is : %s%s", xor,xor); // prints in text file.
    }

    if ((strcmp(choice, "decrypt") == 0) || (strcmp(choice, "Decrypt") == 0) || (strcmp(choice, "DECRYPT") == 0)) // strcmp is to compare string with ....
     {
            printf("Enter text first in encrypt mode ! ");
            printf("-------------------------------------------------------------------------------\n");
     }


    printf("Enter choice encrypt or decrypt or quit: ");
    scanf("%s",choice);
    printf("-------------------------------------------------------------------------------\n");

    if ((strcmp(choice, "encrypt") == 0) || (strcmp(choice, "Encrypt") == 0) || (strcmp(choice, "ENCRYPT") == 0)) // strcmp is to compare string with ....
    {
        printf("Already encrypted !") ;
        printf("\n");
    }

    if ((strcmp(choice, "decrypt") == 0) || (strcmp(choice, "Decrypt") == 0) || (strcmp(choice, "DECRYPT") == 0))// strcmp is to compare string with ....
     {
            decrypt(text);// calls function to decrypt
            printf("\n");
			fprintf(fichier,"\nDecrypted Cesar : %s \n", text); // writes in text document.
			printf("-------------------------------------------------------------------------------n");

			int k1;
            int atoi(const char *str); //initialisation atoi function.
            k1 = xor ^ atoi(text) ; // XOR  of variable xor and text conerted to integer using atoi function.

            printf("K is: %d\n",k1); // Output value of k.
            printf("-------------------------------------------------------------------------------\n");

            //XOR of k and key to find hash.
            hash = k1 ^ key;

            length= strlen(pwd);// Find length of password.

            for(i=0; i < length; i++) // i is zero, while i is less than length, increment i.
            {

             hash= hash ^ pwd[i];// hash is xor of every characters in password.

            }

            printf("Hash is now: %c\n",hash); //Output of hash.
            printf("-------------------------------------------------------------------------------\n");
            printf("Decrypted text : %s  \n" ,text) ; // Output of decrypted text.
            printf("-------------------------------------------------------------------------------\n");

     }

     if ((strcmp(choice, "quit") == 0) || (strcmp(choice, "QUIT") == 0) || (strcmp(choice, "Quit") == 0)) // strcmp is to compare string with ....
     {
			printf("Program finished !") ;
			printf("\n");
     }
     fclose(fichier);// close file.

            return 0;
}
