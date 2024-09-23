import csv
import sys

def main():

    # TODO: Check for command-line usage
    args = sys.argv[1:]
    if len(args) != 2:
        print("Error, program works with 2 arguments only")
        return 1

    # TODO: Read database file into a variable
    rows = list()
    with open(args[0]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)

    # # DEBUG
    # print("rows: ")
    # for row in rows:
    #     print(row)

    # getting all subsequences as the file headers minus the name field
    subsequences = list(reader.fieldnames)
    subsequences.pop(0)

    # # DEBUG
    # print("subsequences: ", end="")
    # print(subsequences)

    # TODO: Read DNA sequence file into a variable
    with open(args[1]) as file:
        sequence = str(file.read())

    # # DEBUG
    # print("sequence: " + sequence, end="")

    # TODO: Find longest match of each STR in DNA sequence
    results = []
    for i in subsequences:
        results.append(longest_match(sequence, str(i)))

    # # DEBUG
    # print("longest match: ", end="")
    # for i in range(0, len(results)):
    #     print(subsequences[i] + ": " + str(results[i]) + " | ", end="")

    # TODO: Check database for matching profiles
    for row in rows:


        # DEBUG
        # print("name: " + row["name"])

        match = True
        for i in range(0, len(results)):

            # DEBUG
            # print(subsequences[i] + ":" + row[subsequences[i]] + " result: " + str(results[i]) + " | ", end="")

            if int(row[subsequences[i]]) != int(results[i]):
                match = False
                break
        if match:
            print(row["name"])
            return 0
    print("No match")
    return 0


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


main()
