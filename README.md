# cs50-2-substitution - Summary
This is a command line application developed in C# that implements a substitution cipher to encrypt a provided text. This is an exercise of Harvard's CS50 online course.

# Table of contents
1. [Substitution](#Substitution)
2. [Background](#Background)
3. [Specification](#Specification)

# Substitution
This program implements a substitution cipher, per the below.
```
$ ./substitution JTREKYAVOGDXPSNCUIZLFBMWHQ
plaintext:  HELLO
ciphertext: VKXXN
```

# Background
In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).

A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. This 26-character key means that A (the first letter of the alphabet) should be converted into N (the first character of the key), B (the second letter of the alphabet) should be converted into Q (the second character of the key), and so forth.

A message like HELLO, then, would be encrypted as FOLLE, replacing each of the letters according to the mapping determined by the key.

This program called substitution enables you to encrypt messages using a substitution cipher. At the time the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message they’ll provide at runtime.

Here are a few examples of how the program might work. For example, if the user inputs a key of YTNSHKVEFXRBAUQZCLWDMIPGJO and a plaintext of HELLO:
```
$ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
plaintext:  HELLO
ciphertext: EHBBQ
```
Here’s how the program might work if the user provides a key of VCHPRZGJNTLSKFBDQWAXEUYMOI and a plaintext of hello, world:
```
$ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
plaintext:  hello, world
ciphertext: jrssb, ybwsp
```
Notice that neither the comma nor the space were substituted by the cipher. Only alphabetical characters are substituted. Notice, too, that the case of the original message has been preserved. Lowercase letters remain lowercase, and uppercase letters remain uppercase.

Whether the characters in the key itself are uppercase or lowercase doesn’t matter. A key of VCHPRZGJNTLSKFBDQWAXEUYMOI is functionally identical to a key of vchprzgjntlskfbdqwaxeuymoi (as is, for that matter, VcHpRzGjNtLsKfBdQwAxEuYmOi).

And what if a user doesn’t provide a valid key?
```
$ ./substitution ABC
Key must contain 26 characters.
```
Or really doesn’t cooperate?
```
$ ./substitution
Usage: ./substitution key
```
Or even…
```
$ ./substitution 1 2 3
Usage: ./substitution key
```

# Specification
Designed and implemented a program, substitution, that encrypts messages using a substitution cipher, according to the following.

* The program accepts a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase does not affect the behavior of the program.
* If the program is executed without any command-line arguments or with more than one command-line argument, the program prints an error message (with printf) and returns from main a value of 1 immediately.
* If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), the program prints an error message (with printf) and returns from main a value of 1 immediately.
* The program outputs plaintext: (without a newline) and then prompts the user for a string of plaintext (using get_string).
* The program outputs ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters are outputted unchanged.
* The program preserves case: capitalized letters remain capitalized letters; lowercase letters remain lowercase letters.
* After outputting ciphertext, it prints a newline. The program then exits by returning 0 from main.
