#include "../../include/yrfs.h"
#include "../../include/sh.h"

int do_open(char *pathname, u32_t flags) {

	int fd = 0;
	struct i_node inode;
	
	if(flags & __O_CREAT__){
		/*
		 *inode作成
		 */
		inode = icreat(pathname);
		/*
		 *inodeを補助記憶装置に書き出し
		 */
		fd = iwrite(&inode);
	}else if(flags & __O_RDONLY__){
		
	}

	return fd;
}
