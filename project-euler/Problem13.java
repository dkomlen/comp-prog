package peuler;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class BigNumber {
	String num;

	public int len(){
		return num.length();
	}

	public BigNumber (String num) {
		this.num = num;
	}

	private int getDigit(int pos) {
		pos = len() - pos;
		if (pos < 0) return 0;
		return Integer.parseInt("" + num.charAt(pos));
	}

	private void setDigit(int pos, int a){
		pos = len()-pos;

		if (pos < 0){
			num = "" + a + num.substring(0);
		}
		else if (pos >= len()) {
			num = num.substring(0,len()-1) + a;
		}
		else {
			num = num.substring(0,pos) + a + num.substring(pos+1);
		}
	}

	private void addDigit (int pos, int b) {
		int a = getDigit(pos) + b;
		if (a >= 10) {
			int c = a / 10;
			a %= 10;
			addDigit(pos+1, c);
		}
		setDigit(pos, a);
	}

	public void add(BigNumber bn){

		for (int i = 1; i <= bn.len(); ++i){
			addDigit(i, bn.getDigit(i));
		}

	}
	@Override
	public String toString() {
		return num;
	}
}

public class Problem13 {

	public static void main(String[] args) {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;

		try {
			BigNumber result = new BigNumber(br.readLine());
			while ((line = br.readLine()) != "stop"){

				result.add(new BigNumber(line));
				System.out.println("= " + result);
			}

		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
