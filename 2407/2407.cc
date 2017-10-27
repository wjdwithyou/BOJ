#include <iostream>
#include <cstring>

class BigInt {
private:
	char num[128];
	int len;
    
public:
	BigInt();
	BigInt(int);
	~BigInt();
    
	BigInt operator+(const BigInt&) const;
	BigInt& operator=(const BigInt&);
    
	const char* getNum(void) const { return this->num; }
};

BigInt comp[128][128];

int main(void) {
	int n, m;
    
	scanf("%d %d", &n, &m);
    
	for (int i = 1; i <= n; ++i) {
		comp[i][0] = comp[i][i] = 1;
	}
    
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			comp[i][j] = comp[i - 1][j - 1] + comp[i - 1][j];
		}
	}
    
	return !printf("%s", comp[n][m].getNum());
}

BigInt::BigInt() {}

BigInt::BigInt(int num) {
	sprintf(this->num, "%d", num);
	this->len = strlen(this->num);
}

BigInt::~BigInt() {}

BigInt BigInt::operator+(const BigInt &ref) const {
	BigInt result;
	int adx = strlen(this->num) - 1;
	int bdx = strlen(ref.num) - 1;
	int rdx = (adx > bdx) ? adx : bdx;
	int carry = 0;
	int t;
    
	result.len = rdx + 1;
	result.num[result.len] = '\0';
    
	for (; adx >= 0 && bdx >= 0; --rdx) {
		t = (this->num[adx--] - '0') + (ref.num[bdx--] - '0') + carry;
        
		if (t > 9) {
			result.num[rdx] = t - 10 + '0';
			carry = 1;
		}
		else {
			result.num[rdx] = t + '0';
			carry = 0;
		}
	}
	for (; adx >= 0; --rdx) {
		t = (this->num[adx--] - '0') + carry;
        
		if (t > 9) {
			result.num[rdx] = t - 10 + '0';
			carry = 1;
		}
		else {
			result.num[rdx] = t + '0';
			carry = 0;
		}
	}
	for (; bdx >= 0; --rdx) {
		t = (ref.num[bdx--] - '0') + carry;
        
		if (t > 9) {
			result.num[rdx] = t - 10 + '0';
			carry = 1;
		}
		else {
			result.num[rdx] = t + '0';
			carry = 0;
		}
	}
    
	if (carry) {
		result.num[++result.len] = '\0';
        
		for (int i = result.len - 1; i > 0; --i) {
			result.num[i] = result.num[i - 1];
		}
        
		result.num[0] = '1';
	}
    
	return result;
}

BigInt& BigInt::operator=(const BigInt &ref) {
	strcpy(this->num, ref.num);
	this->len = ref.len;
    
	return *this;
}