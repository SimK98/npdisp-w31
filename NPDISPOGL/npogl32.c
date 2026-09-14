/*
 * NPDISP graphics API compatibility driver.
 *
 * This is an independent compatibility implementation.
 * It has not undergone the Khronos conformance process,
 * and no claim of conformance is made.
 */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <math.h>
#include <string.h>

#ifndef APIENTRY
#define APIENTRY __stdcall
#endif

/* API scalar types. */
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;

#define GL_FALSE                    0
#define GL_TRUE                     1
#define GL_COMPILE                  0x1300
#define GL_COMPILE_AND_EXECUTE      0x1301
#define GL_POINTS                   0x0000
#define GL_LINES                    0x0001
#define GL_LINE_LOOP                0x0002
#define GL_LINE_STRIP               0x0003
#define GL_TRIANGLES                0x0004
#define GL_TRIANGLE_STRIP           0x0005
#define GL_TRIANGLE_FAN             0x0006
#define GL_QUADS                    0x0007
#define GL_QUAD_STRIP               0x0008
#define GL_POLYGON                  0x0009
#define GL_2D                       0x0600
#define GL_3D                       0x0601
#define GL_3D_COLOR                 0x0602
#define GL_3D_COLOR_TEXTURE         0x0603
#define GL_4D_COLOR_TEXTURE         0x0604
#define GL_PASS_THROUGH_TOKEN       0x0700
#define GL_POINT_TOKEN              0x0701
#define GL_LINE_TOKEN               0x0702
#define GL_POLYGON_TOKEN            0x0703
#define GL_BITMAP_TOKEN             0x0704
#define GL_DRAW_PIXEL_TOKEN         0x0705
#define GL_COPY_PIXEL_TOKEN         0x0706
#define GL_LINE_RESET_TOKEN         0x0707
#define GL_RENDER                   0x1C00
#define GL_FEEDBACK                 0x1C01
#define GL_SELECT                   0x1C02
#define GL_ZERO                     0
#define GL_NONE                     0
#define GL_ONE                      1
#define GL_SRC_COLOR                0x0300
#define GL_ONE_MINUS_SRC_COLOR      0x0301
#define GL_SRC_ALPHA                0x0302
#define GL_ONE_MINUS_SRC_ALPHA      0x0303
#define GL_DST_ALPHA                0x0304
#define GL_ONE_MINUS_DST_ALPHA      0x0305
#define GL_DST_COLOR                0x0306
#define GL_ONE_MINUS_DST_COLOR      0x0307
#define GL_SRC_ALPHA_SATURATE       0x0308
#define GL_FRONT                    0x0404
#define GL_BACK                     0x0405
#define GL_FRONT_AND_BACK           0x0408
#define GL_AMBIENT                  0x1200
#define GL_DIFFUSE                  0x1201
#define GL_SPECULAR                 0x1202
#define GL_POSITION                 0x1203
#define GL_SPOT_DIRECTION           0x1204
#define GL_SPOT_EXPONENT            0x1205
#define GL_SPOT_CUTOFF              0x1206
#define GL_CONSTANT_ATTENUATION     0x1207
#define GL_LINEAR_ATTENUATION       0x1208
#define GL_QUADRATIC_ATTENUATION    0x1209
#define GL_EMISSION                 0x1600
#define GL_SHININESS                0x1601
#define GL_AMBIENT_AND_DIFFUSE      0x1602
#define GL_COLOR_INDEXES            0x1603
#define GL_LIGHT0                   0x4000
#define GL_LIGHT1                   0x4001
#define GL_LIGHT2                   0x4002
#define GL_LIGHT3                   0x4003
#define GL_LIGHT4                   0x4004
#define GL_LIGHT5                   0x4005
#define GL_LIGHT6                   0x4006
#define GL_LIGHT7                   0x4007
#define GL_INVALID_ENUM             0x0500
#define GL_INVALID_VALUE            0x0501
#define GL_INVALID_OPERATION        0x0502
#define GL_STACK_OVERFLOW           0x0503
#define GL_STACK_UNDERFLOW          0x0504
#define GL_OUT_OF_MEMORY            0x0505
#define GL_CW                       0x0900
#define GL_CCW                      0x0901
#define GL_CURRENT_COLOR            0x0B00
#define GL_CURRENT_INDEX            0x0B01
#define GL_RENDER_MODE              0x0C40
#define GL_FEEDBACK_BUFFER_POINTER  0x0DF0
#define GL_FEEDBACK_BUFFER_SIZE     0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE     0x0DF2
#define GL_SELECTION_BUFFER_POINTER 0x0DF3
#define GL_SELECTION_BUFFER_SIZE    0x0DF4
#define GL_MAX_NAME_STACK_DEPTH     0x0D37
#define GL_NAME_STACK_DEPTH         0x0D70
#define GL_POINT_SIZE               0x0B11
#define GL_POINT_SIZE_RANGE         0x0B12
#define GL_POINT_SIZE_GRANULARITY   0x0B13
#define GL_LINE_WIDTH               0x0B21
#define GL_LINE_WIDTH_RANGE         0x0B22
#define GL_LINE_WIDTH_GRANULARITY   0x0B23
#define GL_LINE_STIPPLE             0x0B24
#define GL_LINE_STIPPLE_PATTERN     0x0B25
#define GL_LINE_STIPPLE_REPEAT      0x0B26
#define GL_POLYGON_MODE             0x0B40
#define GL_POINT                    0x1B00
#define GL_LINE                     0x1B01
#define GL_FILL                     0x1B02
#define GL_CULL_FACE                0x0B44
#define GL_LIGHTING                 0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE     0x0B52
#define GL_LIGHT_MODEL_AMBIENT      0x0B53
#define GL_COLOR_MATERIAL_FACE      0x0B55
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#define GL_COLOR_MATERIAL           0x0B57
#define GL_FOG                      0x0B60
#define GL_FOG_INDEX                0x0B61
#define GL_FOG_DENSITY              0x0B62
#define GL_FOG_START                0x0B63
#define GL_FOG_END                  0x0B64
#define GL_FOG_MODE                 0x0B65
#define GL_FOG_COLOR                0x0B66
#define GL_DRAW_BUFFER               0x0C01
#define GL_INDEX_WRITEMASK           0x0C21
#define GL_COLOR_WRITEMASK            0x0C23
#define GL_SCISSOR_BOX               0x0C10
#define GL_SCISSOR_TEST              0x0C11
#define GL_POLYGON_STIPPLE           0x0B42
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_POINT_SMOOTH_HINT         0x0C51
#define GL_LINE_SMOOTH_HINT          0x0C52
#define GL_POLYGON_SMOOTH_HINT       0x0C53
#define GL_FOG_HINT                  0x0C54
#define GL_DONT_CARE                 0x1100
#define GL_FASTEST                   0x1101
#define GL_NICEST                    0x1102
#define GL_NORMALIZE                0x0BA1
#define GL_VIEWPORT                 0x0BA2
#define GL_MODELVIEW_STACK_DEPTH    0x0BA3
#define GL_PROJECTION_STACK_DEPTH   0x0BA4
#define GL_TEXTURE_STACK_DEPTH      0x0BA5
#define GL_MODELVIEW_MATRIX         0x0BA6
#define GL_PROJECTION_MATRIX        0x0BA7
#define GL_TEXTURE_MATRIX           0x0BA8
#define GL_ALPHA_TEST               0x0BC0
#define GL_BLEND                    0x0BE2
#define GL_DEPTH_RANGE              0x0B70
#define GL_DEPTH_TEST               0x0B71
#define GL_DEPTH_WRITEMASK          0x0B72
#define GL_DEPTH_FUNC               0x0B74
#define GL_MATRIX_MODE              0x0BA0
#define GL_SHADE_MODEL              0x0B54
#define GL_FLAT                     0x1D00
#define GL_SMOOTH                   0x1D01
#define GL_VENDOR                   0x1F00
#define GL_RENDERER                 0x1F01
#define GL_VERSION                  0x1F02
#define GL_EXTENSIONS               0x1F03
#define GL_NEVER                    0x0200
#define GL_LESS                     0x0201
#define GL_EQUAL                    0x0202
#define GL_LEQUAL                   0x0203
#define GL_GREATER                  0x0204
#define GL_NOTEQUAL                 0x0205
#define GL_GEQUAL                   0x0206
#define GL_ALWAYS                   0x0207
#define GL_CURRENT_BIT              0x00000001UL
#define GL_POINT_BIT                0x00000002UL
#define GL_LINE_BIT                 0x00000004UL
#define GL_POLYGON_BIT              0x00000008UL
#define GL_POLYGON_STIPPLE_BIT      0x00000010UL
#define GL_PIXEL_MODE_BIT           0x00000020UL
#define GL_LIGHTING_BIT             0x00000040UL
#define GL_FOG_BIT                  0x00000080UL
#define GL_DEPTH_BUFFER_BIT         0x00000100UL
#define GL_ACCUM_BUFFER_BIT         0x00000200UL
#define GL_STENCIL_BUFFER_BIT       0x00000400UL
#define GL_VIEWPORT_BIT             0x00000800UL
#define GL_TRANSFORM_BIT            0x00001000UL
#define GL_ENABLE_BIT               0x00002000UL
#define GL_COLOR_BUFFER_BIT         0x00004000UL
#define GL_HINT_BIT                 0x00008000UL
#define GL_EVAL_BIT                 0x00010000UL
#define GL_LIST_BIT                 0x00020000UL
#define GL_TEXTURE_BIT              0x00040000UL
#define GL_SCISSOR_BIT              0x00080000UL
#define GL_ALL_ATTRIB_BITS          0x000FFFFFUL
#define GL_STENCIL_TEST             0x0B90
#define GL_STENCIL_CLEAR_VALUE      0x0B91
#define GL_STENCIL_FUNC             0x0B92
#define GL_STENCIL_VALUE_MASK       0x0B93
#define GL_STENCIL_FAIL             0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL  0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS  0x0B96
#define GL_STENCIL_REF              0x0B97
#define GL_STENCIL_WRITEMASK        0x0B98
#define GL_STENCIL_BITS             0x0D57
#define GL_ACCUM_RED_BITS           0x0D58
#define GL_ACCUM_GREEN_BITS         0x0D59
#define GL_ACCUM_BLUE_BITS          0x0D5A
#define GL_ACCUM_ALPHA_BITS         0x0D5B
#define GL_KEEP                     0x1E00
#define GL_REPLACE                  0x1E01
#define GL_INCR                     0x1E02
#define GL_DECR                     0x1E03
#define GL_INVERT                   0x150A
#define GL_CLEAR                    0x1500
#define GL_AND                      0x1501
#define GL_AND_REVERSE              0x1502
#define GL_COPY                     0x1503
#define GL_AND_INVERTED             0x1504
#define GL_NOOP                     0x1505
#define GL_XOR                      0x1506
#define GL_OR                       0x1507
#define GL_NOR                      0x1508
#define GL_EQUIV                    0x1509
#define GL_OR_REVERSE               0x150B
#define GL_COPY_INVERTED            0x150C
#define GL_OR_INVERTED              0x150D
#define GL_NAND                     0x150E
#define GL_SET                      0x150F
#define GL_INDEX_LOGIC_OP           0x0BF1
#define GL_COLOR_LOGIC_OP           0x0BF2
#define GL_LOGIC_OP_MODE            0x0BF0
#define GL_CLIP_PLANE0              0x3000
#define GL_CLIP_PLANE1              0x3001
#define GL_CLIP_PLANE2              0x3002
#define GL_CLIP_PLANE3              0x3003
#define GL_CLIP_PLANE4              0x3004
#define GL_CLIP_PLANE5              0x3005
#define GL_MAX_CLIP_PLANES          0x0D32
#define GL_MODELVIEW                0x1700
#define GL_PROJECTION               0x1701
#define GL_TEXTURE                  0x1702
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH  0x0D39
#define GL_MAX_TEXTURE_SIZE         0x0D33
#define GL_ATTRIB_STACK_DEPTH       0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#define GL_MAX_ATTRIB_STACK_DEPTH   0x0D35
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
#define GL_EDGE_FLAG                0x0B43
#define GL_CLIENT_PIXEL_STORE_BIT   0x00000001UL
#define GL_CLIENT_VERTEX_ARRAY_BIT  0x00000002UL
#define GL_CLIENT_ALL_ATTRIB_BITS   0xFFFFFFFFUL
#define GL_TEXTURE_1D              0x0DE0
#define GL_TEXTURE_2D              0x0DE1
#define GL_TEXTURE_ENV             0x2300
#define GL_TEXTURE_ENV_MODE        0x2200
#define GL_TEXTURE_GEN_S           0x0C60
#define GL_TEXTURE_GEN_T           0x0C61
#define GL_TEXTURE_GEN_R           0x0C62
#define GL_TEXTURE_GEN_Q           0x0C63
#define GL_S                       0x2000
#define GL_T                       0x2001
#define GL_R                       0x2002
#define GL_Q                       0x2003
#define GL_EYE_LINEAR              0x2400
#define GL_OBJECT_LINEAR           0x2401
#define GL_SPHERE_MAP              0x2402
#define GL_TEXTURE_GEN_MODE        0x2500
#define GL_OBJECT_PLANE            0x2501
#define GL_EYE_PLANE               0x2502
#define GL_MODULATE                0x2100
#define GL_DECAL                   0x2101
#define GL_TEXTURE_MAG_FILTER      0x2800
#define GL_TEXTURE_MIN_FILTER      0x2801
#define GL_TEXTURE_WRAP_S          0x2802
#define GL_TEXTURE_WRAP_T          0x2803
#define GL_NEAREST                 0x2600
#define GL_LINEAR                  0x2601
#define GL_NEAREST_MIPMAP_NEAREST  0x2700
#define GL_LINEAR_MIPMAP_NEAREST   0x2701
#define GL_NEAREST_MIPMAP_LINEAR   0x2702
#define GL_LINEAR_MIPMAP_LINEAR    0x2703
#define GL_CLAMP                   0x2900
#define GL_REPEAT                  0x2901
#define GL_EXP                     0x0800
#define GL_EXP2                    0x0801
#define GL_RGB                     0x1907
#define GL_RGBA                    0x1908
#define GL_BGRA_EXT                0x80E1
#define GL_BYTE                    0x1400
#define GL_UNSIGNED_BYTE           0x1401
#define GL_SHORT                   0x1402
#define GL_UNSIGNED_SHORT          0x1403
#define GL_INT                     0x1404
#define GL_UNSIGNED_INT            0x1405
#define GL_FLOAT                   0x1406
#define GL_2_BYTES                 0x1407
#define GL_3_BYTES                 0x1408
#define GL_4_BYTES                 0x1409
#define GL_DOUBLE                  0x140A
#define GL_PACK_SWAP_BYTES          0x0D00
#define GL_PACK_LSB_FIRST           0x0D01
#define GL_PACK_ROW_LENGTH          0x0D02
#define GL_PACK_SKIP_ROWS           0x0D03
#define GL_PACK_SKIP_PIXELS         0x0D04
#define GL_PACK_ALIGNMENT           0x0D05
#define GL_UNPACK_SWAP_BYTES        0x0CF0
#define GL_UNPACK_LSB_FIRST         0x0CF1
#define GL_UNPACK_ROW_LENGTH        0x0CF2
#define GL_UNPACK_SKIP_ROWS         0x0CF3
#define GL_UNPACK_SKIP_PIXELS       0x0CF4
#define GL_UNPACK_ALIGNMENT         0x0CF5
#define GL_CURRENT_RASTER_COLOR     0x0B04
#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
#define GL_CURRENT_RASTER_POSITION  0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
#define GL_CURRENT_RASTER_DISTANCE  0x0B09
#define GL_ACCUM_CLEAR_VALUE        0x0B80
#define GL_READ_BUFFER              0x0C02
#define GL_ZOOM_X                   0x0D16
#define GL_ZOOM_Y                   0x0D17
#define GL_MAP_COLOR                0x0D10
#define GL_MAP_STENCIL              0x0D11
#define GL_INDEX_SHIFT              0x0D12
#define GL_INDEX_OFFSET             0x0D13
#define GL_RED_SCALE                0x0D14
#define GL_RED_BIAS                 0x0D15
#define GL_GREEN_SCALE              0x0D18
#define GL_GREEN_BIAS               0x0D19
#define GL_BLUE_SCALE               0x0D1A
#define GL_BLUE_BIAS                0x0D1B
#define GL_ALPHA_SCALE              0x0D1C
#define GL_ALPHA_BIAS               0x0D1D
#define GL_DEPTH_SCALE              0x0D1E
#define GL_DEPTH_BIAS               0x0D1F
#define GL_PIXEL_MAP_I_TO_I         0x0C70
#define GL_PIXEL_MAP_S_TO_S         0x0C71
#define GL_PIXEL_MAP_I_TO_R         0x0C72
#define GL_PIXEL_MAP_I_TO_G         0x0C73
#define GL_PIXEL_MAP_I_TO_B         0x0C74
#define GL_PIXEL_MAP_I_TO_A         0x0C75
#define GL_PIXEL_MAP_R_TO_R         0x0C76
#define GL_PIXEL_MAP_G_TO_G         0x0C77
#define GL_PIXEL_MAP_B_TO_B         0x0C78
#define GL_PIXEL_MAP_A_TO_A         0x0C79
#define GL_PIXEL_MAP_I_TO_I_SIZE    0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE    0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE    0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE    0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE    0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE    0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE    0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE    0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE    0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE    0x0CB9
#define GL_MAX_PIXEL_MAP_TABLE      0x0D34
#define GL_MAX_EVAL_ORDER           0x0D30
#define GL_AUTO_NORMAL              0x0D80
#define GL_MAP1_COLOR_4             0x0D90
#define GL_MAP1_INDEX               0x0D91
#define GL_MAP1_NORMAL              0x0D92
#define GL_MAP1_TEXTURE_COORD_1     0x0D93
#define GL_MAP1_TEXTURE_COORD_2     0x0D94
#define GL_MAP1_TEXTURE_COORD_3     0x0D95
#define GL_MAP1_TEXTURE_COORD_4     0x0D96
#define GL_MAP1_VERTEX_3            0x0D97
#define GL_MAP1_VERTEX_4            0x0D98
#define GL_MAP2_COLOR_4             0x0DB0
#define GL_MAP2_INDEX               0x0DB1
#define GL_MAP2_NORMAL              0x0DB2
#define GL_MAP2_TEXTURE_COORD_1     0x0DB3
#define GL_MAP2_TEXTURE_COORD_2     0x0DB4
#define GL_MAP2_TEXTURE_COORD_3     0x0DB5
#define GL_MAP2_TEXTURE_COORD_4     0x0DB6
#define GL_MAP2_VERTEX_3            0x0DB7
#define GL_MAP2_VERTEX_4            0x0DB8
#define GL_MAP1_GRID_DOMAIN         0x0DD0
#define GL_MAP1_GRID_SEGMENTS       0x0DD1
#define GL_MAP2_GRID_DOMAIN         0x0DD2
#define GL_MAP2_GRID_SEGMENTS       0x0DD3
#define GL_COEFF                    0x0A00
#define GL_ORDER                    0x0A01
#define GL_DOMAIN                   0x0A02
#define GL_COLOR                    0x1800
#define GL_ACCUM                    0x0100
#define GL_LOAD                     0x0101
#define GL_RETURN                   0x0102
#define GL_MULT                     0x0103
#define GL_ADD                      0x0104
#define GL_TEXTURE_WIDTH           0x1000
#define GL_TEXTURE_HEIGHT          0x1001
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_BINDING_1D      0x8068
#define GL_TEXTURE_BINDING_2D      0x8069
#define GL_VERTEX_ARRAY            0x8074
#define GL_NORMAL_ARRAY            0x8075
#define GL_COLOR_ARRAY             0x8076
#define GL_INDEX_ARRAY             0x8077
#define GL_TEXTURE_COORD_ARRAY     0x8078
#define GL_EDGE_FLAG_ARRAY         0x8079
#define GL_VERTEX_ARRAY_SIZE       0x807A
#define GL_VERTEX_ARRAY_TYPE       0x807B
#define GL_VERTEX_ARRAY_STRIDE     0x807C
#define GL_NORMAL_ARRAY_TYPE       0x807E
#define GL_NORMAL_ARRAY_STRIDE     0x807F
#define GL_COLOR_ARRAY_SIZE        0x8081
#define GL_COLOR_ARRAY_TYPE        0x8082
#define GL_COLOR_ARRAY_STRIDE      0x8083
#define GL_INDEX_ARRAY_TYPE        0x8085
#define GL_INDEX_ARRAY_STRIDE      0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE   0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE   0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE     0x808C
#define GL_VERTEX_ARRAY_POINTER       0x808E
#define GL_NORMAL_ARRAY_POINTER       0x808F
#define GL_COLOR_ARRAY_POINTER        0x8090
#define GL_INDEX_ARRAY_POINTER        0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER    0x8093
#define GL_V2F                         0x2A20
#define GL_V3F                         0x2A21
#define GL_C4UB_V2F                    0x2A22
#define GL_C4UB_V3F                    0x2A23
#define GL_C3F_V3F                     0x2A24
#define GL_N3F_V3F                     0x2A25
#define GL_C4F_N3F_V3F                 0x2A26
#define GL_T2F_V3F                     0x2A27
#define GL_T4F_V4F                     0x2A28
#define GL_T2F_C4UB_V3F                0x2A29
#define GL_T2F_C3F_V3F                 0x2A2A
#define GL_T2F_N3F_V3F                 0x2A2B
#define GL_T2F_C4F_N3F_V3F             0x2A2C
#define GL_T4F_C4F_N3F_V4F             0x2A2D

#define NPDISP_EXEC_MAGIC_LOW       0x0000504eUL
#define NPDISP_EXEC_PORT            0x07e9
#define NPDISP_EXEC_COMMAND         0x46
#define NPDISP_FUNCORDER_OGL32_DISPATCH 0xfe31UL

#define NPDISP_OGL_BRIDGE_VERSION       0x0001000BUL
#define NPDISP_OGL_CMD_QUERY            0x0001UL
#define NPDISP_OGL_CMD_CONTEXT_CREATE   0x0002UL
#define NPDISP_OGL_CMD_CONTEXT_DESTROY  0x0003UL
#define NPDISP_OGL_CMD_CLEAR            0x0004UL
#define NPDISP_OGL_CMD_DRAW             0x0005UL
#define NPDISP_OGL_CMD_SWAP             0x0006UL
#define NPDISP_OGL_CMD_TEXTURE_UPLOAD   0x0007UL
#define NPDISP_OGL_CMD_READ_PIXELS      0x0008UL
#define NPDISP_OGL_CMD_DRAW_PIXELS      0x0009UL
#define NPDISP_OGL_CMD_COPY_PIXELS      0x000AUL
#define NPDISP_OGL_CMD_LIST_UPLOAD      0x000BUL
#define NPDISP_OGL_CMD_LIST_DELETE      0x000CUL
#define NPDISP_OGL_CMD_LIST_EXEC        0x000DUL
#define NPDISP_OGL_CMD_TEXTURE_DELETE   0x000EUL
#define NPDISP_OGL_PIXEL_BACK           0UL
#define NPDISP_OGL_PIXEL_FRONT          1UL
#define NPDISP_OGL_CLEAR_COLOR          0x0001UL
#define NPDISP_OGL_CLEAR_DEPTH          0x0002UL
#define NPDISP_OGL_CLEAR_STENCIL        0x0004UL
#define NPDISP_OGL_STENCIL_KEEP         1UL
#define NPDISP_OGL_STENCIL_ZERO         2UL
#define NPDISP_OGL_STENCIL_REPLACE      3UL
#define NPDISP_OGL_STENCIL_INCR         4UL
#define NPDISP_OGL_STENCIL_DECR         5UL
#define NPDISP_OGL_STENCIL_INVERT       6UL

#define NPDISP_OGL_DEPTH_NEVER          1UL
#define NPDISP_OGL_DEPTH_LESS           2UL
#define NPDISP_OGL_DEPTH_EQUAL          3UL
#define NPDISP_OGL_DEPTH_LEQUAL         4UL
#define NPDISP_OGL_DEPTH_GREATER        5UL
#define NPDISP_OGL_DEPTH_NOTEQUAL       6UL
#define NPDISP_OGL_DEPTH_GEQUAL         7UL
#define NPDISP_OGL_DEPTH_ALWAYS         8UL
#define NPDISP_OGL_BLEND_ZERO           1UL
#define NPDISP_OGL_BLEND_ONE            2UL
#define NPDISP_OGL_BLEND_SRCCOLOR       3UL
#define NPDISP_OGL_BLEND_INVSRCCOLOR    4UL
#define NPDISP_OGL_BLEND_SRCALPHA       5UL
#define NPDISP_OGL_BLEND_INVSRCALPHA    6UL
#define NPDISP_OGL_BLEND_DESTALPHA      7UL
#define NPDISP_OGL_BLEND_INVDESTALPHA   8UL
#define NPDISP_OGL_BLEND_DESTCOLOR      9UL
#define NPDISP_OGL_BLEND_INVDESTCOLOR   10UL
#define NPDISP_OGL_BLEND_SRCALPHASAT    11UL
#define NPDISP_OGL_CULL_NONE            1UL
#define NPDISP_OGL_CULL_CW              2UL
#define NPDISP_OGL_CULL_CCW             3UL
#define NPDISP_OGL_TEXENV_MODULATE      1UL
#define NPDISP_OGL_TEXENV_REPLACE       2UL
#define NPDISP_OGL_TEXENV_DECAL         3UL
#define NPDISP_OGL_TEXADDR_WRAP         1UL
#define NPDISP_OGL_TEXADDR_CLAMP        2UL
#define NPDISP_OGL_TEXFILTER_POINT      1UL
#define NPDISP_OGL_TEXFILTER_LINEAR     2UL

#define OPENGL_VERSION_100_ENTRIES       306
#define OPENGL_VERSION_110_ENTRIES       336

#pragma pack(push, 1)
typedef struct {
    DWORD size;
    DWORD version;
    DWORD width;
    DWORD height;
    DWORD bpp;
} NPDISP_OGL_QUERY32;

typedef struct {
    DWORD size;
    DWORD context;
} NPDISP_OGL_CONTEXT32;

typedef struct {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} NPDISP_OGL_CLIPRECT32;

typedef struct {
    DWORD size;
    DWORD context;
    DWORD clipValid;
    DWORD clipCount;
    DWORD clipRects;
} NPDISP_OGL_SWAP32;

typedef struct {
    DWORD size;
    DWORD context;
    LONG x;
    LONG y;
    DWORD width;
    DWORD height;
    DWORD flags;
    DWORD color;
    DWORD depth;
    DWORD scissorEnable;
    LONG scissorX;
    LONG scissorY;
    DWORD scissorWidth;
    DWORD scissorHeight;
    DWORD stencil;
    DWORD stencilBits;
    DWORD stencilWriteMask;
    DWORD colorWriteDisableMask;
} NPDISP_OGL_CLEAR32;

typedef struct {
    float x;
    float y;
    float z;
    float rhw;
    DWORD diffuse;
    float tu;
    float tv;
    float clip[4];
    float texcoord[4];
    float clipDistance[6];
} NPDISP_OGL_VERTEX32;

typedef struct {
    DWORD size;
    DWORD context;
    DWORD primitive;
    DWORD vertexCount;
    DWORD vertices;
    LONG x;
    LONG y;
    DWORD width;
    DWORD height;
    DWORD shadeMode;
    DWORD depthEnable;
    DWORD depthWrite;
    DWORD depthFunc;
    DWORD blendEnable;
    DWORD srcBlend;
    DWORD destBlend;
    DWORD alphaTestEnable;
    DWORD alphaFunc;
    DWORD alphaRef;
    DWORD cullMode;
    DWORD textureEnable;
    DWORD textureId;
    DWORD textureEnvMode;
    DWORD textureWrapS;
    DWORD textureWrapT;
    DWORD textureMinFilter;
    DWORD textureMagFilter;
    DWORD scissorEnable;
    LONG scissorX;
    LONG scissorY;
    DWORD scissorWidth;
    DWORD scissorHeight;
    DWORD stencilEnable;
    DWORD stencilBits;
    DWORD stencilFunc;
    DWORD stencilRef;
    DWORD stencilReadMask;
    DWORD stencilWriteMask;
    DWORD stencilFail;
    DWORD stencilZFail;
    DWORD stencilPass;
    float pointSize;
    float lineWidth;
    DWORD lineStippleEnable;
    DWORD lineStippleFactor;
    DWORD lineStipplePattern;
    DWORD polygonStippleEnable;
    GLubyte polygonStipple[128];
    DWORD polygonModeFront;
    DWORD polygonModeBack;
    DWORD frontFace;
    DWORD colorWriteDisableMask;
    DWORD logicOpEnable;
    DWORD logicOp;
    DWORD clipPlaneMask;
    LONG viewportX;
    LONG viewportY;
    DWORD viewportWidth;
    DWORD viewportHeight;
    float depthNear;
    float depthFar;
} NPDISP_OGL_DRAW32;

typedef struct {
    DWORD size;
    DWORD context;
    DWORD textureId;
    DWORD revision;
    DWORD width;
    DWORD height;
    DWORD pixels;
    DWORD hasAlpha;
} NPDISP_OGL_TEXTURE32;

typedef struct {
    DWORD size;
    DWORD context;
    DWORD textureId;
} NPDISP_OGL_TEXTURE_DELETE32;

typedef struct {
    DWORD size;
    DWORD context;
    LONG x;
    LONG y;
    DWORD width;
    DWORD height;
    DWORD pixels;
    DWORD buffer;
    LONG dstX;
    LONG dstY;
    DWORD scissorEnable;
    LONG scissorX;
    LONG scissorY;
    DWORD scissorWidth;
    DWORD scissorHeight;
    GLfloat zoomX;
    GLfloat zoomY;
    DWORD colorWriteDisableMask;
    DWORD logicOpEnable;
    DWORD logicOp;
} NPDISP_OGL_PIXELS32;

typedef struct {
    DWORD enabled;
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat position[4];
    GLfloat spotDirection[3];
    GLfloat spotExponent;
    GLfloat spotCutoff;
    GLfloat constantAttenuation;
    GLfloat linearAttenuation;
    GLfloat quadraticAttenuation;
} NPDISP_OGL_LIST_LIGHT32;

typedef struct {
    DWORD size;
    DWORD context;
    DWORD list;
    DWORD commandCount;
    DWORD commands;
} NPDISP_OGL_LIST_UPLOAD32;

typedef struct {
    DWORD size;
    DWORD context;
    DWORD list;
    DWORD range;
} NPDISP_OGL_LIST_DELETE32;

typedef struct {
    DWORD size;
    DWORD context;
    DWORD listCount;
    DWORD lists;
    NPDISP_OGL_DRAW32 draw;
    GLfloat modelview[16];
    GLfloat projection[16];
    GLfloat texture[16];
    LONG viewport[4];
    DWORD matrixMode;
    GLfloat depthNear;
    GLfloat depthFar;
    GLfloat currentColor[4];
    GLfloat currentNormal[3];
    GLfloat currentTexCoord[4];
    DWORD lighting;
    DWORD normalize;
    DWORD colorMaterial;
    DWORD colorMaterialMode;
    GLfloat lightModelAmbient[4];
    DWORD lightModelLocalViewer;
    NPDISP_OGL_LIST_LIGHT32 lights[8];
    GLfloat materialAmbient[4];
    GLfloat materialDiffuse[4];
    GLfloat materialSpecular[4];
    GLfloat materialEmission[4];
    GLfloat materialShininess;
    DWORD fog;
    DWORD fogMode;
    GLfloat fogColor[4];
    GLfloat fogDensity;
    GLfloat fogStart;
    GLfloat fogEnd;
    DWORD texGenEnabled[4];
    DWORD texGenMode[4];
    GLfloat texGenObjectPlane[16];
    GLfloat texGenEyePlane[16];
} NPDISP_OGL_LIST_EXEC32;
#pragma pack(pop)

typedef ULONG DHGLRC;
typedef struct {
    int cEntries;
    PROC entries[OPENGL_VERSION_110_ENTRIES];
} GLCLTPROCTABLE, *PGLCLTPROCTABLE;
typedef VOID (APIENTRY *PFN_SETPROCTABLE)(PGLCLTPROCTABLE);

typedef struct _NPGL_TEXTURE_OBJECT {
    GLuint name;
    GLboolean boundOnce;
    GLboolean defined;
    GLboolean hasAlpha;
    GLsizei width;
    GLsizei height;
    GLint internalFormat;
    GLenum target;
    DWORD revision;
    DWORD hostId;
    DWORD hostRevision;
    GLenum wrapS;
    GLenum wrapT;
    GLenum minFilter;
    GLenum magFilter;
    BYTE *pixels;
    DWORD pixelBytes;
    struct _NPGL_TEXTURE_OBJECT *next;
} NPGL_TEXTURE_OBJECT;

typedef struct {
    GLboolean enabled;
    GLint size;
    GLenum type;
    GLsizei stride;
    const GLvoid *pointer;
} NPGL_ARRAY_STATE;

#define NPGL_MAX_PIXEL_MAP_TABLE 256
typedef struct {
    GLint size;
    GLfloat values[NPGL_MAX_PIXEL_MAP_TABLE];
} NPGL_PIXEL_MAP;

#define NPGL_MAX_EVAL_ORDER 8
#define NPGL_EVAL_TARGET_COUNT 9

typedef struct {
    GLint components;
    GLint order;
    GLfloat u1;
    GLfloat u2;
    GLfloat points[NPGL_MAX_EVAL_ORDER * 4];
    GLboolean enabled;
} NPGL_EVAL_MAP1;

typedef struct {
    GLint components;
    GLint uorder;
    GLint vorder;
    GLfloat u1;
    GLfloat u2;
    GLfloat v1;
    GLfloat v2;
    GLfloat points[NPGL_MAX_EVAL_ORDER * NPGL_MAX_EVAL_ORDER * 4];
    GLboolean enabled;
} NPGL_EVAL_MAP2;

typedef struct {
    GLenum target;
    GLint dimension;
    GLint components;
    GLint uorder;
    GLint vorder;
    GLfloat u1;
    GLfloat u2;
    GLfloat v1;
    GLfloat v2;
    GLfloat points[NPGL_MAX_EVAL_ORDER * NPGL_MAX_EVAL_ORDER * 4];
} NPGL_LIST_EVAL_MAP;

typedef struct {
    GLboolean enabled;
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat position[4];
    GLfloat spotDirection[3];
    GLfloat spotExponent;
    GLfloat spotCutoff;
    GLfloat constantAttenuation;
    GLfloat linearAttenuation;
    GLfloat quadraticAttenuation;
} NPGL_LIGHT;

typedef struct {
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat emission[4];
    GLfloat shininess;
} NPGL_MATERIAL;

#define NPGL_LIST_OP_BEGIN          1
#define NPGL_LIST_OP_END            2
#define NPGL_LIST_OP_COLOR4F        3
#define NPGL_LIST_OP_NORMAL3F       4
#define NPGL_LIST_OP_TEXCOORD2F     5
#define NPGL_LIST_OP_VERTEX4F       6
#define NPGL_LIST_OP_CALL_LIST      7
#define NPGL_LIST_OP_CALL_OFFSET    8
#define NPGL_LIST_OP_LIST_BASE      9
#define NPGL_LIST_OP_MATRIX_MODE   10
#define NPGL_LIST_OP_LOAD_IDENTITY 11
#define NPGL_LIST_OP_LOAD_MATRIX   12
#define NPGL_LIST_OP_MULT_MATRIX   13
#define NPGL_LIST_OP_TRANSLATE     14
#define NPGL_LIST_OP_SCALE         15
#define NPGL_LIST_OP_ROTATE        16
#define NPGL_LIST_OP_PUSH_MATRIX   17
#define NPGL_LIST_OP_POP_MATRIX    18
#define NPGL_LIST_OP_ENABLE        19
#define NPGL_LIST_OP_DISABLE       20
#define NPGL_LIST_OP_DEPTH_MASK    21
#define NPGL_LIST_OP_DEPTH_FUNC    22
#define NPGL_LIST_OP_ALPHA_FUNC    23
#define NPGL_LIST_OP_BLEND_FUNC    24
#define NPGL_LIST_OP_POINT_SIZE    25
#define NPGL_LIST_OP_LINE_WIDTH    26
#define NPGL_LIST_OP_LINE_STIPPLE  27
#define NPGL_LIST_OP_POLYGON_MODE  28
#define NPGL_LIST_OP_SHADE_MODEL   29
#define NPGL_LIST_OP_CULL_FACE     30
#define NPGL_LIST_OP_FRONT_FACE    31
#define NPGL_LIST_OP_SCISSOR       32
#define NPGL_LIST_OP_HINT          33
#define NPGL_LIST_OP_CLEAR_COLOR   34
#define NPGL_LIST_OP_CLEAR_DEPTH   35
#define NPGL_LIST_OP_CLEAR_STENCIL 36
#define NPGL_LIST_OP_STENCIL_FUNC  37
#define NPGL_LIST_OP_STENCIL_MASK  38
#define NPGL_LIST_OP_STENCIL_OP    39
#define NPGL_LIST_OP_VIEWPORT      40
#define NPGL_LIST_OP_DEPTH_RANGE   41
#define NPGL_LIST_OP_ORTHO         42
#define NPGL_LIST_OP_FRUSTUM       43
#define NPGL_LIST_OP_CLEAR         44
#define NPGL_LIST_OP_COLOR_MATERIAL 45
#define NPGL_LIST_OP_FOG            46
#define NPGL_LIST_OP_LIGHT          47
#define NPGL_LIST_OP_LIGHT_MODEL    48
#define NPGL_LIST_OP_MATERIAL       49
#define NPGL_LIST_OP_TEX_PARAMETERI 50
#define NPGL_LIST_OP_TEX_ENVI       51
#define NPGL_LIST_OP_BIND_TEXTURE   52
#define NPGL_LIST_OP_TEXCOORD4F      53
#define NPGL_LIST_OP_DRAW_BUFFER      54
#define NPGL_LIST_OP_COLOR_MASK       55
#define NPGL_LIST_OP_CLEAR_INDEX       56
#define NPGL_LIST_OP_INDEX_MASK        57
#define NPGL_LIST_OP_INDEX             58
#define NPGL_LIST_OP_CLEAR_ACCUM       59
#define NPGL_LIST_OP_ACCUM             60
#define NPGL_LIST_OP_PUSH_ATTRIB        61
#define NPGL_LIST_OP_POP_ATTRIB         62
#define NPGL_LIST_OP_EDGE_FLAG          63
#define NPGL_LIST_OP_BITMAP             64
#define NPGL_LIST_OP_PIXEL_TRANSFER     65
#define NPGL_LIST_OP_PIXEL_MAP          66
#define NPGL_LIST_OP_CLIP_PLANE         67
#define NPGL_LIST_OP_LOGIC_OP           68
#define NPGL_LIST_OP_MAP1               69
#define NPGL_LIST_OP_MAP2               70
#define NPGL_LIST_OP_MAP_GRID1          71
#define NPGL_LIST_OP_MAP_GRID2          72
#define NPGL_LIST_OP_EVAL_COORD1        73
#define NPGL_LIST_OP_EVAL_COORD2        74
#define NPGL_LIST_OP_EVAL_MESH1         75
#define NPGL_LIST_OP_EVAL_MESH2         76
#define NPGL_LIST_OP_EVAL_POINT1        77
#define NPGL_LIST_OP_EVAL_POINT2        78
#define NPGL_LIST_OP_INIT_NAMES         79
#define NPGL_LIST_OP_LOAD_NAME          80
#define NPGL_LIST_OP_PASS_THROUGH       81
#define NPGL_LIST_OP_POP_NAME           82
#define NPGL_LIST_OP_PUSH_NAME          83

typedef struct {
    DWORD op;
    DWORD u[4];
    GLfloat f[16];
} NPGL_LIST_COMMAND;

typedef struct NPGL_DISPLAY_LIST {
    GLuint name;
    GLboolean defined;
    GLboolean hostCached;
    GLboolean finalColorSet;
    GLboolean finalNormalSet;
    GLboolean finalTexCoordSet;
    GLboolean finalFrontFaceSet;
    GLboolean finalTranslateSet;
    GLfloat finalColor[4];
    GLfloat finalNormal[3];
    GLfloat finalTexCoord[4];
    GLenum finalFrontFace;
    GLfloat finalTranslate[3];
    NPGL_LIST_COMMAND *commands;
    DWORD commandCount;
    DWORD commandCapacity;
    struct NPGL_DISPLAY_LIST *next;
} NPGL_DISPLAY_LIST;

typedef struct {
    GLbitfield mask;
    GLfloat currentColor[4];
    GLfloat currentIndex;
    GLboolean currentEdgeFlag;
    GLfloat currentNormal[3];
    GLfloat currentTexCoord[4];
    GLfloat rasterPosition[4];
    GLfloat rasterColor[4];
    GLfloat rasterTexCoord[4];
    GLfloat rasterDistance;
    GLboolean rasterValid;
    GLfloat pointSize;
    GLfloat lineWidth;
    GLboolean lineStipple;
    GLint lineStippleFactor;
    GLushort lineStipplePattern;
    GLboolean cullFaceEnable;
    GLenum cullFace;
    GLenum frontFace;
    GLenum polygonModeFront;
    GLenum polygonModeBack;
    GLboolean polygonStipple;
    GLubyte polygonStipplePattern[128];
    GLenum readBuffer;
    GLfloat pixelZoomX;
    GLfloat pixelZoomY;
    GLboolean mapColor;
    GLboolean mapStencil;
    GLint indexShift;
    GLint indexOffset;
    GLfloat redScale;
    GLfloat redBias;
    GLfloat greenScale;
    GLfloat greenBias;
    GLfloat blueScale;
    GLfloat blueBias;
    GLfloat alphaScale;
    GLfloat alphaBias;
    GLfloat depthScale;
    GLfloat depthBias;
    NPGL_PIXEL_MAP pixelMaps[10];
    GLboolean lighting;
    GLboolean normalize;
    GLboolean colorMaterial;
    GLenum colorMaterialFace;
    GLenum colorMaterialMode;
    GLfloat lightModelAmbient[4];
    GLboolean lightModelLocalViewer;
    GLboolean lightModelTwoSide;
    NPGL_LIGHT lights[8];
    NPGL_MATERIAL material;
    GLboolean fog;
    GLenum fogMode;
    GLfloat fogColor[4];
    GLfloat fogDensity;
    GLfloat fogStart;
    GLfloat fogEnd;
    GLboolean depthTest;
    GLboolean depthWrite;
    GLenum depthFunc;
    GLclampd clearDepth;
    GLfloat clearAccum[4];
    GLboolean stencilTest;
    GLenum stencilFunc;
    GLint stencilRef;
    GLuint stencilValueMask;
    GLuint stencilWriteMask;
    GLenum stencilFail;
    GLenum stencilZFail;
    GLenum stencilPass;
    GLint clearStencil;
    GLint viewport[4];
    GLclampd depthNear;
    GLclampd depthFar;
    GLenum matrixMode;
    GLboolean blend;
    GLenum srcBlend;
    GLenum destBlend;
    GLboolean alphaTest;
    GLenum alphaFunc;
    GLclampf alphaRef;
    GLfloat clearColor[4];
    GLfloat clearIndex;
    GLenum drawBuffer;
    GLboolean colorMask[4];
    GLuint indexMask;
    GLboolean colorLogicOp;
    GLboolean indexLogicOp;
    GLenum logicOpMode;
    GLboolean clipPlaneEnabled[6];
    GLdouble clipPlane[6][4];
    GLenum perspectiveHint;
    GLenum pointSmoothHint;
    GLenum lineSmoothHint;
    GLenum polygonSmoothHint;
    GLenum fogHint;
    GLuint listBase;
    GLboolean texture1D;
    GLboolean texture2D;
    GLenum textureEnvMode;
    GLuint boundTexture1D;
    GLuint boundTexture2D;
    GLboolean texGenEnabled[4];
    GLenum texGenMode[4];
    GLfloat texGenObjectPlane[4][4];
    GLfloat texGenEyePlane[4][4];
    GLboolean evalMap1Enabled[NPGL_EVAL_TARGET_COUNT];
    GLboolean evalMap2Enabled[NPGL_EVAL_TARGET_COUNT];
    GLboolean autoNormal;
    GLint map1GridSegments;
    GLfloat map1GridDomain[2];
    GLint map2GridSegments[2];
    GLfloat map2GridDomain[4];
    GLboolean scissorTest;
    GLint scissorBox[4];
    GLboolean scissorSet;
} NPGL_ATTRIB_STATE;

typedef struct {
    GLbitfield mask;
    GLint packAlignment;
    GLint packRowLength;
    GLint packSkipRows;
    GLint packSkipPixels;
    GLboolean packSwapBytes;
    GLboolean packLsbFirst;
    GLint unpackAlignment;
    GLint unpackRowLength;
    GLint unpackSkipRows;
    GLint unpackSkipPixels;
    GLboolean unpackSwapBytes;
    GLboolean unpackLsbFirst;
    NPGL_ARRAY_STATE vertexArray;
    NPGL_ARRAY_STATE normalArray;
    NPGL_ARRAY_STATE colorArray;
    NPGL_ARRAY_STATE indexArray;
    NPGL_ARRAY_STATE texCoordArray;
    NPGL_ARRAY_STATE edgeFlagArray;
} NPGL_CLIENT_ATTRIB_STATE;

typedef struct {
    HDC hdc;
    HWND drawableWindow;
    GLint pixelFormat;
    GLboolean doubleBuffered;
    DWORD bridgeContext;
    LONG drawX;
    LONG drawY;
    DWORD drawWidth;
    DWORD drawHeight;
    DWORD screenWidth;
    DWORD screenHeight;
    GLboolean drawableValid;
    GLboolean drawableDirty;
    GLenum error;
    GLboolean inBegin;
    GLenum beginMode;
    NPDISP_OGL_VERTEX32 *vertices;
    DWORD vertexCount;
    DWORD vertexCapacity;
    GLfloat currentColor[4];
    GLfloat currentIndex;
    GLboolean currentEdgeFlag;
    GLfloat currentNormal[3];
    GLboolean lighting;
    GLboolean normalize;
    GLboolean colorMaterial;
    GLenum colorMaterialFace;
    GLenum colorMaterialMode;
    GLfloat lightModelAmbient[4];
    GLboolean lightModelLocalViewer;
    GLboolean lightModelTwoSide;
    NPGL_LIGHT lights[8];
    NPGL_MATERIAL material;
    GLboolean fog;
    GLenum fogMode;
    GLfloat fogColor[4];
    GLfloat fogDensity;
    GLfloat fogStart;
    GLfloat fogEnd;
    GLboolean scissorTest;
    GLint scissorBox[4];
    GLboolean scissorSet;
    GLenum perspectiveHint;
    GLenum pointSmoothHint;
    GLenum lineSmoothHint;
    GLenum polygonSmoothHint;
    GLenum fogHint;
    GLfloat currentTexCoord[4];
    GLboolean texGenEnabled[4];
    GLenum texGenMode[4];
    GLfloat texGenObjectPlane[4][4];
    GLfloat texGenEyePlane[4][4];
    GLfloat clearColor[4];
    GLfloat clearIndex;
    GLfloat clearAccum[4];
    GLclampd clearDepth;
    GLint clearStencil;
    GLboolean stencilTest;
    GLenum stencilFunc;
    GLint stencilRef;
    GLuint stencilValueMask;
    GLuint stencilWriteMask;
    GLenum stencilFail;
    GLenum stencilZFail;
    GLenum stencilPass;
    GLint stencilBits;
    GLboolean depthTest;
    GLboolean depthWrite;
    GLenum depthFunc;
    GLboolean blend;
    GLenum srcBlend;
    GLenum destBlend;
    GLboolean alphaTest;
    GLenum alphaFunc;
    GLclampf alphaRef;
    GLboolean cullFaceEnable;
    GLenum cullFace;
    GLenum frontFace;
    GLenum shadeModel;
    GLfloat pointSize;
    GLfloat lineWidth;
    GLboolean lineStipple;
    GLint lineStippleFactor;
    GLushort lineStipplePattern;
    GLboolean polygonStipple;
    GLubyte polygonStipplePattern[128];
    GLenum polygonModeFront;
    GLenum polygonModeBack;
    GLboolean texture1D;
    GLboolean texture2D;
    GLenum textureEnvMode;
    NPGL_TEXTURE_OBJECT defaultTexture1D;
    NPGL_TEXTURE_OBJECT defaultTexture2D;
    NPGL_TEXTURE_OBJECT *textures;
    NPGL_TEXTURE_OBJECT *boundTexture1D;
    NPGL_TEXTURE_OBJECT *boundTexture2D;
    DWORD nextHostTextureId;
    GLuint nextTextureName;
    NPGL_ARRAY_STATE vertexArray;
    NPGL_ARRAY_STATE normalArray;
    NPGL_ARRAY_STATE colorArray;
    NPGL_ARRAY_STATE indexArray;
    NPGL_ARRAY_STATE texCoordArray;
    NPGL_ARRAY_STATE edgeFlagArray;
    NPGL_CLIENT_ATTRIB_STATE clientAttribStack[16];
    int clientAttribTop;
    GLint packAlignment;
    GLint packRowLength;
    GLint packSkipRows;
    GLint packSkipPixels;
    GLboolean packSwapBytes;
    GLboolean packLsbFirst;
    GLint unpackAlignment;
    GLint unpackRowLength;
    GLint unpackSkipRows;
    GLint unpackSkipPixels;
    GLboolean unpackSwapBytes;
    GLboolean unpackLsbFirst;
    GLenum readBuffer;
    GLenum drawBuffer;
    GLboolean colorMask[4];
    GLuint indexMask;
    GLboolean colorLogicOp;
    GLboolean indexLogicOp;
    GLenum logicOpMode;
    GLboolean clipPlaneEnabled[6];
    GLdouble clipPlane[6][4];
    GLfloat pixelZoomX;
    GLfloat pixelZoomY;
    GLboolean mapColor;
    GLboolean mapStencil;
    GLint indexShift;
    GLint indexOffset;
    GLfloat redScale;
    GLfloat redBias;
    GLfloat greenScale;
    GLfloat greenBias;
    GLfloat blueScale;
    GLfloat blueBias;
    GLfloat alphaScale;
    GLfloat alphaBias;
    GLfloat depthScale;
    GLfloat depthBias;
    NPGL_PIXEL_MAP pixelMaps[10];
    NPGL_EVAL_MAP1 evalMap1[NPGL_EVAL_TARGET_COUNT];
    NPGL_EVAL_MAP2 evalMap2[NPGL_EVAL_TARGET_COUNT];
    GLboolean autoNormal;
    GLint map1GridSegments;
    GLfloat map1GridDomain[2];
    GLint map2GridSegments[2];
    GLfloat map2GridDomain[4];
    GLfloat rasterPosition[4];
    GLfloat rasterColor[4];
    GLfloat rasterTexCoord[4];
    GLfloat rasterDistance;
    GLboolean rasterValid;
    GLenum renderMode;
    GLuint *selectBuffer;
    GLsizei selectBufferSize;
    GLint selectIndex;
    GLint selectHits;
    GLboolean selectOverflow;
    GLboolean selectBufferSet;
    GLboolean selectHit;
    GLfloat selectMinDepth;
    GLfloat selectMaxDepth;
    GLuint nameStack[64];
    GLint nameStackDepth;
    GLfloat *feedbackBuffer;
    GLsizei feedbackBufferSize;
    GLenum feedbackType;
    GLint feedbackIndex;
    GLboolean feedbackOverflow;
    GLboolean feedbackBufferSet;
    GLenum matrixMode;
    GLfloat modelview[16];
    GLfloat projection[16];
    GLfloat texture[16];
    GLfloat modelviewStack[32][16];
    GLfloat projectionStack[8][16];
    GLfloat textureStack[8][16];
    int modelviewTop;
    int projectionTop;
    int textureTop;
    GLint viewport[4];
    GLboolean viewportSet;
    GLclampd depthNear;
    GLclampd depthFar;
    NPGL_ATTRIB_STATE attribStack[16];
    int attribTop;
    NPGL_DISPLAY_LIST *lists;
    NPGL_DISPLAY_LIST *compilingList;
    GLenum listMode;
    GLuint listBase;
    GLuint nextListName;
    GLboolean listCompileInBegin;
    GLboolean replayingList;
    DWORD listCallDepth;
} NPGL_CONTEXT;

static DWORD g_tlsIndex = TLS_OUT_OF_INDEXES;
static GLCLTPROCTABLE g_procTable;
static BOOL g_procTableInit = FALSE;

#define NPGL_PIXEL_FORMAT_COUNT 6
#define NPGL_PIXEL_FORMAT_NO_DEPTH_DOUBLE 5
#define NPGL_PIXEL_FORMAT_NO_DEPTH_SINGLE 6
#define NPGL_PIXEL_FORMAT_BINDINGS 32
typedef struct { HDC hdc; GLint format; } NPGL_PIXEL_FORMAT_BINDING;
static NPGL_PIXEL_FORMAT_BINDING g_pixelFormatBindings[NPGL_PIXEL_FORMAT_BINDINGS];

static void npgl_remember_pixel_format(HDC hdc, GLint format)
{
    int i;
    int empty = -1;
    for (i = 0; i < NPGL_PIXEL_FORMAT_BINDINGS; ++i) {
        if (g_pixelFormatBindings[i].hdc == hdc) { g_pixelFormatBindings[i].format = format; return; }
        if (!g_pixelFormatBindings[i].hdc && empty < 0) empty = i;
    }
    if (empty >= 0) { g_pixelFormatBindings[empty].hdc = hdc; g_pixelFormatBindings[empty].format = format; }
}

static GLint npgl_pixel_format_for_hdc(HDC hdc)
{
    int i;
    GLint format;
    for (i = 0; i < NPGL_PIXEL_FORMAT_BINDINGS; ++i) if (g_pixelFormatBindings[i].hdc == hdc) return g_pixelFormatBindings[i].format;
    format = GetPixelFormat(hdc);
    return (format >= 1 && format <= NPGL_PIXEL_FORMAT_COUNT) ? format : 1;
}

static DWORD npgl_host_call(DWORD command, void *packet)
{
    DWORD result;
    __asm {
        push ebx
        push esi
        push edi
        mov ebx, NPDISP_FUNCORDER_OGL32_DISPATCH
        mov esi, packet
        mov edi, command
        mov ecx, NPDISP_EXEC_MAGIC_LOW
        mov dx, NPDISP_EXEC_PORT
        mov al, NPDISP_EXEC_COMMAND
        out dx, al
        mov result, eax
        pop edi
        pop esi
        pop ebx
    }
    return result;
}

static NPGL_CONTEXT *npgl_current(void)
{
    if (g_tlsIndex == TLS_OUT_OF_INDEXES) return NULL;
    return (NPGL_CONTEXT *)TlsGetValue(g_tlsIndex);
}

static void npgl_set_error(NPGL_CONTEXT *ctx, GLenum error)
{
    if (ctx && ctx->error == 0) ctx->error = error;
}

static NPGL_DISPLAY_LIST *npgl_find_list(NPGL_CONTEXT *ctx, GLuint name)
{
    NPGL_DISPLAY_LIST *list;
    if (!ctx || !name) return NULL;
    for (list = ctx->lists; list; list = list->next) if (list->name == name) return list;
    return NULL;
}

static NPGL_DISPLAY_LIST *npgl_create_list(NPGL_CONTEXT *ctx, GLuint name)
{
    NPGL_DISPLAY_LIST *list;
    if (!ctx || !name) return NULL;
    list = npgl_find_list(ctx, name);
    if (list) return list;
    list = (NPGL_DISPLAY_LIST *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(*list));
    if (!list) return NULL;
    list->name = name; list->next = ctx->lists; ctx->lists = list;
    return list;
}

static void npgl_clear_list(NPGL_DISPLAY_LIST *list)
{
    DWORD i;
    if (!list) return;
    if (list->commands) {
        for (i = 0; i < list->commandCount; ++i) {
            if ((list->commands[i].op == NPGL_LIST_OP_BITMAP || list->commands[i].op == NPGL_LIST_OP_PIXEL_MAP) && list->commands[i].u[2])
                HeapFree(GetProcessHeap(), 0, (LPVOID)list->commands[i].u[2]);
            if ((list->commands[i].op == NPGL_LIST_OP_MAP1 || list->commands[i].op == NPGL_LIST_OP_MAP2) && list->commands[i].u[0])
                HeapFree(GetProcessHeap(), 0, (LPVOID)list->commands[i].u[0]);
        }
        HeapFree(GetProcessHeap(), 0, list->commands);
    }
    list->commands = NULL; list->commandCount = 0; list->commandCapacity = 0; list->defined = GL_FALSE;
    list->hostCached = GL_FALSE; list->finalColorSet = GL_FALSE; list->finalNormalSet = GL_FALSE; list->finalTexCoordSet = GL_FALSE; list->finalFrontFaceSet = GL_FALSE; list->finalTranslateSet = GL_FALSE;
}

static void npgl_host_delete_lists(NPGL_CONTEXT *ctx, GLuint list, DWORD range)
{
    NPDISP_OGL_LIST_DELETE32 packet;
    if (!ctx || !list || !range) return;
    packet.size = sizeof(packet);
    packet.context = ctx->bridgeContext;
    packet.list = list;
    packet.range = range;
    npgl_host_call(NPDISP_OGL_CMD_LIST_DELETE, &packet);
}

static void npgl_delete_list_name(NPGL_CONTEXT *ctx, GLuint name)
{
    NPGL_DISPLAY_LIST **link; NPGL_DISPLAY_LIST *list;
    if (!ctx || !name) return;
    link = &ctx->lists;
    while (*link) { list = *link; if (list->name == name) { *link = list->next; if (list->hostCached) npgl_host_delete_lists(ctx, name, 1); npgl_clear_list(list); HeapFree(GetProcessHeap(),0,list); return; } link = &list->next; }
}

static void npgl_free_lists(NPGL_CONTEXT *ctx)
{
    NPGL_DISPLAY_LIST *list,*next; if(!ctx)return; list=ctx->lists; while(list){next=list->next;npgl_clear_list(list);HeapFree(GetProcessHeap(),0,list);list=next;}ctx->lists=NULL;ctx->compilingList=NULL;
}

static BOOL npgl_record_list_command(NPGL_CONTEXT *ctx, const NPGL_LIST_COMMAND *command)
{
    NPGL_LIST_COMMAND *commands; DWORD capacity;
    if (!ctx || !ctx->compilingList || ctx->replayingList || !command) return TRUE;
    if (ctx->compilingList->commandCount >= ctx->compilingList->commandCapacity) {
        capacity = ctx->compilingList->commandCapacity ? ctx->compilingList->commandCapacity * 2UL : 64UL;
        commands = (NPGL_LIST_COMMAND *)HeapAlloc(GetProcessHeap(), 0, capacity * sizeof(*commands));
        if (!commands) { npgl_set_error(ctx, GL_OUT_OF_MEMORY); return FALSE; }
        if (ctx->compilingList->commands && ctx->compilingList->commandCount) memcpy(commands, ctx->compilingList->commands, ctx->compilingList->commandCount * sizeof(*commands));
        if (ctx->compilingList->commands) HeapFree(GetProcessHeap(), 0, ctx->compilingList->commands);
        ctx->compilingList->commands = commands; ctx->compilingList->commandCapacity = capacity;
    }
    ctx->compilingList->commands[ctx->compilingList->commandCount++] = *command;
    return TRUE;
}

static GLfloat npgl_clampf(GLfloat v, GLfloat lo, GLfloat hi)
{
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static void npgl_identity(GLfloat *m)
{
    int i;
    for (i = 0; i < 16; ++i) m[i] = 0.0f;
    m[0] = m[5] = m[10] = m[15] = 1.0f;
}

static void npgl_matrix_multiply(GLfloat *dst, const GLfloat *a, const GLfloat *b)
{
    GLfloat r[16];
    int row, col, k;
    for (col = 0; col < 4; ++col) {
        for (row = 0; row < 4; ++row) {
            GLfloat v = 0.0f;
            for (k = 0; k < 4; ++k) v += a[k * 4 + row] * b[col * 4 + k];
            r[col * 4 + row] = v;
        }
    }
    memcpy(dst, r, sizeof(r));
}

static BOOL npgl_matrix_inverse_double(const GLfloat *m, GLdouble *out)
{
    GLdouble a[4][8];
    int row, col, pivot, r;
    for (row = 0; row < 4; ++row) {
        for (col = 0; col < 4; ++col) a[row][col] = (GLdouble)m[col * 4 + row];
        for (col = 0; col < 4; ++col) a[row][col + 4] = (row == col) ? 1.0 : 0.0;
    }
    for (col = 0; col < 4; ++col) {
        GLdouble best = 0.0;
        pivot = col;
        for (r = col; r < 4; ++r) { GLdouble v = a[r][col] < 0.0 ? -a[r][col] : a[r][col]; if (v > best) { best = v; pivot = r; } }
        if (best < 1.0e-30) return FALSE;
        if (pivot != col) for (r = 0; r < 8; ++r) { GLdouble t = a[col][r]; a[col][r] = a[pivot][r]; a[pivot][r] = t; }
        { GLdouble d = a[col][col]; for (r = 0; r < 8; ++r) a[col][r] /= d; }
        for (row = 0; row < 4; ++row) if (row != col) { GLdouble f = a[row][col]; if (f != 0.0) for (r = 0; r < 8; ++r) a[row][r] -= f * a[col][r]; }
    }
    for (row = 0; row < 4; ++row) for (col = 0; col < 4; ++col) out[col * 4 + row] = a[row][col + 4];
    return TRUE;
}

static GLfloat *npgl_current_matrix(NPGL_CONTEXT *ctx)
{
    if (!ctx) return NULL;
    if (ctx->matrixMode == GL_MODELVIEW) return ctx->modelview;
    if (ctx->matrixMode == GL_PROJECTION) return ctx->projection;
    if (ctx->matrixMode == GL_TEXTURE) return ctx->texture;
    return NULL;
}

static void npgl_mult_current(NPGL_CONTEXT *ctx, const GLfloat *m)
{
    GLfloat *dst = npgl_current_matrix(ctx);
    if (!dst) return;
    npgl_matrix_multiply(dst, dst, m);
}

static DWORD npgl_pack_color(const GLfloat *c)
{
    DWORD a = (DWORD)(npgl_clampf(c[3], 0.0f, 1.0f) * 255.0f + 0.5f);
    DWORD r = (DWORD)(npgl_clampf(c[0], 0.0f, 1.0f) * 255.0f + 0.5f);
    DWORD g = (DWORD)(npgl_clampf(c[1], 0.0f, 1.0f) * 255.0f + 0.5f);
    DWORD b = (DWORD)(npgl_clampf(c[2], 0.0f, 1.0f) * 255.0f + 0.5f);
    return (a << 24) | (r << 16) | (g << 8) | b;
}

static DWORD npgl_depth_func(GLenum func)
{
    if (func < GL_NEVER || func > GL_ALWAYS) return 0;
    return (DWORD)(func - GL_NEVER + 1);
}

static DWORD npgl_blend_factor(GLenum factor)
{
    switch (factor) {
    case GL_ZERO: return NPDISP_OGL_BLEND_ZERO;
    case GL_ONE: return NPDISP_OGL_BLEND_ONE;
    case GL_SRC_COLOR: return NPDISP_OGL_BLEND_SRCCOLOR;
    case GL_ONE_MINUS_SRC_COLOR: return NPDISP_OGL_BLEND_INVSRCCOLOR;
    case GL_SRC_ALPHA: return NPDISP_OGL_BLEND_SRCALPHA;
    case GL_ONE_MINUS_SRC_ALPHA: return NPDISP_OGL_BLEND_INVSRCALPHA;
    case GL_DST_ALPHA: return NPDISP_OGL_BLEND_DESTALPHA;
    case GL_ONE_MINUS_DST_ALPHA: return NPDISP_OGL_BLEND_INVDESTALPHA;
    case GL_DST_COLOR: return NPDISP_OGL_BLEND_DESTCOLOR;
    case GL_ONE_MINUS_DST_COLOR: return NPDISP_OGL_BLEND_INVDESTCOLOR;
    case GL_SRC_ALPHA_SATURATE: return NPDISP_OGL_BLEND_SRCALPHASAT;
    default: return 0;
    }
}

static BOOL npgl_query(NPDISP_OGL_QUERY32 *query)
{
    DWORD result;
    memset(query, 0, sizeof(*query));
    query->size = sizeof(*query);
    result = npgl_host_call(NPDISP_OGL_CMD_QUERY, query);
    if (!result) return FALSE;
    if (query->version < NPDISP_OGL_BRIDGE_VERSION || !query->width || !query->height) return FALSE;
    return TRUE;
}

static BOOL npgl_update_drawable(NPGL_CONTEXT *ctx)
{
    NPDISP_OGL_QUERY32 query;
    HWND hwnd;
    RECT rc;
    POINT pt;
    LONG left, top, right, bottom;
    int width, height, bits, planes;
    if (!ctx) return FALSE;
    memset(&query, 0, sizeof(query));
    width = ctx->hdc ? GetDeviceCaps(ctx->hdc, HORZRES) : 0;
    height = ctx->hdc ? GetDeviceCaps(ctx->hdc, VERTRES) : 0;
    bits = ctx->hdc ? GetDeviceCaps(ctx->hdc, BITSPIXEL) : 0;
    planes = ctx->hdc ? GetDeviceCaps(ctx->hdc, PLANES) : 0;
    if (width > 0 && height > 0) {
        query.size = sizeof(query);
        query.version = NPDISP_OGL_BRIDGE_VERSION;
        query.width = (DWORD)width;
        query.height = (DWORD)height;
        query.bpp = (DWORD)(bits > 0 ? bits : 1) * (DWORD)(planes > 0 ? planes : 1);
    }
    else if (!npgl_query(&query)) return FALSE;
    ctx->screenWidth = query.width;
    ctx->screenHeight = query.height;
    left = top = right = bottom = 0;
    hwnd = WindowFromDC(ctx->hdc);
    if (hwnd) {
        ctx->drawableWindow = hwnd;
        if (!GetClientRect(hwnd, &rc) || rc.right <= rc.left || rc.bottom <= rc.top) {
            ctx->drawableValid = GL_FALSE;
            return FALSE;
        }
        pt.x = 0;
        pt.y = 0;
        if (!ClientToScreen(hwnd, &pt)) {
            ctx->drawableValid = GL_FALSE;
            return FALSE;
        }
        left = pt.x;
        top = pt.y;
        right = left + (rc.right - rc.left);
        bottom = top + (rc.bottom - rc.top);
    }
    else {
        int clip;
        if (ctx->drawableWindow) {
            ctx->drawableValid = GL_FALSE;
            return FALSE;
        }
        clip = GetClipBox(ctx->hdc, &rc);
        pt.x = pt.y = 0;
        if (clip == ERROR || clip == NULLREGION || rc.right <= rc.left || rc.bottom <= rc.top || !GetDCOrgEx(ctx->hdc, &pt)) {
            ctx->drawableValid = GL_FALSE;
            return FALSE;
        }
        left = pt.x + rc.left;
        top = pt.y + rc.top;
        right = pt.x + rc.right;
        bottom = pt.y + rc.bottom;
    }
    if (right <= left || bottom <= top) {
        ctx->drawableValid = GL_FALSE;
        return FALSE;
    }
    ctx->drawX = left;
    ctx->drawY = top;
    ctx->drawWidth = (DWORD)(right - left);
    ctx->drawHeight = (DWORD)(bottom - top);
    if (!ctx->viewportSet) {
        ctx->viewport[0] = 0;
        ctx->viewport[1] = 0;
        ctx->viewport[2] = (GLint)ctx->drawWidth;
        ctx->viewport[3] = (GLint)ctx->drawHeight;
    }
    if (!ctx->scissorSet) {
        ctx->scissorBox[0] = 0;
        ctx->scissorBox[1] = 0;
        ctx->scissorBox[2] = (GLint)ctx->drawWidth;
        ctx->scissorBox[3] = (GLint)ctx->drawHeight;
        ctx->scissorSet = GL_TRUE;
    }
    ctx->drawableValid = GL_TRUE;
    ctx->drawableDirty = GL_FALSE;
    return TRUE;
}

static BOOL npgl_ensure_drawable(NPGL_CONTEXT *ctx)
{
    if (!ctx) return FALSE;
    if (ctx->drawableValid && !ctx->drawableDirty) return TRUE;
    return npgl_update_drawable(ctx);
}

static BOOL npgl_reserve_vertices(NPGL_CONTEXT *ctx, DWORD needed)
{
    DWORD capacity;
    SIZE_T bytes;
    NPDISP_OGL_VERTEX32 *p;
    if (needed <= ctx->vertexCapacity) return TRUE;
    capacity = ctx->vertexCapacity ? ctx->vertexCapacity : 64;
    while (capacity < needed) {
        if (capacity > 32768) { capacity = needed; break; }
        capacity *= 2;
    }
    if (capacity > 65536) return FALSE;
    bytes = (SIZE_T)capacity * sizeof(NPDISP_OGL_VERTEX32);
    if (ctx->vertices) p = (NPDISP_OGL_VERTEX32 *)HeapReAlloc(GetProcessHeap(), 0, ctx->vertices, bytes);
    else p = (NPDISP_OGL_VERTEX32 *)HeapAlloc(GetProcessHeap(), 0, bytes);
    if (!p) return FALSE;
    ctx->vertices = p;
    ctx->vertexCapacity = capacity;
    return TRUE;
}

static void npgl_copy4(GLfloat *dst, const GLfloat *src)
{
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; dst[3] = src[3];
}

static GLfloat npgl_normalize3(GLfloat *v)
{
    GLfloat len = (GLfloat)sqrt((double)v[0] * v[0] + (double)v[1] * v[1] + (double)v[2] * v[2]);
    if (len > 0.0f) {
        v[0] /= len; v[1] /= len; v[2] /= len;
    }
    return len;
}

static void npgl_transform_eye_vector(const GLfloat *m, const GLfloat *v, GLfloat *out)
{
    out[0] = m[0] * v[0] + m[4] * v[1] + m[8] * v[2];
    out[1] = m[1] * v[0] + m[5] * v[1] + m[9] * v[2];
    out[2] = m[2] * v[0] + m[6] * v[1] + m[10] * v[2];
}

static void npgl_transform_eye_position(const GLfloat *m, const GLfloat *v, GLfloat *out)
{
    int row;
    int k;
    for (row = 0; row < 4; ++row) {
        out[row] = 0.0f;
        for (k = 0; k < 4; ++k) out[row] += m[k * 4 + row] * v[k];
    }
}

static void npgl_current_material_values(NPGL_CONTEXT *ctx, GLfloat *ambient, GLfloat *diffuse)
{
    npgl_copy4(ambient, ctx->material.ambient);
    npgl_copy4(diffuse, ctx->material.diffuse);
    if (!ctx->colorMaterial) return;
    switch (ctx->colorMaterialMode) {
    case GL_AMBIENT:
        npgl_copy4(ambient, ctx->currentColor);
        break;
    case GL_DIFFUSE:
        npgl_copy4(diffuse, ctx->currentColor);
        break;
    case GL_AMBIENT_AND_DIFFUSE:
        npgl_copy4(ambient, ctx->currentColor);
        npgl_copy4(diffuse, ctx->currentColor);
        break;
    default:
        break;
    }
}

static void npgl_compute_vertex_color(NPGL_CONTEXT *ctx, const GLfloat *eye, GLfloat *color)
{
    GLfloat ambientMat[4], diffuseMat[4];
    GLfloat normal[3];
    GLfloat view[3];
    int i, j;

    if (!ctx->lighting) {
        npgl_copy4(color, ctx->currentColor);
    }
    else {
        GLfloat specularMat[4], emissionMat[4];
        npgl_current_material_values(ctx, ambientMat, diffuseMat);
        npgl_copy4(specularMat, ctx->material.specular);
        npgl_copy4(emissionMat, ctx->material.emission);
        if (ctx->colorMaterial) {
            if (ctx->colorMaterialMode == GL_SPECULAR) npgl_copy4(specularMat, ctx->currentColor);
            else if (ctx->colorMaterialMode == GL_EMISSION) npgl_copy4(emissionMat, ctx->currentColor);
        }
        npgl_transform_eye_vector(ctx->modelview, ctx->currentNormal, normal);
        if (ctx->normalize) npgl_normalize3(normal);

        for (j = 0; j < 3; ++j)
            color[j] = emissionMat[j] + ctx->lightModelAmbient[j] * ambientMat[j];
        color[3] = diffuseMat[3];

        if (ctx->lightModelLocalViewer) {
            view[0] = -eye[0]; view[1] = -eye[1]; view[2] = -eye[2];
            if (npgl_normalize3(view) == 0.0f) { view[0] = 0.0f; view[1] = 0.0f; view[2] = 1.0f; }
        }
        else {
            view[0] = 0.0f; view[1] = 0.0f; view[2] = 1.0f;
        }

        for (i = 0; i < 8; ++i) {
            NPGL_LIGHT *l = &ctx->lights[i];
            GLfloat lv[3], halfv[3], dist = 1.0f, att = 1.0f, ndotl, ndoth, spot = 1.0f;
            if (!l->enabled) continue;

            for (j = 0; j < 3; ++j) color[j] += l->ambient[j] * ambientMat[j];

            if (l->position[3] == 0.0f) {
                lv[0] = l->position[0]; lv[1] = l->position[1]; lv[2] = l->position[2];
                npgl_normalize3(lv);
            }
            else {
                GLfloat invw = 1.0f / l->position[3];
                lv[0] = l->position[0] * invw - eye[0];
                lv[1] = l->position[1] * invw - eye[1];
                lv[2] = l->position[2] * invw - eye[2];
                dist = npgl_normalize3(lv);
                if (dist <= 0.0f) dist = 1.0f;
                att = 1.0f / (l->constantAttenuation + l->linearAttenuation * dist + l->quadraticAttenuation * dist * dist);
                if (l->spotCutoff != 180.0f) {
                    GLfloat spotDot = -(lv[0] * l->spotDirection[0] + lv[1] * l->spotDirection[1] + lv[2] * l->spotDirection[2]);
                    GLfloat cutoffCos = (GLfloat)cos((double)l->spotCutoff * 3.14159265358979323846 / 180.0);
                    if (spotDot < cutoffCos) spot = 0.0f;
                    else if (l->spotExponent != 0.0f) spot = (GLfloat)pow((double)spotDot, (double)l->spotExponent);
                }
            }

            ndotl = normal[0] * lv[0] + normal[1] * lv[1] + normal[2] * lv[2];
            if (ndotl < 0.0f) ndotl = 0.0f;
            if (ndotl > 1.0f) ndotl = 1.0f;
            for (j = 0; j < 3; ++j)
                color[j] += att * spot * l->diffuse[j] * diffuseMat[j] * ndotl;

            if (ndotl > 0.0f && ctx->material.shininess > 0.0f) {
                halfv[0] = lv[0] + view[0]; halfv[1] = lv[1] + view[1]; halfv[2] = lv[2] + view[2];
                npgl_normalize3(halfv);
                ndoth = normal[0] * halfv[0] + normal[1] * halfv[1] + normal[2] * halfv[2];
                if (ndoth < 0.0f) ndoth = 0.0f;
                if (ndoth > 1.0f) ndoth = 1.0f;
                ndoth = (GLfloat)pow((double)ndoth, (double)ctx->material.shininess);
                for (j = 0; j < 3; ++j)
                    color[j] += att * spot * l->specular[j] * specularMat[j] * ndoth;
            }
        }
        color[0] = npgl_clampf(color[0], 0.0f, 1.0f);
        color[1] = npgl_clampf(color[1], 0.0f, 1.0f);
        color[2] = npgl_clampf(color[2], 0.0f, 1.0f);
        color[3] = npgl_clampf(color[3], 0.0f, 1.0f);
    }

    if (ctx->fog) {
        GLfloat z = eye[2] < 0.0f ? -eye[2] : eye[2];
        GLfloat f;
        if (ctx->fogMode == GL_LINEAR) {
            GLfloat d = ctx->fogEnd - ctx->fogStart;
            f = (d == 0.0f) ? 0.0f : (ctx->fogEnd - z) / d;
        }
        else if (ctx->fogMode == GL_EXP) {
            f = (GLfloat)exp(-(double)ctx->fogDensity * z);
        }
        else {
            GLfloat d = ctx->fogDensity * z;
            f = (GLfloat)exp(-(double)d * d);
        }
        f = npgl_clampf(f, 0.0f, 1.0f);
        color[0] = f * color[0] + (1.0f - f) * ctx->fogColor[0];
        color[1] = f * color[1] + (1.0f - f) * ctx->fogColor[1];
        color[2] = f * color[2] + (1.0f - f) * ctx->fogColor[2];
    }
}

static void npgl_init_lighting(NPGL_CONTEXT *ctx)
{
    int i;
    ctx->lighting = GL_FALSE;
    ctx->normalize = GL_FALSE;
    ctx->colorMaterial = GL_FALSE;
    ctx->colorMaterialFace = GL_FRONT_AND_BACK;
    ctx->colorMaterialMode = GL_AMBIENT_AND_DIFFUSE;
    ctx->lightModelAmbient[0] = 0.2f; ctx->lightModelAmbient[1] = 0.2f; ctx->lightModelAmbient[2] = 0.2f; ctx->lightModelAmbient[3] = 1.0f;
    ctx->material.ambient[0] = 0.2f; ctx->material.ambient[1] = 0.2f; ctx->material.ambient[2] = 0.2f; ctx->material.ambient[3] = 1.0f;
    ctx->material.diffuse[0] = 0.8f; ctx->material.diffuse[1] = 0.8f; ctx->material.diffuse[2] = 0.8f; ctx->material.diffuse[3] = 1.0f;
    ctx->material.specular[3] = 1.0f;
    ctx->material.emission[3] = 1.0f;
    for (i = 0; i < 8; ++i) {
        NPGL_LIGHT *l = &ctx->lights[i];
        l->ambient[3] = l->diffuse[3] = l->specular[3] = 1.0f;
        l->position[2] = 1.0f;
        l->spotDirection[2] = -1.0f;
        l->spotCutoff = 180.0f;
        l->constantAttenuation = 1.0f;
    }
    ctx->lights[0].diffuse[0] = ctx->lights[0].diffuse[1] = ctx->lights[0].diffuse[2] = 1.0f;
    ctx->lights[0].specular[0] = ctx->lights[0].specular[1] = ctx->lights[0].specular[2] = 1.0f;
    ctx->fog = GL_FALSE;
    ctx->fogMode = GL_EXP;
    ctx->fogColor[3] = 0.0f;
    ctx->fogDensity = 1.0f;
    ctx->fogStart = 0.0f;
    ctx->fogEnd = 1.0f;
}

static void npgl_transform_vertex(NPGL_CONTEXT *ctx, GLfloat x, GLfloat y, GLfloat z, GLfloat w, NPDISP_OGL_VERTEX32 *out)
{
    GLfloat obj[4], eye[4], clip[4];
    GLfloat ndcX, ndcY, ndcZ, invW;
    int row, k;
    obj[0] = x; obj[1] = y; obj[2] = z; obj[3] = w;
    for (row = 0; row < 4; ++row) {
        eye[row] = 0.0f;
        for (k = 0; k < 4; ++k) eye[row] += ctx->modelview[k * 4 + row] * obj[k];
    }
    for (row = 0; row < 4; ++row) {
        clip[row] = 0.0f;
        for (k = 0; k < 4; ++k) clip[row] += ctx->projection[k * 4 + row] * eye[k];
    }
    if (clip[3] == 0.0f) invW = 1.0f;
    else invW = 1.0f / clip[3];
    ndcX = clip[0] * invW;
    ndcY = clip[1] * invW;
    ndcZ = clip[2] * invW;
    out->x = (GLfloat)ctx->viewport[0] + (ndcX + 1.0f) * (GLfloat)ctx->viewport[2] * 0.5f;
    out->y = (GLfloat)ctx->drawHeight - ((GLfloat)ctx->viewport[1] + (ndcY + 1.0f) * (GLfloat)ctx->viewport[3] * 0.5f);
    out->z = (GLfloat)(ctx->depthNear + (ndcZ + 1.0) * (ctx->depthFar - ctx->depthNear) * 0.5);
    out->rhw = invW;
    for (k = 0; k < 4; ++k) out->clip[k] = clip[k];
    for (k = 0; k < 6; ++k) {
        if (ctx->clipPlaneEnabled[k]) out->clipDistance[k] = (GLfloat)(ctx->clipPlane[k][0] * eye[0] + ctx->clipPlane[k][1] * eye[1] + ctx->clipPlane[k][2] * eye[2] + ctx->clipPlane[k][3] * eye[3]);
        else out->clipDistance[k] = 1.0f;
    }
    {
        GLfloat vertexColor[4];
        npgl_compute_vertex_color(ctx, eye, vertexColor);
        out->diffuse = npgl_pack_color(vertexColor);
    }
    {
        GLfloat srcTex[4], tex[4], q;
        GLfloat n[3], flen, dotnr, refl[3], m;
        for (k=0;k<4;++k) srcTex[k]=ctx->currentTexCoord[k];
        for (k=0;k<4;++k) if(ctx->texGenEnabled[k]) {
            GLenum mode=ctx->texGenMode[k];
            if(mode==GL_OBJECT_LINEAR) srcTex[k]=obj[0]*ctx->texGenObjectPlane[k][0]+obj[1]*ctx->texGenObjectPlane[k][1]+obj[2]*ctx->texGenObjectPlane[k][2]+obj[3]*ctx->texGenObjectPlane[k][3];
            else if(mode==GL_EYE_LINEAR) srcTex[k]=eye[0]*ctx->texGenEyePlane[k][0]+eye[1]*ctx->texGenEyePlane[k][1]+eye[2]*ctx->texGenEyePlane[k][2]+eye[3]*ctx->texGenEyePlane[k][3];
            else if(mode==GL_SPHERE_MAP && k<2) {
                n[0]=ctx->modelview[0]*ctx->currentNormal[0]+ctx->modelview[4]*ctx->currentNormal[1]+ctx->modelview[8]*ctx->currentNormal[2];
                n[1]=ctx->modelview[1]*ctx->currentNormal[0]+ctx->modelview[5]*ctx->currentNormal[1]+ctx->modelview[9]*ctx->currentNormal[2];
                n[2]=ctx->modelview[2]*ctx->currentNormal[0]+ctx->modelview[6]*ctx->currentNormal[1]+ctx->modelview[10]*ctx->currentNormal[2];
                flen=(GLfloat)sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);if(flen!=0.0f){n[0]/=flen;n[1]/=flen;n[2]/=flen;}
                refl[0]=eye[0];refl[1]=eye[1];refl[2]=eye[2];flen=(GLfloat)sqrt(refl[0]*refl[0]+refl[1]*refl[1]+refl[2]*refl[2]);if(flen!=0.0f){refl[0]/=flen;refl[1]/=flen;refl[2]/=flen;}
                dotnr=n[0]*refl[0]+n[1]*refl[1]+n[2]*refl[2];refl[0]-=2.0f*n[0]*dotnr;refl[1]-=2.0f*n[1]*dotnr;refl[2]-=2.0f*n[2]*dotnr;
                m=2.0f*(GLfloat)sqrt(refl[0]*refl[0]+refl[1]*refl[1]+(refl[2]+1.0f)*(refl[2]+1.0f));
                srcTex[k]=(m!=0.0f?((k==0?refl[0]:refl[1])/m):0.0f)+0.5f;
            }
        }
        for (row = 0; row < 4; ++row) { tex[row]=0.0f; for (k = 0; k < 4; ++k) tex[row] += ctx->texture[k * 4 + row] * srcTex[k]; }
        for (k = 0; k < 4; ++k) out->texcoord[k] = tex[k];
        q = tex[3]; if (q == 0.0f) q = 1.0f; out->tu = tex[0] / q; out->tv = tex[1] / q;
    }
}

static void npgl_emit_vertex(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    NPGL_CONTEXT *ctx = npgl_current();
    if (!ctx) return;
    if (!ctx->inBegin) { npgl_set_error(ctx, GL_INVALID_OPERATION); return; }
    if (!npgl_reserve_vertices(ctx, ctx->vertexCount + 1)) { npgl_set_error(ctx, GL_OUT_OF_MEMORY); return; }
    npgl_transform_vertex(ctx, x, y, z, w, &ctx->vertices[ctx->vertexCount]);
    ctx->vertexCount++;
}

static DWORD npgl_cull_mode(NPGL_CONTEXT *ctx)
{
    if (!ctx->cullFaceEnable) return NPDISP_OGL_CULL_NONE;
    if (ctx->cullFace == GL_FRONT_AND_BACK) return 0;
    if (ctx->cullFace == GL_BACK) return (ctx->frontFace == GL_CCW) ? NPDISP_OGL_CULL_CW : NPDISP_OGL_CULL_CCW;
    return (ctx->frontFace == GL_CCW) ? NPDISP_OGL_CULL_CCW : NPDISP_OGL_CULL_CW;
}

static void npgl_init_texture_object(NPGL_TEXTURE_OBJECT *obj, GLuint name, DWORD hostId)
{
    memset(obj, 0, sizeof(*obj));
    obj->name = name;
    obj->target = 0;
    obj->revision = 1;
    obj->hostId = hostId;
    obj->hostRevision = 0;
    obj->wrapS = GL_REPEAT;
    obj->wrapT = GL_REPEAT;
    obj->minFilter = GL_NEAREST_MIPMAP_LINEAR;
    obj->magFilter = GL_LINEAR;
}

static NPGL_TEXTURE_OBJECT *npgl_find_texture(NPGL_CONTEXT *ctx, GLuint name)
{
    NPGL_TEXTURE_OBJECT *obj;
    if (!ctx) return NULL;
    if (name == 0) return NULL;
    for (obj = ctx->textures; obj; obj = obj->next) if (obj->name == name) return obj;
    return NULL;
}

static NPGL_TEXTURE_OBJECT *npgl_bound_texture(NPGL_CONTEXT *ctx, GLenum target)
{
    if (!ctx) return NULL;
    if (target == GL_TEXTURE_1D) return ctx->boundTexture1D;
    if (target == GL_TEXTURE_2D) return ctx->boundTexture2D;
    return NULL;
}

static NPGL_TEXTURE_OBJECT *npgl_active_texture(NPGL_CONTEXT *ctx)
{
    if (!ctx) return NULL;
    if (ctx->texture2D && ctx->boundTexture2D && ctx->boundTexture2D->defined) return ctx->boundTexture2D;
    if (ctx->texture1D && ctx->boundTexture1D && ctx->boundTexture1D->defined) return ctx->boundTexture1D;
    return NULL;
}

static NPGL_TEXTURE_OBJECT *npgl_create_texture(NPGL_CONTEXT *ctx, GLuint name, GLboolean boundOnce)
{
    NPGL_TEXTURE_OBJECT *obj;
    if (!ctx || name == 0) return NULL;
    obj = (NPGL_TEXTURE_OBJECT *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(*obj));
    if (!obj) return NULL;
    {
        DWORD hostId = ctx->nextHostTextureId++;
        if (!hostId) hostId = ctx->nextHostTextureId++;
        npgl_init_texture_object(obj, name, hostId);
    }
    obj->boundOnce = boundOnce;
    obj->next = ctx->textures;
    ctx->textures = obj;
    return obj;
}

static void npgl_free_texture_object(NPGL_TEXTURE_OBJECT *obj)
{
    if (!obj) return;
    if (obj->pixels) HeapFree(GetProcessHeap(), 0, obj->pixels);
    obj->pixels = NULL;
    obj->pixelBytes = 0;
}

static void npgl_free_textures(NPGL_CONTEXT *ctx)
{
    NPGL_TEXTURE_OBJECT *obj;
    NPGL_TEXTURE_OBJECT *next;
    if (!ctx) return;
    npgl_free_texture_object(&ctx->defaultTexture1D);
    npgl_free_texture_object(&ctx->defaultTexture2D);
    obj = ctx->textures;
    while (obj) {
        next = obj->next;
        npgl_free_texture_object(obj);
        HeapFree(GetProcessHeap(), 0, obj);
        obj = next;
    }
    ctx->textures = NULL;
}

static BOOL npgl_upload_texture(NPGL_CONTEXT *ctx, NPGL_TEXTURE_OBJECT *obj)
{
    NPDISP_OGL_TEXTURE32 packet;
    if (!ctx || !obj || !obj->defined || !obj->pixels || !obj->width || !obj->height) return TRUE;
    if (obj->hostRevision == obj->revision) return TRUE;
    memset(&packet, 0, sizeof(packet));
    packet.size = sizeof(packet);
    packet.context = ctx->bridgeContext;
    packet.textureId = obj->hostId;
    packet.revision = obj->revision;
    packet.width = (DWORD)obj->width;
    packet.height = (DWORD)obj->height;
    packet.pixels = (DWORD)obj->pixels;
    packet.hasAlpha = obj->hasAlpha ? 1UL : 0UL;
    if (!npgl_host_call(NPDISP_OGL_CMD_TEXTURE_UPLOAD, &packet)) return FALSE;
    obj->hostRevision = obj->revision;
    return TRUE;
}

static void npgl_delete_host_texture(NPGL_CONTEXT *ctx, NPGL_TEXTURE_OBJECT *obj)
{
    NPDISP_OGL_TEXTURE_DELETE32 packet;
    if (!ctx || !obj || !obj->hostRevision || !obj->hostId) return;
    memset(&packet, 0, sizeof(packet));
    packet.size = sizeof(packet);
    packet.context = ctx->bridgeContext;
    packet.textureId = obj->hostId;
    npgl_host_call(NPDISP_OGL_CMD_TEXTURE_DELETE, &packet);
    obj->hostRevision = 0;
}

static DWORD npgl_texture_filter(GLenum value)
{
    switch (value) {
    case GL_NEAREST:
    case GL_NEAREST_MIPMAP_NEAREST:
    case GL_NEAREST_MIPMAP_LINEAR:
        return NPDISP_OGL_TEXFILTER_POINT;
    case GL_LINEAR:
    case GL_LINEAR_MIPMAP_NEAREST:
    case GL_LINEAR_MIPMAP_LINEAR:
        return NPDISP_OGL_TEXFILTER_LINEAR;
    default:
        return 0;
    }
}

static DWORD npgl_stencil_op(GLenum op)
{
    switch (op) {
    case GL_KEEP: return NPDISP_OGL_STENCIL_KEEP;
    case GL_ZERO: return NPDISP_OGL_STENCIL_ZERO;
    case GL_REPLACE: return NPDISP_OGL_STENCIL_REPLACE;
    case GL_INCR: return NPDISP_OGL_STENCIL_INCR;
    case GL_DECR: return NPDISP_OGL_STENCIL_DECR;
    case GL_INVERT: return NPDISP_OGL_STENCIL_INVERT;
    default: return NPDISP_OGL_STENCIL_KEEP;
    }
}

static DWORD npgl_fill_draw_state(NPGL_CONTEXT *ctx, NPDISP_OGL_DRAW32 *draw)
{
    DWORD cull;
    if (!ctx || !draw) return 0;
    cull = npgl_cull_mode(ctx);
    memset(draw, 0, sizeof(*draw));
    draw->size = sizeof(*draw);
    draw->context = ctx->bridgeContext;
    draw->x = ctx->drawX;
    draw->y = ctx->drawY;
    draw->width = ctx->drawWidth;
    draw->height = ctx->drawHeight;
    draw->shadeMode = (ctx->shadeModel == GL_FLAT) ? 1 : 0;
    draw->depthEnable = (ctx->depthTest && ctx->pixelFormat != NPGL_PIXEL_FORMAT_NO_DEPTH_DOUBLE && ctx->pixelFormat != NPGL_PIXEL_FORMAT_NO_DEPTH_SINGLE) ? 1 : 0;
    draw->depthWrite = ctx->depthWrite ? 1 : 0;
    draw->depthFunc = npgl_depth_func(ctx->depthFunc);
    draw->blendEnable = ctx->blend ? 1 : 0;
    draw->srcBlend = npgl_blend_factor(ctx->srcBlend);
    draw->destBlend = npgl_blend_factor(ctx->destBlend);
    draw->alphaTestEnable = ctx->alphaTest ? 1 : 0;
    draw->alphaFunc = npgl_depth_func(ctx->alphaFunc);
    draw->alphaRef = (DWORD)(npgl_clampf(ctx->alphaRef, 0.0f, 1.0f) * 255.0f + 0.5f);
    {
        NPGL_TEXTURE_OBJECT *tex = npgl_active_texture(ctx);
        draw->cullMode = cull;
        draw->textureEnable = tex ? 1UL : 0UL;
        draw->textureId = tex ? tex->hostId : 0UL;
        if (ctx->textureEnvMode == GL_REPLACE) draw->textureEnvMode = NPDISP_OGL_TEXENV_REPLACE;
        else if (ctx->textureEnvMode == GL_DECAL) draw->textureEnvMode = NPDISP_OGL_TEXENV_DECAL;
        else draw->textureEnvMode = NPDISP_OGL_TEXENV_MODULATE;
        draw->textureWrapS = (tex && tex->wrapS == GL_CLAMP) ? NPDISP_OGL_TEXADDR_CLAMP : NPDISP_OGL_TEXADDR_WRAP;
        draw->textureWrapT = (tex && tex->wrapT == GL_CLAMP) ? NPDISP_OGL_TEXADDR_CLAMP : NPDISP_OGL_TEXADDR_WRAP;
        draw->textureMinFilter = npgl_texture_filter(tex ? tex->minFilter : GL_NEAREST);
        draw->textureMagFilter = npgl_texture_filter(tex ? tex->magFilter : GL_LINEAR);
    }
    draw->scissorEnable = ctx->scissorTest ? 1UL : 0UL;
    draw->scissorX = ctx->scissorBox[0];
    draw->scissorY = ctx->scissorBox[1];
    draw->scissorWidth = (ctx->scissorBox[2] > 0) ? (DWORD)ctx->scissorBox[2] : 0UL;
    draw->scissorHeight = (ctx->scissorBox[3] > 0) ? (DWORD)ctx->scissorBox[3] : 0UL;
    draw->stencilEnable = (ctx->stencilTest && ctx->stencilBits) ? 1UL : 0UL;
    draw->stencilBits = (DWORD)ctx->stencilBits;
    draw->stencilFunc = npgl_depth_func(ctx->stencilFunc);
    draw->stencilRef = (DWORD)ctx->stencilRef;
    draw->stencilReadMask = ctx->stencilValueMask;
    draw->stencilWriteMask = ctx->stencilWriteMask;
    draw->stencilFail = npgl_stencil_op(ctx->stencilFail);
    draw->stencilZFail = npgl_stencil_op(ctx->stencilZFail);
    draw->stencilPass = npgl_stencil_op(ctx->stencilPass);
    draw->pointSize = ctx->pointSize;
    draw->lineWidth = ctx->lineWidth;
    draw->lineStippleEnable = ctx->lineStipple ? 1UL : 0UL;
    draw->lineStippleFactor = (DWORD)ctx->lineStippleFactor;
    draw->lineStipplePattern = (DWORD)ctx->lineStipplePattern;
    draw->polygonStippleEnable = ctx->polygonStipple ? 1UL : 0UL;
    memcpy(draw->polygonStipple, ctx->polygonStipplePattern, sizeof(draw->polygonStipple));
    draw->polygonModeFront = (DWORD)ctx->polygonModeFront;
    draw->polygonModeBack = (DWORD)ctx->polygonModeBack;
    draw->frontFace = (DWORD)ctx->frontFace;
    draw->colorWriteDisableMask = (!ctx->colorMask[0] ? 1UL : 0UL) | (!ctx->colorMask[1] ? 2UL : 0UL) | (!ctx->colorMask[2] ? 4UL : 0UL) | (!ctx->colorMask[3] ? 8UL : 0UL);
    if (ctx->drawBuffer == GL_NONE) draw->colorWriteDisableMask |= 7UL;
    draw->logicOpEnable = ctx->colorLogicOp ? 1UL : 0UL;
    draw->logicOp = (DWORD)ctx->logicOpMode;
    draw->clipPlaneMask = 0;
    { int i; for (i = 0; i < 6; ++i) if (ctx->clipPlaneEnabled[i]) draw->clipPlaneMask |= 1UL << i; }
    draw->viewportX = ctx->viewport[0]; draw->viewportY = ctx->viewport[1];
    draw->viewportWidth = ctx->viewport[2] > 0 ? (DWORD)ctx->viewport[2] : 0UL; draw->viewportHeight = ctx->viewport[3] > 0 ? (DWORD)ctx->viewport[3] : 0UL;
    draw->depthNear = (float)ctx->depthNear; draw->depthFar = (float)ctx->depthFar;
    return cull;
}


static GLfloat npgl_special_clip_distance(const NPDISP_OGL_VERTEX32 *v, int plane)
{
    switch (plane) {
    case 0: return v->clip[0] + v->clip[3];
    case 1: return v->clip[3] - v->clip[0];
    case 2: return v->clip[1] + v->clip[3];
    case 3: return v->clip[3] - v->clip[1];
    case 4: return v->clip[2] + v->clip[3];
    case 5: return v->clip[3] - v->clip[2];
    default: return v->clipDistance[plane - 6];
    }
}

static void npgl_special_reproject_vertex(NPGL_CONTEXT *c, NPDISP_OGL_VERTEX32 *v)
{
    GLfloat invW, ndcX, ndcY, ndcZ, q;
    if (!c || !v) return;
    invW = v->clip[3] != 0.0f ? 1.0f / v->clip[3] : 1.0f;
    ndcX = v->clip[0] * invW;
    ndcY = v->clip[1] * invW;
    ndcZ = v->clip[2] * invW;
    v->x = (GLfloat)c->viewport[0] + (ndcX + 1.0f) * (GLfloat)c->viewport[2] * 0.5f;
    v->y = (GLfloat)c->drawHeight - ((GLfloat)c->viewport[1] + (ndcY + 1.0f) * (GLfloat)c->viewport[3] * 0.5f);
    v->z = (GLfloat)(c->depthNear + (ndcZ + 1.0) * (c->depthFar - c->depthNear) * 0.5);
    v->rhw = invW;
    q = v->texcoord[3];
    if (q == 0.0f) q = 1.0f;
    v->tu = v->texcoord[0] / q;
    v->tv = v->texcoord[1] / q;
}

static void npgl_special_lerp_vertex(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *a, const NPDISP_OGL_VERTEX32 *b, GLfloat t, NPDISP_OGL_VERTEX32 *out)
{
    int i;
    DWORD ca, cb, value = 0;
    if (!a || !b || !out) return;
    memset(out, 0, sizeof(*out));
    for (i = 0; i < 4; ++i) {
        out->clip[i] = a->clip[i] + (b->clip[i] - a->clip[i]) * t;
        out->texcoord[i] = a->texcoord[i] + (b->texcoord[i] - a->texcoord[i]) * t;
    }
    for (i = 0; i < 6; ++i) out->clipDistance[i] = a->clipDistance[i] + (b->clipDistance[i] - a->clipDistance[i]) * t;
    ca = a->diffuse;
    cb = b->diffuse;
    for (i = 0; i < 4; ++i) {
        int shift = i * 8;
        GLfloat av = (GLfloat)((ca >> shift) & 0xffUL);
        GLfloat bv = (GLfloat)((cb >> shift) & 0xffUL);
        DWORD cv = (DWORD)(av + (bv - av) * t + 0.5f);
        if (cv > 255UL) cv = 255UL;
        value |= cv << shift;
    }
    out->diffuse = value;
    npgl_special_reproject_vertex(c, out);
}

static GLboolean npgl_special_vertex_inside(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *v)
{
    int plane;
    if (!c || !v) return GL_FALSE;
    for (plane = 0; plane < 12; ++plane) {
        if (plane >= 6 && !c->clipPlaneEnabled[plane - 6]) continue;
        if (npgl_special_clip_distance(v, plane) < 0.0f) return GL_FALSE;
    }
    return GL_TRUE;
}

static GLboolean npgl_special_clip_line(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *a, const NPDISP_OGL_VERTEX32 *b, NPDISP_OGL_VERTEX32 *outA, NPDISP_OGL_VERTEX32 *outB)
{
    int plane;
    NPDISP_OGL_VERTEX32 va, vb, vi;
    GLfloat da, db, t;
    if (!c || !a || !b || !outA || !outB) return GL_FALSE;
    va = *a;
    vb = *b;
    for (plane = 0; plane < 12; ++plane) {
        if (plane >= 6 && !c->clipPlaneEnabled[plane - 6]) continue;
        da = npgl_special_clip_distance(&va, plane);
        db = npgl_special_clip_distance(&vb, plane);
        if (da < 0.0f && db < 0.0f) return GL_FALSE;
        if (da < 0.0f || db < 0.0f) {
            if (da == db) return GL_FALSE;
            t = da / (da - db);
            npgl_special_lerp_vertex(c, &va, &vb, t, &vi);
            if (da < 0.0f) va = vi;
            else vb = vi;
        }
    }
    *outA = va;
    *outB = vb;
    return GL_TRUE;
}

static NPDISP_OGL_VERTEX32 *npgl_special_clip_polygon(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *vertices, DWORD count, DWORD *outCount)
{
    NPDISP_OGL_VERTEX32 *a, *b, *tmp;
    DWORD capacity, inCount, outN, i;
    int plane;
    if (outCount) *outCount = 0;
    if (!c || !vertices || count < 3 || !outCount) return NULL;
    if (count > 0x7ffffff0UL) return NULL;
    capacity = count + 16UL;
    a = (NPDISP_OGL_VERTEX32 *)HeapAlloc(GetProcessHeap(), 0, capacity * sizeof(*a));
    b = (NPDISP_OGL_VERTEX32 *)HeapAlloc(GetProcessHeap(), 0, capacity * sizeof(*b));
    if (!a || !b) {
        if (a) HeapFree(GetProcessHeap(), 0, a);
        if (b) HeapFree(GetProcessHeap(), 0, b);
        return NULL;
    }
    memcpy(a, vertices, count * sizeof(*a));
    inCount = count;
    for (plane = 0; plane < 12 && inCount; ++plane) {
        NPDISP_OGL_VERTEX32 prev, cur, vi;
        GLfloat dPrev, dCur;
        GLboolean prevInside, curInside;
        if (plane >= 6 && !c->clipPlaneEnabled[plane - 6]) continue;
        outN = 0;
        prev = a[inCount - 1];
        dPrev = npgl_special_clip_distance(&prev, plane);
        prevInside = dPrev >= 0.0f ? GL_TRUE : GL_FALSE;
        for (i = 0; i < inCount; ++i) {
            GLfloat t;
            cur = a[i];
            dCur = npgl_special_clip_distance(&cur, plane);
            curInside = dCur >= 0.0f ? GL_TRUE : GL_FALSE;
            if (curInside != prevInside) {
                t = dPrev / (dPrev - dCur);
                npgl_special_lerp_vertex(c, &prev, &cur, t, &vi);
                if (outN < capacity) b[outN++] = vi;
            }
            if (curInside && outN < capacity) b[outN++] = cur;
            prev = cur;
            dPrev = dCur;
            prevInside = curInside;
        }
        tmp = a; a = b; b = tmp;
        inCount = outN;
    }
    HeapFree(GetProcessHeap(), 0, b);
    *outCount = inCount;
    return a;
}

static GLboolean npgl_special_polygon_front(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *v, DWORD count, GLboolean *front)
{
    double area = 0.0;
    DWORD i, j;
    if (!c || !v || count < 3 || !front) return GL_FALSE;
    for (i = 0; i < count; ++i) {
        double x0 = (double)v[i].x;
        double y0 = (double)c->drawHeight - (double)v[i].y;
        j = (i + 1UL) % count;
        area += x0 * ((double)c->drawHeight - (double)v[j].y) - (double)v[j].x * y0;
    }
    if (area == 0.0) return GL_FALSE;
    *front = (c->frontFace == GL_CCW) ? (area > 0.0 ? GL_TRUE : GL_FALSE) : (area < 0.0 ? GL_TRUE : GL_FALSE);
    return GL_TRUE;
}

static GLboolean npgl_special_polygon_visible(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *v, DWORD count, GLboolean *front)
{
    GLboolean f;
    if (!npgl_special_polygon_front(c, v, count, &f)) return GL_FALSE;
    if (front) *front = f;
    if (!c->cullFaceEnable) return GL_TRUE;
    if (c->cullFace == GL_FRONT_AND_BACK) return GL_FALSE;
    if (c->cullFace == GL_FRONT && f) return GL_FALSE;
    if (c->cullFace == GL_BACK && !f) return GL_FALSE;
    return GL_TRUE;
}

static GLuint npgl_select_depth_value(GLfloat z)
{
    double d = (double)z;
    if (d <= 0.0) return 0UL;
    if (d >= 1.0) return 0xffffffffUL;
    return (GLuint)(d * 4294967295.0 + 0.5);
}

static void npgl_select_accumulate(NPGL_CONTEXT *c, GLfloat minDepth, GLfloat maxDepth)
{
    if (!c || c->renderMode != GL_SELECT) return;
    if (!c->selectHit) {
        c->selectMinDepth = minDepth;
        c->selectMaxDepth = maxDepth;
        c->selectHit = GL_TRUE;
    } else {
        if (minDepth < c->selectMinDepth) c->selectMinDepth = minDepth;
        if (maxDepth > c->selectMaxDepth) c->selectMaxDepth = maxDepth;
    }
}

static void npgl_select_write_uint(NPGL_CONTEXT *c, GLuint value)
{
    if (!c) return;
    if (c->selectIndex < c->selectBufferSize && c->selectBuffer) c->selectBuffer[c->selectIndex] = value;
    else c->selectOverflow = GL_TRUE;
    ++c->selectIndex;
}

static void npgl_select_flush_hit(NPGL_CONTEXT *c)
{
    GLint i;
    if (!c || c->renderMode != GL_SELECT || !c->selectHit) return;
    npgl_select_write_uint(c, (GLuint)c->nameStackDepth);
    npgl_select_write_uint(c, npgl_select_depth_value(c->selectMinDepth));
    npgl_select_write_uint(c, npgl_select_depth_value(c->selectMaxDepth));
    for (i = 0; i < c->nameStackDepth; ++i) npgl_select_write_uint(c, c->nameStack[i]);
    ++c->selectHits;
    c->selectHit = GL_FALSE;
}

static void npgl_feedback_write(NPGL_CONTEXT *c, GLfloat value)
{
    if (!c || c->renderMode != GL_FEEDBACK) return;
    if (c->feedbackIndex < c->feedbackBufferSize && c->feedbackBuffer) c->feedbackBuffer[c->feedbackIndex] = value;
    else c->feedbackOverflow = GL_TRUE;
    ++c->feedbackIndex;
}

static void npgl_feedback_write_color(NPGL_CONTEXT *c, DWORD diffuse)
{
    npgl_feedback_write(c, (GLfloat)((diffuse >> 16) & 0xffUL) / 255.0f);
    npgl_feedback_write(c, (GLfloat)((diffuse >> 8) & 0xffUL) / 255.0f);
    npgl_feedback_write(c, (GLfloat)(diffuse & 0xffUL) / 255.0f);
    npgl_feedback_write(c, (GLfloat)((diffuse >> 24) & 0xffUL) / 255.0f);
}

static void npgl_feedback_write_vertex(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *v)
{
    GLfloat y;
    if (!c || !v) return;
    y = (GLfloat)c->drawHeight - v->y;
    npgl_feedback_write(c, v->x);
    npgl_feedback_write(c, y);
    if (c->feedbackType != GL_2D) npgl_feedback_write(c, npgl_clampf(v->z, 0.0f, 1.0f));
    if (c->feedbackType == GL_4D_COLOR_TEXTURE) npgl_feedback_write(c, v->clip[3]);
    if (c->feedbackType == GL_3D_COLOR || c->feedbackType == GL_3D_COLOR_TEXTURE || c->feedbackType == GL_4D_COLOR_TEXTURE) npgl_feedback_write_color(c, v->diffuse);
    if (c->feedbackType == GL_3D_COLOR_TEXTURE || c->feedbackType == GL_4D_COLOR_TEXTURE) {
        npgl_feedback_write(c, v->texcoord[0]);
        npgl_feedback_write(c, v->texcoord[1]);
        npgl_feedback_write(c, v->texcoord[2]);
        npgl_feedback_write(c, v->texcoord[3]);
    }
}

static void npgl_feedback_write_raster_vertex(NPGL_CONTEXT *c)
{
    int i;
    if (!c || !c->rasterValid) return;
    npgl_feedback_write(c, c->rasterPosition[0]);
    npgl_feedback_write(c, c->rasterPosition[1]);
    if (c->feedbackType != GL_2D) npgl_feedback_write(c, npgl_clampf(c->rasterPosition[2], 0.0f, 1.0f));
    if (c->feedbackType == GL_4D_COLOR_TEXTURE) npgl_feedback_write(c, c->rasterPosition[3]);
    if (c->feedbackType == GL_3D_COLOR || c->feedbackType == GL_3D_COLOR_TEXTURE || c->feedbackType == GL_4D_COLOR_TEXTURE)
        for (i = 0; i < 4; ++i) npgl_feedback_write(c, c->rasterColor[i]);
    if (c->feedbackType == GL_3D_COLOR_TEXTURE || c->feedbackType == GL_4D_COLOR_TEXTURE)
        for (i = 0; i < 4; ++i) npgl_feedback_write(c, c->rasterTexCoord[i]);
}

static void npgl_feedback_point(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *v)
{
    npgl_feedback_write(c, (GLfloat)GL_POINT_TOKEN);
    npgl_feedback_write_vertex(c, v);
}

static void npgl_feedback_line(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *a, const NPDISP_OGL_VERTEX32 *b, GLboolean reset)
{
    npgl_feedback_write(c, (GLfloat)((reset && c->lineStipple) ? GL_LINE_RESET_TOKEN : GL_LINE_TOKEN));
    npgl_feedback_write_vertex(c, a);
    npgl_feedback_write_vertex(c, b);
}

static void npgl_feedback_polygon(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *v, DWORD count)
{
    DWORD i;
    npgl_feedback_write(c, (GLfloat)GL_POLYGON_TOKEN);
    npgl_feedback_write(c, (GLfloat)count);
    for (i = 0; i < count; ++i) npgl_feedback_write_vertex(c, &v[i]);
}

static void npgl_special_process_point(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *v)
{
    if (!npgl_special_vertex_inside(c, v)) return;
    if (c->renderMode == GL_SELECT) npgl_select_accumulate(c, v->z, v->z);
    else if (c->renderMode == GL_FEEDBACK) npgl_feedback_point(c, v);
}

static void npgl_special_process_line(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *a, const NPDISP_OGL_VERTEX32 *b, GLboolean reset)
{
    NPDISP_OGL_VERTEX32 va, vb;
    GLfloat minDepth, maxDepth;
    if (!npgl_special_clip_line(c, a, b, &va, &vb)) return;
    if (c->renderMode == GL_SELECT) {
        minDepth = va.z < vb.z ? va.z : vb.z;
        maxDepth = va.z > vb.z ? va.z : vb.z;
        npgl_select_accumulate(c, minDepth, maxDepth);
    } else if (c->renderMode == GL_FEEDBACK) npgl_feedback_line(c, &va, &vb, reset);
}

static void npgl_special_process_polygon(NPGL_CONTEXT *c, const NPDISP_OGL_VERTEX32 *v, DWORD count)
{
    NPDISP_OGL_VERTEX32 *clipped;
    DWORD clippedCount, i;
    GLboolean front;
    GLfloat minDepth, maxDepth;
    GLenum mode;
    clipped = npgl_special_clip_polygon(c, v, count, &clippedCount);
    if (!clipped) return;
    if (clippedCount < 3 || !npgl_special_polygon_visible(c, clipped, clippedCount, &front)) {
        HeapFree(GetProcessHeap(), 0, clipped);
        return;
    }
    if (c->renderMode == GL_SELECT) {
        minDepth = maxDepth = clipped[0].z;
        for (i = 1; i < clippedCount; ++i) {
            if (clipped[i].z < minDepth) minDepth = clipped[i].z;
            if (clipped[i].z > maxDepth) maxDepth = clipped[i].z;
        }
        npgl_select_accumulate(c, minDepth, maxDepth);
    } else if (c->renderMode == GL_FEEDBACK) {
        mode = front ? c->polygonModeFront : c->polygonModeBack;
        if (mode == GL_POINT) {
            for (i = 0; i < clippedCount; ++i) npgl_feedback_point(c, &clipped[i]);
        } else if (mode == GL_LINE) {
            for (i = 0; i < clippedCount; ++i) npgl_feedback_line(c, &clipped[i], &clipped[(i + 1UL) % clippedCount], i == 0 ? GL_TRUE : GL_FALSE);
        } else npgl_feedback_polygon(c, clipped, clippedCount);
    }
    HeapFree(GetProcessHeap(), 0, clipped);
}

static BOOL npgl_process_special_submit(NPGL_CONTEXT *c)
{
    DWORD i, n;
    NPDISP_OGL_VERTEX32 p[4];
    if (!c || c->renderMode == GL_RENDER) return TRUE;
    n = c->vertexCount;
    switch (c->beginMode) {
    case GL_POINTS:
        for (i = 0; i < n; ++i) npgl_special_process_point(c, &c->vertices[i]);
        break;
    case GL_LINES:
        for (i = 0; i + 1UL < n; i += 2UL) npgl_special_process_line(c, &c->vertices[i], &c->vertices[i + 1UL], GL_TRUE);
        break;
    case GL_LINE_STRIP:
        for (i = 0; i + 1UL < n; ++i) npgl_special_process_line(c, &c->vertices[i], &c->vertices[i + 1UL], i == 0 ? GL_TRUE : GL_FALSE);
        break;
    case GL_LINE_LOOP:
        for (i = 0; i + 1UL < n; ++i) npgl_special_process_line(c, &c->vertices[i], &c->vertices[i + 1UL], i == 0 ? GL_TRUE : GL_FALSE);
        if (n > 1UL) npgl_special_process_line(c, &c->vertices[n - 1UL], &c->vertices[0], GL_FALSE);
        break;
    case GL_TRIANGLES:
        for (i = 0; i + 2UL < n; i += 3UL) npgl_special_process_polygon(c, &c->vertices[i], 3UL);
        break;
    case GL_TRIANGLE_STRIP:
        for (i = 0; i + 2UL < n; ++i) {
            if (i & 1UL) { p[0] = c->vertices[i + 1UL]; p[1] = c->vertices[i]; }
            else { p[0] = c->vertices[i]; p[1] = c->vertices[i + 1UL]; }
            p[2] = c->vertices[i + 2UL];
            npgl_special_process_polygon(c, p, 3UL);
        }
        break;
    case GL_TRIANGLE_FAN:
        for (i = 1; i + 1UL < n; ++i) { p[0] = c->vertices[0]; p[1] = c->vertices[i]; p[2] = c->vertices[i + 1UL]; npgl_special_process_polygon(c, p, 3UL); }
        break;
    case GL_QUADS:
        for (i = 0; i + 3UL < n; i += 4UL) npgl_special_process_polygon(c, &c->vertices[i], 4UL);
        break;
    case GL_QUAD_STRIP:
        for (i = 0; i + 3UL < n; i += 2UL) {
            p[0] = c->vertices[i]; p[1] = c->vertices[i + 1UL]; p[2] = c->vertices[i + 3UL]; p[3] = c->vertices[i + 2UL];
            npgl_special_process_polygon(c, p, 4UL);
        }
        break;
    case GL_POLYGON:
        if (n >= 3UL) npgl_special_process_polygon(c, c->vertices, n);
        break;
    default:
        break;
    }
    return TRUE;
}

static BOOL npgl_submit(NPGL_CONTEXT *ctx)
{
    NPDISP_OGL_DRAW32 draw;
    NPGL_TEXTURE_OBJECT *tex;
    DWORD cull;
    if (!ctx || !ctx->vertexCount) return TRUE;
    if (ctx->renderMode != GL_RENDER) return npgl_process_special_submit(ctx);
    if (!npgl_ensure_drawable(ctx)) return FALSE;
    tex = npgl_active_texture(ctx);
    if (tex && !npgl_upload_texture(ctx, tex)) return FALSE;
    cull = npgl_fill_draw_state(ctx, &draw);
    if (!cull && (ctx->beginMode >= GL_TRIANGLES)) return TRUE;
    draw.primitive = ctx->beginMode;
    draw.vertexCount = ctx->vertexCount;
    draw.vertices = (DWORD)ctx->vertices;
    return npgl_host_call(NPDISP_OGL_CMD_DRAW, &draw) != 0;
}

static BOOL npgl_upload_host_list(NPGL_CONTEXT *ctx, NPGL_DISPLAY_LIST *list)
{
    NPDISP_OGL_LIST_UPLOAD32 packet;
    DWORD i;
    if (!ctx || !list || !list->defined) return FALSE;
    list->hostCached = GL_FALSE;
    list->finalColorSet = GL_FALSE;
    list->finalNormalSet = GL_FALSE;
    list->finalTexCoordSet = GL_FALSE;
    list->finalFrontFaceSet = GL_FALSE;
    list->finalTranslateSet = GL_FALSE;
    list->finalTranslate[0] = list->finalTranslate[1] = list->finalTranslate[2] = 0.0f;
    for (i = 0; i < list->commandCount; ++i) {
        NPGL_LIST_COMMAND *cmd = &list->commands[i];
        if (!((cmd->op >= NPGL_LIST_OP_BEGIN && cmd->op <= NPGL_LIST_OP_VERTEX4F) || cmd->op == NPGL_LIST_OP_TRANSLATE || cmd->op == NPGL_LIST_OP_FRONT_FACE)) return FALSE;
        if (cmd->op == NPGL_LIST_OP_COLOR4F) {
            list->finalColorSet = GL_TRUE;
            memcpy(list->finalColor, cmd->f, 4 * sizeof(GLfloat));
        }
        else if (cmd->op == NPGL_LIST_OP_NORMAL3F) {
            list->finalNormalSet = GL_TRUE;
            memcpy(list->finalNormal, cmd->f, 3 * sizeof(GLfloat));
        }
        else if (cmd->op == NPGL_LIST_OP_TEXCOORD2F) {
            list->finalTexCoordSet = GL_TRUE;
            list->finalTexCoord[0] = cmd->f[0];
            list->finalTexCoord[1] = cmd->f[1];
            list->finalTexCoord[2] = 0.0f;
            list->finalTexCoord[3] = 1.0f;
        }
        else if (cmd->op == NPGL_LIST_OP_FRONT_FACE) {
            list->finalFrontFaceSet = GL_TRUE;
            list->finalFrontFace = (GLenum)cmd->u[0];
        }
        else if (cmd->op == NPGL_LIST_OP_TRANSLATE) {
            list->finalTranslateSet = GL_TRUE;
            list->finalTranslate[0] += cmd->f[0];
            list->finalTranslate[1] += cmd->f[1];
            list->finalTranslate[2] += cmd->f[2];
        }
    }
    memset(&packet, 0, sizeof(packet));
    packet.size = sizeof(packet);
    packet.context = ctx->bridgeContext;
    packet.list = list->name;
    packet.commandCount = list->commandCount;
    packet.commands = (DWORD)list->commands;
    if (!npgl_host_call(NPDISP_OGL_CMD_LIST_UPLOAD, &packet)) return FALSE;
    list->hostCached = GL_TRUE;
    return TRUE;
}

static void npgl_apply_host_list_final(NPGL_CONTEXT *ctx, const NPGL_DISPLAY_LIST *list)
{
    if (!ctx || !list) return;
    if (list->finalColorSet) memcpy(ctx->currentColor, list->finalColor, sizeof(list->finalColor));
    if (list->finalNormalSet) memcpy(ctx->currentNormal, list->finalNormal, sizeof(list->finalNormal));
    if (list->finalTexCoordSet) memcpy(ctx->currentTexCoord, list->finalTexCoord, sizeof(list->finalTexCoord));
    if (list->finalFrontFaceSet) ctx->frontFace = list->finalFrontFace;
    if (list->finalTranslateSet) {
        GLfloat m[16];
        npgl_identity(m);
        m[12] = list->finalTranslate[0]; m[13] = list->finalTranslate[1]; m[14] = list->finalTranslate[2];
        npgl_mult_current(ctx, m);
    }
}

static void npgl_fill_host_list_state(NPGL_CONTEXT *ctx, NPDISP_OGL_LIST_EXEC32 *packet)
{
    int i;
    memset(packet, 0, sizeof(*packet));
    packet->size = sizeof(*packet);
    packet->context = ctx->bridgeContext;
    npgl_fill_draw_state(ctx, &packet->draw);
    memcpy(packet->modelview, ctx->modelview, sizeof(packet->modelview));
    memcpy(packet->projection, ctx->projection, sizeof(packet->projection));
    memcpy(packet->texture, ctx->texture, sizeof(packet->texture));
    memcpy(packet->viewport, ctx->viewport, sizeof(packet->viewport));
    packet->matrixMode = (DWORD)ctx->matrixMode;
    packet->depthNear = (GLfloat)ctx->depthNear;
    packet->depthFar = (GLfloat)ctx->depthFar;
    memcpy(packet->currentColor, ctx->currentColor, sizeof(packet->currentColor));
    memcpy(packet->currentNormal, ctx->currentNormal, sizeof(packet->currentNormal));
    memcpy(packet->currentTexCoord, ctx->currentTexCoord, sizeof(packet->currentTexCoord));
    packet->lighting = ctx->lighting ? 1UL : 0UL;
    packet->normalize = ctx->normalize ? 1UL : 0UL;
    packet->colorMaterial = ctx->colorMaterial ? 1UL : 0UL;
    packet->colorMaterialMode = (DWORD)ctx->colorMaterialMode;
    memcpy(packet->lightModelAmbient, ctx->lightModelAmbient, sizeof(packet->lightModelAmbient));
    packet->lightModelLocalViewer = ctx->lightModelLocalViewer ? 1UL : 0UL;
    for (i = 0; i < 8; ++i) {
        packet->lights[i].enabled = ctx->lights[i].enabled ? 1UL : 0UL;
        memcpy(packet->lights[i].ambient, ctx->lights[i].ambient, 4 * sizeof(GLfloat));
        memcpy(packet->lights[i].diffuse, ctx->lights[i].diffuse, 4 * sizeof(GLfloat));
        memcpy(packet->lights[i].specular, ctx->lights[i].specular, 4 * sizeof(GLfloat));
        memcpy(packet->lights[i].position, ctx->lights[i].position, 4 * sizeof(GLfloat));
        memcpy(packet->lights[i].spotDirection, ctx->lights[i].spotDirection, 3 * sizeof(GLfloat));
        packet->lights[i].spotExponent = ctx->lights[i].spotExponent;
        packet->lights[i].spotCutoff = ctx->lights[i].spotCutoff;
        packet->lights[i].constantAttenuation = ctx->lights[i].constantAttenuation;
        packet->lights[i].linearAttenuation = ctx->lights[i].linearAttenuation;
        packet->lights[i].quadraticAttenuation = ctx->lights[i].quadraticAttenuation;
    }
    memcpy(packet->materialAmbient, ctx->material.ambient, sizeof(packet->materialAmbient));
    memcpy(packet->materialDiffuse, ctx->material.diffuse, sizeof(packet->materialDiffuse));
    memcpy(packet->materialSpecular, ctx->material.specular, sizeof(packet->materialSpecular));
    memcpy(packet->materialEmission, ctx->material.emission, sizeof(packet->materialEmission));
    packet->materialShininess = ctx->material.shininess;
    packet->fog = ctx->fog ? 1UL : 0UL;
    packet->fogMode = (DWORD)ctx->fogMode;
    memcpy(packet->fogColor, ctx->fogColor, sizeof(packet->fogColor));
    packet->fogDensity = ctx->fogDensity;
    packet->fogStart = ctx->fogStart;
    packet->fogEnd = ctx->fogEnd;
    for (i = 0; i < 4; ++i) {
        packet->texGenEnabled[i] = ctx->texGenEnabled[i] ? 1UL : 0UL;
        packet->texGenMode[i] = (DWORD)ctx->texGenMode[i];
    }
    memcpy(packet->texGenObjectPlane, ctx->texGenObjectPlane, sizeof(packet->texGenObjectPlane));
    memcpy(packet->texGenEyePlane, ctx->texGenEyePlane, sizeof(packet->texGenEyePlane));
}

static BOOL npgl_execute_host_lists(NPGL_CONTEXT *ctx, const GLuint *lists, DWORD count)
{
    NPDISP_OGL_LIST_EXEC32 packet;
    if (!ctx || !lists || !count) return TRUE;
    { int i; for (i = 0; i < 6; ++i) if (ctx->clipPlaneEnabled[i]) return FALSE; }
    if (!npgl_ensure_drawable(ctx)) return FALSE;
    {
        NPGL_TEXTURE_OBJECT *tex = npgl_active_texture(ctx);
        if (tex && !npgl_upload_texture(ctx, tex)) return FALSE;
    }
    npgl_fill_host_list_state(ctx, &packet);
    packet.listCount = count;
    packet.lists = (DWORD)lists;
    if (!npgl_host_call(NPDISP_OGL_CMD_LIST_EXEC, &packet)) return FALSE;
    return TRUE;
}

/* API entry points. */
static void APIENTRY npgl_glBegin(GLenum mode)
{
    NPGL_CONTEXT *ctx=npgl_current();NPGL_LIST_COMMAND cmd;if(!ctx)return;
    if(ctx->compilingList&&!ctx->replayingList){if(ctx->listCompileInBegin){npgl_set_error(ctx,GL_INVALID_OPERATION);return;}if(mode>GL_POLYGON){npgl_set_error(ctx,GL_INVALID_ENUM);return;}memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_BEGIN;cmd.u[0]=mode;if(!npgl_record_list_command(ctx,&cmd))return;ctx->listCompileInBegin=GL_TRUE;if(ctx->listMode==GL_COMPILE)return;}
    if(ctx->inBegin){npgl_set_error(ctx,GL_INVALID_OPERATION);return;}if(mode>GL_POLYGON){npgl_set_error(ctx,GL_INVALID_ENUM);return;}ctx->inBegin=GL_TRUE;ctx->beginMode=mode;ctx->vertexCount=0;
}

static void APIENTRY npgl_glEnd(void)
{
    NPGL_CONTEXT *ctx=npgl_current();NPGL_LIST_COMMAND cmd;if(!ctx)return;
    if(ctx->compilingList&&!ctx->replayingList){if(!ctx->listCompileInBegin){npgl_set_error(ctx,GL_INVALID_OPERATION);return;}memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_END;if(!npgl_record_list_command(ctx,&cmd))return;ctx->listCompileInBegin=GL_FALSE;if(ctx->listMode==GL_COMPILE)return;}
    if(!ctx->inBegin){npgl_set_error(ctx,GL_INVALID_OPERATION);return;}ctx->inBegin=GL_FALSE;if(!npgl_submit(ctx))npgl_set_error(ctx,GL_OUT_OF_MEMORY);
}

static GLfloat npgl_norm_s8(GLbyte v) { return (GLfloat)(((double)v * 2.0 + 1.0) / 255.0); }
static GLfloat npgl_norm_s16(GLshort v) { return (GLfloat)(((double)v * 2.0 + 1.0) / 65535.0); }
static GLfloat npgl_norm_s32(GLint v) { return (GLfloat)(((double)v * 2.0 + 1.0) / 4294967295.0); }
static GLfloat npgl_norm_u8(GLubyte v) { return (GLfloat)((double)v / 255.0); }
static GLfloat npgl_norm_u16(GLushort v) { return (GLfloat)((double)v / 65535.0); }
static GLfloat npgl_norm_u32(GLuint v) { return (GLfloat)((double)v / 4294967295.0); }

static void APIENTRY npgl_glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{ NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_COLOR4F;cmd.f[0]=r;cmd.f[1]=g;cmd.f[2]=b;cmd.f[3]=a;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->currentColor[0]=r;c->currentColor[1]=g;c->currentColor[2]=b;c->currentColor[3]=a; }
static void APIENTRY npgl_glColor3b(GLbyte r, GLbyte g, GLbyte b) { npgl_glColor4f(npgl_norm_s8(r),npgl_norm_s8(g),npgl_norm_s8(b),1.0f); }
static void APIENTRY npgl_glColor3bv(const GLbyte *v) { if(v)npgl_glColor3b(v[0],v[1],v[2]); }
static void APIENTRY npgl_glColor3d(GLdouble r, GLdouble g, GLdouble b) { npgl_glColor4f((GLfloat)r,(GLfloat)g,(GLfloat)b,1.0f); }
static void APIENTRY npgl_glColor3dv(const GLdouble *v) { if(v)npgl_glColor3d(v[0],v[1],v[2]); }
static void APIENTRY npgl_glColor3f(GLfloat r, GLfloat g, GLfloat b) { npgl_glColor4f(r,g,b,1.0f); }
static void APIENTRY npgl_glColor3fv(const GLfloat *v) { if(v)npgl_glColor3f(v[0],v[1],v[2]); }
static void APIENTRY npgl_glColor3i(GLint r, GLint g, GLint b) { npgl_glColor4f(npgl_norm_s32(r),npgl_norm_s32(g),npgl_norm_s32(b),1.0f); }
static void APIENTRY npgl_glColor3iv(const GLint *v) { if(v)npgl_glColor3i(v[0],v[1],v[2]); }
static void APIENTRY npgl_glColor3s(GLshort r, GLshort g, GLshort b) { npgl_glColor4f(npgl_norm_s16(r),npgl_norm_s16(g),npgl_norm_s16(b),1.0f); }
static void APIENTRY npgl_glColor3sv(const GLshort *v) { if(v)npgl_glColor3s(v[0],v[1],v[2]); }
static void APIENTRY npgl_glColor3ub(GLubyte r, GLubyte g, GLubyte b) { npgl_glColor4f(npgl_norm_u8(r),npgl_norm_u8(g),npgl_norm_u8(b),1.0f); }
static void APIENTRY npgl_glColor3ubv(const GLubyte *v) { if(v)npgl_glColor3ub(v[0],v[1],v[2]); }
static void APIENTRY npgl_glColor3ui(GLuint r, GLuint g, GLuint b) { npgl_glColor4f(npgl_norm_u32(r),npgl_norm_u32(g),npgl_norm_u32(b),1.0f); }
static void APIENTRY npgl_glColor3uiv(const GLuint *v) { if(v)npgl_glColor3ui(v[0],v[1],v[2]); }
static void APIENTRY npgl_glColor3us(GLushort r, GLushort g, GLushort b) { npgl_glColor4f(npgl_norm_u16(r),npgl_norm_u16(g),npgl_norm_u16(b),1.0f); }
static void APIENTRY npgl_glColor3usv(const GLushort *v) { if(v)npgl_glColor3us(v[0],v[1],v[2]); }
static void APIENTRY npgl_glColor4b(GLbyte r, GLbyte g, GLbyte b, GLbyte a) { npgl_glColor4f(npgl_norm_s8(r),npgl_norm_s8(g),npgl_norm_s8(b),npgl_norm_s8(a)); }
static void APIENTRY npgl_glColor4bv(const GLbyte *v) { if(v)npgl_glColor4b(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glColor4d(GLdouble r, GLdouble g, GLdouble b, GLdouble a) { npgl_glColor4f((GLfloat)r,(GLfloat)g,(GLfloat)b,(GLfloat)a); }
static void APIENTRY npgl_glColor4dv(const GLdouble *v) { if(v)npgl_glColor4d(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glColor4fv(const GLfloat *v) { if(v)npgl_glColor4f(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glColor4i(GLint r, GLint g, GLint b, GLint a) { npgl_glColor4f(npgl_norm_s32(r),npgl_norm_s32(g),npgl_norm_s32(b),npgl_norm_s32(a)); }
static void APIENTRY npgl_glColor4iv(const GLint *v) { if(v)npgl_glColor4i(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glColor4s(GLshort r, GLshort g, GLshort b, GLshort a) { npgl_glColor4f(npgl_norm_s16(r),npgl_norm_s16(g),npgl_norm_s16(b),npgl_norm_s16(a)); }
static void APIENTRY npgl_glColor4sv(const GLshort *v) { if(v)npgl_glColor4s(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glColor4ub(GLubyte r, GLubyte g, GLubyte b, GLubyte a) { npgl_glColor4f(npgl_norm_u8(r),npgl_norm_u8(g),npgl_norm_u8(b),npgl_norm_u8(a)); }
static void APIENTRY npgl_glColor4ubv(const GLubyte *v) { if(v)npgl_glColor4ub(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glColor4ui(GLuint r, GLuint g, GLuint b, GLuint a) { npgl_glColor4f(npgl_norm_u32(r),npgl_norm_u32(g),npgl_norm_u32(b),npgl_norm_u32(a)); }
static void APIENTRY npgl_glColor4uiv(const GLuint *v) { if(v)npgl_glColor4ui(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glColor4us(GLushort r, GLushort g, GLushort b, GLushort a) { npgl_glColor4f(npgl_norm_u16(r),npgl_norm_u16(g),npgl_norm_u16(b),npgl_norm_u16(a)); }
static void APIENTRY npgl_glColor4usv(const GLushort *v) { if(v)npgl_glColor4us(v[0],v[1],v[2],v[3]); }

static void APIENTRY npgl_glNormal3f(GLfloat x, GLfloat y, GLfloat z)
{ NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_NORMAL3F;cmd.f[0]=x;cmd.f[1]=y;cmd.f[2]=z;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->currentNormal[0]=x;c->currentNormal[1]=y;c->currentNormal[2]=z; }
static void APIENTRY npgl_glNormal3b(GLbyte x, GLbyte y, GLbyte z) { npgl_glNormal3f(npgl_norm_s8(x),npgl_norm_s8(y),npgl_norm_s8(z)); }
static void APIENTRY npgl_glNormal3bv(const GLbyte *v) { if(v)npgl_glNormal3b(v[0],v[1],v[2]); }
static void APIENTRY npgl_glNormal3d(GLdouble x, GLdouble y, GLdouble z) { npgl_glNormal3f((GLfloat)x,(GLfloat)y,(GLfloat)z); }
static void APIENTRY npgl_glNormal3dv(const GLdouble *v) { if(v)npgl_glNormal3d(v[0],v[1],v[2]); }
static void APIENTRY npgl_glNormal3fv(const GLfloat *v) { if(v)npgl_glNormal3f(v[0],v[1],v[2]); }
static void APIENTRY npgl_glNormal3i(GLint x, GLint y, GLint z) { npgl_glNormal3f(npgl_norm_s32(x),npgl_norm_s32(y),npgl_norm_s32(z)); }
static void APIENTRY npgl_glNormal3iv(const GLint *v) { if(v)npgl_glNormal3i(v[0],v[1],v[2]); }
static void APIENTRY npgl_glNormal3s(GLshort x, GLshort y, GLshort z) { npgl_glNormal3f(npgl_norm_s16(x),npgl_norm_s16(y),npgl_norm_s16(z)); }
static void APIENTRY npgl_glNormal3sv(const GLshort *v) { if(v)npgl_glNormal3s(v[0],v[1],v[2]); }

static void npgl_texcoord4f_recordable(GLfloat ss, GLfloat tt, GLfloat rr, GLfloat qq)
{ NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_TEXCOORD4F;cmd.f[0]=ss;cmd.f[1]=tt;cmd.f[2]=rr;cmd.f[3]=qq;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->currentTexCoord[0]=ss;c->currentTexCoord[1]=tt;c->currentTexCoord[2]=rr;c->currentTexCoord[3]=qq; }
static void APIENTRY npgl_glTexCoord2f(GLfloat ss, GLfloat tt)
{ NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_TEXCOORD2F;cmd.f[0]=ss;cmd.f[1]=tt;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->currentTexCoord[0]=ss;c->currentTexCoord[1]=tt;c->currentTexCoord[2]=0.0f;c->currentTexCoord[3]=1.0f; }
static void APIENTRY npgl_glTexCoord1d(GLdouble s) { npgl_glTexCoord2f((GLfloat)s,0.0f); }
static void APIENTRY npgl_glTexCoord1dv(const GLdouble *v) { if(v)npgl_glTexCoord1d(v[0]); }
static void APIENTRY npgl_glTexCoord1f(GLfloat s) { npgl_glTexCoord2f(s,0.0f); }
static void APIENTRY npgl_glTexCoord1fv(const GLfloat *v) { if(v)npgl_glTexCoord1f(v[0]); }
static void APIENTRY npgl_glTexCoord1i(GLint s) { npgl_glTexCoord2f((GLfloat)s,0.0f); }
static void APIENTRY npgl_glTexCoord1iv(const GLint *v) { if(v)npgl_glTexCoord1i(v[0]); }
static void APIENTRY npgl_glTexCoord1s(GLshort s) { npgl_glTexCoord2f((GLfloat)s,0.0f); }
static void APIENTRY npgl_glTexCoord1sv(const GLshort *v) { if(v)npgl_glTexCoord1s(v[0]); }
static void APIENTRY npgl_glTexCoord2d(GLdouble ss, GLdouble tt) { npgl_glTexCoord2f((GLfloat)ss,(GLfloat)tt); }
static void APIENTRY npgl_glTexCoord2dv(const GLdouble *v) { if(v)npgl_glTexCoord2d(v[0],v[1]); }
static void APIENTRY npgl_glTexCoord2fv(const GLfloat *v) { if(v)npgl_glTexCoord2f(v[0],v[1]); }
static void APIENTRY npgl_glTexCoord2i(GLint ss, GLint tt) { npgl_glTexCoord2f((GLfloat)ss,(GLfloat)tt); }
static void APIENTRY npgl_glTexCoord2iv(const GLint *v) { if(v)npgl_glTexCoord2i(v[0],v[1]); }
static void APIENTRY npgl_glTexCoord2s(GLshort ss, GLshort tt) { npgl_glTexCoord2f((GLfloat)ss,(GLfloat)tt); }
static void APIENTRY npgl_glTexCoord2sv(const GLshort *v) { if(v)npgl_glTexCoord2s(v[0],v[1]); }
static void APIENTRY npgl_glTexCoord3d(GLdouble ss, GLdouble tt, GLdouble rr) { npgl_texcoord4f_recordable((GLfloat)ss,(GLfloat)tt,(GLfloat)rr,1.0f); }
static void APIENTRY npgl_glTexCoord3dv(const GLdouble *v) { if(v)npgl_glTexCoord3d(v[0],v[1],v[2]); }
static void APIENTRY npgl_glTexCoord3f(GLfloat ss, GLfloat tt, GLfloat rr) { npgl_texcoord4f_recordable(ss,tt,rr,1.0f); }
static void APIENTRY npgl_glTexCoord3fv(const GLfloat *v) { if(v)npgl_glTexCoord3f(v[0],v[1],v[2]); }
static void APIENTRY npgl_glTexCoord3i(GLint ss, GLint tt, GLint rr) { npgl_texcoord4f_recordable((GLfloat)ss,(GLfloat)tt,(GLfloat)rr,1.0f); }
static void APIENTRY npgl_glTexCoord3iv(const GLint *v) { if(v)npgl_glTexCoord3i(v[0],v[1],v[2]); }
static void APIENTRY npgl_glTexCoord3s(GLshort ss, GLshort tt, GLshort rr) { npgl_texcoord4f_recordable((GLfloat)ss,(GLfloat)tt,(GLfloat)rr,1.0f); }
static void APIENTRY npgl_glTexCoord3sv(const GLshort *v) { if(v)npgl_glTexCoord3s(v[0],v[1],v[2]); }
static void APIENTRY npgl_glTexCoord4d(GLdouble ss, GLdouble tt, GLdouble rr, GLdouble qq) { npgl_texcoord4f_recordable((GLfloat)ss,(GLfloat)tt,(GLfloat)rr,(GLfloat)qq); }
static void APIENTRY npgl_glTexCoord4dv(const GLdouble *v) { if(v)npgl_glTexCoord4d(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glTexCoord4f(GLfloat ss, GLfloat tt, GLfloat rr, GLfloat qq) { npgl_texcoord4f_recordable(ss,tt,rr,qq); }
static void APIENTRY npgl_glTexCoord4fv(const GLfloat *v) { if(v)npgl_glTexCoord4f(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glTexCoord4i(GLint ss, GLint tt, GLint rr, GLint qq) { npgl_texcoord4f_recordable((GLfloat)ss,(GLfloat)tt,(GLfloat)rr,(GLfloat)qq); }
static void APIENTRY npgl_glTexCoord4iv(const GLint *v) { if(v)npgl_glTexCoord4i(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glTexCoord4s(GLshort ss, GLshort tt, GLshort rr, GLshort qq) { npgl_texcoord4f_recordable((GLfloat)ss,(GLfloat)tt,(GLfloat)rr,(GLfloat)qq); }
static void APIENTRY npgl_glTexCoord4sv(const GLshort *v) { if(v)npgl_glTexCoord4s(v[0],v[1],v[2],v[3]); }

static void npgl_vertex4f_recordable(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{ NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->compilingList&&!c->replayingList){if(!c->listCompileInBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_VERTEX4F;cmd.f[0]=x;cmd.f[1]=y;cmd.f[2]=z;cmd.f[3]=w;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}npgl_emit_vertex(x,y,z,w); }
static void APIENTRY npgl_glVertex2d(GLdouble x, GLdouble y) { npgl_vertex4f_recordable((GLfloat)x,(GLfloat)y,0.0f,1.0f); }
static void APIENTRY npgl_glVertex2dv(const GLdouble *v) { if(v)npgl_glVertex2d(v[0],v[1]); }
static void APIENTRY npgl_glVertex2f(GLfloat x, GLfloat y) { npgl_vertex4f_recordable(x,y,0.0f,1.0f); }
static void APIENTRY npgl_glVertex2fv(const GLfloat *v) { if(v)npgl_glVertex2f(v[0],v[1]); }
static void APIENTRY npgl_glVertex2i(GLint x, GLint y) { npgl_vertex4f_recordable((GLfloat)x,(GLfloat)y,0.0f,1.0f); }
static void APIENTRY npgl_glVertex2iv(const GLint *v) { if(v)npgl_glVertex2i(v[0],v[1]); }
static void APIENTRY npgl_glVertex2s(GLshort x, GLshort y) { npgl_vertex4f_recordable((GLfloat)x,(GLfloat)y,0.0f,1.0f); }
static void APIENTRY npgl_glVertex2sv(const GLshort *v) { if(v)npgl_glVertex2s(v[0],v[1]); }
static void APIENTRY npgl_glVertex3d(GLdouble x, GLdouble y, GLdouble z) { npgl_vertex4f_recordable((GLfloat)x,(GLfloat)y,(GLfloat)z,1.0f); }
static void APIENTRY npgl_glVertex3dv(const GLdouble *v) { if(v)npgl_glVertex3d(v[0],v[1],v[2]); }
static void APIENTRY npgl_glVertex3f(GLfloat x, GLfloat y, GLfloat z) { npgl_vertex4f_recordable(x,y,z,1.0f); }
static void APIENTRY npgl_glVertex3fv(const GLfloat *v) { if(v)npgl_glVertex3f(v[0],v[1],v[2]); }
static void APIENTRY npgl_glVertex3i(GLint x, GLint y, GLint z) { npgl_vertex4f_recordable((GLfloat)x,(GLfloat)y,(GLfloat)z,1.0f); }
static void APIENTRY npgl_glVertex3iv(const GLint *v) { if(v)npgl_glVertex3i(v[0],v[1],v[2]); }
static void APIENTRY npgl_glVertex3s(GLshort x, GLshort y, GLshort z) { npgl_vertex4f_recordable((GLfloat)x,(GLfloat)y,(GLfloat)z,1.0f); }
static void APIENTRY npgl_glVertex3sv(const GLshort *v) { if(v)npgl_glVertex3s(v[0],v[1],v[2]); }
static void APIENTRY npgl_glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) { npgl_vertex4f_recordable((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w); }
static void APIENTRY npgl_glVertex4dv(const GLdouble *v) { if(v)npgl_glVertex4d(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) { npgl_vertex4f_recordable(x,y,z,w); }
static void APIENTRY npgl_glVertex4fv(const GLfloat *v) { if(v)npgl_glVertex4f(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glVertex4i(GLint x, GLint y, GLint z, GLint w) { npgl_vertex4f_recordable((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w); }
static void APIENTRY npgl_glVertex4iv(const GLint *v) { if(v)npgl_glVertex4i(v[0],v[1],v[2],v[3]); }
static void APIENTRY npgl_glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) { npgl_vertex4f_recordable((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w); }
static void APIENTRY npgl_glVertex4sv(const GLshort *v) { if(v)npgl_glVertex4s(v[0],v[1],v[2],v[3]); }

static void npgl_rectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{ NPGL_CONTEXT *c=npgl_current();if(!c)return;if(c->inBegin||(c->compilingList&&!c->replayingList&&c->listCompileInBegin)){npgl_set_error(c,GL_INVALID_OPERATION);return;}npgl_glBegin(GL_QUADS);npgl_glVertex2f(x1,y1);npgl_glVertex2f(x2,y1);npgl_glVertex2f(x2,y2);npgl_glVertex2f(x1,y2);npgl_glEnd(); }
static void APIENTRY npgl_glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) { npgl_rectf((GLfloat)x1,(GLfloat)y1,(GLfloat)x2,(GLfloat)y2); }
static void APIENTRY npgl_glRectdv(const GLdouble *v1, const GLdouble *v2) { if(v1&&v2)npgl_glRectd(v1[0],v1[1],v2[0],v2[1]); }
static void APIENTRY npgl_glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) { npgl_rectf(x1,y1,x2,y2); }
static void APIENTRY npgl_glRectfv(const GLfloat *v1, const GLfloat *v2) { if(v1&&v2)npgl_glRectf(v1[0],v1[1],v2[0],v2[1]); }
static void APIENTRY npgl_glRecti(GLint x1, GLint y1, GLint x2, GLint y2) { npgl_rectf((GLfloat)x1,(GLfloat)y1,(GLfloat)x2,(GLfloat)y2); }
static void APIENTRY npgl_glRectiv(const GLint *v1, const GLint *v2) { if(v1&&v2)npgl_glRecti(v1[0],v1[1],v2[0],v2[1]); }
static void APIENTRY npgl_glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) { npgl_rectf((GLfloat)x1,(GLfloat)y1,(GLfloat)x2,(GLfloat)y2); }
static void APIENTRY npgl_glRectsv(const GLshort *v1, const GLshort *v2) { if(v1&&v2)npgl_glRects(v1[0],v1[1],v2[0],v2[1]); }

static void APIENTRY npgl_glTexParameteri(GLenum target, GLenum pname, GLint param)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_TEXTURE_OBJECT *obj;
    NPGL_LIST_COMMAND cmd;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (target != GL_TEXTURE_1D && target != GL_TEXTURE_2D) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    switch (pname) {
    case GL_TEXTURE_WRAP_S:
    case GL_TEXTURE_WRAP_T:
        if (param != GL_REPEAT && param != GL_CLAMP) { npgl_set_error(c, GL_INVALID_ENUM); return; }
        break;
    case GL_TEXTURE_MIN_FILTER:
        if (!npgl_texture_filter((GLenum)param)) { npgl_set_error(c, GL_INVALID_ENUM); return; }
        break;
    case GL_TEXTURE_MAG_FILTER:
        if (param != GL_NEAREST && param != GL_LINEAR) { npgl_set_error(c, GL_INVALID_ENUM); return; }
        break;
    default:
        npgl_set_error(c, GL_INVALID_ENUM); return;
    }
    if (c->compilingList && !c->replayingList) {
        memset(&cmd, 0, sizeof(cmd)); cmd.op = NPGL_LIST_OP_TEX_PARAMETERI;
        cmd.u[0] = (DWORD)target; cmd.u[1] = (DWORD)pname; cmd.u[2] = (DWORD)param;
        if (!npgl_record_list_command(c, &cmd)) return;
        if (c->listMode == GL_COMPILE) return;
    }
    obj = npgl_bound_texture(c, target);
    if (!obj) return;
    switch (pname) {
    case GL_TEXTURE_WRAP_S: obj->wrapS = (GLenum)param; break;
    case GL_TEXTURE_WRAP_T: obj->wrapT = (GLenum)param; break;
    case GL_TEXTURE_MIN_FILTER: obj->minFilter = (GLenum)param; break;
    case GL_TEXTURE_MAG_FILTER: obj->magFilter = (GLenum)param; break;
    }
}

static void APIENTRY npgl_glTexParameterf(GLenum target, GLenum pname, GLfloat param) { npgl_glTexParameteri(target, pname, (GLint)param); }
static void APIENTRY npgl_glTexParameteriv(GLenum target, GLenum pname, const GLint *params) { if (params) npgl_glTexParameteri(target, pname, params[0]); }
static void APIENTRY npgl_glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params) { if (params) npgl_glTexParameterf(target, pname, params[0]); }

static void APIENTRY npgl_glTexEnvi(GLenum target, GLenum pname, GLint param)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_LIST_COMMAND cmd;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (target != GL_TEXTURE_ENV || pname != GL_TEXTURE_ENV_MODE) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    if (param != GL_MODULATE && param != GL_REPLACE && param != GL_DECAL) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    if (c->compilingList && !c->replayingList) {
        memset(&cmd, 0, sizeof(cmd)); cmd.op = NPGL_LIST_OP_TEX_ENVI;
        cmd.u[0] = (DWORD)target; cmd.u[1] = (DWORD)pname; cmd.u[2] = (DWORD)param;
        if (!npgl_record_list_command(c, &cmd)) return;
        if (c->listMode == GL_COMPILE) return;
    }
    c->textureEnvMode = (GLenum)param;
}

static void APIENTRY npgl_glTexEnvf(GLenum target, GLenum pname, GLfloat param) { npgl_glTexEnvi(target, pname, (GLint)param); }
static void APIENTRY npgl_glTexEnviv(GLenum target, GLenum pname, const GLint *params) { if (params) npgl_glTexEnvi(target, pname, params[0]); }
static void APIENTRY npgl_glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params) { if (params) npgl_glTexEnvf(target, pname, params[0]); }

static int npgl_texgen_index(GLenum coord)
{
    switch (coord) { case GL_S:return 0; case GL_T:return 1; case GL_R:return 2; case GL_Q:return 3; default:return -1; }
}

static void APIENTRY npgl_glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params)
{
    NPGL_CONTEXT *c=npgl_current();int i;if(!c||!params)return;i=npgl_texgen_index(coord);if(i<0){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(pname==GL_TEXTURE_GEN_MODE){GLenum mode=(GLenum)(GLint)params[0];if(mode!=GL_OBJECT_LINEAR&&mode!=GL_EYE_LINEAR&&mode!=GL_SPHERE_MAP){npgl_set_error(c,GL_INVALID_ENUM);return;}if(mode==GL_SPHERE_MAP&&i>1){npgl_set_error(c,GL_INVALID_ENUM);return;}c->texGenMode[i]=mode;}
    else if(pname==GL_OBJECT_PLANE)memcpy(c->texGenObjectPlane[i],params,4*sizeof(GLfloat));
    else if(pname==GL_EYE_PLANE)memcpy(c->texGenEyePlane[i],params,4*sizeof(GLfloat));
    else {npgl_set_error(c,GL_INVALID_ENUM);return;}
}
static void APIENTRY npgl_glTexGeni(GLenum coord, GLenum pname, GLint param) { GLfloat f[4];f[0]=(GLfloat)param;f[1]=f[2]=f[3]=0.0f;npgl_glTexGenfv(coord,pname,f); }
static void APIENTRY npgl_glTexGenf(GLenum coord, GLenum pname, GLfloat param) { GLfloat f[4];f[0]=param;f[1]=f[2]=f[3]=0.0f;npgl_glTexGenfv(coord,pname,f); }
static void APIENTRY npgl_glTexGend(GLenum coord, GLenum pname, GLdouble param) { npgl_glTexGenf(coord,pname,(GLfloat)param); }
static void APIENTRY npgl_glTexGeniv(GLenum coord, GLenum pname, const GLint *params) { GLfloat f[4];int n=(pname==GL_TEXTURE_GEN_MODE)?1:4,i;if(!params)return;for(i=0;i<n;++i)f[i]=(GLfloat)params[i];for(;i<4;++i)f[i]=0.0f;npgl_glTexGenfv(coord,pname,f); }
static void APIENTRY npgl_glTexGendv(GLenum coord, GLenum pname, const GLdouble *params) { GLfloat f[4];int n=(pname==GL_TEXTURE_GEN_MODE)?1:4,i;if(!params)return;for(i=0;i<n;++i)f[i]=(GLfloat)params[i];for(;i<4;++i)f[i]=0.0f;npgl_glTexGenfv(coord,pname,f); }

static void APIENTRY npgl_glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params)
{
    NPGL_CONTEXT *c=npgl_current();int i;if(!c||!params)return;i=npgl_texgen_index(coord);if(i<0){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(pname==GL_TEXTURE_GEN_MODE)params[0]=(GLfloat)c->texGenMode[i];
    else if(pname==GL_OBJECT_PLANE)memcpy(params,c->texGenObjectPlane[i],4*sizeof(GLfloat));
    else if(pname==GL_EYE_PLANE)memcpy(params,c->texGenEyePlane[i],4*sizeof(GLfloat));
    else npgl_set_error(c,GL_INVALID_ENUM);
}
static void APIENTRY npgl_glGetTexGeniv(GLenum coord, GLenum pname, GLint *params) { GLfloat f[4];int n=(pname==GL_TEXTURE_GEN_MODE)?1:4,i;if(!params)return;npgl_glGetTexGenfv(coord,pname,f);for(i=0;i<n;++i)params[i]=(GLint)f[i]; }
static void APIENTRY npgl_glGetTexGendv(GLenum coord, GLenum pname, GLdouble *params) { GLfloat f[4];int n=(pname==GL_TEXTURE_GEN_MODE)?1:4,i;if(!params)return;npgl_glGetTexGenfv(coord,pname,f);for(i=0;i<n;++i)params[i]=(GLdouble)f[i]; }

static void APIENTRY npgl_glPixelStorei(GLenum pname, GLint param)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    switch (pname) {
    case GL_PACK_ALIGNMENT:
    case GL_UNPACK_ALIGNMENT:
        if (param != 1 && param != 2 && param != 4 && param != 8) { npgl_set_error(c, GL_INVALID_VALUE); return; }
        if (pname == GL_PACK_ALIGNMENT) c->packAlignment = param; else c->unpackAlignment = param;
        break;
    case GL_PACK_ROW_LENGTH: if (param < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; } c->packRowLength = param; break;
    case GL_PACK_SKIP_ROWS: if (param < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; } c->packSkipRows = param; break;
    case GL_PACK_SKIP_PIXELS: if (param < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; } c->packSkipPixels = param; break;
    case GL_UNPACK_ROW_LENGTH: if (param < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; } c->unpackRowLength = param; break;
    case GL_UNPACK_SKIP_ROWS: if (param < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; } c->unpackSkipRows = param; break;
    case GL_UNPACK_SKIP_PIXELS: if (param < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; } c->unpackSkipPixels = param; break;
    case GL_PACK_SWAP_BYTES: c->packSwapBytes = param ? GL_TRUE : GL_FALSE; break;
    case GL_PACK_LSB_FIRST: c->packLsbFirst = param ? GL_TRUE : GL_FALSE; break;
    case GL_UNPACK_SWAP_BYTES: c->unpackSwapBytes = param ? GL_TRUE : GL_FALSE; break;
    case GL_UNPACK_LSB_FIRST: c->unpackLsbFirst = param ? GL_TRUE : GL_FALSE; break;
    default: npgl_set_error(c, GL_INVALID_ENUM); break;
    }
}

static void APIENTRY npgl_glPixelStoref(GLenum pname, GLfloat param) { npgl_glPixelStorei(pname, (GLint)param); }

static void npgl_set_raster_pos(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    NPGL_CONTEXT *c = npgl_current();
    GLfloat obj[4], eye[4], clip[4], invW, ndcX, ndcY, ndcZ;
    int row, k;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    obj[0]=x; obj[1]=y; obj[2]=z; obj[3]=w;
    for (row=0; row<4; ++row) { eye[row]=0.0f; for (k=0;k<4;++k) eye[row]+=c->modelview[k*4+row]*obj[k]; }
    for (row=0; row<4; ++row) { clip[row]=0.0f; for (k=0;k<4;++k) clip[row]+=c->projection[k*4+row]*eye[k]; }
    c->rasterValid = GL_FALSE;
    for (k=0; k<6; ++k) if (c->clipPlaneEnabled[k] && c->clipPlane[k][0]*eye[0]+c->clipPlane[k][1]*eye[1]+c->clipPlane[k][2]*eye[2]+c->clipPlane[k][3]*eye[3] < 0.0) return;
    if (clip[3] == 0.0f) return;
    if (clip[0] < -clip[3] || clip[0] > clip[3] || clip[1] < -clip[3] || clip[1] > clip[3] || clip[2] < -clip[3] || clip[2] > clip[3]) return;
    invW=1.0f/clip[3]; ndcX=clip[0]*invW; ndcY=clip[1]*invW; ndcZ=clip[2]*invW;
    c->rasterPosition[0]=(GLfloat)c->viewport[0]+(ndcX+1.0f)*(GLfloat)c->viewport[2]*0.5f;
    c->rasterPosition[1]=(GLfloat)c->viewport[1]+(ndcY+1.0f)*(GLfloat)c->viewport[3]*0.5f;
    c->rasterPosition[2]=(GLfloat)(c->depthNear+(ndcZ+1.0)*(c->depthFar-c->depthNear)*0.5);
    c->rasterPosition[3]=clip[3];
    memcpy(c->rasterColor,c->currentColor,sizeof(c->rasterColor));
    memcpy(c->rasterTexCoord,c->currentTexCoord,sizeof(c->rasterTexCoord));
    c->rasterDistance = eye[2] < 0.0f ? -eye[2] : eye[2];
    c->rasterValid = GL_TRUE;
    if (c->renderMode == GL_SELECT) npgl_select_accumulate(c, c->rasterPosition[2], c->rasterPosition[2]);
}
static void APIENTRY npgl_glRasterPos2d(GLdouble x,GLdouble y){npgl_set_raster_pos((GLfloat)x,(GLfloat)y,0.0f,1.0f);} static void APIENTRY npgl_glRasterPos2dv(const GLdouble*v){if(v)npgl_glRasterPos2d(v[0],v[1]);}
static void APIENTRY npgl_glRasterPos2f(GLfloat x,GLfloat y){npgl_set_raster_pos(x,y,0.0f,1.0f);} static void APIENTRY npgl_glRasterPos2fv(const GLfloat*v){if(v)npgl_glRasterPos2f(v[0],v[1]);}
static void APIENTRY npgl_glRasterPos2i(GLint x,GLint y){npgl_set_raster_pos((GLfloat)x,(GLfloat)y,0.0f,1.0f);} static void APIENTRY npgl_glRasterPos2iv(const GLint*v){if(v)npgl_glRasterPos2i(v[0],v[1]);}
static void APIENTRY npgl_glRasterPos2s(GLshort x,GLshort y){npgl_set_raster_pos((GLfloat)x,(GLfloat)y,0.0f,1.0f);} static void APIENTRY npgl_glRasterPos2sv(const GLshort*v){if(v)npgl_glRasterPos2s(v[0],v[1]);}
static void APIENTRY npgl_glRasterPos3d(GLdouble x,GLdouble y,GLdouble z){npgl_set_raster_pos((GLfloat)x,(GLfloat)y,(GLfloat)z,1.0f);} static void APIENTRY npgl_glRasterPos3dv(const GLdouble*v){if(v)npgl_glRasterPos3d(v[0],v[1],v[2]);}
static void APIENTRY npgl_glRasterPos3f(GLfloat x,GLfloat y,GLfloat z){npgl_set_raster_pos(x,y,z,1.0f);} static void APIENTRY npgl_glRasterPos3fv(const GLfloat*v){if(v)npgl_glRasterPos3f(v[0],v[1],v[2]);}
static void APIENTRY npgl_glRasterPos3i(GLint x,GLint y,GLint z){npgl_set_raster_pos((GLfloat)x,(GLfloat)y,(GLfloat)z,1.0f);} static void APIENTRY npgl_glRasterPos3iv(const GLint*v){if(v)npgl_glRasterPos3i(v[0],v[1],v[2]);}
static void APIENTRY npgl_glRasterPos3s(GLshort x,GLshort y,GLshort z){npgl_set_raster_pos((GLfloat)x,(GLfloat)y,(GLfloat)z,1.0f);} static void APIENTRY npgl_glRasterPos3sv(const GLshort*v){if(v)npgl_glRasterPos3s(v[0],v[1],v[2]);}
static void APIENTRY npgl_glRasterPos4d(GLdouble x,GLdouble y,GLdouble z,GLdouble w){npgl_set_raster_pos((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w);} static void APIENTRY npgl_glRasterPos4dv(const GLdouble*v){if(v)npgl_glRasterPos4d(v[0],v[1],v[2],v[3]);}
static void APIENTRY npgl_glRasterPos4f(GLfloat x,GLfloat y,GLfloat z,GLfloat w){npgl_set_raster_pos(x,y,z,w);} static void APIENTRY npgl_glRasterPos4fv(const GLfloat*v){if(v)npgl_glRasterPos4f(v[0],v[1],v[2],v[3]);}
static void APIENTRY npgl_glRasterPos4i(GLint x,GLint y,GLint z,GLint w){npgl_set_raster_pos((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w);} static void APIENTRY npgl_glRasterPos4iv(const GLint*v){if(v)npgl_glRasterPos4i(v[0],v[1],v[2],v[3]);}
static void APIENTRY npgl_glRasterPos4s(GLshort x,GLshort y,GLshort z,GLshort w){npgl_set_raster_pos((GLfloat)x,(GLfloat)y,(GLfloat)z,(GLfloat)w);} static void APIENTRY npgl_glRasterPos4sv(const GLshort*v){if(v)npgl_glRasterPos4s(v[0],v[1],v[2],v[3]);}

static void npgl_set_index(GLfloat value)
{
    NPGL_CONTEXT *c=npgl_current();
    NPGL_LIST_COMMAND cmd;
    if(!c)return;
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_INDEX;cmd.f[0]=value;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    c->currentIndex=value;
}
static void APIENTRY npgl_glIndexd(GLdouble c0){npgl_set_index((GLfloat)c0);} static void APIENTRY npgl_glIndexdv(const GLdouble*c0){if(c0)npgl_glIndexd(c0[0]);}
static void APIENTRY npgl_glIndexf(GLfloat c0){npgl_set_index(c0);} static void APIENTRY npgl_glIndexfv(const GLfloat*c0){if(c0)npgl_glIndexf(c0[0]);}
static void APIENTRY npgl_glIndexi(GLint c0){npgl_set_index((GLfloat)c0);} static void APIENTRY npgl_glIndexiv(const GLint*c0){if(c0)npgl_glIndexi(c0[0]);}
static void APIENTRY npgl_glIndexs(GLshort c0){npgl_set_index((GLfloat)c0);} static void APIENTRY npgl_glIndexsv(const GLshort*c0){if(c0)npgl_glIndexs(c0[0]);}

static void APIENTRY npgl_glClearIndex(GLfloat c0)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_CLEAR_INDEX;cmd.f[0]=c0;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->clearIndex=c0;
}
static void APIENTRY npgl_glIndexMask(GLuint mask)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_INDEX_MASK;cmd.u[0]=mask;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->indexMask=mask;
}
static void APIENTRY npgl_glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    red=npgl_clampf(red,-1.0f,1.0f);green=npgl_clampf(green,-1.0f,1.0f);blue=npgl_clampf(blue,-1.0f,1.0f);alpha=npgl_clampf(alpha,-1.0f,1.0f);
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_CLEAR_ACCUM;cmd.f[0]=red;cmd.f[1]=green;cmd.f[2]=blue;cmd.f[3]=alpha;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    c->clearAccum[0]=red;c->clearAccum[1]=green;c->clearAccum[2]=blue;c->clearAccum[3]=alpha;
}
static void APIENTRY npgl_glAccum(GLenum op, GLfloat value)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(op!=GL_ACCUM&&op!=GL_LOAD&&op!=GL_RETURN&&op!=GL_MULT&&op!=GL_ADD){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_ACCUM;cmd.u[0]=(DWORD)op;cmd.f[0]=value;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    /* 蓄積バッファは持たない。 */
}

static DWORD npgl_pixel_buffer(GLenum mode) { return mode==GL_FRONT ? NPDISP_OGL_PIXEL_FRONT : NPDISP_OGL_PIXEL_BACK; }

static BOOL npgl_read_bgra8(NPGL_CONTEXT *c, GLint x, GLint y, GLsizei width, GLsizei height, BYTE *pixels)
{
    NPDISP_OGL_PIXELS32 p;
    if(!c||!pixels||width<=0||height<=0)return FALSE;
    if(!npgl_ensure_drawable(c))return FALSE;
    memset(&p,0,sizeof(p));p.size=sizeof(p);p.context=c->bridgeContext;p.x=x;p.y=y;p.width=(DWORD)width;p.height=(DWORD)height;p.pixels=(DWORD)pixels;p.buffer=npgl_pixel_buffer(c->readBuffer);
    return npgl_host_call(NPDISP_OGL_CMD_READ_PIXELS,&p)!=0;
}
static DWORD npgl_aligned_stride(DWORD bytes, GLint alignment) { DWORD a=(DWORD)alignment; return (bytes+a-1UL)&~(a-1UL); }
static BOOL npgl_pixel_layout(GLsizei width, GLenum format, GLint rowLength, GLint alignment, DWORD *components, DWORD *rowPixels, DWORD *stride)
{
    DWORD c=(format==GL_RGBA)?4UL:(format==GL_RGB)?3UL:0UL, rp;
    if(!c)return FALSE; rp=rowLength>0?(DWORD)rowLength:(DWORD)width; if(rp<(DWORD)width)return FALSE;
    if(rp>0x1fffffffUL/c)return FALSE; *components=c;*rowPixels=rp;*stride=npgl_aligned_stride(rp*c,alignment);return TRUE;
}
static void APIENTRY npgl_glReadBuffer(GLenum mode)
{
    NPGL_CONTEXT *c=npgl_current(); if(!c)return; if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(mode!=GL_BACK&&mode!=GL_FRONT){npgl_set_error(c,GL_INVALID_ENUM);return;} c->readBuffer=mode;
}
static void APIENTRY npgl_glDrawBuffer(GLenum mode)
{
    NPGL_CONTEXT *c=npgl_current();
    NPGL_LIST_COMMAND cmd;
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(mode!=GL_NONE&&mode!=GL_FRONT&&mode!=GL_BACK&&mode!=GL_FRONT_AND_BACK){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(!c->doubleBuffered&&(mode==GL_BACK||mode==GL_FRONT_AND_BACK)){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_DRAW_BUFFER;cmd.u[0]=(DWORD)mode;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    c->drawBuffer=mode;
}
static void APIENTRY npgl_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
    NPGL_CONTEXT *c=npgl_current();
    NPGL_LIST_COMMAND cmd;
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_COLOR_MASK;cmd.u[0]=red?1UL:0UL;cmd.u[1]=green?1UL:0UL;cmd.u[2]=blue?1UL:0UL;cmd.u[3]=alpha?1UL:0UL;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    c->colorMask[0]=red?GL_TRUE:GL_FALSE;c->colorMask[1]=green?GL_TRUE:GL_FALSE;c->colorMask[2]=blue?GL_TRUE:GL_FALSE;c->colorMask[3]=alpha?GL_TRUE:GL_FALSE;
}
static int npgl_pixel_map_index(GLenum map)
{
    switch(map){case GL_PIXEL_MAP_I_TO_I:return 0;case GL_PIXEL_MAP_S_TO_S:return 1;case GL_PIXEL_MAP_I_TO_R:return 2;case GL_PIXEL_MAP_I_TO_G:return 3;case GL_PIXEL_MAP_I_TO_B:return 4;case GL_PIXEL_MAP_I_TO_A:return 5;case GL_PIXEL_MAP_R_TO_R:return 6;case GL_PIXEL_MAP_G_TO_G:return 7;case GL_PIXEL_MAP_B_TO_B:return 8;case GL_PIXEL_MAP_A_TO_A:return 9;default:return -1;}
}
static GLboolean npgl_pixel_map_is_integer(GLenum map)
{
    return (map==GL_PIXEL_MAP_I_TO_I||map==GL_PIXEL_MAP_S_TO_S)?GL_TRUE:GL_FALSE;
}
static GLboolean npgl_pixel_map_requires_power(GLenum map)
{
    return (map==GL_PIXEL_MAP_I_TO_I||map==GL_PIXEL_MAP_S_TO_S||map==GL_PIXEL_MAP_I_TO_R||map==GL_PIXEL_MAP_I_TO_G||map==GL_PIXEL_MAP_I_TO_B||map==GL_PIXEL_MAP_I_TO_A)?GL_TRUE:GL_FALSE;
}
static NPGL_PIXEL_MAP *npgl_pixel_map(NPGL_CONTEXT *c, GLenum map)
{
    int index=npgl_pixel_map_index(map);if(!c||index<0)return NULL;return &c->pixelMaps[index];
}
static GLfloat npgl_pixel_map_lookup(const NPGL_PIXEL_MAP *map, GLfloat value)
{
    GLint index;if(!map||map->size<=0)return value;value=npgl_clampf(value,0.0f,1.0f);index=(GLint)(value*(GLfloat)map->size);if(index<0)index=0;if(index>=map->size)index=map->size-1;return npgl_clampf(map->values[index],0.0f,1.0f);
}
static void npgl_apply_color_transfer(NPGL_CONTEXT *c, BYTE *pixels, DWORD count)
{
    DWORD i;GLfloat r,g,b,a;if(!c||!pixels)return;
    if(!c->mapColor&&c->redScale==1.0f&&c->greenScale==1.0f&&c->blueScale==1.0f&&c->alphaScale==1.0f&&c->redBias==0.0f&&c->greenBias==0.0f&&c->blueBias==0.0f&&c->alphaBias==0.0f)return;
    for(i=0;i<count;++i){BYTE*p=pixels+i*4UL;r=npgl_clampf(((GLfloat)p[2]/255.0f)*c->redScale+c->redBias,0.0f,1.0f);g=npgl_clampf(((GLfloat)p[1]/255.0f)*c->greenScale+c->greenBias,0.0f,1.0f);b=npgl_clampf(((GLfloat)p[0]/255.0f)*c->blueScale+c->blueBias,0.0f,1.0f);a=npgl_clampf(((GLfloat)p[3]/255.0f)*c->alphaScale+c->alphaBias,0.0f,1.0f);if(c->mapColor){r=npgl_pixel_map_lookup(&c->pixelMaps[6],r);g=npgl_pixel_map_lookup(&c->pixelMaps[7],g);b=npgl_pixel_map_lookup(&c->pixelMaps[8],b);a=npgl_pixel_map_lookup(&c->pixelMaps[9],a);}p[2]=(BYTE)(r*255.0f+0.5f);p[1]=(BYTE)(g*255.0f+0.5f);p[0]=(BYTE)(b*255.0f+0.5f);p[3]=(BYTE)(a*255.0f+0.5f);}
}
static GLboolean npgl_set_pixel_transfer(NPGL_CONTEXT *c, GLenum pname, GLfloat param)
{
    if(!c)return GL_FALSE;switch(pname){case GL_MAP_COLOR:c->mapColor=(param!=0.0f)?GL_TRUE:GL_FALSE;break;case GL_MAP_STENCIL:c->mapStencil=(param!=0.0f)?GL_TRUE:GL_FALSE;break;case GL_INDEX_SHIFT:c->indexShift=(GLint)param;break;case GL_INDEX_OFFSET:c->indexOffset=(GLint)param;break;case GL_RED_SCALE:c->redScale=param;break;case GL_RED_BIAS:c->redBias=param;break;case GL_GREEN_SCALE:c->greenScale=param;break;case GL_GREEN_BIAS:c->greenBias=param;break;case GL_BLUE_SCALE:c->blueScale=param;break;case GL_BLUE_BIAS:c->blueBias=param;break;case GL_ALPHA_SCALE:c->alphaScale=param;break;case GL_ALPHA_BIAS:c->alphaBias=param;break;case GL_DEPTH_SCALE:c->depthScale=param;break;case GL_DEPTH_BIAS:c->depthBias=param;break;default:npgl_set_error(c,GL_INVALID_ENUM);return GL_FALSE;}return GL_TRUE;
}
static void APIENTRY npgl_glPixelTransferf(GLenum pname, GLfloat param)
{
    NPGL_CONTEXT*c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_PIXEL_TRANSFER;cmd.u[0]=pname;cmd.f[0]=param;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}npgl_set_pixel_transfer(c,pname,param);
}
static void APIENTRY npgl_glPixelTransferi(GLenum pname, GLint param){npgl_glPixelTransferf(pname,(GLfloat)param);}
static GLboolean npgl_set_pixel_map_values(NPGL_CONTEXT *c, GLenum map, GLint mapsize, const GLfloat *values)
{
    NPGL_PIXEL_MAP*m;GLint i;if(!c)return GL_FALSE;m=npgl_pixel_map(c,map);if(!m){npgl_set_error(c,GL_INVALID_ENUM);return GL_FALSE;}if(mapsize<=0||mapsize>NPGL_MAX_PIXEL_MAP_TABLE){npgl_set_error(c,GL_INVALID_VALUE);return GL_FALSE;}if(npgl_pixel_map_requires_power(map)&&(mapsize&(mapsize-1))){npgl_set_error(c,GL_INVALID_VALUE);return GL_FALSE;}if(!values){npgl_set_error(c,GL_INVALID_VALUE);return GL_FALSE;}m->size=mapsize;for(i=0;i<mapsize;++i)m->values[i]=npgl_pixel_map_is_integer(map)?values[i]:npgl_clampf(values[i],0.0f,1.0f);return GL_TRUE;
}
static void npgl_glPixelMapfv_impl(GLenum map, GLint mapsize, const GLfloat *values)
{
    NPGL_CONTEXT*c=npgl_current();NPGL_LIST_COMMAND cmd;GLfloat*copy;DWORD bytes;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(npgl_pixel_map_index(map)<0){npgl_set_error(c,GL_INVALID_ENUM);return;}if(mapsize<=0||mapsize>NPGL_MAX_PIXEL_MAP_TABLE){npgl_set_error(c,GL_INVALID_VALUE);return;}if(npgl_pixel_map_requires_power(map)&&(mapsize&(mapsize-1))){npgl_set_error(c,GL_INVALID_VALUE);return;}if(!values){npgl_set_error(c,GL_INVALID_VALUE);return;}if(c->compilingList&&!c->replayingList){bytes=(DWORD)mapsize*sizeof(GLfloat);copy=(GLfloat*)HeapAlloc(GetProcessHeap(),0,bytes);if(!copy){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}memcpy(copy,values,bytes);memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_PIXEL_MAP;cmd.u[0]=map;cmd.u[1]=(DWORD)mapsize;cmd.u[2]=(DWORD)copy;if(!npgl_record_list_command(c,&cmd)){HeapFree(GetProcessHeap(),0,copy);return;}if(c->listMode==GL_COMPILE)return;}npgl_set_pixel_map_values(c,map,mapsize,values);
}
static void APIENTRY npgl_glPixelMapfv(GLenum map, GLint mapsize, const GLfloat *values){npgl_glPixelMapfv_impl(map,mapsize,values);}
static void APIENTRY npgl_glPixelMapuiv(GLenum map, GLint mapsize, const GLuint *values)
{
    NPGL_CONTEXT*c=npgl_current();GLfloat tmp[NPGL_MAX_PIXEL_MAP_TABLE];GLint i;if(!c)return;if(mapsize<=0||mapsize>NPGL_MAX_PIXEL_MAP_TABLE){npgl_set_error(c,GL_INVALID_VALUE);return;}if(!values){npgl_set_error(c,GL_INVALID_VALUE);return;}for(i=0;i<mapsize;++i)tmp[i]=npgl_pixel_map_is_integer(map)?(GLfloat)values[i]:(GLfloat)((double)values[i]/4294967295.0);npgl_glPixelMapfv_impl(map,mapsize,tmp);
}
static void APIENTRY npgl_glPixelMapusv(GLenum map, GLint mapsize, const GLushort *values)
{
    NPGL_CONTEXT*c=npgl_current();GLfloat tmp[NPGL_MAX_PIXEL_MAP_TABLE];GLint i;if(!c)return;if(mapsize<=0||mapsize>NPGL_MAX_PIXEL_MAP_TABLE){npgl_set_error(c,GL_INVALID_VALUE);return;}if(!values){npgl_set_error(c,GL_INVALID_VALUE);return;}for(i=0;i<mapsize;++i)tmp[i]=npgl_pixel_map_is_integer(map)?(GLfloat)values[i]:(GLfloat)values[i]/65535.0f;npgl_glPixelMapfv_impl(map,mapsize,tmp);
}
static void APIENTRY npgl_glGetPixelMapfv(GLenum map, GLfloat *values)
{
    NPGL_CONTEXT*c=npgl_current();NPGL_PIXEL_MAP*m;GLint i;if(!c||!values)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}m=npgl_pixel_map(c,map);if(!m){npgl_set_error(c,GL_INVALID_ENUM);return;}for(i=0;i<m->size;++i)values[i]=m->values[i];
}
static void APIENTRY npgl_glGetPixelMapuiv(GLenum map, GLuint *values)
{
    NPGL_CONTEXT*c=npgl_current();NPGL_PIXEL_MAP*m;GLint i;if(!c||!values)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}m=npgl_pixel_map(c,map);if(!m){npgl_set_error(c,GL_INVALID_ENUM);return;}for(i=0;i<m->size;++i)values[i]=npgl_pixel_map_is_integer(map)?(GLuint)m->values[i]:(GLuint)(npgl_clampf(m->values[i],0.0f,1.0f)*4294967295.0);
}
static void APIENTRY npgl_glGetPixelMapusv(GLenum map, GLushort *values)
{
    NPGL_CONTEXT*c=npgl_current();NPGL_PIXEL_MAP*m;GLint i;if(!c||!values)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}m=npgl_pixel_map(c,map);if(!m){npgl_set_error(c,GL_INVALID_ENUM);return;}for(i=0;i<m->size;++i)values[i]=npgl_pixel_map_is_integer(map)?(GLushort)m->values[i]:(GLushort)(npgl_clampf(m->values[i],0.0f,1.0f)*65535.0f+0.5f);
}
static BOOL npgl_submit_bitmap_mask(NPGL_CONTEXT *c, GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, const GLubyte *mask)
{
    NPDISP_OGL_VERTEX32 *vertices;NPDISP_OGL_DRAW32 draw;DWORD capacity=4096UL,count=0;GLint x,y;GLfloat baseX,baseY,q;BOOL ok=TRUE;if(!c||!c->rasterValid||width<=0||height<=0||!mask)return TRUE;if(!npgl_ensure_drawable(c))return FALSE;{NPGL_TEXTURE_OBJECT*tex=npgl_active_texture(c);if(tex&&!npgl_upload_texture(c,tex))return FALSE;}vertices=(NPDISP_OGL_VERTEX32*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,capacity*sizeof(*vertices));if(!vertices)return FALSE;npgl_fill_draw_state(c,&draw);draw.primitive=GL_POINTS;draw.pointSize=1.0f;draw.cullMode=NPDISP_OGL_CULL_NONE;draw.clipPlaneMask=0;baseX=(GLfloat)floor((double)(c->rasterPosition[0]-xorig));baseY=(GLfloat)floor((double)(c->rasterPosition[1]-yorig));q=c->rasterTexCoord[3];if(q==0.0f)q=1.0f;for(y=0;y<height&&ok;++y)for(x=0;x<width;++x)if(mask[(DWORD)y*(DWORD)width+(DWORD)x]){NPDISP_OGL_VERTEX32*v=&vertices[count++];v->x=baseX+(GLfloat)x;v->y=(GLfloat)c->drawHeight-1.0f-(baseY+(GLfloat)y);v->z=c->rasterPosition[2];v->rhw=1.0f;v->diffuse=npgl_pack_color(c->rasterColor);v->tu=c->rasterTexCoord[0]/q;v->tv=c->rasterTexCoord[1]/q;v->clip[3]=1.0f;v->texcoord[0]=c->rasterTexCoord[0];v->texcoord[1]=c->rasterTexCoord[1];v->texcoord[2]=c->rasterTexCoord[2];v->texcoord[3]=c->rasterTexCoord[3];if(count==capacity){draw.vertexCount=count;draw.vertices=(DWORD)vertices;ok=npgl_host_call(NPDISP_OGL_CMD_DRAW,&draw)?TRUE:FALSE;count=0;}}if(ok&&count){draw.vertexCount=count;draw.vertices=(DWORD)vertices;ok=npgl_host_call(NPDISP_OGL_CMD_DRAW,&draw)?TRUE:FALSE;}HeapFree(GetProcessHeap(),0,vertices);return ok;
}
static GLubyte *npgl_unpack_bitmap(NPGL_CONTEXT *c, GLsizei width, GLsizei height, const GLubyte *bitmap)
{
    GLubyte*out;DWORD rowBits,rowBytes,stride;GLint x,y;DWORD bitIndex;const GLubyte*row;GLubyte bit;if(!c||width<0||height<0)return NULL;if(!width||!height)return (GLubyte*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,1);if(!bitmap)return NULL;if((DWORD)width>0x7fffffffUL/(DWORD)height)return NULL;out=(GLubyte*)HeapAlloc(GetProcessHeap(),0,(DWORD)width*(DWORD)height);if(!out)return NULL;rowBits=(DWORD)(c->unpackRowLength>0?c->unpackRowLength:width);rowBytes=(rowBits+7UL)/8UL;stride=(rowBytes+(DWORD)c->unpackAlignment-1UL)&~((DWORD)c->unpackAlignment-1UL);for(y=0;y<height;++y){row=bitmap+(DWORD)(c->unpackSkipRows+y)*stride;for(x=0;x<width;++x){bitIndex=(DWORD)c->unpackSkipPixels+(DWORD)x;bit=c->unpackLsbFirst?(GLubyte)(1U<<(bitIndex&7U)):(GLubyte)(0x80U>>(bitIndex&7U));out[(DWORD)y*(DWORD)width+(DWORD)x]=(row[bitIndex>>3]&bit)?1U:0U;}}return out;
}
static void npgl_execute_bitmap_mask(NPGL_CONTEXT *c, GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *mask)
{
    if(!c||!c->rasterValid)return;
    if(c->renderMode==GL_FEEDBACK){npgl_feedback_write(c,(GLfloat)GL_BITMAP_TOKEN);npgl_feedback_write_raster_vertex(c);}
    else if(c->renderMode==GL_RENDER&&mask&&!npgl_submit_bitmap_mask(c,width,height,xorig,yorig,mask))npgl_set_error(c,GL_OUT_OF_MEMORY);
    c->rasterPosition[0]+=xmove;c->rasterPosition[1]+=ymove;
}
static void APIENTRY npgl_glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap)
{
    NPGL_CONTEXT*c=npgl_current();NPGL_LIST_COMMAND cmd;GLubyte*mask=NULL;GLboolean listOwned=GL_FALSE;
    if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(width<0||height<0){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(width&&height&&(c->rasterValid||(c->compilingList&&!c->replayingList))){mask=npgl_unpack_bitmap(c,width,height,bitmap);if(!mask){npgl_set_error(c,bitmap?GL_OUT_OF_MEMORY:GL_INVALID_VALUE);return;}}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_BITMAP;cmd.u[0]=(DWORD)width;cmd.u[1]=(DWORD)height;cmd.u[2]=(DWORD)mask;cmd.f[0]=xorig;cmd.f[1]=yorig;cmd.f[2]=xmove;cmd.f[3]=ymove;if(!npgl_record_list_command(c,&cmd)){if(mask)HeapFree(GetProcessHeap(),0,mask);return;}listOwned=GL_TRUE;if(c->listMode==GL_COMPILE)return;}
    npgl_execute_bitmap_mask(c,width,height,xorig,yorig,xmove,ymove,mask);
    if(mask&&!listOwned)HeapFree(GetProcessHeap(),0,mask);
}

static void APIENTRY npgl_glPixelZoom(GLfloat xfactor, GLfloat yfactor)
{
    NPGL_CONTEXT *c=npgl_current(); if(!c)return; if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;} c->pixelZoomX=xfactor;c->pixelZoomY=yfactor;
}
static void APIENTRY npgl_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels)
{
    NPGL_CONTEXT *c=npgl_current(); NPDISP_OGL_PIXELS32 p; BYTE *tmp,*dst; DWORD comps,rowPixels,stride,total; GLint row,col;
    if(!c)return; if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;} if(width<0||height<0){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(type!=GL_UNSIGNED_BYTE||(format!=GL_RGB&&format!=GL_RGBA)){npgl_set_error(c,GL_INVALID_ENUM);return;} if(!width||!height)return; if(!pixels){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(!npgl_pixel_layout(width,format,c->packRowLength,c->packAlignment,&comps,&rowPixels,&stride)){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if((DWORD)width>0x1fffffffUL/4UL||(DWORD)height>0x1fffffffUL/((DWORD)width*4UL)){npgl_set_error(c,GL_OUT_OF_MEMORY);return;} total=(DWORD)width*(DWORD)height*4UL;
    tmp=(BYTE*)HeapAlloc(GetProcessHeap(),0,total); if(!tmp){npgl_set_error(c,GL_OUT_OF_MEMORY);return;} npgl_ensure_drawable(c); memset(&p,0,sizeof(p));p.size=sizeof(p);p.context=c->bridgeContext;p.x=x;p.y=y;p.width=(DWORD)width;p.height=(DWORD)height;p.pixels=(DWORD)tmp;p.buffer=npgl_pixel_buffer(c->readBuffer);
    if(!npgl_host_call(NPDISP_OGL_CMD_READ_PIXELS,&p)){HeapFree(GetProcessHeap(),0,tmp);npgl_set_error(c,GL_OUT_OF_MEMORY);return;}
    npgl_apply_color_transfer(c,tmp,(DWORD)width*(DWORD)height);
    dst=(BYTE*)pixels+(DWORD)c->packSkipRows*stride+(DWORD)c->packSkipPixels*comps;
    for(row=0;row<height;++row){BYTE*d=dst+(DWORD)row*stride;BYTE*t=tmp+(DWORD)row*(DWORD)width*4UL;for(col=0;col<width;++col){d[col*comps+0]=t[col*4+2];d[col*comps+1]=t[col*4+1];d[col*comps+2]=t[col*4+0];if(comps==4)d[col*4+3]=t[col*4+3];}}
    HeapFree(GetProcessHeap(),0,tmp);
}
static void APIENTRY npgl_glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
    NPGL_CONTEXT *c=npgl_current();NPDISP_OGL_PIXELS32 p;BYTE*tmp;const BYTE*src;DWORD comps,rowPixels,stride,total;GLint row,col;
    if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(width<0||height<0){npgl_set_error(c,GL_INVALID_VALUE);return;}if(type!=GL_UNSIGNED_BYTE||(format!=GL_RGB&&format!=GL_RGBA)){npgl_set_error(c,GL_INVALID_ENUM);return;}if(!width||!height||!c->rasterValid)return;if(!pixels){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(c->renderMode==GL_FEEDBACK){npgl_feedback_write(c,(GLfloat)GL_DRAW_PIXEL_TOKEN);npgl_feedback_write_raster_vertex(c);return;}if(c->renderMode==GL_SELECT)return;
    if(!npgl_pixel_layout(width,format,c->unpackRowLength,c->unpackAlignment,&comps,&rowPixels,&stride)){npgl_set_error(c,GL_INVALID_VALUE);return;}if((DWORD)width>0x1fffffffUL/4UL||(DWORD)height>0x1fffffffUL/((DWORD)width*4UL)){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}total=(DWORD)width*(DWORD)height*4UL;tmp=(BYTE*)HeapAlloc(GetProcessHeap(),0,total);if(!tmp){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}
    src=(const BYTE*)pixels+(DWORD)c->unpackSkipRows*stride+(DWORD)c->unpackSkipPixels*comps;for(row=0;row<height;++row){const BYTE*sp=src+(DWORD)row*stride;BYTE*d=tmp+(DWORD)row*(DWORD)width*4UL;for(col=0;col<width;++col){d[col*4+0]=sp[col*comps+2];d[col*4+1]=sp[col*comps+1];d[col*4+2]=sp[col*comps+0];d[col*4+3]=(comps==4)?sp[col*4+3]:255U;}}
    npgl_apply_color_transfer(c,tmp,(DWORD)width*(DWORD)height);
    npgl_ensure_drawable(c);memset(&p,0,sizeof(p));p.size=sizeof(p);p.context=c->bridgeContext;p.x=(LONG)c->rasterPosition[0];p.y=(LONG)c->rasterPosition[1];p.width=(DWORD)width;p.height=(DWORD)height;p.pixels=(DWORD)tmp;p.scissorEnable=c->scissorTest?1UL:0UL;p.scissorX=c->scissorBox[0];p.scissorY=c->scissorBox[1];p.scissorWidth=(DWORD)c->scissorBox[2];p.scissorHeight=(DWORD)c->scissorBox[3];p.zoomX=c->pixelZoomX;p.zoomY=c->pixelZoomY;p.colorWriteDisableMask=(!c->colorMask[0]?1UL:0UL)|(!c->colorMask[1]?2UL:0UL)|(!c->colorMask[2]?4UL:0UL)|(!c->colorMask[3]?8UL:0UL);if(c->drawBuffer==GL_NONE)p.colorWriteDisableMask|=7UL;p.logicOpEnable=c->colorLogicOp?1UL:0UL;p.logicOp=(DWORD)c->logicOpMode;
    if(!npgl_host_call(NPDISP_OGL_CMD_DRAW_PIXELS,&p))npgl_set_error(c,GL_OUT_OF_MEMORY);HeapFree(GetProcessHeap(),0,tmp);
}
static void APIENTRY npgl_glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type)
{
    NPGL_CONTEXT *c=npgl_current();NPDISP_OGL_PIXELS32 p;BYTE*tmp;DWORD total;
    if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(width<0||height<0){npgl_set_error(c,GL_INVALID_VALUE);return;}if(type!=GL_COLOR){npgl_set_error(c,GL_INVALID_ENUM);return;}if(!width||!height||!c->rasterValid)return;
    if(c->renderMode==GL_FEEDBACK){npgl_feedback_write(c,(GLfloat)GL_COPY_PIXEL_TOKEN);npgl_feedback_write_raster_vertex(c);return;}if(c->renderMode==GL_SELECT)return;
    if((DWORD)width>0x1fffffffUL/4UL||(DWORD)height>0x1fffffffUL/((DWORD)width*4UL)){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}total=(DWORD)width*(DWORD)height*4UL;tmp=(BYTE*)HeapAlloc(GetProcessHeap(),0,total);if(!tmp){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}
    if(!npgl_read_bgra8(c,x,y,width,height,tmp)){HeapFree(GetProcessHeap(),0,tmp);npgl_set_error(c,GL_OUT_OF_MEMORY);return;}
    npgl_apply_color_transfer(c,tmp,(DWORD)width*(DWORD)height);
    npgl_ensure_drawable(c);memset(&p,0,sizeof(p));p.size=sizeof(p);p.context=c->bridgeContext;p.x=(LONG)c->rasterPosition[0];p.y=(LONG)c->rasterPosition[1];p.width=(DWORD)width;p.height=(DWORD)height;p.pixels=(DWORD)tmp;p.scissorEnable=c->scissorTest?1UL:0UL;p.scissorX=c->scissorBox[0];p.scissorY=c->scissorBox[1];p.scissorWidth=(DWORD)c->scissorBox[2];p.scissorHeight=(DWORD)c->scissorBox[3];p.zoomX=c->pixelZoomX;p.zoomY=c->pixelZoomY;p.colorWriteDisableMask=(!c->colorMask[0]?1UL:0UL)|(!c->colorMask[1]?2UL:0UL)|(!c->colorMask[2]?4UL:0UL)|(!c->colorMask[3]?8UL:0UL);if(c->drawBuffer==GL_NONE)p.colorWriteDisableMask|=7UL;p.logicOpEnable=c->colorLogicOp?1UL:0UL;p.logicOp=(DWORD)c->logicOpMode;
    if(!npgl_host_call(NPDISP_OGL_CMD_DRAW_PIXELS,&p))npgl_set_error(c,GL_OUT_OF_MEMORY);HeapFree(GetProcessHeap(),0,tmp);
}

static void APIENTRY npgl_glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_TEXTURE_OBJECT *obj;
    BYTE *converted;
    const BYTE *src;
    BYTE *dst;
    DWORD srcComponents;
    DWORD srcRow;
    DWORD srcStride;
    DWORD total;
    GLint y;
    GLint x;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (target != GL_TEXTURE_2D) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    if (level != 0 || border != 0 || width <= 0 || height <= 0 || width > 2048 || height > 2048) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if (type != GL_UNSIGNED_BYTE || (format != GL_RGB && format != GL_RGBA && format != GL_BGRA_EXT)) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    if (internalFormat != 3 && internalFormat != 4 && internalFormat != GL_RGB && internalFormat != GL_RGBA) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if ((DWORD)width > 0x1fffffffUL / 4UL || (DWORD)height > 0x1fffffffUL / ((DWORD)width * 4UL)) { npgl_set_error(c, GL_OUT_OF_MEMORY); return; }
    obj = c->boundTexture2D;
    if (!obj) return;
    total = (DWORD)width * (DWORD)height * 4UL;
    converted = (BYTE *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, total);
    if (!converted) { npgl_set_error(c, GL_OUT_OF_MEMORY); return; }
    srcComponents = (format == GL_RGB) ? 3UL : 4UL;
    srcRow = (DWORD)width * srcComponents;
    srcStride = (srcRow + (DWORD)c->unpackAlignment - 1UL) & ~((DWORD)c->unpackAlignment - 1UL);
    if (pixels) {
        src = (const BYTE *)pixels + (DWORD)c->unpackSkipRows * srcStride + (DWORD)c->unpackSkipPixels * srcComponents;
        for (y = 0; y < height; ++y) {
            dst = converted + (DWORD)y * (DWORD)width * 4UL;
            for (x = 0; x < width; ++x) {
                const BYTE *sp = src + (DWORD)y * srcStride + (DWORD)x * srcComponents;
                if (format == GL_BGRA_EXT) {
                    dst[(DWORD)x * 4UL + 0UL] = sp[0];
                    dst[(DWORD)x * 4UL + 1UL] = sp[1];
                    dst[(DWORD)x * 4UL + 2UL] = sp[2];
                    dst[(DWORD)x * 4UL + 3UL] = sp[3];
                } else {
                    dst[(DWORD)x * 4UL + 0UL] = sp[2];
                    dst[(DWORD)x * 4UL + 1UL] = sp[1];
                    dst[(DWORD)x * 4UL + 2UL] = sp[0];
                    dst[(DWORD)x * 4UL + 3UL] = (srcComponents == 4UL) ? sp[3] : 255U;
                }
            }
        }
    }
    if (pixels) npgl_apply_color_transfer(c,converted,(DWORD)width*(DWORD)height);
    if (obj->pixels) HeapFree(GetProcessHeap(), 0, obj->pixels);
    obj->pixels = converted;
    obj->pixelBytes = total;
    obj->defined = GL_TRUE;
    obj->hasAlpha = (format == GL_RGBA || format == GL_BGRA_EXT || internalFormat == 4 || internalFormat == GL_RGBA) ? GL_TRUE : GL_FALSE;
    obj->width = width;
    obj->height = height;
    obj->internalFormat = internalFormat;
    ++obj->revision;
    if (!npgl_upload_texture(c, obj)) { npgl_set_error(c, GL_OUT_OF_MEMORY); return; }
}

static GLboolean npgl_texture_format_valid(GLint internalFormat)
{
    return (internalFormat==3||internalFormat==4||internalFormat==GL_RGB||internalFormat==GL_RGBA)?GL_TRUE:GL_FALSE;
}

static void APIENTRY npgl_glTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels)
{
    NPGL_CONTEXT *c=npgl_current();
    NPGL_TEXTURE_OBJECT *obj;
    BYTE *converted;
    const BYTE *src;
    DWORD comp,total;
    GLint x;
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(target!=GL_TEXTURE_1D){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(level!=0||border!=0||width<=0||width>2048){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(type!=GL_UNSIGNED_BYTE||(format!=GL_RGB&&format!=GL_RGBA)){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(!npgl_texture_format_valid(internalFormat)){npgl_set_error(c,GL_INVALID_VALUE);return;}
    obj=c->boundTexture1D;if(!obj)return;
    if((DWORD)width>0x1fffffffUL/4UL){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}
    total=(DWORD)width*4UL;converted=(BYTE*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,total);if(!converted){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}
    comp=(format==GL_RGBA)?4UL:3UL;
    if(pixels){src=(const BYTE*)pixels+(DWORD)c->unpackSkipPixels*comp;for(x=0;x<width;++x){const BYTE*sp=src+(DWORD)x*comp;BYTE*dp=converted+(DWORD)x*4UL;dp[0]=sp[2];dp[1]=sp[1];dp[2]=sp[0];dp[3]=(comp==4UL)?sp[3]:255U;}}
    if(pixels)npgl_apply_color_transfer(c,converted,(DWORD)width);
    if(obj->pixels)HeapFree(GetProcessHeap(),0,obj->pixels);obj->pixels=converted;obj->pixelBytes=total;obj->defined=GL_TRUE;obj->hasAlpha=(format==GL_RGBA||internalFormat==4||internalFormat==GL_RGBA)?GL_TRUE:GL_FALSE;obj->width=width;obj->height=1;obj->internalFormat=internalFormat;obj->target=GL_TEXTURE_1D;++obj->revision;
    if(c->texture1D&&!c->texture2D&&!npgl_upload_texture(c,obj))npgl_set_error(c,GL_OUT_OF_MEMORY);
}

static void APIENTRY npgl_glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels)
{
    NPGL_CONTEXT *c=npgl_current();
    NPGL_TEXTURE_OBJECT *obj;
    const BYTE *src;
    DWORD comp;
    GLint x;
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(target!=GL_TEXTURE_1D){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(level!=0||xoffset<0||width<0){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(type!=GL_UNSIGNED_BYTE||(format!=GL_RGB&&format!=GL_RGBA)){npgl_set_error(c,GL_INVALID_ENUM);return;}
    obj=c->boundTexture1D;if(!obj||!obj->defined||!obj->pixels){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(xoffset+width>obj->width){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(!pixels||width==0)return;
    comp=(format==GL_RGBA)?4UL:3UL;src=(const BYTE*)pixels+(DWORD)c->unpackSkipPixels*comp;
    for(x=0;x<width;++x){const BYTE*sp=src+(DWORD)x*comp;BYTE px[4];BYTE*dp=obj->pixels+(DWORD)(xoffset+x)*4UL;px[0]=sp[2];px[1]=sp[1];px[2]=sp[0];px[3]=(comp==4UL)?sp[3]:255U;npgl_apply_color_transfer(c,px,1);memcpy(dp,px,4);}
    if(format==GL_RGBA)obj->hasAlpha=GL_TRUE;++obj->revision;if(c->texture1D&&!c->texture2D&&!npgl_upload_texture(c,obj))npgl_set_error(c,GL_OUT_OF_MEMORY);
}

static void APIENTRY npgl_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels)
{
    NPGL_CONTEXT *c=npgl_current();
    NPGL_TEXTURE_OBJECT *obj;
    BYTE *dst;
    DWORD comps,rowPixels,stride;
    GLint x,y;
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(target!=GL_TEXTURE_1D&&target!=GL_TEXTURE_2D){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(level!=0){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(type!=GL_UNSIGNED_BYTE||(format!=GL_RGB&&format!=GL_RGBA)){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(!pixels){npgl_set_error(c,GL_INVALID_VALUE);return;}
    obj=npgl_bound_texture(c,target);if(!obj||!obj->defined||!obj->pixels)return;
    if(!npgl_pixel_layout(obj->width,format,c->packRowLength,c->packAlignment,&comps,&rowPixels,&stride)){npgl_set_error(c,GL_INVALID_VALUE);return;}
    dst=(BYTE*)pixels+(DWORD)c->packSkipRows*stride+(DWORD)c->packSkipPixels*comps;
    for(y=0;y<obj->height;++y){BYTE*d=dst+(DWORD)y*stride;const BYTE*sp=obj->pixels+(DWORD)y*(DWORD)obj->width*4UL;for(x=0;x<obj->width;++x){d[(DWORD)x*comps+0]=sp[(DWORD)x*4UL+2];d[(DWORD)x*comps+1]=sp[(DWORD)x*4UL+1];d[(DWORD)x*comps+2]=sp[(DWORD)x*4UL+0];if(comps==4UL)d[(DWORD)x*4UL+3]=sp[(DWORD)x*4UL+3];}}
}

static BOOL npgl_copy_tex_image(NPGL_CONTEXT *c, NPGL_TEXTURE_OBJECT *obj, GLenum target, GLint internalFormat, GLint x, GLint y, GLsizei width, GLsizei height)
{
    BYTE *pixels;
    DWORD total;
    if(!c||!obj||width<=0||height<=0)return FALSE;
    if((DWORD)width>0x1fffffffUL/4UL||(DWORD)height>0x1fffffffUL/((DWORD)width*4UL))return FALSE;
    total=(DWORD)width*(DWORD)height*4UL;pixels=(BYTE*)HeapAlloc(GetProcessHeap(),0,total);if(!pixels)return FALSE;
    if(!npgl_read_bgra8(c,x,y,width,height,pixels)){HeapFree(GetProcessHeap(),0,pixels);return FALSE;}
    npgl_apply_color_transfer(c,pixels,(DWORD)width*(DWORD)height);
    if(obj->pixels)HeapFree(GetProcessHeap(),0,obj->pixels);obj->pixels=pixels;obj->pixelBytes=total;obj->defined=GL_TRUE;obj->hasAlpha=(internalFormat==4||internalFormat==GL_RGBA)?GL_TRUE:GL_FALSE;obj->width=width;obj->height=height;obj->internalFormat=internalFormat;obj->target=target;++obj->revision;
    return TRUE;
}

static void APIENTRY npgl_glCopyTexImage1D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_TEXTURE_OBJECT *obj;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(target!=GL_TEXTURE_1D){npgl_set_error(c,GL_INVALID_ENUM);return;}if(level!=0||border!=0||width<=0||width>2048){npgl_set_error(c,GL_INVALID_VALUE);return;}if(!npgl_texture_format_valid((GLint)internalFormat)){npgl_set_error(c,GL_INVALID_VALUE);return;}obj=c->boundTexture1D;if(!obj)return;if(!npgl_copy_tex_image(c,obj,target,(GLint)internalFormat,x,y,width,1)){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}if(c->texture1D&&!c->texture2D&&!npgl_upload_texture(c,obj))npgl_set_error(c,GL_OUT_OF_MEMORY);
}
static void APIENTRY npgl_glCopyTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_TEXTURE_OBJECT *obj;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(target!=GL_TEXTURE_2D){npgl_set_error(c,GL_INVALID_ENUM);return;}if(level!=0||border!=0||width<=0||height<=0||width>2048||height>2048){npgl_set_error(c,GL_INVALID_VALUE);return;}if(!npgl_texture_format_valid((GLint)internalFormat)){npgl_set_error(c,GL_INVALID_VALUE);return;}obj=c->boundTexture2D;if(!obj)return;if(!npgl_copy_tex_image(c,obj,target,(GLint)internalFormat,x,y,width,height)){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}if(c->texture2D&&!npgl_upload_texture(c,obj))npgl_set_error(c,GL_OUT_OF_MEMORY);
}
static void APIENTRY npgl_glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_TEXTURE_OBJECT *obj;BYTE*tmp;DWORD total;GLint i;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(target!=GL_TEXTURE_1D){npgl_set_error(c,GL_INVALID_ENUM);return;}if(level!=0||xoffset<0||width<0){npgl_set_error(c,GL_INVALID_VALUE);return;}obj=c->boundTexture1D;if(!obj||!obj->defined||!obj->pixels){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(xoffset+width>obj->width){npgl_set_error(c,GL_INVALID_VALUE);return;}if(!width)return;total=(DWORD)width*4UL;tmp=(BYTE*)HeapAlloc(GetProcessHeap(),0,total);if(!tmp){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}if(!npgl_read_bgra8(c,x,y,width,1,tmp)){HeapFree(GetProcessHeap(),0,tmp);npgl_set_error(c,GL_OUT_OF_MEMORY);return;}npgl_apply_color_transfer(c,tmp,(DWORD)width);for(i=0;i<width;++i)memcpy(obj->pixels+(DWORD)(xoffset+i)*4UL,tmp+(DWORD)i*4UL,4);HeapFree(GetProcessHeap(),0,tmp);++obj->revision;if(c->texture1D&&!c->texture2D&&!npgl_upload_texture(c,obj))npgl_set_error(c,GL_OUT_OF_MEMORY);
}
static void APIENTRY npgl_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_TEXTURE_OBJECT *obj;BYTE*tmp;DWORD total;GLint row;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(target!=GL_TEXTURE_2D){npgl_set_error(c,GL_INVALID_ENUM);return;}if(level!=0||xoffset<0||yoffset<0||width<0||height<0){npgl_set_error(c,GL_INVALID_VALUE);return;}obj=c->boundTexture2D;if(!obj||!obj->defined||!obj->pixels){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(xoffset+width>obj->width||yoffset+height>obj->height){npgl_set_error(c,GL_INVALID_VALUE);return;}if(!width||!height)return;if((DWORD)width>0x1fffffffUL/4UL||(DWORD)height>0x1fffffffUL/((DWORD)width*4UL)){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}total=(DWORD)width*(DWORD)height*4UL;tmp=(BYTE*)HeapAlloc(GetProcessHeap(),0,total);if(!tmp){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}if(!npgl_read_bgra8(c,x,y,width,height,tmp)){HeapFree(GetProcessHeap(),0,tmp);npgl_set_error(c,GL_OUT_OF_MEMORY);return;}npgl_apply_color_transfer(c,tmp,(DWORD)width*(DWORD)height);for(row=0;row<height;++row)memcpy(obj->pixels+((DWORD)(yoffset+row)*(DWORD)obj->width+(DWORD)xoffset)*4UL,tmp+(DWORD)row*(DWORD)width*4UL,(DWORD)width*4UL);HeapFree(GetProcessHeap(),0,tmp);++obj->revision;if(c->texture2D&&!npgl_upload_texture(c,obj))npgl_set_error(c,GL_OUT_OF_MEMORY);
}

static void APIENTRY npgl_glGetTexParameteriv(GLenum target, GLenum pname, GLint *params)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_TEXTURE_OBJECT *obj;
    if (!c || !params) return;
    if (target != GL_TEXTURE_1D && target != GL_TEXTURE_2D) { npgl_set_error(c, GL_INVALID_ENUM); *params = 0; return; }
    obj = npgl_bound_texture(c, target);
    if (!obj) { *params = 0; return; }
    switch (pname) {
    case GL_TEXTURE_WRAP_S: *params = (GLint)obj->wrapS; break;
    case GL_TEXTURE_WRAP_T: *params = (GLint)obj->wrapT; break;
    case GL_TEXTURE_MIN_FILTER: *params = (GLint)obj->minFilter; break;
    case GL_TEXTURE_MAG_FILTER: *params = (GLint)obj->magFilter; break;
    default: npgl_set_error(c, GL_INVALID_ENUM); *params = 0; break;
    }
}

static void APIENTRY npgl_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params)
{
    GLint value;
    if (!params) return;
    npgl_glGetTexParameteriv(target, pname, &value);
    *params = (GLfloat)value;
}

static void APIENTRY npgl_glGetTexEnviv(GLenum target, GLenum pname, GLint *params)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c || !params) return;
    if (target != GL_TEXTURE_ENV || pname != GL_TEXTURE_ENV_MODE) { npgl_set_error(c, GL_INVALID_ENUM); *params = 0; return; }
    *params = (GLint)c->textureEnvMode;
}

static void APIENTRY npgl_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params)
{
    GLint value;
    if (!params) return;
    npgl_glGetTexEnviv(target, pname, &value);
    *params = (GLfloat)value;
}

static void APIENTRY npgl_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c || !params) return;
    if (target != GL_TEXTURE_1D && target != GL_TEXTURE_2D) { npgl_set_error(c, GL_INVALID_ENUM); *params = 0; return; }
    if (level != 0) { npgl_set_error(c, GL_INVALID_VALUE); *params = 0; return; }
    {
        NPGL_TEXTURE_OBJECT *obj = npgl_bound_texture(c, target);
        switch (pname) {
    case GL_TEXTURE_WIDTH: *params = (obj && obj->defined) ? obj->width : 0; break;
    case GL_TEXTURE_HEIGHT: *params = (obj && obj->defined) ? obj->height : 0; break;
    case GL_TEXTURE_INTERNAL_FORMAT: *params = (obj && obj->defined) ? obj->internalFormat : 0; break;
    default: npgl_set_error(c, GL_INVALID_ENUM); *params = 0; break;
        }
    }
}

static void APIENTRY npgl_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params)
{
    GLint value;
    if (!params) return;
    npgl_glGetTexLevelParameteriv(target, level, pname, &value);
    *params = (GLfloat)value;
}

static DWORD npgl_type_size(GLenum type)
{
    switch (type) {
    case GL_BYTE:
    case GL_UNSIGNED_BYTE: return 1;
    case GL_SHORT:
    case GL_UNSIGNED_SHORT: return 2;
    case GL_INT:
    case GL_UNSIGNED_INT:
    case GL_FLOAT: return 4;
    case GL_DOUBLE: return 8;
    default: return 0;
    }
}

static GLfloat npgl_read_component(const BYTE *p, GLenum type, GLboolean normalized)
{
    switch (type) {
    case GL_BYTE: return normalized ? ((*(const GLbyte *)p < 0) ? (GLfloat)*(const GLbyte *)p / 128.0f : (GLfloat)*(const GLbyte *)p / 127.0f) : (GLfloat)*(const GLbyte *)p;
    case GL_UNSIGNED_BYTE: return normalized ? (GLfloat)*(const GLubyte *)p / 255.0f : (GLfloat)*(const GLubyte *)p;
    case GL_SHORT: return normalized ? ((*(const GLshort *)p < 0) ? (GLfloat)*(const GLshort *)p / 32768.0f : (GLfloat)*(const GLshort *)p / 32767.0f) : (GLfloat)*(const GLshort *)p;
    case GL_UNSIGNED_SHORT: return normalized ? (GLfloat)*(const GLushort *)p / 65535.0f : (GLfloat)*(const GLushort *)p;
    case GL_INT: return normalized ? (GLfloat)((double)*(const GLint *)p / 2147483647.0) : (GLfloat)*(const GLint *)p;
    case GL_UNSIGNED_INT: return normalized ? (GLfloat)((double)*(const GLuint *)p / 4294967295.0) : (GLfloat)*(const GLuint *)p;
    case GL_FLOAT: return *(const GLfloat *)p;
    case GL_DOUBLE: return (GLfloat)*(const GLdouble *)p;
    default: return 0.0f;
    }
}

static const BYTE *npgl_array_element_ptr(const NPGL_ARRAY_STATE *a, GLint index)
{
    DWORD ts;
    DWORD stride;
    if (!a || !a->pointer || index < 0) return NULL;
    ts = npgl_type_size(a->type);
    if (!ts) return NULL;
    stride = a->stride ? (DWORD)a->stride : (DWORD)a->size * ts;
    return (const BYTE *)a->pointer + (DWORD)index * stride;
}

static void APIENTRY npgl_glEdgeFlag(GLboolean flag);

static BOOL npgl_apply_array_element(NPGL_CONTEXT *c, GLint index, GLboolean emitVertex)
{
    const BYTE *p;
    DWORD ts;
    int i;
    GLfloat v[4];
    if (!c || index < 0) return FALSE;
    if (c->edgeFlagArray.enabled) {
        p = npgl_array_element_ptr(&c->edgeFlagArray, index);
        if (!p) return FALSE;
        npgl_glEdgeFlag(*(const GLboolean *)p ? GL_TRUE : GL_FALSE);
    }
    if (c->indexArray.enabled) {
        p = npgl_array_element_ptr(&c->indexArray, index);
        if (!p) return FALSE;
        npgl_glIndexf(npgl_read_component(p, c->indexArray.type, GL_FALSE));
    }
    if (c->colorArray.enabled) {
        p = npgl_array_element_ptr(&c->colorArray, index);
        ts = npgl_type_size(c->colorArray.type);
        if (!p || !ts) return FALSE;
        v[0] = v[1] = v[2] = 1.0f; v[3] = 1.0f;
        for (i = 0; i < c->colorArray.size; ++i) v[i] = npgl_read_component(p + i * ts, c->colorArray.type, GL_TRUE);
        npgl_glColor4f(v[0], v[1], v[2], v[3]);
    }
    if (c->normalArray.enabled) {
        p = npgl_array_element_ptr(&c->normalArray, index);
        ts = npgl_type_size(c->normalArray.type);
        if (!p || !ts) return FALSE;
        npgl_glNormal3f(npgl_read_component(p, c->normalArray.type, GL_TRUE), npgl_read_component(p + ts, c->normalArray.type, GL_TRUE), npgl_read_component(p + ts * 2, c->normalArray.type, GL_TRUE));
    }
    if (c->texCoordArray.enabled) {
        p = npgl_array_element_ptr(&c->texCoordArray, index);
        ts = npgl_type_size(c->texCoordArray.type);
        if (!p || !ts) return FALSE;
        v[0] = 0.0f; v[1] = 0.0f; v[2] = 0.0f; v[3] = 1.0f;
        for (i = 0; i < c->texCoordArray.size; ++i) v[i] = npgl_read_component(p + i * ts, c->texCoordArray.type, GL_FALSE);
        if (c->texCoordArray.size <= 2) npgl_glTexCoord2f(v[0], v[1]);
        else npgl_glTexCoord4f(v[0], v[1], v[2], v[3]);
    }
    if (emitVertex && c->vertexArray.enabled) {
        p = npgl_array_element_ptr(&c->vertexArray, index);
        ts = npgl_type_size(c->vertexArray.type);
        if (!p || !ts) return FALSE;
        v[0] = v[1] = v[2] = 0.0f; v[3] = 1.0f;
        for (i = 0; i < c->vertexArray.size; ++i) v[i] = npgl_read_component(p + i * ts, c->vertexArray.type, GL_FALSE);
        npgl_glVertex4f(v[0], v[1], v[2], v[3]);
    }
    return TRUE;
}

static void APIENTRY npgl_glBindTexture(GLenum target, GLuint texture)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_TEXTURE_OBJECT *obj;
    NPGL_LIST_COMMAND cmd;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (target != GL_TEXTURE_1D && target != GL_TEXTURE_2D) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    if (c->compilingList && !c->replayingList) {
        memset(&cmd, 0, sizeof(cmd)); cmd.op = NPGL_LIST_OP_BIND_TEXTURE;
        cmd.u[0] = (DWORD)target; cmd.u[1] = texture;
        if (!npgl_record_list_command(c, &cmd)) return;
        if (c->listMode == GL_COMPILE) return;
    }
    if (!texture) obj = (target == GL_TEXTURE_1D) ? &c->defaultTexture1D : &c->defaultTexture2D;
    else {
        obj = npgl_find_texture(c, texture);
        if (!obj) obj = npgl_create_texture(c, texture, GL_TRUE);
        if (!obj) { npgl_set_error(c, GL_OUT_OF_MEMORY); return; }
        if (obj->target && obj->target != target) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
        obj->target = target;
        obj->boundOnce = GL_TRUE;
    }
    if (target == GL_TEXTURE_1D) c->boundTexture1D = obj;
    else c->boundTexture2D = obj;
}

static void APIENTRY npgl_glGenTextures(GLsizei n, GLuint *textures)
{
    NPGL_CONTEXT *c = npgl_current();
    GLsizei i;
    NPGL_TEXTURE_OBJECT *obj;
    GLuint name;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (n < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if (!textures) return;
    for (i = 0; i < n; ++i) {
        do {
            name = c->nextTextureName++;
            if (!name) name = c->nextTextureName++;
        } while (npgl_find_texture(c, name));
        obj = npgl_create_texture(c, name, GL_FALSE);
        if (!obj) { npgl_set_error(c, GL_OUT_OF_MEMORY); textures[i] = 0; return; }
        textures[i] = name;
    }
}

static void APIENTRY npgl_glDeleteTextures(GLsizei n, const GLuint *textures)
{
    NPGL_CONTEXT *c = npgl_current();
    GLsizei i;
    NPGL_TEXTURE_OBJECT *obj;
    NPGL_TEXTURE_OBJECT *prev;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (n < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if (!textures) return;
    for (i = 0; i < n; ++i) {
        if (!textures[i]) continue;
        prev = NULL;
        obj = c->textures;
        while (obj && obj->name != textures[i]) { prev = obj; obj = obj->next; }
        if (!obj) continue;
        if (c->boundTexture1D == obj) c->boundTexture1D = &c->defaultTexture1D;
        if (c->boundTexture2D == obj) c->boundTexture2D = &c->defaultTexture2D;
        npgl_delete_host_texture(c, obj);
        if (prev) prev->next = obj->next; else c->textures = obj->next;
        npgl_free_texture_object(obj);
        HeapFree(GetProcessHeap(), 0, obj);
    }
}

static GLboolean APIENTRY npgl_glIsTexture(GLuint texture)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_TEXTURE_OBJECT *obj;
    if (!c || !texture) return GL_FALSE;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return GL_FALSE; }
    obj = npgl_find_texture(c, texture);
    return (obj && obj->boundOnce) ? GL_TRUE : GL_FALSE;
}

static GLboolean APIENTRY npgl_glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences)
{
    NPGL_CONTEXT *c = npgl_current();
    GLsizei i;
    GLboolean all = GL_TRUE;
    if (!c) return GL_FALSE;
    if (n < 0) { npgl_set_error(c, GL_INVALID_VALUE); return GL_FALSE; }
    if (!textures || !residences) return GL_FALSE;
    for (i = 0; i < n; ++i) {
        residences[i] = npgl_glIsTexture(textures[i]);
        if (!residences[i]) all = GL_FALSE;
    }
    return all;
}

static void APIENTRY npgl_glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLclampf *priorities)
{
    NPGL_CONTEXT *c = npgl_current();
    (void)textures; (void)priorities;
    if (!c) return;
    if (n < 0) npgl_set_error(c, GL_INVALID_VALUE);
}

static void APIENTRY npgl_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (size < 2 || size > 4) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if (type != GL_SHORT && type != GL_INT && type != GL_FLOAT && type != GL_DOUBLE) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    if (stride < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    c->vertexArray.size = size; c->vertexArray.type = type; c->vertexArray.stride = stride; c->vertexArray.pointer = pointer;
}

static void APIENTRY npgl_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (size != 3 && size != 4) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if (!npgl_type_size(type)) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    if (stride < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    c->colorArray.size = size; c->colorArray.type = type; c->colorArray.stride = stride; c->colorArray.pointer = pointer;
}

static void APIENTRY npgl_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (size < 1 || size > 4) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if (type != GL_SHORT && type != GL_INT && type != GL_FLOAT && type != GL_DOUBLE) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    if (stride < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    c->texCoordArray.size = size; c->texCoordArray.type = type; c->texCoordArray.stride = stride; c->texCoordArray.pointer = pointer;
}

static void APIENTRY npgl_glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (type != GL_BYTE && type != GL_SHORT && type != GL_INT && type != GL_FLOAT && type != GL_DOUBLE) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    if (stride < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    c->normalArray.size = 3; c->normalArray.type = type; c->normalArray.stride = stride; c->normalArray.pointer = pointer;
}

static void APIENTRY npgl_glEnableClientState(GLenum array)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    switch (array) {
    case GL_VERTEX_ARRAY: c->vertexArray.enabled = GL_TRUE; break;
    case GL_NORMAL_ARRAY: c->normalArray.enabled = GL_TRUE; break;
    case GL_COLOR_ARRAY: c->colorArray.enabled = GL_TRUE; break;
    case GL_INDEX_ARRAY: c->indexArray.enabled = GL_TRUE; break;
    case GL_TEXTURE_COORD_ARRAY: c->texCoordArray.enabled = GL_TRUE; break;
    case GL_EDGE_FLAG_ARRAY: c->edgeFlagArray.enabled = GL_TRUE; break;
    default: npgl_set_error(c, GL_INVALID_ENUM); break;
    }
}

static void APIENTRY npgl_glDisableClientState(GLenum array)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    switch (array) {
    case GL_VERTEX_ARRAY: c->vertexArray.enabled = GL_FALSE; break;
    case GL_NORMAL_ARRAY: c->normalArray.enabled = GL_FALSE; break;
    case GL_COLOR_ARRAY: c->colorArray.enabled = GL_FALSE; break;
    case GL_INDEX_ARRAY: c->indexArray.enabled = GL_FALSE; break;
    case GL_TEXTURE_COORD_ARRAY: c->texCoordArray.enabled = GL_FALSE; break;
    case GL_EDGE_FLAG_ARRAY: c->edgeFlagArray.enabled = GL_FALSE; break;
    default: npgl_set_error(c, GL_INVALID_ENUM); break;
    }
}

static void APIENTRY npgl_glArrayElement(GLint i)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c) return;
    if (!c->inBegin && !(c->compilingList && !c->replayingList && c->listCompileInBegin)) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (!npgl_apply_array_element(c, i, GL_TRUE)) npgl_set_error(c, GL_INVALID_OPERATION);
}

static BOOL npgl_begin_array_draw(NPGL_CONTEXT *c, GLenum mode)
{
    if (!c) return FALSE;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return FALSE; }
    if (mode > GL_POLYGON) { npgl_set_error(c, GL_INVALID_ENUM); return FALSE; }
    if (!c->vertexArray.enabled || !c->vertexArray.pointer) { npgl_set_error(c, GL_INVALID_OPERATION); return FALSE; }
    c->inBegin = GL_TRUE; c->beginMode = mode; c->vertexCount = 0;
    return TRUE;
}

static void npgl_end_array_draw(NPGL_CONTEXT *c)
{
    if (!c) return;
    c->inBegin = GL_FALSE;
    if (!npgl_submit(c)) npgl_set_error(c, GL_OUT_OF_MEMORY);
}

static void APIENTRY npgl_glDrawArrays(GLenum mode, GLint first, GLsizei count)
{
    NPGL_CONTEXT *c = npgl_current();
    GLsizei i;
    if (!c) return;
    if (first < 0 || count < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if (!npgl_begin_array_draw(c, mode)) return;
    for (i = 0; i < count; ++i) {
        if (!npgl_apply_array_element(c, first + i, GL_TRUE)) { npgl_set_error(c, GL_INVALID_OPERATION); break; }
    }
    npgl_end_array_draw(c);
}

static void APIENTRY npgl_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)
{
    NPGL_CONTEXT *c = npgl_current();
    GLsizei i;
    GLuint index;
    if (!c) return;
    if (count < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if (type != GL_UNSIGNED_BYTE && type != GL_UNSIGNED_SHORT && type != GL_UNSIGNED_INT) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    if (count && !indices) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (!npgl_begin_array_draw(c, mode)) return;
    for (i = 0; i < count; ++i) {
        if (type == GL_UNSIGNED_BYTE) index = ((const GLubyte *)indices)[i];
        else if (type == GL_UNSIGNED_SHORT) index = ((const GLushort *)indices)[i];
        else index = ((const GLuint *)indices)[i];
        if (index > 0x7fffffffUL || !npgl_apply_array_element(c, (GLint)index, GL_TRUE)) { npgl_set_error(c, GL_INVALID_OPERATION); break; }
    }
    npgl_end_array_draw(c);
}

static void APIENTRY npgl_glGetPointerv(GLenum pname, GLvoid **params)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c || !params) return;
    switch (pname) {
    case GL_VERTEX_ARRAY_POINTER: *params = (GLvoid *)c->vertexArray.pointer; break;
    case GL_NORMAL_ARRAY_POINTER: *params = (GLvoid *)c->normalArray.pointer; break;
    case GL_COLOR_ARRAY_POINTER: *params = (GLvoid *)c->colorArray.pointer; break;
    case GL_INDEX_ARRAY_POINTER: *params = (GLvoid *)c->indexArray.pointer; break;
    case GL_TEXTURE_COORD_ARRAY_POINTER: *params = (GLvoid *)c->texCoordArray.pointer; break;
    case GL_EDGE_FLAG_ARRAY_POINTER: *params = (GLvoid *)c->edgeFlagArray.pointer; break;
    case GL_FEEDBACK_BUFFER_POINTER: *params = (GLvoid *)c->feedbackBuffer; break;
    case GL_SELECTION_BUFFER_POINTER: *params = (GLvoid *)c->selectBuffer; break;
    default: npgl_set_error(c, GL_INVALID_ENUM); *params = NULL; break;
    }
}

static void APIENTRY npgl_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_TEXTURE_OBJECT *obj;
    const BYTE *src;
    DWORD comp;
    DWORD srcRow;
    DWORD srcStride;
    GLint x, y;
    if (!c) return;
    if (target != GL_TEXTURE_2D) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    if (level != 0 || xoffset < 0 || yoffset < 0 || width < 0 || height < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if (type != GL_UNSIGNED_BYTE || (format != GL_RGB && format != GL_RGBA && format != GL_BGRA_EXT)) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    obj = c->boundTexture2D;
    if (!obj || !obj->defined || !obj->pixels) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (xoffset + width > obj->width || yoffset + height > obj->height) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if (!pixels || width == 0 || height == 0) return;
    comp = (format == GL_RGB) ? 3UL : 4UL;
    srcRow = (DWORD)width * comp;
    srcStride = (srcRow + (DWORD)c->unpackAlignment - 1UL) & ~((DWORD)c->unpackAlignment - 1UL);
    src = (const BYTE *)pixels + (DWORD)c->unpackSkipRows * srcStride + (DWORD)c->unpackSkipPixels * comp;
    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            const BYTE *sp = src + (DWORD)y * srcStride + (DWORD)x * comp;
            BYTE *dp = obj->pixels + ((DWORD)(yoffset + y) * (DWORD)obj->width + (DWORD)(xoffset + x)) * 4UL;
            BYTE px[4];
            if (format == GL_BGRA_EXT) { px[0] = sp[0]; px[1] = sp[1]; px[2] = sp[2]; px[3] = sp[3]; } else { px[0] = sp[2]; px[1] = sp[1]; px[2] = sp[0]; px[3] = (comp == 4UL) ? sp[3] : 255U; }
            npgl_apply_color_transfer(c, px, 1);
            memcpy(dp, px, 4);
        }
    }
    if (format == GL_RGBA || format == GL_BGRA_EXT) obj->hasAlpha = GL_TRUE;
    ++obj->revision;
    if (!npgl_upload_texture(c, obj)) npgl_set_error(c, GL_OUT_OF_MEMORY);
}

static void APIENTRY npgl_glEdgeFlag(GLboolean flag)
{
    NPGL_CONTEXT *c=npgl_current();
    NPGL_LIST_COMMAND cmd;
    if(!c)return;
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_EDGE_FLAG;cmd.u[0]=flag?1UL:0UL;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    c->currentEdgeFlag=flag?GL_TRUE:GL_FALSE;
}
static void APIENTRY npgl_glEdgeFlagv(const GLboolean *flag) { if(flag)npgl_glEdgeFlag(flag[0]); }
static void APIENTRY npgl_glEdgeFlagPointer(GLsizei stride, const GLvoid *pointer)
{
    NPGL_CONTEXT *c=npgl_current();
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(stride<0){npgl_set_error(c,GL_INVALID_VALUE);return;}
    c->edgeFlagArray.size=1;c->edgeFlagArray.type=GL_UNSIGNED_BYTE;c->edgeFlagArray.stride=stride;c->edgeFlagArray.pointer=pointer;
}
static void APIENTRY npgl_glIndexPointer(GLenum type, GLsizei stride, const GLvoid *pointer)
{
    NPGL_CONTEXT *c=npgl_current();
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(type!=GL_SHORT&&type!=GL_INT&&type!=GL_FLOAT&&type!=GL_DOUBLE){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(stride<0){npgl_set_error(c,GL_INVALID_VALUE);return;}
    c->indexArray.size=1;c->indexArray.type=type;c->indexArray.stride=stride;c->indexArray.pointer=pointer;
}
static void APIENTRY npgl_glIndexub(GLubyte c0) { npgl_set_index((GLfloat)c0); }
static void APIENTRY npgl_glIndexubv(const GLubyte *c0) { if(c0)npgl_glIndexub(c0[0]); }
static void APIENTRY npgl_glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer)
{
    NPGL_CONTEXT *c = npgl_current();
    const BYTE *base = (const BYTE *)pointer;
    GLsizei defaultStride = 0;
    GLint vertexSize = 3;
    DWORD vertexOffset = 0;
    GLboolean hasColor = GL_FALSE;
    GLint colorSize = 4;
    GLenum colorType = GL_FLOAT;
    DWORD colorOffset = 0;
    GLboolean hasNormal = GL_FALSE;
    DWORD normalOffset = 0;
    GLboolean hasTexCoord = GL_FALSE;
    GLint texCoordSize = 2;
    DWORD texCoordOffset = 0;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (stride < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    switch (format) {
    case GL_V2F: vertexSize=2; vertexOffset=0; defaultStride=8; break;
    case GL_V3F: vertexSize=3; vertexOffset=0; defaultStride=12; break;
    case GL_C4UB_V2F: hasColor=GL_TRUE; colorType=GL_UNSIGNED_BYTE; colorOffset=0; vertexSize=2; vertexOffset=4; defaultStride=12; break;
    case GL_C4UB_V3F: hasColor=GL_TRUE; colorType=GL_UNSIGNED_BYTE; colorOffset=0; vertexOffset=4; defaultStride=16; break;
    case GL_C3F_V3F: hasColor=GL_TRUE; colorSize=3; colorOffset=0; vertexOffset=12; defaultStride=24; break;
    case GL_N3F_V3F: hasNormal=GL_TRUE; normalOffset=0; vertexOffset=12; defaultStride=24; break;
    case GL_C4F_N3F_V3F: hasColor=GL_TRUE; colorOffset=0; hasNormal=GL_TRUE; normalOffset=16; vertexOffset=28; defaultStride=40; break;
    case GL_T2F_V3F: hasTexCoord=GL_TRUE; texCoordSize=2; texCoordOffset=0; vertexOffset=8; defaultStride=20; break;
    case GL_T4F_V4F: hasTexCoord=GL_TRUE; texCoordSize=4; texCoordOffset=0; vertexSize=4; vertexOffset=16; defaultStride=32; break;
    case GL_T2F_C4UB_V3F: hasTexCoord=GL_TRUE; texCoordSize=2; texCoordOffset=0; hasColor=GL_TRUE; colorType=GL_UNSIGNED_BYTE; colorOffset=8; vertexOffset=12; defaultStride=24; break;
    case GL_T2F_C3F_V3F: hasTexCoord=GL_TRUE; texCoordSize=2; texCoordOffset=0; hasColor=GL_TRUE; colorSize=3; colorOffset=8; vertexOffset=20; defaultStride=32; break;
    case GL_T2F_N3F_V3F: hasTexCoord=GL_TRUE; texCoordSize=2; texCoordOffset=0; hasNormal=GL_TRUE; normalOffset=8; vertexOffset=20; defaultStride=32; break;
    case GL_T2F_C4F_N3F_V3F: hasTexCoord=GL_TRUE; texCoordSize=2; texCoordOffset=0; hasColor=GL_TRUE; colorOffset=8; hasNormal=GL_TRUE; normalOffset=24; vertexOffset=36; defaultStride=48; break;
    case GL_T4F_C4F_N3F_V4F: hasTexCoord=GL_TRUE; texCoordSize=4; texCoordOffset=0; hasColor=GL_TRUE; colorOffset=16; hasNormal=GL_TRUE; normalOffset=32; vertexSize=4; vertexOffset=44; defaultStride=60; break;
    default: npgl_set_error(c, GL_INVALID_ENUM); return;
    }
    if (!stride) stride = defaultStride;
    c->indexArray.enabled=GL_FALSE;c->edgeFlagArray.enabled=GL_FALSE;
    c->vertexArray.enabled=GL_TRUE; c->vertexArray.size=vertexSize; c->vertexArray.type=GL_FLOAT; c->vertexArray.stride=stride; c->vertexArray.pointer=base+vertexOffset;
    c->colorArray.enabled=hasColor; if(hasColor){c->colorArray.size=colorSize;c->colorArray.type=colorType;c->colorArray.stride=stride;c->colorArray.pointer=base+colorOffset;}
    c->normalArray.enabled=hasNormal; if(hasNormal){c->normalArray.size=3;c->normalArray.type=GL_FLOAT;c->normalArray.stride=stride;c->normalArray.pointer=base+normalOffset;}
    c->texCoordArray.enabled=hasTexCoord; if(hasTexCoord){c->texCoordArray.size=texCoordSize;c->texCoordArray.type=GL_FLOAT;c->texCoordArray.stride=stride;c->texCoordArray.pointer=base+texCoordOffset;}
}
static void APIENTRY npgl_glPolygonOffset(GLfloat factor, GLfloat units) { (void)factor;(void)units; }
static void APIENTRY npgl_glPushClientAttrib(GLbitfield mask)
{
    NPGL_CONTEXT *c=npgl_current();
    NPGL_CLIENT_ATTRIB_STATE *a;
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(mask&~(GL_CLIENT_PIXEL_STORE_BIT|GL_CLIENT_VERTEX_ARRAY_BIT)){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(c->clientAttribTop>=16){npgl_set_error(c,GL_STACK_OVERFLOW);return;}
    a=&c->clientAttribStack[c->clientAttribTop++];memset(a,0,sizeof(*a));a->mask=mask;
    if(mask&GL_CLIENT_PIXEL_STORE_BIT){a->packAlignment=c->packAlignment;a->packRowLength=c->packRowLength;a->packSkipRows=c->packSkipRows;a->packSkipPixels=c->packSkipPixels;a->packSwapBytes=c->packSwapBytes;a->packLsbFirst=c->packLsbFirst;a->unpackAlignment=c->unpackAlignment;a->unpackRowLength=c->unpackRowLength;a->unpackSkipRows=c->unpackSkipRows;a->unpackSkipPixels=c->unpackSkipPixels;a->unpackSwapBytes=c->unpackSwapBytes;a->unpackLsbFirst=c->unpackLsbFirst;}
    if(mask&GL_CLIENT_VERTEX_ARRAY_BIT){a->vertexArray=c->vertexArray;a->normalArray=c->normalArray;a->colorArray=c->colorArray;a->indexArray=c->indexArray;a->texCoordArray=c->texCoordArray;a->edgeFlagArray=c->edgeFlagArray;}
}
static void APIENTRY npgl_glPopClientAttrib(void)
{
    NPGL_CONTEXT *c=npgl_current();
    NPGL_CLIENT_ATTRIB_STATE *a;
    GLbitfield mask;
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(c->clientAttribTop<=0){npgl_set_error(c,GL_STACK_UNDERFLOW);return;}
    a=&c->clientAttribStack[--c->clientAttribTop];mask=a->mask;
    if(mask&GL_CLIENT_PIXEL_STORE_BIT){c->packAlignment=a->packAlignment;c->packRowLength=a->packRowLength;c->packSkipRows=a->packSkipRows;c->packSkipPixels=a->packSkipPixels;c->packSwapBytes=a->packSwapBytes;c->packLsbFirst=a->packLsbFirst;c->unpackAlignment=a->unpackAlignment;c->unpackRowLength=a->unpackRowLength;c->unpackSkipRows=a->unpackSkipRows;c->unpackSkipPixels=a->unpackSkipPixels;c->unpackSwapBytes=a->unpackSwapBytes;c->unpackLsbFirst=a->unpackLsbFirst;}
    if(mask&GL_CLIENT_VERTEX_ARRAY_BIT){c->vertexArray=a->vertexArray;c->normalArray=a->normalArray;c->colorArray=a->colorArray;c->indexArray=a->indexArray;c->texCoordArray=a->texCoordArray;c->edgeFlagArray=a->edgeFlagArray;}
}

static void APIENTRY npgl_glClearColor(GLclampf r, GLclampf g, GLclampf b, GLclampf a)
{
    NPGL_CONTEXT *c=npgl_current(); NPGL_LIST_COMMAND cmd;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_CLEAR_COLOR;cmd.f[0]=r;cmd.f[1]=g;cmd.f[2]=b;cmd.f[3]=a;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    c->clearColor[0]=npgl_clampf(r,0,1);c->clearColor[1]=npgl_clampf(g,0,1);c->clearColor[2]=npgl_clampf(b,0,1);c->clearColor[3]=npgl_clampf(a,0,1);
}

static void APIENTRY npgl_glClearDepth(GLclampd depth)
{
    NPGL_CONTEXT *c=npgl_current(); NPGL_LIST_COMMAND cmd;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_CLEAR_DEPTH;cmd.f[0]=(GLfloat)depth;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    if (depth < 0.0) depth=0.0; if (depth > 1.0) depth=1.0; c->clearDepth=depth;
}

static void APIENTRY npgl_glClear(GLbitfield mask)
{
    NPGL_CONTEXT *c=npgl_current();
    NPDISP_OGL_CLEAR32 clear;
    DWORD allowed=GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT|GL_ACCUM_BUFFER_BIT;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (mask & ~allowed) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if(c->compilingList&&!c->replayingList){NPGL_LIST_COMMAND cmd;memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_CLEAR;cmd.u[0]=(DWORD)mask;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    if (!npgl_ensure_drawable(c)) return;
    memset(&clear,0,sizeof(clear));
    clear.size=sizeof(clear); clear.context=c->bridgeContext; clear.x=c->drawX; clear.y=c->drawY; clear.width=c->drawWidth; clear.height=c->drawHeight;
    if (mask & GL_COLOR_BUFFER_BIT) clear.flags|=NPDISP_OGL_CLEAR_COLOR;
    if ((mask & GL_DEPTH_BUFFER_BIT) && c->pixelFormat != NPGL_PIXEL_FORMAT_NO_DEPTH_DOUBLE && c->pixelFormat != NPGL_PIXEL_FORMAT_NO_DEPTH_SINGLE) clear.flags|=NPDISP_OGL_CLEAR_DEPTH;
    if ((mask & GL_STENCIL_BUFFER_BIT) && c->stencilBits) clear.flags|=NPDISP_OGL_CLEAR_STENCIL;
    clear.color=npgl_pack_color(c->clearColor);
    clear.depth=(DWORD)(c->clearDepth*65535.0+0.5);
    clear.stencil=(DWORD)c->clearStencil;
    clear.stencilBits=(DWORD)c->stencilBits;
    clear.stencilWriteMask=c->stencilWriteMask;
    clear.colorWriteDisableMask=(!c->colorMask[0]?1UL:0UL)|(!c->colorMask[1]?2UL:0UL)|(!c->colorMask[2]?4UL:0UL)|(!c->colorMask[3]?8UL:0UL);
    if(c->drawBuffer==GL_NONE) clear.colorWriteDisableMask|=7UL;
    clear.scissorEnable=c->scissorTest?1UL:0UL;
    clear.scissorX=c->scissorBox[0];
    clear.scissorY=c->scissorBox[1];
    clear.scissorWidth=(c->scissorBox[2]>0)?(DWORD)c->scissorBox[2]:0UL;
    clear.scissorHeight=(c->scissorBox[3]>0)?(DWORD)c->scissorBox[3]:0UL;
    if (clear.flags && !npgl_host_call(NPDISP_OGL_CMD_CLEAR,&clear)) npgl_set_error(c,GL_OUT_OF_MEMORY);
}

static void APIENTRY npgl_glClearStencil(GLint s)
{
    NPGL_CONTEXT *c=npgl_current(); NPGL_LIST_COMMAND cmd;
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_CLEAR_STENCIL;cmd.u[0]=(DWORD)s;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    c->clearStencil=s;
}

static void APIENTRY npgl_glStencilFunc(GLenum func, GLint ref, GLuint mask)
{
    NPGL_CONTEXT *c=npgl_current();
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(!npgl_depth_func(func)){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(c->stencilBits>0){ GLint maxRef=(1<<c->stencilBits)-1; if(ref<0)ref=0; else if(ref>maxRef)ref=maxRef; }
    if(c->compilingList&&!c->replayingList){NPGL_LIST_COMMAND cmd;memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_STENCIL_FUNC;cmd.u[0]=(DWORD)func;cmd.u[1]=(DWORD)ref;cmd.u[2]=(DWORD)mask;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    c->stencilFunc=func;c->stencilRef=ref;c->stencilValueMask=mask;
}

static void APIENTRY npgl_glStencilMask(GLuint mask)
{
    NPGL_CONTEXT *c=npgl_current(); NPGL_LIST_COMMAND cmd; if(!c)return; if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;} if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_STENCIL_MASK;cmd.u[0]=mask;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;} c->stencilWriteMask=mask;
}

static GLboolean npgl_valid_stencil_op(GLenum op)
{
    return (op==GL_KEEP||op==GL_ZERO||op==GL_REPLACE||op==GL_INCR||op==GL_DECR||op==GL_INVERT)?GL_TRUE:GL_FALSE;
}

static void APIENTRY npgl_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass)
{
    NPGL_CONTEXT *c=npgl_current(); if(!c)return; if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(!npgl_valid_stencil_op(fail)||!npgl_valid_stencil_op(zfail)||!npgl_valid_stencil_op(zpass)){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(c->compilingList&&!c->replayingList){NPGL_LIST_COMMAND cmd;memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_STENCIL_OP;cmd.u[0]=(DWORD)fail;cmd.u[1]=(DWORD)zfail;cmd.u[2]=(DWORD)zpass;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    c->stencilFail=fail;c->stencilZFail=zfail;c->stencilPass=zpass;
}

static NPGL_LIGHT *npgl_light_from_enum(NPGL_CONTEXT *c, GLenum light)
{
    if (!c || light < GL_LIGHT0 || light > GL_LIGHT7) return NULL;
    return &c->lights[light - GL_LIGHT0];
}

static void APIENTRY npgl_glColorMaterial(GLenum face, GLenum mode)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_LIST_COMMAND cmd;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (face != GL_FRONT && face != GL_BACK && face != GL_FRONT_AND_BACK) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    if (mode != GL_AMBIENT && mode != GL_DIFFUSE && mode != GL_SPECULAR && mode != GL_EMISSION && mode != GL_AMBIENT_AND_DIFFUSE) {
        npgl_set_error(c, GL_INVALID_ENUM); return;
    }
    if (c->compilingList && !c->replayingList) {
        memset(&cmd, 0, sizeof(cmd)); cmd.op = NPGL_LIST_OP_COLOR_MATERIAL;
        cmd.u[0] = (DWORD)face; cmd.u[1] = (DWORD)mode;
        if (!npgl_record_list_command(c, &cmd)) return;
        if (c->listMode == GL_COMPILE) return;
    }
    c->colorMaterialFace = face;
    c->colorMaterialMode = mode;
}

static void APIENTRY npgl_glFogfv(GLenum pname, const GLfloat *params)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_LIST_COMMAND cmd;
    if (!c || !params) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    switch (pname) {
    case GL_FOG_MODE:
        if ((GLenum)(GLint)params[0] != GL_LINEAR && (GLenum)(GLint)params[0] != GL_EXP && (GLenum)(GLint)params[0] != GL_EXP2) { npgl_set_error(c, GL_INVALID_ENUM); return; }
        break;
    case GL_FOG_DENSITY:
        if (params[0] < 0.0f) { npgl_set_error(c, GL_INVALID_VALUE); return; }
        break;
    case GL_FOG_START: case GL_FOG_END: case GL_FOG_COLOR: case GL_FOG_INDEX: break;
    default: npgl_set_error(c, GL_INVALID_ENUM); return;
    }
    if (c->compilingList && !c->replayingList) {
        memset(&cmd, 0, sizeof(cmd)); cmd.op = NPGL_LIST_OP_FOG; cmd.u[0] = (DWORD)pname;
        memcpy(cmd.f, params, (pname == GL_FOG_COLOR ? 4 : 1) * sizeof(GLfloat));
        if (!npgl_record_list_command(c, &cmd)) return;
        if (c->listMode == GL_COMPILE) return;
    }
    switch (pname) {
    case GL_FOG_MODE: c->fogMode = (GLenum)(GLint)params[0]; break;
    case GL_FOG_DENSITY: c->fogDensity = params[0]; break;
    case GL_FOG_START: c->fogStart = params[0]; break;
    case GL_FOG_END: c->fogEnd = params[0]; break;
    case GL_FOG_COLOR: npgl_copy4(c->fogColor, params); break;
    case GL_FOG_INDEX: break;
    }
}

static void APIENTRY npgl_glFogf(GLenum pname, GLfloat param) { GLfloat p[4]={param,0,0,0}; npgl_glFogfv(pname,p); }
static void APIENTRY npgl_glFogi(GLenum pname, GLint param) { GLfloat p[4]={(GLfloat)param,0,0,0}; npgl_glFogfv(pname,p); }
static void APIENTRY npgl_glFogiv(GLenum pname, const GLint *params)
{
    GLfloat p[4]={0,0,0,0};
    if (!params) return;
    p[0]=(GLfloat)params[0];
    if (pname==GL_FOG_COLOR) { p[1]=(GLfloat)params[1];p[2]=(GLfloat)params[2];p[3]=(GLfloat)params[3]; }
    npgl_glFogfv(pname,p);
}

static void APIENTRY npgl_glLightfv(GLenum light, GLenum pname, const GLfloat *params)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_LIGHT *l = npgl_light_from_enum(c, light);
    NPGL_LIST_COMMAND cmd;
    if (!c || !params) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (!l) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    switch (pname) {
    case GL_AMBIENT: case GL_DIFFUSE: case GL_SPECULAR: case GL_POSITION: case GL_SPOT_DIRECTION: break;
    case GL_SPOT_EXPONENT: if (params[0] < 0.0f || params[0] > 128.0f) { npgl_set_error(c, GL_INVALID_VALUE); return; } break;
    case GL_SPOT_CUTOFF: if (params[0] != 180.0f && (params[0] < 0.0f || params[0] > 90.0f)) { npgl_set_error(c, GL_INVALID_VALUE); return; } break;
    case GL_CONSTANT_ATTENUATION: case GL_LINEAR_ATTENUATION: case GL_QUADRATIC_ATTENUATION:
        if (params[0] < 0.0f) { npgl_set_error(c, GL_INVALID_VALUE); return; } break;
    default: npgl_set_error(c, GL_INVALID_ENUM); return;
    }
    if (c->compilingList && !c->replayingList) {
        memset(&cmd, 0, sizeof(cmd)); cmd.op = NPGL_LIST_OP_LIGHT; cmd.u[0] = (DWORD)light; cmd.u[1] = (DWORD)pname;
        memcpy(cmd.f, params, ((pname == GL_AMBIENT || pname == GL_DIFFUSE || pname == GL_SPECULAR || pname == GL_POSITION) ? 4 : (pname == GL_SPOT_DIRECTION ? 3 : 1)) * sizeof(GLfloat));
        if (!npgl_record_list_command(c, &cmd)) return;
        if (c->listMode == GL_COMPILE) return;
    }
    switch (pname) {
    case GL_AMBIENT: npgl_copy4(l->ambient, params); break;
    case GL_DIFFUSE: npgl_copy4(l->diffuse, params); break;
    case GL_SPECULAR: npgl_copy4(l->specular, params); break;
    case GL_POSITION: npgl_transform_eye_position(c->modelview, params, l->position); break;
    case GL_SPOT_DIRECTION: npgl_transform_eye_vector(c->modelview, params, l->spotDirection); npgl_normalize3(l->spotDirection); break;
    case GL_SPOT_EXPONENT: l->spotExponent = params[0]; break;
    case GL_SPOT_CUTOFF: l->spotCutoff = params[0]; break;
    case GL_CONSTANT_ATTENUATION: l->constantAttenuation = params[0]; break;
    case GL_LINEAR_ATTENUATION: l->linearAttenuation = params[0]; break;
    case GL_QUADRATIC_ATTENUATION: l->quadraticAttenuation = params[0]; break;
    }
}

static void APIENTRY npgl_glLightf(GLenum light, GLenum pname, GLfloat param) { GLfloat p[4]={param,0,0,0}; npgl_glLightfv(light,pname,p); }
static void APIENTRY npgl_glLighti(GLenum light, GLenum pname, GLint param) { GLfloat p[4]={(GLfloat)param,0,0,0}; npgl_glLightfv(light,pname,p); }
static void APIENTRY npgl_glLightiv(GLenum light, GLenum pname, const GLint *params)
{
    GLfloat p[4]={0,0,0,0};
    if (!params) return;
    p[0]=(GLfloat)params[0];
    if (pname==GL_AMBIENT||pname==GL_DIFFUSE||pname==GL_SPECULAR||pname==GL_POSITION) {
        p[1]=(GLfloat)params[1];p[2]=(GLfloat)params[2];p[3]=(GLfloat)params[3];
    }
    else if (pname==GL_SPOT_DIRECTION) {
        p[1]=(GLfloat)params[1];p[2]=(GLfloat)params[2];
    }
    npgl_glLightfv(light,pname,p);
}

static void APIENTRY npgl_glLightModelfv(GLenum pname, const GLfloat *params)
{
    NPGL_CONTEXT *c=npgl_current(); NPGL_LIST_COMMAND cmd;
    if(!c||!params)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(pname!=GL_LIGHT_MODEL_AMBIENT&&pname!=GL_LIGHT_MODEL_LOCAL_VIEWER&&pname!=GL_LIGHT_MODEL_TWO_SIDE){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_LIGHT_MODEL;cmd.u[0]=(DWORD)pname;memcpy(cmd.f,params,(pname==GL_LIGHT_MODEL_AMBIENT?4:1)*sizeof(GLfloat));if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    switch(pname){case GL_LIGHT_MODEL_AMBIENT:npgl_copy4(c->lightModelAmbient,params);break;case GL_LIGHT_MODEL_LOCAL_VIEWER:c->lightModelLocalViewer=params[0]!=0.0f;break;case GL_LIGHT_MODEL_TWO_SIDE:c->lightModelTwoSide=params[0]!=0.0f;break;}
}

static void APIENTRY npgl_glLightModelf(GLenum pname, GLfloat param){GLfloat p[4]={param,0,0,0};npgl_glLightModelfv(pname,p);}
static void APIENTRY npgl_glLightModeli(GLenum pname, GLint param){GLfloat p[4]={(GLfloat)param,0,0,0};npgl_glLightModelfv(pname,p);}
static void APIENTRY npgl_glLightModeliv(GLenum pname, const GLint *params){GLfloat p[4]={0,0,0,0};if(!params)return;p[0]=(GLfloat)params[0];if(pname==GL_LIGHT_MODEL_AMBIENT){p[1]=(GLfloat)params[1];p[2]=(GLfloat)params[2];p[3]=(GLfloat)params[3];}npgl_glLightModelfv(pname,p);}

static void APIENTRY npgl_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params)
{
    NPGL_CONTEXT *c=npgl_current(); NPGL_LIST_COMMAND cmd;
    if(!c||!params)return;
    if(face!=GL_FRONT&&face!=GL_BACK&&face!=GL_FRONT_AND_BACK){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(pname!=GL_AMBIENT&&pname!=GL_DIFFUSE&&pname!=GL_SPECULAR&&pname!=GL_EMISSION&&pname!=GL_SHININESS&&pname!=GL_AMBIENT_AND_DIFFUSE){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(pname==GL_SHININESS&&(params[0]<0.0f||params[0]>128.0f)){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_MATERIAL;cmd.u[0]=(DWORD)face;cmd.u[1]=(DWORD)pname;memcpy(cmd.f,params,(pname==GL_SHININESS?1:4)*sizeof(GLfloat));if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    switch(pname){case GL_AMBIENT:npgl_copy4(c->material.ambient,params);break;case GL_DIFFUSE:npgl_copy4(c->material.diffuse,params);break;case GL_SPECULAR:npgl_copy4(c->material.specular,params);break;case GL_EMISSION:npgl_copy4(c->material.emission,params);break;case GL_SHININESS:c->material.shininess=params[0];break;case GL_AMBIENT_AND_DIFFUSE:npgl_copy4(c->material.ambient,params);npgl_copy4(c->material.diffuse,params);break;}
}

static void APIENTRY npgl_glMaterialf(GLenum face, GLenum pname, GLfloat param){GLfloat p[4]={param,0,0,1};npgl_glMaterialfv(face,pname,p);}
static void APIENTRY npgl_glMateriali(GLenum face, GLenum pname, GLint param){GLfloat p[4]={(GLfloat)param,0,0,1};npgl_glMaterialfv(face,pname,p);}
static void APIENTRY npgl_glMaterialiv(GLenum face, GLenum pname, const GLint *params){GLfloat p[4]={0,0,0,1};if(!params)return;p[0]=(GLfloat)params[0];if(pname==GL_AMBIENT||pname==GL_DIFFUSE||pname==GL_SPECULAR||pname==GL_EMISSION||pname==GL_AMBIENT_AND_DIFFUSE){p[1]=(GLfloat)params[1];p[2]=(GLfloat)params[2];p[3]=(GLfloat)params[3];}npgl_glMaterialfv(face,pname,p);}

static void APIENTRY npgl_glGetLightfv(GLenum light, GLenum pname, GLfloat *params)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIGHT *l=npgl_light_from_enum(c,light);
    if(!c||!params)return;if(!l){npgl_set_error(c,GL_INVALID_ENUM);return;}
    switch(pname){
    case GL_AMBIENT:npgl_copy4(params,l->ambient);break;case GL_DIFFUSE:npgl_copy4(params,l->diffuse);break;case GL_SPECULAR:npgl_copy4(params,l->specular);break;case GL_POSITION:npgl_copy4(params,l->position);break;
    case GL_SPOT_DIRECTION:params[0]=l->spotDirection[0];params[1]=l->spotDirection[1];params[2]=l->spotDirection[2];break;
    case GL_SPOT_EXPONENT:params[0]=l->spotExponent;break;case GL_SPOT_CUTOFF:params[0]=l->spotCutoff;break;case GL_CONSTANT_ATTENUATION:params[0]=l->constantAttenuation;break;case GL_LINEAR_ATTENUATION:params[0]=l->linearAttenuation;break;case GL_QUADRATIC_ATTENUATION:params[0]=l->quadraticAttenuation;break;
    default:npgl_set_error(c,GL_INVALID_ENUM);break;}
}
static void APIENTRY npgl_glGetLightiv(GLenum light, GLenum pname, GLint *params){GLfloat p[4]={0,0,0,0};int n=1,i;NPGL_CONTEXT *c=npgl_current();if(!params)return;npgl_glGetLightfv(light,pname,p);if(c&&c->error)return;if(pname==GL_AMBIENT||pname==GL_DIFFUSE||pname==GL_SPECULAR||pname==GL_POSITION)n=4;else if(pname==GL_SPOT_DIRECTION)n=3;for(i=0;i<n;++i)params[i]=(GLint)p[i];}
static void APIENTRY npgl_glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params)
{
    NPGL_CONTEXT *c=npgl_current();if(!c||!params)return;if(face!=GL_FRONT&&face!=GL_BACK){npgl_set_error(c,GL_INVALID_ENUM);return;}
    switch(pname){case GL_AMBIENT:npgl_copy4(params,c->material.ambient);break;case GL_DIFFUSE:npgl_copy4(params,c->material.diffuse);break;case GL_SPECULAR:npgl_copy4(params,c->material.specular);break;case GL_EMISSION:npgl_copy4(params,c->material.emission);break;case GL_SHININESS:params[0]=c->material.shininess;break;default:npgl_set_error(c,GL_INVALID_ENUM);break;}
}
static void APIENTRY npgl_glGetMaterialiv(GLenum face, GLenum pname, GLint *params){GLfloat p[4]={0,0,0,0};int n=1,i;NPGL_CONTEXT *c=npgl_current();if(!params)return;npgl_glGetMaterialfv(face,pname,p);if(c&&c->error)return;if(pname!=GL_SHININESS)n=4;for(i=0;i<n;++i)params[i]=(GLint)p[i];}

static void APIENTRY npgl_glHint(GLenum target, GLenum mode)
{
    NPGL_CONTEXT *c=npgl_current();
    GLenum *dst=NULL;
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(mode!=GL_DONT_CARE&&mode!=GL_FASTEST&&mode!=GL_NICEST){npgl_set_error(c,GL_INVALID_ENUM);return;}
    switch(target){
    case GL_PERSPECTIVE_CORRECTION_HINT:dst=&c->perspectiveHint;break;
    case GL_POINT_SMOOTH_HINT:dst=&c->pointSmoothHint;break;
    case GL_LINE_SMOOTH_HINT:dst=&c->lineSmoothHint;break;
    case GL_POLYGON_SMOOTH_HINT:dst=&c->polygonSmoothHint;break;
    case GL_FOG_HINT:dst=&c->fogHint;break;
    default:npgl_set_error(c,GL_INVALID_ENUM);return;
    }
    if(c->compilingList&&!c->replayingList){NPGL_LIST_COMMAND cmd;memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_HINT;cmd.u[0]=(DWORD)target;cmd.u[1]=(DWORD)mode;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    *dst=mode;
}

static void APIENTRY npgl_glScissor(GLint x, GLint y, GLsizei width, GLsizei height)
{
    NPGL_CONTEXT *c=npgl_current();
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(width<0||height<0){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(c->compilingList&&!c->replayingList){NPGL_LIST_COMMAND cmd;memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_SCISSOR;cmd.u[0]=(DWORD)x;cmd.u[1]=(DWORD)y;cmd.u[2]=(DWORD)width;cmd.u[3]=(DWORD)height;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    c->scissorBox[0]=x;c->scissorBox[1]=y;c->scissorBox[2]=width;c->scissorBox[3]=height;c->scissorSet=GL_TRUE;
}


static int npgl_eval_target_index(GLenum target, int dimension, GLint *components)
{
    int index;
    static const GLint counts[NPGL_EVAL_TARGET_COUNT] = {4,1,3,1,2,3,4,3,4};
    GLenum base = dimension == 1 ? GL_MAP1_COLOR_4 : GL_MAP2_COLOR_4;
    if ((dimension != 1 && dimension != 2) || target < base || target > base + 8) return -1;
    index = (int)(target - base);
    if (components) *components = counts[index];
    return index;
}

static int npgl_eval_cap_index(GLenum cap, int *dimension)
{
    if (cap >= GL_MAP1_COLOR_4 && cap <= GL_MAP1_VERTEX_4) { if (dimension) *dimension = 1; return (int)(cap - GL_MAP1_COLOR_4); }
    if (cap >= GL_MAP2_COLOR_4 && cap <= GL_MAP2_VERTEX_4) { if (dimension) *dimension = 2; return (int)(cap - GL_MAP2_COLOR_4); }
    return -1;
}

static void npgl_init_evaluators(NPGL_CONTEXT *c)
{
    int i;
    static const GLint counts[NPGL_EVAL_TARGET_COUNT] = {4,1,3,1,2,3,4,3,4};
    if (!c) return;
    for (i = 0; i < NPGL_EVAL_TARGET_COUNT; ++i) {
        NPGL_EVAL_MAP1 *m1 = &c->evalMap1[i];
        NPGL_EVAL_MAP2 *m2 = &c->evalMap2[i];
        memset(m1, 0, sizeof(*m1)); memset(m2, 0, sizeof(*m2));
        m1->components = counts[i]; m1->order = 1; m1->u1 = 0.0f; m1->u2 = 1.0f;
        m2->components = counts[i]; m2->uorder = 1; m2->vorder = 1; m2->u1 = 0.0f; m2->u2 = 1.0f; m2->v1 = 0.0f; m2->v2 = 1.0f;
        if (i == 0) { m1->points[0]=m1->points[1]=m1->points[2]=m1->points[3]=1.0f; m2->points[0]=m2->points[1]=m2->points[2]=m2->points[3]=1.0f; }
        else if (i == 1) { m1->points[0]=1.0f; m2->points[0]=1.0f; }
        else if (i == 2) { m1->points[2]=1.0f; m2->points[2]=1.0f; }
        else if (i == 6 || i == 8) { m1->points[3]=1.0f; m2->points[3]=1.0f; }
    }
    c->autoNormal = GL_FALSE;
    c->map1GridSegments = 1; c->map1GridDomain[0] = 0.0f; c->map1GridDomain[1] = 1.0f;
    c->map2GridSegments[0] = c->map2GridSegments[1] = 1;
    c->map2GridDomain[0] = 0.0f; c->map2GridDomain[1] = 1.0f; c->map2GridDomain[2] = 0.0f; c->map2GridDomain[3] = 1.0f;
}

static void npgl_eval_curve(const GLfloat *points, GLint order, GLint components, GLfloat t, GLfloat *out)
{
    GLfloat work[NPGL_MAX_EVAL_ORDER * 4]; int i,j,k;
    memset(work,0,sizeof(work));
    for(i=0;i<order;++i)for(k=0;k<components;++k)work[i*4+k]=points[i*4+k];
    for(j=1;j<order;++j)for(i=0;i<order-j;++i)for(k=0;k<components;++k)work[i*4+k]=(1.0f-t)*work[i*4+k]+t*work[(i+1)*4+k];
    for(k=0;k<components;++k)out[k]=work[k];
}

static void npgl_eval_surface(const NPGL_EVAL_MAP2 *m, GLfloat u, GLfloat v, GLfloat *out)
{
    GLfloat rows[NPGL_MAX_EVAL_ORDER * 4]; GLfloat tu,tv; int j;
    tu=(u-m->u1)/(m->u2-m->u1); tv=(v-m->v1)/(m->v2-m->v1);
    memset(rows,0,sizeof(rows));
    for(j=0;j<m->vorder;++j)npgl_eval_curve(&m->points[j*m->uorder*4],m->uorder,m->components,tu,&rows[j*4]);
    npgl_eval_curve(rows,m->vorder,m->components,tv,out);
}

static void npgl_eval_surface_derivatives(const NPGL_EVAL_MAP2 *m, GLfloat u, GLfloat v, GLfloat *p, GLfloat *du, GLfloat *dv)
{
    GLfloat dctrl[NPGL_MAX_EVAL_ORDER * NPGL_MAX_EVAL_ORDER * 4]; NPGL_EVAL_MAP2 dm; int i,j,k;
    npgl_eval_surface(m,u,v,p); memset(du,0,4*sizeof(GLfloat)); memset(dv,0,4*sizeof(GLfloat));
    if(m->uorder>1){memset(&dm,0,sizeof(dm));dm.components=m->components;dm.uorder=m->uorder-1;dm.vorder=m->vorder;dm.u1=m->u1;dm.u2=m->u2;dm.v1=m->v1;dm.v2=m->v2;memset(dctrl,0,sizeof(dctrl));
        for(j=0;j<m->vorder;++j)for(i=0;i<m->uorder-1;++i)for(k=0;k<m->components;++k)dctrl[(j*dm.uorder+i)*4+k]=(m->points[(j*m->uorder+i+1)*4+k]-m->points[(j*m->uorder+i)*4+k])*(GLfloat)(m->uorder-1)/(m->u2-m->u1);
        memcpy(dm.points,dctrl,sizeof(dctrl));npgl_eval_surface(&dm,u,v,du);}
    if(m->vorder>1){memset(&dm,0,sizeof(dm));dm.components=m->components;dm.uorder=m->uorder;dm.vorder=m->vorder-1;dm.u1=m->u1;dm.u2=m->u2;dm.v1=m->v1;dm.v2=m->v2;memset(dctrl,0,sizeof(dctrl));
        for(j=0;j<m->vorder-1;++j)for(i=0;i<m->uorder;++i)for(k=0;k<m->components;++k)dctrl[(j*dm.uorder+i)*4+k]=(m->points[((j+1)*m->uorder+i)*4+k]-m->points[(j*m->uorder+i)*4+k])*(GLfloat)(m->vorder-1)/(m->v2-m->v1);
        memcpy(dm.points,dctrl,sizeof(dctrl));npgl_eval_surface(&dm,u,v,dv);}
}

static GLfloat npgl_eval_grid_value(GLint index, GLint segments, GLfloat a, GLfloat b)
{
    if(index==segments)return b;
    return a+(GLfloat)index*(b-a)/(GLfloat)segments;
}

static void npgl_eval_coord1_internal(NPGL_CONTEXT *c, GLfloat u)
{
    int vi,ti,k; GLfloat value[4], saveColor[4], saveNormal[3], saveTex[4], saveIndex;
    if(!c)return; vi=c->evalMap1[8].enabled?8:(c->evalMap1[7].enabled?7:-1); if(vi<0)return;
    memcpy(saveColor,c->currentColor,sizeof(saveColor));memcpy(saveNormal,c->currentNormal,sizeof(saveNormal));memcpy(saveTex,c->currentTexCoord,sizeof(saveTex));saveIndex=c->currentIndex;
    if(c->evalMap1[1].enabled){npgl_eval_curve(c->evalMap1[1].points,c->evalMap1[1].order,1,(u-c->evalMap1[1].u1)/(c->evalMap1[1].u2-c->evalMap1[1].u1),value);c->currentIndex=value[0];}
    if(c->evalMap1[0].enabled){npgl_eval_curve(c->evalMap1[0].points,c->evalMap1[0].order,4,(u-c->evalMap1[0].u1)/(c->evalMap1[0].u2-c->evalMap1[0].u1),value);memcpy(c->currentColor,value,4*sizeof(GLfloat));}
    if(c->evalMap1[2].enabled){npgl_eval_curve(c->evalMap1[2].points,c->evalMap1[2].order,3,(u-c->evalMap1[2].u1)/(c->evalMap1[2].u2-c->evalMap1[2].u1),value);memcpy(c->currentNormal,value,3*sizeof(GLfloat));}
    ti=-1;for(k=6;k>=3;--k)if(c->evalMap1[k].enabled){ti=k;break;}if(ti>=0){NPGL_EVAL_MAP1*m=&c->evalMap1[ti];memset(value,0,sizeof(value));value[3]=1.0f;npgl_eval_curve(m->points,m->order,m->components,(u-m->u1)/(m->u2-m->u1),value);if(m->components<4)value[3]=1.0f;memcpy(c->currentTexCoord,value,4*sizeof(GLfloat));}
    {NPGL_EVAL_MAP1*m=&c->evalMap1[vi];memset(value,0,sizeof(value));value[3]=1.0f;npgl_eval_curve(m->points,m->order,m->components,(u-m->u1)/(m->u2-m->u1),value);if(m->components==3)value[3]=1.0f;npgl_emit_vertex(value[0],value[1],value[2],value[3]);}
    memcpy(c->currentColor,saveColor,sizeof(saveColor));memcpy(c->currentNormal,saveNormal,sizeof(saveNormal));memcpy(c->currentTexCoord,saveTex,sizeof(saveTex));c->currentIndex=saveIndex;
}

static void npgl_eval_coord2_internal(NPGL_CONTEXT *c, GLfloat u, GLfloat v)
{
    int vi,ti,k; GLfloat value[4],p[4],du[4],dv[4],saveColor[4],saveNormal[3],saveTex[4],saveIndex;
    if(!c)return; vi=c->evalMap2[8].enabled?8:(c->evalMap2[7].enabled?7:-1); if(vi<0)return;
    memcpy(saveColor,c->currentColor,sizeof(saveColor));memcpy(saveNormal,c->currentNormal,sizeof(saveNormal));memcpy(saveTex,c->currentTexCoord,sizeof(saveTex));saveIndex=c->currentIndex;
    if(c->evalMap2[1].enabled){npgl_eval_surface(&c->evalMap2[1],u,v,value);c->currentIndex=value[0];}
    if(c->evalMap2[0].enabled){npgl_eval_surface(&c->evalMap2[0],u,v,value);memcpy(c->currentColor,value,4*sizeof(GLfloat));}
    if(c->autoNormal){NPGL_EVAL_MAP2*m=&c->evalMap2[vi];GLfloat a[3],b[3],n[3],w2;npgl_eval_surface_derivatives(m,u,v,p,du,dv);if(m->components==4&&p[3]!=0.0f){w2=p[3]*p[3];for(k=0;k<3;++k){a[k]=(du[k]*p[3]-p[k]*du[3])/w2;b[k]=(dv[k]*p[3]-p[k]*dv[3])/w2;}}else{for(k=0;k<3;++k){a[k]=du[k];b[k]=dv[k];}}n[0]=a[1]*b[2]-a[2]*b[1];n[1]=a[2]*b[0]-a[0]*b[2];n[2]=a[0]*b[1]-a[1]*b[0];if(npgl_normalize3(n)!=0.0f)memcpy(c->currentNormal,n,3*sizeof(GLfloat));else c->currentNormal[0]=c->currentNormal[1]=c->currentNormal[2]=0.0f;}
    else if(c->evalMap2[2].enabled){npgl_eval_surface(&c->evalMap2[2],u,v,value);memcpy(c->currentNormal,value,3*sizeof(GLfloat));}
    ti=-1;for(k=6;k>=3;--k)if(c->evalMap2[k].enabled){ti=k;break;}if(ti>=0){NPGL_EVAL_MAP2*m=&c->evalMap2[ti];memset(value,0,sizeof(value));value[3]=1.0f;npgl_eval_surface(m,u,v,value);if(m->components<4)value[3]=1.0f;memcpy(c->currentTexCoord,value,4*sizeof(GLfloat));}
    {NPGL_EVAL_MAP2*m=&c->evalMap2[vi];memset(value,0,sizeof(value));value[3]=1.0f;npgl_eval_surface(m,u,v,value);if(m->components==3)value[3]=1.0f;npgl_emit_vertex(value[0],value[1],value[2],value[3]);}
    memcpy(c->currentColor,saveColor,sizeof(saveColor));memcpy(c->currentNormal,saveNormal,sizeof(saveNormal));memcpy(c->currentTexCoord,saveTex,sizeof(saveTex));c->currentIndex=saveIndex;
}

static void npgl_apply_map1(NPGL_CONTEXT *c, const NPGL_LIST_EVAL_MAP *src)
{
    int index=npgl_eval_target_index(src->target,1,NULL); NPGL_EVAL_MAP1*m; if(index<0)return;m=&c->evalMap1[index];m->components=src->components;m->order=src->uorder;m->u1=src->u1;m->u2=src->u2;memcpy(m->points,src->points,(DWORD)src->uorder*4UL*sizeof(GLfloat));
}

static void npgl_apply_map2(NPGL_CONTEXT *c, const NPGL_LIST_EVAL_MAP *src)
{
    int index=npgl_eval_target_index(src->target,2,NULL); NPGL_EVAL_MAP2*m; if(index<0)return;m=&c->evalMap2[index];m->components=src->components;m->uorder=src->uorder;m->vorder=src->vorder;m->u1=src->u1;m->u2=src->u2;m->v1=src->v1;m->v2=src->v2;memcpy(m->points,src->points,(DWORD)src->uorder*(DWORD)src->vorder*4UL*sizeof(GLfloat));
}

static NPGL_LIST_EVAL_MAP *npgl_make_map1(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points)
{
    NPGL_LIST_EVAL_MAP*m;GLint comp;int i,k;if(npgl_eval_target_index(target,1,&comp)<0)return NULL;m=(NPGL_LIST_EVAL_MAP*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(*m));if(!m)return NULL;m->target=target;m->dimension=1;m->components=comp;m->uorder=order;m->vorder=1;m->u1=u1;m->u2=u2;for(i=0;i<order;++i)for(k=0;k<comp;++k)m->points[i*4+k]=points[i*stride+k];return m;
}

static NPGL_LIST_EVAL_MAP *npgl_make_map1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points)
{
    NPGL_LIST_EVAL_MAP*m;GLint comp;int i,k;if(npgl_eval_target_index(target,1,&comp)<0)return NULL;m=(NPGL_LIST_EVAL_MAP*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(*m));if(!m)return NULL;m->target=target;m->dimension=1;m->components=comp;m->uorder=order;m->vorder=1;m->u1=(GLfloat)u1;m->u2=(GLfloat)u2;for(i=0;i<order;++i)for(k=0;k<comp;++k)m->points[i*4+k]=(GLfloat)points[i*stride+k];return m;
}

static NPGL_LIST_EVAL_MAP *npgl_make_map2(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points)
{
    NPGL_LIST_EVAL_MAP*m;GLint comp;int i,j,k;if(npgl_eval_target_index(target,2,&comp)<0)return NULL;m=(NPGL_LIST_EVAL_MAP*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(*m));if(!m)return NULL;m->target=target;m->dimension=2;m->components=comp;m->uorder=uorder;m->vorder=vorder;m->u1=u1;m->u2=u2;m->v1=v1;m->v2=v2;for(j=0;j<vorder;++j)for(i=0;i<uorder;++i)for(k=0;k<comp;++k)m->points[(j*uorder+i)*4+k]=points[j*vstride+i*ustride+k];return m;
}

static NPGL_LIST_EVAL_MAP *npgl_make_map2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points)
{
    NPGL_LIST_EVAL_MAP*m;GLint comp;int i,j,k;if(npgl_eval_target_index(target,2,&comp)<0)return NULL;m=(NPGL_LIST_EVAL_MAP*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(*m));if(!m)return NULL;m->target=target;m->dimension=2;m->components=comp;m->uorder=uorder;m->vorder=vorder;m->u1=(GLfloat)u1;m->u2=(GLfloat)u2;m->v1=(GLfloat)v1;m->v2=(GLfloat)v2;for(j=0;j<vorder;++j)for(i=0;i<uorder;++i)for(k=0;k<comp;++k)m->points[(j*uorder+i)*4+k]=(GLfloat)points[j*vstride+i*ustride+k];return m;
}

static GLboolean npgl_validate_map1(NPGL_CONTEXT*c, GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLvoid *points)
{
    GLint comp;if(npgl_eval_target_index(target,1,&comp)<0){npgl_set_error(c,GL_INVALID_ENUM);return GL_FALSE;}if(u1==u2||order<1||order>NPGL_MAX_EVAL_ORDER||stride<comp){npgl_set_error(c,GL_INVALID_VALUE);return GL_FALSE;}if(!points){npgl_set_error(c,GL_INVALID_VALUE);return GL_FALSE;}return GL_TRUE;
}

static GLboolean npgl_validate_map2(NPGL_CONTEXT*c, GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLvoid *points)
{
    GLint comp;if(npgl_eval_target_index(target,2,&comp)<0){npgl_set_error(c,GL_INVALID_ENUM);return GL_FALSE;}if(u1==u2||v1==v2||uorder<1||uorder>NPGL_MAX_EVAL_ORDER||vorder<1||vorder>NPGL_MAX_EVAL_ORDER||ustride<comp||vstride<comp){npgl_set_error(c,GL_INVALID_VALUE);return GL_FALSE;}if(!points){npgl_set_error(c,GL_INVALID_VALUE);return GL_FALSE;}return GL_TRUE;
}

static void APIENTRY npgl_glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points)
{
    NPGL_CONTEXT*c=npgl_current();NPGL_LIST_EVAL_MAP*m;NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(!npgl_validate_map1(c,target,u1,u2,stride,order,points))return;m=npgl_make_map1(target,u1,u2,stride,order,points);if(!m){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_MAP1;cmd.u[0]=(DWORD)m;if(!npgl_record_list_command(c,&cmd)){HeapFree(GetProcessHeap(),0,m);return;}if(c->listMode==GL_COMPILE)return;}npgl_apply_map1(c,m);if(!(c->compilingList&&!c->replayingList))HeapFree(GetProcessHeap(),0,m);
}

static void APIENTRY npgl_glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points)
{
    NPGL_CONTEXT*c=npgl_current();NPGL_LIST_EVAL_MAP*m;NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(!npgl_validate_map1(c,target,u1,u2,stride,order,points))return;m=npgl_make_map1d(target,u1,u2,stride,order,points);if(!m){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_MAP1;cmd.u[0]=(DWORD)m;if(!npgl_record_list_command(c,&cmd)){HeapFree(GetProcessHeap(),0,m);return;}if(c->listMode==GL_COMPILE)return;}npgl_apply_map1(c,m);if(!(c->compilingList&&!c->replayingList))HeapFree(GetProcessHeap(),0,m);
}

static void APIENTRY npgl_glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points)
{
    NPGL_CONTEXT*c=npgl_current();NPGL_LIST_EVAL_MAP*m;NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(!npgl_validate_map2(c,target,u1,u2,ustride,uorder,v1,v2,vstride,vorder,points))return;m=npgl_make_map2(target,u1,u2,ustride,uorder,v1,v2,vstride,vorder,points);if(!m){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_MAP2;cmd.u[0]=(DWORD)m;if(!npgl_record_list_command(c,&cmd)){HeapFree(GetProcessHeap(),0,m);return;}if(c->listMode==GL_COMPILE)return;}npgl_apply_map2(c,m);if(!(c->compilingList&&!c->replayingList))HeapFree(GetProcessHeap(),0,m);
}

static void APIENTRY npgl_glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points)
{
    NPGL_CONTEXT*c=npgl_current();NPGL_LIST_EVAL_MAP*m;NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(!npgl_validate_map2(c,target,u1,u2,ustride,uorder,v1,v2,vstride,vorder,points))return;m=npgl_make_map2d(target,u1,u2,ustride,uorder,v1,v2,vstride,vorder,points);if(!m){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_MAP2;cmd.u[0]=(DWORD)m;if(!npgl_record_list_command(c,&cmd)){HeapFree(GetProcessHeap(),0,m);return;}if(c->listMode==GL_COMPILE)return;}npgl_apply_map2(c,m);if(!(c->compilingList&&!c->replayingList))HeapFree(GetProcessHeap(),0,m);
}

static void APIENTRY npgl_glMapGrid1f(GLint un, GLfloat u1, GLfloat u2)
{NPGL_CONTEXT*c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(un<=0){npgl_set_error(c,GL_INVALID_VALUE);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_MAP_GRID1;cmd.u[0]=(DWORD)un;cmd.f[0]=u1;cmd.f[1]=u2;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->map1GridSegments=un;c->map1GridDomain[0]=u1;c->map1GridDomain[1]=u2;}
static void APIENTRY npgl_glMapGrid1d(GLint un, GLdouble u1, GLdouble u2){npgl_glMapGrid1f(un,(GLfloat)u1,(GLfloat)u2);}
static void APIENTRY npgl_glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2)
{NPGL_CONTEXT*c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(un<=0||vn<=0){npgl_set_error(c,GL_INVALID_VALUE);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_MAP_GRID2;cmd.u[0]=(DWORD)un;cmd.u[1]=(DWORD)vn;cmd.f[0]=u1;cmd.f[1]=u2;cmd.f[2]=v1;cmd.f[3]=v2;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->map2GridSegments[0]=un;c->map2GridSegments[1]=vn;c->map2GridDomain[0]=u1;c->map2GridDomain[1]=u2;c->map2GridDomain[2]=v1;c->map2GridDomain[3]=v2;}
static void APIENTRY npgl_glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2){npgl_glMapGrid2f(un,(GLfloat)u1,(GLfloat)u2,vn,(GLfloat)v1,(GLfloat)v2);}

static void APIENTRY npgl_glEvalCoord1f(GLfloat u)
{NPGL_CONTEXT*c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->compilingList&&!c->replayingList){if(!c->listCompileInBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_EVAL_COORD1;cmd.f[0]=u;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}npgl_eval_coord1_internal(c,u);}
static void APIENTRY npgl_glEvalCoord1d(GLdouble u){npgl_glEvalCoord1f((GLfloat)u);}
static void APIENTRY npgl_glEvalCoord1fv(const GLfloat*u){if(u)npgl_glEvalCoord1f(u[0]);}
static void APIENTRY npgl_glEvalCoord1dv(const GLdouble*u){if(u)npgl_glEvalCoord1d(u[0]);}
static void APIENTRY npgl_glEvalCoord2f(GLfloat u, GLfloat v)
{NPGL_CONTEXT*c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->compilingList&&!c->replayingList){if(!c->listCompileInBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_EVAL_COORD2;cmd.f[0]=u;cmd.f[1]=v;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}npgl_eval_coord2_internal(c,u,v);}
static void APIENTRY npgl_glEvalCoord2d(GLdouble u, GLdouble v){npgl_glEvalCoord2f((GLfloat)u,(GLfloat)v);}
static void APIENTRY npgl_glEvalCoord2fv(const GLfloat*u){if(u)npgl_glEvalCoord2f(u[0],u[1]);}
static void APIENTRY npgl_glEvalCoord2dv(const GLdouble*u){if(u)npgl_glEvalCoord2d(u[0],u[1]);}

static void APIENTRY npgl_glEvalPoint1(GLint i)
{NPGL_CONTEXT*c=npgl_current();NPGL_LIST_COMMAND cmd;GLfloat u;if(!c)return;if(c->compilingList&&!c->replayingList){if(!c->listCompileInBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_EVAL_POINT1;cmd.u[0]=(DWORD)i;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}u=npgl_eval_grid_value(i,c->map1GridSegments,c->map1GridDomain[0],c->map1GridDomain[1]);npgl_eval_coord1_internal(c,u);}
static void APIENTRY npgl_glEvalPoint2(GLint i, GLint j)
{NPGL_CONTEXT*c=npgl_current();NPGL_LIST_COMMAND cmd;GLfloat u,v;if(!c)return;if(c->compilingList&&!c->replayingList){if(!c->listCompileInBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_EVAL_POINT2;cmd.u[0]=(DWORD)i;cmd.u[1]=(DWORD)j;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}u=npgl_eval_grid_value(i,c->map2GridSegments[0],c->map2GridDomain[0],c->map2GridDomain[1]);v=npgl_eval_grid_value(j,c->map2GridSegments[1],c->map2GridDomain[2],c->map2GridDomain[3]);npgl_eval_coord2_internal(c,u,v);}

static void npgl_eval_mesh1_execute(NPGL_CONTEXT*c, GLenum mode, GLint i1, GLint i2)
{GLint i;GLfloat u;GLboolean oldReplay=c->replayingList;if(c->compilingList&&!oldReplay)c->replayingList=GL_TRUE;npgl_glBegin(mode==GL_POINT?GL_POINTS:GL_LINE_STRIP);for(i=i1;i<=i2;++i){u=npgl_eval_grid_value(i,c->map1GridSegments,c->map1GridDomain[0],c->map1GridDomain[1]);npgl_eval_coord1_internal(c,u);}npgl_glEnd();c->replayingList=oldReplay;}
static void APIENTRY npgl_glEvalMesh1(GLenum mode, GLint i1, GLint i2)
{NPGL_CONTEXT*c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(mode!=GL_POINT&&mode!=GL_LINE){npgl_set_error(c,GL_INVALID_ENUM);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_EVAL_MESH1;cmd.u[0]=(DWORD)mode;cmd.u[1]=(DWORD)i1;cmd.u[2]=(DWORD)i2;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}npgl_eval_mesh1_execute(c,mode,i1,i2);}

static void npgl_eval_mesh2_execute(NPGL_CONTEXT*c, GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2)
{GLint i,j;GLfloat u,v;GLboolean oldReplay=c->replayingList;if(c->compilingList&&!oldReplay)c->replayingList=GL_TRUE;if(mode==GL_POINT){npgl_glBegin(GL_POINTS);for(j=j1;j<=j2;++j){v=npgl_eval_grid_value(j,c->map2GridSegments[1],c->map2GridDomain[2],c->map2GridDomain[3]);for(i=i1;i<=i2;++i){u=npgl_eval_grid_value(i,c->map2GridSegments[0],c->map2GridDomain[0],c->map2GridDomain[1]);npgl_eval_coord2_internal(c,u,v);}}npgl_glEnd();}
 else if(mode==GL_LINE){for(j=j1;j<=j2;++j){v=npgl_eval_grid_value(j,c->map2GridSegments[1],c->map2GridDomain[2],c->map2GridDomain[3]);npgl_glBegin(GL_LINE_STRIP);for(i=i1;i<=i2;++i){u=npgl_eval_grid_value(i,c->map2GridSegments[0],c->map2GridDomain[0],c->map2GridDomain[1]);npgl_eval_coord2_internal(c,u,v);}npgl_glEnd();}for(i=i1;i<=i2;++i){u=npgl_eval_grid_value(i,c->map2GridSegments[0],c->map2GridDomain[0],c->map2GridDomain[1]);npgl_glBegin(GL_LINE_STRIP);for(j=j1;j<=j2;++j){v=npgl_eval_grid_value(j,c->map2GridSegments[1],c->map2GridDomain[2],c->map2GridDomain[3]);npgl_eval_coord2_internal(c,u,v);}npgl_glEnd();}}
 else{for(j=j1;j<j2;++j){GLfloat v0=npgl_eval_grid_value(j,c->map2GridSegments[1],c->map2GridDomain[2],c->map2GridDomain[3]);GLfloat v1=npgl_eval_grid_value(j+1,c->map2GridSegments[1],c->map2GridDomain[2],c->map2GridDomain[3]);npgl_glBegin(GL_QUAD_STRIP);for(i=i1;i<=i2;++i){u=npgl_eval_grid_value(i,c->map2GridSegments[0],c->map2GridDomain[0],c->map2GridDomain[1]);npgl_eval_coord2_internal(c,u,v0);npgl_eval_coord2_internal(c,u,v1);}npgl_glEnd();}}c->replayingList=oldReplay;}
static void APIENTRY npgl_glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2)
{NPGL_CONTEXT*c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(mode!=GL_POINT&&mode!=GL_LINE&&mode!=GL_FILL){npgl_set_error(c,GL_INVALID_ENUM);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_EVAL_MESH2;cmd.u[0]=(DWORD)mode;cmd.u[1]=(DWORD)i1;cmd.u[2]=(DWORD)i2;cmd.u[3]=(DWORD)j1;cmd.f[0]=(GLfloat)j2;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}npgl_eval_mesh2_execute(c,mode,i1,i2,j1,j2);}

static GLint npgl_round_eval_int(GLfloat v){return v>=0.0f?(GLint)floor((double)v+0.5):(GLint)ceil((double)v-0.5);}
static void npgl_get_map_values(NPGL_CONTEXT*c, GLenum target, GLenum query, GLfloat *fv, GLdouble *dv, GLint *iv)
{int dim,index,i,count=0;GLint comp;NPGL_EVAL_MAP1*m1;NPGL_EVAL_MAP2*m2;index=npgl_eval_cap_index(target,&dim);if(index<0){npgl_set_error(c,GL_INVALID_ENUM);return;}npgl_eval_target_index(target,dim,&comp);m1=dim==1?&c->evalMap1[index]:NULL;m2=dim==2?&c->evalMap2[index]:NULL;
 if(query==GL_ORDER){if(dim==1){if(fv)fv[0]=(GLfloat)m1->order;if(dv)dv[0]=(GLdouble)m1->order;if(iv)iv[0]=m1->order;}else{if(fv){fv[0]=(GLfloat)m2->uorder;fv[1]=(GLfloat)m2->vorder;}if(dv){dv[0]=(GLdouble)m2->uorder;dv[1]=(GLdouble)m2->vorder;}if(iv){iv[0]=m2->uorder;iv[1]=m2->vorder;}}return;}
 if(query==GL_DOMAIN){if(dim==1){if(fv){fv[0]=m1->u1;fv[1]=m1->u2;}if(dv){dv[0]=m1->u1;dv[1]=m1->u2;}if(iv){iv[0]=npgl_round_eval_int(m1->u1);iv[1]=npgl_round_eval_int(m1->u2);}}else{if(fv){fv[0]=m2->u1;fv[1]=m2->u2;fv[2]=m2->v1;fv[3]=m2->v2;}if(dv){dv[0]=m2->u1;dv[1]=m2->u2;dv[2]=m2->v1;dv[3]=m2->v2;}if(iv){iv[0]=npgl_round_eval_int(m2->u1);iv[1]=npgl_round_eval_int(m2->u2);iv[2]=npgl_round_eval_int(m2->v1);iv[3]=npgl_round_eval_int(m2->v2);}}return;}
 if(query!=GL_COEFF){npgl_set_error(c,GL_INVALID_ENUM);return;}count=dim==1?m1->order*comp:m2->uorder*m2->vorder*comp;for(i=0;i<count;++i){int pt=i/comp,k=i%comp;GLfloat v=dim==1?m1->points[pt*4+k]:m2->points[pt*4+k];if(fv)fv[i]=v;if(dv)dv[i]=(GLdouble)v;if(iv)iv[i]=npgl_round_eval_int(v);}}
static void APIENTRY npgl_glGetMapfv(GLenum target, GLenum query, GLfloat *v){NPGL_CONTEXT*c=npgl_current();if(!c||!v)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}npgl_get_map_values(c,target,query,v,NULL,NULL);}
static void APIENTRY npgl_glGetMapdv(GLenum target, GLenum query, GLdouble *v){NPGL_CONTEXT*c=npgl_current();if(!c||!v)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}npgl_get_map_values(c,target,query,NULL,v,NULL);}
static void APIENTRY npgl_glGetMapiv(GLenum target, GLenum query, GLint *v){NPGL_CONTEXT*c=npgl_current();if(!c||!v)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}npgl_get_map_values(c,target,query,NULL,NULL,v);}

static void APIENTRY npgl_glClipPlane(GLenum plane, const GLdouble *equation)
{
    NPGL_CONTEXT *c=npgl_current(); NPGL_LIST_COMMAND cmd; GLdouble inv[16], result[4]; int i,j,index;
    if(!c||!equation)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(plane<GL_CLIP_PLANE0||plane>GL_CLIP_PLANE5){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_CLIP_PLANE;cmd.u[0]=(DWORD)plane;memcpy(cmd.f,equation,4*sizeof(GLdouble));if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    index=(int)(plane-GL_CLIP_PLANE0);
    if(npgl_matrix_inverse_double(c->modelview,inv)){
        for(i=0;i<4;++i){result[i]=0.0;for(j=0;j<4;++j)result[i]+=inv[i*4+j]*equation[j];}
        memcpy(c->clipPlane[index],result,sizeof(result));
    } else memcpy(c->clipPlane[index],equation,4*sizeof(GLdouble));
}

static void APIENTRY npgl_glGetClipPlane(GLenum plane, GLdouble *equation)
{
    NPGL_CONTEXT *c=npgl_current(); int index;
    if(!c||!equation)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(plane<GL_CLIP_PLANE0||plane>GL_CLIP_PLANE5){npgl_set_error(c,GL_INVALID_ENUM);return;}
    index=(int)(plane-GL_CLIP_PLANE0); memcpy(equation,c->clipPlane[index],4*sizeof(GLdouble));
}

static void APIENTRY npgl_glLogicOp(GLenum opcode)
{
    NPGL_CONTEXT *c=npgl_current(); NPGL_LIST_COMMAND cmd;
    if(!c)return;
    if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(opcode<GL_CLEAR||opcode>GL_SET){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_LOGIC_OP;cmd.u[0]=(DWORD)opcode;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    c->logicOpMode=opcode;
}

static void APIENTRY npgl_glEnable(GLenum cap)
{
    NPGL_CONTEXT *c=npgl_current(); NPGL_LIST_COMMAND cmd; GLboolean valid=GL_TRUE; int ei,ed;
    if(!c)return; if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    ei=npgl_eval_cap_index(cap,&ed);
    switch(cap){case GL_DEPTH_TEST:case GL_BLEND:case GL_ALPHA_TEST:case GL_CULL_FACE:case GL_TEXTURE_1D:case GL_TEXTURE_2D:case GL_LIGHTING:case GL_NORMALIZE:case GL_COLOR_MATERIAL:case GL_FOG:case GL_SCISSOR_TEST:case GL_STENCIL_TEST:case GL_LINE_STIPPLE:case GL_POLYGON_STIPPLE:case GL_TEXTURE_GEN_S:case GL_TEXTURE_GEN_T:case GL_TEXTURE_GEN_R:case GL_TEXTURE_GEN_Q:case GL_COLOR_LOGIC_OP:case GL_INDEX_LOGIC_OP:case GL_AUTO_NORMAL:break;default:if(ei<0&&!((cap>=GL_LIGHT0&&cap<=GL_LIGHT7)||(cap>=GL_CLIP_PLANE0&&cap<=GL_CLIP_PLANE5)))valid=GL_FALSE;break;}
    if(!valid){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_ENABLE;cmd.u[0]=(DWORD)cap;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    if(ei>=0){if(ed==1)c->evalMap1[ei].enabled=GL_TRUE;else c->evalMap2[ei].enabled=GL_TRUE;return;}
    switch(cap){case GL_DEPTH_TEST:c->depthTest=GL_TRUE;break;case GL_BLEND:c->blend=GL_TRUE;break;case GL_ALPHA_TEST:c->alphaTest=GL_TRUE;break;case GL_CULL_FACE:c->cullFaceEnable=GL_TRUE;break;case GL_TEXTURE_1D:c->texture1D=GL_TRUE;break;case GL_TEXTURE_2D:c->texture2D=GL_TRUE;break;case GL_LIGHTING:c->lighting=GL_TRUE;break;case GL_NORMALIZE:c->normalize=GL_TRUE;break;case GL_COLOR_MATERIAL:c->colorMaterial=GL_TRUE;break;case GL_FOG:c->fog=GL_TRUE;break;case GL_SCISSOR_TEST:c->scissorTest=GL_TRUE;break;case GL_STENCIL_TEST:c->stencilTest=GL_TRUE;break;case GL_LINE_STIPPLE:c->lineStipple=GL_TRUE;break;case GL_POLYGON_STIPPLE:c->polygonStipple=GL_TRUE;break;case GL_TEXTURE_GEN_S:c->texGenEnabled[0]=GL_TRUE;break;case GL_TEXTURE_GEN_T:c->texGenEnabled[1]=GL_TRUE;break;case GL_TEXTURE_GEN_R:c->texGenEnabled[2]=GL_TRUE;break;case GL_TEXTURE_GEN_Q:c->texGenEnabled[3]=GL_TRUE;break;case GL_COLOR_LOGIC_OP:c->colorLogicOp=GL_TRUE;break;case GL_INDEX_LOGIC_OP:c->indexLogicOp=GL_TRUE;break;case GL_AUTO_NORMAL:c->autoNormal=GL_TRUE;break;default:if(cap>=GL_CLIP_PLANE0&&cap<=GL_CLIP_PLANE5)c->clipPlaneEnabled[cap-GL_CLIP_PLANE0]=GL_TRUE;else c->lights[cap-GL_LIGHT0].enabled=GL_TRUE;break;}
}
static void APIENTRY npgl_glDisable(GLenum cap)
{
    NPGL_CONTEXT *c=npgl_current(); NPGL_LIST_COMMAND cmd; GLboolean valid=GL_TRUE; int ei,ed;
    if(!c)return; if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    ei=npgl_eval_cap_index(cap,&ed);
    switch(cap){case GL_DEPTH_TEST:case GL_BLEND:case GL_ALPHA_TEST:case GL_CULL_FACE:case GL_TEXTURE_1D:case GL_TEXTURE_2D:case GL_LIGHTING:case GL_NORMALIZE:case GL_COLOR_MATERIAL:case GL_FOG:case GL_SCISSOR_TEST:case GL_STENCIL_TEST:case GL_LINE_STIPPLE:case GL_POLYGON_STIPPLE:case GL_TEXTURE_GEN_S:case GL_TEXTURE_GEN_T:case GL_TEXTURE_GEN_R:case GL_TEXTURE_GEN_Q:case GL_COLOR_LOGIC_OP:case GL_INDEX_LOGIC_OP:case GL_AUTO_NORMAL:break;default:if(ei<0&&!((cap>=GL_LIGHT0&&cap<=GL_LIGHT7)||(cap>=GL_CLIP_PLANE0&&cap<=GL_CLIP_PLANE5)))valid=GL_FALSE;break;}
    if(!valid){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_DISABLE;cmd.u[0]=(DWORD)cap;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    if(ei>=0){if(ed==1)c->evalMap1[ei].enabled=GL_FALSE;else c->evalMap2[ei].enabled=GL_FALSE;return;}
    switch(cap){case GL_DEPTH_TEST:c->depthTest=GL_FALSE;break;case GL_BLEND:c->blend=GL_FALSE;break;case GL_ALPHA_TEST:c->alphaTest=GL_FALSE;break;case GL_CULL_FACE:c->cullFaceEnable=GL_FALSE;break;case GL_TEXTURE_1D:c->texture1D=GL_FALSE;break;case GL_TEXTURE_2D:c->texture2D=GL_FALSE;break;case GL_LIGHTING:c->lighting=GL_FALSE;break;case GL_NORMALIZE:c->normalize=GL_FALSE;break;case GL_COLOR_MATERIAL:c->colorMaterial=GL_FALSE;break;case GL_FOG:c->fog=GL_FALSE;break;case GL_SCISSOR_TEST:c->scissorTest=GL_FALSE;break;case GL_STENCIL_TEST:c->stencilTest=GL_FALSE;break;case GL_LINE_STIPPLE:c->lineStipple=GL_FALSE;break;case GL_POLYGON_STIPPLE:c->polygonStipple=GL_FALSE;break;case GL_TEXTURE_GEN_S:c->texGenEnabled[0]=GL_FALSE;break;case GL_TEXTURE_GEN_T:c->texGenEnabled[1]=GL_FALSE;break;case GL_TEXTURE_GEN_R:c->texGenEnabled[2]=GL_FALSE;break;case GL_TEXTURE_GEN_Q:c->texGenEnabled[3]=GL_FALSE;break;case GL_COLOR_LOGIC_OP:c->colorLogicOp=GL_FALSE;break;case GL_INDEX_LOGIC_OP:c->indexLogicOp=GL_FALSE;break;case GL_AUTO_NORMAL:c->autoNormal=GL_FALSE;break;default:if(cap>=GL_CLIP_PLANE0&&cap<=GL_CLIP_PLANE5)c->clipPlaneEnabled[cap-GL_CLIP_PLANE0]=GL_FALSE;else c->lights[cap-GL_LIGHT0].enabled=GL_FALSE;break;}
}
static GLboolean APIENTRY npgl_glIsEnabled(GLenum cap)
{
    NPGL_CONTEXT *c=npgl_current(); int ei,ed; if(!c)return GL_FALSE; ei=npgl_eval_cap_index(cap,&ed); if(ei>=0)return ed==1?c->evalMap1[ei].enabled:c->evalMap2[ei].enabled;
    switch(cap){case GL_DEPTH_TEST:return c->depthTest;case GL_BLEND:return c->blend;case GL_ALPHA_TEST:return c->alphaTest;case GL_CULL_FACE:return c->cullFaceEnable;case GL_TEXTURE_1D:return c->texture1D;case GL_TEXTURE_2D:return c->texture2D;case GL_LIGHTING:return c->lighting;case GL_NORMALIZE:return c->normalize;case GL_COLOR_MATERIAL:return c->colorMaterial;case GL_FOG:return c->fog;case GL_SCISSOR_TEST:return c->scissorTest;case GL_STENCIL_TEST:return c->stencilTest;case GL_LINE_STIPPLE:return c->lineStipple;case GL_POLYGON_STIPPLE:return c->polygonStipple;case GL_TEXTURE_GEN_S:return c->texGenEnabled[0];case GL_TEXTURE_GEN_T:return c->texGenEnabled[1];case GL_TEXTURE_GEN_R:return c->texGenEnabled[2];case GL_TEXTURE_GEN_Q:return c->texGenEnabled[3];case GL_COLOR_LOGIC_OP:return c->colorLogicOp;case GL_INDEX_LOGIC_OP:return c->indexLogicOp;case GL_AUTO_NORMAL:return c->autoNormal;default:if(cap>=GL_LIGHT0&&cap<=GL_LIGHT7)return c->lights[cap-GL_LIGHT0].enabled;if(cap>=GL_CLIP_PLANE0&&cap<=GL_CLIP_PLANE5)return c->clipPlaneEnabled[cap-GL_CLIP_PLANE0];npgl_set_error(c,GL_INVALID_ENUM);return GL_FALSE;}
}
static void APIENTRY npgl_glDepthMask(GLboolean flag) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_DEPTH_MASK;cmd.u[0]=flag?1UL:0UL;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->depthWrite=flag?GL_TRUE:GL_FALSE; }
static void APIENTRY npgl_glDepthFunc(GLenum func) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(!npgl_depth_func(func)){npgl_set_error(c,GL_INVALID_ENUM);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_DEPTH_FUNC;cmd.u[0]=(DWORD)func;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->depthFunc=func; }
static void APIENTRY npgl_glAlphaFunc(GLenum func, GLclampf ref) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(!npgl_depth_func(func)){npgl_set_error(c,GL_INVALID_ENUM);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_ALPHA_FUNC;cmd.u[0]=(DWORD)func;cmd.f[0]=ref;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->alphaFunc=func;c->alphaRef=npgl_clampf(ref,0,1); }
static void APIENTRY npgl_glBlendFunc(GLenum sfactor, GLenum dfactor) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(!npgl_blend_factor(sfactor)||!npgl_blend_factor(dfactor)){npgl_set_error(c,GL_INVALID_ENUM);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_BLEND_FUNC;cmd.u[0]=(DWORD)sfactor;cmd.u[1]=(DWORD)dfactor;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->srcBlend=sfactor;c->destBlend=dfactor; }
static void APIENTRY npgl_glPointSize(GLfloat size) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(size<=0.0f){npgl_set_error(c,GL_INVALID_VALUE);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_POINT_SIZE;cmd.f[0]=size;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->pointSize=size; }
static void APIENTRY npgl_glLineWidth(GLfloat width) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(width<=0.0f){npgl_set_error(c,GL_INVALID_VALUE);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_LINE_WIDTH;cmd.f[0]=width;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->lineWidth=width; }
static void APIENTRY npgl_glLineStipple(GLint factor, GLushort pattern) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(factor<1||factor>256){npgl_set_error(c,GL_INVALID_VALUE);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_LINE_STIPPLE;cmd.u[0]=(DWORD)factor;cmd.u[1]=(DWORD)pattern;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->lineStippleFactor=factor;c->lineStipplePattern=pattern; }
static void APIENTRY npgl_glPolygonStipple(const GLubyte *mask) { NPGL_CONTEXT *c=npgl_current(); if(!c)return; if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;} if(!mask){npgl_set_error(c,GL_INVALID_VALUE);return;} memcpy(c->polygonStipplePattern,mask,128); }
static void APIENTRY npgl_glGetPolygonStipple(GLubyte *mask) { NPGL_CONTEXT *c=npgl_current(); if(!c||!mask)return; if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;} memcpy(mask,c->polygonStipplePattern,128); }
static void APIENTRY npgl_glPolygonMode(GLenum face, GLenum mode) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(face!=GL_FRONT&&face!=GL_BACK&&face!=GL_FRONT_AND_BACK){npgl_set_error(c,GL_INVALID_ENUM);return;}if(mode!=GL_POINT&&mode!=GL_LINE&&mode!=GL_FILL){npgl_set_error(c,GL_INVALID_ENUM);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_POLYGON_MODE;cmd.u[0]=(DWORD)face;cmd.u[1]=(DWORD)mode;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}if(face==GL_FRONT||face==GL_FRONT_AND_BACK)c->polygonModeFront=mode;if(face==GL_BACK||face==GL_FRONT_AND_BACK)c->polygonModeBack=mode; }
static void APIENTRY npgl_glShadeModel(GLenum mode) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(mode!=GL_FLAT&&mode!=GL_SMOOTH){npgl_set_error(c,GL_INVALID_ENUM);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_SHADE_MODEL;cmd.u[0]=(DWORD)mode;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->shadeModel=mode; }
static void APIENTRY npgl_glCullFace(GLenum mode) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(mode!=GL_FRONT&&mode!=GL_BACK&&mode!=GL_FRONT_AND_BACK){npgl_set_error(c,GL_INVALID_ENUM);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_CULL_FACE;cmd.u[0]=(DWORD)mode;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->cullFace=mode; }
static void APIENTRY npgl_glFrontFace(GLenum mode) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(mode!=GL_CW&&mode!=GL_CCW){npgl_set_error(c,GL_INVALID_ENUM);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_FRONT_FACE;cmd.u[0]=(DWORD)mode;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->frontFace=mode; }
typedef int (WINAPI *NPGL_GETRANDOMRGNPROC)(HDC, HRGN, INT);

static DWORD npgl_get_visible_rects(NPGL_CONTEXT *c, NPDISP_OGL_CLIPRECT32 **rects, GLboolean *valid)
{
    static NPGL_GETRANDOMRGNPROC getRandomRgn=NULL;
    static GLboolean getRandomRgnInit=GL_FALSE;
    NPGL_GETRANDOMRGNPROC proc;
    HMODULE gdi;
    HRGN rgn, clientRgn;
    RGNDATA *data;
    RECT *src;
    POINT dcOrigin;
    DWORD bytes, count, outCount, version;
    UINT i;
    if (!c || !rects || !valid || !c->hdc) return 0;
    *rects=NULL;
    *valid=GL_FALSE;
    rgn=CreateRectRgn(0,0,0,0);
    if (!rgn) return 0;
    if (!getRandomRgnInit) {
        getRandomRgnInit=GL_TRUE;
        gdi=GetModuleHandleA("GDI32.DLL");
        if (gdi) getRandomRgn=(NPGL_GETRANDOMRGNPROC)GetProcAddress(gdi,"GetRandomRgn");
    }
    proc=getRandomRgn;
    if (!proc) {
        *valid=GL_TRUE;
        DeleteObject(rgn);
        return 0;
    }
    {
        int rgnResult=proc(c->hdc,rgn,4);
        if (rgnResult==0) {
            *rects=(NPDISP_OGL_CLIPRECT32 *)HeapAlloc(GetProcessHeap(),0,sizeof(**rects));
            if (!*rects) { DeleteObject(rgn); return 0; }
            (*rects)[0].left=0;(*rects)[0].top=0;(*rects)[0].right=(LONG)c->drawWidth;(*rects)[0].bottom=(LONG)c->drawHeight;
            *valid=GL_TRUE;
            DeleteObject(rgn);
            return 1;
        }
        if (rgnResult!=1) {
            *valid=GL_TRUE;
            DeleteObject(rgn);
            return 0;
        }
    }
    version=GetVersion();
    if (version&0x80000000UL) {
        dcOrigin.x=dcOrigin.y=0;
        if (!GetDCOrgEx(c->hdc,&dcOrigin)) {
            dcOrigin.x=c->drawX;
            dcOrigin.y=c->drawY;
        }
        OffsetRgn(rgn,dcOrigin.x,dcOrigin.y);
    }
    clientRgn=CreateRectRgn(c->drawX,c->drawY,c->drawX+(LONG)c->drawWidth,c->drawY+(LONG)c->drawHeight);
    if (!clientRgn) { DeleteObject(rgn); return 0; }
    CombineRgn(rgn,rgn,clientRgn,RGN_AND);
    DeleteObject(clientRgn);
    bytes=GetRegionData(rgn,0,NULL);
    if (!bytes) { *valid=GL_TRUE;DeleteObject(rgn);return 0; }
    data=(RGNDATA *)HeapAlloc(GetProcessHeap(),0,bytes);
    if (!data) { DeleteObject(rgn); return 0; }
    if (!GetRegionData(rgn,bytes,data) || data->rdh.iType!=RDH_RECTANGLES) { HeapFree(GetProcessHeap(),0,data);DeleteObject(rgn);return 0; }
    *valid=GL_TRUE;
    count=data->rdh.nCount;
    if (count>256) count=256;
    if (count) {
        *rects=(NPDISP_OGL_CLIPRECT32 *)HeapAlloc(GetProcessHeap(),0,count*sizeof(**rects));
        if (!*rects) { *valid=GL_FALSE;HeapFree(GetProcessHeap(),0,data);DeleteObject(rgn);return 0; }
    }
    src=(RECT *)data->Buffer;
    outCount=0;
    for (i=0;i<count;++i) {
        LONG left=src[i].left-c->drawX,top=src[i].top-c->drawY,right=src[i].right-c->drawX,bottom=src[i].bottom-c->drawY;
        if (left<0) left=0;
        if (top<0) top=0;
        if (right>(LONG)c->drawWidth) right=(LONG)c->drawWidth;
        if (bottom>(LONG)c->drawHeight) bottom=(LONG)c->drawHeight;
        if (right<=left || bottom<=top) continue;
        (*rects)[outCount].left=left;(*rects)[outCount].top=top;(*rects)[outCount].right=right;(*rects)[outCount].bottom=bottom;
        ++outCount;
    }
    HeapFree(GetProcessHeap(),0,data);
    DeleteObject(rgn);
    return outCount;
}

static DWORD npgl_swap_context(NPGL_CONTEXT *c)
{
    NPDISP_OGL_SWAP32 p;
    NPDISP_OGL_CLIPRECT32 *rects=NULL;
    GLboolean clipValid=GL_FALSE;
    DWORD count, result;
    if (!c || !npgl_ensure_drawable(c)) return 0;
    memset(&p,0,sizeof(p));
    p.size=sizeof(p);
    p.context=c->bridgeContext;
    count=npgl_get_visible_rects(c,&rects,&clipValid);
    p.clipValid=clipValid?1UL:0UL;
    p.clipCount=count;
    p.clipRects=(DWORD)rects;
    result=npgl_host_call(NPDISP_OGL_CMD_SWAP,&p);
    if (rects) HeapFree(GetProcessHeap(),0,rects);
    if (result) c->drawableDirty=GL_TRUE;
    return result;
}

static void npgl_present_single_buffer(NPGL_CONTEXT *c)
{
    if (!c || c->doubleBuffered) return;
    npgl_swap_context(c);
}
static void APIENTRY npgl_glFinish(void) { npgl_present_single_buffer(npgl_current()); }
static void APIENTRY npgl_glFlush(void) { npgl_present_single_buffer(npgl_current()); }

static void APIENTRY npgl_glMatrixMode(GLenum mode)
{
    NPGL_CONTEXT *c=npgl_current(); NPGL_LIST_COMMAND cmd; if(!c)return; if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(mode!=GL_MODELVIEW&&mode!=GL_PROJECTION&&mode!=GL_TEXTURE){npgl_set_error(c,GL_INVALID_ENUM);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_MATRIX_MODE;cmd.u[0]=(DWORD)mode;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;} c->matrixMode=mode;
}
static void APIENTRY npgl_glLoadIdentity(void) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;GLfloat *m;if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_LOAD_IDENTITY;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}m=npgl_current_matrix(c);if(m)npgl_identity(m); }
static void APIENTRY npgl_glLoadMatrixf(const GLfloat *m) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;GLfloat *d;if(!c||!m)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_LOAD_MATRIX;memcpy(cmd.f,m,16*sizeof(GLfloat));if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}d=npgl_current_matrix(c);if(d)memcpy(d,m,16*sizeof(GLfloat)); }
static void APIENTRY npgl_glLoadMatrixd(const GLdouble *m) { GLfloat f[16];int i;if(!m)return;for(i=0;i<16;++i)f[i]=(GLfloat)m[i];npgl_glLoadMatrixf(f); }
static void APIENTRY npgl_glMultMatrixf(const GLfloat *m) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c||!m)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_MULT_MATRIX;memcpy(cmd.f,m,16*sizeof(GLfloat));if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}npgl_mult_current(c,m); }
static void APIENTRY npgl_glMultMatrixd(const GLdouble *m) { GLfloat f[16];int i;if(!m)return;for(i=0;i<16;++i)f[i]=(GLfloat)m[i];npgl_glMultMatrixf(f); }
static void APIENTRY npgl_glTranslatef(GLfloat x, GLfloat y, GLfloat z) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;GLfloat m[16];if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_TRANSLATE;cmd.f[0]=x;cmd.f[1]=y;cmd.f[2]=z;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}npgl_identity(m);m[12]=x;m[13]=y;m[14]=z;npgl_mult_current(c,m); }
static void APIENTRY npgl_glTranslated(GLdouble x, GLdouble y, GLdouble z) { npgl_glTranslatef((GLfloat)x,(GLfloat)y,(GLfloat)z); }
static void APIENTRY npgl_glScalef(GLfloat x, GLfloat y, GLfloat z) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;GLfloat m[16];if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_SCALE;cmd.f[0]=x;cmd.f[1]=y;cmd.f[2]=z;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}npgl_identity(m);m[0]=x;m[5]=y;m[10]=z;npgl_mult_current(c,m); }
static void APIENTRY npgl_glScaled(GLdouble x, GLdouble y, GLdouble z) { npgl_glScalef((GLfloat)x,(GLfloat)y,(GLfloat)z); }
static void APIENTRY npgl_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
    NPGL_CONTEXT *ctx=npgl_current();NPGL_LIST_COMMAND cmd;GLfloat m[16];double len,sn,cs,t,rad;if(!ctx)return;len=sqrt((double)x*x+(double)y*y+(double)z*z);if(len==0.0)return;
    if(ctx->compilingList&&!ctx->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_ROTATE;cmd.f[0]=angle;cmd.f[1]=x;cmd.f[2]=y;cmd.f[3]=z;if(!npgl_record_list_command(ctx,&cmd))return;if(ctx->listMode==GL_COMPILE)return;}
    x=(GLfloat)(x/len);y=(GLfloat)(y/len);z=(GLfloat)(z/len);rad=(double)angle*3.14159265358979323846/180.0;sn=sin(rad);cs=cos(rad);t=1.0-cs;
    m[0]=(GLfloat)(x*x*t+cs);m[4]=(GLfloat)(x*y*t-z*sn);m[8]=(GLfloat)(x*z*t+y*sn);m[12]=0;
    m[1]=(GLfloat)(y*x*t+z*sn);m[5]=(GLfloat)(y*y*t+cs);m[9]=(GLfloat)(y*z*t-x*sn);m[13]=0;
    m[2]=(GLfloat)(z*x*t-y*sn);m[6]=(GLfloat)(z*y*t+x*sn);m[10]=(GLfloat)(z*z*t+cs);m[14]=0;
    m[3]=0;m[7]=0;m[11]=0;m[15]=1;npgl_mult_current(ctx,m);
}
static void APIENTRY npgl_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) { npgl_glRotatef((GLfloat)angle,(GLfloat)x,(GLfloat)y,(GLfloat)z); }
static void APIENTRY npgl_glOrtho(GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;GLfloat m[16];if(!c)return;if(r==l||t==b||f==n){npgl_set_error(c,GL_INVALID_VALUE);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_ORTHO;cmd.f[0]=(GLfloat)l;cmd.f[1]=(GLfloat)r;cmd.f[2]=(GLfloat)b;cmd.f[3]=(GLfloat)t;cmd.f[4]=(GLfloat)n;cmd.f[5]=(GLfloat)f;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}npgl_identity(m);m[0]=(GLfloat)(2.0/(r-l));m[5]=(GLfloat)(2.0/(t-b));m[10]=(GLfloat)(-2.0/(f-n));m[12]=(GLfloat)(-(r+l)/(r-l));m[13]=(GLfloat)(-(t+b)/(t-b));m[14]=(GLfloat)(-(f+n)/(f-n));npgl_mult_current(c,m);
}
static void APIENTRY npgl_glFrustum(GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;GLfloat m[16];if(!c)return;if(r==l||t==b||f==n||n<=0.0||f<=0.0){npgl_set_error(c,GL_INVALID_VALUE);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_FRUSTUM;cmd.f[0]=(GLfloat)l;cmd.f[1]=(GLfloat)r;cmd.f[2]=(GLfloat)b;cmd.f[3]=(GLfloat)t;cmd.f[4]=(GLfloat)n;cmd.f[5]=(GLfloat)f;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}memset(m,0,sizeof(m));m[0]=(GLfloat)(2*n/(r-l));m[5]=(GLfloat)(2*n/(t-b));m[8]=(GLfloat)((r+l)/(r-l));m[9]=(GLfloat)((t+b)/(t-b));m[10]=(GLfloat)(-(f+n)/(f-n));m[14]=(GLfloat)(-(2*f*n)/(f-n));m[11]=-1.0f;npgl_mult_current(c,m);
}
static void APIENTRY npgl_glViewport(GLint x, GLint y, GLsizei w, GLsizei h) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(w<0||h<0){npgl_set_error(c,GL_INVALID_VALUE);return;}if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_VIEWPORT;cmd.u[0]=(DWORD)x;cmd.u[1]=(DWORD)y;cmd.u[2]=(DWORD)w;cmd.u[3]=(DWORD)h;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->viewport[0]=x;c->viewport[1]=y;c->viewport[2]=w;c->viewport[3]=h;c->viewportSet=GL_TRUE; }
static void APIENTRY npgl_glDepthRange(GLclampd n, GLclampd f) { NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_DEPTH_RANGE;cmd.f[0]=(GLfloat)n;cmd.f[1]=(GLfloat)f;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}if(n<0)n=0;if(n>1)n=1;if(f<0)f=0;if(f>1)f=1;c->depthNear=n;c->depthFar=f; }

static void APIENTRY npgl_glPushMatrix(void)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_PUSH_MATRIX;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    if(c->matrixMode==GL_MODELVIEW){if(c->modelviewTop>=31){npgl_set_error(c,GL_STACK_OVERFLOW);return;}memcpy(c->modelviewStack[c->modelviewTop++],c->modelview,sizeof(c->modelview));}
    else if(c->matrixMode==GL_PROJECTION){if(c->projectionTop>=7){npgl_set_error(c,GL_STACK_OVERFLOW);return;}memcpy(c->projectionStack[c->projectionTop++],c->projection,sizeof(c->projection));}
    else {if(c->textureTop>=7){npgl_set_error(c,GL_STACK_OVERFLOW);return;}memcpy(c->textureStack[c->textureTop++],c->texture,sizeof(c->texture));}
}
static void APIENTRY npgl_glPopMatrix(void)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_POP_MATRIX;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    if(c->matrixMode==GL_MODELVIEW){if(c->modelviewTop<=0){npgl_set_error(c,GL_STACK_UNDERFLOW);return;}memcpy(c->modelview,c->modelviewStack[--c->modelviewTop],sizeof(c->modelview));}
    else if(c->matrixMode==GL_PROJECTION){if(c->projectionTop<=0){npgl_set_error(c,GL_STACK_UNDERFLOW);return;}memcpy(c->projection,c->projectionStack[--c->projectionTop],sizeof(c->projection));}
    else {if(c->textureTop<=0){npgl_set_error(c,GL_STACK_UNDERFLOW);return;}memcpy(c->texture,c->textureStack[--c->textureTop],sizeof(c->texture));}
}

static void APIENTRY npgl_glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c) return;
    if (c->inBegin || c->renderMode == GL_FEEDBACK) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (size < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    if (type != GL_2D && type != GL_3D && type != GL_3D_COLOR && type != GL_3D_COLOR_TEXTURE && type != GL_4D_COLOR_TEXTURE) { npgl_set_error(c, GL_INVALID_ENUM); return; }
    c->feedbackBuffer = buffer;
    c->feedbackBufferSize = size;
    c->feedbackType = type;
    c->feedbackIndex = 0;
    c->feedbackOverflow = GL_FALSE;
    c->feedbackBufferSet = GL_TRUE;
}

static void APIENTRY npgl_glSelectBuffer(GLsizei size, GLuint *buffer)
{
    NPGL_CONTEXT *c = npgl_current();
    if (!c) return;
    if (c->inBegin || c->renderMode == GL_SELECT) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (size < 0) { npgl_set_error(c, GL_INVALID_VALUE); return; }
    c->selectBuffer = buffer;
    c->selectBufferSize = size;
    c->selectIndex = 0;
    c->selectHits = 0;
    c->selectOverflow = GL_FALSE;
    c->selectHit = GL_FALSE;
    c->selectBufferSet = GL_TRUE;
}

static GLint APIENTRY npgl_glRenderMode(GLenum mode)
{
    NPGL_CONTEXT *c = npgl_current();
    GLenum oldMode;
    GLint result = 0;
    if (!c) return 0;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return 0; }
    if (mode != GL_RENDER && mode != GL_SELECT && mode != GL_FEEDBACK) { npgl_set_error(c, GL_INVALID_ENUM); return 0; }
    if (mode == GL_SELECT && !c->selectBufferSet) { npgl_set_error(c, GL_INVALID_OPERATION); return 0; }
    if (mode == GL_FEEDBACK && !c->feedbackBufferSet) { npgl_set_error(c, GL_INVALID_OPERATION); return 0; }
    oldMode = c->renderMode;
    if (oldMode == GL_SELECT) {
        npgl_select_flush_hit(c);
        result = c->selectOverflow ? -1 : c->selectHits;
    } else if (oldMode == GL_FEEDBACK) {
        result = c->feedbackOverflow ? -1 : c->feedbackIndex;
        if (result > c->feedbackBufferSize) result = c->feedbackBufferSize;
    }
    c->nameStackDepth = 0;
    c->renderMode = mode;
    if (mode == GL_SELECT) {
        c->selectIndex = 0;
        c->selectHits = 0;
        c->selectOverflow = GL_FALSE;
        c->selectHit = GL_FALSE;
    } else if (mode == GL_FEEDBACK) {
        c->feedbackIndex = 0;
        c->feedbackOverflow = GL_FALSE;
    }
    return result;
}

static void APIENTRY npgl_glInitNames(void)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_LIST_COMMAND cmd;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (c->compilingList && !c->replayingList) {
        memset(&cmd, 0, sizeof(cmd)); cmd.op = NPGL_LIST_OP_INIT_NAMES;
        if (!npgl_record_list_command(c, &cmd)) return;
        if (c->listMode == GL_COMPILE) return;
    }
    if (c->renderMode == GL_SELECT) npgl_select_flush_hit(c);
    c->nameStackDepth = 0;
}

static void APIENTRY npgl_glLoadName(GLuint name)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_LIST_COMMAND cmd;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (c->compilingList && !c->replayingList) {
        memset(&cmd, 0, sizeof(cmd)); cmd.op = NPGL_LIST_OP_LOAD_NAME; cmd.u[0] = name;
        if (!npgl_record_list_command(c, &cmd)) return;
        if (c->listMode == GL_COMPILE) return;
    }
    if (c->nameStackDepth <= 0) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (c->renderMode == GL_SELECT) npgl_select_flush_hit(c);
    c->nameStack[c->nameStackDepth - 1] = name;
}

static void APIENTRY npgl_glPassThrough(GLfloat token)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_LIST_COMMAND cmd;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (c->compilingList && !c->replayingList) {
        memset(&cmd, 0, sizeof(cmd)); cmd.op = NPGL_LIST_OP_PASS_THROUGH; cmd.f[0] = token;
        if (!npgl_record_list_command(c, &cmd)) return;
        if (c->listMode == GL_COMPILE) return;
    }
    if (c->renderMode == GL_FEEDBACK) {
        npgl_feedback_write(c, (GLfloat)GL_PASS_THROUGH_TOKEN);
        npgl_feedback_write(c, token);
    }
}

static void APIENTRY npgl_glPopName(void)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_LIST_COMMAND cmd;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (c->compilingList && !c->replayingList) {
        memset(&cmd, 0, sizeof(cmd)); cmd.op = NPGL_LIST_OP_POP_NAME;
        if (!npgl_record_list_command(c, &cmd)) return;
        if (c->listMode == GL_COMPILE) return;
    }
    if (c->nameStackDepth <= 0) { npgl_set_error(c, GL_STACK_UNDERFLOW); return; }
    if (c->renderMode == GL_SELECT) npgl_select_flush_hit(c);
    --c->nameStackDepth;
}

static void APIENTRY npgl_glPushName(GLuint name)
{
    NPGL_CONTEXT *c = npgl_current();
    NPGL_LIST_COMMAND cmd;
    if (!c) return;
    if (c->inBegin) { npgl_set_error(c, GL_INVALID_OPERATION); return; }
    if (c->compilingList && !c->replayingList) {
        memset(&cmd, 0, sizeof(cmd)); cmd.op = NPGL_LIST_OP_PUSH_NAME; cmd.u[0] = name;
        if (!npgl_record_list_command(c, &cmd)) return;
        if (c->listMode == GL_COMPILE) return;
    }
    if (c->nameStackDepth >= 64) { npgl_set_error(c, GL_STACK_OVERFLOW); return; }
    if (c->renderMode == GL_SELECT) npgl_select_flush_hit(c);
    c->nameStack[c->nameStackDepth++] = name;
}

static void APIENTRY npgl_glPushAttrib(GLbitfield mask);
static void APIENTRY npgl_glPopAttrib(void);

static void npgl_execute_list(NPGL_CONTEXT *c, NPGL_DISPLAY_LIST *list)
{
    DWORD i; GLboolean oldReplay;
    if(!c||!list||!list->defined)return;
    if(c->listCallDepth>=64){npgl_set_error(c,GL_STACK_OVERFLOW);return;}
    ++c->listCallDepth;oldReplay=c->replayingList;c->replayingList=GL_TRUE;
    for(i=0;i<list->commandCount;++i){NPGL_LIST_COMMAND *cmd=&list->commands[i];switch(cmd->op){
    case NPGL_LIST_OP_BEGIN:npgl_glBegin((GLenum)cmd->u[0]);break;
    case NPGL_LIST_OP_END:npgl_glEnd();break;
    case NPGL_LIST_OP_COLOR4F:npgl_glColor4f(cmd->f[0],cmd->f[1],cmd->f[2],cmd->f[3]);break;
    case NPGL_LIST_OP_NORMAL3F:npgl_glNormal3f(cmd->f[0],cmd->f[1],cmd->f[2]);break;
    case NPGL_LIST_OP_TEXCOORD2F:npgl_glTexCoord2f(cmd->f[0],cmd->f[1]);break;
    case NPGL_LIST_OP_TEXCOORD4F:npgl_glTexCoord4f(cmd->f[0],cmd->f[1],cmd->f[2],cmd->f[3]);break;
    case NPGL_LIST_OP_VERTEX4F:npgl_glVertex4f(cmd->f[0],cmd->f[1],cmd->f[2],cmd->f[3]);break;
    case NPGL_LIST_OP_CALL_LIST:{NPGL_DISPLAY_LIST *x=npgl_find_list(c,(GLuint)cmd->u[0]);if(x)npgl_execute_list(c,x);}break;
    case NPGL_LIST_OP_CALL_OFFSET:{NPGL_DISPLAY_LIST *x=npgl_find_list(c,c->listBase+(GLuint)cmd->u[0]);if(x)npgl_execute_list(c,x);}break;
    case NPGL_LIST_OP_LIST_BASE:c->listBase=(GLuint)cmd->u[0];break;
    case NPGL_LIST_OP_MATRIX_MODE:npgl_glMatrixMode((GLenum)cmd->u[0]);break;
    case NPGL_LIST_OP_LOAD_IDENTITY:npgl_glLoadIdentity();break;
    case NPGL_LIST_OP_LOAD_MATRIX:npgl_glLoadMatrixf(cmd->f);break;
    case NPGL_LIST_OP_MULT_MATRIX:npgl_glMultMatrixf(cmd->f);break;
    case NPGL_LIST_OP_TRANSLATE:npgl_glTranslatef(cmd->f[0],cmd->f[1],cmd->f[2]);break;
    case NPGL_LIST_OP_SCALE:npgl_glScalef(cmd->f[0],cmd->f[1],cmd->f[2]);break;
    case NPGL_LIST_OP_ROTATE:npgl_glRotatef(cmd->f[0],cmd->f[1],cmd->f[2],cmd->f[3]);break;
    case NPGL_LIST_OP_PUSH_MATRIX:npgl_glPushMatrix();break;
    case NPGL_LIST_OP_POP_MATRIX:npgl_glPopMatrix();break;
    case NPGL_LIST_OP_ENABLE:npgl_glEnable((GLenum)cmd->u[0]);break;
    case NPGL_LIST_OP_DISABLE:npgl_glDisable((GLenum)cmd->u[0]);break;
    case NPGL_LIST_OP_DEPTH_MASK:npgl_glDepthMask((GLboolean)cmd->u[0]);break;
    case NPGL_LIST_OP_DEPTH_FUNC:npgl_glDepthFunc((GLenum)cmd->u[0]);break;
    case NPGL_LIST_OP_ALPHA_FUNC:npgl_glAlphaFunc((GLenum)cmd->u[0],cmd->f[0]);break;
    case NPGL_LIST_OP_BLEND_FUNC:npgl_glBlendFunc((GLenum)cmd->u[0],(GLenum)cmd->u[1]);break;
    case NPGL_LIST_OP_POINT_SIZE:npgl_glPointSize(cmd->f[0]);break;
    case NPGL_LIST_OP_LINE_WIDTH:npgl_glLineWidth(cmd->f[0]);break;
    case NPGL_LIST_OP_LINE_STIPPLE:npgl_glLineStipple((GLint)cmd->u[0],(GLushort)cmd->u[1]);break;
    case NPGL_LIST_OP_POLYGON_MODE:npgl_glPolygonMode((GLenum)cmd->u[0],(GLenum)cmd->u[1]);break;
    case NPGL_LIST_OP_SHADE_MODEL:npgl_glShadeModel((GLenum)cmd->u[0]);break;
    case NPGL_LIST_OP_CULL_FACE:npgl_glCullFace((GLenum)cmd->u[0]);break;
    case NPGL_LIST_OP_FRONT_FACE:npgl_glFrontFace((GLenum)cmd->u[0]);break;
    case NPGL_LIST_OP_SCISSOR:npgl_glScissor((GLint)cmd->u[0],(GLint)cmd->u[1],(GLsizei)cmd->u[2],(GLsizei)cmd->u[3]);break;
    case NPGL_LIST_OP_HINT:npgl_glHint((GLenum)cmd->u[0],(GLenum)cmd->u[1]);break;
    case NPGL_LIST_OP_CLEAR_COLOR:npgl_glClearColor(cmd->f[0],cmd->f[1],cmd->f[2],cmd->f[3]);break;
    case NPGL_LIST_OP_CLEAR_DEPTH:npgl_glClearDepth((GLdouble)cmd->f[0]);break;
    case NPGL_LIST_OP_CLEAR_STENCIL:npgl_glClearStencil((GLint)cmd->u[0]);break;
    case NPGL_LIST_OP_STENCIL_FUNC:npgl_glStencilFunc((GLenum)cmd->u[0],(GLint)cmd->u[1],(GLuint)cmd->u[2]);break;
    case NPGL_LIST_OP_STENCIL_MASK:npgl_glStencilMask((GLuint)cmd->u[0]);break;
    case NPGL_LIST_OP_STENCIL_OP:npgl_glStencilOp((GLenum)cmd->u[0],(GLenum)cmd->u[1],(GLenum)cmd->u[2]);break;
    case NPGL_LIST_OP_VIEWPORT:npgl_glViewport((GLint)cmd->u[0],(GLint)cmd->u[1],(GLsizei)cmd->u[2],(GLsizei)cmd->u[3]);break;
    case NPGL_LIST_OP_DEPTH_RANGE:npgl_glDepthRange((GLdouble)cmd->f[0],(GLdouble)cmd->f[1]);break;
    case NPGL_LIST_OP_ORTHO:npgl_glOrtho(cmd->f[0],cmd->f[1],cmd->f[2],cmd->f[3],cmd->f[4],cmd->f[5]);break;
    case NPGL_LIST_OP_FRUSTUM:npgl_glFrustum(cmd->f[0],cmd->f[1],cmd->f[2],cmd->f[3],cmd->f[4],cmd->f[5]);break;
    case NPGL_LIST_OP_CLEAR:npgl_glClear((GLbitfield)cmd->u[0]);break;
    case NPGL_LIST_OP_COLOR_MATERIAL:npgl_glColorMaterial((GLenum)cmd->u[0],(GLenum)cmd->u[1]);break;
    case NPGL_LIST_OP_FOG:npgl_glFogfv((GLenum)cmd->u[0],cmd->f);break;
    case NPGL_LIST_OP_LIGHT:npgl_glLightfv((GLenum)cmd->u[0],(GLenum)cmd->u[1],cmd->f);break;
    case NPGL_LIST_OP_LIGHT_MODEL:npgl_glLightModelfv((GLenum)cmd->u[0],cmd->f);break;
    case NPGL_LIST_OP_MATERIAL:npgl_glMaterialfv((GLenum)cmd->u[0],(GLenum)cmd->u[1],cmd->f);break;
    case NPGL_LIST_OP_TEX_PARAMETERI:npgl_glTexParameteri((GLenum)cmd->u[0],(GLenum)cmd->u[1],(GLint)cmd->u[2]);break;
    case NPGL_LIST_OP_TEX_ENVI:npgl_glTexEnvi((GLenum)cmd->u[0],(GLenum)cmd->u[1],(GLint)cmd->u[2]);break;
    case NPGL_LIST_OP_BIND_TEXTURE:npgl_glBindTexture((GLenum)cmd->u[0],(GLuint)cmd->u[1]);break;
    case NPGL_LIST_OP_DRAW_BUFFER:npgl_glDrawBuffer((GLenum)cmd->u[0]);break;
    case NPGL_LIST_OP_COLOR_MASK:npgl_glColorMask((GLboolean)cmd->u[0],(GLboolean)cmd->u[1],(GLboolean)cmd->u[2],(GLboolean)cmd->u[3]);break;
    case NPGL_LIST_OP_CLEAR_INDEX:npgl_glClearIndex(cmd->f[0]);break;
    case NPGL_LIST_OP_INDEX_MASK:npgl_glIndexMask((GLuint)cmd->u[0]);break;
    case NPGL_LIST_OP_INDEX:npgl_set_index(cmd->f[0]);break;
    case NPGL_LIST_OP_CLEAR_ACCUM:npgl_glClearAccum(cmd->f[0],cmd->f[1],cmd->f[2],cmd->f[3]);break;
    case NPGL_LIST_OP_ACCUM:npgl_glAccum((GLenum)cmd->u[0],cmd->f[0]);break;
    case NPGL_LIST_OP_PUSH_ATTRIB:npgl_glPushAttrib((GLbitfield)cmd->u[0]);break;
    case NPGL_LIST_OP_POP_ATTRIB:npgl_glPopAttrib();break;
    case NPGL_LIST_OP_EDGE_FLAG:npgl_glEdgeFlag(cmd->u[0]?GL_TRUE:GL_FALSE);break;
    case NPGL_LIST_OP_BITMAP:npgl_execute_bitmap_mask(c,(GLsizei)cmd->u[0],(GLsizei)cmd->u[1],cmd->f[0],cmd->f[1],cmd->f[2],cmd->f[3],(const GLubyte *)cmd->u[2]);break;
    case NPGL_LIST_OP_PIXEL_TRANSFER:npgl_glPixelTransferf((GLenum)cmd->u[0],cmd->f[0]);break;
    case NPGL_LIST_OP_PIXEL_MAP:npgl_glPixelMapfv((GLenum)cmd->u[0],(GLint)cmd->u[1],(const GLfloat *)cmd->u[2]);break;
    case NPGL_LIST_OP_CLIP_PLANE:{GLdouble equation[4];memcpy(equation,cmd->f,4*sizeof(GLdouble));npgl_glClipPlane((GLenum)cmd->u[0],equation);}break;
    case NPGL_LIST_OP_LOGIC_OP:npgl_glLogicOp((GLenum)cmd->u[0]);break;
    case NPGL_LIST_OP_MAP1:npgl_apply_map1(c,(const NPGL_LIST_EVAL_MAP *)cmd->u[0]);break;
    case NPGL_LIST_OP_MAP2:npgl_apply_map2(c,(const NPGL_LIST_EVAL_MAP *)cmd->u[0]);break;
    case NPGL_LIST_OP_MAP_GRID1:npgl_glMapGrid1f((GLint)cmd->u[0],cmd->f[0],cmd->f[1]);break;
    case NPGL_LIST_OP_MAP_GRID2:npgl_glMapGrid2f((GLint)cmd->u[0],cmd->f[0],cmd->f[1],(GLint)cmd->u[1],cmd->f[2],cmd->f[3]);break;
    case NPGL_LIST_OP_EVAL_COORD1:npgl_eval_coord1_internal(c,cmd->f[0]);break;
    case NPGL_LIST_OP_EVAL_COORD2:npgl_eval_coord2_internal(c,cmd->f[0],cmd->f[1]);break;
    case NPGL_LIST_OP_EVAL_MESH1:npgl_eval_mesh1_execute(c,(GLenum)cmd->u[0],(GLint)cmd->u[1],(GLint)cmd->u[2]);break;
    case NPGL_LIST_OP_EVAL_MESH2:npgl_eval_mesh2_execute(c,(GLenum)cmd->u[0],(GLint)cmd->u[1],(GLint)cmd->u[2],(GLint)cmd->u[3],(GLint)cmd->f[0]);break;
    case NPGL_LIST_OP_EVAL_POINT1:{GLfloat u=npgl_eval_grid_value((GLint)cmd->u[0],c->map1GridSegments,c->map1GridDomain[0],c->map1GridDomain[1]);npgl_eval_coord1_internal(c,u);}break;
    case NPGL_LIST_OP_EVAL_POINT2:{GLfloat u=npgl_eval_grid_value((GLint)cmd->u[0],c->map2GridSegments[0],c->map2GridDomain[0],c->map2GridDomain[1]);GLfloat v=npgl_eval_grid_value((GLint)cmd->u[1],c->map2GridSegments[1],c->map2GridDomain[2],c->map2GridDomain[3]);npgl_eval_coord2_internal(c,u,v);}break;
    case NPGL_LIST_OP_INIT_NAMES:npgl_glInitNames();break;
    case NPGL_LIST_OP_LOAD_NAME:npgl_glLoadName((GLuint)cmd->u[0]);break;
    case NPGL_LIST_OP_PASS_THROUGH:npgl_glPassThrough(cmd->f[0]);break;
    case NPGL_LIST_OP_POP_NAME:npgl_glPopName();break;
    case NPGL_LIST_OP_PUSH_NAME:npgl_glPushName((GLuint)cmd->u[0]);break;
    default:break;}}
    c->replayingList=oldReplay;--c->listCallDepth;
}

static void APIENTRY npgl_glNewList(GLuint list, GLenum mode)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_DISPLAY_LIST *obj;if(!c)return;if(c->inBegin||c->compilingList){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(!list){npgl_set_error(c,GL_INVALID_VALUE);return;}if(mode!=GL_COMPILE&&mode!=GL_COMPILE_AND_EXECUTE){npgl_set_error(c,GL_INVALID_ENUM);return;}obj=npgl_create_list(c,list);if(!obj){npgl_set_error(c,GL_OUT_OF_MEMORY);return;}if(obj->hostCached)npgl_host_delete_lists(c,list,1);npgl_clear_list(obj);c->compilingList=obj;c->listMode=mode;c->listCompileInBegin=GL_FALSE;
}
static void APIENTRY npgl_glEndList(void)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_DISPLAY_LIST *obj;if(!c)return;if(!c->compilingList||c->inBegin||c->listCompileInBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}obj=c->compilingList;obj->defined=GL_TRUE;c->compilingList=NULL;c->listMode=0;c->listCompileInBegin=GL_FALSE;npgl_upload_host_list(c,obj);
}
static void APIENTRY npgl_glCallList(GLuint list)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;NPGL_DISPLAY_LIST *obj;GLuint hostList;if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_CALL_LIST;cmd.u[0]=list;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}obj=npgl_find_list(c,list);if(!obj||!obj->defined)return;if(obj->hostCached&&!c->replayingList&&c->renderMode==GL_RENDER){hostList=list;if(npgl_execute_host_lists(c,&hostList,1)){npgl_apply_host_list_final(c,obj);return;}obj->hostCached=GL_FALSE;}npgl_execute_list(c,obj);
}
static GLuint npgl_list_value(GLenum type,const GLvoid *lists,GLsizei index,BOOL *ok)
{
    const GLubyte *b=(const GLubyte *)lists;*ok=TRUE;switch(type){case GL_BYTE:return (GLuint)(GLint)((const GLbyte *)lists)[index];case GL_UNSIGNED_BYTE:return ((const GLubyte *)lists)[index];case GL_SHORT:return (GLuint)(GLint)((const GLshort *)lists)[index];case GL_UNSIGNED_SHORT:return ((const GLushort *)lists)[index];case GL_INT:return (GLuint)((const GLint *)lists)[index];case GL_UNSIGNED_INT:return ((const GLuint *)lists)[index];case GL_FLOAT:return (GLuint)((const GLfloat *)lists)[index];case GL_2_BYTES:return ((GLuint)b[index*2]<<8)|b[index*2+1];case GL_3_BYTES:return ((GLuint)b[index*3]<<16)|((GLuint)b[index*3+1]<<8)|b[index*3+2];case GL_4_BYTES:return ((GLuint)b[index*4]<<24)|((GLuint)b[index*4+1]<<16)|((GLuint)b[index*4+2]<<8)|b[index*4+3];default:*ok=FALSE;return 0;}
}
static void APIENTRY npgl_glCallLists(GLsizei n, GLenum type, const GLvoid *lists)
{
    NPGL_CONTEXT *c=npgl_current();GLsizei i;BOOL ok;GLuint value;NPGL_LIST_COMMAND cmd;GLuint *hostLists;DWORD hostCount;BOOL allCached;NPGL_DISPLAY_LIST *obj;
    if(!c)return;
    if(n<0){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(n&&!lists){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(c->compilingList&&!c->replayingList){
        for(i=0;i<n;++i){value=npgl_list_value(type,lists,i,&ok);if(!ok){npgl_set_error(c,GL_INVALID_ENUM);return;}memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_CALL_OFFSET;cmd.u[0]=value;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode!=GL_COMPILE){obj=npgl_find_list(c,c->listBase+value);if(obj)npgl_execute_list(c,obj);}}
        if(c->listMode==GL_COMPILE)return;
        return;
    }
    if(!n)return;
    hostLists=(GLuint *)HeapAlloc(GetProcessHeap(),0,(SIZE_T)n*sizeof(GLuint));
    hostCount=0;allCached=(hostLists&&c->renderMode==GL_RENDER)?TRUE:FALSE;
    if(allCached){
        for(i=0;i<n;++i){value=npgl_list_value(type,lists,i,&ok);if(!ok){HeapFree(GetProcessHeap(),0,hostLists);npgl_set_error(c,GL_INVALID_ENUM);return;}obj=npgl_find_list(c,c->listBase+value);if(!obj||!obj->defined)continue;if(!obj->hostCached){allCached=FALSE;break;}hostLists[hostCount++]=obj->name;}
    }
    if(allCached){
        if(!hostCount||npgl_execute_host_lists(c,hostLists,hostCount)){
            for(i=0;i<n;++i){value=npgl_list_value(type,lists,i,&ok);obj=npgl_find_list(c,c->listBase+value);if(obj&&obj->defined)npgl_apply_host_list_final(c,obj);}
            HeapFree(GetProcessHeap(),0,hostLists);return;
        }
        for(i=0;i<(GLsizei)hostCount;++i){obj=npgl_find_list(c,hostLists[i]);if(obj)obj->hostCached=GL_FALSE;}
    }
    if(hostLists)HeapFree(GetProcessHeap(),0,hostLists);
    for(i=0;i<n;++i){value=npgl_list_value(type,lists,i,&ok);if(!ok){npgl_set_error(c,GL_INVALID_ENUM);return;}obj=npgl_find_list(c,c->listBase+value);if(obj)npgl_execute_list(c,obj);}
}

static void APIENTRY npgl_glDeleteLists(GLuint list, GLsizei range)
{
    NPGL_CONTEXT *c=npgl_current();GLsizei i;if(!c)return;if(c->inBegin||c->compilingList){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(range<0){npgl_set_error(c,GL_INVALID_VALUE);return;}for(i=0;i<range;++i)npgl_delete_list_name(c,list+(GLuint)i);
}
static GLuint APIENTRY npgl_glGenLists(GLsizei range)
{
    NPGL_CONTEXT *c=npgl_current();GLuint name;GLsizei i;BOOL freeRange;if(!c)return 0;if(c->inBegin||c->compilingList){npgl_set_error(c,GL_INVALID_OPERATION);return 0;}if(range<0){npgl_set_error(c,GL_INVALID_VALUE);return 0;}if(range==0)return 0;for(name=c->nextListName?c->nextListName:1;name<0xffffffffUL-(GLuint)range;++name){freeRange=TRUE;for(i=0;i<range;++i)if(npgl_find_list(c,name+(GLuint)i)){freeRange=FALSE;break;}if(freeRange){c->nextListName=name+(GLuint)range;return name;}}return 0;
}
static void APIENTRY npgl_glListBase(GLuint base)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_LIST_BASE;cmd.u[0]=base;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}c->listBase=base;
}
static GLboolean APIENTRY npgl_glIsList(GLuint list)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_DISPLAY_LIST *obj;if(!c)return GL_FALSE;obj=npgl_find_list(c,list);return (obj&&obj->defined)?GL_TRUE:GL_FALSE;
}

static void npgl_save_attrib(NPGL_CONTEXT *c, NPGL_ATTRIB_STATE *a, GLbitfield mask)
{
    if(!c||!a)return;
    memset(a,0,sizeof(*a));a->mask=mask;
    memcpy(a->currentColor,c->currentColor,sizeof(a->currentColor));a->currentIndex=c->currentIndex;a->currentEdgeFlag=c->currentEdgeFlag;memcpy(a->currentNormal,c->currentNormal,sizeof(a->currentNormal));memcpy(a->currentTexCoord,c->currentTexCoord,sizeof(a->currentTexCoord));
    memcpy(a->rasterPosition,c->rasterPosition,sizeof(a->rasterPosition));memcpy(a->rasterColor,c->rasterColor,sizeof(a->rasterColor));memcpy(a->rasterTexCoord,c->rasterTexCoord,sizeof(a->rasterTexCoord));a->rasterDistance=c->rasterDistance;a->rasterValid=c->rasterValid;
    a->pointSize=c->pointSize;a->lineWidth=c->lineWidth;a->lineStipple=c->lineStipple;a->lineStippleFactor=c->lineStippleFactor;a->lineStipplePattern=c->lineStipplePattern;
    a->cullFaceEnable=c->cullFaceEnable;a->cullFace=c->cullFace;a->frontFace=c->frontFace;a->polygonModeFront=c->polygonModeFront;a->polygonModeBack=c->polygonModeBack;a->polygonStipple=c->polygonStipple;memcpy(a->polygonStipplePattern,c->polygonStipplePattern,sizeof(a->polygonStipplePattern));
    a->readBuffer=c->readBuffer;a->pixelZoomX=c->pixelZoomX;a->pixelZoomY=c->pixelZoomY;a->mapColor=c->mapColor;a->mapStencil=c->mapStencil;a->indexShift=c->indexShift;a->indexOffset=c->indexOffset;a->redScale=c->redScale;a->redBias=c->redBias;a->greenScale=c->greenScale;a->greenBias=c->greenBias;a->blueScale=c->blueScale;a->blueBias=c->blueBias;a->alphaScale=c->alphaScale;a->alphaBias=c->alphaBias;a->depthScale=c->depthScale;a->depthBias=c->depthBias;memcpy(a->pixelMaps,c->pixelMaps,sizeof(a->pixelMaps));
    a->lighting=c->lighting;a->normalize=c->normalize;a->colorMaterial=c->colorMaterial;a->colorMaterialFace=c->colorMaterialFace;a->colorMaterialMode=c->colorMaterialMode;memcpy(a->lightModelAmbient,c->lightModelAmbient,sizeof(a->lightModelAmbient));a->lightModelLocalViewer=c->lightModelLocalViewer;a->lightModelTwoSide=c->lightModelTwoSide;memcpy(a->lights,c->lights,sizeof(a->lights));a->material=c->material;
    a->fog=c->fog;a->fogMode=c->fogMode;memcpy(a->fogColor,c->fogColor,sizeof(a->fogColor));a->fogDensity=c->fogDensity;a->fogStart=c->fogStart;a->fogEnd=c->fogEnd;
    a->depthTest=c->depthTest;a->depthWrite=c->depthWrite;a->depthFunc=c->depthFunc;a->clearDepth=c->clearDepth;memcpy(a->clearAccum,c->clearAccum,sizeof(a->clearAccum));
    a->stencilTest=c->stencilTest;a->stencilFunc=c->stencilFunc;a->stencilRef=c->stencilRef;a->stencilValueMask=c->stencilValueMask;a->stencilWriteMask=c->stencilWriteMask;a->stencilFail=c->stencilFail;a->stencilZFail=c->stencilZFail;a->stencilPass=c->stencilPass;a->clearStencil=c->clearStencil;
    memcpy(a->viewport,c->viewport,sizeof(a->viewport));a->depthNear=c->depthNear;a->depthFar=c->depthFar;a->matrixMode=c->matrixMode;
    a->blend=c->blend;a->srcBlend=c->srcBlend;a->destBlend=c->destBlend;a->alphaTest=c->alphaTest;a->alphaFunc=c->alphaFunc;a->alphaRef=c->alphaRef;memcpy(a->clearColor,c->clearColor,sizeof(a->clearColor));a->clearIndex=c->clearIndex;a->drawBuffer=c->drawBuffer;memcpy(a->colorMask,c->colorMask,sizeof(a->colorMask));a->indexMask=c->indexMask;a->colorLogicOp=c->colorLogicOp;a->indexLogicOp=c->indexLogicOp;a->logicOpMode=c->logicOpMode;memcpy(a->clipPlaneEnabled,c->clipPlaneEnabled,sizeof(a->clipPlaneEnabled));memcpy(a->clipPlane,c->clipPlane,sizeof(a->clipPlane));
    a->perspectiveHint=c->perspectiveHint;a->pointSmoothHint=c->pointSmoothHint;a->lineSmoothHint=c->lineSmoothHint;a->polygonSmoothHint=c->polygonSmoothHint;a->fogHint=c->fogHint;a->listBase=c->listBase;
    a->texture1D=c->texture1D;a->texture2D=c->texture2D;a->textureEnvMode=c->textureEnvMode;a->boundTexture1D=c->boundTexture1D?c->boundTexture1D->name:0;a->boundTexture2D=c->boundTexture2D?c->boundTexture2D->name:0;memcpy(a->texGenEnabled,c->texGenEnabled,sizeof(a->texGenEnabled));memcpy(a->texGenMode,c->texGenMode,sizeof(a->texGenMode));memcpy(a->texGenObjectPlane,c->texGenObjectPlane,sizeof(a->texGenObjectPlane));memcpy(a->texGenEyePlane,c->texGenEyePlane,sizeof(a->texGenEyePlane));
    {int i;for(i=0;i<NPGL_EVAL_TARGET_COUNT;++i){a->evalMap1Enabled[i]=c->evalMap1[i].enabled;a->evalMap2Enabled[i]=c->evalMap2[i].enabled;}}a->autoNormal=c->autoNormal;a->map1GridSegments=c->map1GridSegments;memcpy(a->map1GridDomain,c->map1GridDomain,sizeof(a->map1GridDomain));memcpy(a->map2GridSegments,c->map2GridSegments,sizeof(a->map2GridSegments));memcpy(a->map2GridDomain,c->map2GridDomain,sizeof(a->map2GridDomain));
    a->scissorTest=c->scissorTest;memcpy(a->scissorBox,c->scissorBox,sizeof(a->scissorBox));a->scissorSet=c->scissorSet;
}

static NPGL_TEXTURE_OBJECT *npgl_restore_texture_binding(NPGL_CONTEXT *c, GLenum target, GLuint name)
{
    NPGL_TEXTURE_OBJECT *obj;
    if(!c)return NULL;
    if(!name)return target==GL_TEXTURE_1D?&c->defaultTexture1D:&c->defaultTexture2D;
    obj=npgl_find_texture(c,name);
    if(!obj||obj->target!=target)return target==GL_TEXTURE_1D?&c->defaultTexture1D:&c->defaultTexture2D;
    return obj;
}

static void npgl_restore_attrib(NPGL_CONTEXT *c, const NPGL_ATTRIB_STATE *a)
{
    GLbitfield m;if(!c||!a)return;m=a->mask;
    if(m&GL_CURRENT_BIT){memcpy(c->currentColor,a->currentColor,sizeof(c->currentColor));c->currentIndex=a->currentIndex;c->currentEdgeFlag=a->currentEdgeFlag;memcpy(c->currentNormal,a->currentNormal,sizeof(c->currentNormal));memcpy(c->currentTexCoord,a->currentTexCoord,sizeof(c->currentTexCoord));memcpy(c->rasterPosition,a->rasterPosition,sizeof(c->rasterPosition));memcpy(c->rasterColor,a->rasterColor,sizeof(c->rasterColor));memcpy(c->rasterTexCoord,a->rasterTexCoord,sizeof(c->rasterTexCoord));c->rasterDistance=a->rasterDistance;c->rasterValid=a->rasterValid;}
    if(m&GL_POINT_BIT)c->pointSize=a->pointSize;
    if(m&GL_LINE_BIT){c->lineWidth=a->lineWidth;c->lineStipple=a->lineStipple;c->lineStippleFactor=a->lineStippleFactor;c->lineStipplePattern=a->lineStipplePattern;}
    if(m&GL_POLYGON_BIT){c->cullFaceEnable=a->cullFaceEnable;c->cullFace=a->cullFace;c->frontFace=a->frontFace;c->polygonModeFront=a->polygonModeFront;c->polygonModeBack=a->polygonModeBack;}
    if(m&GL_POLYGON_STIPPLE_BIT){c->polygonStipple=a->polygonStipple;memcpy(c->polygonStipplePattern,a->polygonStipplePattern,sizeof(c->polygonStipplePattern));}
    if(m&GL_PIXEL_MODE_BIT){c->readBuffer=a->readBuffer;c->pixelZoomX=a->pixelZoomX;c->pixelZoomY=a->pixelZoomY;c->mapColor=a->mapColor;c->mapStencil=a->mapStencil;c->indexShift=a->indexShift;c->indexOffset=a->indexOffset;c->redScale=a->redScale;c->redBias=a->redBias;c->greenScale=a->greenScale;c->greenBias=a->greenBias;c->blueScale=a->blueScale;c->blueBias=a->blueBias;c->alphaScale=a->alphaScale;c->alphaBias=a->alphaBias;c->depthScale=a->depthScale;c->depthBias=a->depthBias;memcpy(c->pixelMaps,a->pixelMaps,sizeof(c->pixelMaps));}
    if(m&GL_LIGHTING_BIT){c->lighting=a->lighting;c->colorMaterial=a->colorMaterial;c->colorMaterialFace=a->colorMaterialFace;c->colorMaterialMode=a->colorMaterialMode;memcpy(c->lightModelAmbient,a->lightModelAmbient,sizeof(c->lightModelAmbient));c->lightModelLocalViewer=a->lightModelLocalViewer;c->lightModelTwoSide=a->lightModelTwoSide;memcpy(c->lights,a->lights,sizeof(c->lights));c->material=a->material;}
    if(m&GL_FOG_BIT){c->fog=a->fog;c->fogMode=a->fogMode;memcpy(c->fogColor,a->fogColor,sizeof(c->fogColor));c->fogDensity=a->fogDensity;c->fogStart=a->fogStart;c->fogEnd=a->fogEnd;}
    if(m&GL_DEPTH_BUFFER_BIT){c->depthTest=a->depthTest;c->depthWrite=a->depthWrite;c->depthFunc=a->depthFunc;c->clearDepth=a->clearDepth;}
    if(m&GL_ACCUM_BUFFER_BIT)memcpy(c->clearAccum,a->clearAccum,sizeof(c->clearAccum));
    if(m&GL_STENCIL_BUFFER_BIT){c->stencilTest=a->stencilTest;c->stencilFunc=a->stencilFunc;c->stencilRef=a->stencilRef;c->stencilValueMask=a->stencilValueMask;c->stencilWriteMask=a->stencilWriteMask;c->stencilFail=a->stencilFail;c->stencilZFail=a->stencilZFail;c->stencilPass=a->stencilPass;c->clearStencil=a->clearStencil;}
    if(m&GL_VIEWPORT_BIT){memcpy(c->viewport,a->viewport,sizeof(c->viewport));c->depthNear=a->depthNear;c->depthFar=a->depthFar;}
    if(m&GL_TRANSFORM_BIT){c->matrixMode=a->matrixMode;c->normalize=a->normalize;memcpy(c->clipPlane,a->clipPlane,sizeof(c->clipPlane));}
    if(m&GL_ENABLE_BIT){int i;c->depthTest=a->depthTest;c->blend=a->blend;c->alphaTest=a->alphaTest;c->cullFaceEnable=a->cullFaceEnable;c->texture1D=a->texture1D;c->texture2D=a->texture2D;c->lighting=a->lighting;c->normalize=a->normalize;c->colorMaterial=a->colorMaterial;c->fog=a->fog;c->scissorTest=a->scissorTest;c->stencilTest=a->stencilTest;c->lineStipple=a->lineStipple;c->polygonStipple=a->polygonStipple;for(i=0;i<4;++i)c->texGenEnabled[i]=a->texGenEnabled[i];for(i=0;i<6;++i)c->clipPlaneEnabled[i]=a->clipPlaneEnabled[i];c->colorLogicOp=a->colorLogicOp;c->indexLogicOp=a->indexLogicOp;c->autoNormal=a->autoNormal;for(i=0;i<NPGL_EVAL_TARGET_COUNT;++i){c->evalMap1[i].enabled=a->evalMap1Enabled[i];c->evalMap2[i].enabled=a->evalMap2Enabled[i];}for(i=0;i<8;++i)c->lights[i].enabled=a->lights[i].enabled;}
    if(m&GL_EVAL_BIT){int i;for(i=0;i<NPGL_EVAL_TARGET_COUNT;++i){c->evalMap1[i].enabled=a->evalMap1Enabled[i];c->evalMap2[i].enabled=a->evalMap2Enabled[i];}c->autoNormal=a->autoNormal;c->map1GridSegments=a->map1GridSegments;memcpy(c->map1GridDomain,a->map1GridDomain,sizeof(c->map1GridDomain));memcpy(c->map2GridSegments,a->map2GridSegments,sizeof(c->map2GridSegments));memcpy(c->map2GridDomain,a->map2GridDomain,sizeof(c->map2GridDomain));}
    if(m&GL_COLOR_BUFFER_BIT){c->blend=a->blend;c->srcBlend=a->srcBlend;c->destBlend=a->destBlend;c->alphaTest=a->alphaTest;c->alphaFunc=a->alphaFunc;c->alphaRef=a->alphaRef;memcpy(c->clearColor,a->clearColor,sizeof(c->clearColor));c->clearIndex=a->clearIndex;c->drawBuffer=a->drawBuffer;memcpy(c->colorMask,a->colorMask,sizeof(c->colorMask));c->indexMask=a->indexMask;c->colorLogicOp=a->colorLogicOp;c->indexLogicOp=a->indexLogicOp;c->logicOpMode=a->logicOpMode;}
    if(m&GL_HINT_BIT){c->perspectiveHint=a->perspectiveHint;c->pointSmoothHint=a->pointSmoothHint;c->lineSmoothHint=a->lineSmoothHint;c->polygonSmoothHint=a->polygonSmoothHint;c->fogHint=a->fogHint;}
    if(m&GL_LIST_BIT)c->listBase=a->listBase;
    if(m&GL_TEXTURE_BIT){c->texture1D=a->texture1D;c->texture2D=a->texture2D;c->textureEnvMode=a->textureEnvMode;c->boundTexture1D=npgl_restore_texture_binding(c,GL_TEXTURE_1D,a->boundTexture1D);c->boundTexture2D=npgl_restore_texture_binding(c,GL_TEXTURE_2D,a->boundTexture2D);memcpy(c->texGenEnabled,a->texGenEnabled,sizeof(c->texGenEnabled));memcpy(c->texGenMode,a->texGenMode,sizeof(c->texGenMode));memcpy(c->texGenObjectPlane,a->texGenObjectPlane,sizeof(c->texGenObjectPlane));memcpy(c->texGenEyePlane,a->texGenEyePlane,sizeof(c->texGenEyePlane));}
    if(m&GL_SCISSOR_BIT){c->scissorTest=a->scissorTest;memcpy(c->scissorBox,a->scissorBox,sizeof(c->scissorBox));c->scissorSet=a->scissorSet;}
}

static void APIENTRY npgl_glPushAttrib(GLbitfield mask)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}if(mask&~GL_ALL_ATTRIB_BITS){npgl_set_error(c,GL_INVALID_VALUE);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_PUSH_ATTRIB;cmd.u[0]=(DWORD)mask;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    if(c->attribTop>=16){npgl_set_error(c,GL_STACK_OVERFLOW);return;}npgl_save_attrib(c,&c->attribStack[c->attribTop],mask);++c->attribTop;
}
static void APIENTRY npgl_glPopAttrib(void)
{
    NPGL_CONTEXT *c=npgl_current();NPGL_LIST_COMMAND cmd;if(!c)return;if(c->inBegin){npgl_set_error(c,GL_INVALID_OPERATION);return;}
    if(c->compilingList&&!c->replayingList){memset(&cmd,0,sizeof(cmd));cmd.op=NPGL_LIST_OP_POP_ATTRIB;if(!npgl_record_list_command(c,&cmd))return;if(c->listMode==GL_COMPILE)return;}
    if(c->attribTop<=0){npgl_set_error(c,GL_STACK_UNDERFLOW);return;}--c->attribTop;npgl_restore_attrib(c,&c->attribStack[c->attribTop]);
}

static GLenum APIENTRY npgl_glGetError(void) { NPGL_CONTEXT *c=npgl_current();GLenum e;if(!c)return 0;e=c->error;c->error=0;return e; }
static const GLubyte * APIENTRY npgl_glGetString(GLenum name)
{
    NPGL_CONTEXT *c=npgl_current();if(!c)return NULL;
    switch(name){case GL_VENDOR:return (const GLubyte *)"Neko Project II";case GL_RENDERER:return (const GLubyte *)"NPDISP software rasterizer";case GL_VERSION:return (const GLubyte *)"1.1 NPDISP compatibility layer";case GL_EXTENSIONS:return (const GLubyte *)"";default:npgl_set_error(c,GL_INVALID_ENUM);return NULL;}
}
static void APIENTRY npgl_glGetFloatv(GLenum pname, GLfloat *p)
{
    NPGL_CONTEXT *c=npgl_current();int i,ei,ed;if(!c||!p)return;
    ei=npgl_eval_cap_index(pname,&ed);if(ei>=0){p[0]=(ed==1?c->evalMap1[ei].enabled:c->evalMap2[ei].enabled)?1.0f:0.0f;return;}if(pname==GL_AUTO_NORMAL){p[0]=c->autoNormal?1.0f:0.0f;return;}
    switch(pname){case GL_CURRENT_COLOR:memcpy(p,c->currentColor,4*sizeof(GLfloat));break;case GL_CURRENT_INDEX:p[0]=c->currentIndex;break;case GL_EDGE_FLAG:p[0]=c->currentEdgeFlag?1.0f:0.0f;break;case GL_ACCUM_CLEAR_VALUE:memcpy(p,c->clearAccum,4*sizeof(GLfloat));break;case GL_MODELVIEW_MATRIX:memcpy(p,c->modelview,16*sizeof(GLfloat));break;case GL_PROJECTION_MATRIX:memcpy(p,c->projection,16*sizeof(GLfloat));break;case GL_TEXTURE_MATRIX:memcpy(p,c->texture,16*sizeof(GLfloat));break;case GL_DEPTH_RANGE:p[0]=(GLfloat)c->depthNear;p[1]=(GLfloat)c->depthFar;break;case GL_FOG_COLOR:memcpy(p,c->fogColor,4*sizeof(GLfloat));break;case GL_FOG_DENSITY:p[0]=c->fogDensity;break;case GL_FOG_START:p[0]=c->fogStart;break;case GL_FOG_END:p[0]=c->fogEnd;break;case GL_LIGHT_MODEL_AMBIENT:memcpy(p,c->lightModelAmbient,4*sizeof(GLfloat));break;case GL_POINT_SIZE:p[0]=c->pointSize;break;case GL_LINE_WIDTH:p[0]=c->lineWidth;break;case GL_POINT_SIZE_RANGE:p[0]=1.0f;p[1]=64.0f;break;case GL_POINT_SIZE_GRANULARITY:p[0]=1.0f;break;case GL_LINE_WIDTH_RANGE:p[0]=1.0f;p[1]=64.0f;break;case GL_LINE_WIDTH_GRANULARITY:p[0]=1.0f;break;case GL_CURRENT_RASTER_POSITION:memcpy(p,c->rasterPosition,4*sizeof(GLfloat));break;case GL_CURRENT_RASTER_COLOR:memcpy(p,c->rasterColor,4*sizeof(GLfloat));break;case GL_CURRENT_RASTER_TEXTURE_COORDS:memcpy(p,c->rasterTexCoord,4*sizeof(GLfloat));break;case GL_CURRENT_RASTER_DISTANCE:p[0]=c->rasterDistance;break;case GL_ZOOM_X:p[0]=c->pixelZoomX;break;case GL_ZOOM_Y:p[0]=c->pixelZoomY;break;case GL_MAP_COLOR:p[0]=c->mapColor?1.0f:0.0f;break;case GL_MAP_STENCIL:p[0]=c->mapStencil?1.0f:0.0f;break;case GL_INDEX_SHIFT:p[0]=(GLfloat)c->indexShift;break;case GL_INDEX_OFFSET:p[0]=(GLfloat)c->indexOffset;break;case GL_RED_SCALE:p[0]=c->redScale;break;case GL_RED_BIAS:p[0]=c->redBias;break;case GL_GREEN_SCALE:p[0]=c->greenScale;break;case GL_GREEN_BIAS:p[0]=c->greenBias;break;case GL_BLUE_SCALE:p[0]=c->blueScale;break;case GL_BLUE_BIAS:p[0]=c->blueBias;break;case GL_ALPHA_SCALE:p[0]=c->alphaScale;break;case GL_ALPHA_BIAS:p[0]=c->alphaBias;break;case GL_DEPTH_SCALE:p[0]=c->depthScale;break;case GL_DEPTH_BIAS:p[0]=c->depthBias;break;case GL_LOGIC_OP_MODE:p[0]=(GLfloat)c->logicOpMode;break;case GL_MAX_CLIP_PLANES:p[0]=6.0f;break;case GL_MAX_EVAL_ORDER:p[0]=(GLfloat)NPGL_MAX_EVAL_ORDER;break;case GL_MAP1_GRID_DOMAIN:p[0]=c->map1GridDomain[0];p[1]=c->map1GridDomain[1];break;case GL_MAP1_GRID_SEGMENTS:p[0]=(GLfloat)c->map1GridSegments;break;case GL_MAP2_GRID_DOMAIN:memcpy(p,c->map2GridDomain,4*sizeof(GLfloat));break;case GL_MAP2_GRID_SEGMENTS:p[0]=(GLfloat)c->map2GridSegments[0];p[1]=(GLfloat)c->map2GridSegments[1];break;case GL_RENDER_MODE:p[0]=(GLfloat)c->renderMode;break;case GL_NAME_STACK_DEPTH:p[0]=(GLfloat)c->nameStackDepth;break;case GL_MAX_NAME_STACK_DEPTH:p[0]=64.0f;break;case GL_SELECTION_BUFFER_SIZE:p[0]=(GLfloat)c->selectBufferSize;break;case GL_FEEDBACK_BUFFER_SIZE:p[0]=(GLfloat)c->feedbackBufferSize;break;case GL_FEEDBACK_BUFFER_TYPE:p[0]=(GLfloat)c->feedbackType;break;default:npgl_set_error(c,GL_INVALID_ENUM);for(i=0;i<4;++i)p[i]=0;break;}
}
static void APIENTRY npgl_glGetDoublev(GLenum pname, GLdouble *p)
{
    NPGL_CONTEXT *c=npgl_current();GLfloat f[16];int count=1,i;if(!c||!p)return;
    if(pname==GL_MODELVIEW_MATRIX||pname==GL_PROJECTION_MATRIX||pname==GL_TEXTURE_MATRIX)count=16;else if(pname==GL_CURRENT_COLOR||pname==GL_ACCUM_CLEAR_VALUE||pname==GL_FOG_COLOR||pname==GL_LIGHT_MODEL_AMBIENT||pname==GL_CURRENT_RASTER_POSITION||pname==GL_CURRENT_RASTER_COLOR||pname==GL_CURRENT_RASTER_TEXTURE_COORDS)count=4;else if(pname==GL_MAP2_GRID_DOMAIN)count=4;else if(pname==GL_DEPTH_RANGE||pname==GL_POINT_SIZE_RANGE||pname==GL_LINE_WIDTH_RANGE||pname==GL_MAP1_GRID_DOMAIN||pname==GL_MAP2_GRID_SEGMENTS)count=2;
    npgl_glGetFloatv(pname,f);for(i=0;i<count;++i)p[i]=(GLdouble)f[i];
}
static void APIENTRY npgl_glGetIntegerv(GLenum pname, GLint *p)
{
    NPGL_CONTEXT *c=npgl_current();int ei,ed;if(!c||!p)return;
    ei=npgl_eval_cap_index(pname,&ed);if(ei>=0){*p=(ed==1?c->evalMap1[ei].enabled:c->evalMap2[ei].enabled)?1:0;return;}if(pname==GL_AUTO_NORMAL){*p=c->autoNormal?1:0;return;}
    switch(pname){case GL_VIEWPORT:memcpy(p,c->viewport,4*sizeof(GLint));break;case GL_MATRIX_MODE:*p=(GLint)c->matrixMode;break;case GL_DEPTH_FUNC:*p=(GLint)c->depthFunc;break;case GL_SHADE_MODEL:*p=(GLint)c->shadeModel;break;case GL_POLYGON_MODE:p[0]=(GLint)c->polygonModeFront;p[1]=(GLint)c->polygonModeBack;break;case GL_MODELVIEW_STACK_DEPTH:*p=c->modelviewTop+1;break;case GL_PROJECTION_STACK_DEPTH:*p=c->projectionTop+1;break;case GL_TEXTURE_STACK_DEPTH:*p=c->textureTop+1;break;case GL_MAX_MODELVIEW_STACK_DEPTH:*p=32;break;case GL_MAX_PROJECTION_STACK_DEPTH:*p=8;break;case GL_MAX_TEXTURE_STACK_DEPTH:*p=8;break;case GL_ATTRIB_STACK_DEPTH:*p=c->attribTop;break;case GL_CLIENT_ATTRIB_STACK_DEPTH:*p=c->clientAttribTop;break;case GL_MAX_ATTRIB_STACK_DEPTH:*p=16;break;case GL_MAX_CLIENT_ATTRIB_STACK_DEPTH:*p=16;break;case GL_MAX_TEXTURE_SIZE:*p=2048;break;case GL_PACK_SWAP_BYTES:*p=c->packSwapBytes?1:0;break;case GL_PACK_LSB_FIRST:*p=c->packLsbFirst?1:0;break;case GL_PACK_ALIGNMENT:*p=c->packAlignment;break;case GL_PACK_ROW_LENGTH:*p=c->packRowLength;break;case GL_PACK_SKIP_ROWS:*p=c->packSkipRows;break;case GL_PACK_SKIP_PIXELS:*p=c->packSkipPixels;break;case GL_UNPACK_SWAP_BYTES:*p=c->unpackSwapBytes?1:0;break;case GL_UNPACK_LSB_FIRST:*p=c->unpackLsbFirst?1:0;break;case GL_UNPACK_ALIGNMENT:*p=c->unpackAlignment;break;case GL_UNPACK_ROW_LENGTH:*p=c->unpackRowLength;break;case GL_UNPACK_SKIP_ROWS:*p=c->unpackSkipRows;break;case GL_UNPACK_SKIP_PIXELS:*p=c->unpackSkipPixels;break;case GL_READ_BUFFER:*p=(GLint)c->readBuffer;break;case GL_DRAW_BUFFER:*p=(GLint)c->drawBuffer;break;case GL_INDEX_WRITEMASK:*p=(GLint)c->indexMask;break;case GL_ACCUM_RED_BITS:case GL_ACCUM_GREEN_BITS:case GL_ACCUM_BLUE_BITS:case GL_ACCUM_ALPHA_BITS:*p=0;break;case GL_TEXTURE_BINDING_1D:*p=(GLint)(c->boundTexture1D?c->boundTexture1D->name:0);break;case GL_TEXTURE_BINDING_2D:*p=(GLint)(c->boundTexture2D?c->boundTexture2D->name:0);break;case GL_VERTEX_ARRAY_SIZE:*p=c->vertexArray.size;break;case GL_VERTEX_ARRAY_TYPE:*p=(GLint)c->vertexArray.type;break;case GL_VERTEX_ARRAY_STRIDE:*p=c->vertexArray.stride;break;case GL_NORMAL_ARRAY_TYPE:*p=(GLint)c->normalArray.type;break;case GL_NORMAL_ARRAY_STRIDE:*p=c->normalArray.stride;break;case GL_COLOR_ARRAY_SIZE:*p=c->colorArray.size;break;case GL_COLOR_ARRAY_TYPE:*p=(GLint)c->colorArray.type;break;case GL_COLOR_ARRAY_STRIDE:*p=c->colorArray.stride;break;case GL_INDEX_ARRAY_TYPE:*p=(GLint)c->indexArray.type;break;case GL_INDEX_ARRAY_STRIDE:*p=c->indexArray.stride;break;case GL_TEXTURE_COORD_ARRAY_SIZE:*p=c->texCoordArray.size;break;case GL_TEXTURE_COORD_ARRAY_TYPE:*p=(GLint)c->texCoordArray.type;break;case GL_TEXTURE_COORD_ARRAY_STRIDE:*p=c->texCoordArray.stride;break;case GL_EDGE_FLAG_ARRAY_STRIDE:*p=c->edgeFlagArray.stride;break;case GL_FOG_MODE:*p=(GLint)c->fogMode;break;case GL_SCISSOR_BOX:memcpy(p,c->scissorBox,4*sizeof(GLint));break;case GL_STENCIL_BITS:*p=c->stencilBits;break;case GL_STENCIL_CLEAR_VALUE:*p=c->clearStencil;break;case GL_STENCIL_FUNC:*p=(GLint)c->stencilFunc;break;case GL_STENCIL_REF:*p=c->stencilRef;break;case GL_STENCIL_VALUE_MASK:*p=(GLint)c->stencilValueMask;break;case GL_STENCIL_WRITEMASK:*p=(GLint)c->stencilWriteMask;break;case GL_STENCIL_FAIL:*p=(GLint)c->stencilFail;break;case GL_STENCIL_PASS_DEPTH_FAIL:*p=(GLint)c->stencilZFail;break;case GL_STENCIL_PASS_DEPTH_PASS:*p=(GLint)c->stencilPass;break;case GL_PERSPECTIVE_CORRECTION_HINT:*p=(GLint)c->perspectiveHint;break;case GL_POINT_SMOOTH_HINT:*p=(GLint)c->pointSmoothHint;break;case GL_LINE_SMOOTH_HINT:*p=(GLint)c->lineSmoothHint;break;case GL_POLYGON_SMOOTH_HINT:*p=(GLint)c->polygonSmoothHint;break;case GL_FOG_HINT:*p=(GLint)c->fogHint;break;case GL_LINE_STIPPLE_PATTERN:*p=(GLint)c->lineStipplePattern;break;case GL_LINE_STIPPLE_REPEAT:*p=c->lineStippleFactor;break;case GL_COLOR_MATERIAL_FACE:*p=(GLint)c->colorMaterialFace;break;case GL_COLOR_MATERIAL_PARAMETER:*p=(GLint)c->colorMaterialMode;break;case GL_MAX_PIXEL_MAP_TABLE:*p=NPGL_MAX_PIXEL_MAP_TABLE;break;case GL_PIXEL_MAP_I_TO_I_SIZE:*p=c->pixelMaps[0].size;break;case GL_PIXEL_MAP_S_TO_S_SIZE:*p=c->pixelMaps[1].size;break;case GL_PIXEL_MAP_I_TO_R_SIZE:*p=c->pixelMaps[2].size;break;case GL_PIXEL_MAP_I_TO_G_SIZE:*p=c->pixelMaps[3].size;break;case GL_PIXEL_MAP_I_TO_B_SIZE:*p=c->pixelMaps[4].size;break;case GL_PIXEL_MAP_I_TO_A_SIZE:*p=c->pixelMaps[5].size;break;case GL_PIXEL_MAP_R_TO_R_SIZE:*p=c->pixelMaps[6].size;break;case GL_PIXEL_MAP_G_TO_G_SIZE:*p=c->pixelMaps[7].size;break;case GL_PIXEL_MAP_B_TO_B_SIZE:*p=c->pixelMaps[8].size;break;case GL_PIXEL_MAP_A_TO_A_SIZE:*p=c->pixelMaps[9].size;break;case GL_MAP_COLOR:*p=c->mapColor?1:0;break;case GL_MAP_STENCIL:*p=c->mapStencil?1:0;break;case GL_INDEX_SHIFT:*p=c->indexShift;break;case GL_INDEX_OFFSET:*p=c->indexOffset;break;case GL_RED_SCALE:*p=(GLint)c->redScale;break;case GL_RED_BIAS:*p=(GLint)c->redBias;break;case GL_GREEN_SCALE:*p=(GLint)c->greenScale;break;case GL_GREEN_BIAS:*p=(GLint)c->greenBias;break;case GL_BLUE_SCALE:*p=(GLint)c->blueScale;break;case GL_BLUE_BIAS:*p=(GLint)c->blueBias;break;case GL_ALPHA_SCALE:*p=(GLint)c->alphaScale;break;case GL_ALPHA_BIAS:*p=(GLint)c->alphaBias;break;case GL_DEPTH_SCALE:*p=(GLint)c->depthScale;break;case GL_DEPTH_BIAS:*p=(GLint)c->depthBias;break;case GL_LOGIC_OP_MODE:*p=(GLint)c->logicOpMode;break;case GL_MAX_CLIP_PLANES:*p=6;break;case GL_MAX_EVAL_ORDER:*p=NPGL_MAX_EVAL_ORDER;break;case GL_MAP1_GRID_DOMAIN:p[0]=npgl_round_eval_int(c->map1GridDomain[0]);p[1]=npgl_round_eval_int(c->map1GridDomain[1]);break;case GL_MAP1_GRID_SEGMENTS:*p=c->map1GridSegments;break;case GL_MAP2_GRID_DOMAIN:p[0]=npgl_round_eval_int(c->map2GridDomain[0]);p[1]=npgl_round_eval_int(c->map2GridDomain[1]);p[2]=npgl_round_eval_int(c->map2GridDomain[2]);p[3]=npgl_round_eval_int(c->map2GridDomain[3]);break;case GL_MAP2_GRID_SEGMENTS:p[0]=c->map2GridSegments[0];p[1]=c->map2GridSegments[1];break;case GL_RENDER_MODE:*p=(GLint)c->renderMode;break;case GL_NAME_STACK_DEPTH:*p=c->nameStackDepth;break;case GL_MAX_NAME_STACK_DEPTH:*p=64;break;case GL_SELECTION_BUFFER_SIZE:*p=c->selectBufferSize;break;case GL_FEEDBACK_BUFFER_SIZE:*p=c->feedbackBufferSize;break;case GL_FEEDBACK_BUFFER_TYPE:*p=(GLint)c->feedbackType;break;default:npgl_set_error(c,GL_INVALID_ENUM);*p=0;break;}
}
static void APIENTRY npgl_glGetBooleanv(GLenum pname, GLboolean *p)
{
    NPGL_CONTEXT *c=npgl_current();int ei,ed;if(!c||!p)return;ei=npgl_eval_cap_index(pname,&ed);if(ei>=0){*p=ed==1?c->evalMap1[ei].enabled:c->evalMap2[ei].enabled;return;}if(pname==GL_AUTO_NORMAL){*p=c->autoNormal;return;}
    switch(pname){case GL_MAP1_GRID_DOMAIN:p[0]=c->map1GridDomain[0]!=0.0f?GL_TRUE:GL_FALSE;p[1]=c->map1GridDomain[1]!=0.0f?GL_TRUE:GL_FALSE;break;case GL_MAP1_GRID_SEGMENTS:*p=c->map1GridSegments?GL_TRUE:GL_FALSE;break;case GL_MAP2_GRID_DOMAIN:p[0]=c->map2GridDomain[0]!=0.0f?GL_TRUE:GL_FALSE;p[1]=c->map2GridDomain[1]!=0.0f?GL_TRUE:GL_FALSE;p[2]=c->map2GridDomain[2]!=0.0f?GL_TRUE:GL_FALSE;p[3]=c->map2GridDomain[3]!=0.0f?GL_TRUE:GL_FALSE;break;case GL_MAP2_GRID_SEGMENTS:p[0]=c->map2GridSegments[0]?GL_TRUE:GL_FALSE;p[1]=c->map2GridSegments[1]?GL_TRUE:GL_FALSE;break;case GL_MAX_EVAL_ORDER:*p=GL_TRUE;break;case GL_DEPTH_TEST:*p=c->depthTest;break;case GL_BLEND:*p=c->blend;break;case GL_ALPHA_TEST:*p=c->alphaTest;break;case GL_CULL_FACE:*p=c->cullFaceEnable;break;case GL_TEXTURE_1D:*p=c->texture1D;break;case GL_TEXTURE_2D:*p=c->texture2D;break;case GL_DEPTH_WRITEMASK:*p=c->depthWrite;break;case GL_VERTEX_ARRAY:*p=c->vertexArray.enabled;break;case GL_NORMAL_ARRAY:*p=c->normalArray.enabled;break;case GL_COLOR_ARRAY:*p=c->colorArray.enabled;break;case GL_INDEX_ARRAY:*p=c->indexArray.enabled;break;case GL_TEXTURE_COORD_ARRAY:*p=c->texCoordArray.enabled;break;case GL_EDGE_FLAG_ARRAY:*p=c->edgeFlagArray.enabled;break;case GL_EDGE_FLAG:*p=c->currentEdgeFlag;break;case GL_LIGHTING:*p=c->lighting;break;case GL_NORMALIZE:*p=c->normalize;break;case GL_COLOR_MATERIAL:*p=c->colorMaterial;break;case GL_FOG:*p=c->fog;break;case GL_SCISSOR_TEST:*p=c->scissorTest;break;case GL_STENCIL_TEST:*p=c->stencilTest;break;case GL_LINE_STIPPLE:*p=c->lineStipple;break;case GL_POLYGON_STIPPLE:*p=c->polygonStipple;break;case GL_CURRENT_RASTER_POSITION_VALID:*p=c->rasterValid;break;case GL_PACK_SWAP_BYTES:*p=c->packSwapBytes;break;case GL_PACK_LSB_FIRST:*p=c->packLsbFirst;break;case GL_UNPACK_SWAP_BYTES:*p=c->unpackSwapBytes;break;case GL_UNPACK_LSB_FIRST:*p=c->unpackLsbFirst;break;case GL_COLOR_WRITEMASK:p[0]=c->colorMask[0];p[1]=c->colorMask[1];p[2]=c->colorMask[2];p[3]=c->colorMask[3];break;case GL_MAP_COLOR:*p=c->mapColor;break;case GL_MAP_STENCIL:*p=c->mapStencil;break;case GL_COLOR_LOGIC_OP:*p=c->colorLogicOp;break;case GL_INDEX_LOGIC_OP:*p=c->indexLogicOp;break;case GL_RENDER_MODE:*p=c->renderMode?GL_TRUE:GL_FALSE;break;case GL_NAME_STACK_DEPTH:*p=c->nameStackDepth?GL_TRUE:GL_FALSE;break;case GL_MAX_NAME_STACK_DEPTH:*p=GL_TRUE;break;case GL_SELECTION_BUFFER_SIZE:*p=c->selectBufferSize?GL_TRUE:GL_FALSE;break;case GL_FEEDBACK_BUFFER_SIZE:*p=c->feedbackBufferSize?GL_TRUE:GL_FALSE;break;case GL_FEEDBACK_BUFFER_TYPE:*p=c->feedbackType?GL_TRUE:GL_FALSE;break;default:if(pname>=GL_CLIP_PLANE0&&pname<=GL_CLIP_PLANE5)*p=c->clipPlaneEnabled[pname-GL_CLIP_PLANE0];else{npgl_set_error(c,GL_INVALID_ENUM);*p=GL_FALSE;}break;}
}


static void npgl_init_dispatch(void)
{
    if(g_procTableInit)return;
    memset(&g_procTable,0,sizeof(g_procTable));
    g_procTable.cEntries=OPENGL_VERSION_110_ENTRIES;
    g_procTable.entries[0]=(PROC)npgl_glNewList;
    g_procTable.entries[1]=(PROC)npgl_glEndList;
    g_procTable.entries[2]=(PROC)npgl_glCallList;
    g_procTable.entries[3]=(PROC)npgl_glCallLists;
    g_procTable.entries[4]=(PROC)npgl_glDeleteLists;
    g_procTable.entries[5]=(PROC)npgl_glGenLists;
    g_procTable.entries[6]=(PROC)npgl_glListBase;
    g_procTable.entries[7]=(PROC)npgl_glBegin;
    g_procTable.entries[8]=(PROC)npgl_glBitmap;
    g_procTable.entries[9]=(PROC)npgl_glColor3b; g_procTable.entries[10]=(PROC)npgl_glColor3bv;
    g_procTable.entries[11]=(PROC)npgl_glColor3d; g_procTable.entries[12]=(PROC)npgl_glColor3dv;
    g_procTable.entries[13]=(PROC)npgl_glColor3f; g_procTable.entries[14]=(PROC)npgl_glColor3fv;
    g_procTable.entries[15]=(PROC)npgl_glColor3i; g_procTable.entries[16]=(PROC)npgl_glColor3iv;
    g_procTable.entries[17]=(PROC)npgl_glColor3s; g_procTable.entries[18]=(PROC)npgl_glColor3sv;
    g_procTable.entries[19]=(PROC)npgl_glColor3ub; g_procTable.entries[20]=(PROC)npgl_glColor3ubv;
    g_procTable.entries[21]=(PROC)npgl_glColor3ui; g_procTable.entries[22]=(PROC)npgl_glColor3uiv;
    g_procTable.entries[23]=(PROC)npgl_glColor3us; g_procTable.entries[24]=(PROC)npgl_glColor3usv;
    g_procTable.entries[25]=(PROC)npgl_glColor4b; g_procTable.entries[26]=(PROC)npgl_glColor4bv;
    g_procTable.entries[27]=(PROC)npgl_glColor4d; g_procTable.entries[28]=(PROC)npgl_glColor4dv;
    g_procTable.entries[29]=(PROC)npgl_glColor4f; g_procTable.entries[30]=(PROC)npgl_glColor4fv;
    g_procTable.entries[31]=(PROC)npgl_glColor4i; g_procTable.entries[32]=(PROC)npgl_glColor4iv;
    g_procTable.entries[33]=(PROC)npgl_glColor4s; g_procTable.entries[34]=(PROC)npgl_glColor4sv;
    g_procTable.entries[35]=(PROC)npgl_glColor4ub; g_procTable.entries[36]=(PROC)npgl_glColor4ubv;
    g_procTable.entries[37]=(PROC)npgl_glColor4ui; g_procTable.entries[38]=(PROC)npgl_glColor4uiv;
    g_procTable.entries[39]=(PROC)npgl_glColor4us; g_procTable.entries[40]=(PROC)npgl_glColor4usv;
    g_procTable.entries[41]=(PROC)npgl_glEdgeFlag; g_procTable.entries[42]=(PROC)npgl_glEdgeFlagv;
    g_procTable.entries[43]=(PROC)npgl_glEnd;
    g_procTable.entries[44]=(PROC)npgl_glIndexd; g_procTable.entries[45]=(PROC)npgl_glIndexdv;
    g_procTable.entries[46]=(PROC)npgl_glIndexf; g_procTable.entries[47]=(PROC)npgl_glIndexfv;
    g_procTable.entries[48]=(PROC)npgl_glIndexi; g_procTable.entries[49]=(PROC)npgl_glIndexiv;
    g_procTable.entries[50]=(PROC)npgl_glIndexs; g_procTable.entries[51]=(PROC)npgl_glIndexsv;
    g_procTable.entries[52]=(PROC)npgl_glNormal3b; g_procTable.entries[53]=(PROC)npgl_glNormal3bv;
    g_procTable.entries[54]=(PROC)npgl_glNormal3d; g_procTable.entries[55]=(PROC)npgl_glNormal3dv; g_procTable.entries[56]=(PROC)npgl_glNormal3f; g_procTable.entries[57]=(PROC)npgl_glNormal3fv;
    g_procTable.entries[58]=(PROC)npgl_glNormal3i; g_procTable.entries[59]=(PROC)npgl_glNormal3iv; g_procTable.entries[60]=(PROC)npgl_glNormal3s; g_procTable.entries[61]=(PROC)npgl_glNormal3sv;
    g_procTable.entries[62]=(PROC)npgl_glRasterPos2d; g_procTable.entries[63]=(PROC)npgl_glRasterPos2dv;
    g_procTable.entries[64]=(PROC)npgl_glRasterPos2f; g_procTable.entries[65]=(PROC)npgl_glRasterPos2fv;
    g_procTable.entries[66]=(PROC)npgl_glRasterPos2i; g_procTable.entries[67]=(PROC)npgl_glRasterPos2iv;
    g_procTable.entries[68]=(PROC)npgl_glRasterPos2s; g_procTable.entries[69]=(PROC)npgl_glRasterPos2sv;
    g_procTable.entries[70]=(PROC)npgl_glRasterPos3d; g_procTable.entries[71]=(PROC)npgl_glRasterPos3dv;
    g_procTable.entries[72]=(PROC)npgl_glRasterPos3f; g_procTable.entries[73]=(PROC)npgl_glRasterPos3fv;
    g_procTable.entries[74]=(PROC)npgl_glRasterPos3i; g_procTable.entries[75]=(PROC)npgl_glRasterPos3iv;
    g_procTable.entries[76]=(PROC)npgl_glRasterPos3s; g_procTable.entries[77]=(PROC)npgl_glRasterPos3sv;
    g_procTable.entries[78]=(PROC)npgl_glRasterPos4d; g_procTable.entries[79]=(PROC)npgl_glRasterPos4dv;
    g_procTable.entries[80]=(PROC)npgl_glRasterPos4f; g_procTable.entries[81]=(PROC)npgl_glRasterPos4fv;
    g_procTable.entries[82]=(PROC)npgl_glRasterPos4i; g_procTable.entries[83]=(PROC)npgl_glRasterPos4iv;
    g_procTable.entries[84]=(PROC)npgl_glRasterPos4s; g_procTable.entries[85]=(PROC)npgl_glRasterPos4sv;
    g_procTable.entries[86]=(PROC)npgl_glRectd; g_procTable.entries[87]=(PROC)npgl_glRectdv; g_procTable.entries[88]=(PROC)npgl_glRectf; g_procTable.entries[89]=(PROC)npgl_glRectfv;
    g_procTable.entries[90]=(PROC)npgl_glRecti; g_procTable.entries[91]=(PROC)npgl_glRectiv; g_procTable.entries[92]=(PROC)npgl_glRects; g_procTable.entries[93]=(PROC)npgl_glRectsv;
    g_procTable.entries[94]=(PROC)npgl_glTexCoord1d; g_procTable.entries[95]=(PROC)npgl_glTexCoord1dv; g_procTable.entries[96]=(PROC)npgl_glTexCoord1f; g_procTable.entries[97]=(PROC)npgl_glTexCoord1fv;
    g_procTable.entries[98]=(PROC)npgl_glTexCoord1i; g_procTable.entries[99]=(PROC)npgl_glTexCoord1iv; g_procTable.entries[100]=(PROC)npgl_glTexCoord1s; g_procTable.entries[101]=(PROC)npgl_glTexCoord1sv;
    g_procTable.entries[102]=(PROC)npgl_glTexCoord2d; g_procTable.entries[103]=(PROC)npgl_glTexCoord2dv; g_procTable.entries[104]=(PROC)npgl_glTexCoord2f; g_procTable.entries[105]=(PROC)npgl_glTexCoord2fv;
    g_procTable.entries[106]=(PROC)npgl_glTexCoord2i; g_procTable.entries[107]=(PROC)npgl_glTexCoord2iv; g_procTable.entries[108]=(PROC)npgl_glTexCoord2s; g_procTable.entries[109]=(PROC)npgl_glTexCoord2sv;
    g_procTable.entries[110]=(PROC)npgl_glTexCoord3d; g_procTable.entries[111]=(PROC)npgl_glTexCoord3dv; g_procTable.entries[112]=(PROC)npgl_glTexCoord3f; g_procTable.entries[113]=(PROC)npgl_glTexCoord3fv;
    g_procTable.entries[114]=(PROC)npgl_glTexCoord3i; g_procTable.entries[115]=(PROC)npgl_glTexCoord3iv; g_procTable.entries[116]=(PROC)npgl_glTexCoord3s; g_procTable.entries[117]=(PROC)npgl_glTexCoord3sv;
    g_procTable.entries[118]=(PROC)npgl_glTexCoord4d; g_procTable.entries[119]=(PROC)npgl_glTexCoord4dv; g_procTable.entries[120]=(PROC)npgl_glTexCoord4f; g_procTable.entries[121]=(PROC)npgl_glTexCoord4fv;
    g_procTable.entries[122]=(PROC)npgl_glTexCoord4i; g_procTable.entries[123]=(PROC)npgl_glTexCoord4iv; g_procTable.entries[124]=(PROC)npgl_glTexCoord4s; g_procTable.entries[125]=(PROC)npgl_glTexCoord4sv;
    g_procTable.entries[126]=(PROC)npgl_glVertex2d; g_procTable.entries[127]=(PROC)npgl_glVertex2dv; g_procTable.entries[128]=(PROC)npgl_glVertex2f; g_procTable.entries[129]=(PROC)npgl_glVertex2fv;
    g_procTable.entries[130]=(PROC)npgl_glVertex2i; g_procTable.entries[131]=(PROC)npgl_glVertex2iv; g_procTable.entries[132]=(PROC)npgl_glVertex2s; g_procTable.entries[133]=(PROC)npgl_glVertex2sv;
    g_procTable.entries[134]=(PROC)npgl_glVertex3d; g_procTable.entries[135]=(PROC)npgl_glVertex3dv; g_procTable.entries[136]=(PROC)npgl_glVertex3f; g_procTable.entries[137]=(PROC)npgl_glVertex3fv;
    g_procTable.entries[138]=(PROC)npgl_glVertex3i; g_procTable.entries[139]=(PROC)npgl_glVertex3iv; g_procTable.entries[140]=(PROC)npgl_glVertex3s; g_procTable.entries[141]=(PROC)npgl_glVertex3sv;
    g_procTable.entries[142]=(PROC)npgl_glVertex4d; g_procTable.entries[143]=(PROC)npgl_glVertex4dv; g_procTable.entries[144]=(PROC)npgl_glVertex4f; g_procTable.entries[145]=(PROC)npgl_glVertex4fv;
    g_procTable.entries[146]=(PROC)npgl_glVertex4i; g_procTable.entries[147]=(PROC)npgl_glVertex4iv; g_procTable.entries[148]=(PROC)npgl_glVertex4s; g_procTable.entries[149]=(PROC)npgl_glVertex4sv;
    g_procTable.entries[150]=(PROC)npgl_glClipPlane;
    g_procTable.entries[151]=(PROC)npgl_glColorMaterial;
    g_procTable.entries[152]=(PROC)npgl_glCullFace;
    g_procTable.entries[153]=(PROC)npgl_glFogf;
    g_procTable.entries[154]=(PROC)npgl_glFogfv;
    g_procTable.entries[155]=(PROC)npgl_glFogi;
    g_procTable.entries[156]=(PROC)npgl_glFogiv;
    g_procTable.entries[157]=(PROC)npgl_glFrontFace;
    g_procTable.entries[158]=(PROC)npgl_glHint;
    g_procTable.entries[159]=(PROC)npgl_glLightf;
    g_procTable.entries[160]=(PROC)npgl_glLightfv;
    g_procTable.entries[161]=(PROC)npgl_glLighti;
    g_procTable.entries[162]=(PROC)npgl_glLightiv;
    g_procTable.entries[163]=(PROC)npgl_glLightModelf;
    g_procTable.entries[164]=(PROC)npgl_glLightModelfv;
    g_procTable.entries[165]=(PROC)npgl_glLightModeli;
    g_procTable.entries[166]=(PROC)npgl_glLightModeliv;
    g_procTable.entries[167]=(PROC)npgl_glLineStipple;
    g_procTable.entries[168]=(PROC)npgl_glLineWidth;
    g_procTable.entries[169]=(PROC)npgl_glMaterialf;
    g_procTable.entries[170]=(PROC)npgl_glMaterialfv;
    g_procTable.entries[171]=(PROC)npgl_glMateriali;
    g_procTable.entries[172]=(PROC)npgl_glMaterialiv;
    g_procTable.entries[173]=(PROC)npgl_glPointSize;
    g_procTable.entries[174]=(PROC)npgl_glPolygonMode;
    g_procTable.entries[175]=(PROC)npgl_glPolygonStipple;
    g_procTable.entries[176]=(PROC)npgl_glScissor;
    g_procTable.entries[177]=(PROC)npgl_glShadeModel;
    g_procTable.entries[178]=(PROC)npgl_glTexParameterf;
    g_procTable.entries[179]=(PROC)npgl_glTexParameterfv;
    g_procTable.entries[180]=(PROC)npgl_glTexParameteri;
    g_procTable.entries[181]=(PROC)npgl_glTexParameteriv;
    g_procTable.entries[182]=(PROC)npgl_glTexImage1D;
    g_procTable.entries[183]=(PROC)npgl_glTexImage2D;
    g_procTable.entries[184]=(PROC)npgl_glTexEnvf;
    g_procTable.entries[185]=(PROC)npgl_glTexEnvfv;
    g_procTable.entries[186]=(PROC)npgl_glTexEnvi;
    g_procTable.entries[187]=(PROC)npgl_glTexEnviv;
    g_procTable.entries[188]=(PROC)npgl_glTexGend;
    g_procTable.entries[189]=(PROC)npgl_glTexGendv;
    g_procTable.entries[190]=(PROC)npgl_glTexGenf;
    g_procTable.entries[191]=(PROC)npgl_glTexGenfv;
    g_procTable.entries[192]=(PROC)npgl_glTexGeni;
    g_procTable.entries[193]=(PROC)npgl_glTexGeniv;
    g_procTable.entries[194]=(PROC)npgl_glFeedbackBuffer;
    g_procTable.entries[195]=(PROC)npgl_glSelectBuffer;
    g_procTable.entries[196]=(PROC)npgl_glRenderMode;
    g_procTable.entries[197]=(PROC)npgl_glInitNames;
    g_procTable.entries[198]=(PROC)npgl_glLoadName;
    g_procTable.entries[199]=(PROC)npgl_glPassThrough;
    g_procTable.entries[200]=(PROC)npgl_glPopName;
    g_procTable.entries[201]=(PROC)npgl_glPushName;
    g_procTable.entries[220]=(PROC)npgl_glMap1d;
    g_procTable.entries[221]=(PROC)npgl_glMap1f;
    g_procTable.entries[222]=(PROC)npgl_glMap2d;
    g_procTable.entries[223]=(PROC)npgl_glMap2f;
    g_procTable.entries[224]=(PROC)npgl_glMapGrid1d;
    g_procTable.entries[225]=(PROC)npgl_glMapGrid1f;
    g_procTable.entries[226]=(PROC)npgl_glMapGrid2d;
    g_procTable.entries[227]=(PROC)npgl_glMapGrid2f;
    g_procTable.entries[228]=(PROC)npgl_glEvalCoord1d;
    g_procTable.entries[229]=(PROC)npgl_glEvalCoord1dv;
    g_procTable.entries[230]=(PROC)npgl_glEvalCoord1f;
    g_procTable.entries[231]=(PROC)npgl_glEvalCoord1fv;
    g_procTable.entries[232]=(PROC)npgl_glEvalCoord2d;
    g_procTable.entries[233]=(PROC)npgl_glEvalCoord2dv;
    g_procTable.entries[234]=(PROC)npgl_glEvalCoord2f;
    g_procTable.entries[235]=(PROC)npgl_glEvalCoord2fv;
    g_procTable.entries[236]=(PROC)npgl_glEvalMesh1;
    g_procTable.entries[237]=(PROC)npgl_glEvalPoint1;
    g_procTable.entries[238]=(PROC)npgl_glEvalMesh2;
    g_procTable.entries[239]=(PROC)npgl_glEvalPoint2;
    g_procTable.entries[202]=(PROC)npgl_glDrawBuffer;
    g_procTable.entries[203]=(PROC)npgl_glClear;
    g_procTable.entries[204]=(PROC)npgl_glClearAccum;
    g_procTable.entries[205]=(PROC)npgl_glClearIndex;
    g_procTable.entries[206]=(PROC)npgl_glClearColor;
    g_procTable.entries[207]=(PROC)npgl_glClearStencil;
    g_procTable.entries[208]=(PROC)npgl_glClearDepth;
    g_procTable.entries[209]=(PROC)npgl_glStencilMask;
    g_procTable.entries[210]=(PROC)npgl_glColorMask;
    g_procTable.entries[211]=(PROC)npgl_glDepthMask;
    g_procTable.entries[212]=(PROC)npgl_glIndexMask;
    g_procTable.entries[213]=(PROC)npgl_glAccum;
    g_procTable.entries[214]=(PROC)npgl_glDisable;
    g_procTable.entries[215]=(PROC)npgl_glEnable;
    g_procTable.entries[216]=(PROC)npgl_glFinish;
    g_procTable.entries[217]=(PROC)npgl_glFlush;
    g_procTable.entries[218]=(PROC)npgl_glPopAttrib;
    g_procTable.entries[219]=(PROC)npgl_glPushAttrib;
    g_procTable.entries[240]=(PROC)npgl_glAlphaFunc;
    g_procTable.entries[241]=(PROC)npgl_glBlendFunc;
    g_procTable.entries[242]=(PROC)npgl_glLogicOp;
    g_procTable.entries[243]=(PROC)npgl_glStencilFunc;
    g_procTable.entries[244]=(PROC)npgl_glStencilOp;
    g_procTable.entries[245]=(PROC)npgl_glDepthFunc;
    g_procTable.entries[246]=(PROC)npgl_glPixelZoom;
    g_procTable.entries[247]=(PROC)npgl_glPixelTransferf;
    g_procTable.entries[248]=(PROC)npgl_glPixelTransferi;
    g_procTable.entries[249]=(PROC)npgl_glPixelStoref;
    g_procTable.entries[250]=(PROC)npgl_glPixelStorei;
    g_procTable.entries[251]=(PROC)npgl_glPixelMapfv;
    g_procTable.entries[252]=(PROC)npgl_glPixelMapuiv;
    g_procTable.entries[253]=(PROC)npgl_glPixelMapusv;
    g_procTable.entries[254]=(PROC)npgl_glReadBuffer;
    g_procTable.entries[255]=(PROC)npgl_glCopyPixels;
    g_procTable.entries[256]=(PROC)npgl_glReadPixels;
    g_procTable.entries[257]=(PROC)npgl_glDrawPixels;
    g_procTable.entries[258]=(PROC)npgl_glGetBooleanv;
    g_procTable.entries[259]=(PROC)npgl_glGetClipPlane;
    g_procTable.entries[260]=(PROC)npgl_glGetDoublev;
    g_procTable.entries[261]=(PROC)npgl_glGetError;
    g_procTable.entries[262]=(PROC)npgl_glGetFloatv;
    g_procTable.entries[263]=(PROC)npgl_glGetIntegerv;
    g_procTable.entries[264]=(PROC)npgl_glGetLightfv;
    g_procTable.entries[265]=(PROC)npgl_glGetLightiv;
    g_procTable.entries[266]=(PROC)npgl_glGetMapdv;
    g_procTable.entries[267]=(PROC)npgl_glGetMapfv;
    g_procTable.entries[268]=(PROC)npgl_glGetMapiv;
    g_procTable.entries[269]=(PROC)npgl_glGetMaterialfv;
    g_procTable.entries[270]=(PROC)npgl_glGetMaterialiv;
    g_procTable.entries[271]=(PROC)npgl_glGetPixelMapfv;
    g_procTable.entries[272]=(PROC)npgl_glGetPixelMapuiv;
    g_procTable.entries[273]=(PROC)npgl_glGetPixelMapusv;
    g_procTable.entries[274]=(PROC)npgl_glGetPolygonStipple;
    g_procTable.entries[275]=(PROC)npgl_glGetString;
    g_procTable.entries[276]=(PROC)npgl_glGetTexEnvfv;
    g_procTable.entries[277]=(PROC)npgl_glGetTexEnviv;
    g_procTable.entries[278]=(PROC)npgl_glGetTexGendv;
    g_procTable.entries[279]=(PROC)npgl_glGetTexGenfv;
    g_procTable.entries[280]=(PROC)npgl_glGetTexGeniv;
    g_procTable.entries[281]=(PROC)npgl_glGetTexImage;
    g_procTable.entries[282]=(PROC)npgl_glGetTexParameterfv;
    g_procTable.entries[283]=(PROC)npgl_glGetTexParameteriv;
    g_procTable.entries[284]=(PROC)npgl_glGetTexLevelParameterfv;
    g_procTable.entries[285]=(PROC)npgl_glGetTexLevelParameteriv;
    g_procTable.entries[286]=(PROC)npgl_glIsEnabled;
    g_procTable.entries[287]=(PROC)npgl_glIsList;
    g_procTable.entries[288]=(PROC)npgl_glDepthRange;
    g_procTable.entries[289]=(PROC)npgl_glFrustum;
    g_procTable.entries[290]=(PROC)npgl_glLoadIdentity;
    g_procTable.entries[291]=(PROC)npgl_glLoadMatrixf;
    g_procTable.entries[292]=(PROC)npgl_glLoadMatrixd;
    g_procTable.entries[293]=(PROC)npgl_glMatrixMode;
    g_procTable.entries[294]=(PROC)npgl_glMultMatrixf;
    g_procTable.entries[295]=(PROC)npgl_glMultMatrixd;
    g_procTable.entries[296]=(PROC)npgl_glOrtho;
    g_procTable.entries[297]=(PROC)npgl_glPopMatrix;
    g_procTable.entries[298]=(PROC)npgl_glPushMatrix;
    g_procTable.entries[299]=(PROC)npgl_glRotated;
    g_procTable.entries[300]=(PROC)npgl_glRotatef;
    g_procTable.entries[301]=(PROC)npgl_glScaled;
    g_procTable.entries[302]=(PROC)npgl_glScalef;
    g_procTable.entries[303]=(PROC)npgl_glTranslated;
    g_procTable.entries[304]=(PROC)npgl_glTranslatef;
    g_procTable.entries[305]=(PROC)npgl_glViewport;
    g_procTable.entries[306]=(PROC)npgl_glArrayElement;
    g_procTable.entries[307]=(PROC)npgl_glBindTexture;
    g_procTable.entries[308]=(PROC)npgl_glColorPointer;
    g_procTable.entries[309]=(PROC)npgl_glDisableClientState;
    g_procTable.entries[310]=(PROC)npgl_glDrawArrays;
    g_procTable.entries[311]=(PROC)npgl_glDrawElements;
    g_procTable.entries[312]=(PROC)npgl_glEdgeFlagPointer;
    g_procTable.entries[313]=(PROC)npgl_glEnableClientState;
    g_procTable.entries[314]=(PROC)npgl_glIndexPointer;
    g_procTable.entries[315]=(PROC)npgl_glIndexub;
    g_procTable.entries[316]=(PROC)npgl_glIndexubv;
    g_procTable.entries[317]=(PROC)npgl_glInterleavedArrays;
    g_procTable.entries[318]=(PROC)npgl_glNormalPointer;
    g_procTable.entries[319]=(PROC)npgl_glPolygonOffset;
    g_procTable.entries[320]=(PROC)npgl_glTexCoordPointer;
    g_procTable.entries[321]=(PROC)npgl_glVertexPointer;
    g_procTable.entries[322]=(PROC)npgl_glAreTexturesResident;
    g_procTable.entries[323]=(PROC)npgl_glCopyTexImage1D;
    g_procTable.entries[324]=(PROC)npgl_glCopyTexImage2D;
    g_procTable.entries[325]=(PROC)npgl_glCopyTexSubImage1D;
    g_procTable.entries[326]=(PROC)npgl_glCopyTexSubImage2D;
    g_procTable.entries[327]=(PROC)npgl_glDeleteTextures;
    g_procTable.entries[328]=(PROC)npgl_glGenTextures;
    g_procTable.entries[329]=(PROC)npgl_glGetPointerv;
    g_procTable.entries[330]=(PROC)npgl_glIsTexture;
    g_procTable.entries[331]=(PROC)npgl_glPrioritizeTextures;
    g_procTable.entries[332]=(PROC)npgl_glTexSubImage1D;
    g_procTable.entries[333]=(PROC)npgl_glTexSubImage2D;
    g_procTable.entries[334]=(PROC)npgl_glPopClientAttrib;
    g_procTable.entries[335]=(PROC)npgl_glPushClientAttrib;
    g_procTableInit=TRUE;
}

static NPGL_CONTEXT *npgl_context_from_handle(DHGLRC h) { return (NPGL_CONTEXT *)h; }

DHGLRC APIENTRY DrvCreateContext(HDC hdc)
{
    NPGL_CONTEXT *c;
    NPDISP_OGL_CONTEXT32 packet;
    GLint pixelFormat;
    c=(NPGL_CONTEXT *)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,sizeof(*c));
    if(!c)return 0;
    pixelFormat=npgl_pixel_format_for_hdc(hdc);
    c->hdc=hdc;c->pixelFormat=pixelFormat;c->doubleBuffered=(pixelFormat<=2||pixelFormat==NPGL_PIXEL_FORMAT_NO_DEPTH_DOUBLE)?GL_TRUE:GL_FALSE;c->bridgeContext=(DWORD)c;c->renderMode=GL_RENDER;c->feedbackType=GL_2D;c->perspectiveHint=GL_DONT_CARE;c->pointSmoothHint=GL_DONT_CARE;c->lineSmoothHint=GL_DONT_CARE;c->polygonSmoothHint=GL_DONT_CARE;c->fogHint=GL_DONT_CARE;c->currentColor[0]=c->currentColor[1]=c->currentColor[2]=1.0f;c->currentColor[3]=1.0f;c->currentIndex=1.0f;c->currentEdgeFlag=GL_TRUE;c->currentNormal[2]=1.0f;c->currentTexCoord[3]=1.0f;c->texGenMode[0]=c->texGenMode[1]=c->texGenMode[2]=c->texGenMode[3]=GL_EYE_LINEAR;c->texGenObjectPlane[0][0]=1.0f;c->texGenObjectPlane[1][1]=1.0f;c->texGenObjectPlane[2][2]=1.0f;c->texGenObjectPlane[3][3]=1.0f;c->texGenEyePlane[0][0]=1.0f;c->texGenEyePlane[1][1]=1.0f;c->texGenEyePlane[2][2]=1.0f;c->texGenEyePlane[3][3]=1.0f;c->clearColor[3]=0.0f;c->clearDepth=1.0;c->clearStencil=0;c->stencilFunc=GL_ALWAYS;c->stencilValueMask=~0UL;c->stencilWriteMask=~0UL;c->stencilFail=GL_KEEP;c->stencilZFail=GL_KEEP;c->stencilPass=GL_KEEP;c->stencilBits=(pixelFormat==2||pixelFormat==4)?4:0;c->depthWrite=GL_TRUE;c->depthFunc=GL_LESS;c->srcBlend=GL_ONE;c->destBlend=GL_ZERO;c->alphaFunc=GL_ALWAYS;c->alphaRef=0;c->cullFace=GL_BACK;c->frontFace=GL_CCW;c->shadeModel=GL_SMOOTH;c->pointSize=1.0f;c->lineWidth=1.0f;c->lineStipple=GL_FALSE;c->lineStippleFactor=1;c->lineStipplePattern=0xffff;c->polygonStipple=GL_FALSE;memset(c->polygonStipplePattern,0xff,sizeof(c->polygonStipplePattern));c->polygonModeFront=GL_FILL;c->polygonModeBack=GL_FILL;c->textureEnvMode=GL_MODULATE;c->packAlignment=4;c->unpackAlignment=4;c->readBuffer=c->doubleBuffered?GL_BACK:GL_FRONT;c->drawBuffer=c->doubleBuffered?GL_BACK:GL_FRONT;c->colorMask[0]=c->colorMask[1]=c->colorMask[2]=c->colorMask[3]=GL_TRUE;c->logicOpMode=GL_COPY;c->indexMask=~0UL;c->pixelZoomX=1.0f;c->pixelZoomY=1.0f;c->redScale=c->greenScale=c->blueScale=c->alphaScale=c->depthScale=1.0f;{int i;for(i=0;i<10;++i){c->pixelMaps[i].size=1;c->pixelMaps[i].values[0]=0.0f;}}c->rasterColor[0]=c->rasterColor[1]=c->rasterColor[2]=1.0f;c->rasterColor[3]=1.0f;c->rasterTexCoord[3]=1.0f;c->rasterPosition[3]=1.0f;c->rasterValid=GL_TRUE;c->matrixMode=GL_MODELVIEW;c->depthNear=0.0;c->depthFar=1.0;c->nextTextureName=1;c->nextHostTextureId=3;c->nextListName=1;npgl_init_texture_object(&c->defaultTexture1D,0,1);npgl_init_texture_object(&c->defaultTexture2D,0,2);c->defaultTexture1D.boundOnce=GL_TRUE;c->defaultTexture1D.target=GL_TEXTURE_1D;c->defaultTexture2D.boundOnce=GL_TRUE;c->defaultTexture2D.target=GL_TEXTURE_2D;c->boundTexture1D=&c->defaultTexture1D;c->boundTexture2D=&c->defaultTexture2D;c->vertexArray.size=4;c->vertexArray.type=GL_FLOAT;c->normalArray.size=3;c->normalArray.type=GL_FLOAT;c->colorArray.size=4;c->colorArray.type=GL_FLOAT;c->indexArray.size=1;c->indexArray.type=GL_FLOAT;c->texCoordArray.size=4;c->texCoordArray.type=GL_FLOAT;c->edgeFlagArray.size=1;c->edgeFlagArray.type=GL_UNSIGNED_BYTE;npgl_init_lighting(c);npgl_init_evaluators(c);npgl_identity(c->modelview);npgl_identity(c->projection);npgl_identity(c->texture);
    if(!npgl_update_drawable(c)){HeapFree(GetProcessHeap(),0,c);return 0;}
    packet.size=sizeof(packet);packet.context=c->bridgeContext;if(!npgl_host_call(NPDISP_OGL_CMD_CONTEXT_CREATE,&packet)){HeapFree(GetProcessHeap(),0,c);return 0;}
    return (DHGLRC)c;
}
DHGLRC APIENTRY DrvCreateLayerContext(HDC hdc, int layer) { if(layer!=0)return 0;return DrvCreateContext(hdc); }
BOOL APIENTRY DrvDeleteContext(DHGLRC h)
{
    NPGL_CONTEXT *c=npgl_context_from_handle(h);NPDISP_OGL_CONTEXT32 p;if(!c)return FALSE;if(npgl_current()==c)TlsSetValue(g_tlsIndex,NULL);p.size=sizeof(p);p.context=c->bridgeContext;npgl_host_call(NPDISP_OGL_CMD_CONTEXT_DESTROY,&p);if(c->vertices)HeapFree(GetProcessHeap(),0,c->vertices);npgl_free_textures(c);npgl_free_lists(c);HeapFree(GetProcessHeap(),0,c);return TRUE;
}
PGLCLTPROCTABLE APIENTRY DrvSetContext(HDC hdc, DHGLRC h, PFN_SETPROCTABLE setProc)
{
    NPGL_CONTEXT *c=npgl_context_from_handle(h);(void)setProc;if(!c)return NULL;if(c->hdc!=hdc){c->hdc=hdc;c->drawableWindow=NULL;c->drawableValid=GL_FALSE;c->drawableDirty=GL_TRUE;}if(!npgl_update_drawable(c))return NULL;c->drawableDirty=GL_TRUE;if(g_tlsIndex!=TLS_OUT_OF_INDEXES)TlsSetValue(g_tlsIndex,c);npgl_init_dispatch();return &g_procTable;
}
BOOL APIENTRY DrvReleaseContext(DHGLRC h) { NPGL_CONTEXT *c=npgl_context_from_handle(h);if(g_tlsIndex!=TLS_OUT_OF_INDEXES&&npgl_current()==c)TlsSetValue(g_tlsIndex,NULL);return TRUE; }
BOOL APIENTRY DrvCopyContext(DHGLRC src, DHGLRC dst, UINT mask) { (void)src;(void)dst;(void)mask;return FALSE; }
BOOL APIENTRY DrvShareLists(DHGLRC a, DHGLRC b) { (void)a;(void)b;return TRUE; }
PROC APIENTRY DrvGetProcAddress(LPCSTR name) { (void)name;return NULL; }
BOOL APIENTRY DrvValidateVersion(ULONG version) { return (version==1 || version==0); }
VOID APIENTRY DrvSetCallbackProcs(INT n, PROC *p) { (void)n;(void)p; }

LONG APIENTRY DrvDescribePixelFormat(HDC hdc, INT format, ULONG bytes, PIXELFORMATDESCRIPTOR *pfd)
{
    int bits;
    BOOL doubleBuffered;
    BOOL stencil;
    if(format==0)return NPGL_PIXEL_FORMAT_COUNT;
    if(format<1||format>NPGL_PIXEL_FORMAT_COUNT)return 0;
    if(!pfd||bytes<sizeof(*pfd))return NPGL_PIXEL_FORMAT_COUNT;
    memset(pfd,0,sizeof(*pfd));pfd->nSize=sizeof(*pfd);pfd->nVersion=1;
    doubleBuffered=(format<=2||format==NPGL_PIXEL_FORMAT_NO_DEPTH_DOUBLE); stencil=(format==2||format==4);
    pfd->dwFlags=PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL;
    if(doubleBuffered)pfd->dwFlags|=PFD_DOUBLEBUFFER|PFD_SWAP_COPY;
    pfd->iPixelType=PFD_TYPE_RGBA;bits=GetDeviceCaps(hdc,BITSPIXEL)*GetDeviceCaps(hdc,PLANES);if(bits<=0)bits=32;
    pfd->cColorBits=(BYTE)bits;
    if(bits>=24){pfd->cRedBits=8;pfd->cGreenBits=8;pfd->cBlueBits=8;pfd->cAlphaBits=0;}
    else if(bits==16){pfd->cRedBits=5;pfd->cGreenBits=6;pfd->cBlueBits=5;}
    if(format==NPGL_PIXEL_FORMAT_NO_DEPTH_DOUBLE||format==NPGL_PIXEL_FORMAT_NO_DEPTH_SINGLE){pfd->cDepthBits=0;pfd->cStencilBits=0;}
    else if(stencil){pfd->cDepthBits=12;pfd->cStencilBits=4;}else{pfd->cDepthBits=16;pfd->cStencilBits=0;}
    pfd->iLayerType=PFD_MAIN_PLANE;
    return NPGL_PIXEL_FORMAT_COUNT;
}
BOOL APIENTRY DrvSetPixelFormat(HDC hdc, LONG format)
{
    BOOL ok=(format>=1&&format<=NPGL_PIXEL_FORMAT_COUNT);
    if(ok)npgl_remember_pixel_format(hdc,(GLint)format);
    return ok;
}
BOOL APIENTRY DrvSwapBuffers(HDC hdc)
{
    NPGL_CONTEXT *c=npgl_current();DWORD result;if(!c)return FALSE;if(hdc&&c->hdc!=hdc){c->hdc=hdc;c->drawableWindow=NULL;c->drawableValid=GL_FALSE;c->drawableDirty=GL_TRUE;}result=npgl_swap_context(c);return result!=0;
}
BOOL APIENTRY DrvDescribeLayerPlane(HDC hdc, INT pf, INT layer, UINT bytes, LPLAYERPLANEDESCRIPTOR p) { (void)hdc;(void)pf;(void)layer;(void)bytes;(void)p;return FALSE; }
INT APIENTRY DrvSetLayerPaletteEntries(HDC hdc, INT layer, INT start, INT count, CONST COLORREF *p) { (void)hdc;(void)layer;(void)start;(void)count;(void)p;return 0; }
INT APIENTRY DrvGetLayerPaletteEntries(HDC hdc, INT layer, INT start, INT count, COLORREF *p) { (void)hdc;(void)layer;(void)start;(void)count;(void)p;return 0; }
BOOL APIENTRY DrvRealizeLayerPalette(HDC hdc, INT layer, BOOL realize) { (void)hdc;(void)layer;(void)realize;return FALSE; }
BOOL APIENTRY DrvSwapLayerBuffers(HDC hdc, UINT planes) { (void)planes;return DrvSwapBuffers(hdc); }

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
    (void)instance;(void)reserved;
    if(reason==DLL_PROCESS_ATTACH){memset(g_pixelFormatBindings,0,sizeof(g_pixelFormatBindings));g_tlsIndex=TlsAlloc();if(g_tlsIndex==TLS_OUT_OF_INDEXES)return FALSE;npgl_init_dispatch();}
    else if(reason==DLL_PROCESS_DETACH){if(g_tlsIndex!=TLS_OUT_OF_INDEXES){TlsFree(g_tlsIndex);g_tlsIndex=TLS_OUT_OF_INDEXES;}}
    return TRUE;
}
