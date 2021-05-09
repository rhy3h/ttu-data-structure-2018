/*�@�Aarray-based polynomials
    1. inputArrayBasedTerms()
        �Ϩ�i�H���ݫ��ӭ��������ǿ�J�Y��
        �o�|�����������Ǧs�J
        �Y�ۦP���������п�J�A�h�N�Y�Ƭۥ[
    2. ArrayBasedDifferentiation()
        2x^2 + 1x^1 => 4x^1 + 1
        �N�h�����L��
    3. removeArrayBasedTerm()
        �N��J����������

�G�Alink-based polynomials
    1. inputLinkBasedTerms
        �Ϩ�i�H���ݫ��ӭ��������ǿ�J�Y��
        �o�|�����������Ǧs�J
        �Y�ۦP���������п�J�A�h�N�Y�Ƭۥ[
    2. LinkBasedDifferentiation()
        2x^2 + 1x^1 => 4x^1 + 1
        �N�h�����L��
    3. removeLinkBasedTerm()
        �N��J����������*/

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

		//��Y�Ƥ����s
		if (coef != 0) {
			//�ⴡ�J��m
			while (terms[temp].expo > expo) {
				temp++;
			}
			//����ƬۦP�n���N��
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
		//��Y�Ƥ����s��
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
		//�p�G�Y�Ƥ�����s
		if (coef != 0) {
			//�p�G�{�b�O�Ū��A�����[�W�h
			if (polynomialTermPtr == nullptr) {
				polynomialTermPtr = tmpPtr;
				polynomialTermPtr->nextTermPtr = nullptr;
			}
			else {
				//���Ш�ӫ��Ь����A�]������ʨ�header
				LinkedPolynomialTerm* currPtr, * prePtr;
				currPtr = polynomialTermPtr;
				prePtr = nullptr;

				//�䴡�J��m
				//��e���쪺���Ƥ���j�N���U��A���Y�O�w�g��̫�@�ӤF(currPtr�Onulptr)�N����
				while (currPtr != nullptr && currPtr->expo > expo) {
					prePtr = currPtr;
					currPtr = currPtr->nextTermPtr;
				}
				//�p�G�O�ۦP�n�ۥ[�A���n�`�N�p�G�w�g�]��̫�FcurrPtr�w�g�Onullptr�F�ҥH������
				if(currPtr != nullptr && currPtr->expo == expo) {
					currPtr->coef += coef;
				}
				//�p�G�n���b�Ĥ@��
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

		//��{�b���������šA�N�n�~��L��
		while (currPtr != nullptr) {
			//�L��
			currPtr->coef *= currPtr->expo;
			currPtr->expo -= 1;

			//��L�����A�Y�Ƭ��s�N��O�ŭȴN�n�R��(�]���O����)(���M�i��|�]�F��X��)
			if (currPtr->coef == 0) {
				//�R���n����ر��p
				//�Ĥ@�ؤ��O�Rheader�A�N������prePtr�L���ۭn�R�����U�@��
				if (prePtr != nullptr) {
					prePtr->nextTermPtr = currPtr->nextTermPtr;
				}
				//�ĤG�جO�Rheader�A�N�n���ڪ�polynomialTermPtr���ۭn�R�����U�@��
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
			remove 7�A 8->7->6 ----> 8->6		c = 7, p = 8, Ptr = 8
			remove 8 ----> 6		c = 8, p = null, Ptr = 6
			remove 6 ----> null		c = 6, p = null, Ptr = 0
		*/

		while (currPtr != nullptr) {
			if (currPtr->expo == expo) {
				//�p�G�n�R�����Y�Ʀb�Y
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
