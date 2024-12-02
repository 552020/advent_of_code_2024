# Python script to process the numbers in a text file


def process_file(file_path):
    with open(file_path, "r") as file:
        # Read the file and split into lines
        lines = file.readlines()

    # Parse the numbers into two separate lists
    left_numbers = []
    right_numbers = []

    for line in lines:
        left, right = map(int, line.split())
        left_numbers.append(left)
        right_numbers.append(right)

    # Sort the numbers in both lists
    left_numbers.sort()
    right_numbers.sort()

    # Calculate the absolute differences and the total
    differences = [abs(l - r) for l, r in zip(left_numbers, right_numbers)]
    total_difference = sum(differences)

    # Display the results
    print(f"Sorted Left Numbers: {left_numbers}")
    print(f"Sorted Right Numbers: {right_numbers}")
    print(f"Differences: {differences}")
    print(f"Total Difference: {total_difference}")

    return total_difference


# Example usage
file_path = "input.txt"  # Replace with your file path
total = process_file(file_path)
print(f"Total Difference: {total}")
