#!/usr/bin/python
# -*-coding:utf-8 -*
from sys import argv
import matplotlib.pyplot as plt
import re
import numpy as np

def	get_theta_values():
	trained_file = open("theta.txt")
	contenu = trained_file.read()
	reg_theta = re.compile("theta[0-1]\s*=\s*(\d*.?\d*)")
	theta_values = re.match(reg_theta, contenu)
	if theta_values.group(1) is not None:
		theta0 = float(theta_values.group(1))
		theta_values = re.match(reg_theta, contenu[len(theta_values.group(0)) + 1:])
		if theta_values.group(1) is not None:
			theta1 = float(theta_values.group(1))
		else:
			print "Invalid file for theta values (from train.py)"
	else:
		print "Invalid file for theta values (from train.py)"
	return (theta0, theta1)

def parse_arg(argv):
	if len(argv) == 1:
		return -1
	if len(argv) == 2:
		print argv[1]
		return float(argv[1])

def	compute_price(theta0, theta1, mileage):
	return (theta0 + theta1 * mileage)

def predict(argv):
	theta0, theta1 = get_theta_values()
	#print theta0
	#print theta1
	mileage = parse_arg(argv)
	if (mileage < 0):
		print "error"
	else:
#		mileage = parse_arg(argv)
		estimated_price = compute_price(theta0, theta1, mileage)
		print estimated_price

predict(argv)
