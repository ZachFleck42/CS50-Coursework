import csv
import sys

def main():
    # Check to ensure proper usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Open the database file
    databaseFile = open(sys.argv[1], 'r')

    # Create a list of sequences to check for
    reader = csv.reader(databaseFile)
    firstRow = next(reader)

    sequences = []
    for i in range(1, len(firstRow), 1):
        sequences.append(firstRow[i])

    # Create a dictionary of people and their max consecutive sequence occurrences
    databaseFile.seek(0)
    tempReader = csv.DictReader(databaseFile)

    people = []
    for row in tempReader:
        people.append(row)

    # Close the database file
    databaseFile.close()

    # Open the sequence file
    sequenceFile = open(sys.argv[2], 'r')
    sequence = sequenceFile.read()

    # Create and populate a dictionary that stores maximum consecutive occurrences of sequences
    counts = {}
    for i in range(len(sequences)):
        counts[sequences[i]] = checkSequences(sequence, sequences[i])

    # Close the sequence file
    sequenceFile.close()

    # Check if the sequence counts matches those of any individual in the database
    for i in range(len(people)):
        if checkMatch(people[i], counts, sequences) == True:
            print(f"{people[i]['name']}")
            sys.exit()

    print("No match")


def checkSequences(sequence, s):
    sMax = 0
    for i in range(len(sequence)):
        tempMax = 0
        while sequence[i:i + len(s)] == s:
            tempMax += 1
            i += len(s)
        if tempMax > sMax:
            sMax = tempMax

    return sMax


def checkMatch(person, counts, sequences):
    for i in range(len(sequences)):
        if int(person[sequences[i]]) != int(counts[sequences[i]]):
            return False
    return True


main()