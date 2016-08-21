__author__="Xu Shijie"
__date__="$Date: 2014-8-18$"

import re
import urllib,urllib2

def translate(text):
    #ģ�����������Ϊ����Google Translate����ҳ�������ݣ�Ȼ��ץȡ������

    #����Ҫ�����Ӣ�ľ���
    text_1=text
    #'langpair':'en'|'zh-CN'��Ӣ�ﵽ��������  
    values={'hl':'zh-CN','ie':'UTF-8','text':text_1,'langpair':"'en'|'zh-CN'"}
    url="http://translate.google.cn/#en/zh-CN/"+text
    data = urllib.urlencode(values)  
    req = urllib2.Request(url,data)
    #ģ��һ�������  
    browser='Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 2.0.50727)'  
    req.add_header('User-Agent',browser)
    #��ȸ跭�뷢������  
    response = urllib2.urlopen(req)  
    #��ȡ����ҳ��  
    html=response.read()
    #�ӷ���ҳ���й��˳��������ı�  
    #ʹ��������ʽƥ��  
    #�������ı���'TRANSLATED_TEXT='�Ⱥź��������  
    #.*? non-greedy or minimal fashion  
    #(?<=...)Matches if the current position in the string is preceded  
    #by a match for ... that ends at the current position  
    p=re.compile(r"(?<=TRANSLATED_TEXT=).*?;")  
    m=p.search(html)  
    text_2=m.group(0).strip(';')  
    return text_2

if __name__=="__main__":
    #text_1 ԭ��  
    text_1=open('D:\\C\\Python\\Google_translate_history.txt','r').read()  
    #text_1='Hello,My name\'s Xushijie'
    while True:
        text_1=raw_input("Text:")
        #print('The input text: %s' % text_1)  
        text_2=translate(text_1).strip("'")
        print('The output text: %s' % text_2.decode("utf-8"))  
      
        #������  
        filename='D:\\C\\Python\\Google_translate_history.txt'  
        fp=open(filename,'w+')
        fp.write(text_1)
        fp.write("  ")
        fp.write(text_2)
        fp.write("\n")
        fp.close()  
            
        report='Master, I have done the work and saved the translation at '+filename+'.'  
        print('Report: %s' % report)
