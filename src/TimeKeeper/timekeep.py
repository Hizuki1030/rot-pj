#coding:UTF-8
import datetime
import voice
import time
import json
try:
    i = 0
    while True:
        dt_now=datetime.datetime.now()
        now_h=dt_now.hour
        now_m=dt_now.minute
        day = dt_now.day
        month = dt_now.month
        value= (now_h,now_m)
        if value ==(8,50):
            print('１時間目開始')
            time.sleep(60)
        elif value==(9,30):
            print('１時間目終わり')
            voice.speech("１時間目終わり十分前")
            time.sleep(60)
        elif value==(9,45):
            print('2時間目開始')
            time.sleep(60)
        elif value==(10,25):
            print('2時間目終わり')
            voice.speech("2時間目終わり十分前")
            time.sleep(60)
        elif value==(10,45):
            print('3時間目開始')
            time.sleep(60)
        elif value==(11,25):
            print('3時間目終わり')
            voice.speech("3時間目終わり十分前")
            time.sleep(60)
        elif value==(11,40):
            print('4時間目開始')
            time.sleep(60)
        elif value==(12,20):
            print('4時間目終わり')
            voice.speech("4時間目終わり十分前")
            time.sleep(60)
        elif value==(13,20):
            print('5時間目開始')
            time.sleep(60)
        elif value==(14,00):
            print('5時間目終わり')
            voice.speech("6時間目終わり十分前")
            time.sleep(60)
        elif value==(14,15):
            print('6時間目開始')
            time.sleep(60)
        elif value==(14,55):
            print('6時間目終わり')
            voice.speech("6時間目終わり十分前")
            time.sleep(60)
        elif value==(15,15):
            print('7時間目開始')
            time.sleep(60)
        elif value==(15,55):
            print('7時間目終わり')
            voice.speech("7時間目終わり十分前")
            time.sleep(60)            
        elif(value==(16,10)):
            print('8時間目開始')
            time.sleep(60)
        elif value==(16,50):
            print('8時間目終わり')
            voice.speech("8時間目終わり十分前")
            time.sleep(60)
            fd = open(r'/home/sunglab/ドキュメント/homework_json.json', "r",encoding="utf-8")
            data = json.load(fd)
            fd.close()
            subject = data[str(month)+ ","+ str(day +1)]
            message = "明日の課題は"+subject+"です。"
            voice.speech(message)
            time.sleep(60)
except KeyboardInterrupt:   # exceptに例外処理を書く
    print('stop!')
