#!/usr/bin/python
# -*-coding:utf-8 -*
from sys import argv
import matplotlib.pyplot as plt
import numpy as np

x,y = np.loadtxt("Data.txt", unpack='true')

#plt.scatter(x,y)
plt.plot(x, y)
plt.show()


