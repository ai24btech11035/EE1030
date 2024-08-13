import numpy as np

# Coefficient matrix (A)
A = np.array([[41, -62], [71, -41]])

# Constants matrix (B)
B = np.array([125, 45])

# Solve for X (i.e., x and y)
X = np.linalg.solve(A, B)

# Extract solutions
x, y = X

print(f"Solution: x = {x}, y = {y}")
