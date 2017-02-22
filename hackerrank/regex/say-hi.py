import re
n, hr = None, 'hackerrank'
for i in range(int(raw_input())):
	p = re.compile(r'hi\s[^d].*', re.IGNORECASE)
	s = raw_input()
	if p.match(s): print s