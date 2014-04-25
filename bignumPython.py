t=0;
t=input()
while t:
    n,m,option=map(int,raw_input().split(" "))
    if(option==1):
        print n+m
    elif(option==2):
        print abs(n-m)
    elif(option==3):
        print n*m
    elif(option==4):
        print n/m
    elif(option==5):
        print n%m
    elif(option==6):
        print n**m
    elif(option==7):
        print n**m
    else:
        print "Invalid Option!!"
    t-=1;
