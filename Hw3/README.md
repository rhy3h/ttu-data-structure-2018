# Hw 3

參考附件檔 HW3.cpp，使用 array-based polynomials 來撰寫多項式加法運算。

1. 你必須撰寫 inputTerm(...)，使其可以不需按照降冪的順序輸入係數，
卻會按降冪的順序存入 array-based polynomials。若相同的冪次重覆輸入，則以最後輸入的係數為主。

<<注意>>輸入係數存入陣列時，需一次就放到定位，不可以先存入，然後使用 sorting 方法排序。

2. 你必須撰寫 addArrayBasedPoly(...)，使其可以將傳入的前兩個 array-based polynomials 的相加結果，
   
存在傳入的第三個 array-based polynomial 中 。
<<注意>>輸入係數可以是負數。