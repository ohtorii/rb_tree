赤黒木を表示する秀丸マクロ


■これは何
    昔々、オレオレSTLを作ったときに赤黒木(rb_tree/red black tree)のデバッグを
    行うために作った「秀丸マクロとコマンドラインツール」です。
    秀丸エディタ上で赤黒木の中身をダンプ表示します


■使い方
    （入力）
        5
        4
        3
        2
        1

    （結果）
                [R]1
            [B]2
                [R]3
        [B]4
            [B]5


        ※[R] - Red
        ※[B] - Black


■動作環境
    秀丸エディタver8.10で動作を確認、ver8以降なら動くと思います。


■インストール方法
    macroディレクトリの以下２ファイルを秀丸エディタのマクロディレクトリへ
    コピーして下さい。

    rb_tree.exe
    rb_tree.mac


■使い方
    doc/rb_tree.pdf を参照して下さい。


■連絡先とか
    http://d.hatena.ne.jp/ohtorii
    https://github.com/ohtorii


以上