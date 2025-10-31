# Microsoft Developer Studio Project File - Name="Balloons" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Balloons - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Balloons.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Balloons.mak" CFG="Balloons - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Balloons - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Balloons - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Balloons - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Balloons - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Balloons - Win32 Release"
# Name "Balloons - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Balloons.cpp
# End Source File
# Begin Source File

SOURCE=.\Balloons.rc
# End Source File
# Begin Source File

SOURCE=.\BalloonsDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\BalloonsView.cpp
# End Source File
# Begin Source File

SOURCE=.\ExitGame.cpp
# End Source File
# Begin Source File

SOURCE=.\Inst.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Balloons.h
# End Source File
# Begin Source File

SOURCE=.\BalloonsDoc.h
# End Source File
# Begin Source File

SOURCE=.\BalloonsView.h
# End Source File
# Begin Source File

SOURCE=.\ExitGame.h
# End Source File
# Begin Source File

SOURCE=.\Inst.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Arrow.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Arrow_Mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Artirons.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Artirons2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_Df_1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_Df_10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_Df_2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_Df_3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_Df_4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_Df_5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_Df_6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_Df_7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_Df_8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_Df_9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_Df_Mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_In_1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_In_10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_In_2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_In_3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_In_4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_In_5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_In_6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_In_7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_In_8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_In_9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\B_In_Mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BA_Game_BackGround.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Balloons.ico
# End Source File
# Begin Source File

SOURCE=.\res\Balloons.rc2
# End Source File
# Begin Source File

SOURCE=.\res\BalloonsDoc.ico
# End Source File
# Begin Source File

SOURCE=".\res\bonus-1.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\Robin_1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\robin_1_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Robin_2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\robin_2_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Robin_3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\robin_3_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\robin_4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\robin_4_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\robin_5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\robin_5_mask.bmp
# End Source File
# Begin Source File

SOURCE=.\res\robin_6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\robin_6_mask.bmp
# End Source File
# End Group
# End Target
# End Project
