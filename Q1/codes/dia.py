# Function to find the coordinates of point A
def find_point_A(center, point_B):
    # Extract center and point_B coordinates
    center_x, center_y = center
    B_x, B_y = point_B
    
    # Use the midpoint formula to find A
    A_x = 2 * center_x - B_x
    A_y = 2 * center_y - B_y
    
    return A_x, A_y

# Given values
center = (3, -1)
point_B = (2, 6)

# Find coordinates of point A
point_A = find_point_A(center, point_B)
print("Coordinates of point A:", point_A)
