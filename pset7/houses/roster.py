import sys

from cs50 import SQL

# Handle the arguments.
if len(sys.argv) != 2:
    print("Usage: python import.py housename")
    sys.exit(1)

# Get CLI args.
house = sys.argv[1]

# Connect to the database.
db = SQL("sqlite:///students.db")

# Get the students in the house.
students = db.execute("SELECT * FROM STUDENTS WHERE house=? ORDER BY last;", house)

# Print the students.
for student in students:
    if student["middle"] is not None:
        print(
            f"{student['first']} {student['middle']} {student['last']}, born {student['birth']}"
        )
    else:
        print(f"{student['first']} {student['last']}, born {student['birth']}")
