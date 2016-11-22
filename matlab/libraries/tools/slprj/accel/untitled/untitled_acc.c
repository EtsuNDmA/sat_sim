#include "__cf_untitled.h"
#include <math.h>
#include "untitled_acc.h"
#include "untitled_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T eeuqh5q5nv [ 3
] ; real_T pa50t4b3dn [ 6 ] ; real_T pv32z1bzou ; real_T gy3mzkjmau ; int32_T
i ; real_T fuv5dnpz51_p ; fsg2leehhc * _rtB ; g0szqdi43g * _rtP ; duq1u2s0wi
* _rtX ; kywlqvr0yp * _rtDW ; _rtDW = ( ( kywlqvr0yp * ) ssGetRootDWork ( S )
) ; _rtX = ( ( duq1u2s0wi * ) ssGetContStates ( S ) ) ; _rtP = ( ( g0szqdi43g
* ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( fsg2leehhc * ) _ssGetBlockIO ( S )
) ; _rtB -> crn03rus2b = _rtX -> fr0yv3xbqo ; _rtB -> ajbq20vppm [ 0 ] = _rtX
-> bpck5n5zaq [ 0 ] ; _rtB -> blmahtorz5 [ 0 ] = _rtX -> ooyttrphgp [ 0 ] ;
_rtB -> mw5vansroa [ 0 ] = _rtP -> P_6 [ 0 ] * _rtB -> crn03rus2b + _rtB ->
blmahtorz5 [ 0 ] ; _rtB -> ajbq20vppm [ 1 ] = _rtX -> bpck5n5zaq [ 1 ] ; _rtB
-> blmahtorz5 [ 1 ] = _rtX -> ooyttrphgp [ 1 ] ; _rtB -> mw5vansroa [ 1 ] =
_rtP -> P_6 [ 1 ] * _rtB -> crn03rus2b + _rtB -> blmahtorz5 [ 1 ] ; _rtB ->
ajbq20vppm [ 2 ] = _rtX -> bpck5n5zaq [ 2 ] ; _rtB -> blmahtorz5 [ 2 ] = _rtX
-> ooyttrphgp [ 2 ] ; _rtB -> mw5vansroa [ 2 ] = _rtP -> P_6 [ 2 ] * _rtB ->
crn03rus2b + _rtB -> blmahtorz5 [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> aifhto12qx [ 0 ] = _rtB -> mw5vansroa [ 0 ] ; _rtB -> c0vmpsbmdf [ 0
] = ( _rtB -> a10iranybs [ 0 ] - _rtB -> aifhto12qx [ 0 ] ) * _rtP -> P_7 ;
_rtB -> aifhto12qx [ 1 ] = _rtB -> mw5vansroa [ 1 ] ; _rtB -> c0vmpsbmdf [ 1
] = ( _rtB -> a10iranybs [ 1 ] - _rtB -> aifhto12qx [ 1 ] ) * _rtP -> P_7 ;
_rtB -> aifhto12qx [ 2 ] = _rtB -> mw5vansroa [ 2 ] ; _rtB -> c0vmpsbmdf [ 2
] = ( _rtB -> a10iranybs [ 2 ] - _rtB -> aifhto12qx [ 2 ] ) * _rtP -> P_7 ; }
_rtB -> hhu5nv0pqc [ 0 ] = ( _rtB -> kkyje2dxd2 [ 0 ] - _rtB -> ajbq20vppm [
0 ] ) * _rtP -> P_2 + _rtB -> c0vmpsbmdf [ 0 ] ; _rtB -> hhu5nv0pqc [ 1 ] = (
_rtB -> kkyje2dxd2 [ 1 ] - _rtB -> ajbq20vppm [ 1 ] ) * _rtP -> P_2 + _rtB ->
c0vmpsbmdf [ 1 ] ; _rtB -> hhu5nv0pqc [ 2 ] = ( _rtB -> kkyje2dxd2 [ 2 ] -
_rtB -> ajbq20vppm [ 2 ] ) * _rtP -> P_2 + _rtB -> c0vmpsbmdf [ 2 ] ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> m3v4uhp21i [ 0 ] = _rtB -> hhu5nv0pqc [
0 ] >= _rtP -> P_8 ? 1 : _rtB -> hhu5nv0pqc [ 0 ] > _rtP -> P_9 ? 0 : - 1 ;
_rtDW -> m3v4uhp21i [ 1 ] = _rtB -> hhu5nv0pqc [ 1 ] >= _rtP -> P_8 ? 1 :
_rtB -> hhu5nv0pqc [ 1 ] > _rtP -> P_9 ? 0 : - 1 ; _rtDW -> m3v4uhp21i [ 2 ]
= _rtB -> hhu5nv0pqc [ 2 ] >= _rtP -> P_8 ? 1 : _rtB -> hhu5nv0pqc [ 2 ] >
_rtP -> P_9 ? 0 : - 1 ; } _rtB -> pkmsfcnt02 [ 0 ] = _rtDW -> m3v4uhp21i [ 0
] == 1 ? _rtP -> P_8 : _rtDW -> m3v4uhp21i [ 0 ] == - 1 ? _rtP -> P_9 : _rtB
-> hhu5nv0pqc [ 0 ] ; _rtB -> pkmsfcnt02 [ 1 ] = _rtDW -> m3v4uhp21i [ 1 ] ==
1 ? _rtP -> P_8 : _rtDW -> m3v4uhp21i [ 1 ] == - 1 ? _rtP -> P_9 : _rtB ->
hhu5nv0pqc [ 1 ] ; _rtB -> pkmsfcnt02 [ 2 ] = _rtDW -> m3v4uhp21i [ 2 ] == 1
? _rtP -> P_8 : _rtDW -> m3v4uhp21i [ 2 ] == - 1 ? _rtP -> P_9 : _rtB ->
hhu5nv0pqc [ 2 ] ; ssCallAccelRunBlock ( S , 0 , 15 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> ajbq20vppm [ 0 ] = _rtX -> bzfh4clrnw [ 0 ] ; _rtB -> g3suzz4rqf [ 0
] = _rtB -> mw5vansroa [ 0 ] - _rtB -> blmahtorz5 [ 0 ] ; _rtB -> ajbq20vppm
[ 1 ] = _rtX -> bzfh4clrnw [ 1 ] ; _rtB -> g3suzz4rqf [ 1 ] = _rtB ->
mw5vansroa [ 1 ] - _rtB -> blmahtorz5 [ 1 ] ; _rtB -> ajbq20vppm [ 2 ] = _rtX
-> bzfh4clrnw [ 2 ] ; _rtB -> g3suzz4rqf [ 2 ] = _rtB -> mw5vansroa [ 2 ] -
_rtB -> blmahtorz5 [ 2 ] ; ssCallAccelRunBlock ( S , 0 , 18 ,
SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i < 3 ; i ++ ) { eeuqh5q5nv [ i ] =
_rtP -> P_13 [ i + 6 ] * _rtB -> blmahtorz5 [ 2 ] + ( _rtP -> P_13 [ i + 3 ]
* _rtB -> blmahtorz5 [ 1 ] + _rtP -> P_13 [ i ] * _rtB -> blmahtorz5 [ 0 ] )
; } pa50t4b3dn [ 0 ] = _rtB -> blmahtorz5 [ 1 ] * eeuqh5q5nv [ 2 ] ;
pa50t4b3dn [ 1 ] = _rtB -> blmahtorz5 [ 2 ] * eeuqh5q5nv [ 0 ] ; pa50t4b3dn [
2 ] = _rtB -> blmahtorz5 [ 0 ] * eeuqh5q5nv [ 1 ] ; pa50t4b3dn [ 3 ] = _rtB
-> blmahtorz5 [ 2 ] * eeuqh5q5nv [ 1 ] ; pa50t4b3dn [ 4 ] = _rtB ->
blmahtorz5 [ 0 ] * eeuqh5q5nv [ 2 ] ; pa50t4b3dn [ 5 ] = _rtB -> blmahtorz5 [
1 ] * eeuqh5q5nv [ 0 ] ; fuv5dnpz51_p = 0.0 ; for ( i = 0 ; i < 3 ; i ++ ) {
_rtB -> g3suzz4rqf [ i ] = pa50t4b3dn [ i ] - pa50t4b3dn [ i + 3 ] ;
fuv5dnpz51_p += _rtB -> pkmsfcnt02 [ i ] * _rtB -> mdvapwqcso [ i ] ;
eeuqh5q5nv [ i ] = _rtP -> P_17 [ i + 6 ] * _rtB -> pkmsfcnt02 [ 2 ] + ( _rtP
-> P_17 [ i + 3 ] * _rtB -> pkmsfcnt02 [ 1 ] + _rtP -> P_17 [ i ] * _rtB ->
pkmsfcnt02 [ 0 ] ) ; } pv32z1bzou = _rtP -> P_14 * _rtB -> crn03rus2b ;
gy3mzkjmau = _rtP -> P_16 * _rtX -> eg35snt5px ; ssCallAccelRunBlock ( S , 0
, 29 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> ki5rdz55fn = ( fuv5dnpz51_p -
gy3mzkjmau ) - pv32z1bzou ; _rtB -> alpjrim1mu [ 0 ] = eeuqh5q5nv [ 0 ] -
_rtB -> g3suzz4rqf [ 0 ] ; _rtB -> alpjrim1mu [ 1 ] = eeuqh5q5nv [ 1 ] - _rtB
-> g3suzz4rqf [ 1 ] ; _rtB -> alpjrim1mu [ 2 ] = eeuqh5q5nv [ 2 ] - _rtB ->
g3suzz4rqf [ 2 ] ; UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID2 (
SimStruct * S , int_T tid ) { fsg2leehhc * _rtB ; g0szqdi43g * _rtP ; _rtP =
( ( g0szqdi43g * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( fsg2leehhc * )
_ssGetBlockIO ( S ) ) ; _rtB -> kkyje2dxd2 [ 0 ] = _rtP -> P_0 [ 0 ] ; _rtB
-> a10iranybs [ 0 ] = _rtP -> P_3 [ 0 ] ; _rtB -> mdvapwqcso [ 0 ] = _rtP ->
P_11 [ 0 ] ; _rtB -> pam1dx0pkc [ 0 ] = _rtP -> P_12 [ 0 ] ; _rtB ->
kkyje2dxd2 [ 1 ] = _rtP -> P_0 [ 1 ] ; _rtB -> a10iranybs [ 1 ] = _rtP -> P_3
[ 1 ] ; _rtB -> mdvapwqcso [ 1 ] = _rtP -> P_11 [ 1 ] ; _rtB -> pam1dx0pkc [
1 ] = _rtP -> P_12 [ 1 ] ; _rtB -> kkyje2dxd2 [ 2 ] = _rtP -> P_0 [ 2 ] ;
_rtB -> a10iranybs [ 2 ] = _rtP -> P_3 [ 2 ] ; _rtB -> mdvapwqcso [ 2 ] =
_rtP -> P_11 [ 2 ] ; _rtB -> pam1dx0pkc [ 2 ] = _rtP -> P_12 [ 2 ] ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER ( tid
) ; }
#define MDL_UPDATE
static void mdlUpdateTID2 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { fsg2leehhc * _rtB ; d1e4i05lcy
* _rtXdot ; _rtXdot = ( ( d1e4i05lcy * ) ssGetdX ( S ) ) ; _rtB = ( (
fsg2leehhc * ) _ssGetBlockIO ( S ) ) ; _rtXdot -> fr0yv3xbqo = _rtB ->
ki5rdz55fn ; _rtXdot -> bpck5n5zaq [ 0 ] = _rtB -> aifhto12qx [ 0 ] ; _rtXdot
-> ooyttrphgp [ 0 ] = _rtB -> alpjrim1mu [ 0 ] ; _rtXdot -> bzfh4clrnw [ 0 ]
= _rtB -> blmahtorz5 [ 0 ] ; _rtXdot -> bpck5n5zaq [ 1 ] = _rtB -> aifhto12qx
[ 1 ] ; _rtXdot -> ooyttrphgp [ 1 ] = _rtB -> alpjrim1mu [ 1 ] ; _rtXdot ->
bzfh4clrnw [ 1 ] = _rtB -> blmahtorz5 [ 1 ] ; _rtXdot -> bpck5n5zaq [ 2 ] =
_rtB -> aifhto12qx [ 2 ] ; _rtXdot -> ooyttrphgp [ 2 ] = _rtB -> alpjrim1mu [
2 ] ; _rtXdot -> bzfh4clrnw [ 2 ] = _rtB -> blmahtorz5 [ 2 ] ; _rtXdot ->
eg35snt5px = _rtB -> crn03rus2b ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { fsg2leehhc * _rtB ;
g0szqdi43g * _rtP ; avyyf1we1b * _rtZCSV ; _rtZCSV = ( ( avyyf1we1b * )
ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( ( g0szqdi43g * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( fsg2leehhc * ) _ssGetBlockIO ( S ) ) ;
_rtZCSV -> njd5ptkgnv [ 0 ] = _rtB -> hhu5nv0pqc [ 0 ] - _rtP -> P_8 ;
_rtZCSV -> bqvvzliou3 [ 0 ] = _rtB -> hhu5nv0pqc [ 0 ] - _rtP -> P_9 ;
_rtZCSV -> njd5ptkgnv [ 1 ] = _rtB -> hhu5nv0pqc [ 1 ] - _rtP -> P_8 ;
_rtZCSV -> bqvvzliou3 [ 1 ] = _rtB -> hhu5nv0pqc [ 1 ] - _rtP -> P_9 ;
_rtZCSV -> njd5ptkgnv [ 2 ] = _rtB -> hhu5nv0pqc [ 2 ] - _rtP -> P_8 ;
_rtZCSV -> bqvvzliou3 [ 2 ] = _rtB -> hhu5nv0pqc [ 2 ] - _rtP -> P_9 ; }
static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 ,
4025444202U ) ; ssSetChecksumVal ( S , 1 , 1551129560U ) ; ssSetChecksumVal (
S , 2 , 2901920185U ) ; ssSetChecksumVal ( S , 3 , 3803136397U ) ; { mxArray
* slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" )
; char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat ,
1 , & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat =
mxGetField ( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) {
status = 1 ; } else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; }
} mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.6" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( kywlqvr0yp ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( fsg2leehhc ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
g0szqdi43g ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & lxkrdcync0 ) ; } static void mdlInitializeSampleTimes (
SimStruct * S ) { slAccRegPrmChangeFcn ( S , mdlOutputsTID2 ) ; } static void
mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
