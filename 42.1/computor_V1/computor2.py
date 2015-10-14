#!/usr/bin/python
# -*-coding:utf-8 -*
from sys import argv
import re

def check_valid_poly(arg)

def extract_right_poly(poly)
	return (right_poly)

def extract_left_poly(poly)
	return (left_poly)

def extract_eq_part(poly)
	return (eq_part)

def reduce_form(poly_parts)
	return (reduced_poly)

def parse(arg):
	poly = check_valid_poly(arg)
	right_poly = extract_right_poly(poly)
	left_poly = extract_left_poly(poly)
	for elt in right_poly:
		poly_parts += extract_eq_part(right_poly)
	for elt in right_poly:
		poly_parts += extract_eq_part(left_poly)
	reduce_form(poly_parts)


	return (a, b, c)




def solve():
	if a == 0 and b != 0:
		x = -c / b
		print "\033[90mx = {}\033[39m ".format(x)
		return
	delta = b ** 2 - (4 * a * c)
	if delta > 0:
		x1 = (-b - abs(delta) ** 0.5) / (2 * a)
		x2 = (-b + abs(delta) ** 0.5) / (2 * a)
		print("\033[90mDiscriminant is strictly positive, the two solutions are:")
		print "x1 = {}".format(x1)
		print "x2 = {}\033[39m ".format(x2)
	if delta == 0:
		x = (-b) / (2 * a)
		print("\033[90mDiscriminant is 0, the solution is:")
		print "x = {}\033[39m ".format(x)
	if delta < 0:
		x1r = -b / (2 * a)
		x1c = -(abs(delta) ** 0.5) / (2 * a)
		x2r = -b / (2 * a)
		x2c = -(abs(delta) ** 0.5) / (2 * a)
		print("\033[90mDiscriminant is strictly negative, the two solutions are:")
		print "x1 = {} - i * {}".format(x1r, x1c)
		print "x2 = {} + i * {}\033[39m ".format(x2r, x2c)

if (len(argv) == 2):
	arg = argv[1]
	if parse(arg) == 1:
		solve()
else:
	print "Wrong number of parameters."
