# kyoupuro-template

その名の通り、竸プロのテンプレートです。

## C++

[`main.cpp`](c++/main.cpp)がメイン。

[`template.hpp`](c++/template.hpp)は提出時に展開される。

[`submit.cpp`](c++/submit.cpp)は展開されたやつ。

[`test.cpp`](c++/test.cpp)は実験とかするコードをかくためのもの。

### コンパイル

[`Makefile`](c++/Makefile)を用意しているため、`make`だけでコンパイルできる。

コンパイルに[`zapcc`](https://github.com/yrnkrn/zapcc)を使ってるからコンパイルが高速！！！

([`ccache`](https://github.com/ccache/ccache)より`zapcc`の方がコンパイル時間が短いのです…)

(でも`zapcc`は死んでるっぽいのが気になる)

~~~
make
~~~

### テスト

[`oj`](https://github.com/online-judge-tools/oj)を使用。

テストケースのダウンロードは[`atcoder-cli`](http://tatamo.81.la/blog/2018/12/07/atcoder-cli/)がよしなにやってくれる。

~~~
oj t -N -d tests
~~~

### 提出

[`quom`](https://github.com/Viatorus/quom)を使ってヘッダーを展開し、`submit.cpp`に出力。

(`quom`の`trim`は改造？によって無効化してる)

そして`submit.cpp`を提出。

~~~
quom main.cpp submit.cpp -I ~/Documents/KyouPuro/c++/ && acc submit
~~~
