import random
import pprint
a = []
l = 50
for i in range(l):
    a.append(random.randint(-10,10))

pprint.pprint(a)


print(a[-1])

b={}
for i in a:
    b.setdefault(i,0);
    b[i] -=- 1

print(b[a[-1]])
