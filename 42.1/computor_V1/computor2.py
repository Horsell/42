#!/usr/bin/python
# -*-coding:utf-8 -*
from sys import argv
import re

def check_valid_eq(arg):
	reg_eq = re.compile('(([-+=]?)\s*([0-9\.]+)?(\s*\*?\s*[xX](?:\s*\^\s*([0-2]+))?)?\s*)*')
	eq = re.match(reg_eq, arg)
	if (eq is None or len(eq.group(0)) < len(arg)):
		print "Invalid equation"
		return (None)
	return (eq)

def extract_right_left(eq):
	for i, elt in enumerate(eq.group()):
		if (elt == '='):
			break
	left_poly = eq.group(0)[0:i]
	right_poly = eq.group(0)[i+1:]
	return (left_poly, right_poly)

def get_coeffs(poly, side):
	a = b = c = 0
	reg_eq = re.compile('\s*([-+=]?)\s*([0-9\.]+)?\s*\*?\s*[xX](?:\s*\^\s*([0-2]+))?\s*')
	eq_part = re.match(reg_eq, poly)
	poly_len = 0
	sign = 1
	while (eq_part.group(0) is not None):
		if (poly_len >= len(poly)):
			break
		eq_part = re.match(reg_eq, poly[poly_len:])
		#print "eq_part : {}".format(eq_part.group(0))
		if (eq_part is not None):
			for i, elt in enumerate(eq_part.groups()):
		#		print "i : {} elt : {}".format(i, elt)
				if (i == 0 and (elt == '-' and side == 0) or (elt == '+' and side == 1)):
					sign = -1
				elif (i == 0):
					sign = 1
				if (i == 1):
					tmp = float(elt) * sign
				if (i == 2 and elt == '0'):
					c += tmp
				if (i == 2 and elt == '1'):
					b += tmp
				if (i == 2 and elt == '2'):
					a += tmp
		poly_len += len(eq_part.group(0))
	return (a, b, c)

def reduce_form(left_poly, right_poly):
	a, b, c = get_coeffs(left_poly, 0)
	a2, b2, c2 = get_coeffs(right_poly, 1)
	a += a2
	b += b2
	c += c2
	if (a > 0)
		a_part = "{} * X^2".format(a)
	if (a < 0)
		a_part = "- {} * X^2".format(-a)
"""	if (a >= 0 and b >= 0 and c >= 0):
		reduced_poly = "{} * X^0 + {} * X^1 + {} * X^2 = 0".format(c, b, a)
	if (a <= 0 and b >= 0 and c >= 0):
		reduced_poly = "{} * X^0 + {} * X^1 - {} * X^2 = 0".format(c, b, -a)
	if (a >= 0 and b <= 0 and c >= 0):
		reduced_poly = "{} * X^0 - {} * X^1 + {} * X^2 = 0".format(c, -b, a)
	if (a >= 0 and b >= 0 and c <= 0):
		reduced_poly = "- {} * X^0 + {} * X^1 + {} * X^2 = 0".format(-c, b, a)
	if (a <= 0 and b <= 0 and c >= 0):
		reduced_poly = "{} * X^0 - {} * X^1 - {} * X^2 = 0".format(c, -b, -a)
	if (a >= 0 and b <= 0 and c <= 0):
		reduced_poly = "- {} * X^0 - {} * X^1 + {} * X^2 = 0".format(-c, -b, a)
	if (a <= 0 and b <= 0 and c <= 0):
		reduced_poly = "- {} * X^0 - {} * X^1 - {} * X^2 = 0".format(-c, -b, -a)"""
	print reduced_poly
	return (a, b, c)

def parse(arg):
	eq = check_valid_eq(arg)
	if (eq is not None):
		left_poly, right_poly = extract_right_left(eq)
		#print left_poly
		#print right_poly
		a, b, c = reduce_form(left_poly, right_poly)
		return (1, a, b, c)
	else:
		return (0, 0, 0, 0)




def solve(a, b, c):
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
	is_ok, a, b, c = parse(arg)
	if is_ok == 1:
		solve(a, b, c)
else:
	print "Wrong number of parameters."
