/* cin���當������󂯎��B

�w�b�_�������J�����֌W��<iostream>�̃r���h���ʂ�Ȃ��Ȃ����B
�ʃt�@�C���ɕ�������B
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
