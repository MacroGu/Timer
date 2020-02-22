/*
	author: Macro Gu
	email: macrogu@qq.com
	QQ: 877188891

*/

#pragma once


// ʱ�䳤�ȵ�λ  ���� ms
#define TIME_LENGTH_PER_FRAME		30
#define TIME_LENGTH_PER_SECONDS		1000
#define TIME_LENGTH_PER_MINUTE	    60000
#define TIME_LENGTH_PER_HOUR		600000



// ��ʱ������
enum class eTimerType : uint8_t {
	ONCE,			// ��ִ��һ��
	CIRCLE			// ѭ��ִ��
};