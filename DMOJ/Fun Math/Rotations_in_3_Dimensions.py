from math import sqrt, sin, cos


def unit_vector(x_pos, y_pos, z_pos):
    magnitude = sqrt(x_pos**2 + y_pos**2 + z_pos**2)

    return([x_pos/magnitude, y_pos/magnitude, z_pos/magnitude])


def rotation(x_orig, y_orig, z_orig, x_new, y_new, z_new, t):
    # u[0]:x, u[1]:y, u[2]:z
    u = unit_vector(x_new, y_new, z_new)

    # Rotation matrix for unit vector and angle theta to calculate x', y', and z'
    x_prime = x_orig*(cos(t) + u[0]**2*(1-cos(t))) + y_orig*(u[0]*u[1]*(1-cos(t)) - u[2]*sin(t)) + z_orig*(u[0]*u[2]*(1-cos(t)) + u[1]*sin(t))
    y_prime = x_orig*(u[1]*u[0]*(1-cos(t)) + u[2]*sin(t)) + y_orig*(cos(t) + u[1]**2*(1-cos(t))) + z_orig*(u[1]*u[2]*(1-cos(t)) - u[0]*sin(t))
    z_prime = x_orig*(u[2]*u[0]*(1-cos(t)) - u[1]*sin(t)) + y_orig*(u[2]*u[1]*(1-cos(t)) + u[0]*sin(t)) + z_orig*(cos(t) + u[2]**2*(1-cos(t)))

    return f"{x_prime} {y_prime} {z_prime}"


for i in range(int(input())):
    x, y, z, rx, ry, rz, theta = map(float, input().split())
    print(rotation(x, y, z, rx, ry, rz, theta))
