/*
 * inord_list.cpp
 *
 *  Created on: May 8, 2021
 *      Author: student
 */
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <vector>
#include <sstream>
#include "inord_list.h"
InOrderList::InOrderList()
{
	head = NULL;
	tail = NULL;
	current = NULL;
}
bool InOrderList::insert(const ListType& INword,const int& NOline)
{
	node* addedNode;
	node* pred;
	addedNode = new node; //step 1
	if (addedNode == NULL)
		return false;
	else {
		addedNode-> word = INword; //step 2
		addedNode->line = NOline;
		addedNode->count = 0;
		//step 3
		if (head == NULL || INword < head ->word)
		{

			addedNode->next = head;
			//step 4
			head = addedNode;
			return true;

		} // end of if condition
		else { //search for proper position
			pred = head;
			while (pred->next != NULL && pred->next->word <= INword)
			{
				pred = pred->next;
			}
			//step 3 (2nd case)
			addedNode->next = pred->next;
			//step 4 (2nd case)
			pred->next = addedNode;
			return true;

		}
	}
}
void InOrderList::repet()
{
	node* freq;
	node* repet;
	freq =head;
	while(freq!=NULL)
	{   repet=head;
	while((repet!=NULL))
	{
		if(freq->word==repet->word)
		{
			(freq->count)++;
		}
		repet=repet->next;
	}
	freq=freq->next;
	}
}
void InOrderList::show()
{    node* dis;
dis = head;

while(dis!=NULL)
{
	cout<<"line"<<dis->line<<" : "<<endl;
	cout<<dis->word<<endl;
	dis =  dis->next;

}

}
void InOrderList::wordCount()
{   int c=0;
node* wordc;
wordc = head;

while(wordc!=NULL)
{
	c++;
	wordc =  wordc->next;

}
cout<<c<<" words"<<endl;
}
void InOrderList::distWords()
{
	node* dist=head;
	string chek;
	string previous;
	int nodis=0;

	if(dist!=NULL)
	{
		nodis=1;

	}
	else
	{
		cout<<"no word";
	}
	previous=dist->word;
	dist=dist->next;
	while(dist!=NULL)
	{
	if(previous!=dist->word)
	{
		nodis++;

	}
	previous=dist->word;
	dist =  dist->next;

	}
	cout<<nodis<<" distinct words"<<endl;
}
void InOrderList::countWord(ListType& INword)
{
	int cw=0;
	string str=INword;
	node* coutw;
	coutw = head;
	for(unsigned int i=0;i<str.length();i++)
	{
		str[i]=tolower(str[i]);
	}
	while(coutw!=NULL)
	{
		if(coutw->word==str)
		{
			cw++;

		}
		//cout<<cw<<" , ";
		coutw =  coutw->next;
	}
	cout<<str<<" is repeated "<<cw<<" times"<<endl;
}
void InOrderList::frequentWord()
{ /*node* freq;
node* repet;
freq =head;
while(freq!=NULL)
{   repet=head;
while(repet!=NULL)
{
	if(freq->word==repet->word)
	{
		(freq->count)++;
	}
	repet=repet->next;
}
freq=freq->next;
}*/
string mostf;
int ff=0;
node* freqmost;
node* print;
print = head;
freqmost =head;
ff=freqmost->count;
mostf=print->word;
if(freqmost==NULL)
{
	cout<<"no word";
}
while(freqmost!=NULL)
{
	if(freqmost->count>=ff)
	{
		ff=freqmost->count;
		//cout<<ff<<" or ";
	}
	freqmost =  freqmost->next;
}
cout<<"Most frequent word is: ";
string previous;
if(print->count==ff)
{   if((mostf!="the"&&mostf!="a"&&mostf!="an"&&mostf!="of"&&mostf!="is"&&mostf!="are"&&mostf!="in"&&mostf!="on"&&mostf!="and"))
{
	cout<<mostf<<" ";
}
	previous=print->word;
	print=print->next;
}
while(print!=NULL)
{    mostf==print->word;
if(print->count==ff &&previous!=mostf)
{  mostf=print->word;
if((mostf!="the"&&mostf!="a"&&mostf!="an"&&mostf!="of"&&mostf!="is"&&mostf!="are"&&mostf!="in"&&mostf!="on"&&mostf!="and"))
{
	cout<<mostf<<" ";
}


}
previous=print->word;
print =  print->next;




}

cout<<endl;
}
void InOrderList::starting(ListType& INword)
{
	/*node* freq;
	node* repet;
	freq =head;
	while(freq!=NULL)
	{   repet=head;
	while(repet!=NULL)
	{
		if(freq->word==repet->word)
		{
			(freq->count)++;
		}
		repet=repet->next;
	}
	freq=freq->next;
	}*/
	node* start=head;
	string str=INword;
	for(unsigned int i=0;i<str.length();i++)
	{
		str[i]=tolower(str[i]);
	}
	string chek=start->word;
	string pervious;
	int test=0;
	size_t found = chek.find(str);
	if (found != string::npos&&found==0)
	{test=1;
	cout<<start->word<<":\t"<<start->count<<" ";

	}
	pervious=start->word;
	start=start->next;
	while(start!=NULL)
	{   chek=start->word;

	size_t found = chek.find(str);
	if (found != string::npos&&found==0&&(pervious!=chek))
	{test=1;
	cout<<start->word<<":\t"<<start->count<<" ";

	}
	pervious=start->word;
	start =  start->next;
	}

	if(test==0)
	{
		cout<<"Word not found";
	}

	cout<<endl;

}
void InOrderList::containing(ListType& INword)
{  /*node* freq;
node* repet;
freq =head;
while(freq!=NULL)
{   repet=head;
while(repet!=NULL)
{
	if(freq->word==repet->word)
	{
		(freq->count)++;
	}
	repet=repet->next;
}
freq=freq->next;
}*/
int test=0;
node* start=head;
string str=INword;
for(unsigned int i=0;i<str.length();i++)
{
	str[i]=tolower(str[i]);
}
string chek=start->word;
string pervious;

size_t found = chek.find(str);
if (found != string::npos)
{ test=1;
cout <<chek<<":\t"<<start->count<<" ";
}
pervious=start->word;
start=start->next;
while(start!=NULL)
{   chek=start->word;
size_t found = chek.find(str);
if(found != string::npos&&(chek!=pervious))
{    test=1;
cout <<chek<<":\t"<<start->count<<" ";
}
pervious=start->word;
start =  start->next;
}
if(test==0)cout<<"Word not found";
cout<<endl;
}
void InOrderList::search(ListType& INword)
{    int test=0;
node* start=head;
string str=INword;
for(unsigned int i=0;i<str.length();i++)
{
	str[i]=tolower(str[i]);
}
string chek=start->word;
string pervious;

std::size_t found1 = chek.find(str);
if (found1!=std::string::npos&&start!=NULL)
{ test=1;
  //cout<<"found1 : "<<found1<<endl;
cout <<start->word<<":\t"<<"lines "<<start->line<<" ";
}
pervious=start->word;
start=start->next;
while(start!=NULL)
{  chek=start->word;
std::size_t found2 = chek.find(str);;
if(found2!=std::string::npos&&(start->word==pervious))
{    test=1;
cout <<start->line<<" ";
}
else if(found2 != string::npos&&(start->word!=pervious))
{    test=1;
cout<<endl;
//cout<<"found2 : "<<found1<<endl;
cout <<start->word<<":\t"<<"lines "<<start->line<<" ";
}
pervious=start->word;
start =  start->next;
}
if(test==0)cout<<"Word not found";
cout<<endl;
}


