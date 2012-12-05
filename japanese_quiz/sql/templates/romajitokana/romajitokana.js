var romaji_to_kana_list = 
{
    'a' : ['あ','ア'],
    'i' : ['い','イ'],
    'u' : ['う','ウ'],
    'e' : ['え','エ'],
    'o' : ['お','オ'],
    'ka' : ['か','カ'],
    'ki' : ['き','キ'],
    'ku' : ['く','ク'],
    'ke' : ['け','ケ'],
    'ko' : ['こ','コ'],
    'ga' : ['が','ガ'],
    'gi' : ['ぎ','ギ'],
    'gu' : ['ぐ','グ'],
    'ge' : ['げ','ゲ'],
    'go' : ['ご','ゴ'],
    'sa' : ['さ','サ'],
    'shi' : ['し','シ'],
    'su' : ['す','ス'],
    'se' : ['せ','セ'],
    'so' : ['そ','ソ'],
    'za' : ['ざ','ザ'],
    'ji' : ['じ','ジ'],
    'zu' : ['ず','ズ'],
    'ze' : ['ぜ','ゼ'],
    'zo' : ['ぞ','ゾ'],
    'ta' : ['た','タ'],
    'chi' : ['ち','チ'],
    'tsu' : ['つ','ツ'],
    'te' : ['て','テ'],
    'to' : ['と','ト'],
    'da' : ['だ','ダ'],
    'dji' : ['ぢ','ヂ'],
    'dzu' : ['づ','ヅ'],
    'de' : ['で','デ'],
    'do' : ['ど','ド'],
    'na' : ['な','ナ'],
    'ni' : ['に','ニ'],
    'nu' : ['ぬ','ヌ'],
    'ne' : ['ね','ネ'],
    'no' : ['の','ノ'],
    'ha' : ['は','ハ'],
    'hi' : ['ひ','ヒ'],
    'fu' : ['ふ','フ'],
    'he' : ['へ','ヘ'],
    'ho' : ['ほ','ホ'],
    'ba' : ['ば','バ'],
    'bi' : ['び','ビ'],
    'bu' : ['ぶ','ブ'],
    'be' : ['べ','ベ'],
    'bo' : ['ぼ','ボ'],
    'pa' : ['ぱ','パ'],
    'pi' : ['ぴ','ピ'],
    'pu' : ['ぷ','プ'],
    'pe' : ['ぺ','ペ'],
    'po' : ['ぽ','ポ'],
    'ma' : ['ま','マ'],
    'mi' : ['み','ミ'],
    'mu' : ['む','ム'],
    'me' : ['め','メ'],
    'mo' : ['も','モ'],
    'ya' : ['や','ヤ'],
    'yu' : ['ゆ','ユ'],
    'yo' : ['よ','ヨ'],
    'ra' : ['ら','ラ'],
    'ri' : ['り','リ'],
    'ru' : ['る','ル'],
    're' : ['れ','レ'],
    'ro' : ['ろ','ロ'],
    'wa' : ['わ','ワ'],
    'wo' : ['を','ヲ'],
    'nn' : ['ん','ン']
};


function romaji_to_kana( tekst, which ) // 0 = hiragana, 1 = katakana
{
    rez = ''
    brisanje = []
    min = 0;

    console.log( 'ulaz  ---', tekst )

    for( var i = 0; i < tekst.length ; i++ )
    {
        for( var j = min; j <= i ; j++)
        {
            var s = tekst.substring(j, i + 1);
            console.log(s)
            if( romaji_to_kana_list[ s ] )
            {
                rez += tekst.substring(min, j) + romaji_to_kana_list[ s ][which];

                for( var k = min; k < j; k++) brisanje.push(1);
                brisanje.push( s.length );

                min = i + 1;
                break;
            }
            if( i - j == 1 && tekst[i] == tekst[j] )
            {
                rez += tekst.substring(min, j) + romaji_to_kana_list['tsu'][which];
                min = i;
                break;
            }
        }


    }

    if( j == i )
    {
        rez += tekst.substring(min, i+1);
        for( var k = min; k < i + 1; k++) brisanje.push(1);

    }
    console.log('brisa ---', brisanje )
    console.log('izlaz ---', rez );
    return [rez, brisanje]; 
}

