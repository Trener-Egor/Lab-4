#pragma once
#include<iostream>
#include<string>
class student
{
private:
	std::string f;
	std::string i;
	std::string o;
	std::string grp;
	int id;
	int marks[4];
public:
	student(const std::string& f, const std::string& i, const std::string& o, const std::string& grp, int id)
	{
		this->f = f;
		this->i = i;
		this->o = o;
		this->grp = grp;
		this->id = id;
		for (int i = 0; i < 4; ++i) {
			marks[i] = 0;
		}
		
	}
	//copy ctr
	//move ctr
	std::string get_f()const
	{
		return f;
	}
	std::string get_i()const
	{
		return i;
	}
	std::string get_o()const
	{
		return o;
	}
	std::string get_grp()const
	{
		return grp;
	}
	int get_id()const
	{
		return id;
	}
	const int get_mark(int idx)const
	{
		return marks[idx];
	}
	const int* get_marks()const
	{
		return marks;
	}
	const int& operator[](int idx)const
	{
		return marks[idx];
	}

	void set_f(const std::string& f)
	{
		this->f = f;
	}
	void set_i(const std::string& i)
	{
		this->i = i;
	}
	void set_o(const std::string& o)
	{
		this->o = o;
	}
	void set_grp(const std::string& grp)
	{
		this->grp = grp;
	}
	void set_id(const int& id)
	{
		this->id = id;
	}
	void set_marks(int* marks )
	{
		for (int i = 0; i < 4; ++i) {
			this->marks[i] = marks[i];
		}
	}
	void set_mark(int idx,int mark)
	{
		this->marks[idx] = mark;
	}

	bool operator<  (const student& other)
	{
		double gpa = 0;
		double ogpa = 0;
		for(int i = 0; i<4 ;i++)
		{
			//gpa += this->get_marks()[i];
			gpa += this->get_mark(i);
			ogpa += other.get_mark(i);
			//gpa += (*this)[i];
		}
		gpa /= 4.0;
		ogpa /= 4.0;
		return gpa > ogpa;
	}
	friend std::ostream& operator<<(std::ostream& out,const student& a)
	{
		out << "[" << a.id << "] " << a.f << ' ' << a.i << ' ' << a.o << ": "<< a.marks[0] << ", " << a.marks[1] << ", " << a.marks[2] << ", " << a.marks[3] << "\n";
		return out;
	}
};
