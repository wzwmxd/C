__author__="Xu Shijie"
__date__="$Date: 2014-8-18$"

import re
import urllib,urllib2

def translate(text):
    #模拟浏览器的行为，向Google Translate的主页发送数据，然后抓取翻译结果

    #输入要翻译的英文句子
    text_1=text
    #'langpair':'en'|'zh-CN'从英语到简体中文  
    values={'hl':'zh-CN','ie':'UTF-8','text':text_1,'langpair':"'en'|'zh-CN'"}
    url="http://translate.google.cn/#en/zh-CN/"+text
    data = urllib.urlencode(values)  
    req = urllib2.Request(url,data)
    #模拟一个浏览器  
    browser='Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 2.0.50727)'  
    req.add_header('User-Agent',browser)
    #向谷歌翻译发送请求  
    response = urllib2.urlopen(req)  
    #读取返回页面  
    html=response.read()
    #从返回页面中过滤出翻译后的文本  
    #使用正则表达式匹配  
    #翻译后的文本是'TRANSLATED_TEXT='等号后面的内容  
    #.*? non-greedy or minimal fashion  
    #(?<=...)Matches if the current position in the string is preceded  
    #by a match for ... that ends at the current position  
    p=re.compile(r"(?<=TRANSLATED_TEXT=).*?;")  
    m=p.search(html)  
    text_2=m.group(0).strip(';')  
    return text_2

if __name__=="__main__":
    #text_1 原文  
    text_1=open('D:\\C\\Python\\Google_translate_history.txt','r').read()  
    #text_1='Hello,My name\'s Xushijie'
    while True:
        text_1=raw_input("Text:")
        #print('The input text: %s' % text_1)  
        text_2=translate(text_1).strip("'")
        print('The output text: %s' % text_2.decode("utf-8"))  
      
        #保存结果  
        filename='D:\\C\\Python\\Google_translate_history.txt'  
        fp=open(filename,'w+')
        fp.write(text_1)
        fp.write("  ")
        fp.write(text_2)
        fp.write("\n")
        fp.close()  
            
        report='Master, I have done the work and saved the translation at '+filename+'.'  
        print('Report: %s' % report)
