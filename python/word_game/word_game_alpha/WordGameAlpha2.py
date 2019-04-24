# Program description: Plays a word constructing game.
#                      Consists of 5 rounds and random letters are given to the user
#                      The user must make a real word from the list of 9 random letters
#                      Points are awarded for the word. 2 point for consonants and 1 for vowels
#                      The highest scoring word and its point will be displayed after the end of the game along with the users total.
# Author: Mikael Escolin
# Date: 21 Feb 2019
# Version: 0.1

import sys
import random

class Game ():

    lettersList = "eeeeeeeeeeeeaaaaaaaaaiiiiiiiiioooooooonnnnnnrrrrrrttttttllllssssuuuuddddgggbbccmmppffhhvvwwyykkjxqz"
    randomLetters = [0, 1, 2, 3, 4, 5, 6, 7, 8]
    rounds = 0
    points = [0, 0, 0, 0, 0]
    highscore = 0
    highscoreWord = "N/A"
    dictionary = contents("words_alpha_lite.txt", "dict").split()

    def displayMenu (self):

        "Displays the main menu of the game"

        print("""
-------------------------------------------------
         Welcome To Word Game Alpha

Would you like to play?
Enter yes or no.
Enter rules to display the rules of the game.

-------------------------------------------------
        """)

        userInput = input("Input: ")

        self.menuSelection(userInput)

    #END displayMenu()

    def menuSelection (self, userInput):

        "Checks userInput is valid input and calls appropriate function"

        if userInput.lower() == "yes":

            self.trackGame()

        elif userInput.lower() == "no":

            print("Exiting game")
            print("Goodbye")
            exit()

        elif userInput.lower() == "rules":

            self.displayRules()

        else:

            print("ERROR: Invalid input")
            print("Only \"yes\", \"no\" or \"rules\" is accepted\n")

        #END IF

    #END menuSelection()

    def displayRules ():

        "Displays rules of the game"

        print ("""
There will be 5 rounds where a 9 random letters
will appear and you have to make the longest word
you can.

Points will be added up each round.
1 point for a vowel and 2 points for a consonant.
0 points are awarded for words not found in the
dictionary.
        """)

    #END displayRules

    def roundOfGame (self):

        "This is where the game starts"

        print("Round %d\n" % (self.rounds))

        self.generateRandomLetter()

        print("%s\n" % (randomLetters))

        userInput = input("Answer: \n")

        return userInput

    #END roundOfGame()

    def calculatePoints (self, userInput):

        "Calculate points for the current round"

        for letter in userInput:

            if letter in "aeiou":

                self.points[rounds] += 1

            else:

                self.points[rounds] += 2

            #END IF

        #END FOR

    #END calculatePoints

    def generateRandomLetter (self):

        "Generates a list of random letters"

        for i in range(0, len(self.randomLetters)):

            self.randomLetters[i] = lettersList[random.randint(0, 98)]

        #END FOR

    #END generateRandomLetter

def checkValidWord (self, userInput):

    "Checks if only letters are used"

    if userInput.isalpha():

        return self.checkRepeats(userInput)

    else:

        print("Error: Invalid input")
        print("Only letters can be used")
        return 0

    #END IF

#END checkValidWord

    def checkRepeats (self, userInput):

        "Checks that only each letter is used once in the random letters generated"

        valid = 0

        for i in range(0, len(userInput)):

            for j in range(0, len(randomLetters[j])):

                self.randomLetters[j] = '\0'
                valid += 1
                break

            #END INNER FOR

        #END FOR

        if valid == len(userInput):

            return(self.checkRealWord(userInput))

        else:

            print("Each letter in random letters list can only be used once\n")
            return 0

        #END IF

    #END checkRepeats

    def checkRealWord (self, userInput):

        "Checks if the word entered is a real word"

        if userInput.lower() in self.dictinary:

            return 1

        else:

            print("Not a real word\n")
            return 0

        #END IF

    #END checkRealWord

    def trackGame (self):

        ""

#END Game

def main():

    "Program starts here"

    GameEntity = Game()

    GameEntity.displayMenu()


#END main()

def contents(filename, name):

    "Return contents of text file as strings"

    with open(filename, 'r') as name:

        return name.read()

    #END WITH

#END contents()

if __name__ == "__main__":

    main()

#END PROGRAM
