#include"DirOp.h"
#include<iostream>
#include<cassert>
void test_dirop()
{
	DirOp dir_op("hello");
	assert(dir_op.Exists()==false);
	dir_op.Mkdir();
	assert(dir_op.Exists());
	dir_op.Rmdir();
	assert(dir_op.Exists()==false);
}
