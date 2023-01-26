#!/usr/bin/python3

class Fibonacci:
    def __init__(self, before_previous, previous):
        try:
            self.previous = int(previous)
            self.before_previous = int(before_previous)
        except ValueError:
            raise ValueError("Previous numbers must be an integers")
            
        try:
            self.number = self.before_previous + self.previous
        except OverflowError:
            raise OverflowErrror("Prior numbers are too large.  Cannot calculate Fibonacci number.")


    def next(self):
        return Fibonacci(before_previous=self.previous, previous=self.number)


class Euler2:
    def solve(self):
        """
        Solves the problem.
        """
        total = 0
        f = Fibonacci(before_previous=1, previous=1)
        
        while f.number < 4000000:
            if (f.number % 2 == 0):
                total += f.number
            f = f.next()
        
        return total


if __name__ == '__main__':
    import locale
    locale.setlocale(locale.LC_ALL, '')
    
    e = Euler2()
    print(f"The sum of all even Fibonacci numbers below {4000000:n} is {e.solve():n}.")
    
