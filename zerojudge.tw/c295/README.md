# c295: 最大和

## 題目

給定 N 群數字，每群都恰有 M 個正整數。若從每群數字中各選擇一個數字 (假設第 i 群所選出數字為 ti)，將所選出的 N 個數字加總即可得和 S = t1+t2+…+ +…+ tN。請寫程式計算 S 的最大值 (最大總和 )，並判斷各群所選出的數字是否可以整除 S。

## 輸入

第一行有二個正整數 N 和 M， 1≦ N ≦ 20 ，1≦ M ≦ 20。

接下來的 N 行，每一行各有 M 個正整數 xi ，代表一群整數，數字與數字間有一個空格，且 1≦ i ≦M，以及 1≦ xi ≦256。

## 輸出

第一行輸出最大總和 S。

第二行按照被選擇數字所屬群的順序，輸出可以整除 S 的被選擇數字，數字與數字間以一個空格隔開，最後一個數字後無空白；若 N 個被選擇數字都不能整除 S，就輸出 -1。

## 出處

[https://zerojudge.tw/ShowProblem?problemid=c295](https://zerojudge.tw/ShowProblem?problemid=c295)