/* cinから文字列を受け取る。

ヘッダをこじ開けた関係で<iostream>のビルドが通らなくなった。
別ファイルに分け回避。
*/

#include"rb_tree_input.h"
#include<iostream>
#include<string>
#include<memory>


bool  RB_IsEof(){
	return std::cin.eof();
}

char* RB_GetCin(){
	std::string tmp;
	std::cin >> tmp;
	char *buf = (char*)malloc((tmp.size()+1) * sizeof(std::string::value_type));
	strcpy(buf, tmp.c_str());
	return buf;
}
