import requests
import time

rows, cols = (3, 2)#3 customers with 2 columns {tread, mread}
arr = []

for i in range(rows):
   a = []
   a.append( int(input("Enter transmission line reading of customer " + str(i) + ": ")) )
   a.append( int(input("Enter meter reading of customer " + str(i) + ": ")) )
   arr.append(a)
print(type(arr[0][0]))
print(arr)

prev = input("Enter units from transformer: ")

for i in range(len(arr)):
   url = 'http://10.10.210.116:8080/reads'
   j = i + 1
   open = '{'
   close = '}'
   json = open + f'"custid" : {j},"tread" : {arr[i][0]},"mread" : {arr[i][1]}' + close
   print(json)
   headers = {'Content-Type': 'application/json'}
   r = requests.post(url, data=json, headers=headers)
   print(r)
   # time.sleep(2)
    
