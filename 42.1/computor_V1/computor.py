#!/usr/bin/python2.7
""" Computor_V1"""
import re
import sys
import math
import cmath
# p = re.compile('(\d+) \* X\^([012]) ([+-]) (\d+) \* X\^([012]) ([+-]) (\d+) \* X\^([012])')

if len(sys.argv) == 2:
	poly = sys.argv[1]
	poly = re.match("((\d+) \* X\^(0))*( ([+-]) (\d+) \* X\^(1))*( ([+-]) (\d+) \* X\^(2))*", poly)
	test = re.search("((\d+) \* X\^([012]))", poly)
	print(test)
	print("end of test")
	if poly is not None:
#		print(poly)
#		print(poly.groupdict().iterkeys())
		i = 0
		while poly.group(i) is not None:
			print(poly.group(i))
			i += 1
		a = float(poly.group(2))
		b = float(poly.group(6))
		if poly.group(8) is None:
			print("X^2 missing")
		else:
			c = float(poly.group(10))
			delta = (b * b) - 4 * a * c
			if delta >= 0:
				x1 = (-b - math.sqrt(delta)) / 2 * a
				x2 = (-b + math.sqrt(delta)) / 2 * a
			else:
				x1 = (-b - cmath.sqrt(delta)) / 2 * a
				x2 = (-b + cmath.sqrt(delta)) / 2 * a
			print(x1)
			print(x2)
	else:
		print("Syntax error")
else:
	print("Wrong number of arguments, try : ./computor.py \"Polynomial equation\"")
