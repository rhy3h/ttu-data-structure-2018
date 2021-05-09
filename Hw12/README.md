# Hw 12

參考附件檔 HW12.zip(此次作業所需的程式檔，可編譯執行，但功能並不完全)，製作 array-based, list-based, binary-search-tree-based 的 priority queues。

此 priority queue 係以字串比較來判斷 priority，字串值小 priority 高，例如，"abc" 的 priroity 高於 "def"。

根據下述說明更改 BinarySearchTree.h 與 HW12.cpp 使其具有底下的功能。

1. 修正 BinarySearchTree.h中的 findMinimumValue(...) 和 findMinimumNode(...)，使其可以從 binary search tree 中取出最小的 item 值。

    i. findMinimumValue(...)：呼叫 findMinimumNode(...)，找到binary search tree 中 item 值最小的 node，藉由參數 minimumValue 回傳其 item 值。

    ii. findMinimumNode(...)：Recusively 呼叫自己，直到找到 binary search tree 中 item 值最小的 node 後，回傳其位址。

2. 修正 HW12.cpp 中的 pqListInsert(...)，使其可以按照字串值由小到大的順序， 將輸入的字串正確地插入以 C++ STL list 實作的 priority queue 中。

3. 修正 HW12.cpp 中的 pqArrayInsert(...)，使其可以按照字串值由小到大的順序，將輸入的字串正確地插入以 C++ array 實作的 priority queue 中。