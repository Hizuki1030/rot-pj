#!/usr/bin/env python
# -*- coding: utf-8 -*-
# coding: UTF-8
import requests
import json
class Talk:
    def get(self,talking):
        # リクエストに必要なパラメーター
        headers = {'content-type':'text/json'}
        payload = {'utterance':talking}

        # APIKEYの部分は自分のAPI鍵を代入してください
        url = 'https://www.chaplus.jp/v1/chat?apikey=61725ce9aa788'
        # APIを叩く
        res = requests.post(url=url, headers=headers, data=json.dumps(payload))

        # 最適と思われるレスポンスを抽出
        data = res.json()['bestResponse']['utterance']

        return data