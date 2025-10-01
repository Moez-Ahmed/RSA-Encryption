#include <iostream>
#include <string>
#include <cmath>
#include <random>
#include <ctime>
#include <cctype>
using namespace std;


long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

//calculate gcd
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

//Euclidean algorithm
long long modInverse(long long a, long long m) {
    long long m0 = m, x0 = 0, x1 = 1;
    while (a > 1) {
        long long q = a / m;
        long long t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0) {
        x1 += m0;
    }
    return x1;
}
//miller rabin primality
bool isPrime(long long n) {
    if (n < 2) {
        return false;
    }
    if (n % 2 == 0) {
        return n == false;
    }
    long long d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }


    return true;
}
//pick random prime
long long randomPrime() {
    static mt19937 gen(time(0));
    uniform_int_distribution<long long> dist(100, 500); //can be changed
    while (true) {
        long long pickedValue = dist(gen);
        if (isPrime(pickedValue)) {
            return pickedValue;
        }
    }
}
//encode string to base-27 number
long long encode(const string& s) {
    long long val = 0, power = 1;
    for (size_t i = 0; i < s.size(); i++) {
        char c = tolower(s[i]);
        int num = c - 'a' + 1;
        val += num * power;
        power *= 27;
    }
    return val;
}
//return number as a string
string decode(long long x) {
    string returnValue;
    while (x > 0) {
        int rem = x % 27;
        x /= 27;
        if (rem == 0) {
            rem = 1;
        }
        returnValue.push_back(char('a' + rem - 1));
    }
    return returnValue;
}

int main() {

    //pick primes
    long long p = randomPrime();
    long long q = randomPrime();
    while (q == p) {
        q = randomPrime();
    }
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    long long e;
    do {
        cout << "Enter a public key: ";
        cin >> e;
        cout <<endl;
    } while (gcd(e, phi) != 1);

    long long d = modInverse(e, phi);

    string message;
    cout << "Enter message: ";
    cin >> message;

    long long M = encode(message);
    long long C = modExp(M, e, n);
    long long P = modExp(C, d, n);
    string decoded = decode(P);

    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "n = " << n << endl;
    cout << "M = " << M << endl;
    cout << "C = " << C << endl;
    cout << "P = " << P << endl;
    cout << "Decoded: " << decoded << endl;

    return 0;
}
