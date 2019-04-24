#Program design: Get a text file and create another text file containing all words in the file and the frequency of the words.
#Author: Mikael Escolin

import sys
import FileHandling

def main():
    "Program starts here"

    hist = makeHist ("beeMovieScript.txt")

    for key in hist:
        data = key + ": " + str (hist[key]) + "\n"

        FileHandling.writeSimple("beeMovieScriptWordFrequency.txt", data)
    #END FOR
#END main()

def makeHist (data):
    "Makes a histogram out of data"

    wordList = FileHandling.returnWords(data)
    hist = {}

    for word in wordList:
        if word in hist:
            hist[word] += 1
        else:
            hist[word] = 1
        #END IF
    #END FOR
    return hist
#END makeHist()

if __name__ == "__main__":
    main()
