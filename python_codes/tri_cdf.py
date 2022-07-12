#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import matplotlib.pyplot as plt
import scipy


x = np.linspace(-4,2,30)#points on the x axis
simlen = int(1e6) #number of samples
err = [] #declaring probability list
#randvar = np.random.normal(0,1,simlen)
randvar = np.loadtxt('tri.dat',dtype='double')
#randvar = np.loadtxt('gau.dat',dtype='double')
for i in range(0,30):
	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list
def tri_cdf(x):
	if x>=0 and x<=1 :
		return x*x/2
	elif x>1 and x<=2 :
		return 2*x-1-x*x/2
	else : 
		return 0*x
vec_tri_cdf = scipy.vectorize(tri_cdf)
	
plt.plot(x[0:(50-1)].T,err,'o')
plt.plot(x,vec_tri_cdf(x))#plotting the CDF
plt.grid() #creating the grid
plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')
plt.legend(["Numerical","Theory"])
plt.savefig('tri_cdf.pdf')
