from math import *
from fractions import *
def solve():
	s1 = raw_input()
	s2 = raw_input()[::-1]
	t1 = raw_input()
	t2 = raw_input()[::-1]
	
	x1 = s1 + s2
	y1 = t1 + t2
	
	x = ""
	y = ""
	for c in x1:
		if c != 'X': x += c
	for c in y1:
		if c != 'X': y += c
	
	if x in y+y or y in x+x:
		print "YES"
	else:
		print "NO"
	
	return

solve()
