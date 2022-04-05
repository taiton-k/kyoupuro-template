# kyoupuro-template

その名の通り、竸プロのテンプレートです。

## C++

[`main.cpp`](https://github.com/taiton-k/kyoupuro-template/blob/main/c++/main.cpp)がメイン。

[`template.hpp`](https://github.com/taiton-k/kyoupuro-template/blob/main/c++/template.hpp)は提出時に展開される。

[`submit.cpp`](https://github.com/taiton-k/kyoupuro-template/blob/main/c++/template.hpp)は展開されたやつ。

### コンパイル

Makefileを用意しているため、`make`だけでコンパイルできる。

コンパイルに[`ccache`](https://github.com/ccache/ccache)を使ってるからコンパイルが高速！！！

### 提出

[`quom`](https://github.com/Viatorus/quom)を使ってヘッダーを展開し、`submit.cpp`に出力。

そして`submit.cpp`を提出。
