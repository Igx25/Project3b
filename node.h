#pragma once

#include <string>
#include <iostream>

class Val
{
public:
	Val() {type = NONE;}
	Val(int i) {type = INT;  ival = i;}
	Val(double d){type = DBL; dval = d;}
	Val(std::string &s) {type = STR;  sval = new std::string(s);}
	~Val() {if(type == STR) {delete sval;}}

	enum Type {NONE, INT, STR, DBL};
	
	Val(const Val &v)
	{
		if(v.GetType() == INT)
		{
			type = INT;
			ival = v.IVal();
		}
		else if(v.GetType() == STR)
		{
			type = STR;
			sval = new std::string(v.SVal());
		}
		else if(v.GetType() == DBL)
		{
			type = DBL;
			dval = v.DVal();
		}
	}

	Val &operator=(const Val &v)
	{
		if(type == STR) {delete sval;}

		if(v.GetType() == INT)
		{
			type = INT;
			ival = v.IVal();
		}
		else if(v.GetType() == STR)
		{
			type = STR;
			sval = new std::string(v.SVal());
		}
	}


	Type GetType() const {return type;}
	int IVal() const {return ival;}
	double DVal() const{return dval;}
	const std::string &SVal() const {return *sval;}

private:
	Type  type;
	union
	{
		std::string  *sval;
		int           ival;
		double        dval;
	};
};

class CNode
{
public:
	CNode(void) {}
	virtual ~CNode(void) {}

	virtual Val Evaluate() {
	return Val();}
};

class CNodeInt : public CNode
{
public:
	CNodeInt(int i) {val = i;}

	virtual Val Evaluate() {return Val(val);}

private:
	int val;
};

class CNodeDbl : public CNode
{
public:
	CNodeDbl(double i) {val = i;}

	virtual Val Evaluate() {return Val(val);}

private:
	double val;
};

class CNodeStr : public CNode
{
public:
	CNodeStr(const char *s) {val = s;}

	virtual Val Evaluate() {return Val(val);}

private:
	std::string val;
};

class CNodeAdd : public CNode
{
public:
	CNodeAdd(CNode *a, CNode *b) {pa = a;  pb = b;}

	virtual Val Evaluate()
	{	
		Val v = pa->Evaluate();
		Val z = pb->Evaluate();
		val = (v.DVal() + z.DVal());
		return (v.DVal() + z.DVal());
	}


private:
	CNode *pa;
	CNode *pb;
	double val;
};

class CNodeMul : public CNode
{
public:
	CNodeMul(CNode *a, CNode *b) {pa = a;  pb = b;}

	virtual Val Evaluate()
	{	
		Val v = pa->Evaluate();
		Val z = pb->Evaluate();
		val = (v.DVal() * z.DVal());
		return (v.DVal() * z.DVal());
	}


private:
	CNode *pa;
	CNode *pb;
	double val;
};

class CNodeFlicker : public CNode
{
public:
	CNodeFlicker(CNode *a, CNode *b) {pa = a;  pb = b;}

	virtual Val Evaluate()
	{
		for(int i=0;  i<5;  i++)
		{
			Print(pa);
			Print(pb);
		}

		std::cout << std::endl;

		return Val();
	}


private:
	void Print(CNode *n)
	{
		Val v = n->Evaluate();
		if(v.GetType() == Val::INT)
			std::cout << v.IVal() << " ";
		else if(v.GetType() == Val::STR)
			std::cout << v.SVal() << " ";
		else if(v.GetType() == Val::DBL)
			std::cout << v.DVal() << " ";
	}

	CNode *pa;
	CNode *pb;
};


class CNodeStmts : public CNode
{
public:
	CNodeStmts(CNode *a, CNode *b) {pa = a;  pb = b;}
	virtual ~CNodeStmts() {delete pa;  delete pb;}

	virtual Val Evaluate()
	{
		if(pa != NULL)
		{
			Val v = pa->Evaluate();	
		}
		if(pb != NULL)
		{
			Val z = pb->Evaluate();
			std::cout << "z.Dval: " << z.DVal()<< std::endl;	
		}
		
		return Val();
	}

private:
	CNode *pa;
	CNode *pb;
	
};
