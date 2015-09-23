#!/usr/bin/python
# -*-coding:utf-8 -*
from sys import argv
import re

a = 0
b = 0
c = 0

def parse(arg):
	reg_poly = re.compile('([-+=]?)\s*([0-9\.]+)?(\s*\*?\s*[xX](?:\s*\^\s*([0-9]+))?)?\s*')
	reg_eq = re.compile('\s+=\s+')
	reg_sp = re.compile('\s*')
	reg_num = re.compile('[0-9]*')
	reg_pow = re.compile('[0-2]+')
	reg_a = re. compile('\d*\s*\*?\s*[xX]\^2')
	reg_b = re. compile('(\d*\s*\*?\s*[xX]\s*[+-=]|\d*\s*\*?\s*[xX](\^1)\s*[+-=]|\d*\s*[xX]$)')
	reg_c = re. compile('(\d*\s*[+-=]|\d*\s*[xX]\^0\s*[+-=]|\d*\s*\*\s*[xX]\^0\s*[+-=]|\d*\s*$)')
	eq_part = re.match(reg_poly, arg)

	global a, b, c
	tmp = 0
	num = 0
	j = 0
	side = 0
	while j < len(arg) -1:
		last_elt = None
		for i, elt in enumerate(eq_part.group()):
#			print "indice :  {} , élément : {}".format(i, elt)
			if elt.isdigit() and (last_elt is None or last_elt.isdigit() is False) and last_elt != 'x' and last_elt != 'X':
				nb = re.match(reg_num, arg[j + i:])
				tmp = float(nb.group(0))
			if elt.isdigit() and last_elt == '-':
				tmp *= -1
			if side == 1 and elt.isdigit() and last_elt != 'x' and last_elt != 'X':
				tmp *= -1
			if elt.isdigit() and (last_elt is None or last_elt.isdigit() is False) and last_elt != 'x' and last_elt != 'X':
				if (re.match(reg_a, arg[j + i:])) is not None:
					a += tmp
				elif (re.match(reg_b, arg[j + i:])) is not None:
					b += tmp
				elif (re.match(reg_c, arg[j + i:])) is not None:
					c += tmp
			if elt.isdigit() and (last_elt == 'X' or last_elt == 'x'):
				num = re.match(reg_pow, arg[j + i:])
				if num is None or len(num.group(0)) > 1:
					print("\033[31mThe polynomial degree is stricly greater than 2, I can't solve.\033[39m")
					return 0
			if elt.isdigit() or elt == '-' or elt == 'x' or elt == 'X' or elt == '+':
				last_elt = elt
		j += i
		eq = re.match(reg_eq, arg[j:])
		if eq is not None:
			j += len(eq.group(0))
			side = 1
		sp = re.match(reg_sp, arg[j:])
		if sp is not None:
			j += len(sp.group(0))
		eq_part = re.match(reg_poly, arg[j:])
	if a == 0 and b == 0:
		print "\033[90mReduced form : {} = 0.0\033[39m".format(c)
		print "\033[32mEvery real are solution\033[39m"
		return 0
	if b < 0 and a < 0:
		print "\033[90mReduced form : {} - {} * X - {} * X^2 = 0\033[39m".format(c, -b, -a)
	elif a < 0:
		print "\033[90mReduced form : {} + {} * X - {} * X^2 = 0\033[39m".format(c, b, -a)
	elif b < 0:
		print "\033[90mReduced form : {} - {} * X + {} * X^2 = 0\033[39m".format(c, -b, a)
	else:
		print "\033[90mReduced form : {} + {} * X + {} * X^2 = 0\033[39m".format(c, b, a)
	if a == 0 and b != 0:
		print "\033[90mPolynomial degree: 1\033[39m"
	if a != 0:
		print "\033[90mPolynomial degree: 2\033[39m"

def solve():
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
	parse(arg)
	solve()
else:
	print "Wrong number of parameters."
