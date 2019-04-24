import sys
import string

def test():
    "Test if imported correctly"

    print ("FileHandling imported")
#END test()

def returnContents (filename):
    "Returns content of file"

    with open (filename, 'r') as file:
        return file.read()
    #END WITH
#END returnContents()

def returnWords (filename):
    "Returns list of words in file"

    with open (filename, 'r') as file:
        words = []

        for line in file:
            for word in line.split():
                table = str.maketrans('','', string.punctuation)

                if word.translate(table) != '':
                    words.append((word.translate(table)).upper())
                #END IF
            #END INNER F0R
        #END FOR
        return words
    #END WITH
#END returnWords()

def writeSimple (filename, data):
    "Writes all data into txt file without any formatting"

    with open (filename, 'a') as file:
        file.write(data)
    #END WITH
#END writeSimple()\

def formatWord(word):
    "Makes the word is formatted correctly so that the apostrophe is included in the word if needed"


#END formatWord
