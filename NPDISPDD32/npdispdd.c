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
#define NPDISP_DDHALINFO_D3DCALLBACKS       452
#define NPDISP_DDHALINFO_DDEXEBUFCALLBACKS  456

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

#define NPDISP_DDBRIDGE_V2_MAGIC                 0x3242444eUL
#define NPDISP_DDBRIDGE_ABI_V2                   0x00020000UL
#define NPDISP_DDBRIDGE_ABI_MAJOR_MASK           0xffff0000UL
#define NPDISP_DDBRIDGE_STATUS_HOST_READY        0x00000001UL
#define NPDISP_DDBRIDGE_STATUS_DRIVER_READY      0x00000002UL
#define NPDISP_DDBRIDGE_STATUS_FAILED            0xffffffffUL
#define NPDISP_DDBRIDGE_FEATURE_GETDRIVERINFO    0x00000001UL
#define NPDISP_DDBRIDGE_FEATURE_D3D_HAL          0x00000002UL
#define NPDISP_DDBRIDGE_FEATURE_D3D_SHARED_DATA  0x00000004UL
#define NPDISP_DDBRIDGE_FEATURE_D3D_HOST_METADATA 0x00000008UL
#define NPDISP_DDBRIDGE_FEATURE_SUPPORTED        (NPDISP_DDBRIDGE_FEATURE_GETDRIVERINFO | NPDISP_DDBRIDGE_FEATURE_D3D_HAL | NPDISP_DDBRIDGE_FEATURE_D3D_SHARED_DATA | NPDISP_DDBRIDGE_FEATURE_D3D_HOST_METADATA)
#define NPDISP_D3D_PROFILE_1                      0x00010000UL
#define NPDISP_D3D_THUNK_TABLE_VERSION            0x00010000UL

#define NPDISP_EXEC_MAGIC_LOW                    0x0000504eUL
#define NPDISP_EXEC_PORT                         0x07e9
#define NPDISP_EXEC_COMMAND                      0x46
#define NPDISP_FUNCORDER_DD32_DISPATCH           0xfe30UL

#define NPDISP_DDHAL_DRIVER_NOTHANDLED            0x00000000UL
#define NPDISP_DDHAL_DRIVER_HANDLED               0x00000001UL
#define NPDISP_DDWAITVB_BLOCKBEGIN                0x00000001UL
#define NPDISP_DDWAITVB_BLOCKEND                  0x00000004UL
#define NPDISP_DDWAITVB_I_TESTVB                  0x80000006UL

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

#define NPDISP_DDBRIDGE_CB_PAL_DESTROY            0x0200UL
#define NPDISP_DDBRIDGE_CB_PAL_SETENTRIES         0x0201UL

#define NPDISP_DDBRIDGE_CB_D3D_CONTEXTCREATE      0x0300UL
#define NPDISP_DDBRIDGE_CB_D3D_CONTEXTDESTROY     0x0301UL
#define NPDISP_DDBRIDGE_CB_D3D_CONTEXTDESTROYALL  0x0302UL
#define NPDISP_DDBRIDGE_CB_D3D_RENDERSTATE        0x0303UL
#define NPDISP_DDBRIDGE_CB_D3D_RENDERPRIMITIVE    0x0304UL
#define NPDISP_DDBRIDGE_CB_D3D_GETSTATE           0x0305UL
#define NPDISP_DDBRIDGE_CB_D3D_SCENECAPTURE       0x0306UL
#define NPDISP_DDBRIDGE_CB_D3D_TEXTURECREATE      0x0307UL
#define NPDISP_DDBRIDGE_CB_D3D_TEXTUREDESTROY     0x0308UL
#define NPDISP_DDBRIDGE_CB_D3D_TEXTURESWAP        0x0309UL
#define NPDISP_DDBRIDGE_CB_D3D_TEXTUREGETSURF     0x030aUL
#define NPDISP_DDBRIDGE_CB_D3D_CREATESURFACEEX    0x0310UL
#define NPDISP_DDBRIDGE_CB_D3D_DESTROYDDLOCAL     0x0311UL
#define NPDISP_DDBRIDGE_CB_D3D_GETDRIVERSTATE     0x0312UL
#define NPDISP_DDBRIDGE_CB_D3D_ALPHABLT           0x0313UL
#define NPDISP_DDBRIDGE_CB_D3D_SETRENDERTARGET    0x0320UL
#define NPDISP_DDBRIDGE_CB_D3D_CLEAR              0x0321UL
#define NPDISP_DDBRIDGE_CB_D3D_DRAWONEPRIMITIVE   0x0322UL
#define NPDISP_DDBRIDGE_CB_D3D_DRAWONEINDEXEDPRIMITIVE 0x0323UL
#define NPDISP_DDBRIDGE_CB_D3D_DRAWPRIMITIVES     0x0324UL
#define NPDISP_DDBRIDGE_CB_D3D_DRAWPRIMITIVES2    0x0330UL
#define NPDISP_DDBRIDGE_CB_D3D_VALIDATESTAGE      0x0331UL
#define NPDISP_DDBRIDGE_CB_D3D_CLEAR2             0x0332UL

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
    DWORD lpD3DThunkTable;
    DWORD dwD3DThunkTableSize;
    DWORD dwD3DThunkTableVersion;
} NPDISP_DDBRIDGEINFO32;

typedef char NPDISP_DDBRIDGEINFO32_SIZE_CHECK[(sizeof(NPDISP_DDBRIDGEINFO32) == 80) ? 1 : -1];
typedef char NPDISP_DDBRIDGEINFO32_HAL_OFFSET_CHECK[(offsetof(NPDISP_DDBRIDGEINFO32, lpDDHalInfo) == 32) ? 1 : -1];
typedef char NPDISP_DDBRIDGEINFO32_MASK_OFFSET_CHECK[(offsetof(NPDISP_DDBRIDGEINFO32, dwDDRequestMask) == 48) ? 1 : -1];
typedef char NPDISP_DDBRIDGEINFO32_D3D_OFFSET_CHECK[(offsetof(NPDISP_DDBRIDGEINFO32, lpD3DGlobalDriverData) == 60) ? 1 : -1];

typedef struct {
    DWORD dwSize;
    DWORD dwVersion;
    DWORD ContextCreate;
    DWORD ContextDestroy;
    DWORD ContextDestroyAll;
    DWORD SceneCapture;
    DWORD RenderState;
    DWORD RenderPrimitive;
    DWORD GetState;
    DWORD TextureCreate;
    DWORD TextureDestroy;
    DWORD TextureSwap;
    DWORD TextureGetSurf;
    DWORD SetRenderTarget;
    DWORD Clear;
    DWORD DrawOnePrimitive;
    DWORD DrawOneIndexedPrimitive;
    DWORD DrawPrimitives;
    DWORD ValidateTextureStageState;
    DWORD DrawPrimitives2;
    DWORD Clear2;
    DWORD CreateSurfaceEx;
    DWORD GetDriverState;
    DWORD DestroyDDLocal;
    DWORD AlphaBlt;
} NPDISP_D3D_THUNK_TABLE32;
typedef char NPDISP_D3D_THUNK_TABLE32_SIZE_CHECK[(sizeof(NPDISP_D3D_THUNK_TABLE32) == 100) ? 1 : -1];

#pragma data_seg(".npddshr")
static DWORD npdispdd_hInstance = 0xFFFFFFFFUL;
static NPDISP_D3D_THUNK_TABLE32 npdispdd_d3dThunks = { sizeof(NPDISP_D3D_THUNK_TABLE32), NPDISP_D3D_THUNK_TABLE_VERSION };
#pragma data_seg()

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

static DWORD npdispdd_test_vblank(NPDISP_DDHAL_WAITVBDATA32 *data, DWORD *inVBlank)
{
    DWORD result;
    data->dwFlags = NPDISP_DDWAITVB_I_TESTVB;
    result = npdispdd_host_call(NPDISP_DDBRIDGE_CB_DD_WAITVB, data);
    if (result == NPDISP_DDHAL_DRIVER_HANDLED) *inVBlank = data->bIsInVB ? 1UL : 0UL;
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

    if (originalFlags == NPDISP_DDWAITVB_I_TESTVB) return npdispdd_host_call(NPDISP_DDBRIDGE_CB_DD_WAITVB, data);
    if (originalFlags != NPDISP_DDWAITVB_BLOCKBEGIN && originalFlags != NPDISP_DDWAITVB_BLOCKEND) {
        return npdispdd_host_call(NPDISP_DDBRIDGE_CB_DD_WAITVB, data);
    }

    result = npdispdd_test_vblank(data, &inVBlank);
    if (result != NPDISP_DDHAL_DRIVER_HANDLED) {
        data->dwFlags = originalFlags;
        return result;
    }

    if (originalFlags == NPDISP_DDWAITVB_BLOCKBEGIN) {
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
NPDISP_DDBRIDGE_WRAPPER(npdispdd_GetDriverInfo,       NPDISP_DDBRIDGE_CB_DD_GETDRIVERINFO)

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

NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DContextCreate,     NPDISP_DDBRIDGE_CB_D3D_CONTEXTCREATE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DContextDestroy,    NPDISP_DDBRIDGE_CB_D3D_CONTEXTDESTROY)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DContextDestroyAll, NPDISP_DDBRIDGE_CB_D3D_CONTEXTDESTROYALL)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DSceneCapture,      NPDISP_DDBRIDGE_CB_D3D_SCENECAPTURE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DRenderState,       NPDISP_DDBRIDGE_CB_D3D_RENDERSTATE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DRenderPrimitive,   NPDISP_DDBRIDGE_CB_D3D_RENDERPRIMITIVE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DGetState,          NPDISP_DDBRIDGE_CB_D3D_GETSTATE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DTextureCreate,     NPDISP_DDBRIDGE_CB_D3D_TEXTURECREATE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DTextureDestroy,    NPDISP_DDBRIDGE_CB_D3D_TEXTUREDESTROY)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DTextureSwap,       NPDISP_DDBRIDGE_CB_D3D_TEXTURESWAP)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DTextureGetSurf,    NPDISP_DDBRIDGE_CB_D3D_TEXTUREGETSURF)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DCreateSurfaceEx,   NPDISP_DDBRIDGE_CB_D3D_CREATESURFACEEX)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DDestroyDDLocal,    NPDISP_DDBRIDGE_CB_D3D_DESTROYDDLOCAL)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DGetDriverState,    NPDISP_DDBRIDGE_CB_D3D_GETDRIVERSTATE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DAlphaBlt,          NPDISP_DDBRIDGE_CB_D3D_ALPHABLT)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DSetRenderTarget,   NPDISP_DDBRIDGE_CB_D3D_SETRENDERTARGET)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DClear,             NPDISP_DDBRIDGE_CB_D3D_CLEAR)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DDrawOnePrimitive,  NPDISP_DDBRIDGE_CB_D3D_DRAWONEPRIMITIVE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DDrawOneIndexedPrimitive, NPDISP_DDBRIDGE_CB_D3D_DRAWONEINDEXEDPRIMITIVE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DDrawPrimitives,    NPDISP_DDBRIDGE_CB_D3D_DRAWPRIMITIVES)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DValidateTextureStageState, NPDISP_DDBRIDGE_CB_D3D_VALIDATESTAGE)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DDrawPrimitives2,   NPDISP_DDBRIDGE_CB_D3D_DRAWPRIMITIVES2)
NPDISP_DDBRIDGE_WRAPPER(npdispdd_D3DClear2,            NPDISP_DDBRIDGE_CB_D3D_CLEAR2)

static void npdispdd_zero_bytes(void *dst, DWORD size)
{
    unsigned char *d = (unsigned char *)dst;
    while (size--) *d++ = 0;
}

static void npdispdd_initD3DThunks(void)
{
    npdispdd_zero_bytes(&npdispdd_d3dThunks, sizeof(npdispdd_d3dThunks));
    npdispdd_d3dThunks.dwSize = sizeof(npdispdd_d3dThunks);
    npdispdd_d3dThunks.dwVersion = NPDISP_D3D_THUNK_TABLE_VERSION;
    npdispdd_d3dThunks.ContextCreate = (DWORD)npdispdd_D3DContextCreate;
    npdispdd_d3dThunks.ContextDestroy = (DWORD)npdispdd_D3DContextDestroy;
    npdispdd_d3dThunks.ContextDestroyAll = (DWORD)npdispdd_D3DContextDestroyAll;
    npdispdd_d3dThunks.SceneCapture = (DWORD)npdispdd_D3DSceneCapture;
    npdispdd_d3dThunks.RenderState = (DWORD)npdispdd_D3DRenderState;
    npdispdd_d3dThunks.RenderPrimitive = (DWORD)npdispdd_D3DRenderPrimitive;
    npdispdd_d3dThunks.GetState = (DWORD)npdispdd_D3DGetState;
    npdispdd_d3dThunks.TextureCreate = (DWORD)npdispdd_D3DTextureCreate;
    npdispdd_d3dThunks.TextureDestroy = (DWORD)npdispdd_D3DTextureDestroy;
    npdispdd_d3dThunks.TextureSwap = (DWORD)npdispdd_D3DTextureSwap;
    npdispdd_d3dThunks.TextureGetSurf = (DWORD)npdispdd_D3DTextureGetSurf;
    npdispdd_d3dThunks.SetRenderTarget = (DWORD)npdispdd_D3DSetRenderTarget;
    npdispdd_d3dThunks.Clear = (DWORD)npdispdd_D3DClear;
    npdispdd_d3dThunks.DrawOnePrimitive = (DWORD)npdispdd_D3DDrawOnePrimitive;
    npdispdd_d3dThunks.DrawOneIndexedPrimitive = (DWORD)npdispdd_D3DDrawOneIndexedPrimitive;
    npdispdd_d3dThunks.DrawPrimitives = (DWORD)npdispdd_D3DDrawPrimitives;
    npdispdd_d3dThunks.ValidateTextureStageState = (DWORD)npdispdd_D3DValidateTextureStageState;
    npdispdd_d3dThunks.DrawPrimitives2 = (DWORD)npdispdd_D3DDrawPrimitives2;
    npdispdd_d3dThunks.Clear2 = (DWORD)npdispdd_D3DClear2;
    npdispdd_d3dThunks.CreateSurfaceEx = (DWORD)npdispdd_D3DCreateSurfaceEx;
    npdispdd_d3dThunks.GetDriverState = (DWORD)npdispdd_D3DGetDriverState;
    npdispdd_d3dThunks.DestroyDDLocal = (DWORD)npdispdd_D3DDestroyDDLocal;
    npdispdd_d3dThunks.AlphaBlt = (DWORD)npdispdd_D3DAlphaBlt;
}

#define NPDISP_DDBRIDGE_INSTALL(table, request, bit, offset, fn) \
    do { if ((request) & (bit)) *(DWORD *)((table) + (offset)) = (DWORD)(fn); } while (0)

DWORD WINAPI DriverInit(DWORD dwContext)
{
    NPDISP_DDBRIDGEINFO32 *bridge;
    unsigned char *sharedInfo;
    unsigned char *ddCallbacks;
    unsigned char *surfaceCallbacks;
    unsigned char *paletteCallbacks;
    DWORD ddInstalled;
    DWORD surfaceInstalled;
    DWORD paletteInstalled;
    DWORD negotiatedFeatures;

    if (!dwContext || !npdispdd_hInstance || npdispdd_hInstance == 0xFFFFFFFFUL) return 0;

    bridge = (NPDISP_DDBRIDGEINFO32 *)dwContext;
    if (bridge->dwSize < sizeof(NPDISP_DDBRIDGEINFO32) ||
        bridge->dwMagic != NPDISP_DDBRIDGE_V2_MAGIC ||
        (bridge->dwAbiVersion & NPDISP_DDBRIDGE_ABI_MAJOR_MASK) != (NPDISP_DDBRIDGE_ABI_V2 & NPDISP_DDBRIDGE_ABI_MAJOR_MASK) ||
        bridge->dwStatus != NPDISP_DDBRIDGE_STATUS_HOST_READY) return 0;

    if (!bridge->lpDDHalInfo || !bridge->lpDDCallbacks || !bridge->lpDDSurfaceCallbacks || !bridge->lpDDPaletteCallbacks) {
        bridge->dwStatus = NPDISP_DDBRIDGE_STATUS_FAILED;
        return 0;
    }

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

    ddInstalled = bridge->dwDDRequestMask & NPDISP_DDHAL_CB32_SUPPORTED;
    surfaceInstalled = bridge->dwSurfaceRequestMask & NPDISP_DDHAL_SURFCB32_SUPPORTED;
    paletteInstalled = bridge->dwPaletteRequestMask & NPDISP_DDHAL_PALCB32_SUPPORTED;

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
         !(negotiatedFeatures & NPDISP_DDBRIDGE_FEATURE_D3D_HOST_METADATA) ||
         bridge->dwD3DProfileId != NPDISP_D3D_PROFILE_1 ||
         !bridge->lpD3DGlobalDriverData || !bridge->lpD3DHALCallbacks)) {
        negotiatedFeatures &= ~(NPDISP_DDBRIDGE_FEATURE_D3D_HAL | NPDISP_DDBRIDGE_FEATURE_D3D_SHARED_DATA | NPDISP_DDBRIDGE_FEATURE_D3D_HOST_METADATA);
    }

    if (!(negotiatedFeatures & NPDISP_DDBRIDGE_FEATURE_D3D_HOST_METADATA)) {
        negotiatedFeatures &= ~NPDISP_DDBRIDGE_FEATURE_GETDRIVERINFO;
    }

    bridge->dwNegotiatedFeatures = negotiatedFeatures;
    bridge->lpD3DThunkTable = 0;
    bridge->dwD3DThunkTableSize = 0;
    bridge->dwD3DThunkTableVersion = 0;

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
        npdispdd_initD3DThunks();
        bridge->lpD3DThunkTable = (DWORD)&npdispdd_d3dThunks;
        bridge->dwD3DThunkTableSize = sizeof(npdispdd_d3dThunks);
        bridge->dwD3DThunkTableVersion = NPDISP_D3D_THUNK_TABLE_VERSION;
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
    if (reason == DLL_PROCESS_ATTACH) npdispdd_hInstance = (DWORD)hInstance;
    return 1;
}
