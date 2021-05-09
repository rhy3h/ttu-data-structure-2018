/*一，array-based polynomials
    1. inputArrayBasedTerms()
        使其可以不需按照降冪的順序輸入係數
        卻會按降冪的順序存入
        若相同的冪次重覆輸入，則將係數相加
    2. ArrayBasedDifferentiation()
        2x^2 + 1x^1 => 4x^1 + 1
        將多項式微分
    3. removeArrayBasedTerm()
        將輸入的冪次移除

二，link-based polynomials
    1. inputLinkBasedTerms
        使其可以不需按照降冪的順序輸入係數
        卻會按降冪的順序存入
        若相同的冪次重覆輸入，則將係數相加
    2. LinkBasedDifferentiation()
        2x^2 + 1x^1 => 4x^1 + 1
        將多項式微分
    3. removeLinkBasedTerm()
        將輸入的冪次移除*/

//#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX_TERMS 10 /*size of terms array*/

class PolynomialTerm {
public:
	int coef;
	int expo;
};

class ArrayPolynomial {
public:
	PolynomialTerm terms[MAX_TERMS];

	void clear()
	{
		for (int i = 0; i < MAX_TERMS; i++) {
			terms[i].coef = 0;
			terms[i].expo = 0;
		}

		return;
	}

	void inputArrayBasedTerms(int coef, int expo)
	{
		// modify the following code and add your code here
		/*int i = 0;

		for (; terms[i].coef != 0 && i < MAX_TERMS; i++);

		terms[i].coef = coef;
		terms[i].expo = expo;*/

		// add your code here
		int temp = 0;

		//當係數不為零
		if (coef != 0) {
			//算插入位置
			while (terms[temp].expo > expo) {
				temp++;
			}
			//當指數相同要取代時
			if (terms[temp].expo == expo) {
				terms[temp].coef = terms[temp].coef + coef;
			}
			else {
				for (int i = MAX_TERMS - 1; i > temp; i--) {
					terms[i].coef = terms[i - 1].coef;
					terms[i].expo = terms[i - 1].expo;
				}
				terms[temp].coef = coef;
				terms[temp].expo = expo;
			}
		}
		/*
		int CurTerm = 0, LastTerm = MAX_TERMS;

		if (coef != 0) {
			while (terms[CurTerm].expo > expo)
				CurTerm++;

			if (terms[CurTerm].expo != expo) {
				while (LastTerm-- > CurTerm) {
					terms[LastTerm].expo = terms[LastTerm - 1].expo;
					terms[LastTerm].coef = terms[LastTerm - 1].coef;
				}
			}
			terms[CurTerm].expo = expo;
			terms[CurTerm].coef = coef;
		}*/
		return;
	}

	void printArrayBasedPoly()
	{
		for (int i = 0; i < MAX_TERMS; i++) {
			if (terms[i].coef == 0)
				return;

			if (terms[i].expo == 0)
				cout << " + " << terms[i].coef;
			else
				cout << " + " << terms[i].coef << "X^" << terms[i].expo;
		}

		return;
	}

	void ArrayBasedDifferentiation()
	{
		// add yor code here
		int temp = 0, lastTemp = MAX_TERMS;
		//當係數不為零時
		while (lastTemp--) {
			terms[temp].coef = terms[temp].coef * terms[temp].expo;
			terms[temp].expo -= 1;
			if (terms[temp].expo < 0) {
				terms[temp].coef = 0;
				terms[temp].expo = 0;
			}
			temp++;
		}
	}

	void removeArrayBasedTerm(int expo)
	{
		int temp = 0;

		while (terms[temp].coef != 0) {
			if (terms[temp].expo == expo) {
				if (temp == MAX_TERMS - 1) {
					terms[MAX_TERMS - 1].coef = 0;
					terms[MAX_TERMS - 1].expo = 0;
					break;
				}
				else {
					for (int i = temp; i < MAX_TERMS - 1; i++) {
					terms[i].coef = terms[i + 1].coef;
					terms[i].expo = terms[i + 1].expo;
					}
					terms[MAX_TERMS - 1].coef = 0;
					terms[MAX_TERMS - 1].expo = 0;
					break;
				}
			}
			temp++;
		}
	}
};

class LinkedPolynomialTerm {
public:
	int coef;
	int expo;
	LinkedPolynomialTerm *nextTermPtr;
};

class LinkedPolynomial {
public:
	LinkedPolynomialTerm *polynomialTermPtr = nullptr;

	void clear()
	{
		LinkedPolynomialTerm *tmpPtr;

		while (polynomialTermPtr != nullptr) {
			tmpPtr = polynomialTermPtr;
			polynomialTermPtr = polynomialTermPtr->nextTermPtr;
			delete tmpPtr;
		}

		return;
	}

	void inputLinkBasedTerms(int coef, int expo)
	{
		LinkedPolynomialTerm *tmpPtr;

		tmpPtr = new LinkedPolynomialTerm;
		tmpPtr->coef = coef;
		tmpPtr->expo = expo;
		tmpPtr->nextTermPtr = nullptr;

		//polynomialTermPtr = tmpPtr;


		// add your code here
		//如果係數不等於零
		if (coef != 0) {
			//如果現在是空的，直接加上去
			if (polynomialTermPtr == nullptr) {
				polynomialTermPtr = tmpPtr;
				polynomialTermPtr->nextTermPtr = nullptr;
			}
			else {
				//先創兩個指標紀錄，因為不能動到header
				LinkedPolynomialTerm* currPtr, * prePtr;
				currPtr = polynomialTermPtr;
				prePtr = nullptr;

				//找插入位置
				//當前指到的指數比較大就往下找，但若是已經到最後一個了(currPtr是nulptr)就停止
				while (currPtr != nullptr && currPtr->expo > expo) {
					prePtr = currPtr;
					currPtr = currPtr->nextTermPtr;
				}
				//如果是相同要相加，但要注意如果已經跑到最後了currPtr已經是nullptr了所以不能比較
				if(currPtr != nullptr && currPtr->expo == expo) {
					currPtr->coef += coef;
				}
				//如果要插在第一個
				else if (prePtr == nullptr) {
					tmpPtr->nextTermPtr = currPtr;
					polynomialTermPtr = tmpPtr;
				}
				else {
					tmpPtr->nextTermPtr = currPtr;
					prePtr->nextTermPtr = tmpPtr;
				}
			}
		}


		return;
	}

	void printLinkBasedPoly()
	{
		LinkedPolynomialTerm *termPtr = polynomialTermPtr;

		while (termPtr != nullptr) {
			if (termPtr->coef == 0)
				return;
			if (termPtr->expo == 0)
				cout << " + " << termPtr->coef;
			else
				cout << " + " << termPtr->coef << "X^" << termPtr->expo;

			termPtr = termPtr->nextTermPtr;
		}

		return;
	}

	void LinkBasedDifferentiation()
	{
		// add yor code here

		LinkedPolynomialTerm* currPtr, * prePtr;
		currPtr = polynomialTermPtr;
		prePtr = nullptr;

		//當現在指的不為空，就要繼續微分
		while (currPtr != nullptr) {
			//微分
			currPtr->coef *= currPtr->expo;
			currPtr->expo -= 1;

			//當微分完，係數為零代表是空值就要刪除(因為是指標)(不然可能會跑東西出來)
			if (currPtr->coef == 0) {
				//刪除要分兩種情況
				//第一種不是刪header，就直接讓prePtr他指著要刪除的下一個
				if (prePtr != nullptr) {
					prePtr->nextTermPtr = currPtr->nextTermPtr;
				}
				//第二種是刪header，就要讓我的polynomialTermPtr指著要刪除的下一個
				else {
					polynomialTermPtr = currPtr->nextTermPtr;
				}
			}
			prePtr = currPtr;
			currPtr = currPtr->nextTermPtr;
		}



	}

	void removeLinkBasedTerm(int expo)
	{
		// add yor code here
		LinkedPolynomialTerm* currPtr, * prePtr;
		currPtr = polynomialTermPtr;
		prePtr = nullptr;

		/*
		8->7->6	c = 8, p = null, Ptr = 8
			remove 7， 8->7->6 ----> 8->6		c = 7, p = 8, Ptr = 8
			remove 8 ----> 6		c = 8, p = null, Ptr = 6
			remove 6 ----> null		c = 6, p = null, Ptr = 0
		*/

		while (currPtr != nullptr) {
			if (currPtr->expo == expo) {
				//如果要刪掉的係數在頭
				if (prePtr == nullptr) {
					polynomialTermPtr = currPtr->nextTermPtr;
					//delete currPtr;
					break;
				}

				else {
					prePtr->nextTermPtr = currPtr->nextTermPtr;
					//delete currPtr;
					break;
				}
			}
			prePtr = currPtr;
			currPtr = currPtr->nextTermPtr;
		}

	}
};
