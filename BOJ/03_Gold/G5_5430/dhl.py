import sys
from collections import deque

sys.stdin = open('./BOJ/03_Gold/G5_5430/input.txt', 'r')

def check(cmd, arr):
    reverse = False
    arr = deque(arr)
    
    for x in cmd:
        if x == "R":
            reverse = not reverse
        elif x == "D":
            if not arr:
                print("error")
                return
            if reverse:
                arr.pop()
            else:
                arr.popleft()
                
    if reverse:
        arr.reverse()
        
    print('[' + ','.join(map(str, arr)) + ']')

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    
    for _ in range(n):
        cmd = sys.stdin.readline().strip()
        length = int(sys.stdin.readline().strip())
        arr = sys.stdin.readline().strip()[1:-1]
        if arr:
            arr = list(map(int, arr.split(',')))
        else:
            arr = []
        check(cmd, arr)
