import random
from time import time


def mult1(matrix_1, matrix_2, result, n):
    for i in range(n):
        for j in range(n):
            for k in range(n):
                result[i][j] += matrix_1[i][k] * matrix_2[k][j]
    return result


def mult2(matrix_1, matrix_2, result, n):
    for i in range(n):
        for k in range(n):
            for j in range(n):
                result[i][j] += matrix_1[i][k] * matrix_2[k][j]
    return result


def mult3(matrix_1, matrix_2, result, n):
    for j in range(n):
        for i in range(n):
            for k in range(n):
                result[i][j] += matrix_1[i][k] * matrix_2[k][j]
    return result


def mult4(matrix_1, matrix_2, result, n):
    for j in range(n):
        for k in range(n):
            for i in range(n):
                result[i][j] += matrix_1[i][k] * matrix_2[k][j]
    return result


def mult5(matrix_1, matrix_2, result, n):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                result[i][j] += matrix_1[i][k] * matrix_2[k][j]
    return result


def mult6(matrix_1, matrix_2, result, n):
    for k in range(n):
        for j in range(n):
            for i in range(n):
                result[i][j] += matrix_1[i][k] * matrix_2[k][j]
    return result


def flush_result(n):
    res = []
    for i in range(n):
        res.append([])
        for j in range(n):
            res[i].append(0)
    return res


def timeit(func, A, B, result, n):
    res = 0
    for _ in range(50):
        start = time()
        func(A, B, result, n)
        end = time()
        res += end - start
    return res

n = 100
result = flush_result(n)

A = []
B = []
for i in range(n):
    A.append([])
    B.append([])
    for j in range(n):
        A[i].append(random.randint(0, 1000))
        B[i].append(random.randint(0, 1000))


res = timeit(mult1, A, B, result, n)
print(f"ijk: {res}")

result = flush_result(n)

res = timeit(mult2, A, B, result, n)
print(f"ikj: {res}")

result = flush_result(n)

res = timeit(mult3, A, B, result, n)
print(f"jik: {res}")

result = flush_result(n)

res = timeit(mult4, A, B, result, n)
print(f"jki: {res}")

result = flush_result(n)

res = timeit(mult5, A, B, result, n)
print(f"kij: {res}")

result = flush_result(n)

res = timeit(mult6, A, B, result, n)
print(f"kji: {res}")


# ijk: 3.876579761505127
# ikj: 3.8491625785827637
# jik: 3.795686721801758
# jki: 4.026663780212402
# kij: 3.758127450942993
# kji: 3.936894416809082