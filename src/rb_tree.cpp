// rb_tree.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"


//
//VC2010でコンパイルできることを確認。
//
//こじ開ける（これから、何をしようとしているか分かるよね）
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
	//ルート==1 なので減じておく
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
		//rb-treeの「left-mostを最下段」「right-mostを最上段」にするため reverse_iterator を使用。
		set_string_type::const_reverse_iterator first = t.rbegin();
		set_string_type::const_reverse_iterator last  = t.rend();
		set_string_type::const_iterator			nil_node = t.end();

		for(; first!=last ; ++first){
			//const_reverse_iterator を剥いで中身(const_iterator)を取り出す。
			set_string_type::const_reverse_iterator tmp = first;
			++tmp;
			set_string_type::const_iterator cur = tmp.current;

			print_space(node_depth(cur,nil_node));
			printf("[%s]%s\n", cur._Ptr->_Color==set_string_type::_Red?"R":"B", cur._Ptr->_Myval.c_str());
		}
	}
	return 0;
}

