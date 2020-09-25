#!/usr/bin/python3

import getopt
import sys


def main():
    """Project Euler Problem 1:
    
    If we list all the natural numbers below 10 that are multiples of 3 or
    5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
        
    Find the sum of all the multiples of 3 or 5 below 1000.
    """

    limit = 1000  # The limit that all multiples must be less than

    try:
        opts, args = getopt.getopt(sys.argv[1:], "hl:")
    except:
        print("Unrecognized argument")
        exit()

    for opt, arg in opts:
        if opt in ['-h']:         # tell the user what the program does
            print(main.__doc__)
            print("Usage:\n    euler1.py\n    euler1.py -h\n    euler1.py -l <limit>")
            exit()
        if opt in ['-l']:         # set a different limit
            limit = int(arg)

    multiples = [n for n in range(3, limit) if ( (n % 3 == 0) or (n % 5 == 0) )]
    print("The sum of all the multiples of 3 or 5 below {} is {}".format(limit, sum(multiples)))


if __name__ == '__main__':
    main()
