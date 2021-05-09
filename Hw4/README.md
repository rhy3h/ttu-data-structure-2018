# Hw 4

參考附件檔 HW4.cpp，使用 link - based polynomials 來撰寫多項式加法運算。

1. 你必須撰寫 inputLinkTerms(...)，使其可以不需按照降冪的順序輸入係數，卻會按降冪的順序存入 link-based polynomials。
若相同的冪次重覆輸入，則以最後輸入的係數為主。

<< 注意 >> 輸入係數存入 link - based polynomial 時，需一次就放到定位，不可以先存入，然後使用 sorting 方法排序。

2. 你必須撰寫 addLinkBasedPoly(...)，使其可以將傳入的兩個 link - based polynomials 相加所得到的第三個 link-based polynomial 的指標回傳。

<< 注意 >> 輸入係數可以是負數。