#if 0
#include<stdio.h>

//C语言一个重要思想就是分别编译,若干个源程序在不同的时候单独进行编译,然后在恰当的时候整合到一起
//尽管连接器并不理解C语言,然而却能理解机器语言和内存布局
//编译器把C源程序翻译成对连接器有意义的形式,这样连接器就能读懂C源程序


extern int a;	//并不是对a的定义,说明了a是一个外部整形变量,包显示说明a的存储空间是在程序其他地方分配
//这是对外部变量的a的引用,而不是对a的定义
//如果int a;出现在两个或者更多的不同源文件中,则这个问题的答案与系统有关
//严格的规则是,每个外部变量只能定义一次,大多数系统会拒绝接受
//但如果一个外部变量在多个源文件定义却没有指定初始值,那么某些系统会接受这个程序
//如果避免这个问题,就是每个外部变量定义一次

//如果一个函数没有float short或者char类型的参数,在函数声明中晚全可以省略参数类型的说明
int isvowel(char);
//必须这么声明,否则将实参自动转换为int类型
int isvowel(char c) {
	return  c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

static int g(int x) {
	return x;
}

void f(int a) {
	int b = g(a);
	printf("%d\n", b);
}
//如果f需要调用g,而且只有函数f调用函数g,可以把函数f与函数g放到同一个源文件中,并声明g为static

int main() {
	static int a = 0;

	printf("%d\n", a);
	a = 10;
	f(a);

 
	return 0;
}
#endif