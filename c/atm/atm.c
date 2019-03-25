#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4

void menuDisplay(char *, int *, int *);
void enterPin(char *, int *, int *);
void changePin(char *);
void checkTries(short, int *, int *);
int checkErrors(char *);

int main ()
{

  char pin[SIZE] = {'1', '2', '3', '4'};
  int correct, incorrect;
  correct = incorrect = 0;

  menuDisplay(pin, &correct, &incorrect);

  return 0;

}//end main()

void menuDisplay(char *pin, int *correct, int *incorrect)
{

  char *userInput;
  size_t nBytes = SIZE;

  userInput = malloc (SIZE);

  while (1)
  {

    printf("welcome To The Bank\n");
    printf("Enter 1: To enter PIN\n");
    printf("Enter 2: To change PIN\n");
    printf("Enter 3: To check entry tries\n");
    printf("Enter 4: To exit\n\n");

    printf("Option: ");
    getline(&userInput, &nBytes, stdin);

    if (isdigit(userInput[0]) != 0 && userInput[1] == '\n')
    {

      switch (*userInput)
      {

        case '1':

          enterPin(pin, correct, incorrect);
          break;

        case '2':

          changePin(pin);
          break;

        case '3':

          checkTries(3, correct, incorrect);
          break;

        case '4':

          exit(0);
          break;

        default:

          printf("ERROR: Invalid input\n\n");

      }//end switch

    }
    else
    {

      printf ("ERROR: Invalid input\n\n");

    }//end if

  }//end while

  free(userInput);

}//end menuDisplay()

void enterPin (char *pin, int *correct, int *incorrect)
{

  char *userInput;
  char enteredPin[SIZE] = {'\0', '\0', '\0', '\0'};
  size_t nBytes = SIZE;
  short tries = 0;

  userInput = malloc(nBytes);

  do
  {

    printf("Enter your PIN: ");

    getline(&userInput, &nBytes, stdin);

    printf("\n");

    if (checkErrors(userInput) != 4)
    {

      tries++;
      printf("The PIN you entered did not match\n");
      printf("Enter your PIN again\n");
      printf("Try %d out of 4\n\n", tries);

    }
    else
    {

      break;

    }//end if

  }//end do
  while (tries < 4);

  if (tries < 4)
  {

    sscanf (userInput, "%c %c %c %c", &*(enteredPin), &*(enteredPin + 1), &*(enteredPin + 2), (&*enteredPin + 3));

    if (memcmp(enteredPin, pin, SIZE) == 0)
    {

      printf("The PIN matches\n\n");
      checkTries(1, correct, incorrect);

    }
    else
    {

      printf("PIN does not match\n\n");
      checkTries(0,correct, incorrect);

    }//end inner if

  }
  else
  {

    printf("PIN does not match\n\n");
    checkTries(0,correct, incorrect);

  }//end if

  free(userInput);

}//end enteredPin()

void changePin (char *pin)
{

  char *userInput;
  char enteredPin[SIZE] = {'\0', '\0', '\0', '\0'};
  char enteredPin2[SIZE] = {'\0', '\0', '\0', '\0'};
  size_t nBytes = SIZE;
  short i;
  short tries = 0;

  userInput = malloc(SIZE);

  do
  {

    printf("Enter your PIN: ");
    getline(&userInput, &nBytes, stdin);

    printf("\n");

  }//end do
  while(checkErrors(userInput) != 4);

  sscanf(userInput, "%c %c %c %c", &*(enteredPin), &*(enteredPin + 1), &*(enteredPin + 2), (&*enteredPin + 3));

  if (memcmp(enteredPin, pin, SIZE) == 0)
  {

    do
    {

      printf("Enter your new PIN: ");
      getline(&userInput, &nBytes, stdin);

    }//end do
    while (checkErrors(userInput) != 4);

    sscanf(userInput, "%c %c %c %c", &*(enteredPin), &*(enteredPin + 1), &*(enteredPin + 2), (&*enteredPin + 3));

    do
    {

      printf("Confirm new PIN: ");
      getline(&userInput, &nBytes, stdin);

      printf("\n");

    }//end do
    while (checkErrors(userInput) == 4);

    sscanf(userInput, "%c %c %c %c", &*(enteredPin2), &*(enteredPin2 + 1), &*(enteredPin2 + 2), (&*enteredPin2 + 3));

    if (memcmp(enteredPin, enteredPin2, SIZE) == 0)
    {

      for (i = 0; i < SIZE; i++)
      {

        pin[i] = enteredPin[i];

      }//end for

    }
    else
    {

      printf("Your PIN did not match\n\n");

    }//end inner if

  }
  else
  {

    printf("ERROR your PIN did not match\n\n");

  }//end if

  free(userInput);

}//end changePin()

void checkTries (short success, int *correct, int *incorrect)
{

  if (success == 1)
  {

    ++*correct;

  }
  else if (success == 0)
  {

    ++*incorrect;

  }
  else
  {

    printf("You entered your PIN correctly %d times\n",  *correct);
    printf("You entered your PIN incorrectly %d times\n\n", *incorrect);

  }//end if

}//end checkTries()

int checkErrors (char *userInput)
{

  short errors = 0;
  short i;
  short check = 0;

  for (i = 0; i < SIZE + 1; i++)
  {

    if(isdigit(userInput[i]) != 0 && i < SIZE)
    {

      check++;

    }//end if

    if(userInput[i] != '\n' && i == SIZE)
    {

      check = 0;

    }//end if

  }//end for

  return check;

}//end checkErrors
