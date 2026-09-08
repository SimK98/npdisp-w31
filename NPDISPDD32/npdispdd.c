#include <stddef.h>

typedef unsigned long DWORD;
typedef int BOOL;

#ifndef WINAPI
#define WINAPI __stdcall
#endif

#define DLL_PROCESS_ATTACH 1

#define NPDISP_DDHALINFO_GETDRIVERINFO      416
#define NPDISP_DDHALINFO_HINSTANCE          444
#define NPDISP_DDHALINFO_D3DGLOBAL          448
#define NPDISP_DDHALINFO_D3DCALLBACKS        452
#define NPDISP_DDHALINFO_DDEXEBUFCALLBACKS   456

#define NPDISP_DDCALLBACKS_SIZE              48
#define NPDISP_DDCALLBACKS_FLAGS              4
#define NPDISP_DDCALLBACKS_CREATESURFACE     12
#define NPDISP_DDCALLBACKS_SETCOLORKEY       16
#define NPDISP_DDCALLBACKS_SETMODE           20
#define NPDISP_DDCALLBACKS_WAITVB            24
#define NPDISP_DDCALLBACKS_CANCREATESURFACE  28
#define NPDISP_DDCALLBACKS_CREATEPALETTE     32
#define NPDISP_DDCALLBACKS_GETSCANLINE       36
#define NPDISP_DDCALLBACKS_SETEXCLUSIVEMODE  40
#define NPDISP_DDCALLBACKS_FLIPTOGDI         44

#define NPDISP_DDHAL_CB32_CREATESURFACE      0x00000002UL
#define NPDISP_DDHAL_CB32_SETCOLORKEY        0x00000004UL
#define NPDISP_DDHAL_CB32_SETMODE            0x00000008UL
#define NPDISP_DDHAL_CB32_WAITVB             0x00000010UL
#define NPDISP_DDHAL_CB32_CANCREATESURFACE   0x00000020UL
#define NPDISP_DDHAL_CB32_CREATEPALETTE      0x00000040UL
#define NPDISP_DDHAL_CB32_GETSCANLINE        0x00000080UL
#define NPDISP_DDHAL_CB32_SETEXCLUSIVEMODE   0x00000100UL
#define NPDISP_DDHAL_CB32_FLIPTOGDI          0x00000200UL
#define NPDISP_DDHAL_CB32_SUPPORTED          0x000003FEUL

#define NPDISP_DDSURFACECALLBACKS_SIZE        64
#define NPDISP_DDSURFACECALLBACKS_FLAGS        4
#define NPDISP_DDSURFACECALLBACKS_DESTROY      8
#define NPDISP_DDSURFACECALLBACKS_FLIP        12
#define NPDISP_DDSURFACECALLBACKS_SETCLIPLIST 16
#define NPDISP_DDSURFACECALLBACKS_LOCK        20
#define NPDISP_DDSURFACECALLBACKS_UNLOCK      24
#define NPDISP_DDSURFACECALLBACKS_BLT         28
#define NPDISP_DDSURFACECALLBACKS_SETCOLORKEY 32
#define NPDISP_DDSURFACECALLBACKS_ADDATTACHED 36
#define NPDISP_DDSURFACECALLBACKS_GETBLTSTATUS 40
#define NPDISP_DDSURFACECALLBACKS_GETFLIPSTATUS 44
#define NPDISP_DDSURFACECALLBACKS_UPDATEOVERLAY 48
#define NPDISP_DDSURFACECALLBACKS_SETOVERLAYPOS 52
#define NPDISP_DDSURFACECALLBACKS_SETPALETTE  60

#define NPDISP_DDHAL_SURFCB32_DESTROY          0x00000001UL
#define NPDISP_DDHAL_SURFCB32_FLIP             0x00000002UL
#define NPDISP_DDHAL_SURFCB32_SETCLIPLIST      0x00000004UL
#define NPDISP_DDHAL_SURFCB32_LOCK             0x00000008UL
#define NPDISP_DDHAL_SURFCB32_UNLOCK           0x00000010UL
#define NPDISP_DDHAL_SURFCB32_BLT              0x00000020UL
#define NPDISP_DDHAL_SURFCB32_SETCOLORKEY      0x00000040UL
#define NPDISP_DDHAL_SURFCB32_ADDATTACHED      0x00000080UL
#define NPDISP_DDHAL_SURFCB32_GETBLTSTATUS     0x00000100UL
#define NPDISP_DDHAL_SURFCB32_GETFLIPSTATUS    0x00000200UL
#define NPDISP_DDHAL_SURFCB32_UPDATEOVERLAY    0x00000400UL
#define NPDISP_DDHAL_SURFCB32_SETOVERLAYPOS    0x00000800UL
#define NPDISP_DDHAL_SURFCB32_SETPALETTE       0x00002000UL
#define NPDISP_DDHAL_SURFCB32_SUPPORTED        0x00002FFFUL

#define NPDISP_DDPALETTECALLBACKS_SIZE          16
#define NPDISP_DDPALETTECALLBACKS_FLAGS          4
#define NPDISP_DDPALETTECALLBACKS_DESTROY        8
#define NPDISP_DDPALETTECALLBACKS_SETENTRIES    12
#define NPDISP_DDHAL_PALCB32_DESTROY            0x00000001UL
#define NPDISP_DDHAL_PALCB32_SETENTRIES         0x00000002UL
#define NPDISP_DDHAL_PALCB32_SUPPORTED          0x00000003UL

#define NPDISP_DDBRIDGE_V2_MAGIC                 0x3242444eUL /* "NDB2" */
#define NPDISP_DDBRIDGE_ABI_V2                   0x00020000UL
#define NPDISP_DDBRIDGE_ABI_MAJOR_MASK           0xffff0000UL
#define NPDISP_DDBRIDGE_STATUS_HOST_READY        0x00000001UL
#define NPDISP_DDBRIDGE_STATUS_DRIVER_READY      0x00000002UL
#define NPDISP_DDBRIDGE_STATUS_FAILED            0xffffffffUL
#define NPDISP_DDBRIDGE_FEATURE_GETDRIVERINFO    0x00000001UL
#define NPDISP_DDBRIDGE_FEATURE_D3D_HAL          0x00000002UL
#define NPDISP_DDBRIDGE_FEATURE_D3D_SHARED_DATA   0x00000004UL
#define NPDISP_DDBRIDGE_FEATURE_SUPPORTED        (NPDISP_DDBRIDGE_FEATURE_GETDRIVERINFO | NPDISP_DDBRIDGE_FEATURE_D3D_HAL | NPDISP_DDBRIDGE_FEATURE_D3D_SHARED_DATA)
#define NPDISP_DDBRIDGE_D3D_PROFILE_NONE         0x00000000UL
#define NPDISP_D3D_PROFILE_1                      0x00010000UL

#define NPDISP_EXEC_MAGIC_LOW                    0x0000504eUL
#define NPDISP_EXEC_PORT                         0x07e9
#define NPDISP_EXEC_COMMAND                      0x46
#define NPDISP_FUNCORDER_DD32_DISPATCH           0xfe30UL

#define NPDISP_DDHAL_DRIVER_NOTHANDLED            0x00000000UL
#define NPDISP_DDHAL_DRIVER_HANDLED               0x00000001UL
#define NPDISP_DDWAITVB_BLOCKBEGIN                0x00000001UL
#define NPDISP_DDWAITVB_BLOCKEND                  0x00000004UL
#define NPDISP_DDWAITVB_I_TESTVB                  0x80000006UL

typedef struct {
    DWORD lpDD;
    DWORD dwFlags;
    DWORD bIsInVB;
    DWORD hEvent;
    DWORD ddRVal;
    DWORD WaitForVerticalBlank;
} NPDISP_DDHAL_WAITVBDATA32;

typedef struct {
    DWORD dwSize;
    DWORD dwMagic;
    DWORD dwAbiVersion;
    DWORD dwStatus;
    DWORD dwHostFeaturesOffered;
    DWORD dwDriverFeaturesSupported;
    DWORD dwNegotiatedFeatures;
    DWORD dwD3DProfileId;
    DWORD lpDDHalInfo;
    DWORD lpDDCallbacks;
    DWORD lpDDSurfaceCallbacks;
    DWORD lpDDPaletteCallbacks;
    DWORD dwDDRequestMask;
    DWORD dwSurfaceRequestMask;
    DWORD dwPaletteRequestMask;
    DWORD lpD3DGlobalDriverData;
    DWORD lpD3DHALCallbacks;
    DWORD dwReserved[3];
} NPDISP_DDBRIDGEINFO32;

typedef char NPDISP_DDBRIDGEINFO32_SIZE_CHECK[(sizeof(NPDISP_DDBRIDGEINFO32) == 80) ? 1 : -1];
typedef char NPDISP_DDBRIDGEINFO32_HAL_OFFSET_CHECK[(offsetof(NPDISP_DDBRIDGEINFO32, lpDDHalInfo) == 32) ? 1 : -1];
typedef char NPDISP_DDBRIDGEINFO32_MASK_OFFSET_CHECK[(offsetof(NPDISP_DDBRIDGEINFO32, dwDDRequestMask) == 48) ? 1 : -1];
typedef char NPDISP_DDBRIDGEINFO32_D3D_OFFSET_CHECK[(offsetof(NPDISP_DDBRIDGEINFO32, lpD3DGlobalDriverData) == 60) ? 1 : -1];


typedef struct {
    DWORD dwSize;
    DWORD dwCaps;
} NPDISP_D3DTRANSFORMCAPS32;

typedef struct {
    DWORD dwSize;
    DWORD dwCaps;
    DWORD dwLightingModel;
    DWORD dwNumLights;
} NPDISP_D3DLIGHTINGCAPS32;

typedef struct {
    DWORD dwSize;
    DWORD dwMiscCaps;
    DWORD dwRasterCaps;
    DWORD dwZCmpCaps;
    DWORD dwSrcBlendCaps;
    DWORD dwDestBlendCaps;
    DWORD dwAlphaCmpCaps;
    DWORD dwShadeCaps;
    DWORD dwTextureCaps;
    DWORD dwTextureFilterCaps;
    DWORD dwTextureBlendCaps;
    DWORD dwTextureAddressCaps;
    DWORD dwStippleWidth;
    DWORD dwStippleHeight;
} NPDISP_D3DPRIMCAPS32;

typedef struct {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dcmColorModel;
    DWORD dwDevCaps;
    NPDISP_D3DTRANSFORMCAPS32 dtcTransformCaps;
    DWORD bClipping;
    NPDISP_D3DLIGHTINGCAPS32 dlcLightingCaps;
    NPDISP_D3DPRIMCAPS32 dpcLineCaps;
    NPDISP_D3DPRIMCAPS32 dpcTriCaps;
    DWORD dwDeviceRenderBitDepth;
    DWORD dwDeviceZBufferBitDepth;
    DWORD dwMaxBufferSize;
    DWORD dwMaxVertexCount;
} NPDISP_D3DDEVICEDESC_V1_32;

typedef struct {
    DWORD dwSize;
    NPDISP_D3DDEVICEDESC_V1_32 hwCaps;
    DWORD dwNumVertices;
    DWORD dwNumClipVertices;
    DWORD dwNumTextureFormats;
    DWORD lpTextureFormats;
} NPDISP_D3DHAL_GLOBALDRIVERDATA32;

typedef struct {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD dwFourCC;
    DWORD dwZBufferBitDepth;
    DWORD dwStencilBitDepth;
    DWORD dwZBitMask;
    DWORD dwStencilBitMask;
    DWORD dwRGBZBitMask;
} NPDISP_DDPIXELFORMAT32;

typedef char NPDISP_DDPIXELFORMAT32_SIZE_CHECK[(sizeof(NPDISP_DDPIXELFORMAT32) == 32) ? 1 : -1];

typedef struct {
    DWORD dwCount;
    NPDISP_DDPIXELFORMAT32 formats[1];
} NPDISP_DDZPIXELFORMATS32;

typedef char NPDISP_DDZPIXELFORMATS32_SIZE_CHECK[(sizeof(NPDISP_DDZPIXELFORMATS32) == 36) ? 1 : -1];

typedef struct {
    DWORD dwSize;
    DWORD ContextCreate;
    DWORD ContextDestroy;
    DWORD ContextDestroyAll;
    DWORD SceneCapture;
    DWORD lpReserved10;
    DWORD lpReserved11;
    DWORD RenderState;
    DWORD RenderPrimitive;
    DWORD dwReserved;
    DWORD TextureCreate;
    DWORD TextureDestroy;
    DWORD TextureSwap;
    DWORD TextureGetSurf;
    DWORD lpReserved12;
    DWORD lpReserved13;
    DWORD lpReserved14;
    DWORD lpReserved15;
    DWORD lpReserved16;
    DWORD lpReserved17;
    DWORD lpReserved18;
    DWORD lpReserved19;
    DWORD lpReserved20;
    DWORD lpReserved21;
    DWORD GetState;
    DWORD dwReserved0;
    DWORD dwReserved1;
    DWORD dwReserved2;
    DWORD dwReserved3;
    DWORD dwReserved4;
    DWORD dwReserved5;
    DWORD dwReserved6;
    DWORD dwReserved7;
    DWORD dwReserved8;
    DWORD dwReserved9;
} NPDISP_D3DHAL_CALLBACKS32;

typedef struct {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD SetRenderTarget;
    DWORD Clear;
    DWORD DrawOnePrimitive;
    DWORD DrawOneIndexedPrimitive;
    DWORD DrawPrimitives;
} NPDISP_D3DHAL_CALLBACKS2_32;

typedef struct {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD Clear2;
    DWORD lpvReserved;
    DWORD ValidateTextureStageState;
    DWORD DrawPrimitives2;
} NPDISP_D3DHAL_CALLBACKS3_32;

typedef struct {
    DWORD dwhContext;
    DWORD dwFlags;
    DWORD dwReserved;
    DWORD dwNumPasses;
    DWORD ddrval;
} NPDISP_D3DHAL_VALIDATETEXTURESTAGESTATEDATA32;

/* DirectX 7 runtime が参照する extended caps を固定32bit layoutで返す。 */
typedef struct {
    DWORD dwSize;
    DWORD dwMinTextureWidth;
    DWORD dwMaxTextureWidth;
    DWORD dwMinTextureHeight;
    DWORD dwMaxTextureHeight;
    DWORD dwMinStippleWidth;
    DWORD dwMaxStippleWidth;
    DWORD dwMinStippleHeight;
    DWORD dwMaxStippleHeight;
    DWORD dwMaxTextureRepeat;
    DWORD dwMaxTextureAspectRatio;
    DWORD dwMaxAnisotropy;
    float dvGuardBandLeft;
    float dvGuardBandTop;
    float dvGuardBandRight;
    float dvGuardBandBottom;
    float dvExtentsAdjust;
    DWORD dwStencilCaps;
    DWORD dwFVFCaps;
    DWORD dwTextureOpCaps;
    unsigned short wMaxTextureBlendStages;
    unsigned short wMaxSimultaneousTextures;
    DWORD dwMaxActiveLights;
    float dvMaxVertexW;
    unsigned short wMaxUserClipPlanes;
    unsigned short wMaxVertexBlendMatrices;
    DWORD dwVertexProcessingCaps;
    DWORD dwReserved1;
    DWORD dwReserved2;
    DWORD dwReserved3;
    DWORD dwReserved4;
} NPDISP_D3DHAL_D3DEXTENDEDCAPS32;

typedef struct {
    DWORD dwSize;
    DWORD dwFlags;
    DWORD AlphaBlt;
    DWORD CreateSurfaceEx;
    DWORD GetDriverState;
    DWORD DestroyDDLocal;
} NPDISP_DD_MISCELLANEOUS2CALLBACKS32;

typedef struct {
    DWORD dwFlags;
    DWORD dwhContext;
    DWORD lpdwStates;
    DWORD dwLength;
    DWORD ddRVal;
} NPDISP_DD_GETDRIVERSTATEDATA32;

typedef struct {
    DWORD bThrashing;
    DWORD dwApproxBytesDownloaded;
    DWORD dwNumEvicts;
    DWORD dwNumVidCreates;
    DWORD dwNumTexturesUsed;
    DWORD dwNumUsedTexInVid;
    DWORD dwWorkingSet;
    DWORD dwWorkingSetBytes;
    DWORD dwTotalManaged;
    DWORD dwTotalBytes;
    DWORD dwLastPri;
} NPDISP_D3DDEVINFO_TEXTUREMANAGER32;

typedef struct {
    DWORD dwNumLoads;
    DWORD dwApproxBytesLoaded;
    DWORD dwNumPreLoads;
    DWORD dwNumSet;
    DWORD dwNumCreates;
    DWORD dwNumDestroys;
    DWORD dwNumSetPriorities;
    DWORD dwNumSetLODs;
    DWORD dwNumLocks;
    DWORD dwNumGetDCs;
} NPDISP_D3DDEVINFO_TEXTURING32;

typedef struct {
    DWORD Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} NPDISP_GUID32;

typedef struct {
    DWORD dwSize;
    DWORD dwFlags;
    NPDISP_GUID32 guidInfo;
    DWORD dwExpectedSize;
    DWORD lpvData;
    DWORD dwActualSize;
    DWORD ddRVal;
    DWORD dwContext;
} NPDISP_DD_GETDRIVERINFODATA32;

typedef char NPDISP_D3DDEVICEDESC_V1_32_SIZE_CHECK[(sizeof(NPDISP_D3DDEVICEDESC_V1_32) == 172) ? 1 : -1];
typedef char NPDISP_D3DHAL_GLOBALDRIVERDATA32_SIZE_CHECK[(sizeof(NPDISP_D3DHAL_GLOBALDRIVERDATA32) == 192) ? 1 : -1];
typedef char NPDISP_D3DHAL_CALLBACKS32_SIZE_CHECK[(sizeof(NPDISP_D3DHAL_CALLBACKS32) == 140) ? 1 : -1];
typedef char NPDISP_D3DHAL_CALLBACKS2_32_SIZE_CHECK[(sizeof(NPDISP_D3DHAL_CALLBACKS2_32) == 28) ? 1 : -1];
typedef char NPDISP_D3DHAL_CALLBACKS3_32_SIZE_CHECK[(sizeof(NPDISP_D3DHAL_CALLBACKS3_32) == 24) ? 1 : -1];
typedef char NPDISP_D3DHAL_D3DEXTENDEDCAPS32_SIZE_CHECK[(sizeof(NPDISP_D3DHAL_D3DEXTENDEDCAPS32) == 116) ? 1 : -1];
typedef char NPDISP_DD_MISCELLANEOUS2CALLBACKS32_SIZE_CHECK[(sizeof(NPDISP_DD_MISCELLANEOUS2CALLBACKS32) == 24) ? 1 : -1];
typedef char NPDISP_DD_GETDRIVERINFODATA32_SIZE_CHECK[(sizeof(NPDISP_DD_GETDRIVERINFODATA32) == 44) ? 1 : -1];

/* 固定2DブリッジではEDIにコールバックIDを渡す。 */
#define NPDISP_DDBRIDGE_CB_DD_CREATESURFACE      0x0001UL
#define NPDISP_DDBRIDGE_CB_DD_SETCOLORKEY        0x0002UL
#define NPDISP_DDBRIDGE_CB_DD_SETMODE            0x0003UL
#define NPDISP_DDBRIDGE_CB_DD_WAITVB             0x0004UL
#define NPDISP_DDBRIDGE_CB_DD_CANCREATESURFACE   0x0005UL
#define NPDISP_DDBRIDGE_CB_DD_CREATEPALETTE      0x0006UL
#define NPDISP_DDBRIDGE_CB_DD_GETSCANLINE        0x0007UL
#define NPDISP_DDBRIDGE_CB_DD_SETEXCLUSIVEMODE   0x0008UL
#define NPDISP_DDBRIDGE_CB_DD_FLIPTOGDI          0x0009UL
#define NPDISP_DDBRIDGE_CB_DD_GETDRIVERINFO      0x000aUL

#define NPDISP_DDBRIDGE_CB_SURF_DESTROY           0x0100UL
#define NPDISP_DDBRIDGE_CB_SURF_FLIP              0x0101UL
#define NPDISP_DDBRIDGE_CB_SURF_SETCLIPLIST       0x0102UL
#define NPDISP_DDBRIDGE_CB_SURF_LOCK              0x0103UL
#define NPDISP_DDBRIDGE_CB_SURF_UNLOCK            0x0104UL
#define NPDISP_DDBRIDGE_CB_SURF_BLT               0x0105UL
#define NPDISP_DDBRIDGE_CB_SURF_SETCOLORKEY       0x0106UL
#define NPDISP_DDBRIDGE_CB_SURF_ADDATTACHED       0x0107UL
#define NPDISP_DDBRIDGE_CB_SURF_GETBLTSTATUS      0x0108UL
#define NPDISP_DDBRIDGE_CB_SURF_GETFLIPSTATUS     0x0109UL
#define NPDISP_DDBRIDGE_CB_SURF_UPDATEOVERLAY     0x010aUL
#define NPDISP_DDBRIDGE_CB_SURF_SETOVERLAYPOS     0x010bUL
#define NPDISP_DDBRIDGE_CB_SURF_SETPALETTE        0x010dUL

#define NPDISP_DDBRIDGE_CB_PAL_DESTROY             0x0200UL
#define NPDISP_DDBRIDGE_CB_PAL_SETENTRIES          0x0201UL

#define NPDISP_DDBRIDGE_CB_D3D_CONTEXTCREATE       0x0300UL
#define NPDISP_DDBRIDGE_CB_D3D_CONTEXTDESTROY      0x0301UL
#define NPDISP_DDBRIDGE_CB_D3D_CONTEXTDESTROYALL   0x0302UL
#define NPDISP_DDBRIDGE_CB_D3D_RENDERSTATE         0x0303UL
#define NPDISP_DDBRIDGE_CB_D3D_RENDERPRIMITIVE     0x0304UL
#define NPDISP_DDBRIDGE_CB_D3D_GETSTATE            0x0305UL
#define NPDISP_DDBRIDGE_CB_D3D_SCENECAPTURE        0x0306UL
#define NPDISP_DDBRIDGE_CB_D3D_DESTROYDDLOCAL      0x0311UL
#define NPDISP_DDBRIDGE_CB_D3D_SETRENDERTARGET     0x0320UL
#define NPDISP_DDBRIDGE_CB_D3D_CLEAR               0x0321UL
#define NPDISP_DDBRIDGE_CB_D3D_DRAWONEPRIMITIVE    0x0322UL
#define NPDISP_DDBRIDGE_CB_D3D_DRAWONEINDEXEDPRIMITIVE 0x0323UL
#define NPDISP_DDBRIDGE_CB_D3D_DRAWPRIMITIVES      0x0324UL
#define NPDISP_DDBRIDGE_CB_D3D_DRAWPRIMITIVES2     0x0330UL
#define NPDISP_DDBRIDGE_CB_D3D_CREATESURFACEEX     0x0310UL

#define NPDISP_D3DDD_COLORMODEL                     0x00000001UL
#define NPDISP_D3DDD_DEVCAPS                        0x00000002UL
#define NPDISP_D3DDD_TRANSFORMCAPS                  0x00000004UL
#define NPDISP_D3DDD_LIGHTINGCAPS                   0x00000008UL
#define NPDISP_D3DDD_BCLIPPING                      0x00000010UL
#define NPDISP_D3DDD_LINECAPS                       0x00000020UL
#define NPDISP_D3DDD_TRICAPS                        0x00000040UL
#define NPDISP_D3DDD_DEVICERENDERBITDEPTH           0x00000080UL
#define NPDISP_D3DDD_DEVICEZBUFFERBITDEPTH           0x00000100UL
#define NPDISP_D3DDD_MAXVERTEXCOUNT                  0x00000400UL
#define NPDISP_D3DPRASTERCAPS_ZTEST                  0x00000010UL
#define NPDISP_D3DPCMPCAPS_ALL                       0x000000ffUL
#define NPDISP_D3DDEVCAPS_FLOATTLVERTEX             0x00000001UL
#define NPDISP_D3DDEVCAPS_EXECUTESYSTEMMEMORY       0x00000010UL
#define NPDISP_D3DDEVCAPS_TLVERTEXSYSTEMMEMORY      0x00000040UL
#define NPDISP_D3DDEVCAPS_DRAWPRIMTLVERTEX          0x00000400UL
#define NPDISP_D3DDEVCAPS_DRAWPRIMITIVES2            0x00002000UL
#define NPDISP_D3DDEVCAPS_DRAWPRIMITIVES2EX          0x00008000UL
#define NPDISP_D3DDEVCAPS_HWRASTERIZATION             0x00080000UL
#define NPDISP_D3DCOLOR_RGB                          0x00000002UL
#define NPDISP_D3DPMISCCAPS_CULLNONE                 0x00000010UL
#define NPDISP_D3DPMISCCAPS_CULLCW                   0x00000020UL
#define NPDISP_D3DPMISCCAPS_CULLCCW                  0x00000040UL
#define NPDISP_D3DPSHADECAPS_COLORFLATRGB            0x00000002UL
#define NPDISP_D3DPSHADECAPS_COLORGOURAUDRGB         0x00000008UL
#define NPDISP_D3DHAL2_CB32_SETRENDERTARGET          0x00000001UL
#define NPDISP_D3DHAL2_CB32_CLEAR                    0x00000002UL
#define NPDISP_D3DHAL2_CB32_DRAWONEPRIMITIVE         0x00000004UL
#define NPDISP_D3DHAL2_CB32_DRAWONEINDEXEDPRIMITIVE  0x00000008UL
#define NPDISP_D3DHAL2_CB32_DRAWPRIMITIVES           0x00000010UL
#define NPDISP_D3DHAL3_CB32_VALIDATETEXTURESTAGESTATE 0x00000004UL
#define NPDISP_D3DHAL3_CB32_DRAWPRIMITIVES2          0x00000008UL
#define NPDISP_DDBD_16                               0x00000400UL
#define NPDISP_DDBD_24                               0x00000200UL
#define NPDISP_DDBD_32                               0x00000100UL
#define NPDISP_DDHAL_MISC2CB32_CREATESURFACEEX       0x00000002UL
#define NPDISP_DDHAL_MISC2CB32_GETDRIVERSTATE        0x00000004UL
#define NPDISP_DDHAL_MISC2CB32_DESTROYDDLOCAL        0x00000008UL
#define NPDISP_D3DDEVINFOID_TEXTUREMANAGER           0x00000001UL
#define NPDISP_D3DDEVINFOID_D3DTEXTUREMANAGER        0x00000002UL
#define NPDISP_D3DDEVINFOID_TEXTURING                 0x00000003UL
#define NPDISP_DDERR_CURRENTLYNOTAVAIL                0x88760028UL

/*
 * Win9xのDirectDrawはHAL DLLを共有アドレス領域へロードするため、
 * プロセス間で使用する状態は共有セクションに置く。
 */
#pragma data_seg(".npddshr")
static DWORD npdispdd_hInstance = 0xFFFFFFFFUL;
#pragma data_seg()

/*
 * 2DコールバックはESIにLPDDHAL_*DATA、EDIにコールバックIDを設定して
 * np21/wへ転送する。戻り値はEAXのDDHAL_DRIVER_*。
 */
static DWORD npdispdd_host_call(DWORD callbackId, void *lpData)
{
    DWORD result;

    __asm {
        push ebx
        push esi
        push edi
        mov  ebx, NPDISP_FUNCORDER_DD32_DISPATCH
        mov  esi, lpData
        mov  edi, callbackId
        mov  ecx, NPDISP_EXEC_MAGIC_LOW
        mov  dx, NPDISP_EXEC_PORT
        mov  al, NPDISP_EXEC_COMMAND
        out  dx, al
        mov  result, eax
        pop  edi
        pop  esi
        pop  ebx
    }
    return result;
}

#define NPDISP_DDBRIDGE_WRAPPER(name, id) \
    static DWORD WINAPI name(void *lpData) { return npdispdd_host_call((id), lpData); }

NPDISP_DDBRIDGE_WRAPPER(npdispdd_CreateSurface,       NPDISP_DDBRIDGE_CB_DD_CREATESURFACE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_DriverSetColorKey,   NPDISP_DDBRIDGE_CB_DD_SETCOLORKEY)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_SetMode,             NPDISP_DDBRIDGE_CB_DD_SETMODE)
/*
 * Blocking vertical-blank waits are implemented here rather than in one host
 * callback. Every TESTVB transaction returns to guest execution, allowing the
 * emulator's normal event scheduler to advance the raster state.
 */
static DWORD npdispdd_test_vblank(NPDISP_DDHAL_WAITVBDATA32 *data, DWORD *inVBlank)
{
    DWORD result;

    data->dwFlags = NPDISP_DDWAITVB_I_TESTVB;
    result = npdispdd_host_call(NPDISP_DDBRIDGE_CB_DD_WAITVB, data);
    if (result == NPDISP_DDHAL_DRIVER_HANDLED) {
        *inVBlank = data->bIsInVB ? 1UL : 0UL;
    }
    return result;
}

static DWORD WINAPI npdispdd_WaitForVerticalBlank(void *lpData)
{
    NPDISP_DDHAL_WAITVBDATA32 *data;
    DWORD originalFlags;
    DWORD inVBlank;
    DWORD result;

    if (!lpData) return NPDISP_DDHAL_DRIVER_NOTHANDLED;
    data = (NPDISP_DDHAL_WAITVBDATA32 *)lpData;
    originalFlags = data->dwFlags;

    if (originalFlags == NPDISP_DDWAITVB_I_TESTVB) {
        return npdispdd_host_call(NPDISP_DDBRIDGE_CB_DD_WAITVB, data);
    }
    if (originalFlags != NPDISP_DDWAITVB_BLOCKBEGIN &&
        originalFlags != NPDISP_DDWAITVB_BLOCKEND) {
        return npdispdd_host_call(NPDISP_DDBRIDGE_CB_DD_WAITVB, data);
    }

    result = npdispdd_test_vblank(data, &inVBlank);
    if (result != NPDISP_DDHAL_DRIVER_HANDLED) {
        data->dwFlags = originalFlags;
        return result;
    }

    if (originalFlags == NPDISP_DDWAITVB_BLOCKBEGIN) {
        /* A call made during VBlank waits for the following VBlank begin. */
        while (inVBlank) {
            result = npdispdd_test_vblank(data, &inVBlank);
            if (result != NPDISP_DDHAL_DRIVER_HANDLED) {
                data->dwFlags = originalFlags;
                return result;
            }
        }
        while (!inVBlank) {
            result = npdispdd_test_vblank(data, &inVBlank);
            if (result != NPDISP_DDHAL_DRIVER_HANDLED) {
                data->dwFlags = originalFlags;
                return result;
            }
        }
    }
    else {
        /* Outside VBlank, BLOCKEND is already satisfied. */
        while (inVBlank) {
            result = npdispdd_test_vblank(data, &inVBlank);
            if (result != NPDISP_DDHAL_DRIVER_HANDLED) {
                data->dwFlags = originalFlags;
                return result;
            }
        }
    }

    data->dwFlags = originalFlags;
    data->ddRVal = 0;
    return NPDISP_DDHAL_DRIVER_HANDLED;
}
NPDISP_DDBRIDGE_WRAPPER(npdispdd_CanCreateSurface,    NPDISP_DDBRIDGE_CB_DD_CANCREATESURFACE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_CreatePalette,       NPDISP_DDBRIDGE_CB_DD_CREATEPALETTE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_GetScanLine,         NPDISP_DDBRIDGE_CB_DD_GETSCANLINE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_SetExclusiveMode,    NPDISP_DDBRIDGE_CB_DD_SETEXCLUSIVEMODE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_FlipToGDISurface,    NPDISP_DDBRIDGE_CB_DD_FLIPTOGDI)
static DWORD WINAPI npdispdd_D3DValidateTextureStageState(void *lpData)
{
    NPDISP_D3DHAL_VALIDATETEXTURESTAGESTATEDATA32 *data;

    data = (NPDISP_D3DHAL_VALIDATETEXTURESTAGESTATEDATA32 *)lpData;
    if (!data) return NPDISP_DDHAL_DRIVER_HANDLED;
    data->dwNumPasses = 1;
    data->ddrval = 0;
    return NPDISP_DDHAL_DRIVER_HANDLED;
}

NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DContextCreate,     NPDISP_DDBRIDGE_CB_D3D_CONTEXTCREATE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DContextDestroy,    NPDISP_DDBRIDGE_CB_D3D_CONTEXTDESTROY)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DContextDestroyAll, NPDISP_DDBRIDGE_CB_D3D_CONTEXTDESTROYALL)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DSceneCapture,      NPDISP_DDBRIDGE_CB_D3D_SCENECAPTURE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DRenderState,       NPDISP_DDBRIDGE_CB_D3D_RENDERSTATE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DRenderPrimitive,   NPDISP_DDBRIDGE_CB_D3D_RENDERPRIMITIVE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DGetState,          NPDISP_DDBRIDGE_CB_D3D_GETSTATE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DSetRenderTarget,   NPDISP_DDBRIDGE_CB_D3D_SETRENDERTARGET)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DClear,             NPDISP_DDBRIDGE_CB_D3D_CLEAR)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DDrawOnePrimitive,  NPDISP_DDBRIDGE_CB_D3D_DRAWONEPRIMITIVE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DDrawOneIndexedPrimitive, NPDISP_DDBRIDGE_CB_D3D_DRAWONEINDEXEDPRIMITIVE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DDrawPrimitives,    NPDISP_DDBRIDGE_CB_D3D_DRAWPRIMITIVES)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DDrawPrimitives2,   NPDISP_DDBRIDGE_CB_D3D_DRAWPRIMITIVES2)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DCreateSurfaceEx,   NPDISP_DDBRIDGE_CB_D3D_CREATESURFACEEX)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DDestroyDDLocal,    NPDISP_DDBRIDGE_CB_D3D_DESTROYDDLOCAL)

NPDISP_DDBRIDGE_WRAPPER(npdispdd_DestroySurface,      NPDISP_DDBRIDGE_CB_SURF_DESTROY)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_Flip,                NPDISP_DDBRIDGE_CB_SURF_FLIP)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_SetClipList,         NPDISP_DDBRIDGE_CB_SURF_SETCLIPLIST)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_Lock,                NPDISP_DDBRIDGE_CB_SURF_LOCK)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_Unlock,              NPDISP_DDBRIDGE_CB_SURF_UNLOCK)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_Blt,                 NPDISP_DDBRIDGE_CB_SURF_BLT)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_SetColorKey,         NPDISP_DDBRIDGE_CB_SURF_SETCOLORKEY)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_AddAttachedSurface,  NPDISP_DDBRIDGE_CB_SURF_ADDATTACHED)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_GetBltStatus,        NPDISP_DDBRIDGE_CB_SURF_GETBLTSTATUS)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_GetFlipStatus,       NPDISP_DDBRIDGE_CB_SURF_GETFLIPSTATUS)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_UpdateOverlay,       NPDISP_DDBRIDGE_CB_SURF_UPDATEOVERLAY)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_SetOverlayPosition,  NPDISP_DDBRIDGE_CB_SURF_SETOVERLAYPOS)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_SetPalette,          NPDISP_DDBRIDGE_CB_SURF_SETPALETTE)

NPDISP_DDBRIDGE_WRAPPER(npdispdd_DestroyPalette,      NPDISP_DDBRIDGE_CB_PAL_DESTROY)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_SetEntries,          NPDISP_DDBRIDGE_CB_PAL_SETENTRIES)

static NPDISP_D3DHAL_GLOBALDRIVERDATA32 *npdispdd_d3dGlobal;
static NPDISP_D3DHAL_CALLBACKS32 *npdispdd_d3dCallbacks;
static NPDISP_D3DHAL_CALLBACKS2_32 npdispdd_d3dCallbacks2 = { sizeof(NPDISP_D3DHAL_CALLBACKS2_32) };
static NPDISP_D3DHAL_CALLBACKS3_32 npdispdd_d3dCallbacks3 = { sizeof(NPDISP_D3DHAL_CALLBACKS3_32) };
static NPDISP_D3DHAL_D3DEXTENDEDCAPS32 npdispdd_d3dExtendedCaps = { sizeof(NPDISP_D3DHAL_D3DEXTENDEDCAPS32) };
static NPDISP_DDZPIXELFORMATS32 npdispdd_zPixelFormats;
static NPDISP_DD_MISCELLANEOUS2CALLBACKS32 npdispdd_misc2Callbacks = { sizeof(NPDISP_DD_MISCELLANEOUS2CALLBACKS32) };
static BOOL npdispdd_d3dEnabled;
static DWORD npdispdd_d3dParseUnknownCommand;

static int npdispdd_guid_equal(const NPDISP_GUID32 *a, const NPDISP_GUID32 *b)
{
    int i;
    if (a->Data1 != b->Data1 || a->Data2 != b->Data2 || a->Data3 != b->Data3) return 0;
    for (i = 0; i < 8; i++) if (a->Data4[i] != b->Data4[i]) return 0;
    return 1;
}

static void npdispdd_copy_bytes(void *dst, const void *src, DWORD size)
{
    unsigned char *d = (unsigned char *)dst;
    const unsigned char *s = (const unsigned char *)src;
    while (size--) *d++ = *s++;
}

static void npdispdd_zero_bytes(void *dst, DWORD size)
{
    unsigned char *d = (unsigned char *)dst;
    while (size--) *d++ = 0;
}

static DWORD WINAPI npdispdd_D3DGetDriverState(void *lpData)
{
    NPDISP_DD_GETDRIVERSTATEDATA32 *data;
    DWORD expectedSize;

    data = (NPDISP_DD_GETDRIVERSTATEDATA32 *)lpData;
    if (!data) return NPDISP_DDHAL_DRIVER_HANDLED;

    expectedSize = 0;
    if (data->dwFlags == NPDISP_D3DDEVINFOID_TEXTUREMANAGER || data->dwFlags == NPDISP_D3DDEVINFOID_D3DTEXTUREMANAGER) {
        expectedSize = sizeof(NPDISP_D3DDEVINFO_TEXTUREMANAGER32);
    }
    else if (data->dwFlags == NPDISP_D3DDEVINFOID_TEXTURING) {
        expectedSize = sizeof(NPDISP_D3DDEVINFO_TEXTURING32);
    }

    if (!expectedSize || !data->lpdwStates || data->dwLength < expectedSize) {
        data->ddRVal = NPDISP_DDERR_CURRENTLYNOTAVAIL;
        return NPDISP_DDHAL_DRIVER_HANDLED;
    }

    npdispdd_zero_bytes((void *)data->lpdwStates, expectedSize);
    data->ddRVal = 0;
    return NPDISP_DDHAL_DRIVER_HANDLED;
}

static DWORD WINAPI npdispdd_GetDriverInfo(void *lpData)
{
    static const NPDISP_GUID32 callbacksGuid = { 0x7bf06990UL, 0x8794, 0x11d0, { 0x91, 0x39, 0x08, 0x00, 0x36, 0xd2, 0xef, 0x02 } };
    static const NPDISP_GUID32 callbacks2Guid = { 0x0ba584e1UL, 0x70b6, 0x11d0, { 0x88, 0x9d, 0x00, 0xaa, 0x00, 0xbb, 0xb7, 0x6a } };
    static const NPDISP_GUID32 callbacks3Guid = { 0xddf41230UL, 0xec0a, 0x11d0, { 0xa9, 0xb6, 0x00, 0xaa, 0x00, 0xc0, 0x99, 0x3e } };
    static const NPDISP_GUID32 parseUnknownCommandGuid = { 0x2e04ffa0UL, 0x98e4, 0x11d1, { 0x8c, 0xe1, 0x00, 0xa0, 0xc9, 0x06, 0x29, 0xa8 } };
    static const NPDISP_GUID32 extendedCapsGuid = { 0x7de41f80UL, 0x9d93, 0x11d0, { 0x89, 0xab, 0x00, 0xa0, 0xc9, 0x05, 0x41, 0x29 } };
    static const NPDISP_GUID32 misc2Guid = { 0x406b2f00UL, 0x3e5a, 0x11d1, { 0xb6, 0x40, 0x00, 0xaa, 0x00, 0xa1, 0xf9, 0x6a } };
    static const NPDISP_GUID32 zPixelFormatsGuid = { 0x93869880UL, 0x36cf, 0x11d1, { 0x9b, 0x1b, 0x00, 0xaa, 0x00, 0xbb, 0xb8, 0xae } };
    NPDISP_DD_GETDRIVERINFODATA32 *data = (NPDISP_DD_GETDRIVERINFODATA32 *)lpData;
    const void *source;
    DWORD sourceSize;
    DWORD copySize;

    if (!data) return NPDISP_DDHAL_DRIVER_HANDLED;
    data->dwActualSize = 0;

    if (npdispdd_guid_equal(&data->guidInfo, &parseUnknownCommandGuid)) {
        npdispdd_d3dParseUnknownCommand = data->lpvData;
        data->ddRVal = 0;
        return NPDISP_DDHAL_DRIVER_HANDLED;
    }

    if (npdispdd_guid_equal(&data->guidInfo, &callbacksGuid)) {
        if (!npdispdd_d3dCallbacks) {
            data->ddRVal = NPDISP_DDERR_CURRENTLYNOTAVAIL;
            return NPDISP_DDHAL_DRIVER_HANDLED;
        }
        source = npdispdd_d3dCallbacks;
        sourceSize = sizeof(*npdispdd_d3dCallbacks);
    }
    else if (npdispdd_guid_equal(&data->guidInfo, &callbacks2Guid)) {
        source = &npdispdd_d3dCallbacks2;
        sourceSize = sizeof(npdispdd_d3dCallbacks2);
    }
    else if (npdispdd_guid_equal(&data->guidInfo, &callbacks3Guid)) {
        source = &npdispdd_d3dCallbacks3;
        sourceSize = sizeof(npdispdd_d3dCallbacks3);
    }
    else if (npdispdd_guid_equal(&data->guidInfo, &extendedCapsGuid)) {
        source = &npdispdd_d3dExtendedCaps;
        sourceSize = sizeof(npdispdd_d3dExtendedCaps);
    }
    else if (npdispdd_guid_equal(&data->guidInfo, &zPixelFormatsGuid)) {
        source = &npdispdd_zPixelFormats;
        sourceSize = sizeof(npdispdd_zPixelFormats);
    }
    else if (npdispdd_guid_equal(&data->guidInfo, &misc2Guid)) {
        source = &npdispdd_misc2Callbacks;
        sourceSize = sizeof(npdispdd_misc2Callbacks);
    }
    else {
        data->ddRVal = NPDISP_DDERR_CURRENTLYNOTAVAIL;
        return NPDISP_DDHAL_DRIVER_HANDLED;
    }

    if (!npdispdd_d3dEnabled || !data->lpvData) {
        data->ddRVal = NPDISP_DDERR_CURRENTLYNOTAVAIL;
        return NPDISP_DDHAL_DRIVER_HANDLED;
    }

    data->dwActualSize = sourceSize;
    copySize = data->dwExpectedSize;
    if (copySize > sourceSize) copySize = sourceSize;
    npdispdd_copy_bytes((void *)data->lpvData, source, copySize);
    data->ddRVal = 0;
    return NPDISP_DDHAL_DRIVER_HANDLED;
}

static void npdispdd_initD3D(void)
{
    if (!npdispdd_d3dGlobal || !npdispdd_d3dCallbacks) return;

    npdispdd_zero_bytes(npdispdd_d3dGlobal, sizeof(*npdispdd_d3dGlobal));
    npdispdd_zero_bytes(npdispdd_d3dCallbacks, sizeof(*npdispdd_d3dCallbacks));

    npdispdd_d3dGlobal->dwSize = sizeof(*npdispdd_d3dGlobal);
    npdispdd_d3dGlobal->hwCaps.dwSize = sizeof(npdispdd_d3dGlobal->hwCaps);
    npdispdd_d3dGlobal->hwCaps.dwFlags = NPDISP_D3DDD_COLORMODEL | NPDISP_D3DDD_DEVCAPS |
        NPDISP_D3DDD_TRANSFORMCAPS | NPDISP_D3DDD_LIGHTINGCAPS | NPDISP_D3DDD_BCLIPPING |
        NPDISP_D3DDD_LINECAPS | NPDISP_D3DDD_TRICAPS | NPDISP_D3DDD_DEVICERENDERBITDEPTH | NPDISP_D3DDD_DEVICEZBUFFERBITDEPTH |
        NPDISP_D3DDD_MAXVERTEXCOUNT;
    npdispdd_d3dGlobal->hwCaps.dcmColorModel = NPDISP_D3DCOLOR_RGB;
    npdispdd_d3dGlobal->hwCaps.dwDevCaps = NPDISP_D3DDEVCAPS_FLOATTLVERTEX |
        NPDISP_D3DDEVCAPS_EXECUTESYSTEMMEMORY | NPDISP_D3DDEVCAPS_TLVERTEXSYSTEMMEMORY |
        NPDISP_D3DDEVCAPS_DRAWPRIMTLVERTEX | NPDISP_D3DDEVCAPS_DRAWPRIMITIVES2 |
        NPDISP_D3DDEVCAPS_DRAWPRIMITIVES2EX | NPDISP_D3DDEVCAPS_HWRASTERIZATION;
    npdispdd_d3dGlobal->hwCaps.dtcTransformCaps.dwSize = sizeof(npdispdd_d3dGlobal->hwCaps.dtcTransformCaps);
    npdispdd_d3dGlobal->hwCaps.bClipping = 0;
    npdispdd_d3dGlobal->hwCaps.dlcLightingCaps.dwSize = sizeof(npdispdd_d3dGlobal->hwCaps.dlcLightingCaps);
    npdispdd_d3dGlobal->hwCaps.dpcLineCaps.dwSize = sizeof(npdispdd_d3dGlobal->hwCaps.dpcLineCaps);
    npdispdd_d3dGlobal->hwCaps.dpcLineCaps.dwRasterCaps = NPDISP_D3DPRASTERCAPS_ZTEST;
    npdispdd_d3dGlobal->hwCaps.dpcLineCaps.dwZCmpCaps = NPDISP_D3DPCMPCAPS_ALL;
    npdispdd_d3dGlobal->hwCaps.dpcLineCaps.dwShadeCaps = NPDISP_D3DPSHADECAPS_COLORFLATRGB | NPDISP_D3DPSHADECAPS_COLORGOURAUDRGB;
    npdispdd_d3dGlobal->hwCaps.dpcTriCaps.dwSize = sizeof(npdispdd_d3dGlobal->hwCaps.dpcTriCaps);
    npdispdd_d3dGlobal->hwCaps.dpcTriCaps.dwMiscCaps = NPDISP_D3DPMISCCAPS_CULLNONE | NPDISP_D3DPMISCCAPS_CULLCW | NPDISP_D3DPMISCCAPS_CULLCCW;
    npdispdd_d3dGlobal->hwCaps.dpcTriCaps.dwRasterCaps = NPDISP_D3DPRASTERCAPS_ZTEST;
    npdispdd_d3dGlobal->hwCaps.dpcTriCaps.dwZCmpCaps = NPDISP_D3DPCMPCAPS_ALL;
    npdispdd_d3dGlobal->hwCaps.dpcTriCaps.dwShadeCaps = NPDISP_D3DPSHADECAPS_COLORFLATRGB | NPDISP_D3DPSHADECAPS_COLORGOURAUDRGB;
    npdispdd_d3dGlobal->hwCaps.dwDeviceRenderBitDepth = NPDISP_DDBD_16 | NPDISP_DDBD_24 | NPDISP_DDBD_32;
    npdispdd_d3dGlobal->hwCaps.dwDeviceZBufferBitDepth = NPDISP_DDBD_16;
    npdispdd_d3dGlobal->hwCaps.dwMaxBufferSize = 0;
    npdispdd_d3dGlobal->hwCaps.dwMaxVertexCount = 65536UL;
    npdispdd_d3dGlobal->dwNumVertices = 0;
    npdispdd_d3dGlobal->dwNumClipVertices = 20;
    npdispdd_d3dGlobal->dwNumTextureFormats = 0;
    npdispdd_d3dGlobal->lpTextureFormats = 0;

    npdispdd_d3dCallbacks->dwSize = sizeof(*npdispdd_d3dCallbacks);
    npdispdd_d3dCallbacks->ContextCreate = (DWORD)npdispdd_D3DContextCreate;
    npdispdd_d3dCallbacks->ContextDestroy = (DWORD)npdispdd_D3DContextDestroy;
    npdispdd_d3dCallbacks->ContextDestroyAll = (DWORD)npdispdd_D3DContextDestroyAll;
    npdispdd_d3dCallbacks->SceneCapture = (DWORD)npdispdd_D3DSceneCapture;
    npdispdd_d3dCallbacks->RenderState = (DWORD)npdispdd_D3DRenderState;
    npdispdd_d3dCallbacks->RenderPrimitive = (DWORD)npdispdd_D3DRenderPrimitive;
    npdispdd_d3dCallbacks->GetState = (DWORD)npdispdd_D3DGetState;

    npdispdd_d3dCallbacks2.dwSize = sizeof(npdispdd_d3dCallbacks2);
    npdispdd_d3dCallbacks2.dwFlags = NPDISP_D3DHAL2_CB32_SETRENDERTARGET | NPDISP_D3DHAL2_CB32_CLEAR |
        NPDISP_D3DHAL2_CB32_DRAWONEPRIMITIVE | NPDISP_D3DHAL2_CB32_DRAWONEINDEXEDPRIMITIVE | NPDISP_D3DHAL2_CB32_DRAWPRIMITIVES;
    npdispdd_d3dCallbacks2.SetRenderTarget = (DWORD)npdispdd_D3DSetRenderTarget;
    npdispdd_d3dCallbacks2.Clear = (DWORD)npdispdd_D3DClear;
    npdispdd_d3dCallbacks2.DrawOnePrimitive = (DWORD)npdispdd_D3DDrawOnePrimitive;
    npdispdd_d3dCallbacks2.DrawOneIndexedPrimitive = (DWORD)npdispdd_D3DDrawOneIndexedPrimitive;
    npdispdd_d3dCallbacks2.DrawPrimitives = (DWORD)npdispdd_D3DDrawPrimitives;

    npdispdd_d3dCallbacks3.dwSize = sizeof(npdispdd_d3dCallbacks3);
    npdispdd_d3dCallbacks3.dwFlags = NPDISP_D3DHAL3_CB32_VALIDATETEXTURESTAGESTATE | NPDISP_D3DHAL3_CB32_DRAWPRIMITIVES2;
    npdispdd_d3dCallbacks3.Clear2 = 0;
    npdispdd_d3dCallbacks3.lpvReserved = 0;
    npdispdd_d3dCallbacks3.ValidateTextureStageState = (DWORD)npdispdd_D3DValidateTextureStageState;
    npdispdd_d3dCallbacks3.DrawPrimitives2 = (DWORD)npdispdd_D3DDrawPrimitives2;

    npdispdd_d3dParseUnknownCommand = 0;

    npdispdd_zero_bytes(&npdispdd_zPixelFormats, sizeof(npdispdd_zPixelFormats));
    npdispdd_zPixelFormats.dwCount = 1;
    npdispdd_zPixelFormats.formats[0].dwSize = sizeof(npdispdd_zPixelFormats.formats[0]);
    npdispdd_zPixelFormats.formats[0].dwFlags = 0x00000400UL;
    npdispdd_zPixelFormats.formats[0].dwZBufferBitDepth = 16UL;
    npdispdd_zPixelFormats.formats[0].dwZBitMask = 0x0000ffffUL;

    npdispdd_zero_bytes(&npdispdd_d3dExtendedCaps, sizeof(npdispdd_d3dExtendedCaps));
    npdispdd_d3dExtendedCaps.dwSize = sizeof(npdispdd_d3dExtendedCaps);
    npdispdd_d3dExtendedCaps.dwMaxAnisotropy = 1;

    npdispdd_zero_bytes(&npdispdd_misc2Callbacks, sizeof(npdispdd_misc2Callbacks));
    npdispdd_misc2Callbacks.dwSize = sizeof(npdispdd_misc2Callbacks);
    npdispdd_misc2Callbacks.dwFlags = NPDISP_DDHAL_MISC2CB32_CREATESURFACEEX | NPDISP_DDHAL_MISC2CB32_GETDRIVERSTATE | NPDISP_DDHAL_MISC2CB32_DESTROYDDLOCAL;
    npdispdd_misc2Callbacks.CreateSurfaceEx = (DWORD)npdispdd_D3DCreateSurfaceEx;
    npdispdd_misc2Callbacks.GetDriverState = (DWORD)npdispdd_D3DGetDriverState;
    npdispdd_misc2Callbacks.DestroyDDLocal = (DWORD)npdispdd_D3DDestroyDDLocal;
}

#define NPDISP_DDBRIDGE_INSTALL(table, request, bit, offset, fn) \
    do { if ((request) & (bit)) *(DWORD *)((table) + (offset)) = (DWORD)(fn); } while (0)

/*
 * protocol v15ではdwContextはNPDISP_DDBRIDGEINFO32のフラットアドレス。
 * callback tableとDDHALINFOはdescriptor内の32bit addressから参照する。
 */
DWORD WINAPI DriverInit(DWORD dwContext)
{
    NPDISP_DDBRIDGEINFO32 *bridge;
    unsigned char *sharedInfo;
    unsigned char *ddCallbacks;
    unsigned char *surfaceCallbacks;
    unsigned char *paletteCallbacks;
    DWORD ddRequest;
    DWORD surfaceRequest;
    DWORD paletteRequest;
    DWORD ddInstalled;
    DWORD surfaceInstalled;
    DWORD paletteInstalled;
    DWORD negotiatedFeatures;
    DWORD requestedProfile;

    if (!dwContext || !npdispdd_hInstance || npdispdd_hInstance == 0xFFFFFFFFUL) {
        return 0;
    }

    bridge = (NPDISP_DDBRIDGEINFO32 *)dwContext;
    if (bridge->dwSize < sizeof(NPDISP_DDBRIDGEINFO32) ||
        bridge->dwMagic != NPDISP_DDBRIDGE_V2_MAGIC ||
        (bridge->dwAbiVersion & NPDISP_DDBRIDGE_ABI_MAJOR_MASK) != (NPDISP_DDBRIDGE_ABI_V2 & NPDISP_DDBRIDGE_ABI_MAJOR_MASK) ||
        bridge->dwStatus != NPDISP_DDBRIDGE_STATUS_HOST_READY) {
        return 0;
    }

    if (!bridge->lpDDHalInfo || !bridge->lpDDCallbacks ||
        !bridge->lpDDSurfaceCallbacks || !bridge->lpDDPaletteCallbacks) {
        bridge->dwStatus = NPDISP_DDBRIDGE_STATUS_FAILED;
        return 0;
    }

    requestedProfile = bridge->dwD3DProfileId;
    npdispdd_d3dEnabled = 0;
    npdispdd_d3dGlobal = 0;
    npdispdd_d3dCallbacks = 0;

    sharedInfo = (unsigned char *)bridge->lpDDHalInfo;
    ddCallbacks = (unsigned char *)bridge->lpDDCallbacks;
    surfaceCallbacks = (unsigned char *)bridge->lpDDSurfaceCallbacks;
    paletteCallbacks = (unsigned char *)bridge->lpDDPaletteCallbacks;

    if (*(DWORD *)(ddCallbacks + 0) != NPDISP_DDCALLBACKS_SIZE ||
        *(DWORD *)(surfaceCallbacks + 0) != NPDISP_DDSURFACECALLBACKS_SIZE ||
        *(DWORD *)(paletteCallbacks + 0) != NPDISP_DDPALETTECALLBACKS_SIZE) {
        bridge->dwStatus = NPDISP_DDBRIDGE_STATUS_FAILED;
        return 0;
    }

    ddRequest = bridge->dwDDRequestMask;
    surfaceRequest = bridge->dwSurfaceRequestMask;
    paletteRequest = bridge->dwPaletteRequestMask;
    ddInstalled = ddRequest & NPDISP_DDHAL_CB32_SUPPORTED;
    surfaceInstalled = surfaceRequest & NPDISP_DDHAL_SURFCB32_SUPPORTED;
    paletteInstalled = paletteRequest & NPDISP_DDHAL_PALCB32_SUPPORTED;

    /* DestroyDriverはlpSetInfoの寿命をNPDISP.DRV側で管理するため16bit側に残す。 */
    NPDISP_DDBRIDGE_INSTALL(ddCallbacks, ddInstalled, NPDISP_DDHAL_CB32_CREATESURFACE,     NPDISP_DDCALLBACKS_CREATESURFACE,    npdispdd_CreateSurface);
    NPDISP_DDBRIDGE_INSTALL(ddCallbacks, ddInstalled, NPDISP_DDHAL_CB32_SETCOLORKEY,       NPDISP_DDCALLBACKS_SETCOLORKEY,      npdispdd_DriverSetColorKey);
    NPDISP_DDBRIDGE_INSTALL(ddCallbacks, ddInstalled, NPDISP_DDHAL_CB32_SETMODE,           NPDISP_DDCALLBACKS_SETMODE,          npdispdd_SetMode);
    NPDISP_DDBRIDGE_INSTALL(ddCallbacks, ddInstalled, NPDISP_DDHAL_CB32_WAITVB,            NPDISP_DDCALLBACKS_WAITVB,           npdispdd_WaitForVerticalBlank);
    NPDISP_DDBRIDGE_INSTALL(ddCallbacks, ddInstalled, NPDISP_DDHAL_CB32_CANCREATESURFACE,  NPDISP_DDCALLBACKS_CANCREATESURFACE, npdispdd_CanCreateSurface);
    NPDISP_DDBRIDGE_INSTALL(ddCallbacks, ddInstalled, NPDISP_DDHAL_CB32_CREATEPALETTE,     NPDISP_DDCALLBACKS_CREATEPALETTE,    npdispdd_CreatePalette);
    NPDISP_DDBRIDGE_INSTALL(ddCallbacks, ddInstalled, NPDISP_DDHAL_CB32_GETSCANLINE,       NPDISP_DDCALLBACKS_GETSCANLINE,       npdispdd_GetScanLine);
    NPDISP_DDBRIDGE_INSTALL(ddCallbacks, ddInstalled, NPDISP_DDHAL_CB32_SETEXCLUSIVEMODE,  NPDISP_DDCALLBACKS_SETEXCLUSIVEMODE, npdispdd_SetExclusiveMode);
    NPDISP_DDBRIDGE_INSTALL(ddCallbacks, ddInstalled, NPDISP_DDHAL_CB32_FLIPTOGDI,         NPDISP_DDCALLBACKS_FLIPTOGDI,         npdispdd_FlipToGDISurface);

    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_DESTROY,       NPDISP_DDSURFACECALLBACKS_DESTROY,       npdispdd_DestroySurface);
    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_FLIP,          NPDISP_DDSURFACECALLBACKS_FLIP,          npdispdd_Flip);
    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_SETCLIPLIST,   NPDISP_DDSURFACECALLBACKS_SETCLIPLIST,   npdispdd_SetClipList);
    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_LOCK,          NPDISP_DDSURFACECALLBACKS_LOCK,          npdispdd_Lock);
    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_UNLOCK,        NPDISP_DDSURFACECALLBACKS_UNLOCK,        npdispdd_Unlock);
    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_BLT,           NPDISP_DDSURFACECALLBACKS_BLT,           npdispdd_Blt);
    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_SETCOLORKEY,   NPDISP_DDSURFACECALLBACKS_SETCOLORKEY,   npdispdd_SetColorKey);
    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_ADDATTACHED,   NPDISP_DDSURFACECALLBACKS_ADDATTACHED,   npdispdd_AddAttachedSurface);
    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_GETBLTSTATUS,  NPDISP_DDSURFACECALLBACKS_GETBLTSTATUS,  npdispdd_GetBltStatus);
    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_GETFLIPSTATUS, NPDISP_DDSURFACECALLBACKS_GETFLIPSTATUS, npdispdd_GetFlipStatus);
    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_UPDATEOVERLAY, NPDISP_DDSURFACECALLBACKS_UPDATEOVERLAY, npdispdd_UpdateOverlay);
    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_SETOVERLAYPOS, NPDISP_DDSURFACECALLBACKS_SETOVERLAYPOS, npdispdd_SetOverlayPosition);
    NPDISP_DDBRIDGE_INSTALL(surfaceCallbacks, surfaceInstalled, NPDISP_DDHAL_SURFCB32_SETPALETTE,     NPDISP_DDSURFACECALLBACKS_SETPALETTE,     npdispdd_SetPalette);

    NPDISP_DDBRIDGE_INSTALL(paletteCallbacks, paletteInstalled, NPDISP_DDHAL_PALCB32_DESTROY,    NPDISP_DDPALETTECALLBACKS_DESTROY,    npdispdd_DestroyPalette);
    NPDISP_DDBRIDGE_INSTALL(paletteCallbacks, paletteInstalled, NPDISP_DDHAL_PALCB32_SETENTRIES, NPDISP_DDPALETTECALLBACKS_SETENTRIES, npdispdd_SetEntries);

    *(DWORD *)(ddCallbacks + NPDISP_DDCALLBACKS_FLAGS) = ddInstalled;
    *(DWORD *)(surfaceCallbacks + NPDISP_DDSURFACECALLBACKS_FLAGS) = surfaceInstalled;
    *(DWORD *)(paletteCallbacks + NPDISP_DDPALETTECALLBACKS_FLAGS) = paletteInstalled;

    bridge->dwDriverFeaturesSupported = NPDISP_DDBRIDGE_FEATURE_SUPPORTED;
    negotiatedFeatures = bridge->dwHostFeaturesOffered & NPDISP_DDBRIDGE_FEATURE_SUPPORTED;
    if ((negotiatedFeatures & NPDISP_DDBRIDGE_FEATURE_D3D_HAL) &&
        (!(negotiatedFeatures & NPDISP_DDBRIDGE_FEATURE_GETDRIVERINFO) ||
         !(negotiatedFeatures & NPDISP_DDBRIDGE_FEATURE_D3D_SHARED_DATA) ||
         requestedProfile != NPDISP_D3D_PROFILE_1 || !bridge->lpD3DGlobalDriverData || !bridge->lpD3DHALCallbacks)) {
        negotiatedFeatures &= ~NPDISP_DDBRIDGE_FEATURE_D3D_HAL;
    }
    bridge->dwNegotiatedFeatures = negotiatedFeatures;
    bridge->dwD3DProfileId = requestedProfile;

    if (negotiatedFeatures & NPDISP_DDBRIDGE_FEATURE_GETDRIVERINFO) {
        *(DWORD *)(sharedInfo + NPDISP_DDHALINFO_GETDRIVERINFO) = (DWORD)npdispdd_GetDriverInfo;
    }
    else {
        *(DWORD *)(sharedInfo + NPDISP_DDHALINFO_GETDRIVERINFO) = 0;
    }

    *(DWORD *)(sharedInfo + NPDISP_DDHALINFO_D3DGLOBAL) = 0;
    *(DWORD *)(sharedInfo + NPDISP_DDHALINFO_D3DCALLBACKS) = 0;
    *(DWORD *)(sharedInfo + NPDISP_DDHALINFO_DDEXEBUFCALLBACKS) = 0;
    if (negotiatedFeatures & NPDISP_DDBRIDGE_FEATURE_D3D_HAL) {
        npdispdd_d3dGlobal = (NPDISP_D3DHAL_GLOBALDRIVERDATA32 *)bridge->lpD3DGlobalDriverData;
        npdispdd_d3dCallbacks = (NPDISP_D3DHAL_CALLBACKS32 *)bridge->lpD3DHALCallbacks;
        npdispdd_initD3D();
        npdispdd_d3dEnabled = 1;
        *(DWORD *)(sharedInfo + NPDISP_DDHALINFO_D3DGLOBAL) = bridge->lpD3DGlobalDriverData;
        *(DWORD *)(sharedInfo + NPDISP_DDHALINFO_D3DCALLBACKS) = bridge->lpD3DHALCallbacks;
    }
    *(DWORD *)(sharedInfo + NPDISP_DDHALINFO_HINSTANCE) = npdispdd_hInstance;

    bridge->dwStatus = NPDISP_DDBRIDGE_STATUS_DRIVER_READY;
    return 1;
}

BOOL WINAPI DllMain(void *hInstance, DWORD reason, void *reserved)
{
    (void)reserved;
    if (reason == DLL_PROCESS_ATTACH) {
        npdispdd_hInstance = (DWORD)hInstance;
    }
    return 1;
}
