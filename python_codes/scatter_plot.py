#Importing numpy, scipy, mpmath and pyplot
#from re import X
import numpy as np
import mpmath as mp
import scipy 
import matplotlib.pyplot as plt
simlen = int(1e6)
x = np.linspace(0,1,simlen)
a = np.loadtxt('../bernouli.dat',dtype='double')
b =np.loadtxt('../gau.dat',dtype='double')
y=10**(0.5)*a+b
#x=np.loadtxt('abs.dat',dtype='double')
plt.plot(x, y, 'o')
plt.grid() #creating the grid
plt.xlabel('$n$')
plt.ylabel('$Y$')
#plt.legend(["Numerical","Theory"])
plt.savefig('../../figs/scatter_plot.png')