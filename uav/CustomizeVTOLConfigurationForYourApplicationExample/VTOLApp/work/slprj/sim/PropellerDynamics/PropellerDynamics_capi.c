#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "PropellerDynamics_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 21
#endif
#ifndef SS_INT64
#define SS_INT64 22
#endif
#else
#include "builtin_typeid_types.h"
#include "PropellerDynamics.h"
#include "PropellerDynamics_capi.h"
#include "PropellerDynamics_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , - 1
, ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 , - 1 , 0 } } ;
static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static TARGET_CONST
rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "" , "" , 0 , 0 , 0 , 0 , 0 , 0 ,
0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 0 , 0 } } ; static uint_T rtDimensionArray [ ] = { 0 } ;
static rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( NULL ) , ( NULL ) , 0 , 0 }
} ; static int_T rtContextSystems [ 2 ] ; static rtwCAPI_LoggingMetaInfo
loggingMetaInfo [ ] = { { 0 , 0 , "" , 0 } } ; static
rtwCAPI_ModelMapLoggingStaticInfo mmiStaticInfoLogging = { 2 ,
rtContextSystems , loggingMetaInfo , 0 , ( NULL ) , { 0 , ( NULL ) , ( NULL )
} , 0 , ( NULL ) } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 0 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL ) , 0 , ( NULL
) , 0 } , { rtBlockStates , 0 } , { rtDataTypeMap , rtDimensionMap ,
rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" ,
{ 204610270U , 1600140228U , 2350993130U , 3652656672U } , &
mmiStaticInfoLogging , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * PropellerDynamics_GetCAPIStaticMap ( void )
{ return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void PropellerDynamics_InitializeSystemRan ( ndzwvtjpgv * const
n3istur3p5 , sysRanDType * systemRan [ ] , cauih2yi0g * localDW , int_T
systemTid [ ] , void * rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER (
n3istur3p5 ) ; UNUSED_PARAMETER ( localDW ) ; systemRan [ 0 ] = ( sysRanDType
* ) rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemTid [ 1 ] = n3istur3p5
-> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 0 ] = rootTid ;
rtContextSystems [ 0 ] = 0 ; rtContextSystems [ 1 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void PropellerDynamics_InitializeDataMapInfo ( ndzwvtjpgv * const n3istur3p5
, cauih2yi0g * localDW , void * sysRanPtr , int contextTid ) {
rtwCAPI_SetVersion ( n3istur3p5 -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( n3istur3p5 -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( n3istur3p5 -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; rtwCAPI_SetPath ( n3istur3p5 -> DataMapInfo . mmi ,
( NULL ) ) ; rtwCAPI_SetFullPath ( n3istur3p5 -> DataMapInfo . mmi , ( NULL )
) ; rtwCAPI_SetInstanceLoggingInfo ( n3istur3p5 -> DataMapInfo . mmi , &
n3istur3p5 -> DataMapInfo . mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray (
n3istur3p5 -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen (
n3istur3p5 -> DataMapInfo . mmi , 0 ) ; PropellerDynamics_InitializeSystemRan
( n3istur3p5 , n3istur3p5 -> DataMapInfo . systemRan , localDW , n3istur3p5
-> DataMapInfo . systemTid , sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan
( n3istur3p5 -> DataMapInfo . mmi , n3istur3p5 -> DataMapInfo . systemRan ) ;
rtwCAPI_SetSystemTid ( n3istur3p5 -> DataMapInfo . mmi , n3istur3p5 ->
DataMapInfo . systemTid ) ; rtwCAPI_SetGlobalTIDMap ( n3istur3p5 ->
DataMapInfo . mmi , & n3istur3p5 -> Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void PropellerDynamics_host_InitializeDataMapInfo (
PropellerDynamics_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
