import sys
while True:
    l = sys.stdin.readline()
    l = sorted(list(map(int, l.split())))
    if sum(l) == 0: break
    if l[2]**2 == l[0]**2 + l[1]**2:
        print('right')
    else:
        print('wrong')
