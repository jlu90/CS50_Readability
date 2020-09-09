import re


def main():
    # Get text
    text = input('Please Input a Text: ')

    # Split the text into words
    word_count = count_words(text)

    # Count the letters
    letters = count_letters(text)c

    # Split the text into sentences
    sentences = count_sentences(text)

    # Use the Coleman-Liau Index
    # Coleman-Liau Index was designed to tell what U.S. grade level is needed to understand a given text
    # L = Average number of letters per 100 words
    # S = Average number of sentences per 100 words
    # Formula = 0.0588 * L - 0.296 * S - 15.8

    l = 100 * (letters/word_count)
    s = 100 * (sentences/word_count)

    readability = 0.0588 * l - 0.296 * s - 15.8

    # Print Index
    if round(readability) < 1:
        print('Before Grade 1')
    elif round(readability) >= 16:
        print('Grade 16+')
    else:
        print(f'Grade {round(readability)}')


def count_words(text):
    text = text.replace('.', '')
    words = text.split(' ')
    return len(words)


def count_letters(text):
    for ch in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '"', "'", '.', ', ', '!', '?', '-', '$', '@', '()', ';', ':', ' ', '&', '#', '*']:
        if ch in text:
            text = text.replace(ch, '')
    return len(text)


def count_sentences(text):
    text = text.replace('"', '')
    text = re.split('\.|\?|!', text)
    if not text[-1]:
        text.pop()
    return len(text)


main()