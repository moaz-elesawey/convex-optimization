from optm import methods


def f(x):
    return x**4 - 14*x**3 + 60*x**2 - 70*x

def df(x):
    return 4*x**3 - 14*3*x**2 + 120*x - 70

def ddf(x):
    return 12*x**2 - 14*6*x + 120


# Golden
op = methods.Golden(f)
minima = op.Minimize(0, 2, 0.003)
op.PrintOptimizationSteps()
op.ExportOptimizationSteps(0, 3, "Golden_OptimizedFunction")

# BiSection
op = methods.BiSection(f, df)
minima = op.Minimize(0, 2, 10)
op.PrintOptimizationSteps()
op.ExportOptimizationSteps(0, 3, "BiSection_OptimizedFunction")

# Newton
op = methods.Newton(f, df, ddf)
minima = op.Minimize(0, 0.0003)
op.PrintOptimizationSteps()
op.ExportOptimizationSteps(0, 3, "Newton_OptimizedFunction")

# Secant
op = methods.Secant(f, df)
minima = op.Minimize(0, 0.1, 0.0003)
op.PrintOptimizationSteps()
op.ExportOptimizationSteps(0, 3, "Secant_OptimizedFunction")

