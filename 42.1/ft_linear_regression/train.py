#!/usr/bin/python
# -*-coding:utf-8 -*
from sys import argv
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
import re

def mean(x, y):
	m = 0
	km = 0
	price = 0
	for i, j in zip(x, y):
		price += j
		km += i * 10000
		m += 1
	print "Average price : {}".format(price / m)
	print "Average mileage : {}".format(km / m)

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
		y.insert(0, float(xy.group(2)))
		xy = re.match(reg_xy, content[i:])
	return (x, y)

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

def	plot_line(x, y, t0, t1):
	z = np.linspace(1.5, 25)
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

def	write_thetas(t0, t1):
	theta_file = open("theta.txt", "w")
	theta_file.write("theta0 = {}\ntheta1 = {}".format(t0, t1))
	theta_file.close()

def	calc_tmp_thetas(x, y, t0, t1, learn_rate):
	tmp0 = 0
	tmp1 = 0
	for i, j in zip(x, y):
		tmp0 += (t0 + t1 * i) - j
		tmp1 += ((t0 + t1 * i) - j) * i
	tmp0 = tmp0 / 24 * learn_rate
	tmp1 = tmp1 / 24 * learn_rate
	t0 -= tmp0
	t1 -= tmp1
	return (t0, t1, tmp0, tmp1)


def	gradient_descent(x, y, tmp_t0, tmp_t1, learn_rate):
	i = 0

	while (i < 5000):
		tmp_t0, tmp_t1, tmp0, tmp1 = calc_tmp_thetas(x, y, tmp_t0, tmp_t1, learn_rate)
		if i % 500 == 0:
			plot_line(x, y, tmp_t0, tmp_t1);
		i += 1
	return (tmp_t0, tmp_t1)

tmp_t0 = 0
tmp_t1 = 0
learn_rate = 0.01
x, y = get_xy()
r_correl_coeff(x, y)
mean(x, y)
t0, t1 = gradient_descent(x, y, tmp_t0, tmp_t1, learn_rate)
t1 = t1 / 10000
write_thetas(t0, t1)
