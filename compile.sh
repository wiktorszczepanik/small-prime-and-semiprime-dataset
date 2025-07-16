#!/bin/bash
gcc -o prime-number-generator \
    prime_number_generator.c \
    algorithms/generation_of_primes.c \
    setup/set_generation_of_primes.c \
	save/save_generation_of_primes.c \
    -I algorithms -I setup -I save -lm

if [ $? -eq 0 ]; then
	echo "Compilation success!"
fi
