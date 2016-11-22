#include "__cf_ACStesbed1.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) , sizeof ( BusObject ) } ; static const
char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T"
, "int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" ,
"fcn_call_T" , "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" ,
"BusObject" } ; static DataTypeTransition rtBTransitions [ ] = { { ( char_T *
) ( & rtB . njvqg5q4aw [ 0 ] ) , 0 , 0 , 333 } , { ( char_T * ) ( & rtDW .
m5suqpxty3 ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtDW . bknzq3wgub . TimePtr [
0 ] ) , 11 , 0 , 25 } , { ( char_T * ) ( & rtDW . hvy1dfvqu0 ) , 7 , 0 , 2 }
, { ( char_T * ) ( & rtDW . fibx4ptf5m . PrevIndex [ 0 ] ) , 10 , 0 , 21 } ,
{ ( char_T * ) ( & rtDW . ks4j0in3rc ) , 2 , 0 , 30 } , { ( char_T * ) ( &
rtDW . bn411rqyba ) , 8 , 0 , 8 } } ; static DataTypeTransitionTable
rtBTransTable = { 7U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . Constant_Value ) , 0 , 0 ,
19933 } } ; static DataTypeTransitionTable rtPTransTable = { 1U ,
rtPTransitions } ;
