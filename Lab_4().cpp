#include <iostream>
#include <deque>
#include <list>
#include <fstream>
#include <algorithm>

#include"Students.h"


void read_from_file(const std::string& file_name,std::deque<student>& deq )
{
	std::ifstream file(file_name);

	if(!file.is_open())
	{
		std::cout << "file didnt open\n";
		return;
	}

	while(!file.eof())
	{
		std::string grp;
		std::string f;
		std::string i;
		std::string o;
		int id;
		int arr[4];
		file >> grp >> id >> f >> i >> o >> arr[0] >> arr[1] >> arr[2] >> arr[3];

		student newstudent(f, i, o, grp, id);
		newstudent.set_marks(arr);

		deq.push_back(newstudent);
	}
	file.close();
}

int main()
{	
	std::string fname = "input.txt";
	std::deque<student> deq_st;

	read_from_file(fname, deq_st);

	if(deq_st.empty())
	{	
		std::cout << "deque is empty\n";
		return 0;
	}
	std::ofstream file("output.txt");

	if (!file.is_open()) 
	{	
		std::cout << "file error\n";
		return 0; 
	}

	for(std::deque<student>::iterator it_b = deq_st.begin(),
		                              it_e = deq_st.end(); it_b != it_e;++it_b)
	{
		file << *it_b;
	}
	file << "\nsort deque:\n";

	std::sort(deq_st.begin(), deq_st.end());
	 
	file << "\nafter deque:\n";

	for (std::deque<student>::iterator it_b = deq_st.begin(),
		                               it_e = deq_st.end(); it_b != it_e; ++it_b)
	{
		file << *it_b;
	}
	std::list<student> lst;

	for (std::deque<student>::iterator it_b = deq_st.begin(),
		                               it_e = deq_st.end(); it_b != it_e; ++it_b)
	{
		lst.push_back(*it_b);
	}
	file << "\nprint list:\n";


	for (std::list<student>::iterator it_b = lst.begin(),
									  it_e = lst.end(); it_b != it_e; ++it_b)
	{
		file << *it_b;
	}
	file << "\ncopy list std::copy:\n";
	
	std::list<student>  newlst;
	std::copy(deq_st.begin(), deq_st.end(), std::back_inserter(newlst));
	
	file << "\ncopy list print:\n";

	for (std::list<student>::iterator it_b = newlst.begin(),
									  it_e = newlst.end(); it_b != it_e; ++it_b)
	{
		file << *it_b;
	}
}
//iomanip std::setw(x) 
/*категория значений
*                                   expression
*               glvalue										 rvalue
*	  lvalue						  xvalue			 	              prvalue
* 
* glvalue-generalized lvalue-представляет собой выражение,вычисление которого определяет идентичность объекта или функции
* сущности имеющей storage
* prvalue-pure value-выражение вычисление которого инициализирует объект(или битовое поле)или вычисляет значение операнда оператора
* пример:
* foo(std::string("hello")){}        foo(const std::string& s){}        
* int v =5;  f(v);        f(3+2);    f(int arg)
* xvalue-объект или битовое поле ресурсы которого могут быть повторно использованы (обычно из-за того что вскоре исчезает его время жизни)
* std::string str = "abc"
* foo(std::move(str))
* lvalue- представляет собой glvalue не являющейся xvalue
* rvalue- представляет собой либо prvalue либо xvalue
*/