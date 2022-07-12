import numpy as np
import mpmath as mp
from matplotlib import pyplot as plt
import scipy

X = np.loadtxt('../bernouli.dat', dtype='double')
N = np.loadtxt('../gau.dat', dtype='double')

A = np.linspace(0, 10, 11)
err = np.loadtxt('../err.dat',dtype='double')

def qfunction(x):
    return (0.5)*mp.erfc(x/np.sqrt(2))

qfunc_vec = scipy.vectorize(qfunction, otypes=['double'])

plt.plot(A.T,err,'o')
def qfunction(x):
    return (0.5)*mp.erfc(x/np.sqrt(2))

qfunc_vec = scipy.vectorize(qfunction, otypes=['double'])

A = np.linspace(0, 10, 15)
plt.semilogy(A, err_vec(A), 'o')
plt.semilogy(A, qfunc_vec(10**(A/10.0)))

plt.grid()
plt.xlabel('$A$ (dB)')
plt.ylabel('$P_e(A)$')
plt.legend(["Numerical", "Theory"])
plt.savefig('../../figs/P_e_semilog.pdf')


