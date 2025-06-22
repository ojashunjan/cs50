import csv
import sys

def main():
    # Check for proper usage
    if len(sys.argv) != 3:

        print("Usage: python dna.py data.csv sequence.txt")

        sys.exit(1)

    # Read db file into a variable
    with open(sys.argv[1], newline='') as csvfile:

        rdr = csv.DictReader(csvfile)

        db = list(rdr)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file:

        dna = file.read()

    # Extract STRs from the db header
    actg = rdr.fieldnames[1:]

    # Compute longest same of each STR in the DNA sequence
    count = {}

    for STR in actg:

        count[STR] = longest_match(dna, STR)

    # Check db for matching profile
    for person in db:

        same = all(int(person[STR]) == count[STR] for STR in actg)

        if same:

            print(person['name'])

            return

    print("No same")


# Helper function
def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):

        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()
