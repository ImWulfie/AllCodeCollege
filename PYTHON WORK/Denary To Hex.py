a=input("enter number in decimal :")
def cal(a):
    if a<10:
        b=str(a)
    elif a==10:
        b="A"
    elif a==11:
        b="B"
    elif a==12:
        b="C"
    elif a==13:
        b="D"
    elif a==14:
        b="E"
    else:
        b="F"
    return b
b=a
L1=""
while True:
    c=b%16
    if b<16:
        L1=L1+cal(c)
        break
    else:
        L1=L1+cal(c)
    b=b/16
c=""
for i in reversed(L1):
    c=c+i
print (c)
