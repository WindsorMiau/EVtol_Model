#ifndef RTW_HEADER_PropellerDynamics_cap_host_h__
#define RTW_HEADER_PropellerDynamics_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap_simtarget.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
PropellerDynamics_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void PropellerDynamics_host_InitializeDataMapInfo (
PropellerDynamics_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
