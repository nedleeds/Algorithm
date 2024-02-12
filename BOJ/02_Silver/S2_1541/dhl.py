import sys
sys.stdin = open('./BOJ/02_Silver/S2_1541/input.txt', 'r') 

str = input()

l = str.split('-')
s = sum(list(map(int, l[0].split('+'))))
if len(l) != 1:
    for i in range(1, len(l)):
        s -= sum(list(map(int, l[i].split('+'))))
print(s)