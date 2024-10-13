#Code by Preethika
#Date: October 13, 2024
#by GVV Sharma
#Released under GNU GPL
#Circle with Diameter AB

import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA

# Function to generate circle points
def circ_gen(O, r):
    len = 100
    theta = np.linspace(0, 2*np.pi, len)
    x_circ = np.zeros((2,len))
    x_circ[0,:] = r*np.cos(theta)
    x_circ[1,:] = r*np.sin(theta)
    x_circ = (x_circ.T + O).T
    return x_circ

# Function to generate line points between A and B
def line_gen(A, B):
    len = 100
    dim = A.shape[0]
    x_AB = np.zeros((dim,len))
    lam_1 = np.linspace(0, 1, len)
    for i in range(len):
        temp1 = A + lam_1[i] * (B - A)
        x_AB[:,i]= temp1.T
    return x_AB

# Given points A and B
A = np.array([4, -8]).reshape(-1,1)
B = np.array([2, 6]).reshape(-1,1)

# Center of the circle is the midpoint of AB
C = (A + B) / 2

# Radius of the circle is half the distance between A and B
r = LA.norm(B - A) / 2

# Generate the circle points
x_circ = circ_gen(C, r)

# Generate the line between A and B
x_AB = line_gen(A, B)

# Plot the circle and line
plt.plot(x_AB[0,:], x_AB[1,:], label='Diameter AB')
plt.plot(x_circ[0,:], x_circ[1,:], label='Circle')

# Label the points
plt.scatter([A[0,0], B[0,0], C[0,0]], [A[1,0], B[1,0], C[1,0]], c='r')
vert_labels = ['A', 'B', 'Center']
coords = [(A[0,0], A[1,0]), (B[0,0], B[1,0]), (C[0,0], C[1,0])]

for i, txt in enumerate(vert_labels):
    plt.annotate(f'{txt}\n({coords[i][0]:.0f}, {coords[i][1]:.0f})',
                 (coords[i][0], coords[i][1]),
                 textcoords="offset points", xytext=(-15,-10),
                 ha='center')

# Set axis labels and other graph properties
ax = plt.gca()
ax.spines['top'].set_color('none')
ax.spines['right'].set_color('none')
ax.spines['left'].set_position('zero')
ax.spines['bottom'].set_position('zero')

plt.grid(True)
plt.axis('equal')
plt.legend(loc='best')

plt.savefig('/sdcard/Download/circle_with_diameter.pdf')
