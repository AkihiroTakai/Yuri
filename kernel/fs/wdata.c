#include "../../include/yrfs.h"
#include "../../include/bootpack.h"

/*
 *=======================================================================================
 *new_wrdata関数
 *新しくwritable_data構造体を確保する関数
 *=======================================================================================
 */
void new_wrdata(struct writable_data *data, u32_t size) {
	data->size = size;
	data->data = (u32_t *)memory_alloc(memman, size * sizeof(u32_t));
}


/*
 *=======================================================================================
 *delete_wrdata関数
 *writable_data構造体を開放する関数
 *=======================================================================================
 */
void delete_wrdata(struct writable_data *data) {
	memory_free(memman, (u32_t)data->data, data->size * sizeof(u32_t));
}

/*
 *=======================================================================================
 *u32to4char関数
 *unsigned intの中に入った4つの文字列を取り出す関数
 *=======================================================================================
 */
void u32to4char(u32_t data, char *buffer) {
	*buffer = (char)data;
	buffer++;
	*buffer = (char)(data >> 8);
	buffer++;
	*buffer = (char)(data >> 16);
	buffer++;
	*buffer = (char)(data >> 24);
}

/*
 *=======================================================================================
 *char4tou32関数
 *unsigned intの中に入った4つの文字列を取り出す関数
 *=======================================================================================
 */
void char4tou32(char *data, u32_t *u32) {
      *u32 =
		(u32_t)data[0]         |
		(u32_t)(data[1] <<  8) |
		(u32_t)(data[2] << 16) |
		(u32_t)(data[3] << 24);
}
