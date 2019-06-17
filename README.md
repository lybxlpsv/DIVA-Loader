# DIVA Loader

**DIVA Loader** lets you load plugins into **Hatsune Miku Project DIVA Arcade Future Tone** by placing them into the **"plugins"** folder, it includes useful ones such as **TLAC**, **Prepatch** and a **Launcher** in the form of a plugin without needing to use extra executables.

## Installation

* Have a **full clean** dump of the game version **"7.10"** decompressed without **"mdata"** merges or any other modifications.
* Download the latest release.
* Decompress everything into the **root folder** of the game.

* **"mdata"** from **M215** to **M270** are supported, custom **"mdata"** will be possible soon.
* Files required to load **"mdata"** without merging it into the actual game are included (**"ram\databank\PvList*"** files)

For **"mdata"** to work, you have to drop each **"mdata"** update decompressed into the **"mdata\"** folder in the root folder of the game (create it if it doesn't exists).

**e.g.** For all **"mdata"** you should have the following folders inside:
  * M215
  * M220
  * M230
  * M240
  * M250
  * M260
  * M270

## Usage

Use **"plugins\components.ini"** to enable or disable TLAC components.\
Use **"plugins\config.ini"** to enable or disable plugins loading along other useful settings.\
Use **"plugins\keyconfig.ini"** to change your game keybinds.\
Use **"plugins\playerdata.ini"** to change your playername and other player customization.

Place any **Dynamic-link library (DLL)** with the filename extension as **".dva"** inside the **"plugins"** folder.\
**TLAC v2.0** with community modifications,an alternative for **"Prepatch"** and a **"Launcher"** are included by default.

Launch **"diva.exe"**.
Use **"--launch"** argument to bypass the launcher.

## Screenshots

Your **root** game folder should look like this:

![root game folder](https://i.imgur.com/c57lQPH.png)

Your **"mdata"** folder should look like this:

![mdata folder](https://i.imgur.com/2jUjosM.png)

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)

## FAQ

Compatible with **Windows 7** except for WMV PV videos.

Previous versions used **dinput8.dll** in the game root folder, if you still have it you must delete it.

**"Prepatch"** is not needed, it works with the original game executable.

[TLAC (TotallyLegitArcadeController) v2.0](https://github.com/samyuu/TotallyLegitArcadeController) by **Samyuu**.

Special thanks to **Brolijah**, **Skyth**, **korenkonder**, **Samyuu**, **somewhatlurker**, **Cainan**, **crash5band**, **vladkorotnev** and everyone else who helped at [Project DIVA Modding 2nd Community Discord](https://discord.gg/cvBVGDZ).

## Developer FAQ

This is a stripdown of [**ThirteenAG's** Ultimate ASI Loader v4.47](https://github.com/ThirteenAG/Ultimate-ASI-Loader/) for **"dnsapi.dll"** usage only.

Solution for **Visual Studio 2019**. 
Requires platform toolset **v142**.
Requires **Windows 10 SDK (10.0.17763.0)**.

Requires **Desktop development with C++**.
Requires **Windows Universal CRT SDK**.

Requires **.NET desktop development** (Launcher plugin)
Requires **.NET Framework 4 targeting pack** (Launcher plugin)
Requires **C++/CLI support for v142 build tools (14.21)** (Launcher plugin)

Requires [**Microsoft Research Detours Package**](https://github.com/microsoft/Detours) (included in the solution).
Requires [**FreeGLUT 3.0.0 DIVA**](https://github.com/Rayduxz/FreeGLUT) (included in the solution).


