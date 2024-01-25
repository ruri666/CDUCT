#############################################################################
# Makefile for building: QWCalSoftware
# Generated by qmake (3.1) (Qt 5.15.2)
# Project:  QWCalSoftware.pro
# Template: app
# Command: D:\7777777\Software\Qt\5.15.2\mingw81_64\bin\qmake.exe -o Makefile QWCalSoftware.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
#############################################################################

MAKEFILE      = Makefile

EQ            = =

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = D:\7777777\Software\Qt\5.15.2\mingw81_64\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = D:\7777777\Software\Qt\5.15.2\mingw81_64\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = D:\7777777\Software\Qt\5.15.2\mingw81_64\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
IDC           = idc
IDL           = midl
ZIP           = zip -r -9
DEF_FILE      = 
RES_FILE      = 
SED           = $(QMAKE) -install sed
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: QWCalSoftware.pro D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/win32-g++/qmake.conf D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/spec_pre.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/qdevice.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/device_config.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/sanitize.conf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/gcc-base.conf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/g++-base.conf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/angle.conf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/win32/windows_vulkan_sdk.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/windows-vulkan.conf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/g++-win32.conf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/windows-desktop.conf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/qconfig.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3danimation.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3danimation_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dcore.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dcore_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dextras.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dextras_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dinput.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dinput_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dlogic.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dlogic_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquick.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquick_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickanimation.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickanimation_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickextras.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickinput.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickrender.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickscene2d.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickscene2d_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3drender.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3drender_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_axbase.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_axbase_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_axcontainer.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_axcontainer_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_axserver.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_axserver_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_bluetooth.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_bodymovin_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_charts.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_charts_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_concurrent.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_core.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_core_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_datavisualization.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_datavisualization_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_dbus.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_dbus_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_designer.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_designer_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_edid_support_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_egl_support_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_fb_support_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_gamepad.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_gamepad_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_gui.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_gui_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_help.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_help_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_location.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_location_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_multimedia.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_network.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_network_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_networkauth.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_networkauth_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_nfc.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_nfc_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_opengl.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_opengl_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_openglextensions.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_positioning.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_positioning_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_positioningquick.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_positioningquick_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_printsupport.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_purchasing.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_purchasing_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qml.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qml_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmldebug_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmlmodels.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmlmodels_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmltest.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmlworkerscript.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmlworkerscript_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3d.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3d_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3dassetimport.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3dassetimport_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3drender.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3drender_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3druntimerender.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3druntimerender_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3dutils.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3dutils_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quickcontrols2.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quickshapes_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quicktemplates2.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_remoteobjects.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_remoteobjects_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_repparser.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_repparser_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_script.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_script_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_scripttools.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_scxml.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_scxml_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_sensors.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_sensors_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_serialbus.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_serialbus_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_serialport.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_serialport_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_sql.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_sql_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_svg.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_svg_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_testlib.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_testlib_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_texttospeech.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_texttospeech_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_theme_support_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_uiplugin.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_uitools.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_uitools_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_virtualkeyboard.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_virtualkeyboard_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_webchannel.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_websockets.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_websockets_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_widgets.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_widgets_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_windowsuiautomation_support_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_winextras.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_winextras_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_xml.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_xml_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_zlib_private.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/qt_functions.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/qt_config.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/win32-g++/qmake.conf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/spec_post.prf \
		.qmake.stash \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/exclusive_builds.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/toolchain.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/default_pre.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/win32/default_pre.prf \
		../core_base/h3.pri \
		../core_base/core_base.pri \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/resolve_config.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/exclusive_builds_post.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/default_post.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/warn_off.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/qml_debug.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/precompile_header.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/qt.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/resources_functions.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/resources.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/moc.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/win32/opengl.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/uic.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/qmake_use.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/file_copies.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/win32/windows.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/testcase_targets.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/exceptions.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/yacc.prf \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/lex.prf \
		QWCalSoftware.pro \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/lib/Qt5PrintSupport.prl \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/lib/Qt5Widgets.prl \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/lib/Qt5Gui.prl \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/lib/Qt5Network.prl \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/lib/Qt5Core.prl \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/lib/qtmain.prl \
		D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/build_pass.prf \
		../core_qss/qss.qrc \
		src.qrc \
		../core_base/qrc/image.qrc \
		../core_base/qrc/qm.qrc \
		../core_base/qrc/font.qrc
	$(QMAKE) -o Makefile QWCalSoftware.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/spec_pre.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/qdevice.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/device_config.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/sanitize.conf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/gcc-base.conf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/g++-base.conf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/angle.conf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/win32/windows_vulkan_sdk.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/windows-vulkan.conf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/g++-win32.conf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/common/windows-desktop.conf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/qconfig.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3danimation.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3danimation_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dcore.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dcore_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dextras.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dextras_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dinput.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dinput_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dlogic.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dlogic_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquick.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquick_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickanimation.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickanimation_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickextras.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickextras_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickinput.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickinput_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickrender.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickrender_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickscene2d.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3dquickscene2d_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3drender.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_3drender_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_accessibility_support_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_axbase.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_axbase_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_axcontainer.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_axcontainer_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_axserver.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_axserver_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_bluetooth.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_bodymovin_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_charts.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_charts_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_concurrent.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_concurrent_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_core.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_core_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_datavisualization.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_datavisualization_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_dbus.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_dbus_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_designer.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_designer_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_edid_support_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_egl_support_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_fb_support_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_gamepad.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_gamepad_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_gui.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_gui_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_help.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_help_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_location.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_location_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_multimedia.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_multimedia_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_network.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_network_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_networkauth.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_networkauth_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_nfc.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_nfc_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_opengl.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_opengl_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_openglextensions.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_packetprotocol_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_positioning.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_positioning_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_positioningquick.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_positioningquick_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_printsupport.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_printsupport_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_purchasing.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_purchasing_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qml.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qml_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmldebug_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmlmodels.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmlmodels_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmltest.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmltest_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmlworkerscript.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qmlworkerscript_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3d.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3d_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3dassetimport.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3dassetimport_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3drender.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3drender_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3druntimerender.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3druntimerender_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3dutils.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick3dutils_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quick_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quickcontrols2.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quickshapes_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quicktemplates2.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quickwidgets.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_remoteobjects.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_remoteobjects_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_repparser.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_repparser_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_script.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_script_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_scripttools.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_scripttools_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_scxml.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_scxml_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_sensors.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_sensors_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_serialbus.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_serialbus_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_serialport.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_serialport_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_sql.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_sql_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_svg.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_svg_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_testlib.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_testlib_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_texttospeech.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_texttospeech_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_theme_support_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_uiplugin.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_uitools.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_uitools_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_virtualkeyboard.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_virtualkeyboard_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_vulkan_support_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_webchannel.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_webchannel_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_websockets.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_websockets_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_widgets.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_widgets_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_windowsuiautomation_support_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_winextras.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_winextras_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_xml.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_xml_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/modules/qt_lib_zlib_private.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/qt_functions.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/qt_config.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/win32-g++/qmake.conf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/spec_post.prf:
.qmake.stash:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/exclusive_builds.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/toolchain.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/default_pre.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/win32/default_pre.prf:
../core_base/h3.pri:
../core_base/core_base.pri:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/resolve_config.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/exclusive_builds_post.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/default_post.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/warn_off.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/qml_debug.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/precompile_header.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/qt.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/resources_functions.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/resources.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/moc.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/win32/opengl.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/uic.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/qmake_use.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/file_copies.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/win32/windows.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/testcase_targets.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/exceptions.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/yacc.prf:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/lex.prf:
QWCalSoftware.pro:
D:/7777777/Software/Qt/5.15.2/mingw81_64/lib/Qt5PrintSupport.prl:
D:/7777777/Software/Qt/5.15.2/mingw81_64/lib/Qt5Widgets.prl:
D:/7777777/Software/Qt/5.15.2/mingw81_64/lib/Qt5Gui.prl:
D:/7777777/Software/Qt/5.15.2/mingw81_64/lib/Qt5Network.prl:
D:/7777777/Software/Qt/5.15.2/mingw81_64/lib/Qt5Core.prl:
D:/7777777/Software/Qt/5.15.2/mingw81_64/lib/qtmain.prl:
D:/7777777/Software/Qt/5.15.2/mingw81_64/mkspecs/features/build_pass.prf:
../core_qss/qss.qrc:
src.qrc:
../core_base/qrc/image.qrc:
../core_base/qrc/qm.qrc:
../core_base/qrc/font.qrc:
qmake: FORCE
	@$(QMAKE) -o Makefile QWCalSoftware.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
