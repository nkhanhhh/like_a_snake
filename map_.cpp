#include "map_.h"
#include "main_include.h"

void create_map() {
	for (int i = 0; i <= max_x ; i += 20) {
		for (int j = 0; j <= max_y - 80; j += 20) {
			if (i == 0 || i == max_x - 20 || j == 0 || j == max_y - 80) {
				wall[size_wall] = { i , j , 40 , 40 };
				size_wall++;
			}
		}
	}
}