import sys
import re
import csv

# Check the args
if len(sys.argv) == 3:

    # Get the arg values
    file = sys.argv[1]
    sequence = sys.argv[2]

    # get the txt file content
    with open(sequence, "r") as content:
        data = content.read()

    # read the CSV file
    with open(file, "r") as csvfile:
        reader = csv.reader(csvfile)
        reader = list(reader)  # make it a list

        reader[0].remove("name")  # remove name elem
        i = reader[0]

    valuelist = []
    for q in range(len(i)):  # the small CSV i = 3. so iterates for each nucleotide.

        res = max(re.findall('((?:' + re.escape(i[q]) + ')*)', data), key=len)

        max_counter = len(res) / len(i[q])

        # max count of the STR in row.
        valuelist.append(int(max_counter))

    valuelist = list(map(str, valuelist))

    final = list(reader)
    final.pop(0)

    for person in final:
        if person[1:] == valuelist:
            print(person[0])
            break
        elif person == final[-1]:
            print("No match")

else:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)
