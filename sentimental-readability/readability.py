import cs50

text = cs50.get_string("Text: ")


def letters(text):
    count = 0
    for i in range(len(text)):
        if text[i].isalpha() == True:
            count = count + 1
    return float(count)


def words(text):
    count = 1
    for i in range(len(text)):
        if text[i] == ' ':
            count = count + 1
    return float(count)


def sentances(text):
    count = 0
    for i in range(len(text)):
        if text[i] in ['.', '!', '?']:
            count = count + 1
    return float(count)


L = letters(text)/words(text) * 100
S = sentances(text)/words(text) * 100

index = 0.0588 * L - 0.296 * S - 15.8
index = round(index)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print("Grade", index)
