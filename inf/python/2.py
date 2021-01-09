import random
import pprint
a = []
l = 25
for i in range(l):
    a.append(random.randint(0,100))

pprint.pprint(a)

for i in range(l):
    for j in range(l-1):
        (a[j],a[j+1])=(min(a[j],a[j+1]),max(a[j],a[j+1]))

pprint.pprint(a)

x=int(input("Zadej hledanou hodnotu: "))

def find (a,v):
    print(a)
    if len(a)==0:
        return 0
    m=len(a)//2
    if a[m] == v:
        return 1
    elif a[m] < v:
        return find(a[m+1:],v)
    elif a[m] > v:
        return find(a[:m],v)

print(find(a,x))
    
