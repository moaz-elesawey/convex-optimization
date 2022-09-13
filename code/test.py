from math import exp, sin, cos, log
from optm import Optimization

def f(x):
    return x**4 - 14*x**3 + 60*x**2 - 70*x

def f(x):
    return 0.5 * x**2 - sin(x)

## Golden Minima
op = Optimization()
op.Minimize(method="Golden", func=f, xmin=0, xmax=3, eps=0.0003, verbose=True)
print(op.GetMinima())


def df(x):
    return 4*(x - 1)**3 * exp(x)

def df(x):
    return x - cos(x)

## Bisection Minima
op = Optimization()
op.Minimize(method="Bisection", dfunc=df, xmin=0, xmax=3, num_iters=10, verbose=True)
print(op.GetMinima())


def ddf(x):
    return 12*(x-1)**2 * exp(x)

def ddf(x):
    return 1 + sin(x)

## Newton Minima
op = Optimization()
op.Minimize(method="Newton", dfunc=df, ddfunc=ddf, x0=0.5, eps=10**-5, verbose=True)
print(op.GetMinima())

def f(x):
    return x**3 - 12.2*x**2 + 7.45*x + 42

def df(x):
    return 3*x**2 - 24.4*x + 7.45

## Secant Minima
op = Optimization()
op.Minimize(method="Secant", dfunc=df, x0=13, x1=12, eps=1, verbose=True)
print(op.GetMinima())

