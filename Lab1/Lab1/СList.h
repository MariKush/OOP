#pragma once

#include <string>

using std::string;

struct  NodeS
{
	string s;
	NodeS *Next;
};

class ÑList
{
	int kol;

	NodeS *beg;
	NodeS *end;

public:
	ÑList() {
		kol = 0;
		beg = NULL;
		end = NULL;
	}            
	~ÑList() {
		while (kol != 0)                        
		{
			NodeS *temp = beg->Next;
			delete beg;                         
			beg = temp;                         
			kol--;                                
		}
	}

    
	//size of the CList
	int size() {
		return kol;
	}

	void Add(string x) {
		kol++;                           
		NodeS  *temp = new NodeS;        
		temp->Next = beg;                
		temp->s = x;                     

		if (beg != NULL)                 
		{
			end->Next = temp;            
			end = temp;                  
		}
		else beg = end = temp;              
	}

	string Shift(int sh) {
		NodeS *temp = beg;
		for (int i = 0; i < sh; i++)
		{
			temp = temp->Next;
		}
		return temp->s;
	}

	//void Show(int kol)
	//{
	//	NodeS *temp = beg;                              
	//
	//	int temp = kol;                                 
	//	while (temp != 0)                               
	//	{
	//		//std:: cout << temp->s << " ";             
	//		temp = temp->Next;                          
	//		temp--;                                     
	//	}
	//}
		
};
