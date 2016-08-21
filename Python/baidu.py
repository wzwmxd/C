import urllib.urllib2,cookielib2
import pdb
import os,sys
def test(username,passwd):
    cj=cookielib.CookieJar()
    url_login="https://passport.baidu.com/?login"
    body=(('username',username),('password',passwd),('tpl','sp'),('Submit','µÇÂ¼'),('mem_pass','on'))
    print body
    opener=urllib2.build_opener(utllib2.HTTPCookieProcessor(cj))
    opener.addheaders=[('User-Agent', 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.9.2.12) Gecko/20101026 Firefox/3.6.12 ( .NET CLR 3.5.30729; .NET4.0E)'),('Host','passport.baidu.com')]
    urllib2.install_opener(opener)
    req=urllib2.Request(url_login,urllib.urlencode(body))
    u=urllib2.urlopen(req)
print u.read()

if __name__=='__main__':
    name=u'username'
    pwd=u'password'
    _name=name.encode('gb2312')
    _pwd=pwd.encode('gb2312')
    test(_name,_pwd)
