from cs50 import get_string


def main():
    # Main function

    # Text insertion and functions
    text = get_string("Text: ")
    letters = int(count_letters(text))
    words = int(count_words(text))
    sentences = int(count_sentences(text))

    # Readability index calculation
    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    grade = int(round(index, 0))

    # # DEBUG output
    # L = str(round(L, 2))
    # S = str(round(S, 2))
    # print("letters ---> " + str(letters))
    # print("words -----> " + str(words))
    # print("sentences -> " + str(sentences))
    # print("L ---------> " + L)
    # print("S ---------> " + S)
    # print("index = 0.0588 * " + L + " - 0.296 * " + S + " - 15.8")
    # print("index = " + str(round(index, 2)))

    # Main Output
    if index >= 16:
        print("Grade 16+")
    if index > 1 and index < 16:
        print("Grade " + str(grade))
    if index < 1:
        print("Before Grade 1\n")


def count_letters(text):
    # Counting all letters in the text
    letters = 0
    for char in text:
        if char.isalpha():
            letters += 1
    return letters


def count_words(text):
    # Counting all words in the text using split function
    words = 0
    wordlist = text.split()
    for _ in wordlist:
        words += 1
    return words


def count_sentences(text):
    # Counting all sentences in the text, based in punctuation existence
    sentences = 0
    for char in text:
        if char == "." or char == "!" or char == "?":
            sentences += 1
    return sentences


main()
