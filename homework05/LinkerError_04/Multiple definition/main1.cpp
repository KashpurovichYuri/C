#include "LinkerError1.h"
#include <iostream>

int main()
{
}

/*

	Ошибка multiple definition:
	C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/12.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: C:\Users\USER-S~1\AppData\Local\Temp\ccQKgeLN.o:LinkerError_ODR1.cpp:(.bss+0x0): multiple definition of `g_x'; C:\Users\USER-S~1\AppData\Local\Temp\ccB6Nv8o.o:main.cpp:(.bss+0x0): first defined here
collect2.exe: error: ld returned 1 exit status

	Предположим, что нам необходимо использовать какие-либо объявления из header file "LinkerError1.h" в файле main.cpp.
	Если в заголовке "LinkerError1.h" будет указано, что где-то определена глобальная переменная g_x (с внешним связыванием, поскольку неконстантные глобальные переменные имеют внешнее связывание по умолчанию), то по отдельности файлы main.cpp и LinkerError_ODR1.cpp будут компилироваться.
	Но если будет рассматриваться этап линковки, то окажется, что глобальная переменная g_x определена и в main.cpp, и в LinkerError_ODR1.cpp

	Рассмотрим подробнее, почему это происходит.
	Когда LinkerError1.h включается из LinkerError_ODR1.cpp, #pragma once действует до конца LinkerError_ODR1.cpp.
	Эта директива предотвращает повторное включение LinkerError1.h (если бы мы попытались его написать) в LinkerError_ODR1.cpp (что является целью защиты заголовков).
	Однако после завершения работы LinkerError_ODR1.cpp директива #pragma once прекращает действовать.
	Это означает, что когда препроцессор работает на main.cpp, #pragma once вновь допустит включение заголовка LinkerError1.h в main.cpp.
	Конечным результатом является то, что и LinkerError_ODR1.cpp, и main.cpp получают копию определения g_x. Эта программа скомпилируется, но компоновщик будет жаловаться на то, что она имеет несколько определений для идентификатора g_x.

	Решение:
	В данном случае достаточно добавить ключевое слово extern перед определением глобальной переменной g_x. Тогда она будет просто объявляться, что и должно происходить в заголовочных файлах.
	
*/