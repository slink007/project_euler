#!/usr/bin/python3

class Euler1:
    def __init__(self, limit=None):
        if limit is None:
            self.limit = 1000
        else:
            try:
                self.limit = int(limit)
                assert self.limit > 2
            except (TypeError, AssertionError):
                raise ValueError("Invalid limit value")
	
    def solve(self):
        """
        Solves the problem.

        The 'or' is critical to this approach to the solution.  Going through
        once to find all multiples of 3, and then a second time for all
        multiples of 5, would lead to double counting numbers which are 
        multiples of both (15 for example).
        """
        multiples = [n for n in range(3, self.limit) if ( (n % 3 == 0) or 
            (n % 5 == 0) )]
        return sum(multiples)


if __name__ == '__main__':
    import getopt
    import sys
    
    limit = 1000
        
    opts, args = getopt.getopt(sys.argv[1:], "l:")
    for opt, arg in opts:
        if opt in ['-l']:         # set a different limit
            limit = arg

    e = Euler1(limit)
    print(f"\nThe sum of all the multiples of 3 or 5 below {limit}" +
        f" is {e.solve()}.\n")
