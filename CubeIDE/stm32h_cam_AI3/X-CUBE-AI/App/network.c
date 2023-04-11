/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Apr 11 10:48:22 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network.h"
#include "network_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "fe98b3bbf94fd053307e1960ba147c41"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Tue Apr 11 10:48:22 2023"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

static ai_ptr g_network_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_network_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  block_2_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  block_2_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)
/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  block_2_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  block_3_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)
/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  block_3_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  block_3_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 432, AI_STATIC)
/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  block_3_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  block_3_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)
/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  block_3_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)
/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  block_4_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)
/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  block_4_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  block_4_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)
/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  block_4_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  block_4_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)
/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  block_4_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)
/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  block_5_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)
/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  block_5_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  block_5_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)
/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  block_5_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  block_5_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)
/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  block_5_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)
/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  block_6_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)
/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  block_6_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  block_6_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 864, AI_STATIC)
/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  block_6_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  block_6_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2304, AI_STATIC)
/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  block_6_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)
/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  block_7_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)
/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  block_7_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)
/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  block_7_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1296, AI_STATIC)
/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  block_7_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)
/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  block_7_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)
/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  block_7_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)
/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  block_8_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)
/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  block_8_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)
/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  block_8_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1296, AI_STATIC)
/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  block_8_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)
/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  block_8_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)
/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  block_8_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)
/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  block_9_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)
/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  input_0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 3072, AI_STATIC)
/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  block_9_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)
/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  Conv1_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)
/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  expanded_conv_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)
/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  block_9_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1296, AI_STATIC)
/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  expanded_conv_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)
/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  block_1_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12288, AI_STATIC)
/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  block_9_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)
/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  block_1_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)
/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  block_1_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)
/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  block_9_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)
/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  block_2_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)
/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  block_2_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)
/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  block_9_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 24, AI_STATIC)
/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  block_2_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)
/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  block_2_add_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)
/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  block_10_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3456, AI_STATIC)
/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  block_3_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)
/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  block_3_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)
/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  block_10_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)
/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  block_3_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)
/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  block_4_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)
/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  block_10_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1296, AI_STATIC)
/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  block_4_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)
/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  block_4_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)
/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  block_10_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)
/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  block_4_add_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)
/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  block_5_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)
/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  block_10_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4608, AI_STATIC)
/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  block_5_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)
/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  block_5_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)
/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  block_10_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)
/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  block_5_add_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)
/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  block_6_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1536, AI_STATIC)
/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  block_11_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6144, AI_STATIC)
/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  block_6_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)
/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  block_6_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  block_11_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)
/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  block_7_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 576, AI_STATIC)
/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  block_7_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 576, AI_STATIC)
/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  block_11_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1728, AI_STATIC)
/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  block_7_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  block_7_add_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  block_11_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)
/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  block_8_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 576, AI_STATIC)
/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  block_8_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 576, AI_STATIC)
/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  block_11_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6144, AI_STATIC)
/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  block_8_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  block_8_add_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  block_11_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)
/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  block_9_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 576, AI_STATIC)
/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  block_9_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 576, AI_STATIC)
/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  block_12_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6144, AI_STATIC)
/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  block_9_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  block_9_add_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)
/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  block_12_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)
/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  block_10_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 576, AI_STATIC)
/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  block_10_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 576, AI_STATIC)
/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  block_12_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1728, AI_STATIC)
/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  block_10_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  block_11_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)
/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  block_12_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)
/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  block_11_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)
/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  block_11_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  block_12_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6144, AI_STATIC)
/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  block_11_add_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  block_12_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)
/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  block_12_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)
/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  block_12_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)
/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  block_12_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  block_13_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6144, AI_STATIC)
/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  block_12_add_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  block_13_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 768, AI_STATIC)
/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  block_13_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)
/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  block_13_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)
/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  block_13_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)
/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  block_13_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1728, AI_STATIC)
/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  block_14_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)
/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  block_14_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)
/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  block_13_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)
/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  block_14_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)
/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  block_14_add_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)
/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  block_13_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10752, AI_STATIC)
/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  block_15_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)
/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  block_15_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)
/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  block_13_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)
/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  block_15_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)
/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  block_15_add_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)
/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  block_14_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18816, AI_STATIC)
/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  block_16_expand_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)
/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  block_16_depthwise_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)
/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  block_14_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)
/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  block_16_project_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 112, AI_STATIC)
/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  Conv_1_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1280, AI_STATIC)
/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  block_14_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3024, AI_STATIC)
/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  dense_dense_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  dense_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  block_14_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)
/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_dense_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)
/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 10, AI_STATIC)
/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  block_14_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18816, AI_STATIC)
/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  block_14_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)
/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  block_15_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18816, AI_STATIC)
/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  block_15_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)
/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  block_15_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3024, AI_STATIC)
/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  block_15_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)
/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  block_15_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18816, AI_STATIC)
/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  block_15_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 56, AI_STATIC)
/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  block_16_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18816, AI_STATIC)
/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  block_16_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)
/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  block_16_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3024, AI_STATIC)
/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  block_16_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 336, AI_STATIC)
/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  block_16_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 37632, AI_STATIC)
/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  block_16_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 112, AI_STATIC)
/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  Conv_1_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 143360, AI_STATIC)
/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  Conv_1_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1280, AI_STATIC)
/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  dense_dense_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10240, AI_STATIC)
/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  dense_dense_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_dense_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 80, AI_STATIC)
/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_dense_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)
/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  Conv1_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 432, AI_STATIC)
/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  Conv1_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)
/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  expanded_conv_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)
/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  expanded_conv_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)
/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  expanded_conv_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  expanded_conv_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  block_1_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)
/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  block_1_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  block_1_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 432, AI_STATIC)
/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  block_1_depthwise_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  block_1_project_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)
/* Array#171 */
AI_ARRAY_OBJ_DECLARE(
  block_1_project_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#172 */
AI_ARRAY_OBJ_DECLARE(
  block_2_expand_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)
/* Array#173 */
AI_ARRAY_OBJ_DECLARE(
  block_2_expand_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#174 */
AI_ARRAY_OBJ_DECLARE(
  block_2_depthwise_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 432, AI_STATIC)
/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  block_2_depthwise_conv2d_bias, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &block_2_depthwise_conv2d_bias_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  block_2_project_conv2d_weights, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 4, 192, 192, 192),
  1, &block_2_project_conv2d_weights_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  block_2_project_conv2d_bias, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &block_2_project_conv2d_bias_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  block_3_expand_conv2d_weights, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &block_3_expand_conv2d_weights_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  block_3_expand_conv2d_bias, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &block_3_expand_conv2d_bias_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  block_3_depthwise_conv2d_weights, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 48), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_3_depthwise_conv2d_weights_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  block_3_depthwise_conv2d_bias, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &block_3_depthwise_conv2d_bias_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  block_3_project_conv2d_weights, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 16), AI_STRIDE_INIT(4, 4, 192, 192, 192),
  1, &block_3_project_conv2d_weights_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  block_3_project_conv2d_bias, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &block_3_project_conv2d_bias_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  block_4_expand_conv2d_weights, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 4, 64, 64, 64),
  1, &block_4_expand_conv2d_weights_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  block_4_expand_conv2d_bias, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &block_4_expand_conv2d_bias_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  block_4_depthwise_conv2d_weights, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 96), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_4_depthwise_conv2d_weights_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  block_4_depthwise_conv2d_bias, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &block_4_depthwise_conv2d_bias_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  block_4_project_conv2d_weights, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 4, 384, 384, 384),
  1, &block_4_project_conv2d_weights_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  block_4_project_conv2d_bias, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &block_4_project_conv2d_bias_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  block_5_expand_conv2d_weights, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 4, 64, 64, 64),
  1, &block_5_expand_conv2d_weights_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  block_5_expand_conv2d_bias, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &block_5_expand_conv2d_bias_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  block_5_depthwise_conv2d_weights, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 96), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_5_depthwise_conv2d_weights_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  block_5_depthwise_conv2d_bias, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &block_5_depthwise_conv2d_bias_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  block_5_project_conv2d_weights, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 4, 384, 384, 384),
  1, &block_5_project_conv2d_weights_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  block_5_project_conv2d_bias, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &block_5_project_conv2d_bias_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  block_6_expand_conv2d_weights, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 4, 64, 64, 64),
  1, &block_6_expand_conv2d_weights_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  block_6_expand_conv2d_bias, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &block_6_expand_conv2d_bias_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  block_6_depthwise_conv2d_weights, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 96), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_6_depthwise_conv2d_weights_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  block_6_depthwise_conv2d_bias, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &block_6_depthwise_conv2d_bias_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  block_6_project_conv2d_weights, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 4, 384, 384, 384),
  1, &block_6_project_conv2d_weights_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  block_6_project_conv2d_bias, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &block_6_project_conv2d_bias_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  block_7_expand_conv2d_weights, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 4, 96, 96, 96),
  1, &block_7_expand_conv2d_weights_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  block_7_expand_conv2d_bias, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &block_7_expand_conv2d_bias_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  block_7_depthwise_conv2d_weights, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 144), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_7_depthwise_conv2d_weights_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  block_7_depthwise_conv2d_bias, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &block_7_depthwise_conv2d_bias_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  block_7_project_conv2d_weights, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 4, 576, 576, 576),
  1, &block_7_project_conv2d_weights_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  block_7_project_conv2d_bias, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &block_7_project_conv2d_bias_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  block_8_expand_conv2d_weights, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 4, 96, 96, 96),
  1, &block_8_expand_conv2d_weights_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  block_8_expand_conv2d_bias, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &block_8_expand_conv2d_bias_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  block_8_depthwise_conv2d_weights, AI_STATIC,
  35, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 144), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_8_depthwise_conv2d_weights_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  block_8_depthwise_conv2d_bias, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &block_8_depthwise_conv2d_bias_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  block_8_project_conv2d_weights, AI_STATIC,
  37, 0x0,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 4, 576, 576, 576),
  1, &block_8_project_conv2d_weights_array, NULL)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  block_8_project_conv2d_bias, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &block_8_project_conv2d_bias_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  block_9_expand_conv2d_weights, AI_STATIC,
  39, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 4, 96, 96, 96),
  1, &block_9_expand_conv2d_weights_array, NULL)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  input_0_output, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 32, 32), AI_STRIDE_INIT(4, 4, 4, 12, 384),
  1, &input_0_output_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  block_9_expand_conv2d_bias, AI_STATIC,
  41, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &block_9_expand_conv2d_bias_array, NULL)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  Conv1_conv2d_output, AI_STATIC,
  42, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &Conv1_conv2d_output_array, NULL)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  expanded_conv_depthwise_conv2d_output, AI_STATIC,
  43, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 4, 4, 64, 1024),
  1, &expanded_conv_depthwise_conv2d_output_array, NULL)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  block_9_depthwise_conv2d_weights, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 144), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_9_depthwise_conv2d_weights_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  expanded_conv_project_conv2d_output, AI_STATIC,
  45, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 16, 16), AI_STRIDE_INIT(4, 4, 4, 32, 512),
  1, &expanded_conv_project_conv2d_output_array, NULL)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  block_1_expand_conv2d_output, AI_STATIC,
  46, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 16, 16), AI_STRIDE_INIT(4, 4, 4, 192, 3072),
  1, &block_1_expand_conv2d_output_array, NULL)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  block_9_depthwise_conv2d_bias, AI_STATIC,
  47, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &block_9_depthwise_conv2d_bias_array, NULL)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  block_1_depthwise_conv2d_output, AI_STATIC,
  48, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 8, 8), AI_STRIDE_INIT(4, 4, 4, 192, 1536),
  1, &block_1_depthwise_conv2d_output_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  block_1_project_conv2d_output, AI_STATIC,
  49, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 8, 8), AI_STRIDE_INIT(4, 4, 4, 32, 256),
  1, &block_1_project_conv2d_output_array, NULL)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  block_9_project_conv2d_weights, AI_STATIC,
  50, 0x0,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 4, 576, 576, 576),
  1, &block_9_project_conv2d_weights_array, NULL)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  block_2_expand_conv2d_output, AI_STATIC,
  51, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 8, 8), AI_STRIDE_INIT(4, 4, 4, 192, 1536),
  1, &block_2_expand_conv2d_output_array, NULL)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  block_2_depthwise_conv2d_output, AI_STATIC,
  52, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 8, 8), AI_STRIDE_INIT(4, 4, 4, 192, 1536),
  1, &block_2_depthwise_conv2d_output_array, NULL)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  block_9_project_conv2d_bias, AI_STATIC,
  53, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &block_9_project_conv2d_bias_array, NULL)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  block_2_project_conv2d_output, AI_STATIC,
  54, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 8, 8), AI_STRIDE_INIT(4, 4, 4, 32, 256),
  1, &block_2_project_conv2d_output_array, NULL)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  block_2_add_output, AI_STATIC,
  55, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 8, 8), AI_STRIDE_INIT(4, 4, 4, 32, 256),
  1, &block_2_add_output_array, NULL)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  block_10_expand_conv2d_weights, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 4, 96, 96, 96),
  1, &block_10_expand_conv2d_weights_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  block_3_expand_conv2d_output, AI_STATIC,
  57, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 8, 8), AI_STRIDE_INIT(4, 4, 4, 192, 1536),
  1, &block_3_expand_conv2d_output_array, NULL)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  block_3_depthwise_conv2d_output, AI_STATIC,
  58, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 4, 4), AI_STRIDE_INIT(4, 4, 4, 192, 768),
  1, &block_3_depthwise_conv2d_output_array, NULL)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  block_10_expand_conv2d_bias, AI_STATIC,
  59, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &block_10_expand_conv2d_bias_array, NULL)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  block_3_project_conv2d_output, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 4, 4), AI_STRIDE_INIT(4, 4, 4, 64, 256),
  1, &block_3_project_conv2d_output_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  block_4_expand_conv2d_output, AI_STATIC,
  61, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 4, 4), AI_STRIDE_INIT(4, 4, 4, 384, 1536),
  1, &block_4_expand_conv2d_output_array, NULL)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  block_10_depthwise_conv2d_weights, AI_STATIC,
  62, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 144), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_10_depthwise_conv2d_weights_array, NULL)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  block_4_depthwise_conv2d_output, AI_STATIC,
  63, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 4, 4), AI_STRIDE_INIT(4, 4, 4, 384, 1536),
  1, &block_4_depthwise_conv2d_output_array, NULL)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  block_4_project_conv2d_output, AI_STATIC,
  64, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 4, 4), AI_STRIDE_INIT(4, 4, 4, 64, 256),
  1, &block_4_project_conv2d_output_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  block_10_depthwise_conv2d_bias, AI_STATIC,
  65, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &block_10_depthwise_conv2d_bias_array, NULL)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  block_4_add_output, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 4, 4), AI_STRIDE_INIT(4, 4, 4, 64, 256),
  1, &block_4_add_output_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  block_5_expand_conv2d_output, AI_STATIC,
  67, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 4, 4), AI_STRIDE_INIT(4, 4, 4, 384, 1536),
  1, &block_5_expand_conv2d_output_array, NULL)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  block_10_project_conv2d_weights, AI_STATIC,
  68, 0x0,
  AI_SHAPE_INIT(4, 144, 1, 1, 32), AI_STRIDE_INIT(4, 4, 576, 576, 576),
  1, &block_10_project_conv2d_weights_array, NULL)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  block_5_depthwise_conv2d_output, AI_STATIC,
  69, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 4, 4), AI_STRIDE_INIT(4, 4, 4, 384, 1536),
  1, &block_5_depthwise_conv2d_output_array, NULL)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  block_5_project_conv2d_output, AI_STATIC,
  70, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 4, 4), AI_STRIDE_INIT(4, 4, 4, 64, 256),
  1, &block_5_project_conv2d_output_array, NULL)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  block_10_project_conv2d_bias, AI_STATIC,
  71, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &block_10_project_conv2d_bias_array, NULL)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  block_5_add_output, AI_STATIC,
  72, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 4, 4), AI_STRIDE_INIT(4, 4, 4, 64, 256),
  1, &block_5_add_output_array, NULL)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  block_6_expand_conv2d_output, AI_STATIC,
  73, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 4, 4), AI_STRIDE_INIT(4, 4, 4, 384, 1536),
  1, &block_6_expand_conv2d_output_array, NULL)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  block_11_expand_conv2d_weights, AI_STATIC,
  74, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 4, 128, 128, 128),
  1, &block_11_expand_conv2d_weights_array, NULL)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  block_6_depthwise_conv2d_output, AI_STATIC,
  75, 0x0,
  AI_SHAPE_INIT(4, 1, 96, 2, 2), AI_STRIDE_INIT(4, 4, 4, 384, 768),
  1, &block_6_depthwise_conv2d_output_array, NULL)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  block_6_project_conv2d_output, AI_STATIC,
  76, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 2, 2), AI_STRIDE_INIT(4, 4, 4, 96, 192),
  1, &block_6_project_conv2d_output_array, NULL)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  block_11_expand_conv2d_bias, AI_STATIC,
  77, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &block_11_expand_conv2d_bias_array, NULL)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  block_7_expand_conv2d_output, AI_STATIC,
  78, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 2, 2), AI_STRIDE_INIT(4, 4, 4, 576, 1152),
  1, &block_7_expand_conv2d_output_array, NULL)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  block_7_depthwise_conv2d_output, AI_STATIC,
  79, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 2, 2), AI_STRIDE_INIT(4, 4, 4, 576, 1152),
  1, &block_7_depthwise_conv2d_output_array, NULL)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  block_11_depthwise_conv2d_weights, AI_STATIC,
  80, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 192), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_11_depthwise_conv2d_weights_array, NULL)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  block_7_project_conv2d_output, AI_STATIC,
  81, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 2, 2), AI_STRIDE_INIT(4, 4, 4, 96, 192),
  1, &block_7_project_conv2d_output_array, NULL)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  block_7_add_output, AI_STATIC,
  82, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 2, 2), AI_STRIDE_INIT(4, 4, 4, 96, 192),
  1, &block_7_add_output_array, NULL)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  block_11_depthwise_conv2d_bias, AI_STATIC,
  83, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &block_11_depthwise_conv2d_bias_array, NULL)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  block_8_expand_conv2d_output, AI_STATIC,
  84, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 2, 2), AI_STRIDE_INIT(4, 4, 4, 576, 1152),
  1, &block_8_expand_conv2d_output_array, NULL)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  block_8_depthwise_conv2d_output, AI_STATIC,
  85, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 2, 2), AI_STRIDE_INIT(4, 4, 4, 576, 1152),
  1, &block_8_depthwise_conv2d_output_array, NULL)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  block_11_project_conv2d_weights, AI_STATIC,
  86, 0x0,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 4, 768, 768, 768),
  1, &block_11_project_conv2d_weights_array, NULL)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  block_8_project_conv2d_output, AI_STATIC,
  87, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 2, 2), AI_STRIDE_INIT(4, 4, 4, 96, 192),
  1, &block_8_project_conv2d_output_array, NULL)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  block_8_add_output, AI_STATIC,
  88, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 2, 2), AI_STRIDE_INIT(4, 4, 4, 96, 192),
  1, &block_8_add_output_array, NULL)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  block_11_project_conv2d_bias, AI_STATIC,
  89, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &block_11_project_conv2d_bias_array, NULL)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  block_9_expand_conv2d_output, AI_STATIC,
  90, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 2, 2), AI_STRIDE_INIT(4, 4, 4, 576, 1152),
  1, &block_9_expand_conv2d_output_array, NULL)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  block_9_depthwise_conv2d_output, AI_STATIC,
  91, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 2, 2), AI_STRIDE_INIT(4, 4, 4, 576, 1152),
  1, &block_9_depthwise_conv2d_output_array, NULL)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  block_12_expand_conv2d_weights, AI_STATIC,
  92, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 4, 128, 128, 128),
  1, &block_12_expand_conv2d_weights_array, NULL)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  block_9_project_conv2d_output, AI_STATIC,
  93, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 2, 2), AI_STRIDE_INIT(4, 4, 4, 96, 192),
  1, &block_9_project_conv2d_output_array, NULL)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  block_9_add_output, AI_STATIC,
  94, 0x0,
  AI_SHAPE_INIT(4, 1, 24, 2, 2), AI_STRIDE_INIT(4, 4, 4, 96, 192),
  1, &block_9_add_output_array, NULL)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  block_12_expand_conv2d_bias, AI_STATIC,
  95, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &block_12_expand_conv2d_bias_array, NULL)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  block_10_expand_conv2d_output, AI_STATIC,
  96, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 2, 2), AI_STRIDE_INIT(4, 4, 4, 576, 1152),
  1, &block_10_expand_conv2d_output_array, NULL)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  block_10_depthwise_conv2d_output, AI_STATIC,
  97, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 2, 2), AI_STRIDE_INIT(4, 4, 4, 576, 1152),
  1, &block_10_depthwise_conv2d_output_array, NULL)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  block_12_depthwise_conv2d_weights, AI_STATIC,
  98, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 192), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_12_depthwise_conv2d_weights_array, NULL)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  block_10_project_conv2d_output, AI_STATIC,
  99, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 2, 2), AI_STRIDE_INIT(4, 4, 4, 128, 256),
  1, &block_10_project_conv2d_output_array, NULL)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  block_11_expand_conv2d_output, AI_STATIC,
  100, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 2, 2), AI_STRIDE_INIT(4, 4, 4, 768, 1536),
  1, &block_11_expand_conv2d_output_array, NULL)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  block_12_depthwise_conv2d_bias, AI_STATIC,
  101, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &block_12_depthwise_conv2d_bias_array, NULL)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  block_11_depthwise_conv2d_output, AI_STATIC,
  102, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 2, 2), AI_STRIDE_INIT(4, 4, 4, 768, 1536),
  1, &block_11_depthwise_conv2d_output_array, NULL)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  block_11_project_conv2d_output, AI_STATIC,
  103, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 2, 2), AI_STRIDE_INIT(4, 4, 4, 128, 256),
  1, &block_11_project_conv2d_output_array, NULL)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  block_12_project_conv2d_weights, AI_STATIC,
  104, 0x0,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 4, 768, 768, 768),
  1, &block_12_project_conv2d_weights_array, NULL)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  block_11_add_output, AI_STATIC,
  105, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 2, 2), AI_STRIDE_INIT(4, 4, 4, 128, 256),
  1, &block_11_add_output_array, NULL)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  block_12_expand_conv2d_output, AI_STATIC,
  106, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 2, 2), AI_STRIDE_INIT(4, 4, 4, 768, 1536),
  1, &block_12_expand_conv2d_output_array, NULL)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  block_12_project_conv2d_bias, AI_STATIC,
  107, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &block_12_project_conv2d_bias_array, NULL)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  block_12_depthwise_conv2d_output, AI_STATIC,
  108, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 2, 2), AI_STRIDE_INIT(4, 4, 4, 768, 1536),
  1, &block_12_depthwise_conv2d_output_array, NULL)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  block_12_project_conv2d_output, AI_STATIC,
  109, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 2, 2), AI_STRIDE_INIT(4, 4, 4, 128, 256),
  1, &block_12_project_conv2d_output_array, NULL)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  block_13_expand_conv2d_weights, AI_STATIC,
  110, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 4, 128, 128, 128),
  1, &block_13_expand_conv2d_weights_array, NULL)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  block_12_add_output, AI_STATIC,
  111, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 2, 2), AI_STRIDE_INIT(4, 4, 4, 128, 256),
  1, &block_12_add_output_array, NULL)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  block_13_expand_conv2d_output, AI_STATIC,
  112, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 2, 2), AI_STRIDE_INIT(4, 4, 4, 768, 1536),
  1, &block_13_expand_conv2d_output_array, NULL)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  block_13_expand_conv2d_bias, AI_STATIC,
  113, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &block_13_expand_conv2d_bias_array, NULL)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  block_13_depthwise_conv2d_output, AI_STATIC,
  114, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &block_13_depthwise_conv2d_output_array, NULL)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  block_13_project_conv2d_output, AI_STATIC,
  115, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &block_13_project_conv2d_output_array, NULL)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  block_13_depthwise_conv2d_weights, AI_STATIC,
  116, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 192), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_13_depthwise_conv2d_weights_array, NULL)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  block_14_expand_conv2d_output, AI_STATIC,
  117, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &block_14_expand_conv2d_output_array, NULL)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  block_14_depthwise_conv2d_output, AI_STATIC,
  118, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &block_14_depthwise_conv2d_output_array, NULL)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  block_13_depthwise_conv2d_bias, AI_STATIC,
  119, 0x0,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &block_13_depthwise_conv2d_bias_array, NULL)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  block_14_project_conv2d_output, AI_STATIC,
  120, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &block_14_project_conv2d_output_array, NULL)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  block_14_add_output, AI_STATIC,
  121, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &block_14_add_output_array, NULL)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  block_13_project_conv2d_weights, AI_STATIC,
  122, 0x0,
  AI_SHAPE_INIT(4, 192, 1, 1, 56), AI_STRIDE_INIT(4, 4, 768, 768, 768),
  1, &block_13_project_conv2d_weights_array, NULL)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  block_15_expand_conv2d_output, AI_STATIC,
  123, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &block_15_expand_conv2d_output_array, NULL)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  block_15_depthwise_conv2d_output, AI_STATIC,
  124, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &block_15_depthwise_conv2d_output_array, NULL)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  block_13_project_conv2d_bias, AI_STATIC,
  125, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &block_13_project_conv2d_bias_array, NULL)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  block_15_project_conv2d_output, AI_STATIC,
  126, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &block_15_project_conv2d_output_array, NULL)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  block_15_add_output, AI_STATIC,
  127, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &block_15_add_output_array, NULL)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  block_14_expand_conv2d_weights, AI_STATIC,
  128, 0x0,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 4, 224, 224, 224),
  1, &block_14_expand_conv2d_weights_array, NULL)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  block_16_expand_conv2d_output, AI_STATIC,
  129, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &block_16_expand_conv2d_output_array, NULL)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  block_16_depthwise_conv2d_output, AI_STATIC,
  130, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &block_16_depthwise_conv2d_output_array, NULL)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  block_14_expand_conv2d_bias, AI_STATIC,
  131, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &block_14_expand_conv2d_bias_array, NULL)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  block_16_project_conv2d_output, AI_STATIC,
  132, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 4, 4, 448, 448),
  1, &block_16_project_conv2d_output_array, NULL)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  Conv_1_conv2d_output, AI_STATIC,
  133, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 4, 4, 5120, 5120),
  1, &Conv_1_conv2d_output_array, NULL)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  block_14_depthwise_conv2d_weights, AI_STATIC,
  134, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 336), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_14_depthwise_conv2d_weights_array, NULL)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  dense_dense_output, AI_STATIC,
  135, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &dense_dense_output_array, NULL)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  dense_output, AI_STATIC,
  136, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &dense_output_array, NULL)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  block_14_depthwise_conv2d_bias, AI_STATIC,
  137, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &block_14_depthwise_conv2d_bias_array, NULL)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_dense_output, AI_STATIC,
  138, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &dense_1_dense_output_array, NULL)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_output, AI_STATIC,
  139, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &dense_1_output_array, NULL)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  block_14_project_conv2d_weights, AI_STATIC,
  140, 0x0,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 4, 1344, 1344, 1344),
  1, &block_14_project_conv2d_weights_array, NULL)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  block_14_project_conv2d_bias, AI_STATIC,
  141, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &block_14_project_conv2d_bias_array, NULL)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  block_15_expand_conv2d_weights, AI_STATIC,
  142, 0x0,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 4, 224, 224, 224),
  1, &block_15_expand_conv2d_weights_array, NULL)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  block_15_expand_conv2d_bias, AI_STATIC,
  143, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &block_15_expand_conv2d_bias_array, NULL)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  block_15_depthwise_conv2d_weights, AI_STATIC,
  144, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 336), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_15_depthwise_conv2d_weights_array, NULL)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  block_15_depthwise_conv2d_bias, AI_STATIC,
  145, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &block_15_depthwise_conv2d_bias_array, NULL)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  block_15_project_conv2d_weights, AI_STATIC,
  146, 0x0,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 4, 1344, 1344, 1344),
  1, &block_15_project_conv2d_weights_array, NULL)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  block_15_project_conv2d_bias, AI_STATIC,
  147, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &block_15_project_conv2d_bias_array, NULL)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  block_16_expand_conv2d_weights, AI_STATIC,
  148, 0x0,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 4, 224, 224, 224),
  1, &block_16_expand_conv2d_weights_array, NULL)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  block_16_expand_conv2d_bias, AI_STATIC,
  149, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &block_16_expand_conv2d_bias_array, NULL)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  block_16_depthwise_conv2d_weights, AI_STATIC,
  150, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 336), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_16_depthwise_conv2d_weights_array, NULL)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  block_16_depthwise_conv2d_bias, AI_STATIC,
  151, 0x0,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &block_16_depthwise_conv2d_bias_array, NULL)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  block_16_project_conv2d_weights, AI_STATIC,
  152, 0x0,
  AI_SHAPE_INIT(4, 336, 1, 1, 112), AI_STRIDE_INIT(4, 4, 1344, 1344, 1344),
  1, &block_16_project_conv2d_weights_array, NULL)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  block_16_project_conv2d_bias, AI_STATIC,
  153, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 4, 4, 448, 448),
  1, &block_16_project_conv2d_bias_array, NULL)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  Conv_1_conv2d_weights, AI_STATIC,
  154, 0x0,
  AI_SHAPE_INIT(4, 112, 1, 1, 1280), AI_STRIDE_INIT(4, 4, 448, 448, 448),
  1, &Conv_1_conv2d_weights_array, NULL)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  Conv_1_conv2d_bias, AI_STATIC,
  155, 0x0,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 4, 4, 5120, 5120),
  1, &Conv_1_conv2d_bias_array, NULL)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  dense_dense_weights, AI_STATIC,
  156, 0x0,
  AI_SHAPE_INIT(4, 1280, 8, 1, 1), AI_STRIDE_INIT(4, 4, 5120, 40960, 40960),
  1, &dense_dense_weights_array, NULL)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  dense_dense_bias, AI_STATIC,
  157, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &dense_dense_bias_array, NULL)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_dense_weights, AI_STATIC,
  158, 0x0,
  AI_SHAPE_INIT(4, 8, 10, 1, 1), AI_STRIDE_INIT(4, 4, 32, 320, 320),
  1, &dense_1_dense_weights_array, NULL)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_dense_bias, AI_STATIC,
  159, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &dense_1_dense_bias_array, NULL)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  Conv1_conv2d_weights, AI_STATIC,
  160, 0x0,
  AI_SHAPE_INIT(4, 3, 3, 3, 16), AI_STRIDE_INIT(4, 4, 12, 36, 108),
  1, &Conv1_conv2d_weights_array, NULL)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  Conv1_conv2d_bias, AI_STATIC,
  161, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &Conv1_conv2d_bias_array, NULL)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  expanded_conv_depthwise_conv2d_weights, AI_STATIC,
  162, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 16), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &expanded_conv_depthwise_conv2d_weights_array, NULL)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  expanded_conv_depthwise_conv2d_bias, AI_STATIC,
  163, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &expanded_conv_depthwise_conv2d_bias_array, NULL)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  expanded_conv_project_conv2d_weights, AI_STATIC,
  164, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 8), AI_STRIDE_INIT(4, 4, 64, 64, 64),
  1, &expanded_conv_project_conv2d_weights_array, NULL)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  expanded_conv_project_conv2d_bias, AI_STATIC,
  165, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &expanded_conv_project_conv2d_bias_array, NULL)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  block_1_expand_conv2d_weights, AI_STATIC,
  166, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &block_1_expand_conv2d_weights_array, NULL)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  block_1_expand_conv2d_bias, AI_STATIC,
  167, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &block_1_expand_conv2d_bias_array, NULL)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  block_1_depthwise_conv2d_weights, AI_STATIC,
  168, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 48), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_1_depthwise_conv2d_weights_array, NULL)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  block_1_depthwise_conv2d_bias, AI_STATIC,
  169, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &block_1_depthwise_conv2d_bias_array, NULL)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  block_1_project_conv2d_weights, AI_STATIC,
  170, 0x0,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 4, 192, 192, 192),
  1, &block_1_project_conv2d_weights_array, NULL)

/* Tensor #171 */
AI_TENSOR_OBJ_DECLARE(
  block_1_project_conv2d_bias, AI_STATIC,
  171, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &block_1_project_conv2d_bias_array, NULL)

/* Tensor #172 */
AI_TENSOR_OBJ_DECLARE(
  block_2_expand_conv2d_weights, AI_STATIC,
  172, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &block_2_expand_conv2d_weights_array, NULL)

/* Tensor #173 */
AI_TENSOR_OBJ_DECLARE(
  block_2_expand_conv2d_bias, AI_STATIC,
  173, 0x0,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &block_2_expand_conv2d_bias_array, NULL)

/* Tensor #174 */
AI_TENSOR_OBJ_DECLARE(
  block_2_depthwise_conv2d_weights, AI_STATIC,
  174, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 48), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &block_2_depthwise_conv2d_weights_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_1_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_1_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_1_layer, 5,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &dense_1_chain,
  NULL, &dense_1_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_1_dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_1_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_1_dense_weights, &dense_1_dense_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_1_dense_layer, 5,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_1_dense_chain,
  NULL, &dense_1_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_layer, 2,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &dense_chain,
  NULL, &dense_1_dense_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &Conv_1_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_dense_weights, &dense_dense_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_dense_layer, 2,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_dense_chain,
  NULL, &dense_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float Conv_1_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    Conv_1_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    Conv_1_conv2d_nl_params_data, Conv_1_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  Conv_1_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_16_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &Conv_1_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &Conv_1_conv2d_weights, &Conv_1_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  Conv_1_conv2d_layer, 153,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &Conv_1_conv2d_chain,
  NULL, &dense_dense_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &Conv_1_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_16_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_16_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_16_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_16_project_conv2d_weights, &block_16_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_16_project_conv2d_layer, 150,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_16_project_conv2d_chain,
  NULL, &Conv_1_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_16_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_16_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_16_depthwise_conv2d_nl_params_data, block_16_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_16_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_16_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_16_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_16_depthwise_conv2d_weights, &block_16_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_16_depthwise_conv2d_layer, 148,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_16_depthwise_conv2d_chain,
  NULL, &block_16_project_conv2d_layer, AI_STATIC, 
  .groups = 336, 
  .nl_params = &block_16_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float block_16_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_16_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_16_expand_conv2d_nl_params_data, block_16_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_16_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_15_add_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_16_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_16_expand_conv2d_weights, &block_16_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_16_expand_conv2d_layer, 145,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_16_expand_conv2d_chain,
  NULL, &block_16_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_16_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_15_add_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &block_14_add_output, &block_15_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_15_add_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_15_add_layer, 142,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &block_15_add_chain,
  NULL, &block_16_expand_conv2d_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_15_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_15_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_15_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_15_project_conv2d_weights, &block_15_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_15_project_conv2d_layer, 141,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_15_project_conv2d_chain,
  NULL, &block_15_add_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_15_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_15_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_15_depthwise_conv2d_nl_params_data, block_15_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_15_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_15_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_15_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_15_depthwise_conv2d_weights, &block_15_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_15_depthwise_conv2d_layer, 139,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_15_depthwise_conv2d_chain,
  NULL, &block_15_project_conv2d_layer, AI_STATIC, 
  .groups = 336, 
  .nl_params = &block_15_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float block_15_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_15_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_15_expand_conv2d_nl_params_data, block_15_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_15_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_14_add_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_15_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_15_expand_conv2d_weights, &block_15_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_15_expand_conv2d_layer, 136,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_15_expand_conv2d_chain,
  NULL, &block_15_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_15_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_14_add_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &block_13_project_conv2d_output, &block_14_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_14_add_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_14_add_layer, 133,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &block_14_add_chain,
  NULL, &block_15_expand_conv2d_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_14_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_14_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_14_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_14_project_conv2d_weights, &block_14_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_14_project_conv2d_layer, 132,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_14_project_conv2d_chain,
  NULL, &block_14_add_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_14_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_14_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_14_depthwise_conv2d_nl_params_data, block_14_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_14_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_14_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_14_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_14_depthwise_conv2d_weights, &block_14_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_14_depthwise_conv2d_layer, 130,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_14_depthwise_conv2d_chain,
  NULL, &block_14_project_conv2d_layer, AI_STATIC, 
  .groups = 336, 
  .nl_params = &block_14_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float block_14_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_14_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_14_expand_conv2d_nl_params_data, block_14_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_14_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_13_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_14_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_14_expand_conv2d_weights, &block_14_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_14_expand_conv2d_layer, 127,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_14_expand_conv2d_chain,
  NULL, &block_14_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_14_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_13_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_13_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_13_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_13_project_conv2d_weights, &block_13_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_13_project_conv2d_layer, 124,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_13_project_conv2d_chain,
  NULL, &block_14_expand_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_13_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_13_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_13_depthwise_conv2d_nl_params_data, block_13_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_13_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_13_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_13_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_13_depthwise_conv2d_weights, &block_13_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_13_depthwise_conv2d_layer, 122,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_13_depthwise_conv2d_chain,
  NULL, &block_13_project_conv2d_layer, AI_STATIC, 
  .groups = 192, 
  .nl_params = &block_13_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)


AI_STATIC_CONST ai_float block_13_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_13_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_13_expand_conv2d_nl_params_data, block_13_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_13_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_12_add_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_13_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_13_expand_conv2d_weights, &block_13_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_13_expand_conv2d_layer, 118,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_13_expand_conv2d_chain,
  NULL, &block_13_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_13_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_12_add_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &block_11_add_output, &block_12_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_12_add_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_12_add_layer, 115,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &block_12_add_chain,
  NULL, &block_13_expand_conv2d_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_12_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_12_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_12_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_12_project_conv2d_weights, &block_12_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_12_project_conv2d_layer, 114,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_12_project_conv2d_chain,
  NULL, &block_12_add_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_12_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_12_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_12_depthwise_conv2d_nl_params_data, block_12_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_12_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_12_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_12_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_12_depthwise_conv2d_weights, &block_12_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_12_depthwise_conv2d_layer, 112,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_12_depthwise_conv2d_chain,
  NULL, &block_12_project_conv2d_layer, AI_STATIC, 
  .groups = 192, 
  .nl_params = &block_12_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float block_12_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_12_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_12_expand_conv2d_nl_params_data, block_12_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_12_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_11_add_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_12_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_12_expand_conv2d_weights, &block_12_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_12_expand_conv2d_layer, 109,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_12_expand_conv2d_chain,
  NULL, &block_12_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_12_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_11_add_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &block_10_project_conv2d_output, &block_11_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_11_add_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_11_add_layer, 106,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &block_11_add_chain,
  NULL, &block_12_expand_conv2d_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_11_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_11_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_11_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_11_project_conv2d_weights, &block_11_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_11_project_conv2d_layer, 105,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_11_project_conv2d_chain,
  NULL, &block_11_add_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_11_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_11_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_11_depthwise_conv2d_nl_params_data, block_11_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_11_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_11_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_11_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_11_depthwise_conv2d_weights, &block_11_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_11_depthwise_conv2d_layer, 103,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_11_depthwise_conv2d_chain,
  NULL, &block_11_project_conv2d_layer, AI_STATIC, 
  .groups = 192, 
  .nl_params = &block_11_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float block_11_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_11_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_11_expand_conv2d_nl_params_data, block_11_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_11_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_10_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_11_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_11_expand_conv2d_weights, &block_11_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_11_expand_conv2d_layer, 100,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_11_expand_conv2d_chain,
  NULL, &block_11_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_11_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_10_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_10_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_10_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_10_project_conv2d_weights, &block_10_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_10_project_conv2d_layer, 97,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_10_project_conv2d_chain,
  NULL, &block_11_expand_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_10_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_10_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_10_depthwise_conv2d_nl_params_data, block_10_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_10_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_10_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_10_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_10_depthwise_conv2d_weights, &block_10_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_10_depthwise_conv2d_layer, 95,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_10_depthwise_conv2d_chain,
  NULL, &block_10_project_conv2d_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = &block_10_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float block_10_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_10_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_10_expand_conv2d_nl_params_data, block_10_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_10_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_9_add_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_10_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_10_expand_conv2d_weights, &block_10_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_10_expand_conv2d_layer, 92,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_10_expand_conv2d_chain,
  NULL, &block_10_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_10_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_9_add_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &block_8_add_output, &block_9_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_9_add_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_9_add_layer, 89,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &block_9_add_chain,
  NULL, &block_10_expand_conv2d_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_9_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_9_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_9_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_9_project_conv2d_weights, &block_9_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_9_project_conv2d_layer, 88,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_9_project_conv2d_chain,
  NULL, &block_9_add_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_9_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_9_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_9_depthwise_conv2d_nl_params_data, block_9_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_9_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_9_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_9_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_9_depthwise_conv2d_weights, &block_9_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_9_depthwise_conv2d_layer, 86,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_9_depthwise_conv2d_chain,
  NULL, &block_9_project_conv2d_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = &block_9_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float block_9_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_9_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_9_expand_conv2d_nl_params_data, block_9_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_9_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_8_add_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_9_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_9_expand_conv2d_weights, &block_9_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_9_expand_conv2d_layer, 83,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_9_expand_conv2d_chain,
  NULL, &block_9_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_9_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_8_add_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &block_7_add_output, &block_8_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_8_add_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_8_add_layer, 80,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &block_8_add_chain,
  NULL, &block_9_expand_conv2d_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_8_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_8_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_8_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_8_project_conv2d_weights, &block_8_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_8_project_conv2d_layer, 79,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_8_project_conv2d_chain,
  NULL, &block_8_add_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_8_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_8_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_8_depthwise_conv2d_nl_params_data, block_8_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_8_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_8_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_8_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_8_depthwise_conv2d_weights, &block_8_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_8_depthwise_conv2d_layer, 77,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_8_depthwise_conv2d_chain,
  NULL, &block_8_project_conv2d_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = &block_8_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float block_8_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_8_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_8_expand_conv2d_nl_params_data, block_8_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_8_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_7_add_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_8_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_8_expand_conv2d_weights, &block_8_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_8_expand_conv2d_layer, 74,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_8_expand_conv2d_chain,
  NULL, &block_8_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_8_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_7_add_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &block_6_project_conv2d_output, &block_7_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_7_add_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_7_add_layer, 71,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &block_7_add_chain,
  NULL, &block_8_expand_conv2d_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_7_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_7_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_7_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_7_project_conv2d_weights, &block_7_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_7_project_conv2d_layer, 70,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_7_project_conv2d_chain,
  NULL, &block_7_add_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_7_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_7_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_7_depthwise_conv2d_nl_params_data, block_7_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_7_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_7_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_7_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_7_depthwise_conv2d_weights, &block_7_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_7_depthwise_conv2d_layer, 68,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_7_depthwise_conv2d_chain,
  NULL, &block_7_project_conv2d_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = &block_7_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float block_7_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_7_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_7_expand_conv2d_nl_params_data, block_7_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_7_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_6_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_7_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_7_expand_conv2d_weights, &block_7_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_7_expand_conv2d_layer, 65,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_7_expand_conv2d_chain,
  NULL, &block_7_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_7_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_6_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_6_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_6_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_6_project_conv2d_weights, &block_6_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_6_project_conv2d_layer, 62,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_6_project_conv2d_chain,
  NULL, &block_7_expand_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_6_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_6_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_6_depthwise_conv2d_nl_params_data, block_6_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_6_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_6_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_6_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_6_depthwise_conv2d_weights, &block_6_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_6_depthwise_conv2d_layer, 60,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_6_depthwise_conv2d_chain,
  NULL, &block_6_project_conv2d_layer, AI_STATIC, 
  .groups = 96, 
  .nl_params = &block_6_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)


AI_STATIC_CONST ai_float block_6_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_6_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_6_expand_conv2d_nl_params_data, block_6_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_6_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_5_add_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_6_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_6_expand_conv2d_weights, &block_6_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_6_expand_conv2d_layer, 56,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_6_expand_conv2d_chain,
  NULL, &block_6_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_6_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_5_add_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &block_4_add_output, &block_5_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_5_add_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_5_add_layer, 53,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &block_5_add_chain,
  NULL, &block_6_expand_conv2d_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_5_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_5_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_5_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_5_project_conv2d_weights, &block_5_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_5_project_conv2d_layer, 52,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_5_project_conv2d_chain,
  NULL, &block_5_add_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_5_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_5_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_5_depthwise_conv2d_nl_params_data, block_5_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_5_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_5_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_5_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_5_depthwise_conv2d_weights, &block_5_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_5_depthwise_conv2d_layer, 50,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_5_depthwise_conv2d_chain,
  NULL, &block_5_project_conv2d_layer, AI_STATIC, 
  .groups = 96, 
  .nl_params = &block_5_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float block_5_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_5_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_5_expand_conv2d_nl_params_data, block_5_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_5_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_4_add_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_5_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_5_expand_conv2d_weights, &block_5_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_5_expand_conv2d_layer, 47,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_5_expand_conv2d_chain,
  NULL, &block_5_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_5_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_4_add_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &block_3_project_conv2d_output, &block_4_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_4_add_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_4_add_layer, 44,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &block_4_add_chain,
  NULL, &block_5_expand_conv2d_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_4_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_4_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_4_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_4_project_conv2d_weights, &block_4_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_4_project_conv2d_layer, 43,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_4_project_conv2d_chain,
  NULL, &block_4_add_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_4_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_4_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_4_depthwise_conv2d_nl_params_data, block_4_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_4_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_4_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_4_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_4_depthwise_conv2d_weights, &block_4_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_4_depthwise_conv2d_layer, 41,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_4_depthwise_conv2d_chain,
  NULL, &block_4_project_conv2d_layer, AI_STATIC, 
  .groups = 96, 
  .nl_params = &block_4_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float block_4_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_4_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_4_expand_conv2d_nl_params_data, block_4_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_4_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_3_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_4_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_4_expand_conv2d_weights, &block_4_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_4_expand_conv2d_layer, 38,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_4_expand_conv2d_chain,
  NULL, &block_4_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_4_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_3_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_3_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_3_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_3_project_conv2d_weights, &block_3_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_3_project_conv2d_layer, 35,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_3_project_conv2d_chain,
  NULL, &block_4_expand_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_3_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_3_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_3_depthwise_conv2d_nl_params_data, block_3_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_3_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_3_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_3_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_3_depthwise_conv2d_weights, &block_3_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_3_depthwise_conv2d_layer, 33,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_3_depthwise_conv2d_chain,
  NULL, &block_3_project_conv2d_layer, AI_STATIC, 
  .groups = 48, 
  .nl_params = &block_3_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)


AI_STATIC_CONST ai_float block_3_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_3_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_3_expand_conv2d_nl_params_data, block_3_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_3_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_2_add_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_3_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_3_expand_conv2d_weights, &block_3_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_3_expand_conv2d_layer, 29,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_3_expand_conv2d_chain,
  NULL, &block_3_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_3_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_2_add_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &block_1_project_conv2d_output, &block_2_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_2_add_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_2_add_layer, 26,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &block_2_add_chain,
  NULL, &block_3_expand_conv2d_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_2_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_2_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_2_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_2_project_conv2d_weights, &block_2_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_2_project_conv2d_layer, 25,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_2_project_conv2d_chain,
  NULL, &block_2_add_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_2_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_2_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_2_depthwise_conv2d_nl_params_data, block_2_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_2_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_2_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_2_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_2_depthwise_conv2d_weights, &block_2_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_2_depthwise_conv2d_layer, 23,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_2_depthwise_conv2d_chain,
  NULL, &block_2_project_conv2d_layer, AI_STATIC, 
  .groups = 48, 
  .nl_params = &block_2_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float block_2_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_2_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_2_expand_conv2d_nl_params_data, block_2_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_2_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_1_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_2_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_2_expand_conv2d_weights, &block_2_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_2_expand_conv2d_layer, 20,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_2_expand_conv2d_chain,
  NULL, &block_2_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_2_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_1_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_1_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_1_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_1_project_conv2d_weights, &block_1_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_1_project_conv2d_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_1_project_conv2d_chain,
  NULL, &block_2_expand_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float block_1_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_1_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_1_depthwise_conv2d_nl_params_data, block_1_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_1_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_1_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_1_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_1_depthwise_conv2d_weights, &block_1_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_1_depthwise_conv2d_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_1_depthwise_conv2d_chain,
  NULL, &block_1_project_conv2d_layer, AI_STATIC, 
  .groups = 48, 
  .nl_params = &block_1_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)


AI_STATIC_CONST ai_float block_1_expand_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    block_1_expand_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    block_1_expand_conv2d_nl_params_data, block_1_expand_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  block_1_expand_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &expanded_conv_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &block_1_expand_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &block_1_expand_conv2d_weights, &block_1_expand_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  block_1_expand_conv2d_layer, 11,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &block_1_expand_conv2d_chain,
  NULL, &block_1_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &block_1_expand_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  expanded_conv_project_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &expanded_conv_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &expanded_conv_project_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &expanded_conv_project_conv2d_weights, &expanded_conv_project_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  expanded_conv_project_conv2d_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &expanded_conv_project_conv2d_chain,
  NULL, &block_1_expand_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_STATIC_CONST ai_float expanded_conv_depthwise_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    expanded_conv_depthwise_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    expanded_conv_depthwise_conv2d_nl_params_data, expanded_conv_depthwise_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  expanded_conv_depthwise_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &Conv1_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &expanded_conv_depthwise_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &expanded_conv_depthwise_conv2d_weights, &expanded_conv_depthwise_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  expanded_conv_depthwise_conv2d_layer, 6,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &expanded_conv_depthwise_conv2d_chain,
  NULL, &expanded_conv_project_conv2d_layer, AI_STATIC, 
  .groups = 16, 
  .nl_params = &expanded_conv_depthwise_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)


AI_STATIC_CONST ai_float Conv1_conv2d_nl_params_data[] = { 0, 6.0 };
AI_ARRAY_OBJ_DECLARE(
    Conv1_conv2d_nl_params, AI_ARRAY_FORMAT_FLOAT,
    Conv1_conv2d_nl_params_data, Conv1_conv2d_nl_params_data, 2, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  Conv1_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &Conv1_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &Conv1_conv2d_weights, &Conv1_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  Conv1_conv2d_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &Conv1_conv2d_chain,
  NULL, &expanded_conv_depthwise_conv2d_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &Conv1_conv2d_nl_params, 
  .nl_func = nl_func_clip_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1597704, 1, 1),
    1597704, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 56512, 1, 1),
    56512, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &dense_1_output),
  &Conv1_conv2d_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1597704, 1, 1),
      1597704, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 56512, 1, 1),
      56512, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &dense_1_output),
  &Conv1_conv2d_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_network_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    input_0_output_array.data = AI_PTR(g_network_activations_map[0] + 44224);
    input_0_output_array.data_start = AI_PTR(g_network_activations_map[0] + 44224);
    
    Conv1_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 27840);
    Conv1_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 27840);
    
    expanded_conv_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 25600);
    expanded_conv_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 25600);
    
    expanded_conv_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 48320);
    expanded_conv_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 48320);
    
    block_1_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 1728);
    block_1_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1728);
    
    block_1_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_1_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_1_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 12288);
    block_1_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 12288);
    
    block_2_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_2_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_2_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 14336);
    block_2_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 14336);
    
    block_2_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_2_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_2_add_output_array.data = AI_PTR(g_network_activations_map[0] + 2048);
    block_2_add_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2048);
    
    block_3_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 4096);
    block_3_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4096);
    
    block_3_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_3_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_3_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 3072);
    block_3_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3072);
    
    block_4_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 4096);
    block_4_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4096);
    
    block_4_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 10240);
    block_4_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 10240);
    
    block_4_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_4_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_4_add_output_array.data = AI_PTR(g_network_activations_map[0] + 1024);
    block_4_add_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1024);
    
    block_5_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 2048);
    block_5_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2048);
    
    block_5_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 8192);
    block_5_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 8192);
    
    block_5_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_5_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_5_add_output_array.data = AI_PTR(g_network_activations_map[0] + 2048);
    block_5_add_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2048);
    
    block_6_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 3072);
    block_6_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3072);
    
    block_6_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_6_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_6_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 1536);
    block_6_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1536);
    
    block_7_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 1920);
    block_7_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1920);
    
    block_7_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 4224);
    block_7_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4224);
    
    block_7_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_7_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_7_add_output_array.data = AI_PTR(g_network_activations_map[0] + 384);
    block_7_add_output_array.data_start = AI_PTR(g_network_activations_map[0] + 384);
    
    block_8_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 768);
    block_8_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 768);
    
    block_8_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 3072);
    block_8_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3072);
    
    block_8_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_8_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_8_add_output_array.data = AI_PTR(g_network_activations_map[0] + 768);
    block_8_add_output_array.data_start = AI_PTR(g_network_activations_map[0] + 768);
    
    block_9_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 1152);
    block_9_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1152);
    
    block_9_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 3456);
    block_9_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3456);
    
    block_9_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_9_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_9_add_output_array.data = AI_PTR(g_network_activations_map[0] + 384);
    block_9_add_output_array.data_start = AI_PTR(g_network_activations_map[0] + 384);
    
    block_10_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 768);
    block_10_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 768);
    
    block_10_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 3072);
    block_10_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3072);
    
    block_10_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_10_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_11_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 512);
    block_11_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 512);
    
    block_11_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 3584);
    block_11_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 3584);
    
    block_11_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 512);
    block_11_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 512);
    
    block_11_add_output_array.data = AI_PTR(g_network_activations_map[0] + 1024);
    block_11_add_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1024);
    
    block_12_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 1536);
    block_12_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1536);
    
    block_12_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 4608);
    block_12_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 4608);
    
    block_12_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_12_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_12_add_output_array.data = AI_PTR(g_network_activations_map[0] + 512);
    block_12_add_output_array.data_start = AI_PTR(g_network_activations_map[0] + 512);
    
    block_13_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 1024);
    block_13_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1024);
    
    block_13_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_13_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_13_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 768);
    block_13_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 768);
    
    block_14_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 992);
    block_14_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 992);
    
    block_14_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 2336);
    block_14_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2336);
    
    block_14_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_14_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_14_add_output_array.data = AI_PTR(g_network_activations_map[0] + 224);
    block_14_add_output_array.data_start = AI_PTR(g_network_activations_map[0] + 224);
    
    block_15_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 448);
    block_15_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 448);
    
    block_15_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 1792);
    block_15_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 1792);
    
    block_15_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_15_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    block_15_add_output_array.data = AI_PTR(g_network_activations_map[0] + 448);
    block_15_add_output_array.data_start = AI_PTR(g_network_activations_map[0] + 448);
    
    block_16_expand_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 672);
    block_16_expand_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 672);
    
    block_16_depthwise_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 2016);
    block_16_depthwise_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 2016);
    
    block_16_project_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    block_16_project_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    Conv_1_conv2d_output_array.data = AI_PTR(g_network_activations_map[0] + 448);
    Conv_1_conv2d_output_array.data_start = AI_PTR(g_network_activations_map[0] + 448);
    
    dense_dense_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    dense_dense_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    dense_output_array.data = AI_PTR(g_network_activations_map[0] + 32);
    dense_output_array.data_start = AI_PTR(g_network_activations_map[0] + 32);
    
    dense_1_dense_output_array.data = AI_PTR(g_network_activations_map[0] + 64);
    dense_1_dense_output_array.data_start = AI_PTR(g_network_activations_map[0] + 64);
    
    dense_1_output_array.data = AI_PTR(g_network_activations_map[0] + 0);
    dense_1_output_array.data_start = AI_PTR(g_network_activations_map[0] + 0);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_network_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    block_2_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_2_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 0);
    block_2_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 0);
    
    block_2_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_2_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 192);
    block_2_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 192);
    
    block_2_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_2_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 1728);
    block_2_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1728);
    
    block_3_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_3_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 1760);
    block_3_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1760);
    
    block_3_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_3_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 3296);
    block_3_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 3296);
    
    block_3_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_3_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 3488);
    block_3_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 3488);
    
    block_3_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_3_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 5216);
    block_3_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 5216);
    
    block_3_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_3_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 5408);
    block_3_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 5408);
    
    block_3_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_3_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 8480);
    block_3_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 8480);
    
    block_4_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_4_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 8544);
    block_4_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 8544);
    
    block_4_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_4_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 14688);
    block_4_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 14688);
    
    block_4_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_4_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 15072);
    block_4_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 15072);
    
    block_4_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_4_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 18528);
    block_4_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 18528);
    
    block_4_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_4_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 18912);
    block_4_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 18912);
    
    block_4_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_4_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 25056);
    block_4_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 25056);
    
    block_5_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_5_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 25120);
    block_5_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 25120);
    
    block_5_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_5_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 31264);
    block_5_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 31264);
    
    block_5_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_5_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 31648);
    block_5_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 31648);
    
    block_5_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_5_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 35104);
    block_5_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 35104);
    
    block_5_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_5_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 35488);
    block_5_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 35488);
    
    block_5_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_5_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 41632);
    block_5_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 41632);
    
    block_6_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_6_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 41696);
    block_6_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 41696);
    
    block_6_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_6_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 47840);
    block_6_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 47840);
    
    block_6_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_6_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 48224);
    block_6_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 48224);
    
    block_6_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_6_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 51680);
    block_6_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 51680);
    
    block_6_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_6_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 52064);
    block_6_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 52064);
    
    block_6_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_6_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 61280);
    block_6_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 61280);
    
    block_7_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_7_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 61376);
    block_7_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 61376);
    
    block_7_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_7_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 75200);
    block_7_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 75200);
    
    block_7_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_7_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 75776);
    block_7_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 75776);
    
    block_7_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_7_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 80960);
    block_7_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 80960);
    
    block_7_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_7_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 81536);
    block_7_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 81536);
    
    block_7_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_7_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 95360);
    block_7_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 95360);
    
    block_8_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_8_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 95456);
    block_8_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 95456);
    
    block_8_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_8_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 109280);
    block_8_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 109280);
    
    block_8_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_8_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 109856);
    block_8_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 109856);
    
    block_8_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_8_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 115040);
    block_8_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 115040);
    
    block_8_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_8_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 115616);
    block_8_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 115616);
    
    block_8_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_8_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 129440);
    block_8_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 129440);
    
    block_9_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_9_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 129536);
    block_9_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 129536);
    
    block_9_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_9_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 143360);
    block_9_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 143360);
    
    block_9_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_9_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 143936);
    block_9_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 143936);
    
    block_9_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_9_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 149120);
    block_9_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 149120);
    
    block_9_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_9_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 149696);
    block_9_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 149696);
    
    block_9_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_9_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 163520);
    block_9_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 163520);
    
    block_10_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_10_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 163616);
    block_10_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 163616);
    
    block_10_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_10_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 177440);
    block_10_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 177440);
    
    block_10_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_10_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 178016);
    block_10_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 178016);
    
    block_10_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_10_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 183200);
    block_10_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 183200);
    
    block_10_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_10_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 183776);
    block_10_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 183776);
    
    block_10_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_10_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 202208);
    block_10_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 202208);
    
    block_11_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_11_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 202336);
    block_11_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 202336);
    
    block_11_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_11_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 226912);
    block_11_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 226912);
    
    block_11_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_11_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 227680);
    block_11_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 227680);
    
    block_11_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_11_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 234592);
    block_11_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 234592);
    
    block_11_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_11_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 235360);
    block_11_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 235360);
    
    block_11_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_11_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 259936);
    block_11_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 259936);
    
    block_12_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_12_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 260064);
    block_12_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 260064);
    
    block_12_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_12_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 284640);
    block_12_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 284640);
    
    block_12_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_12_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 285408);
    block_12_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 285408);
    
    block_12_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_12_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 292320);
    block_12_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 292320);
    
    block_12_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_12_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 293088);
    block_12_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 293088);
    
    block_12_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_12_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 317664);
    block_12_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 317664);
    
    block_13_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_13_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 317792);
    block_13_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 317792);
    
    block_13_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_13_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 342368);
    block_13_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 342368);
    
    block_13_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_13_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 343136);
    block_13_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 343136);
    
    block_13_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_13_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 350048);
    block_13_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 350048);
    
    block_13_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_13_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 350816);
    block_13_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 350816);
    
    block_13_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_13_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 393824);
    block_13_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 393824);
    
    block_14_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_14_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 394048);
    block_14_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 394048);
    
    block_14_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_14_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 469312);
    block_14_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 469312);
    
    block_14_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_14_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 470656);
    block_14_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 470656);
    
    block_14_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_14_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 482752);
    block_14_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 482752);
    
    block_14_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_14_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 484096);
    block_14_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 484096);
    
    block_14_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_14_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 559360);
    block_14_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 559360);
    
    block_15_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_15_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 559584);
    block_15_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 559584);
    
    block_15_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_15_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 634848);
    block_15_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 634848);
    
    block_15_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_15_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 636192);
    block_15_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 636192);
    
    block_15_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_15_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 648288);
    block_15_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 648288);
    
    block_15_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_15_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 649632);
    block_15_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 649632);
    
    block_15_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_15_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 724896);
    block_15_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 724896);
    
    block_16_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_16_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 725120);
    block_16_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 725120);
    
    block_16_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_16_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 800384);
    block_16_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 800384);
    
    block_16_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_16_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 801728);
    block_16_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 801728);
    
    block_16_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_16_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 813824);
    block_16_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 813824);
    
    block_16_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_16_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 815168);
    block_16_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 815168);
    
    block_16_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_16_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 965696);
    block_16_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 965696);
    
    Conv_1_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    Conv_1_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 966144);
    Conv_1_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 966144);
    
    Conv_1_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    Conv_1_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 1539584);
    Conv_1_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1539584);
    
    dense_dense_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_dense_weights_array.data = AI_PTR(g_network_weights_map[0] + 1544704);
    dense_dense_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1544704);
    
    dense_dense_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_dense_bias_array.data = AI_PTR(g_network_weights_map[0] + 1585664);
    dense_dense_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1585664);
    
    dense_1_dense_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_1_dense_weights_array.data = AI_PTR(g_network_weights_map[0] + 1585696);
    dense_1_dense_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1585696);
    
    dense_1_dense_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_1_dense_bias_array.data = AI_PTR(g_network_weights_map[0] + 1586016);
    dense_1_dense_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1586016);
    
    Conv1_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    Conv1_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 1586056);
    Conv1_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1586056);
    
    Conv1_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    Conv1_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 1587784);
    Conv1_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1587784);
    
    expanded_conv_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    expanded_conv_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 1587848);
    expanded_conv_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1587848);
    
    expanded_conv_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    expanded_conv_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 1588424);
    expanded_conv_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1588424);
    
    expanded_conv_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    expanded_conv_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 1588488);
    expanded_conv_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1588488);
    
    expanded_conv_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    expanded_conv_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 1589000);
    expanded_conv_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1589000);
    
    block_1_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_1_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 1589032);
    block_1_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1589032);
    
    block_1_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_1_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 1590568);
    block_1_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1590568);
    
    block_1_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_1_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 1590760);
    block_1_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1590760);
    
    block_1_depthwise_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_1_depthwise_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 1592488);
    block_1_depthwise_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1592488);
    
    block_1_project_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_1_project_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 1592680);
    block_1_project_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1592680);
    
    block_1_project_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_1_project_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 1594216);
    block_1_project_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1594216);
    
    block_2_expand_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_2_expand_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 1594248);
    block_2_expand_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1594248);
    
    block_2_expand_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    block_2_expand_conv2d_bias_array.data = AI_PTR(g_network_weights_map[0] + 1595784);
    block_2_expand_conv2d_bias_array.data_start = AI_PTR(g_network_weights_map[0] + 1595784);
    
    block_2_depthwise_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    block_2_depthwise_conv2d_weights_array.data = AI_PTR(g_network_weights_map[0] + 1595976);
    block_2_depthwise_conv2d_weights_array.data_start = AI_PTR(g_network_weights_map[0] + 1595976);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/


AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 1310080,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_network_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 1310080,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_network_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_network_create(network, AI_NETWORK_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_network_data_params_get(&params) != true) {
        err = ai_network_get_error(*network);
        return err;
    }
#if defined(AI_NETWORK_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_NETWORK_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_network_init(*network, &params) != true) {
        err = ai_network_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_network_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_network_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, params);
  ok &= network_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

