#include "../../include/kernel.h"
#include "../../include/yrws.h"

/*
 *=======================================================================================
 *draw_window関数
 *ウィンドウを描画する関数
 *=======================================================================================
 */
struct Layer *draw_window(i16_t start_x, i16_t start_y, i16_t width, i16_t height){
      struct Layer *window = layer_alloc(Yrws_Master.LAYER_MASTER);
      u8_t *window_buf = (u8_t *)memory_alloc_4k(memman, width * height);
      layer_chbuf(window, window_buf);
      modify_layer(window, width, height, 255);

      boxfill8(window->data, width, __RGB256COL__(36, 49, 61), 0, 0, width-48, 16);
      boxfill8(window->data, width, __RGB256COL__(196, 199, 255), width-48, 0, width-32, 16);
      boxfill8(window->data, width, __RGB256COL__(232, 255, 148), width-32, 0, width-16, 16);
      boxfill8(window->data, width, __RGB256COL__(255, 226, 220), width-16, 0, width-1, 16);
      boxfill8(window->data, width, __RGB256COL__(255, 255, 255), 0, 16, width, height);

      move_layer(Yrws_Master.LAYER_MASTER, window, start_x, start_y);
      layer_ch_position(Yrws_Master.LAYER_MASTER, window, 1);

	puttext(window, "YURI OS window!!", 20, 20, __RGB256COL__(0, 0, 0));

      window->flags |= __WINDOW_LAYER__;

      redraw_all_layer(Yrws_Master.LAYER_MASTER, window, 0, 0, binfo->scrny, binfo->scrny);

	return window;
}