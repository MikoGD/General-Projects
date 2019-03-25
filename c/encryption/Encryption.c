/*
Program description:  This program is a simple security authoristation program based on access codes.
                      The program will be menu driven with 5 options to chose from the menu:
                      1. Enter a code: The user will be able any 4 digit interger code and appropriate error checking will be done using a function.
                      2. Encrypt code: The code entered from option 1 will then be encrypted and compared to the default athorisation code and will display a message if they match or not.
                         Only codes NOT decrypted can be encrypted.
                      3. Decrypt a code: Decrypt a code from option 1 and display the decrypted code.
                         Only codes that ARE encrypted can be decrypted.
                      4. Display tries: This will display the amount of times the user enters right code and the amount of times the user enters the wrong code.
                      5. Exit: This will end the program.
                      The program will continue to go back to the menu after each appopriate task is done so the user can choose another task to do.
Author: Mikael Escolin
Date: 28 Feb 2019
Revised: 19 Mar 2019
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CODE_SIZE 4
#define TRY_SIZE 2
#define NBYTES 5

void displayMenu();
char *getUserInput();
void runOptionFromMenu(char *, uint8_t[], char[], char[]);
void getCode(char[]);
void encryptCode(char[]);
uint8_t isCodeEncrypted(char[], char[]);
void storeCode(char[], char[]);
void resetEnteredCode(char[]);
void doesCodeMatch(char[], uint8_t[]);
void decryptCode(char[], char[]);
void displayAttempts(uint8_t[]);

const char accessCode[CODE_SIZE] = {'4' , '5', '2', '3'};

int main ()
{
  /*
  These 2 arrays will hold codes entered by the user.
  enteredCode will hold the code temporarily until it is verified and test with the accessCode. Then it will be stored in curCode.
  curCode will hold the verified code. It will be used to see if the code is already encrypted so we can tell if the code can be encrypted or decrypted.
  */
  char curCode[CODE_SIZE] = {'\0', '\0', '\0', '\0'};
  char enteredCode[CODE_SIZE] = {'\0', '\0', '\0', '\0'};
  /*
  Keeps count of the amount of time the user enters the right code (accessCode).
  If they enter it right the number at index 0 will increment by 1.
  If they enter it wrong the number at index 1 will increment by 1.
  */
  uint8_t enteredCodeTries[TRY_SIZE] = {0, 0};

  //Continuously runs the program until the user chooses option 5 to exit
  do
  {
    displayMenu();
    runOptionFromMenu(getUserInput(), enteredCodeTries, curCode, enteredCode);
  }
  while(1);
}//END main()

void displayMenu()
{
  printf("---------------------------------------------------\n");
  printf("1: Enter code\n");
  printf("2: Encrypt code\n");
  printf("3: Decrypt code\n");
  printf("4: Displays amount of times coded entered correctly\n");
  printf("5: Exit program\n\n");

  //Asks for the user's input and puts it in a string with \n at the end instead of \0.
  printf("Enter: ");
}//END displayMenu()

//Gets user input and returns the input as a string
char *getUserInput()
{
  //String to store input
  char *userInput;
  //Size of string, may change if input is bigger than size which is done by getline();
  size_t nBytes = NBYTES;
  char *pos;

  //Allocate memory and gets input and stores it in userInput
  userInput = malloc(nBytes);
  getline(&userInput, &nBytes, stdin);
  printf("\n");

  //Replaces \n with \0
  if ((pos=strchr(userInput, '\n')) != NULL)
  {
    *pos = '\0';
  }
  else
  {
    printf("ERROR: could not replace \\n\n\n");
  }//END IF

  return userInput;
}//END getUserInput()

void runOptionFromMenu(char *userInput, uint8_t enteredCodeTries[], char curCode[], char enteredCode[])
{
  if(isdigit(*userInput) == 0 || *(userInput + 1) != '\0')
  {
    printf("ERROR: Invalid input\n");
    printf("Only options from the menu can be entered\n\n");
    return;
  }//END IF

  switch(*userInput)
  {
    case '1':
    {
      getCode(enteredCode);
      break;
    }//END CASE

    case '2':
    {
      encryptCode(enteredCode);
      storeCode(enteredCode, curCode);
      doesCodeMatch(curCode, enteredCodeTries);
      break;
    }//END CASE

    case '3':
    {
      decryptCode(enteredCode, curCode);
      break;
    }//END CASE

    case '4':
    {
      displayAttempts(enteredCodeTries);
      break;
    }//END CASE

    case '5':
    {
      printf("Exiting program...\n");
      printf("Goodbye\n\n");
      exit(0);
      break;
    }//END CASE

    default:
    {
      printf("ERROR: Invalid input\n");
      printf("Only options from the menu can be entered\n\n");
    }//END DEFAULT
  }//END SWITCH
}//END runOptionFromMenu()

/*
Gets code from user and checks if it a valid code
If the code is valid then copy it into enteredCode
If not then return null.
*/
void getCode(char enteredCode[])
{
  char *userInput;

  uint8_t i;

  //Gets input by using getUserInput() function
  printf("Enter code: ");
  userInput = getUserInput();
  printf("\n");

  /*
  Checks each literal to see if it is a digit
  If it is continue the loop
  If it isn't, display an error message and return null.
  */
  for(i = 0; i < CODE_SIZE; i++)
  {
    if(isdigit((userInput + i) == 0))
    {
      printf("ERROR: Invalid input\n");
      printf("Only a 4 digit code can be entered\n\n");
      return;
    }
    else
    {
      continue;
    }//END IF
  }//END FOR

  //Copies userInput into enteredCode.
  for(i = 0; i < CODE_SIZE; i++)
  {
    *(enteredCode + i) = *(userInput + i);
  }//END FOR
}//END getCode()

/*
Encryptes the code using the following algorithm:
-1. Swap first and third number
-2. Swap second and last number
-3. Increase all numbers by 1
-4. If number is >9 go back to 0
*/
void encryptCode(char enteredCode[])
{
  uint8_t i;
  char codeCopy[CODE_SIZE] = {'\0', '\0', '\0', '\0'};

  //Stops encryption if there is not code entered and display error message
  if(*enteredCode == '\0')
  {
    printf("ERROR: no code found\n\n");
    return;
  }//END IF

  //Copies the code into a temporary array
  for(i = 0; i < CODE_SIZE; i++)
  {
    *(codeCopy + i) = *(enteredCode + i);
  }//END FOR

  //Using the temporary array the numbers are swapped according to the algorithm
  for (i = 0; i < CODE_SIZE - 2; i++)
  {
    *(enteredCode + i) = *(codeCopy + i + 2);
    *(enteredCode + i + 2) = *(codeCopy + i);
  }//END for

  //Increases the number by one and if it 9 change it to 0 instead
  for (i = 0; i < CODE_SIZE; i++)
  {
    if(*(enteredCode + i) == '9')
    {
      *(enteredCode + i) = '0';
    }
    else
    {
      *(enteredCode + i) += 1;
    }//END INNER IF
  }//END FOR
}//END encryptCode()

uint8_t isCodeEncrypted(char enteredCode[], char curCode[])
{
  uint8_t i;

  for(i = 0; i < CODE_SIZE; i++)
  {
    if(*(enteredCode + i) == *(curCode + i))
    {
      return 1;
    }
    else
    {
      continue;
    }//END IF
  }//END FOR

  return 0;
}//END isCodeEncrypted()

/*
Stores code into curCode if the code isn't already encrypted.
*/
void storeCode(char enteredCode[], char curCode[])
{
  uint8_t i;

  /*
  Checks to see if code is encrypted
  If it is display error message and reset enteredCode
  Else copy enteredCode into curCode and reset enteredCode
  */
  if(isCodeEncrypted(enteredCode, curCode) == 1)
  {
    printf("Error: could not encrypt code\n");
    printf("Code already encrypted\n\n");

    resetEnteredCode(enteredCode);

    return;
  }
  else
  {
    for(i = 0; i < CODE_SIZE; i++)
    {
      *(curCode + i) = *(enteredCode + i);
    }//END FOR

    resetEnteredCode(enteredCode);
  }//END IF
}//END storeCode()

/*
Fills enteredCode with \0 so it can take in a new code
Program requires enteredCode to be empty once it is stored to function properly
For example encryptCode function checks to see if a code has been entered by checking if there is any \0 in it.
A new code should be entered every single time an encryption or decryption is done whether they fail or not.
*/
void resetEnteredCode(char enteredCode[])
{
  uint8_t i;

  for(i = 0; i < CODE_SIZE; i++)
  {
    *(enteredCode + i) = '\0';
  }//END FOR
}//END resetEnteredCode()

/*
Checks to see if the code entered by the user matches the access code
If it does display message saying it matches, increment first index of enteredCodeTries as this tracks the amount of time code was entered right
Else display message saying it doesn't match, increment second index of enteredCodeTries as this tracks the amount of time code was entere wrong
*/
void doesCodeMatch(char curCode[], uint8_t enteredCodeTries[])
{
  uint8_t i;

  for(i = 0; i < CODE_SIZE; i++)
  {
    if(*(curCode + i) != *(accessCode + i))
    {
      printf("Wrong code entered\n\n");
      ++*(enteredCodeTries + 1);
      return;
    }
    else
    {
      continue;
    }//END IF
  }//END FOR

  ++*enteredCodeTries;
  printf("Right code entered\n\n");
}//END doesCodeMatch()

/*
If the code is already encrypted then continue decryption if not display error message and stop decryption
Decryptes the code using the following algorithm:
-1. Swap the first and third number
-2. Swap the second and last number
-3. Decrease each number by 1
-4. If number is <0 go to 9
*/
void decryptCode(char enteredCode[], char curCode[])
{
  uint8_t i;
  char codeCopy[CODE_SIZE] = {'\0', '\0', '\0', '\0'};
  /*
  Checks to see if code is encrypted to allow decryption
  If code is not encrypted then display error message
  Else continue decryption
  */
  if(isCodeEncrypted(enteredCode, curCode) == 0)
  {
    printf("ERROR: could not decrypt code\n");
    printf("Code not encrypted\n\n");

    return;
  }//END IF

  //Copies the code into a temporary array
  for(i = 0; i < CODE_SIZE; i++)
  {
    *(codeCopy + i) = *(enteredCode + i);
  }//END FOR

  //Using the temporary array the numbers are swapped according to the algorithm
  for (i = 0; i < CODE_SIZE - 2; i++)
  {
    *(enteredCode + i) = *(codeCopy + i + 2);
    *(enteredCode + i + 2) = *(codeCopy + i);
  }//END for

  //Decreases the number by one and if it is 0 change it to 9 instead
  for (i = 0; i < CODE_SIZE; i++)
  {
    if(*(enteredCode + i) == '0')
    {
      *(enteredCode + i) = '9';
    }
    else
    {
      *(enteredCode + i) -= 1;
    }//END INNER IF
  }//END FOR

  printf("Decrypted code: ");

  for(i = 0; i < CODE_SIZE; i++)
  {
    printf("%c", *(enteredCode + i));
  }//END FOR

  printf("\n\n");
}//END decryptCode()

//Display attempts at entering a code that matches the accessCode
void displayAttempts(uint8_t enteredCodeTries[])
{
  printf("You entered the code right %d times\n", *enteredCodeTries);
  printf("You entered the code wrong %d times\n\n", *(enteredCodeTries + 1));
}//END displayAttempts()
