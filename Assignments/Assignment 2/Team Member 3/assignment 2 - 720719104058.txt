import random;
import time;
while 1==1:
   temperature = random.randint(30,200)
   humidity = random.randrange(0,100)
   print("temperature : "+str(temperature)+" °F\n")
   print("humidity : "+str(humidity)+" %\n")
   if(temperature >=100):
    print("high temperature : "+ str(temperature) +" °F\n")
   time.sleep(5)