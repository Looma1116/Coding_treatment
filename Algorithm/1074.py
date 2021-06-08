z = [[0 for i in range(2)]for j in range(2)]
z[0][1] = 1
z[1][0] = 2
z[1][1] = 3


def two_square(n):
    d = int(0)
    if n <= 0:
        return 0
    while n:
        n = n // 2
        d += 1
    return d-1


def base(n):
    return n % 2


def plus(r, c, sum):
    if r < 2 and c < 2:
        return sum
    if two_square(r) != 0:
        sum += 2**(2*two_square(r)+1)
    if two_square(c) != 0:
        sum += 2**(2*two_square(c))
    return plus(r-2**two_square(r), c-2**two_square(c), sum)


# 가장 작은 2*2를 기준으로 인덱스
# 2^n의 증가 마다
# r >= 2^n : +2^(2n+1)
# c >= 2^n : +2^(2n) 만큼이 2배의 차이 마다 더해진다


N, r, c = map(int, input().split())

T = z[base(r)][base(c)]+plus(r, c, 0)
print(T)
