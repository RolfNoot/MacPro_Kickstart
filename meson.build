project('meson_test', 'c',
	version : '0.1',
	default_options : ['warning_level=3']
)

[host_machine]
system     = 'none'
cpu_family = 'arm'
cpu        = 'cortex-m4'
endian     = 'little'

#================================================================================================================================#
# check Creator_PostBuild version and set various variables for possible use

# Creator_PostBuild_Minumum_Version: '2.10' - used for checking Creator_PostBuild minimum version, do not remove

# Creator_PostBuild_Version_Line - automatic insert of Creator_PostBuild version. Do not edit the line below
creatorPostBuildVersion = '2.10'

# Creator_PostBuild_DateTime_Line - automatic insert of Creator Generated DateTime. Do not edit the line below
creatorGeneratedDateTime = '2023-05-07 21:46:03'

# Creator_PostBuild_devicePart_Line - automatic insert of device part by Creator_PostBuild. Do not edit the line below
devicePart = 'CY8C4246AZI-L433'

# Creator_PostBuild_linkerFile_Line - automatic insert of linker file by Creator_PostBuild. Do not edit the line below
linkerFile = './Generated_Source/PSoC4/cm0gcc.ld'

# Creator_PostBuild_SVDfile_Line - automatic insert of SVD file by Creator_PostBuild. Do not edit the line below
SVDfile = 'PSoC4200L.svd'

# Creator_PostBuild_prePostBuild_Lines - automatic insert of pre- and postbuild commands by Creator_PostBuild. Do not edit the two line below
preBuildCommands = ''
postBuildCommands = ''

# set directories
# Creator_PostBuild_Directory_Line - automatic insert of Creator Project main directory. Do not edit the line below
creatorDirectory = 'PSoC4200L.cydsn'

# OTX_Extension_print(PROJECTNAME = '${workspaceFolderBasename}')
PROJECTNAME = 'MacPro_KickStart'

# OTX_Extension_print(ONETHINX_PACK_LOC = '${env:ONETHINX_PACK_LOC}')
ONETHINX_PACK_LOC = '/Volumes/Data/VScode/GIT/VSCode_OnethinxPack_macOS'

# OTX_Extension_print(ONETHINX_TOOLS_LOC = '${env:ONETHINX_TOOLS_LOC}')
ONETHINX_TOOLS_LOC = '/Volumes/Data/VScode/GIT/VSCode_OnethinxPack_macOS/tools_3.0'

CONFIG_DIR = ONETHINX_PACK_LOC + '/config'
MESON_SOURCE_LOC = meson.current_source_dir()

CREATOR_DIR = MESON_SOURCE_LOC + '/' + creatorDirectory

#================================================================================================================================#
# import tools

objcopy  		= find_program('arm-none-eabi-objcopy').path()
objdump  		= find_program('arm-none-eabi-objdump').path()
size     		= find_program('arm-none-eabi-size').path()
gdb      		= find_program('arm-none-eabi-gdb').path()
cymcuelftool 	= find_program(ONETHINX_TOOLS_LOC + '/cymcuelftool-1.0/bin/cymcuelftool').path()
readelf  		= find_program('arm-none-eabi-readelf').path()
memcalc 		= find_program(CONFIG_DIR + '/scripts/memcalc').path()

#================================================================================================================================#
# setup compile & link arguments

assembler_args = [
# Creator_PostBuild_AssemblerOptions_Start - automatic insert of assembler options by Creator_PostBuild. Do not edit below this line
	'-mcpu=cortex-m0',
	'-mthumb',
	'-g',
	'-W',
# Creator_PostBuild_AssemblerOptions_End - automatic insert of assembler options by Creator_PostBuild. Do not edit above this line
]

compiler_args     = [
# Creator_PostBuild_CompilerOptions_Start - automatic insert of compiler options by Creator_PostBuild. Do not edit below this line
	'-mcpu=cortex-m0',
	'-mthumb',
	'-g',
	'-DDEBUG',
	'-DCY_CORE_ID=0',
	'-Wall',
	'-ffunction-sections',
	'-ffat-lto-objects',
	'-Og',
# Creator_PostBuild_CompilerOptions_End - automatic insert of compiler options by Creator_PostBuild. Do not edit above this line
]

linker_args     = [
	'-L'+CREATOR_DIR,
	'-L'+CREATOR_DIR+'/Generated_Source/PSoC4/',
# Creator_PostBuild_LinkerOptions_Start - automatic insert of linker options by Creator_PostBuild. Do not edit below this line
	'-mcpu=cortex-m0',
	'-mthumb',
	'-LGenerated_Source/PSoC4',
	'-TGenerated_Source/PSoC4/cm0gcc.ld',
	'-specs=nano.specs',
	'-Wl,--gc-sections',
	'-g',
	'-ffunction-sections',
	'-Og',
	'-ffat-lto-objects',
# Creator_PostBuild_LinkerOptions_End - automatic insert of linker options by Creator_PostBuild. Do not edit above this line
]

include_dirs       = [
# OTX_Extension_HeaderFiles_Start - automatic insert of source files by the OTX VSCode extension. Do not edit below this line
# OTX_Extension_HeaderFiles_End - automatic insert of source files by the OTX VSCode extension. Do not edit above this line
# Creator_PostBuild_IncludeFolders_Start - automatic insert of include header folders by Creator_PostBuild. Do not edit below this line
	'PSoC4200L.cydsn/Generated_Source/PSoC4',
	'PSoC4200L.cydsn/',
# Creator_PostBuild_IncludeFolders_End - automatic insert of include header folders by Creator_PostBuild. Do not edit above this line
]

sourcefiles       = [
	# manual insert of Creator_PostBuild stripped files
	#CREATOR_DIR + '/gcc/startup_psoc6_01_cm4.S',
#	CREATOR_DIR + '/system_psoc6_cm4.c',
	#CREATOR_DIR + '/Generated_Source/PSoC6/cyfitter_cfg_otx.c',
# OTX_Extension_SourceFiles_Start - automatic insert of source files by the OTX VSCode extension. Do not edit below this line
	'source/main.c',
# OTX_Extension_SourceFiles_End - automatic insert of source files by the OTX VSCode extension. Do not edit above this line
# Creator_PostBuild_SourceFiles_Start - automatic insert of source files by Creator_PostBuild. Do not edit below this line
	'PSoC4200L.cydsn/Generated_Source/PSoC4/cyfitter_cfg.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/cymetadata.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/SPIM_EE.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/SPIM_EE_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/SPIM_EE_INT.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/SPIS_HOST.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/SPIS_HOST_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/SPIS_HOST_INT.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/SPIS_HOST_BOOT.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/EE_MISO.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/EE_MISO_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/Control_SELECT_SPI.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/Control_SELECT_SPI_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/HOST_MOSI.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/HOST_MOSI_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/EE_SS.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/EE_SS_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/HOST_SS.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/HOST_SS_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/EE_MOSI.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/EE_MOSI_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/EE_CLK.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/EE_CLK_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/HOST_MISO.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/HOST_MISO_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/HOST_CLK.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/HOST_CLK_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/EE_WP.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/EE_WP_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/HOST_WP.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/HOST_WP_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/EE_HOLD.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/EE_HOLD_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/HOST_HOLD.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/HOST_HOLD_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/SPIM_EE_IntClock.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/SPIS_HOST_IntClock.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/Cm0Start.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/CyFlash.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/CyLib.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/cyPm.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/cyutils.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/CyDMA.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/CyLFClk.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/cy_em_eeprom.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_audio.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_boot.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_cdc.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_cls.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_descr.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_drv.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_episr.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_hid.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_pm.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_std.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_vnd.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_midi.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_msc.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_Dp.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_Dp_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_Dm.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/USBUART_Dm_PM.c',
	'PSoC4200L.cydsn/Generated_Source/PSoC4/CyBootAsmGnu.s',
# Creator_PostBuild_SourceFiles_End - automatic insert of source files by Creator_PostBuild. Do not edit above this line
]

#================================================================================================================================#
# include libraries

cc = meson.get_compiler('c')

# example: include library.a from directory
#link_deps = declare_dependency( dependencies : cc.find_library('library', dirs : ['directory/libdir']) )
link_deps = [
# Creator_PostBuild_LibSources_Start - automatic insert of include source files by Creator_PostBuild. Do not edit below this line
# Creator_PostBuild_LibSources_End - automatic insert of include source files by Creator_PostBuild. Do not edit above this line
]

# example: include object.o from directory
#link_deps += declare_dependency( link_args : ['directory/libdir/object.o'] )

#================================================================================================================================#
# run prebuild script 

#prebuild = custom_target('prebuild', output : 'buildversion.h', command : [MESON_SOURCE_LOC+'/config/prebuild.bash']) #use prebuild.bash / prebuild.bat file
#link_deps += declare_dependency( sources : [prebuild])

#================================================================================================================================#
# build executable

main = executable(
            PROJECTNAME,          [sourcefiles],
            name_suffix         : 'elf',
            c_args              : [compiler_args],
            link_args           : [linker_args],
            dependencies        : link_deps,
            include_directories : [include_dirs] )

#================================================================================================================================#
# run post build

signed = custom_target(
                        PROJECTNAME + '_signed.elf',
    output           : [PROJECTNAME + '_signed.elf'],
    build_by_default : true,
    command          : [cymcuelftool, '--sign',  PROJECTNAME + '.elf', '--output', PROJECTNAME + '_signed.elf', '--hex', PROJECTNAME + '.hex'],
    depends          : [main])
	
mainout = custom_target(
                        PROJECTNAME + '.memcalc.txt',
    output           :  [PROJECTNAME + '.memcalc.txt'],
    build_by_default : true,
	console			 : true,
    command          : [memcalc, readelf, PROJECTNAME + '.elf', '0x0e0000', '0x38000', '0x10000000', '0x08000000', PROJECTNAME + '.memcalc.txt'],  #Flash 0x0e0000   SRAM 0x38000   Flash start 0x10000000   SRAM start 0x08000000
   # command          : [memcalc, PROJECTNAME + '.readelf', '0x0e0000', '0x38000', '0x10000000', '0x08000000', PROJECTNAME + '.memcalc2.txt'],  #Flash 0x0e0000   SRAM 0x38000   Flash start 0x10000000   SRAM start 0x08000000
    depends          : [main])
