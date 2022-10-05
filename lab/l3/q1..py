t, l = int(input()), int(input())
for _ in range(t):
    L = list(map(int, input().split()))
    for i in range(l-1,-1,-1):
        print(L[i], end = ' ')
    print()
    i = 3
    while(i<l):
        print(L[i]+3,end = ' ')
        i+=3
    print()
    i = 5  
    while(i<l):
        print(L[i]-7,end = ' ')
        i+=5
    print()
    sum = 0
    for i in range(3,8):
        sum += L[i]
    print(sum)