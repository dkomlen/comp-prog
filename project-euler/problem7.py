from math import *
def primes(n):
	primes = []
	for i in range(2,n+1):
		isp = True
		a = ceil(sqrt(i));
		for p in primes:
			if p >= a+1: break
			if i % p == 0:
				isp = False
				break
		if isp: primes.append(i)
	return primes

def firstNPrimes(n):
	primes = []
	i = 1
	while len (primes) < n:
		i += 1
		isp = True
		a = ceil(sqrt(i));
		for p in primes:
			if p >= a+1: break
			if i % p == 0:
				isp = False
				break
		if isp: primes.append(i)
	return primes

print sum(primes(2000000))

