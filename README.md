# Small Prime And Semiprime Dataset

This repository contains three command-line programs designed for generating and working with prime and semiprime numbers. The primary goal of this project was to practice **C** language and create a tool for participating in CTF's challenges that involve number theory and cryptography.

## Programs

1. **Prime Number Generator**
   - Command structure: `./prime-number-generator {1-32} {output_file}`
   - Description: Generates prime numbers up to the specified bit limit (1-32) and saves them to a binary file of your choice.

2. **Semiprime Number Generator**
   - Command structure: `./semiprime-number-generator {input_file} {output_file}`
   - Description: Takes a binary file containing prime numbers as input and generates semiprime numbers, saving them to a binary file of your choice.

3. **Find by Semiprime**
   - Command structure: `./find-by-semiprime {input_file} {semiprime_value}`
   - Description: Searches for the components of the specified semiprime (e.g. 314) in the provided binary file.

## Compilation

To compile all programs, run the following command:

```bash
bash compile-all-programs.sh
```

## Example Workflow

1. Run the prime number generator to create a binary file with prime numbers:
```bash
./prime-number-generator 1-10 my_primes.bin
```
2. Use the semiprime number generator to create a binary file with semiprimes:
```bash
./semiprime-number-generator my_primes.bin my_semiprimes.bin
```
3. Finally, utilize the find by semiprime program to search for components of a specific semiprime:
```bash
./find-by-semiprime my_semiprimes.bin 485
```

## Warning

Be aware that generating large ranges of prime numbers can result in long processing times and significant memory allocation in RAM. It is advisable to start with smaller ranges to understand the performance implications before scaling up.
