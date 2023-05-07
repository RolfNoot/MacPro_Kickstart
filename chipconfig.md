
## Configure the Chip Setup (IOs, peripherals etc.) using PSoC Creator
  These steps are **only needed** when you need to change the chip configuration.
1. [Install](https://www.infineon.com/cms/en/design-support/tools/sdk/psoc-software/psoc-creator/) and start PSoC Creator
1. Open the PSoC4200L.cywrk workspace (File >> Open >> Project/Workspace)
<br>`..MacPro_KickStart\PSoC4200L.cydsn\PSoC4200L.cywrk`<br>
1. The PSoC Schematic Editor and the Design Wide Resources can be accessed at the left 'Workspace Explorer' pane:
![PSoC_Creator_Config](https://github.com/onethinx/Readme_assets/blob/main/PSoC_Creator_Config.png)
1. After the changes to the chip configuration are done, build the PSoC4200L project (Build >> Build PSoC4200L or Shift + F5)
1. Make sure the project builds well from the output tab and the [Creator_PostBuild](https://github.com/RolfNoot/Creator_PostBuild) has run:<br>
![Creator_PostBuild](https://github.com/onethinx/Readme_assets/blob/main/PSoC_Creator_Build.png)
1. The chip configuration is done and PSoC Creator may be closed.
