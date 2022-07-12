#Importing numpy, scipy, mpmath and pyplot
#from re import X
import numpy as np
#import mpmath as mp
#import scipy 
import matplotlib.pyplot as plt
y = np.loadtxt('rand.dat',dtype='double')
x=np.loadtxt('abs.dat',dtype='double')
plt.scatter(x,y)
plt.grid() #creating the grid
plt.xlabel('$X$')
plt.ylabel('$Y$')
#plt.legend(["Numerical","Theory"])
plt.savefig('../figs/scatter_plot.png')
plt.show()

