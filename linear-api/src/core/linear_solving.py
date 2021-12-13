import numpy
from scipy.optimize import linprog


def solve_linear() -> dict:
    obj = [-0.14, -0.13, -0.12, -0.125, -0.1]

    lhs_ineq = [
        [1, 1, 1, 1, 1],
        [0.03, 0, -0.04, -0.02, -0.05],
        [0.4, 0.4, 0.4, -0.6, -0.6],
        [0.5, 0.5, -0.5, 0, 0]
    ]

    rhs_ineq = [
        12000000,
        0,  # Материал A
        0,
        0,
    ]  # Материал B

    opt = linprog(c=obj, A_ub=lhs_ineq, b_ub=rhs_ineq,
                  method="revised simplex")

    _sum = 0
    q = 0
    response = {}
    for i in numpy.ndenumerate(opt['x']):
        x = int(i[1])
        _sum += x
        response[f"x{q + 1}"] = x
        q += 1

    response["sum"] = _sum
    response["F"] = -int(opt['fun'])

    return response


if __name__ == "__main__":
    print(solve_linear())
