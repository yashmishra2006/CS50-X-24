import csv
import sys


def main():

    if len(sys.argv) != 3:
        print('Error in name of csv or text file')

    lst = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        lst = reader.fieldnames
        lst.pop(0)

    rows = []
    with open(sys.argv[1]) as file:
        reader = csv.reader(file)
        for row in reader:
            rows.append(row)

    with open(sys.argv[2]) as txtfile:
        dnadata = txtfile.read()

    repeat = []
    for i in range(len(lst)):
        repeat.append(longest_match(dnadata, lst[i]))

    for i in range(len(rows)-1):
        count = 0
        for j in range(len(lst)):

            if int(rows[i+1][j+1]) == int(repeat[j]):
                count = count + 1
        if count == len(repeat):
            name = rows[i+1][0]
            return name

    else:
        return "No Match"


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


print(main())
