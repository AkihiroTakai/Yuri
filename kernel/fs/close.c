#include "../../include/yrfs.h"

/*
 *=======================================================================================
 *do_close関数
 *closeシステムコールの中身
 *=======================================================================================
 */
i32_t do_close(i32_t fd) {
	struct i_node inode;

	/*
	 *inode情報を取得
	 */
	iread(&inode, fd);

	/*
	 *オフセットを初期化
	 */
	inode.seek_address.offset = 0;
	inode.seek_address.sector = 0;

	/*
	 *新しいデータを書き込み
	 */
	iwrite(&inode);

	return 0;
}
