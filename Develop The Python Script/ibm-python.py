import wiotp.sdk.device
import time
import random
myConfig = { 
    "identity": {
        "orgId": "2223cm",
        "typeId": "RaspberryPi",
        "deviceId":"192165160"
    },
    "auth": {
        "token": "147258369"
    }
}

def myCommandCallback(cmd):
    print("Message received from IBM IoT Platform: %s" % cmd.data['command'])
    m=cmd.data['command']

client = wiotp.sdk.device.DeviceClient(config=myConfig, logHandlers=None)
client.connect()

while True:
    pH_value=random.randint(0,14)
    turbidity=random.randint(0,1000)
    myData1={'pH_value':pH_value}
    myData2={'Turbidity':turbidity}
    client.publishEvent(eventId="pH_value", msgFormat="json", data=myData1, qos=0, onPublish=None)
    client.publishEvent(eventId="Turbidity in NTU's", msgFormat="json", data=myData2, qos=0, onPublish=None)
    print("pH_value",pH_value)
    print("Turbidity in NTU's", turbidity) 
    print("Published data Successfully")
    client.commandCallback = myCommandCallback
    time.sleep(2)
client.disconnect()