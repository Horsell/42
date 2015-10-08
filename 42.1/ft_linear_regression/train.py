#!/usr/bin/python
# -*-coding:utf-8 -*
from sys import argv
import matplotlib.pyplot as plt
import numpy as np
import math
import re

def	get_xy():
	data = open("data.csv", "r")
	content = data.read()
	data.close()
	i = 0
	while (content[i] != '\n'):
		i += 1
	content = content[i + 1:]
	reg_xy = re.compile("(\d+.?\d*),(\d+.?\d*)\n")
	i = 0
	xy = re.match(reg_xy, content[i:])
	x = []
	y = []
	while xy is not None:
		i += len(xy.group(0))
		x.insert(0, float(xy.group(1)) / 10000)
		y.insert(0, float(xy.group(2)) / 10000)
		xy = re.match(reg_xy, content[i:])
	return (x, y)

def	calc_tmp_thetas(x, y, tmp_t0, tmp_t1, learn_rate):
	m = 0
	sum_prediction_t0 = tmp_t0
	sum_prediction_t1 = tmp_t1
	for i, j in zip(x, y):
		sum_prediction_t0 += (( tmp_t0 + tmp_t1 * i) - j)
		sum_prediction_t1 += (( tmp_t0 + tmp_t1 * i) - j) * i
		m += 1
	tmp_t0 = learn_rate * (sum_prediction_t0 / m)
	tmp_t1 = learn_rate * (sum_prediction_t1 / m)
	return (tmp_t0, tmp_t1)

def mean(x, y):
	m = 0
	km = 0
	price = 0
	for i, j in zip(x, y):
		print "i : {}".format(i)
		print "j : {}".format(j)
		price += j
		km += i
		m += 1
	print "price : {}".format(price / m)
	print "km : {}".format(km / m)

def	gradient_descent(x, y, tmp_t0, tmp_t1, learn_rate):
	i = 0
	while (i < 1500):
		tmp_t0, tmp_t1 = calc_tmp_thetas(x, y, tmp_t0, tmp_t1, learn_rate)
		i += 1
	return (tmp_t0, tmp_t1)

def	r_correl_coeff(x, y):
	s1 = s2 = s3 = s4 = s5 = n = 0
	for i, j in zip(x, y):
		s1 += i * j
		s2 += i
		s3 += j
		s4 += i ** 2
		s5 += j ** 2
		n += 1
	r_eq_div = math.sqrt(n * s4 - s2 ** 2) * math.sqrt(n * s5 - s3 ** 2)
	r_eq_num = n * s1 - s2 * s3
	r = r_eq_num / r_eq_div
	print "r(correlation coefficient) : {}".format(r)

tmp_t0 = 0
tmp_t1 = 0
learn_rate = -0.00001
x, y = get_xy()
r_correl_coeff(x, y)
t0, t1 = gradient_descent(x, y, tmp_t0, tmp_t1, learn_rate)
print t0
print t1
print (t0 + t1 * 100000)
#mean(x, y)

z = np.linspace(0, 30)
fig, ax = plt.subplots()
ax.plot(z, t0 + t1 * z, 'r-', label="t0 + t1 * mileage")
ax.scatter(x, y)
ax.plot(x, y, 'bo', label="data values")
ax.legend(loc='best')
ax.grid()
ax.set_xlabel('mileage')
ax.set_ylabel('price')
ax.set_title('title')
plt.show()
