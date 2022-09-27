import random;
import time;


while True:
   temperature = random.randint(30,205)
   humidity = random.randrange(0,100)
   print("temperature : "+str(temperature)+" °F\n")
   print("humidity : "+str(humidity)+" %\n")
   if(temperature >=100):
    print("high temperature : "+ str(temperature) +" °F\n")
   time.sleep(5)