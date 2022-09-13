from math import sqrt, log, ceil


class CONST:
    RO = 0.3819660112501051


class METHOD:
    GOLDEN    = "Golden"
    BISECTION = "Bisection"
    NEWTON    = "Newton"
    SECANT    = "Secant"


class Optimization:
    def __init__(self):
        self._minima = None

    def _Golden_Method(self, func, xmin, xmax, eps, verbose=False):
        """
        this method is an impl of the Golden Section Search Optimization Method.

        Parameters
        ----------
         - func (function) : the function we want to minimize writen as
           pure python function with one input and one output.
         - xmin (float) : the minimum value of the domain of the function
         - xmax (float) : the maximum value of the domain of the function
         - eps  (float) : (epsilon) is the range we want to locate our minuma.

        Returns
        -------
         - minima (tuple) : the local minumum the algo find for the function (func)

        Attrs
        -----
         - _optim_steps (list) : list of the optimization steps the algo takes
        """
        
        ## N is the number of iterations calculated using the eps
        N = ceil( log(eps / 2.0) / log(1 - CONST.RO) )
        if verbose:
            print("Number of Iterations = {}".format(N))

        ## begining of the algo
        for i in range(N):
            a1 = xmin + CONST.RO * (xmax - xmin)
            b1 = xmax - CONST.RO * (xmax - xmin)

            ## update the splitting points
            if func(b1) > func(a1): xmax = b1
            else:                   xmin = a1

        return (xmin, xmax)

    def _Bisection_Method(self, dfunc, xmin, xmax, num_iters=10, verbose=False):
        """
        this method is an impl of the Bisection Optimization Method.

        Parameters
        ----------
         - dfunc (function) : the first derivative function we want to minimize
             writen as pure python function with one input and one output.
         - xmin (float) : the minimum value of the domain of the function
         - xmax (float) : the maximum value of the domain of the function
         - num_iters (int) : the number of iterations we want to run the algo for.

        Returns
        -------
         - minima (float) : the local minumum the algo find for the function (func)

        Attrs
        -----
         - _optim_steps (list) : list of the optimization steps the algo takes
        """

        for k in range(num_iters):
            ## c is the center point between xmin and xmax
            c = (xmin + xmax) / 2.0

            if dfunc(c) > 0: xmax = c
            else:            xmin = c

        return (xmin + xmax) / 2.0

    def _Newton_Method(self, dfunc, ddfunc, x0, eps, verbose=False):
        """
        this method is an impl of the Newton Optimization Method.

        Parameters
        ----------
         - dfunc (function) : the first derivative function we want to minimize
             writen as pure python function with one input and one output.
         - ddfunc (function) : the second derivative function we want to minimize
             writen as pure python function with one input and one output.
         - x0 (float) : the initial point we want to start with
         - eps (float) : the residul to compare to with calculated value.

        Returns
        -------
         - minima (float) : the local minumum the algo find for the function (func)

        Attrs
        -----
         - _optim_steps (list) : list of the optimization steps the algo takes
        """

        xk = x0
        while True:
            xk = x0 - ( dfunc(x0) / ddfunc(x0) )
            if (xk - x0) < eps: break
            x0 = xk

        return xk

    def _Secant_Method(self, dfunc, x0, x1, eps, verbose=False):
        """
        this method is an impl of the Secant Optimization Method.

        Parameters
        ----------
         - dfunc (function) : the first derivative function we want to minimize
             writen as pure python function with one input and one output.
         - x0 (float) : the initial point we want to start with
         - x1 (float) : the second initial point we want to start with
         - eps (float) : the residul to compare to with calculated value.

        Returns
        -------
         - minima (float) : the local minumum the algo find for the function (func)

        Attrs
        -----
         - _optim_steps (list) : list of the optimization steps the algo takes
        """

        while True:
            xk = ((dfunc(x1)*x0 - dfunc(x0)*x1) / (dfunc(x1) - dfunc(x0)))
            if (xk - x1) < eps: break
            x1 = xk
            x0 = x1
        
        return xk

    def Minimize(self, method="Newton", verbose=False, **kw):
        """
        The function used to call the backed impl of the algorithms
        called by (method) keyword

        Parameters
        ----------
         - method (str)   : the type of algorithm will be used
         - verbose (bool) : to whether to print information or not

        Returns
        -------
         - None

        Raises
        ------
         - err (ValueError) : if the passed wrong type of methods

        """

        if   method == METHOD.GOLDEN:
            self._minima = self._Golden_Method(func=kw["func"], xmin=kw["xmin"], 
                    xmax=kw["xmax"], eps=kw["eps"], verbose=verbose)

        elif method == METHOD.BISECTION:
            self._minima = self._Bisection_Method(dfunc=kw["dfunc"], xmin=kw["xmin"],
                    xmax=kw["xmax"], num_iters=kw["num_iters"], verbose=verbose)

        elif method == METHOD.NEWTON:
            self._minima = self._Newton_Method(dfunc=kw["dfunc"], ddfunc=kw["ddfunc"], 
                    x0=kw["x0"], eps=kw["eps"], verbose=verbose)

        elif method == METHOD.SECANT:
            self._minima = self._Secant_Method(dfunc=kw["dfunc"], x0=kw["x0"],
                    x1=kw["x1"], eps=kw["eps"], verbose=verbose)

        else:
            raise ValueError("method with value {} does not exists yet".format(method))

    def GetMinima(self):
        """
        return the minumum value if it already calculated

        Raises
        ------
         - err (ValueError) : if the we does not optimize.
        """

        if self._minima is not None:
            return self._minima
        else:
            raise ValueError("function does not minimized yet.")

    def PlotOptimizationSteps(self):
        pass

    def PrintOptimizationSteps(self):
        pass


