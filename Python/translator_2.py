#-*- coding:utf-8 -*-

import urllib
import urllib2
from bs4 import BeautifulSoup

translate_param = {
    'hl': 'zh-CN',
    'ie': 'UTF-8',
    'text': None,
    'langpair': "'en'|'zh-CN'",
    }

def translate(src):
    translate_param['text'] = src
    url = 'http://translate.google.com/'
    req = urllib2.Request(url, urllib.urlencode(translate_param))

    # simulate browser
    browser = 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_8_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/29.0.1547.65 Safari/537.36'
    req.add_header('User-Agent', browser)

    soup = BeautifulSoup(urllib2.urlopen(req).read())
    result = soup.find(id='result_box')

    return result.get_text()

def process():
    while True:
        srcString = str(raw_input(">>>")).strip()
        if srcString.lower().startswith('quit'):
            break

        destString = translate(srcString)
        print destString

if __name__ == '__main__':
    process()
