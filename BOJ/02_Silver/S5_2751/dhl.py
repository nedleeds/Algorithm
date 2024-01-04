def heap_method():
    import heapq

    n = int(input())
    heap = []

    for _ in range(n):
        heapq.heappush(heap, int(input()))

    for _ in range(n):
        print(heapq.heappop(heap))

def sorted_method():
    # 아래 코드 실행 시간 : 1068ms 시스템 입출력 사용 여부 차이
    import sys
    
    l = [int(sys.stdin.readline()) for _ in range(int(input()))]
    for x in sorted(l):
        sys.stdout.write(f'{x}\n')
    
    """
    아래 코드 실행 시간 : 1304 ms
    import sys

    l = [int(sys.stdin.readline()) for _ in range(int(input()))]
    print(*sorted(l), sep='\n')
    """

if __name__ == '__main__':
    sorted_method()