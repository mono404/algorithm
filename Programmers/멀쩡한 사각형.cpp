#include <iostream>

using namespace std;

int gcd(int a, int b)
{ 
	int mod = a % b; 
	
	while (mod > 0)
	{
		a = b;
		b = mod;
		mod = a % b; 
	} 
	return b;
}

long long solution(int w, int h) {
	long long answer = 1;
	long long W = w;
	long long H = h;

	answer = (W * H) - ((W + H) - gcd(W, H));

	return answer;
}

int main(void)
{
	cout << solution(8, 12) << endl;
}