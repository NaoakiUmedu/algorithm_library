# pypyで実行する
def calc(x: int, y: int, dx: int, dy: int) -> bool:
    """(x, y)を始点として(dx, dy)方向を調べる"""
    count: int = 0
    for i in range(6):
        if not (0 <= min(x, y) and max(x, y) < N):
            # マスからはみ出たらNG
            return False
        if S[x][y] == '#':
            count += 1
        x += dx
        y += dy
    return count >= 4


N: int = int(input())
S: list = [input() for _ in range(N)]

# 動き [横, 縦, ななめ, ななめ]
Dx = [1, 0, 1, 1]
Dy = [0, 1, 1, -1]

# 全てのマスに対して6マスずつ判定を実施しても4 * 6 * 10^6
for x in range(N):
    for y in range(N):
        for dx, dy in zip(Dx, Dy):
            if calc(x, y, dx, dy):
                print("Yes")
                exit()
print("No")
