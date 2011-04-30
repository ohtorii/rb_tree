// rb_tree.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"


//
//VC2010�ŃR���p�C���ł��邱�Ƃ��m�F�B
//
//�����J����i���ꂩ��A�������悤�Ƃ��Ă��邩�������ˁj
#define private public
#define protected public
//#define class struct
#include<set>
#include<string>



typedef std::set<std::string>	set_string_type;

static int node_depth(set_string_type::const_iterator first, set_string_type::const_iterator last){
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

int _tmain(int argc, _TCHAR* argv[])
{
	set_string_type	t;
	for(int i=1 ; i<argc ; ++i){
		t.insert(argv[i]);
	}

	{
		//rb-tree�́uleft-most���ŉ��i�v�uright-most���ŏ�i�v�ɂ��邽�� reverse_iterator ���g�p�B
		set_string_type::const_reverse_iterator first = t.rbegin();
		set_string_type::const_reverse_iterator last  = t.rend();
		set_string_type::const_iterator			nil_node = t.end();

		for(; first!=last ; ++first){
			//const_reverse_iterator �𔍂��Œ��g(const_iterator)�����o���B
			set_string_type::const_reverse_iterator tmp = first;
			++tmp;
			set_string_type::const_iterator cur = tmp.current;

			print_space(node_depth(cur,nil_node));
			printf("[%s]%s\n", cur._Ptr->_Color==set_string_type::_Red?"R":"B", cur._Ptr->_Myval.c_str());
		}
	}
	return 0;
}

