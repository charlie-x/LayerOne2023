#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-HT_PIC16F54_BootLoader.mk)" "nbproject/Makefile-local-HT_PIC16F54_BootLoader.mk"
include nbproject/Makefile-local-HT_PIC16F54_BootLoader.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=HT_PIC16F54_BootLoader
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/OKBBPIC_firmware.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/OKBBPIC_firmware.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c Usb.c ws2812.c keyboard.c flash.c effects.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.p1 ${OBJECTDIR}/Usb.p1 ${OBJECTDIR}/ws2812.p1 ${OBJECTDIR}/keyboard.p1 ${OBJECTDIR}/flash.p1 ${OBJECTDIR}/effects.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/main.p1.d ${OBJECTDIR}/Usb.p1.d ${OBJECTDIR}/ws2812.p1.d ${OBJECTDIR}/keyboard.p1.d ${OBJECTDIR}/flash.p1.d ${OBJECTDIR}/effects.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.p1 ${OBJECTDIR}/Usb.p1 ${OBJECTDIR}/ws2812.p1 ${OBJECTDIR}/keyboard.p1 ${OBJECTDIR}/flash.p1 ${OBJECTDIR}/effects.p1

# Source Files
SOURCEFILES=main.c Usb.c ws2812.c keyboard.c flash.c effects.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-HT_PIC16F54_BootLoader.mk ${DISTDIR}/OKBBPIC_firmware.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F1455
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Usb.p1: Usb.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Usb.p1.d 
	@${RM} ${OBJECTDIR}/Usb.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Usb.p1 Usb.c 
	@-${MV} ${OBJECTDIR}/Usb.d ${OBJECTDIR}/Usb.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Usb.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ws2812.p1: ws2812.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ws2812.p1.d 
	@${RM} ${OBJECTDIR}/ws2812.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ws2812.p1 ws2812.c 
	@-${MV} ${OBJECTDIR}/ws2812.d ${OBJECTDIR}/ws2812.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ws2812.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/keyboard.p1: keyboard.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/keyboard.p1.d 
	@${RM} ${OBJECTDIR}/keyboard.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/keyboard.p1 keyboard.c 
	@-${MV} ${OBJECTDIR}/keyboard.d ${OBJECTDIR}/keyboard.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/keyboard.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/flash.p1: flash.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/flash.p1.d 
	@${RM} ${OBJECTDIR}/flash.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/flash.p1 flash.c 
	@-${MV} ${OBJECTDIR}/flash.d ${OBJECTDIR}/flash.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/flash.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/effects.p1: effects.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/effects.p1.d 
	@${RM} ${OBJECTDIR}/effects.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/effects.p1 effects.c 
	@-${MV} ${OBJECTDIR}/effects.d ${OBJECTDIR}/effects.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/effects.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Usb.p1: Usb.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Usb.p1.d 
	@${RM} ${OBJECTDIR}/Usb.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/Usb.p1 Usb.c 
	@-${MV} ${OBJECTDIR}/Usb.d ${OBJECTDIR}/Usb.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Usb.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ws2812.p1: ws2812.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ws2812.p1.d 
	@${RM} ${OBJECTDIR}/ws2812.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ws2812.p1 ws2812.c 
	@-${MV} ${OBJECTDIR}/ws2812.d ${OBJECTDIR}/ws2812.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ws2812.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/keyboard.p1: keyboard.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/keyboard.p1.d 
	@${RM} ${OBJECTDIR}/keyboard.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/keyboard.p1 keyboard.c 
	@-${MV} ${OBJECTDIR}/keyboard.d ${OBJECTDIR}/keyboard.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/keyboard.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/flash.p1: flash.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/flash.p1.d 
	@${RM} ${OBJECTDIR}/flash.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/flash.p1 flash.c 
	@-${MV} ${OBJECTDIR}/flash.d ${OBJECTDIR}/flash.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/flash.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/effects.p1: effects.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/effects.p1.d 
	@${RM} ${OBJECTDIR}/effects.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     -o ${OBJECTDIR}/effects.p1 effects.c 
	@-${MV} ${OBJECTDIR}/effects.d ${OBJECTDIR}/effects.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/effects.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/OKBBPIC_firmware.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/OKBBPIC_firmware.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits -std=c90 -gdwarf-3 -mstack=compiled:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/OKBBPIC_firmware.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/OKBBPIC_firmware.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/OKBBPIC_firmware.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/OKBBPIC_firmware.${IMAGE_TYPE}.map  -DXPRJ_HT_PIC16F54_BootLoader=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fshort-double -fshort-float -mrom=default,-0-1FF,-1F7F-1F7F -O2 -fasmfile -maddrqual=ignore -DUSE_BOOTLOADER -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file -mcodeoffset=0x200  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mdownload -mno-stackcall -mdefault-config-bits -std=c90 -gdwarf-3 -mstack=compiled:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/OKBBPIC_firmware.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
