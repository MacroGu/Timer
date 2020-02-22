/*
	author: Macro Gu
	email: macrogu@qq.com
	QQ: 877188891

*/

#pragma once


// 时间长度单位  毫秒 ms
#define TIME_LENGTH_PER_FRAME		30
#define TIME_LENGTH_PER_SECONDS		1000
#define TIME_LENGTH_PER_MINUTE	    60000
#define TIME_LENGTH_PER_HOUR		600000



// 定时器类型
enum class eTimerType : uint8_t {
	ONCE,			// 仅执行一次
	CIRCLE			// 循环执行
};