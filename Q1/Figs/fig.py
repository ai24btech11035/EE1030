import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA

# Define points A, B, and the center
A = np.array([4, -8]).reshape(-1,1)
B = np.array([2, 6]).reshape(-1,1)
C = np.array([3, -1]).reshape(-1,1)  # center (midpoint of A and B)

# Calculate the radius (half of AB)
r = LA.norm(B - A) / 2

# Function to generate circle points
def circ_gen(C, r):
    theta = np.linspace(0, 2*np.pi, 100)
    x_circ = np.zeros((2,100))
    x_circ[0,:] = r * np.cos(theta)
    x_circ[1,:] = r * np.sin(theta)
    x_circ = (x_circ.T + C.T).T
    return x_circ

# Line generation between two points
def line_gen(A, B):
    len = 100
    dim = A.shape[0]
    x_AB = np.zeros((dim, len))
    lam_1 = np.linspace(0, 1, len)
    for i in range(len):
        temp = A + lam_1[i] * (B - A)
        x_AB[:, i] = temp.T
    return x_AB

# Generate the circle and line
x_circ = circ_gen(C, r)
x_AB = line_gen(A, B)

# Plotting the circle and line
plt.plot(x_AB[0,:], x_AB[1,:], label='AB')
plt.plot(x_circ[0,:], x_circ[1,:], label='Circle')

# Scatter and label the points
tri_coords = np.block([A, B, C])
plt.scatter(tri_coords[0,:], tri_coords[1,:], color='black')
vert_labels = ['A', 'B', 'Center']
for i, txt in enumerate(vert_labels):
    plt.annotate(f'{txt}\n({tri_coords[0,i]:.0f}, {tri_coords[1,i]:.0f})',
                 (tri_coords[0,i], tri_coords[1,i]), 
                 textcoords="offset points", 
                 xytext=(-20,5), 
                 ha='center')

# Setting axis properties to match the diagram
plt.xlim(-5, 10)
plt.ylim(-10, 10)
plt.grid()  # Minor grid

# Set equal scaling for x and y axes to ensure the circle doesn't appear as an ellipse
plt.gca().set_aspect('equal', adjustable='box')

# Removing the top and right spines
ax = plt.gca()
ax.spines['top'].set_color('none')
ax.spines['right'].set_color('none')

# Moving the left and bottom spines to the center
ax.spines['left'].set_position('zero')
ax.spines['bottom'].set_position('zero')

# Add labels to the axes
plt.xlabel('X-axis')
plt.ylabel('Y-axis')

# Set the title and show the legend
plt.title('Circle with Diameter AB')
plt.legend(loc='best')

# Show the plot
plt.savefig('circle.png')
