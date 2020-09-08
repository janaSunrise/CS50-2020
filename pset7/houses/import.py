import sys
import csv

from cs50 import SQL

if len(sys.argv) != 2:
    print("Usage: python import.py <file_name>.csv")
    sys.exit(1)

csvfile = sys.argv[1]
db = SQL("sqlite:///students.db")

with open(csvfile, "r") as file:
    reader = csv.DictReader(file)

    for rows in reader:
        name = rows["name"].split(" ")
        house = rows["house"]
        birth = rows["birth"]

        if len(name) == 1:
            db.execute(
                """
                INSERT INTO students(first, middle, last, house, birth) values(?, NULL, NULL, ?, ?)
                """,
                name[0],
                house,
                birth
            )

        elif len(name) == 2:
            db.execute(
                """
                INSERT INTO students(first, middle, last, house, birth) values(?, NULL, ?, ?, ?)
                """,
                name[0],
                name[1],
                house,
                birth
            )

        elif len(name) == 3:
            db.execute(
                """
                INSERT INTO students(first, middle, last, house, birth) values(?, ?, ?, ?, ?)
                """,
                name[0],
                name[1],
                name[2],
                house,
                birth
            )

