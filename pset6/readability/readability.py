from cs50 import get_string
import re

# Get text
text = get_string("Text: ")

# count letters
letters = len(text.replace(" ", ""))

# count words
words = len(text.split(" "))

# count sentences
sentences = len(re.split(r"\.|!|\?", text))

# calculate the index
index = (
    0.0588 * (100 * float(letters) / float(words))
    - 0.296 * (100 * float(sentences) / float(words))
    - 15.8
)

# convert index to integer
index = round(index)

# output index
if index > 16:
    print("Grade 16+")

elif index < 1:
    print("Before Grade 1")

else:
    print(f"Grade {int(index)}")
