# https: // pheromone.hatenablog.com/entry/2016/01/31/175131
# 2乗になってたら展開してみましょうね
# cppでかいたらどこかでバグった。多分オーバーフローしたっぽい

def solve(N, X):

    total = 0
    sum_x = sum_x2 = 0
    for i in range(N):
        total += i * X[i] ** 2 - 2 * X[i] * sum_x + sum_x2

        sum_x += X[i]
        sum_x2 += X[i] ** 2
    return int(total)


N = int(input())
X = input().split()
iX = []
for i in X:
    iX.append(int(i))
print(solve(N, iX))
