import os
import urllib
def Schedule(a,b,c):
	per=100.0*a*b/c
	if per>100:
		per=100
	print('%0.2f%%'%per)
url='http://zhangmenshiting2.baidu.com/data2/music/7345405/aGVnaWlmbGaeomZzrZmmnJZvlZpuZnCbZWJnl5eZaHFqaGdlmW9rapNpmWeaamxqaZRsmW2ba25mYmxtapmZcWqTWaGemnRoX2dqbWtub3FhY2lqa25sOA$$7345405.mp3?xcode=bf909c404cbc199641d942b7f3e4528b9e8e4650995cb99a&mid=0.57968890166685'
local=os.path.join("e:/","bd.mp3")
urllib.urlretrieve(url,local,Schedule)
