#include <iostream>
using namespace std;

/*
 * check a null terminated string, see if
 * being a valid utf-8 encoding.
 */
bool
is_valid_utf8_code (unsigned char* str)
{
	int len = 0;
	int tmp = 0;
	unsigned char* c = str;

	if (*c == '\0') {
		return false;
	}
	
	while (*c) {
		if ((*c & 0x80) == 0) {
			// ASCII. 0....
			len = 0;
		} else if ((*c & 0xe0) == 0xc0) {
			// 110....
			len = 1;
		} else if ((*c & 0xf0) == 0xe0) {
			// 1110....
			len = 2;
		} else if ((*c & 0xf8) == 0xf0) {
			// 11110....
			len = 3;
		} else {
			// anything else not valid.
			return false;
		}

		tmp = len;
		while (tmp > 0) {
			if ((*(c + tmp) & 0xc0) != 0x80) {
				// not 10 .....
				return false;
			}
			tmp--;
		}
		c += (len + 1);
	}
	return true;
}


int
main ()
{
	// add tests here.
	return 0;
}

