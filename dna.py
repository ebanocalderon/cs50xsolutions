 # Simulate a sports tournament
import re
import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    #Get command line argument for data and database
    database = sys.argv[1]
    sequence = sys.argv[2]

    #Open the files
    with open("dna/" + sequence) as file, open("dna/" + database) as file1 :
        
     #Get the headers of the database and assign them to columns
     dbData = csv.DictReader(file1)
     columns = dbData.fieldnames[1:]
     
     #Get the sequences 
     sqData = file.read()
     
    #Get the number of consecutive repetitions in the sequence file
     dnaSequence = {}
     for column in columns:
         dnaSequence[column] = dnaRepetitions(column, sqData)
         
     #Get mactches
     for row in dbData:
         if match(columns, dnaSequence, row):
             print(f"{row['name']}")
             return

     print("No Match")





#Function to get the number of consecutive repetitions
def dnaRepetitions(columns,sqData):
    i = 0
    while columns*(i + 1) in sqData:
        i += 1
    return i

#Function to match the repetitions with the users in database
def match(columns, dnaSequence, row):
    for column in columns:
        if dnaSequence[column] != int(row[column]):
            return False

    return True





if __name__ == "__main__":
    main()

