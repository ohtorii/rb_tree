// rb_tree.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include"rb_tree_input.h"

//
//VC2010�ŃR���p�C���ł��邱�Ƃ��m�F�B
//
//�����J����i���ꂩ��A�������悤�Ƃ��Ă��邩�������ˁj
#define private public
#define protected public
//#define class struct

#include<set>
#include<string>




typedef std::set<std::string>		set_string_type;
typedef std::multiset<std::string>	multiset_string_type;

static void usage(){
	printf(
		"rb_tree.exe mode\n"
		"mode   0   set<std::string>\n"
		"       1   multiset<std::string>\n"
	);
}

template<class _T> static int node_depth(_T first, _T last){
	int i =0;

	for(; first._Ptr!=last._Ptr; first._Ptr=first._Ptr->_Parent){
		++i;
	}
	//���[�g==1 �Ȃ̂Ō����Ă���
	--i;
	return i;
}

static void print_space(int n){
	while(0<n){
		printf("    ");
		--n;
	}
}

template<class _T> static void proc(){
	_T	t;

	while(! RB_IsEof()){
		char *buf = RB_GetCin();
		t.insert(std::string(buf));
		free(buf);
	}

#if 0
	{
		_T::const_iterator first = t.begin();
		_T::const_iterator last  = t.end();
		_T::const_iterator nil_node = t.end();

		for(; first!=last ; ++first){
			print_space(node_depth(first,nil_node));
			printf("[%s]%s\n", first._Ptr->_Color==set_string_type::_Black?"B":"R", first._Ptr->_Myval.c_str());
		}
	}
#else
	{
		//rb-tree�́uleft-most���ŉ��i�v�uright-most���ŏ�i�v�ɂ��邽�� reverse_iterator ���g�p�B
		_T::const_reverse_iterator	first = t.rbegin();
		_T::const_reverse_iterator	last  = t.rend();
		_T::const_iterator			nil_node = t.end();

		for(; first!=last ; ++first){
			//const_reverse_iterator �𔍂��Œ��g(const_iterator)�����o���B
			_T::const_reverse_iterator tmp = first;
			++tmp;
			_T::const_iterator cur = tmp.current;

			print_space(node_depth(cur,nil_node));
			printf("[%s]%s\n", cur._Ptr->_Color==set_string_type::_Black?"B":"R", cur._Ptr->_Myval.c_str());
		}
	}
#endif
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	if(argc!=2){
		usage();
		return 0;
	}
	
	if(0==atoi(argv[1])){
		proc<set_string_type>();
	}else{
		proc<multiset_string_type>();
	}
	
	return 0;
}

