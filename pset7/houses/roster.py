import sys
import csv

from cs50 import SQL

if len(sys.argv) != 2:
    print("Usage: python import.py housename")
    sys.exit(1)

house = sys.argv[1]
db = SQL("sqlite:///students.db")

students = db.execute("SELECT * FROM STUDENTS WHERE house=? ORDER BY last;", house)

for student in students:
    if student['middle'] != None:
        print(f"{student['first']} {student['middle']} {student['last']}, born {student['birth']}")
    else:
        print(f"{student['first']} {student['last']}, born {student['birth']}")
