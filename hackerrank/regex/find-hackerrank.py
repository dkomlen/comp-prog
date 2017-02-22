import re
n, hr = None, 'hackerrank'
for i in range(int(raw_input())):
	p = re.compile(r'^(%s)?.*?(%s)?$' % (hr, hr))
	s = raw_input()
	m = p.match(s).groups() if s != hr else (hr,hr)	
	print {(n,n):-1, (hr,n):1, (n,hr):2, (hr,hr):0}[m]