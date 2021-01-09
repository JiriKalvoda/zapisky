def printTable(a):
    s = [0 for i in a[0] ]
    for b in a:
        s=list(map(max,map(len,b),s))
    for b in a:
        print(" ".join(map(lambda x,y:x.center(y),b,s)))




printTable([
    ['a','abcd','xy'],
    ['avfnkdfklk n','cd','']
    ])

