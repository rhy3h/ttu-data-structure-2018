# Hw 8 沒寫

參考附件檔 HW8.zip(此次作業所需的程式檔，可編譯執行，但功能並不完全)，

使用 C++ class template 的 deque ( stack, queue)
(可參考http://www.cplusplus.com/reference/stl/deque/)來完成底下的功能。

1. pushAndCorrect(...): 
此功能會將傳入的字串一個字母一個字母地放入deque, stack, queue 中，
而且在放入的過程中會順便進行修正。
字串由英文字母組成同時參雜著字元 '<' (「小於」符號，代表鍵盤的 backspace)，
在將字母放入deque (stack, queue) 的過程中，碰到 '<' 時，則捨棄此字元，
同時還須將前一個字母(若存在的話)消除。
例子：假設傳入的字元為 <<

2. isPalindrome(...): 

判斷 deque 中所存放的字串是否為 palindrome，清空 deque，並回傳 true 或 false，。

例子：abcdcba 為 palindrome，回傳 true；abcabc 非 palindrome，回傳 false。

注意：你只能唯一使用程式中已經定義宣告好的 deque, stack, queue 以及相關變數，
不能再額外定義宣告使用任何 array 等。
