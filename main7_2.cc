#include "p7.h"
int main()
{
	EZ_CURVE_FIT C(5);
	C.LS_FIT_BY_MATLAB("in_7_2");
	return 0;
}
