#include<iostream>
using namespace std;
void Primeoff(bool flags[], int prime) {
	for (int i = prime * prime; i <= 999; i += prime)
		flags[i] = false;
}
int getNextprime(bool flags[], int prime) {
	prime += 1;
	while (!flags[prime]) prime++;
	return prime;
}
int main(void) {
	bool flags[1000];
	memset(flags, true, sizeof(flags));
	int prime = 2;
	while (prime <= 999) {
		Primeoff(flags, prime);
		prime = getNextprime(flags, prime);
	}
	for (int i = 2; i <= 999; i++)
		if (flags[i]) cout << i << "  ";
	return 0;
}