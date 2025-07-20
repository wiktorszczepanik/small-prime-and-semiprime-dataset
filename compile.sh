#!/bin/bash

# ./prime-number-generator { 1-32 } { primes.bin }
gcc -o prime-number-generator \
    prime_number_generator.c \
    algorithms/generation_of_primes.c \
    setup/set_generation_of_primes.c \
	save/save_generation_of_primes.c \
    -I algorithms -I setup -I save -lm

if [ $? -eq 0 ]; then
	echo "Prime number generator -> Compilation success!"
fi

# ./semiprime-number-generator { primes.bin } { semiprimes.bin }
gcc -o semiprime-number-generator \
    semiprime_number_generator.c \
    setup/set_generation_of_semiprimes.c \
	save/save_generation_of_semiprimes.c \
    -I setup -I save -lm

if [ $? -eq 0 ]; then
	echo "Semiprime number generator -> Compilation success!"
fi
