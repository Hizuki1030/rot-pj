#-*- coding: utf-8 -*-
import subprocess
from datetime import datetime
import time


def jtalk(word):
    subprocess.Popen(r"open_jtalk -m /usr/share/hts-voice/nitech-jp-atr503-m001/nitech_jp_atr503_m001.htsvoice -x /var/lib/mecab/dic/open-jtalk/naist-jdic -ow test.wav voice.txt",shell=True)
    time.sleep(len(word)/10)
    print(len(word)/5)
    subprocess.Popen(r"aplay test.wav",shell= True)


def speech(voiceword):
    f = open('voice.txt', 'w')
    f.write(voiceword)
    f.close()
    jtalk(voiceword)