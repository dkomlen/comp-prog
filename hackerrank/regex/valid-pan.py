import re
n, hr = None, 'hackerrank'
for i in range(int(raw_input())):
	p = re.compile(r'^[A-Z]{5}\d{4}[A-Z]$')
	s = raw_input()
	print 'YES' if p.match(s) else 'NO'