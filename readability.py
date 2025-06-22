from cs50 import get_string

def main():

    txt = get_string("Text: ")

    chars = 0

    word = 1

    complete = 0

    for i in txt:

        if i.isalpha():

            chars += 1

        elif i.isspace():

            word += 1

        elif i in ['.', '!', '?']:

            complete += 1

    L = (chars / word) * 100

    S = (complete / word) * 100

    ind = round(0.0588 * L - 0.296 * S - 15.8)

    if ind < 1:

        print("Before Grade 1")

    elif ind >= 16:

        print("Grade 16+")

    else:

        print(f"Grade {ind}")

if __name__ == "__main__":
    main()
