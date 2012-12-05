function klik()
{   var a = $('.more > a')[0];
    var e = document.createEvent('MouseEvents');
    e.initEvent( 'click', true, true );
    a.dispatchEvent(e);
}
klik();klik();klik();klik();
$.each( $('#item_explorer>ul>li'), function ( i, v ) 
{
    function rad( s , niz )
    {
        var rez = s;
        $.each( niz, function(i, v) { rez = rez.childNodes[v] } );
        return rez; 
    }
    var item_audio = rad( v, [1, 3, 1] ).getAttribute('href');
    var item_type  = rad( v, [1, 5, 1, 0] ).textContent;
    var item_kanji = rad( v, [1, 5, 3, 0] ).textContent.trim();
    var item_kana  = rad( v, [1, 5, 3, 1, 0] ).textContent.trim();
    var item_engl  = rad( v, [1, 5, 5, 0] ).textContent.trim();


    var sentence1_image      = rad( v, [3, 1, 1]).getAttribute('href');
    var sentence1_kanji_pre  = rad( v, [3, 3, 0]).textContent.trim();
    var sentence1_kanji      = rad( v, [3, 3, 1, 0]).textContent.trim();
    var sentence1_kanji_post = rad( v, [3, 3, 2]).textContent.trim();
    var sentence1_audio      = rad( v, [3, 3, 3]).getAttribute('href');
    var sentence1_kana_pre   = rad( v, [3, 5, 0]).textContent.trim();
    var sentence1_kana       = rad( v, [3, 5, 1, 0]).textContent.trim();
    var sentence1_kana_post  = rad( v, [3, 5, 2]).textContent.trim();
    var sentence1_english    = rad( v, [3, 7, 0] ).textContent.trim();

    console.log( 
        item_audio, ';', 
        item_type, ';' ,
        item_kanji, ';',
        item_kana, ';',  
        item_engl , ';',
        sentence1_image , ';',
        sentence1_kanji_pre, ';',
        sentence1_kanji, ';',
        sentence1_kanji_post, ';',
        sentence1_audio, ';',
        sentence1_kana_pre, ';',
        sentence1_kana, ';',
        sentence1_kana_post, ';',
        sentence1_english, ';',
        '***' 
        )
})
