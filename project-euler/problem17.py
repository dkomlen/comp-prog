one1 = ["one","two","three","four","five","six","seven","eight","nine"];
ten1 = ["ten","eleven","twelve","thirteen", "fourteen", "fifteen" , "sixteen", "nineteen", "seventeen", "eighteen"];
ten2 = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"];


def hundred(x): return one(x/100)+"hundred" + (("end" + ten(x%100)) if x%100 > 0 else "");
def ten(x):
	if (x == 0): return 0;
	elif (x < 10): return one(x);
	elif (x < 20): return ten1[x-10];
	else: return ten2[(x/10)-2] + one(x%10);

def one(x): 
	if (x == 0): return "";
	return one1[x-1];

def count(x):
	print 1;

if __name__ == "__main__":
	sol = 0;
	for i in range(1,1000):
		if (i < 100): x = (ten(i));
		else: x = (hundred(i));
		sol += len(x);
		#sol += count(i);
	
	print sol + len("onethousand");