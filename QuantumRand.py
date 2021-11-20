#******************************************
#Title: Quantum Random
#Author: Aleksandar Damnjanovic
#Date: 19.11.2021
#Last edit: 20.11.2021
#******************************************

import requests
import json
import time
import sys

class QuantumRand:

    def __init__(self):
        self.next()

    def next(self):
        __address= 'https://qrng.anu.edu.au/API/jsonI.php?length=1&type=hex16&size=8'
        __data=requests.get(__address)
        __obj= json.loads(__data.text)
        __hexString= __obj['data'][0]
        self.value= int(__hexString,16)
        time.sleep(0.5)

    def getRand(self, min=0, max=sys.maxsize):
        if min<0 or max>sys.maxsize:
            print(f'min must be bigger than or 0\nmax must be less that {sys.maxsize}')

        __ret=0
        if max!=sys.maxsize:
            if self.value > max:
                __ret= self.value % max

        if __ret<min and min!=0:
            __ret= min + (self.value % (max-min))

        return __ret

    def getFloat(self, decimal=2):
        if self.value<sys.maxsize:
            __ret= float(self.value/ sys.maxsize)
        else:
            __ret= float(sys.maxsize/self.value)

        return f'%.{decimal}f' % __ret