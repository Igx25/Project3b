#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

void *createNodeInt(int n);
void *createNodeDbl(double n);
void *createNodeStr(const char *s);
void *createNodeFlicker(void *a, void *b);
void *createNodeStmts(void *a, void *b);
void *createNodeAdd(void *a, void *b);
void *createNodeMul(void *a, void *b);
void setRoot(void *a);

#endif
