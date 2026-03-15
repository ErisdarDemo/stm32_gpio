/**************************************************************************************************/
/** @file     component.h
 *  @brief    Component interface for public API
 *  @details  interface file header is typically omitted in preference for source file header
 *
 *  @note   Consider replacing compConfig.comps with dynamic alloc as a ptr
 */
/**************************************************************************************************/
#ifndef DEMO_OTHER_H
#define DEMO_OTHER_H

//************************************************************************************************//
//                                            INCLUDES                                            //
//************************************************************************************************//

//Standard Library Includes

//Library Includes

//BSP Includes

//Project Includes


//************************************************************************************************//
//                                        DEFINITIONS & TYPES                                     //
//************************************************************************************************//

//-----------------------------------------  Definitions -----------------------------------------//

#define COMP_NUM_ITEMS    (1)


//-------------------------------------------- Macros --------------------------------------------//


//----------------------------------------- Enumerations -----------------------------------------//


//------------------------------------------- Typedefs -------------------------------------------//

//Setup
typedef struct compConfig {
    int comps[COMP_NUM_ITEMS];                      /* qualifying descrip for comps e.g.  pins    */
    
    int paramOne;                                   /* qualifying descrip for param               */
    int paramTwo;                                   /* qualifying descrip for param               */
    /* .... */  
} CompConfig;


//************************************************************************************************//
//                                            VARIABLES                                           //
//************************************************************************************************//


//************************************************************************************************//
//                                       FUNCTION DECLARATIONS                                    //
//************************************************************************************************//

//-------------------------------------------- Public --------------------------------------------//

//Setup
extern void demo_other_init(CompConfig *cfg);
extern void demo_other_enable(void);
extern void demo_other_disable(void);

//Action
extern void  demo_other_start(void);
extern void  demo_other_stop(void);
extern void *demo_other_status(void);                /* current status of API performance          */
extern void  demo_other_reset(void);

//Configure
extern void        demo_other_setConfig(CompConfig *cfg);
extern CompConfig *demo_other_getConfig(void);       /* applied configuration for use              */
extern void       *demo_other_getInfo(void);         /* current operational state                  */

//Get-Set
extern int  demo_other_getState(void);
extern void demo_other_setState(int val);

//Read-Write
extern int  demo_other_read(void);
extern void demo_other_write(int val);

//Log
extern void *demo_other_getLog(void);

//Int
extern void demo_other_callback(void);               /* default peripheral interrupt callback      */


//-------------------------------------------- Private -------------------------------------------//


#endif /*  DEMO_OTHER_H */

