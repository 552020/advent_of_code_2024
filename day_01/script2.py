def calculate_total_distance(file_path):
    with open(file_path, "r") as file:
        # Read the file and parse numbers
        left_numbers = []
        right_numbers = []

        for line in file:
            left, right = map(int, line.split())
            left_numbers.append(left)
            right_numbers.append(right)

    # Sort both lists
    left_numbers.sort()
    right_numbers.sort()

    # Calculate total distance
    total_distance = sum(abs(l - r) for l, r in zip(left_numbers, right_numbers))

    return total_distance


# Example usage
file_path = "input.txt"  # Replace with your file path
total_distance = calculate_total_distance(file_path)
print(f"Total Distance: {total_distance}")
