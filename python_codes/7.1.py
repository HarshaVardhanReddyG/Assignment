import numpy as np
import mpmath as mp
import scipy
import matplotlib.pyplot as plt

bv = np.loadtxt('../bernouli.dat', dtype='double')
nv = np.loadtxt('../gau.dat', dtype='double')

def emp_err(g):
    ral_file = "../rand.dat"
    rv = np.loadtxt(ral_file, dtype='double')
    sig = rv*bv + nv
    n0 = np.count_nonzero(bv > 0)
    e0 = np.count_nonzero((sig < 0) & (bv > 0)) 
    return e0/n0

emp_err_vec = scipy.vectorize(emp_err, otypes=['double'])

def expected_err(g):
    g_new = 10**(g/10.0)
    return 0.5*(1 - ((g_new/(g_new+2))**(0.5)))

expected_err_vec = scipy.vectorize(expected_err, otypes=['double'])

maxrange=100
G = np.linspace(0,10,11)
x = np.linspace(0,10,1000)
plt.plot(G, emp_err_vec(G), 'o')
plt.plot(x, expected_err_vec(x))
plt.grid() #creating the grid
plt.xlabel('$\gamma$')
plt.ylabel('$P_e(\gamma)$')
plt.legend(["Numerical", "Theory"])
plt.savefig('../../figs/7_1.pdf')