import csv
import sys

def main():
    # Ensure correct usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read the DNA database into a list of dictionaries
    with open(sys.argv[1], newline='') as csvfile:
        reader = csv.DictReader(csvfile)
        database = list(reader)
        str_sequences = reader.fieldnames[1:]  # Exclude the 'name' field

    # Read the DNA sequence to be analyzed
    with open(sys.argv[2], 'r') as file:
        dna_sequence = file.read()

    # Compute the longest match of each STR in the DNA sequence
    str_counts = {}
    for STR in str_sequences:
        str_counts[STR] = longest_match(dna_sequence, STR)

    # Check for a matching profile in the database
    for person in database:
        match = True
        for STR in str_sequences:
            if int(person[STR]) != str_counts[STR]:
                match = False
                break
        if match:
            print(person['name'])
            return

    print("No match")

def longest_match(sequence, subsequence):
    """
    Returns the length of the longest run of subsequence in sequence.
    """
    longest_run = 0
    subseq_length = len(subsequence)
    seq_length = len(sequence)

    for i in range(seq_length):
        count = 0
        while True:
            start = i + count * subseq_length
            end = start + subseq_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)

    return longest_run

if __name__ == "__main__":
    main()
