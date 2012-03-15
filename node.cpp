#include "node.h"

extern "C" {
#include "functions.h"
}

extern "C" void *createNodeInt(int n)
{
	CNodeInt *node = new CNodeInt(n);
	return node;
}

extern "C" void *createNodeDbl(double n)
{
	CNodeDbl *node = new CNodeDbl(n);
	return node;
}

extern "C" void *createNodeStr(const char *s)
{
	CNodeStr *node = new CNodeStr(s);
	return node;
}

extern "C" void *createNodeFlicker(void *a, void *b)
{
	CNodeFlicker *node = new CNodeFlicker((CNode *)a, (CNode *)b);
	return node;
}

extern "C" void *createNodeAdd(void *a, void *b)
{
	CNodeAdd *node = new CNodeAdd((CNode *)a, (CNode *)b);
	return node;
}

extern "C" void *createNodeMul(void *a, void *b)
{
	CNodeMul *node = new CNodeMul((CNode *)a, (CNode *)b);
	return node;
}

extern "C" void *createNodeStmts(void *a, void *b)
{
	CNodeStmts *node = new CNodeStmts((CNode *)a, (CNode *)b);
	return node;
}

CNode *g_root = NULL;

extern "C" void setRoot(void *a)
{
	g_root = (CNode *)a;
}

void Execute()
{
	if(g_root != NULL)
		g_root->Evaluate();
}
