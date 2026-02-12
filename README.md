# RSA-Encryption

Simple RSA implementation for my cryptography class.

## What it does

Encrypts and decrypts messages using RSA algorithm. Generates random primes, lets you pick a public key, then encrypts/decrypts a message.

## How to run

```bash
g++ rsa.cpp -o rsa
./rsa
```

Then enter a public key (like 17 or 65537) and a message (lowercase letters only).

## Example

```
Enter a public key: 17
Enter message: hello
p = 151
q = 197
n = 29747
M = 5126359
C = 15234
P = 5126359
Decoded: hello
```

## How it works

- Generates two random primes p and q
- Calculates n = p * q and phi = (p-1)(q-1)
- You give it a public key e
- Calculates private key d
- Encrypts message M to ciphertext C
- Decrypts C back to M

Messages get converted to numbers using base-27 (a=1, b=2, etc).

## Notes

- Only works with short lowercase messages
- Not secure for real use, just for learning
- Prime range is 100-500
