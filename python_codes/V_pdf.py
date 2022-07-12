import numpy as np
import mpmath as mp
import scipy 
import matplotlib.pyplot as plt


maxrange=100
x = np.linspace(-5,10,maxrange)#points on the x axis
simlen = int(1e6) #number of samples
err = [] #declaring probability list
pdf = [] #declaring pdf list
#randvar = np.random.normal(0,1,simlen)
#randvar = np.loadtxt('uni.dat',dtype='double')
randvar = np.loadtxt('../gau_other.dat',dtype='double')

for i in range(maxrange):
	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list
	
for i in range(maxrange-1):
	test = (err[i+1]-err[i])/(x[i+1]-x[i])
	pdf.append(test) #storing the pdf values in a list

def chi_pdf(x):
    if (x>=0): return 0.5*np.exp(-x/2)
    else: return 0

chi_pdf_vec = scipy.vectorize(chi_pdf, otypes=['double'])

plt.plot(x[0:(maxrange-1)],pdf,'o')
plt.plot(x,chi_pdf_vec(x))#plotting the PDF
plt.grid() #creating the grid
plt.xlabel('$x$')
plt.ylabel('$p_V(x)$')
plt.legend(["Numerical","Theory"])
plt.savefig('../../figs/V_pdf.pdf')