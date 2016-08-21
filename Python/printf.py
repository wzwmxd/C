from ctypes import *
msvcrt=cdll.msvcrt
msvcrt.scanf("%d%d",a,b)
msvcrt.printf("%d+%d=%d",a,b,a+b)
