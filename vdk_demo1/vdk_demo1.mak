# Generated by the VisualDSP++ IDDE

# Note:  Any changes made to this Makefile will be lost the next time the
# matching project file is loaded into the IDDE.  If you wish to preserve
# changes, rename this file and run it externally to the IDDE.

# The syntax of this Makefile is such that GNU Make v3.77 or higher is
# required.

# The current working directory should be the directory in which this
# Makefile resides.

# Supported targets:
#     vdk_demo1_Debug
#     vdk_demo1_Debug_clean

# Define this variable if you wish to run this Makefile on a host
# other than the host that created it and VisualDSP++ may be installed
# in a different directory.

ADI_DSP=C:\Program Files\Analog Devices\VisualDSP 5.0


# $VDSP is a gmake-friendly version of ADI_DIR

empty:=
space:= $(empty) $(empty)
VDSP_INTERMEDIATE=$(subst \,/,$(ADI_DSP))
VDSP=$(subst $(space),\$(space),$(VDSP_INTERMEDIATE))

RM=cmd /C del /F /Q

#
# Begin "vdk_demo1_Debug" configuration
#

ifeq ($(MAKECMDGOALS),vdk_demo1_Debug)

vdk_demo1_Debug : ./Debug/vdk_demo1.dxe 

./Debug/ExceptionHandler-BF536.doj :./ExceptionHandler-BF536.asm ./VDK.h $(VDSP)/Blackfin/include/VDK_Public.h $(VDSP)/Blackfin/include/defBF534.h $(VDSP)/Blackfin/include/defBF536.h $(VDSP)/Blackfin/include/defBF537.h $(VDSP)/Blackfin/include/def_LPBlackfin.h 
	@echo ".\ExceptionHandler-BF536.asm"
	$(VDSP)/easmblkfn.exe .\ExceptionHandler-BF536.asm -proc ADSP-BF536 -file-attr ProjectName=vdk_demo1 -g -D_ADI_THREADS -o .\Debug\ExceptionHandler-BF536.doj -MM

Debug/P_thread1.doj :P_thread1.c P_thread1.h VDK.h $(VDSP)/Blackfin/include/defBF536.h $(VDSP)/Blackfin/include/defBF537.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/defBF534.h $(VDSP)/Blackfin/include/VDK_Public.h $(VDSP)/Blackfin/include/limits.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdio.h $(VDSP)/Blackfin/include/sys/stdio_bf.h 
	@echo ".\P_thread1.c"
	$(VDSP)/ccblkfn.exe -c .\P_thread1.c -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -threads -proc ADSP-BF536 -o .\Debug\P_thread1.doj -MM

Debug/P_thread2.doj :P_thread2.c P_thread2.h VDK.h $(VDSP)/Blackfin/include/defBF536.h $(VDSP)/Blackfin/include/defBF537.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/defBF534.h $(VDSP)/Blackfin/include/VDK_Public.h $(VDSP)/Blackfin/include/limits.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stdio.h $(VDSP)/Blackfin/include/sys/stdio_bf.h 
	@echo ".\P_thread2.c"
	$(VDSP)/ccblkfn.exe -c .\P_thread2.c -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -threads -proc ADSP-BF536 -o .\Debug\P_thread2.doj -MM

Debug/VDK.doj :VDK.cpp VDK.h $(VDSP)/Blackfin/include/defBF536.h $(VDSP)/Blackfin/include/defBF537.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/defBF534.h $(VDSP)/Blackfin/include/VDK_Public.h $(VDSP)/Blackfin/include/limits.h $(VDSP)/Blackfin/include/yvals.h $(VDSP)/Blackfin/include/stddef.h $(VDSP)/Blackfin/include/assert.h $(VDSP)/Blackfin/include/sys/platform.h $(VDSP)/Blackfin/include/sys/_adi_platform.h $(VDSP)/Blackfin/include/cdefBF536.h $(VDSP)/Blackfin/include/cdefBF537.h $(VDSP)/Blackfin/include/cdefBF534.h $(VDSP)/Blackfin/include/cdef_LPBlackfin.h $(VDSP)/Blackfin/include/cplus/new $(VDSP)/Blackfin/include/cplus/exception $(VDSP)/Blackfin/include/cplus/xstddef $(VDSP)/Blackfin/include/cplus/cstddef $(VDSP)/Blackfin/include/string.h $(VDSP)/Blackfin/include/stdlib.h $(VDSP)/Blackfin/include/stdlib_bf.h $(VDSP)/Blackfin/include/VDK_Internals.h $(VDSP)/Blackfin/include/sys/exception.h P_thread1.h P_thread2.h 
	@echo ".\VDK.cpp"
	$(VDSP)/ccblkfn.exe -c .\VDK.cpp -c++ -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -threads -proc ADSP-BF536 -o .\Debug\VDK.doj -MM

VDK.h VDK.cpp vdk_demo1.rbld :$(VDSP)/blackfin/vdk/VDK.cpp.tf $(VDSP)/blackfin/vdk/VDK.h.tf $(VDSP)/blackfin/vdk/VDKGen.exe ./vdk_demo1.vdk vdk_demo1.rbld 
	@echo ".\vdk_demo1.vdk"
	$(VDSP)/Blackfin\vdk\vdkgen.exe .\vdk_demo1.vdk -proc ADSP-BF536 -MM

./Debug/vdk_demo1_basiccrt.doj :./vdk_demo1_basiccrt.s $(VDSP)/Blackfin/include/defBF534.h $(VDSP)/Blackfin/include/defBF536.h $(VDSP)/Blackfin/include/defBF537.h $(VDSP)/Blackfin/include/def_LPBlackfin.h $(VDSP)/Blackfin/include/sys/_adi_platform.h $(VDSP)/Blackfin/include/sys/anomaly_macros_rtl.h $(VDSP)/Blackfin/include/sys/platform.h 
	@echo ".\vdk_demo1_basiccrt.s"
	$(VDSP)/easmblkfn.exe .\vdk_demo1_basiccrt.s -proc ADSP-BF536 -file-attr ProjectName=vdk_demo1 -g -D_ADI_THREADS -o .\Debug\vdk_demo1_basiccrt.doj -MM

Debug/vdk_demo1_heaptab.doj :vdk_demo1_heaptab.c 
	@echo ".\vdk_demo1_heaptab.c"
	$(VDSP)/ccblkfn.exe -c .\vdk_demo1_heaptab.c -g -structs-do-not-overlap -no-multiline -double-size-32 -decls-strong -warn-protos -threads -proc ADSP-BF536 -o .\Debug\vdk_demo1_heaptab.doj -MM

./Debug/vdk_demo1.dxe :./VDK.h ./vdk_demo1.ldf ./Debug/vdk_demo1_basiccrt.doj ./Debug/ExceptionHandler-BF536.doj ./Debug/P_thread1.doj ./Debug/P_thread2.doj ./Debug/VDK.doj ./Debug/vdk_demo1_heaptab.doj $(VDSP)/Blackfin/lib/cplbtab536.doj $(VDSP)/Blackfin/lib/bf534_rev_0.3/crtn532y.doj $(VDSP)/Blackfin/lib/bf534_rev_0.3/TMK-BF532.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/vdk-CORE-BF532.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/vdk-i-BF532.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/libsmall532mty.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/libio532mty.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/libc532mty.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/libevent532mty.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/libx532mty.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/libcpp532mty.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/libcpprt532mty.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/libf64ieee532y.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/libdsp532y.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/libsftflt532y.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/libetsi532y.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/Debug/libssl537_vdky.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/Debug/libdrv537y.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/Debug/libusb537y.dlb $(VDSP)/Blackfin/lib/bf534_rev_0.3/idle532mty.doj $(VDSP)/Blackfin/lib/bf534_rev_0.3/librt_fileio532mty.dlb 
	@echo "Linking..."
	$(VDSP)/ccblkfn.exe .\Debug\ExceptionHandler-BF536.doj .\Debug\P_thread1.doj .\Debug\P_thread2.doj .\Debug\VDK.doj .\Debug\vdk_demo1_basiccrt.doj .\Debug\vdk_demo1_heaptab.doj -T .\vdk_demo1.ldf -L .\Debug -flags-link -MDUSER_CRT=ADI_QUOTEvdk_demo1_basiccrt.dojADI_QUOTE,-MDUSE_FILEIO,-MD__cplusplus -add-debug-libpaths -flags-link -od,.\Debug -o .\Debug\vdk_demo1.dxe -proc ADSP-BF536 -flags-link -MD_ADI_THREADS -flags-link -MM

endif

ifeq ($(MAKECMDGOALS),vdk_demo1_Debug_clean)

vdk_demo1_Debug_clean:
	-$(RM) ".\Debug\ExceptionHandler-BF536.doj"
	-$(RM) "Debug\P_thread1.doj"
	-$(RM) "Debug\P_thread2.doj"
	-$(RM) "Debug\VDK.doj"
	-$(RM) ".\Debug\vdk_demo1_basiccrt.doj"
	-$(RM) "Debug\vdk_demo1_heaptab.doj"
	-$(RM) ".\Debug\vdk_demo1.dxe"
	-$(RM) ".\Debug\*.ipa"
	-$(RM) ".\Debug\*.opa"
	-$(RM) ".\Debug\*.ti"
	-$(RM) ".\Debug\*.pgi"
	-$(RM) ".\*.rbld"

endif


