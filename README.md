# MacPro_Kickstart
MacPro KickStart firmware for PSoC4

*This project is licensed under GPL3.0. Any changes and/or additions should be made public.*

This project is created with the following tools / extensions.
- Visual Studio Code (coding, programming, debugging)
- PSoC Creator (only for one-time PSoC4 chip setup)
- Creator PostBuild Tool (integrating PSoC4 chip setup) 
- GNU GCC for ARM (compiling / building)
- Meson build system (generating build files)
- OpenOCD (programming / debugging)
- J-Link debugger or DAP-Link compatible (programmer / debugger hardware)

## Installation instructions:
1. Download and install the [Visual Studio Code IDE](https://code.visualstudio.com) 
1. This project uses multiple tools and extensions from the Onethinx Dependencies Pack, follow the instructions in the link below to set it up:
    - For Windows: [VSCode_OnethinxPack_Windows](https://github.com/onethinx/VSCode_OnethinxPack_Windows)
    - For Linux: [VSCode_OnethinxPack_Linux](https://github.com/onethinx/VSCode_OnethinxPack_Linux)
    - For MacOS: [VSCode_OnethinxPack_MacOS](https://github.com/onethinx/VSCode_OnethinxPack_MacOS)
1. This project uses the Meson build tool, follow [this link](https://github.com/onethinx/OTX-Meson-Testing) to set it up. 
1. Clone `https://github.com/RolfNoot/MacPro_Kickstart.git` or [download](https://github.com/RolfNoot/MacPro_Kickstart/archive/refs/heads/main.zip) and unpack the MacPro_Kickstart Project to your local machine.


## Prepare the project in VS Code
1. Start VS Code
1. Load the project by selecting the project folder (File >> Open Folder):
<br>`..\MacPro_Kickstart`<br>
1. The following buttons in the statusbar can be used to configure, build and debug the project.
![VScode Buttons](https://github.com/onethinx/Readme_assets/blob/main/VScode_buttons.png)<br>
1. On first-time load of a project, the build folder should be removed.
1. Click `Clean-Reconfigure` in the status bar to configure the project's makefiles (only needs to be done once, when the Chip Configuration is changed and when source files are removed/added to the project).
1. Select the debug adapter to use for the project:
    - From the left extensions pane, click the `Run and Debug` icon (Cortex-Debug extension) and select the debugger for the project from the top 'Run and Debug' dropdown list)
## Build and Debug your code
1. Click `Build` in the status bar to build the project.
1. Click `Build-and-Launch` in the status bar to build and debug the project.

## Optionally: Modify Chip Configuration
The chip configuration can be modified with PSoC Creator.<br>[A detailed guide can be found here.](https://github.com/RolfNoot/MacPro_Kickstart/blob/main/chipconfig.md)
