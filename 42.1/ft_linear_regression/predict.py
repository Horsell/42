#!/usr/bin/python
# -*-coding:utf-8 -*
from sys import argv
import matplotlib.pyplot as plt
import re
import numpy as np

def	get_theta_values():
	trained_file = open("theta.txt")
	contenu = trained_file.read()
	trained_file.close()
	reg_theta = re.compile("theta[0-1]\s*=\s*(-?\d*.?\d*)")
	theta_values = re.match(reg_theta, contenu)
	if theta_values is not None:
		theta0 = float(theta_values.group(1))
		theta_values = re.match(reg_theta, contenu[len(theta_values.group(0)) + 1:])
		if theta_values.group(1) is not None:
			theta1 = float(theta_values.group(1))
		else:
			print "Invalid file for theta values (from train.py)"
			return (0, 0)
	else:
		print "Invalid file for 444 theta values (from train.py)"
		return (0, 0)
	return (theta0, theta1)

def parse_arg(argv):
		return float(argv[1])

def	compute_price(theta0, theta1, mileage):
	return (theta0 + theta1 * mileage)

def predict(argv):
	mileage = input("Enter a mileage for which you want to predict the price of a car : \n")
	mileage = float(mileage)
	theta0, theta1 = get_theta_values()
	if (mileage < 0):
		print "Error : mileage must be positive"
	else:
		estimated_price = compute_price(theta0, theta1, mileage)
		print estimated_price

predict(argv)
