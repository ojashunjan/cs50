def main():
    # Prompt the user for height between 1 and 8 inclusive
    while True:

        try:

            height = int(input("Height: "))

            if 1 <= height <= 8:

                break

        except ValueError:

            continue

    for i in range(1, height + 1):

        space = height - i

        block = i

        print(" " * space + "#" * block)


if __name__ == "__main__":
    main()
