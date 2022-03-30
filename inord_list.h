/*
 * inord_list.h
 *
 *  Created on: May 8, 2021
 *      Author: student
 */

#ifndef INORD_LIST_H_
#define INORD_LIST_H_
#include <string>
using namespace std;
#define ListType string
class InOrderList
{
public :
	InOrderList();
	bool insert(const ListType& INword,const int& NOline);
	void show();
	void repet();
	void wordCount();
	void distWords();
	void frequentWord();
	void deleteword(ListType& INword);
	void countline(ListType& INword);
	void countWord(ListType& INword);
	void starting(ListType& INword);
	void containing(ListType& INword);
	void search(ListType& INword);





private :
struct node
{
	string word;
	int line;
	int count;
	node* next;
};
node* head;
node* current;
node* tail;


};























#endif /* INORD_LIST_H_ */
