#include "PropellerDynamics.h"
#include "rtwtypes.h"
#include "PropellerDynamics_private.h"
#include "mwmathutil.h"
#include "PropellerDynamics_types.h"
#include "PropellerDynamics_capi.h"
#include <string.h>
#include "rt_nonfinite.h"
static RegMdlInfo rtMdlInfo_PropellerDynamics [ 44 ] = { { "bfxsfyeisx3" ,
MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * ) "PropellerDynamics" } , {
"h1jo3kaarc" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"PropellerDynamics" } , { "iqz04cnfi1" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "PropellerDynamics" } , { "fdujwvx1zp" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "PropellerDynamics" }
, { "lv50wtnb5y" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"PropellerDynamics" } , { "nn4f1iv5iz" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "PropellerDynamics" } , { "nces1glmg1" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "PropellerDynamics" }
, { "diuziyhz5c" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"PropellerDynamics" } , { "h5zkh0togi" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "PropellerDynamics" } , { "hbpfldiooe" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "PropellerDynamics" }
, { "hstgrmttq1" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"PropellerDynamics" } , { "c4gwkx4s3g" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "PropellerDynamics" } , { "cauih2yi0g" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "PropellerDynamics" }
, { "hdlladljw4" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"PropellerDynamics" } , { "gnpigr4b5r" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "PropellerDynamics" } , { "ctvtngd0gv" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "PropellerDynamics" }
, { "mtcg1cjvrw" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"PropellerDynamics" } , { "hgebfhb0qf" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "PropellerDynamics" } , { "h32dqdiwp3" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "PropellerDynamics" }
, { "j3unvwpf2g" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"PropellerDynamics" } , { "owx3smczj2" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "PropellerDynamics" } , { "psdsefxn4d" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "PropellerDynamics" }
, { "PropellerDynamics" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , 0 , ( NULL )
} , { "fkyogibgue" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"PropellerDynamics" } , { "asjk1czvet" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0
, - 1 , ( void * ) "PropellerDynamics" } , { "ndzwvtjpgv" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "PropellerDynamics" }
, { "struct_DAy4VMOKMUhj3u1IcOvsOG" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , (
NULL ) } , { "struct_u2xOoEtpHkUtzKIxOOJ85F" , MDL_INFO_ID_DATA_TYPE , 0 , -
1 , ( NULL ) } , { "struct_cS9JNIA7WhyhnQhWdnNLhC" , MDL_INFO_ID_DATA_TYPE ,
0 , - 1 , ( NULL ) } , { "struct_nGmILHkzXdduNopEcCRSWH" ,
MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , {
"mr_PropellerDynamics_GetSimStateDisallowedBlocks" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "PropellerDynamics" } , {
"mr_PropellerDynamics_extractBitFieldFromCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "PropellerDynamics" } , {
"mr_PropellerDynamics_cacheBitFieldToCellArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "PropellerDynamics" } , {
"mr_PropellerDynamics_restoreDataFromMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "PropellerDynamics" } , {
"mr_PropellerDynamics_cacheDataToMxArrayWithOffset" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "PropellerDynamics" } , {
"mr_PropellerDynamics_extractBitFieldFromMxArray" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "PropellerDynamics" } , {
"mr_PropellerDynamics_cacheBitFieldToMxArray" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "PropellerDynamics" } , {
"mr_PropellerDynamics_restoreDataFromMxArray" , MDL_INFO_ID_MODEL_FCN_NAME ,
0 , - 1 , ( void * ) "PropellerDynamics" } , {
"mr_PropellerDynamics_cacheDataAsMxArray" , MDL_INFO_ID_MODEL_FCN_NAME , 0 ,
- 1 , ( void * ) "PropellerDynamics" } , {
"mr_PropellerDynamics_RegisterSimStateChecksum" , MDL_INFO_ID_MODEL_FCN_NAME
, 0 , - 1 , ( void * ) "PropellerDynamics" } , {
"mr_PropellerDynamics_SetDWork" , MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , (
void * ) "PropellerDynamics" } , { "mr_PropellerDynamics_GetDWork" ,
MDL_INFO_ID_MODEL_FCN_NAME , 0 , - 1 , ( void * ) "PropellerDynamics" } , {
"PropellerDynamics.h" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( NULL ) } , {
"PropellerDynamics.c" , MDL_INFO_MODEL_FILENAME , 0 , - 1 , ( void * )
"PropellerDynamics" } } ; ht5n2qntkht ht5n2qntkh = { 1.0 , { 0.03338 , -
0.1265 , - 0.121 , 0.1142 } , 1.0 , { 0.0428 , - 0.05046 , 0.005711 , -
0.003293 , 0.007048 } , 1.0 , 4.0 , 5.0 } ; void owx3smczj2 ( cauih2yi0g *
localDW ) { localDW -> cmbvvgaq02 = 0 ; } void hgebfhb0qf ( const real_T *
akzpwcud41 , h1jo3kaarc * localZCSV ) { localZCSV -> axzx40ieep = *
akzpwcud41 - ht5n2qntkh . P_2 ; localZCSV -> lzvkcu23cc = * akzpwcud41 -
rtP_minPWM ; } void PropellerDynamics ( ndzwvtjpgv * const n3istur3p5 , const
real_T * akzpwcud41 , const real_T de0biblu0l [ 3 ] , const real_T jgodcikh13
[ 3 ] , const real_T e4xmvna52m [ 3 ] , const real_T p1nux5b0nf [ 3 ] , const
real_T fcurtqao22 [ 3 ] , real_T d5ttxibnex [ 3 ] , real_T bumzwrs5da [ 3 ] ,
real_T * bdy3wtdo2m , hdlladljw4 * localB , cauih2yi0g * localDW ) { real_T
annb3lflth ; real_T cl1xecblr0 ; real_T cufvm1stfs ; real_T d412fnruld ;
real_T eoxyrq1xn4 ; real_T komzhs0tbr ; real_T l21iumy13n ; real_T npp33pyly2
; real_T od5o4bkp0y ; real_T pvw5j2urh0 ; if ( ssIsModeUpdateTimeStep (
n3istur3p5 -> _mdlRefSfcnS ) ) { if ( * akzpwcud41 >= ht5n2qntkh . P_2 ) {
localDW -> cu55bydicj = 1 ; } else if ( * akzpwcud41 > rtP_minPWM ) { localDW
-> cu55bydicj = 0 ; } else { localDW -> cu55bydicj = - 1 ; } } if ( localDW
-> cu55bydicj == 1 ) { komzhs0tbr = ht5n2qntkh . P_2 ; } else if ( localDW ->
cu55bydicj == - 1 ) { komzhs0tbr = rtP_minPWM ; } else { komzhs0tbr = *
akzpwcud41 ; } * bdy3wtdo2m = rtP_uavParam . motor . RPMMAX / 60.0 *
komzhs0tbr ; cl1xecblr0 = jgodcikh13 [ 0 ] * e4xmvna52m [ 1 ] ; komzhs0tbr =
jgodcikh13 [ 1 ] * e4xmvna52m [ 2 ] ; l21iumy13n = e4xmvna52m [ 0 ] *
jgodcikh13 [ 2 ] ; cufvm1stfs = jgodcikh13 [ 0 ] * e4xmvna52m [ 2 ] ;
eoxyrq1xn4 = e4xmvna52m [ 0 ] * jgodcikh13 [ 1 ] ; pvw5j2urh0 = e4xmvna52m [
1 ] * jgodcikh13 [ 2 ] ; komzhs0tbr = ( komzhs0tbr - pvw5j2urh0 ) +
de0biblu0l [ 0 ] ; l21iumy13n = ( l21iumy13n - cufvm1stfs ) + de0biblu0l [ 1
] ; cl1xecblr0 = ( cl1xecblr0 - eoxyrq1xn4 ) + de0biblu0l [ 2 ] ; eoxyrq1xn4
= komzhs0tbr * p1nux5b0nf [ 0 ] ; eoxyrq1xn4 += l21iumy13n * p1nux5b0nf [ 1 ]
; eoxyrq1xn4 += cl1xecblr0 * p1nux5b0nf [ 2 ] ; komzhs0tbr = eoxyrq1xn4 *
p1nux5b0nf [ 0 ] ; l21iumy13n = komzhs0tbr * komzhs0tbr ; komzhs0tbr =
eoxyrq1xn4 * p1nux5b0nf [ 1 ] ; l21iumy13n += komzhs0tbr * komzhs0tbr ;
komzhs0tbr = eoxyrq1xn4 * p1nux5b0nf [ 2 ] ; l21iumy13n += komzhs0tbr *
komzhs0tbr ; if ( rtmIsMajorTimeStep ( n3istur3p5 ) ) { if ( localDW ->
cmbvvgaq02 != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( n3istur3p5
-> _mdlRefSfcnS ) ; ssSetContTimeOutputInconsistentWithStateAtMajorStep (
n3istur3p5 -> _mdlRefSfcnS ) ; localDW -> cmbvvgaq02 = 0 ; } komzhs0tbr =
muDoubleScalarSqrt ( l21iumy13n ) ; } else if ( l21iumy13n < 0.0 ) {
komzhs0tbr = - muDoubleScalarSqrt ( muDoubleScalarAbs ( l21iumy13n ) ) ;
localDW -> cmbvvgaq02 = 1 ; } else { komzhs0tbr = muDoubleScalarSqrt (
l21iumy13n ) ; } l21iumy13n = rtP_uavParam . geom . PropDiameter * *
bdy3wtdo2m ; komzhs0tbr /= l21iumy13n ; l21iumy13n = * bdy3wtdo2m * *
bdy3wtdo2m ; cl1xecblr0 = ( ( ( ht5n2qntkh . P_3 [ 0 ] * komzhs0tbr +
ht5n2qntkh . P_3 [ 1 ] ) * komzhs0tbr + ht5n2qntkh . P_3 [ 2 ] ) * komzhs0tbr
+ ht5n2qntkh . P_3 [ 3 ] ) * ( l21iumy13n * rtP_uavParam . aero . rho *
localB -> g33x3brnwl ) ; d5ttxibnex [ 0 ] = p1nux5b0nf [ 0 ] * cl1xecblr0 *
ht5n2qntkh . P_6 ; d5ttxibnex [ 1 ] = p1nux5b0nf [ 1 ] * cl1xecblr0 *
ht5n2qntkh . P_6 ; d5ttxibnex [ 2 ] = p1nux5b0nf [ 2 ] * cl1xecblr0 *
ht5n2qntkh . P_6 ; cl1xecblr0 = ht5n2qntkh . P_4 * fcurtqao22 [ 2 ] ;
cufvm1stfs = e4xmvna52m [ 0 ] * d5ttxibnex [ 1 ] ; pvw5j2urh0 = e4xmvna52m [
1 ] * d5ttxibnex [ 2 ] ; od5o4bkp0y = d5ttxibnex [ 0 ] * e4xmvna52m [ 2 ] ;
annb3lflth = e4xmvna52m [ 0 ] * d5ttxibnex [ 2 ] ; npp33pyly2 = d5ttxibnex [
0 ] * e4xmvna52m [ 1 ] ; d412fnruld = d5ttxibnex [ 1 ] * e4xmvna52m [ 2 ] ;
eoxyrq1xn4 = ( ( ( ( ht5n2qntkh . P_5 [ 0 ] * komzhs0tbr + ht5n2qntkh . P_5 [
1 ] ) * komzhs0tbr + ht5n2qntkh . P_5 [ 2 ] ) * komzhs0tbr + ht5n2qntkh . P_5
[ 3 ] ) * komzhs0tbr + ht5n2qntkh . P_5 [ 4 ] ) * ( l21iumy13n * rtP_uavParam
. aero . rho * localB -> f4sjvlzpnp ) * cl1xecblr0 ; komzhs0tbr = eoxyrq1xn4
* p1nux5b0nf [ 0 ] ; l21iumy13n = eoxyrq1xn4 * p1nux5b0nf [ 1 ] ; cl1xecblr0
= eoxyrq1xn4 * p1nux5b0nf [ 2 ] ; bumzwrs5da [ 0 ] = ( pvw5j2urh0 -
d412fnruld ) + komzhs0tbr ; bumzwrs5da [ 1 ] = ( od5o4bkp0y - annb3lflth ) +
l21iumy13n ; bumzwrs5da [ 2 ] = ( cufvm1stfs - npp33pyly2 ) + cl1xecblr0 ; }
void PropellerDynamicsTID1 ( hdlladljw4 * localB ) { localB -> g33x3brnwl =
muDoubleScalarPower ( rtP_uavParam . geom . PropDiameter , ht5n2qntkh . P_7 )
; localB -> f4sjvlzpnp = muDoubleScalarPower ( rtP_uavParam . geom .
PropDiameter , ht5n2qntkh . P_8 ) ; } void ctvtngd0gv ( ndzwvtjpgv * const
n3istur3p5 ) { if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( n3istur3p5 -> _mdlRefSfcnS , "PropellerDynamics" ,
"SIMSTATUS_TERMINATING_MODELREF_ACCEL_EVENT" ) ; } } void j3unvwpf2g (
SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , int_T mdlref_TID1 , ndzwvtjpgv
* const n3istur3p5 , hdlladljw4 * localB , cauih2yi0g * localDW , void *
sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const
char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) {
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( void ) memset ( ( void * )
n3istur3p5 , 0 , sizeof ( ndzwvtjpgv ) ) ; n3istur3p5 -> Timing .
mdlref_GlobalTID [ 0 ] = mdlref_TID0 ; n3istur3p5 -> Timing .
mdlref_GlobalTID [ 1 ] = mdlref_TID1 ; n3istur3p5 -> _mdlRefSfcnS = (
_mdlRefSfcnS ) ; if ( ! slIsRapidAcceleratorSimulating ( ) ) {
slmrRunPluginEvent ( n3istur3p5 -> _mdlRefSfcnS , "PropellerDynamics" ,
"START_OF_SIM_MODEL_MODELREF_ACCEL_EVENT" ) ; } { localB -> g33x3brnwl = 0.0
; localB -> f4sjvlzpnp = 0.0 ; } ( void ) memset ( ( void * ) localDW , 0 ,
sizeof ( cauih2yi0g ) ) ; PropellerDynamics_InitializeDataMapInfo (
n3istur3p5 , localDW , sysRanPtr , contextTid ) ; if ( ( rt_ParentMMI != (
NULL ) ) && ( rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( *
rt_ParentMMI , rt_ChildMMIIdx , & ( n3istur3p5 -> DataMapInfo . mmi ) ) ;
rtwCAPI_SetPath ( n3istur3p5 -> DataMapInfo . mmi , rt_ChildPath ) ;
rtwCAPI_MMISetContStateStartIndex ( n3istur3p5 -> DataMapInfo . mmi ,
rt_CSTATEIdx ) ; } } void mr_PropellerDynamics_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; {
boolean_T regSubmodelsMdlinfo = false ; ssGetRegSubmodelsMdlinfo (
mdlRefSfcnS , & regSubmodelsMdlinfo ) ; if ( regSubmodelsMdlinfo ) { } } *
retVal = 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName ,
rtMdlInfo_PropellerDynamics , 44 ) ; * retVal = 1 ; } static void
mr_PropellerDynamics_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) ; static void
mr_PropellerDynamics_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_PropellerDynamics_restoreDataFromMxArray ( void * destData
, const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_PropellerDynamics_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_PropellerDynamics_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) ; static void
mr_PropellerDynamics_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_PropellerDynamics_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_PropellerDynamics_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_PropellerDynamics_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_PropellerDynamics_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_PropellerDynamics_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void
mr_PropellerDynamics_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_PropellerDynamics_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_PropellerDynamics_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_PropellerDynamics_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_PropellerDynamics_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_PropellerDynamics_GetDWork ( const
bfxsfyeisx3 * mdlrefDW ) { static const char_T * ssDWFieldNames [ 3 ] = {
"rtb" , "rtdw" , "NULL->rtzce" , } ; mxArray * ssDW = mxCreateStructMatrix (
1 , 1 , 3 , ssDWFieldNames ) ; mr_PropellerDynamics_cacheDataAsMxArray ( ssDW
, 0 , 0 , ( const void * ) & ( mdlrefDW -> rtb ) , sizeof ( mdlrefDW -> rtb )
) ; { static const char_T * rtdwDataFieldNames [ 2 ] = {
"mdlrefDW->rtdw.cu55bydicj" , "mdlrefDW->rtdw.cmbvvgaq02" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 2 , rtdwDataFieldNames ) ;
mr_PropellerDynamics_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * )
& ( mdlrefDW -> rtdw . cu55bydicj ) , sizeof ( mdlrefDW -> rtdw . cu55bydicj
) ) ; mr_PropellerDynamics_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const
void * ) & ( mdlrefDW -> rtdw . cmbvvgaq02 ) , sizeof ( mdlrefDW -> rtdw .
cmbvvgaq02 ) ) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } ( void )
mdlrefDW ; return ssDW ; } void mr_PropellerDynamics_SetDWork ( bfxsfyeisx3 *
mdlrefDW , const mxArray * ssDW ) { ( void ) ssDW ; ( void ) mdlrefDW ;
mr_PropellerDynamics_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtb
) , ssDW , 0 , 0 , sizeof ( mdlrefDW -> rtb ) ) ; { const mxArray * rtdwData
= mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_PropellerDynamics_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW -> rtdw
. cu55bydicj ) , rtdwData , 0 , 0 , sizeof ( mdlrefDW -> rtdw . cu55bydicj )
) ; mr_PropellerDynamics_restoreDataFromMxArray ( ( void * ) & ( mdlrefDW ->
rtdw . cmbvvgaq02 ) , rtdwData , 0 , 1 , sizeof ( mdlrefDW -> rtdw .
cmbvvgaq02 ) ) ; } } void mr_PropellerDynamics_RegisterSimStateChecksum (
SimStruct * S ) { const uint32_T chksum [ 4 ] = { 3885523115U , 4001784753U ,
3477727034U , 4086142801U , } ; slmrModelRefRegisterSimStateChecksum ( S ,
"PropellerDynamics" , & chksum [ 0 ] ) ; } mxArray *
mr_PropellerDynamics_GetSimStateDisallowedBlocks ( ) { return ( NULL ) ; }
#if defined(_MSC_VER)
#pragma warning(disable: 4505) //unreferenced local function has been removed
#endif
