#!/bin/bash

printf "\nTesting value: 0\n"
./convert '0'

printf "\nTesting value: 21\n"
./convert '21'

printf "\nTesting value: -50\n"
./convert '-50'

printf "\nTesting value: 32\n"
./convert '32'

printf "\nTesting value: 'a'\n"
./convert 'a'

printf "\nTesting value: '*'\n"
./convert '*'

printf "\nTesting value: 'T'\n"
./convert 'T'

printf "\nTesting value: ' '\n"
./convert ' '

printf "\nTesting value: '345'\n"
./convert '345'

printf "\nTesting value: 'abcd'\n"
./convert 'abcd'

printf "\nTesting value: '58.0'\n"
./convert '58.0'

printf "\nTesting value: '42.4545f'\n"
./convert '42.4545f'

printf "\nTesting value: '+42.0004'\n"
./convert '+42.0004'

printf "\nTesting value: '2147483648'\n"
./convert '2147483648'

printf "\nTesting value: '-2147483646'\n"
./convert '-2147483646'

printf "\nTesting value: 'nan'\n"
./convert 'nan'

printf "\nTesting value: '-inf'\n"
./convert '-inf'

printf "\nTesting value: '+inff'\n"
./convert '+inff'
