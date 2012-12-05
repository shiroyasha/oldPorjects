# -*- coding: utf-8 -*-
# generate kana's

a = ['a','i','u','e','o']
b = ['', 'k', 'g', 's', 'z', 't', 'd', 'n', 'h', 'b', 'p', 'm', 'y', 'r', 'w']

tekst = ''

for prvi in b:
    for drugi in a:
        tekst = tekst + prvi + drugi 

print tekst

tekst= ['a','i','u','e','o','ka','ki','ku','ke','ko','ga','gi','gu','ge','go',
        'sa','shi','su','se','so',
        'za','ji','zu','ze','zo','ta','chi','tsu','te','to','da','dji','dzu','de','do',
        'na','ni','nu','ne','no','ha','hi','fu','he','ho','ba','bi','bu','be','bo',
        'pa','pi','pu','pe','po','ma','mi','mu','me','mo','ya','yu','yo','ra','ri','ru','re','ro','wa','wo','nn']

# create list
hiragana =['あ','い','う','え','お','か','き','く','け','こ','が','ぎ','ぐ','げ','ご',
           'さ','し','す','せ','そ','ざ','じ','ず','ぜ','ぞ','た','ち','つ','て','と',
           'だ','ぢ','づ','で','ど','な','に','ぬ','ね','の','は','ひ','ふ','へ','ほ',
           'ば','び','ぶ','べ','ぼ','ぱ','ぴ','ぷ','ぺ','ぽ','ま','み','む','め','も',
           'や','ゆ','よ','ら','り','る','れ','ろ','わ','を','ん']
katakana =['ア','イ','ウ','エ','オ','カ','キ','ク','ケ','コ','ガ','ギ','グ','ゲ','ゴ',
           'サ','シ','ス','セ','ソ','ザ','ジ','ズ','ゼ','ゾ','タ','チ','ツ','テ','ト',
           'ダ','ヂ','ヅ','デ','ド','ナ','ニ','ヌ','ネ','ノ','ハ','ヒ','フ','ヘ','ホ',
           'バ','ビ','ブ','ベ','ボ','パ','ピ','プ','ペ','ポ','マ','ミ','ム','メ','モ',
           'ヤ','ユ','ヨ','ラ','リ','ル','レ','ロ','ワ','ヲ','ン']

h = [ i for i in hiragana ]
k = [ i for i in katakana ]

print len(tekst), len(h), len(k)
gotovo = dict( [tekst[i], [h[i], k[i]]] for i in xrange(0, len(h)-1))

print '{'
for i in xrange(0, len(tekst)):
    print "'{}' : ['{}','{}'],".format(tekst[i], h[i], k[i] )

print '}'
