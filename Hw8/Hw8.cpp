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
		// �[�J�{���X�P�_ aString[ i ] �O�_�� '<'
		// �Y�O�h�˱�A�ñN�̫�@�ө�J aDeque ���r������
		if ( aString[ i ] == '<' ) {
		// add your code here
			if (aDeque.size() != 0) // �p�G�Ŷ��٦�
				aDeque.pop_back(); // �R�� aDeque �̧��ݪ�����
		}
		// �Y���O�h�N aString[ i ] ��J aDeque ������
		else {
		// add your code here
			aDeque.push_back(aString[i]);	// �s�W������ aDeque �����ݡA���n�ɷ|�i��O����t�m�C
		}
	}
		// �`�N�G���i�H�A�ŧi�w�q�����ܼƩΪ���
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
	// �M��Q�� aDeque �� operations:
	// aDeque.size(), aDeque.empty(),
	// aDeque.back(), aDeque.front(),
	// aDeque.pop_back(), aDeque.pop_front(),
	// �ӧP�_ palindrome�A�ñN aDeque �M��

	// �`�N�G���i�H�A�ŧi�w�q�����ܼƩΪ���


	// add your code here
	if (aDeque.size() == 1)	// �p�G���׬� 1�A�^�� true
		return true;
	else {
		while ( !aDeque.empty() ) { // �ˬd aDeque �O�_���Ū��A�Y�O�Ū��A�^�� true �A�_�h�^�� false�C
			if ( aDeque.front() != aDeque.back() ) // �p�G�e��������᭱�A�^�� false
				return false;
			// �� aDeque ���e����᭱�����A�A�����᭱�ɭn�T�w�j�p�O�_������ 0
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

   // �`�N�G���U�{���X���i�H���

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
