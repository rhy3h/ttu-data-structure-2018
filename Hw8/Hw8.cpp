#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

void input(string sMessage, string &sInputString)
{
	do {
		cout << sMessage << endl;
		cin >> sInputString;
	} while ( cin.fail() );

	return;
}

void pushAndCorrectDeque(string& aString, deque<char>& aDeque)
{
	for ( int i = 0; i < aString.size(); i++) {
		// 加入程式碼判斷 aString[ i ] 是否為 '<'
		// 若是則捨棄，並將最後一個放入 aDeque 的字母消除
		if ( aString[ i ] == '<' ) {
		// add your code here
			if (aDeque.size() != 0) // 如果空間還有
				aDeque.pop_back(); // 刪除 aDeque 最尾端的元素
		}
		// 若不是則將 aString[ i ] 放入 aDeque 的尾端
		else {
		// add your code here
			aDeque.push_back(aString[i]);	// 新增元素至 aDeque 的尾端，必要時會進行記憶體配置。
		}
	}
		// 注意：不可以再宣告定義任何變數或物件
}

void pushAndCorrectStackQueue(string& aString, stack<char>& aStack, queue<char>& aQueue)
{
	//123<<<
	for ( int i = 0; i < aString.size(); i++) {
		// add your code here
		int j = i;
		while (aString[j++] != '<') {

		}
		if (aString[i] == '<') {
			if (aStack.size() != 0)
				aStack.pop();
			if (aQueue.size() != 0)
				aQueue.pop();
		}
	
		else {
			aStack.push(aString[i]);
			aQueue.push(aString[i]);
		}
	}
}

bool isPalindromeDeque(deque<char> aDeque)
{
	// 然後利用 aDeque 的 operations:
	// aDeque.size(), aDeque.empty(),
	// aDeque.back(), aDeque.front(),
	// aDeque.pop_back(), aDeque.pop_front(),
	// 來判斷 palindrome，並將 aDeque 清空

	// 注意：不可以再宣告定義任何變數或物件


	// add your code here
	if (aDeque.size() == 1)	// 如果長度為 1，回傳 true
		return true;
	else {
		while ( !aDeque.empty() ) { // 檢查 aDeque 是否為空的，若是空的，回傳 true ，否則回傳 false。
			if ( aDeque.front() != aDeque.back() ) // 如果前面不等於後面，回傳 false
				return false;
			// 把 aDeque 的前面跟後面移除，再移除後面時要確定大小是否為不為 0
			aDeque.pop_front();
			if ( aDeque.size() )
				aDeque.pop_back();
		}
	}
	return true;
}

bool isPalindromeStackQueue(stack<char> aStack, queue<char> aQueue)
{
	// add your code here


	return false;
}

int main()
{
 	string sInput;

	// Queue STL
   queue<char> myQueue;

   for ( char j = 0; j < 5; j++ )
	   myQueue.push( j + 'A' );

   cout << "myQueue is a true queue:  ";
   
   while ( !myQueue.empty() )  {
	   cout << myQueue.front() << " ";
	   myQueue.pop();
   }

   cout << endl;

	// Use Deque STL as Queue
   deque<char> myDeque;
   
   for ( char j = 0; j < 5; j++ )
	   myDeque.push_back( j + 'A' );

   cout << "myDeque is also a queue:  ";
   
   while ( !myDeque.empty() )  {
	   cout << myDeque.front() << " ";
	   myDeque.pop_front();
   }

   cout << endl;

   for ( char j = 0; j < 5; j++ )
	   myDeque.push_front( j + 'A'  );

   cout << "myDeque is still a queue: ";

   while ( !myDeque.empty() )  {
	   cout << myDeque.back() << " ";
	   myDeque.pop_back();
   }

   cout << endl;


   // Stack STL

   stack<char> myStack;

   for ( char j = 0; j < 5; j++ )
		myStack.push(  j + 'A'  );

   cout << "myStack is a true stack:  ";

   while ( !myStack.empty() )  {
	   cout << myStack.top() << " ";
	   myStack.pop();
   }

   cout << endl;

	// Use Deque STL as Stack

   for ( char j = 0; j < 5; j++ )
	   myDeque.push_front(  j + 'A'  );

   cout << "myDeque is also a stack:  ";
   
   while ( !myDeque.empty() )  {
	   cout << myDeque.front() << " ";
	   myDeque.pop_front();
   }  

   cout << endl;

   for ( char j = 0; j < 5; j++ )
	   myDeque.push_back(  j + 'A'  );

   cout << "myDeque is still a stack: ";
   
   while ( !myDeque.empty() )  {
	   cout << myDeque.back() << " ";
	   myDeque.pop_back();
   }

   cout << endl;

   // 注意：底下程式碼不可以更動

	while (1) {
		input( "\nEnter a string or X to Exit:", sInput );

		if ( sInput.size() == 1 && ( sInput == "X" || sInput == "x" ) )
			return 0;	

		pushAndCorrectDeque( sInput, myDeque );
		bool yes = isPalindromeDeque( myDeque );

		for ( int i = myDeque.size(); i > 0; i--) {
			cout << myDeque.front();
			myDeque.pop_front();
		}

		if ( yes ) 
			cout << " is a palindrome" << endl;
		else
			cout << " is not a palindrome" << endl;

		pushAndCorrectStackQueue( sInput, myStack, myQueue );
		yes = isPalindromeStackQueue( myStack, myQueue );

		for ( int i = myQueue.size(); i > 0; i--) {
			cout << myQueue.front();
			myQueue.pop();
		}

		if ( yes ) 
			cout << " is a palindrome" << endl;
		else
			cout << " is not a palindrome" << endl;
	}

	return 1;
}
