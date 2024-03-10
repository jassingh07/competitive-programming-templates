import pywhatkit
from datetime import datetime

myobj = datetime.now()
print(myobj.hour, myobj.minute, myobj.second)
msg = 'Alert: illegal connection detected\nLocation: House number 2\n Area id: 4'
pywhatkit.sendwhatmsg('+916239507536', msg, myobj.hour, myobj.minute + 2)