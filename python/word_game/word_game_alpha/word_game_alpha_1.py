#Program description: A game that consist of 5 rounds. Each round the user has to make a word from a list of random letters generated

import sys
import random

################## START OF FUNCTIONS #####################

def contents (filename, name):

    "Return contents of text file as strings"

    with open (filename, "r") as name:
        return name.read ()

def random_letter_generator ():

    "Generates random letters into a list from letters_list"

    global random_letters
    i = 0

    for x in random_letters:

        random_letters[i] = letters_list[random.randint(0, 98)]

        i += 1

def check_repeats (input):

    "Checks that only each letter is used once"

    global valid
    i = 0
    valid = 0

    while i < len (input):

        j = 0

        while j < len(random_letters):

            if input[i] == random_letters[j]:

                random_letters[j] = '\0'
                valid += 1
                j = len (random_letters)

            else:

                j += 1

        i += 1

    return valid

def check_valid (input):

    "Checks if input is valid i.e letters only and is a real word"

    valid_words = contents ("words_alpha_lite.txt", "dictionary").split ()

    global valid
    valid = 0

    if input.isalpha ():

        if input.lower () in valid_words and check_repeats (input) == len (input):

            valid = 1

        elif input.lower () not in valid_words and check_repeats (input) == len (input):

            print ("\nNot a real word")
            valid = 0

        else:

            print ("\nERROR: INVALID INPUT")
            print ("Only letters from the list can be used and can only repeat if there are repeats")
            valid = 0

    else:

        print ("\nERROR: INVALID INPUT")
        print ("Only letters can be used")
        valid = 0

    return valid

def points_calculator (input):

    "Calculates points for word. Vowels = 1 point, consonants = 2 points"

    i = 0
    global points

    for x in input:

        if input[i] in "aeiou":

            points[rounds] += 1

        else:

            points[rounds] += 2

        i += 1

def start_game ():

    "Start of the game & main display"

    global rounds
    rounds = 0
    global points
    points = [0, 0, 0, 0, 0]
    global highscore, highscore_word

    while rounds < 5:

        random_letter_generator ()

        print ("\nRound %d" % (rounds + 1))

        print ("\n%s" % (random_letters))

        user_input = input ("Enter your word: ")

        if check_valid (user_input) == 1:

            points_calculator (user_input)

            print ("\nYou got %d points" % (points[rounds]))

            if rounds == 0:

                highscore = points[rounds]
                highscore_word = user_input
                rounds += 1

            else:

                if points[rounds] > highscore:

                    highscore = points[rounds]
                    highscore_word = user_input
                    rounds += 1

                else:

                    rounds += 1

        else:

            print ("\nYou got 0 points")
            rounds += 1

    score = 0

    for x in points:

        score += x

    print ("\nYour score is %d" % (score))
    print ("Your highscore was %d with the word %s" % (highscore, highscore_word))


def display_rules ():

    "Displays rules of the game"

    back = 1

    print ("""
There will be 5 rounds where a 9 random letters
will appear and you have to make the longest word
you can.

Points will be added up each round.
1 point for a vowel and 2 points for a consonant.
0 points are awarded for words not found in the
dictionary.
    """)

    while back == 1:

        user_input = input ("Enter 'back' to go back: ")

        print (user_input)

        if user_input.lower () == "back":

            back = 0
            print ("true")

        else:

            back = 1
            print ("false")

    return back



################## END OF FUNCTIONS #####################

if __name__ == "__main__":

    continue_program = 1
    letters_list = "eeeeeeeeeeeeaaaaaaaaaiiiiiiiiioooooooonnnnnnrrrrrrttttttllllssssuuuuddddgggbbccmmppffhhvvwwyykkjxqz"
    random_letters = [0, 1, 2, 3, 4, 5, 6, 7, 8]
    play_again = 1
    rounds = 0
    points = [0, 0, 0, 0, 0]
    valid = 0

    while continue_program == 1:

        print("""
-------------------------------------------------
         Welcome To Word Game Alpha

Would you like to play?
Enter yes or no.
Enter rules to display the rules of the game.

-------------------------------------------------
        """)

        back = 0

        user_input = input ("Answer: ")

        if user_input.lower () == "yes":

            while play_again == 1:

                start_game ()

                valid = 0

                while valid == 0:

                    print ("\nWould you like to play again?")
                    user_input = input ("Enter yes or no: ")

                    if user_input.lower () == "yes":

                        valid = 1

                    elif user_input.lower () == "no":

                        play_again = 0
                        continue_program = 0
                        valid = 1

                    else:

                        print ("ERROR: INVALID INPUT")
                        print ("Enter yes, no or rules only")

        elif user_input.lower () == "no":

            continue_program = 0

        elif user_input.lower () == "rules":

                display_rules ()

        else:

            print ("\nERROR: INVALID INPUT")
            print ("Only yes or no is accepted")

    print ("\nExiting Program....")
    print ("Goodbye!\n")
