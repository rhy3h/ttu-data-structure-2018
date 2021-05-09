# Hw 11

參考附件檔 HW11.zip(此次作業所需的程式檔，可編譯執行，但功能並不完全)，

修改BinarySerachTree.h使得binary search tree有底下的功能。

1. 增加 BinarySearchTree::levelorder(...)，使得traverse一個search tree時，level越高的越晚visit，同一層level的節點 (sibling nodes)則由左至右visit。

2. 修改BinarySearchTree::insertInorder(...)，使得重複的word加入search tree時，不會產生新的節點，而是記錄該word已被加入幾次。

註：class BinaryNode已增加一count變數，用來記錄該word被加入的次數。

3. 修改BinarySearchTree::removeValue(...)，使得刪除search tree中的某word時，除非 count是1，否則不移除該節點，而僅是減少count記錄的次數。

4. 增加 BinarySearchTree::removeRightmostNode(...)，使得真正移除某個word的節點時，其空缺由最接近但小於該word的節點來遞補。

<<注意>>原始的程式碼有bug，在某些狀況下執行結果會不正確，請找出來並加以修正。

Output: if a is b, and b is c, then a is c.