#Importing numpy, scipy, mpmath and pyplot
import numpy as np

import matplotlib.pyplot as plt
import scipy


x = np.linspace(-10,10,50)#points on the x axis
simlen = int(1e6) #number of samples
err = [] #declaring probability list
randvar = np.loadtxt('other.dat',dtype='double')
for i in range(0,50):
	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list
def f(x) :
	if x<0 :
		return 0*x
	else :
		return 1-np.exp(-x/2)
vec_f = scipy.vectorize(f)

plt.plot(x,err,'o')#plotting empirical CDF
plt.plot(x, vec_f(x))#plotting analytical CDF
plt.grid() #creating the grid
plt.xlabel('$v$')
plt.ylabel('$F_V(v)$')
plt.legend(["Numerical","Theory"])
plt.savefig('../figs/other_cdf.pdf')