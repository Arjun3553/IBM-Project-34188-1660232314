import random 
import time

i=1
while i==1 : 
    temp = random.randint(30,200)
    hum = random.randint(0,100)
    print("temperature : "+str(temp)+" °F\n")
    print("humidity : "+str(hum)+" %\n")
    if temp>=100:
        print("high temperature : "+str(temp)+" °F\n")
    time.sleep(5)