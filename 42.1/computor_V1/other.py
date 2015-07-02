#!/usr/bin/python2.7
# -*-coding:utf-8 -*
import sys
import re
import numpy as np

P = sys.argv[1]
InvalidP = re.search("[Xx]\^(\d\.?\d+)|[Xx]\^([3-9])", P)
if InvalidP is not None:
	print("Polynome de degré > à 2 ou non entier : ce programme est incapable de le résoudre...")
P = re.match(" *((\d+.?\d*) *\*? *[Xx]\^(0)|(\d+))*( *([+-]) *(\d+.?\d*) *\*? *[Xx]\^(1))*( *([+-]) *(\d+.?\d*) *\*? *[Xx]\^(2))*", P)

i = 0
sign = 1
coefs = np.array([])
power = np.array([])
while 1:
	try:
		if P.group(i) is not None:
			if i % 4 == 2:
				coefs = np.append(coefs, float(P.group(i)))
				if sign == 0:
					print(yay)
					coefs[i] *= -1
			if i % 4 == 3:
				power = np.append(power, int(P.group(i)))
			if i % 4 == 1 and i > 1 and P.group(i) == '-':
				sign = 0
			else:
				sign = 1
		i += 1
	except:
		break
print("end")
print(coefs)
