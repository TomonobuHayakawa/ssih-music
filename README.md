# Sound Signal Processing Library for Spresense

## Version info

| バージョン | リリース日  | 主な新機能と変更点                                               |
| ---        | ---         | ---                                                              |
| v0.6.0     | 2022-07-20  | 初版                                                             |
| v0.7.0     | 2022-08-26  | (機能追加) スケッチでメモリプールの初期化が不要になりました。    |
|            |             | (不具合修正) https://github.com/SonySemiconductorSolutions/ssih-music/issues/3: 音声データの供給がされないと異常停止する問題を修正しました。    |
|            |             | (不具合修正) https://github.com/SonySemiconductorSolutions/ssih-music/issues/4: 一部のSFZファイルのロードができない問題を修正しました。         |
|            |             | (サンプル) サンプルスケッチにYuruFlaCastanetを追加しました。     |
| v0.8.0     | 2022-09-30  | (機能追加) MIDIファイルの一時停止に対応しました。                |
|            |             | (サンプル) サンプルスケッチにYuruFlaShoeを追加しました。         |

## ライブラリ概要

このライブラリは[Spresense](https://www.sony-semicon.co.jp/products/smart-sensing/spresense/)で簡単に楽器を開発するためのものです。
電子楽器の演奏データを定めるMIDI規格をベースとしたAPIと、Spresenseのオーディオ入力・オーディオ出力を簡単に扱える機能ブロックを提供します。

## チュートリアル

使い方は[チュートリアル](/docs/Tutorial.md)を参照してください。

## ライセンス

本ソフトウェアは Apache License 2.0 または GNU Lesser General Public License v2.1 or later の下に提供します。
詳しくは [LICENSE](/LICENSE) を参照してください。

## Copyright

Copyright 2022 Sony Semiconductor Solutions Corporation
