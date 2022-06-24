from cs50 import get_string

s = get_string("Text: ")

wordCount = len(s.split())

charCount = 0
for i in range(len(s)):
    if s[i].isalpha() == True:
        charCount += 1

sentenceCount = 0
for i in range(len(s)):
    if s[i] == '.' or s[i] == '?' or s[i] == '!':
        sentenceCount += 1

wordsX = 100 / wordCount
charX = wordsX * charCount
sentenceX = wordsX * sentenceCount

index = (0.0588 * charX) - (0.296 * sentenceX) - 15.8

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")