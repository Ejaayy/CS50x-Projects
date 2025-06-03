import cs50

text = input("Input Text: ")

letter = 0
word = 1
sentence = 0

#count letters
for char in text:
    if char.isalpha():
        letter = letter + 1

#count word
for char in text:
    if char == ' ':
        word = word + 1

#count sentence
for char in text:
    if char in ['.', '!', '?']:
        sentence = sentence + 1

#let L be the percentage of that ratio
L = (letter / word) * 100
S = (sentence / word) * 100

#compute for the index
index = 0.0588 * L - 0.296 * S - 15.8

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:

    print(f"Grade {round(index)}")











