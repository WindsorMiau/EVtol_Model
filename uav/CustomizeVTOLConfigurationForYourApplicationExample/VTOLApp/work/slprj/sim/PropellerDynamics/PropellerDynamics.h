#ifndef RTW_HEADER_PropellerDynamics_h_
#define RTW_HEADER_PropellerDynamics_h_
#ifndef PropellerDynamics_COMMON_INCLUDES_
#define PropellerDynamics_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "PropellerDynamics_types.h"
#include "rtw_modelmap_simtarget.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
typedef struct { real_T g33x3brnwl ; real_T f4sjvlzpnp ; } hdlladljw4 ;
typedef struct { int_T cu55bydicj ; int8_T cmbvvgaq02 ; } cauih2yi0g ;
typedef struct { real_T axzx40ieep ; real_T lzvkcu23cc ; } h1jo3kaarc ;
struct ht5n2qntkht_ { real_T P_2 ; real_T P_3 [ 4 ] ; real_T P_4 ; real_T P_5
[ 5 ] ; real_T P_6 ; real_T P_7 ; real_T P_8 ; } ; struct asjk1czvet { struct
SimStruct_tag * _mdlRefSfcnS ; struct { rtwCAPI_ModelMappingInfo mmi ;
rtwCAPI_ModelMapLoggingInstanceInfo mmiLogInstanceInfo ; sysRanDType *
systemRan [ 2 ] ; int_T systemTid [ 2 ] ; } DataMapInfo ; struct { int_T
mdlref_GlobalTID [ 2 ] ; } Timing ; } ; typedef struct { hdlladljw4 rtb ;
cauih2yi0g rtdw ; ndzwvtjpgv rtm ; } bfxsfyeisx3 ; extern
struct_DAy4VMOKMUhj3u1IcOvsOG rtP_uavParam ; extern real_T rtP_minPWM ;
extern void j3unvwpf2g ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T
mdlref_TID1 , ndzwvtjpgv * const n3istur3p5 , hdlladljw4 * localB ,
cauih2yi0g * localDW , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_PropellerDynamics_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray * mr_PropellerDynamics_GetDWork
( const bfxsfyeisx3 * mdlrefDW ) ; extern void mr_PropellerDynamics_SetDWork
( bfxsfyeisx3 * mdlrefDW , const mxArray * ssDW ) ; extern void
mr_PropellerDynamics_RegisterSimStateChecksum ( SimStruct * S ) ; extern
mxArray * mr_PropellerDynamics_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * PropellerDynamics_GetCAPIStaticMap ( void )
; extern void owx3smczj2 ( cauih2yi0g * localDW ) ; extern void hgebfhb0qf (
const real_T * akzpwcud41 , h1jo3kaarc * localZCSV ) ; extern void
PropellerDynamics ( ndzwvtjpgv * const n3istur3p5 , const real_T * akzpwcud41
, const real_T de0biblu0l [ 3 ] , const real_T jgodcikh13 [ 3 ] , const
real_T e4xmvna52m [ 3 ] , const real_T p1nux5b0nf [ 3 ] , const real_T
fcurtqao22 [ 3 ] , real_T d5ttxibnex [ 3 ] , real_T bumzwrs5da [ 3 ] , real_T
* bdy3wtdo2m , hdlladljw4 * localB , cauih2yi0g * localDW ) ; extern void
PropellerDynamicsTID1 ( hdlladljw4 * localB ) ; extern void ctvtngd0gv (
ndzwvtjpgv * const n3istur3p5 ) ;
#endif
