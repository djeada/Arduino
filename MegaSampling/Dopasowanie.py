import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import scipy as sy
import pylab as plb
import numpy as np
import csv
from lmfit import Model
from math import pi
np.seterr(divide='ignore', invalid='ignore')

y = []

with open('100Hz.csv') as plikCSV:
    czytnikCSV = csv.reader(plikCSV,delimiter=',')
    for wiersz in czytnikCSV:
        if wiersz:
            y.append(int(float(wiersz[1])*10//10))

y_1 = y[:len(y)//2]
y_2 = y[len(y)//2:]
x = np.array([x for x in range(1,len(y)//2+1)])

def clean(arr):
    i = 0
    while arr[i] == 0:
        del arr[i]

def recreate_sine(arr):
    temp = []
    i = 0
    while True:
        while arr[i] != 0:
            temp.append(arr[i])
            i += 1
            if i >= len(arr):
                return
        j = 0
        if i >= len(arr):
                return
        while arr[i] == 0:
            if j < len(temp):
                arr[i] = -1*temp[j]
                j += 1
            else:
                del arr[i]
            i += 1
            if i >= len(arr):
                return
        temp = []

def clean_zeros(arr):
    for i in range(len(arr)):
        j = i
        while abs(arr[j]) < 5:
            j += 1
            if j >= len(arr):
                return arr
        arr = arr[:i] + arr[j:]
    return arr
            
clean(y_2)
recreate_sine(y_2)
y_2 = clean_zeros(y_2)
y_2 = np.array(y_2)
x_2 = np.array([x for x in range(1,len(y_2)+1)])

def sinus(x, A, B, C):
    return A*np.sin(B*x) + C

#p0 = [0.68, 0, 1/17]
#coeffs, matcov = curve_fit(sinus, x, y, p0, maxfev=50000)

#plt.scatter(x,y_1)
plt.scatter(x_2,y_2)

plt.show()


