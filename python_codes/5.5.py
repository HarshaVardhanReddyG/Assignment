import numpy as np

sz = 1000
N = np.loadtxt('../gau.dat', dtype='double')
X = np.loadtxt('../bernouli.dat', dtype='double')
Y = (10**(0.5))*X + N
e0 = np.count_nonzero((Y < 0) & (X > 0))
n0 = np.count_nonzero(X > 0)
e1 = np.count_nonzero((Y > 0) & (X < 0))
n1 = np.count_nonzero(X < 0)
print("P_(e|0): ", e0/n0)
print("P_(e|1): ", e1/n1)